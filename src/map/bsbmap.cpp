#include <cctype>
#include <QFileInfo>
#include <QPainter>
#include "image.h"
#include "gcs.h"
#include "pcs.h"
#include "calibrationpoint.h"
#include "color.h"
#include "bsbmap.h"


#define LINE_LIMIT 1024

static inline bool getChar(QFile &file, bool mangled, char *c)
{
	if (!file.getChar(c))
		return false;
	if (mangled)
		*c = (char)((int)(*c - 9) & 0xFF);
	return true;
}

static inline bool isEOH(const QByteArray &line)
{
	return (line.size() >= 2 && line.at(line.size() - 2) == 0x1A
	  && line.at(line.size() -1) == 0);
}

static inline bool isType(const QByteArray &line, const QByteArray &type)
{
	return (line.left(4) == type);
}

static inline QByteArray hdrData(const QByteArray &line)
{
	return line.right(line.size() - 4);
}

static bool readHeaderLine(QFile &file, bool mangled, QByteArray &line)
{
	char c;

	while (getChar(file, mangled, &c) && line.size() < LINE_LIMIT) {
		if (c == '\0') {
			line.append(c);
			return true;
		}

		if (c == '\r')
			continue;

		if (c == '\n') {
			if (!getChar(file, mangled, &c))
				return false;
			if (c == ' ') {
				do {
					if (!getChar(file, mangled, &c))
						return false;
				} while (c == ' ');
				line.append(',');
				file.ungetChar(c);
				continue;
			} else {
				file.ungetChar(c);
				return true;
			}
		}

		line.append(c);
	}

	return false;
}

static inline bool isSplitter(const QByteArray &line, int i)
{
	return (line.at(i) == ',' && line.size() - i > 3 && isupper(line.at(i+1))
	  && (isupper(line.at(i+2)) || isdigit(line.at(i+2))) && line.at(i+3) == '=');
}

static QList<QByteArray> split(const QByteArray &line)
{
	QList<QByteArray> list;
	int ls = 0;

	for (int i = 0; i < line.size(); i++) {
		if (isSplitter(line, i)) {
			list.append(line.mid(ls, i - ls));
			ls = i + 1;
		}
	}
	list.append(line.mid(ls, line.size() - ls));

	return list;
}

static QMap<QString, QString> kvMap(const QByteArray &line)
{
	QMap<QString, QString> map;
	QList<QByteArray> parts(split(line));

	for (int i = 0; i < parts.size(); i++) {
		QList<QByteArray> ba = parts.at(i).split('=');
		if (ba.size() != 2)
			continue;
		map.insert(ba.at(0), ba.at(1));
	}

	return map;
}

static double parameter(const QString &str, bool *res)
{
	if (str.isEmpty() || str == "NOT_APPLICABLE") {
		*res = true;
		return NAN;
	}

	return str.toDouble(res);
}


bool BSBMap::parseBSB(const QByteArray &line)
{
	QMap<QString, QString> map(kvMap(line));

	_name = map.value("NA");
	if (_name.isEmpty()) {
		_errorString = "Invalid/missing BSB NA field";
		return false;
	}

	QStringList sv(map.value("RA").split(','));
	unsigned w, h;
	bool wok = false, hok = false;
	if (sv.size() == 2) {
		w = sv.at(0).toUInt(&wok);
		h = sv.at(1).toUInt(&hok);
	} else if (sv.size() == 4) {
		w = sv.at(2).toUInt(&wok);
		h = sv.at(3).toUInt(&hok);
	}

	if (!wok || !hok || !w || !h) {
		_errorString = "Invalid BSB RA field";
		return false;
	}

	_size = QSize(w, h);

	return true;
}

bool BSBMap::parseKNP(const QByteArray &line, QString &datum, QString &proj,
  double &pp)
{
	QMap<QString, QString> map(kvMap(line));
	bool ok;

	if (!(map.contains("PR") && map.contains("GD") && map.contains("PP"))) {
		_errorString = "Missing KNP PR/GD/PP field";
		return false;
	}

	proj = map.value("PR");
	datum = map.value("GD");

	pp = parameter(map.value("PP"), &ok);
	if (!ok) {
		_errorString = "Invalid KNP PP field";
		return false;
	}

	return true;
}

bool BSBMap::parseKNQ(const QByteArray &line, double &p2, double &p3)
{
	QMap<QString, QString> map(kvMap(line));
	bool ok;

	p2 = parameter(map.value("P2"), &ok);
	if (!ok) {
		_errorString = "Invalid KNQ P2 parameter";
		return false;
	}
	p3 = parameter(map.value("P3"), &ok);
	if (!ok) {
		_errorString = "Invalid KNQ P3 parameter";
		return false;
	}

	return true;
}

bool BSBMap::parseREF(const QByteArray &line, QList<ReferencePoint> &points)
{
	QList<QByteArray> fields(line.split(','));

	if (fields.size() == 5) {
		bool xok, yok, lonok, latok;
		CalibrationPoint p(PointD(fields.at(1).toDouble(&xok),
		  fields.at(2).toDouble(&yok)), Coordinates(fields.at(4).toDouble(&lonok),
		  fields.at(3).toDouble(&latok)));
		if (xok && yok && lonok && latok) {
			points.append(p.rp(_projection));
			return true;
		}
	}

	_errorString = QString(line) + ": Invalid reference point entry";
	return false;
}

bool BSBMap::parseRGB(const QByteArray &line)
{
	QList<QByteArray> fields(line.split(','));
	bool iok, rok, gok, bok;
	int i = fields.at(0).toUInt(&iok);

	if (fields.size() == 4 && i > 0 && i < 256) {
		_palette[i-1] = Color::rgb(fields.at(1).toUInt(&rok),
		  fields.at(2).toUInt(&gok), fields.at(3).toUInt(&bok));
		return true;
	}

	_errorString = QString(line) + ": Invalid RGB entry";
	return false;
}

bool BSBMap::readHeader(QFile &file, bool mangled)
{
	QByteArray line;
	QString datum, proj;
	double pp, p2, p3;
	QList<ReferencePoint> points;

	while (readHeaderLine(file, mangled, line)) {
		if (isEOH(line)) {
			if (!_size.isValid() || !_projection.isValid()) {
				_errorString = "Invalid KAP/NOS file header";
				return false;
			}
			return createTransform(points);
		}

		if ((isType(line, "BSB/") || isType(line, "NOS/"))
		  && !parseBSB(hdrData(line)))
			return false;
		else if (isType(line, "KNP/") && !parseKNP(hdrData(line), datum, proj,
		  pp))
			return false;
		else if (isType(line, "KNQ/") && !parseKNQ(hdrData(line), p2, p3))
			return false;
		else if (isType(line, "REF/")) {
			if (_projection.isNull()) {
				if (!createProjection(datum, proj, pp, p2, p3))
					return false;
			}
			if (!parseREF(hdrData(line), points))
				return false;
		} else if (isType(line, "RGB/") && !parseRGB(hdrData(line)))
			return false;

		line.clear();
	}

	_errorString = "Not a KAP/NOS file";

	return false;
}

bool BSBMap::createTransform(const QList<ReferencePoint> &points)
{
	_transform = Transform(points);
	if (!_transform.isValid()) {
		_errorString = _transform.errorString();
		return false;
	}

	return true;
}

bool BSBMap::createProjection(const QString &datum, const QString &proj,
  double pp, double p2, double p3)
{
	const GCS *gcs = 0;
	PCS pcs;

	if (datum.isEmpty())
		gcs = GCS::gcs(4326);
	else
		gcs = GCS::gcs(datum);
	if (!gcs) {
		_errorString = datum + ": Unknown datum";
		return false;
	}

	if (proj.compare("MERCATOR", Qt::CaseInsensitive)) {
		Projection::Setup setup(0, 0, 1, 0, 0, 0, 0);
		pcs = PCS(gcs, 9804, setup, 9001);
	} else if (proj.compare("TRANSVERSE MERCATOR", Qt::CaseInsensitive)) {
		Projection::Setup setup(0, pp, 1, 0, 0, 0, 0);
		pcs = PCS(gcs, 9807, setup, 9001);
	} else if (proj.compare("UNIVERSAL TRANSVERSE MERCATOR",
	  Qt::CaseInsensitive)) {
		Projection::Setup setup(0, pp, 0.9996, 500000, 0, 0, 0);
		pcs = PCS(gcs, 9807, setup, 9001);
	} else if (proj.compare("LAMBERT CONFORMAL CONIC", Qt::CaseInsensitive)) {
		Projection::Setup setup(0, pp, 1, 0, 0, p2, p3);
		pcs = PCS(gcs, 9802, setup, 9001);
	} else {
		_errorString = proj + ": Unknown/missing projection";
		return false;
	}

	_projection = Projection(&pcs);

	return true;
}

bool BSBMap::readRow(QFile &file, char bits, uchar *buf)
{
	char c;
	int multiplier;
	int pixel = 1, written = 0;
	static const char mask[] = {0, 63, 31, 15, 7, 3, 1, 0};

	do {
		if (!getChar(file, _mangled, &c))
			return false;
	} while ((uchar)c >= 0x80);

	while (true) {
		if (!getChar(file, _mangled, &c))
			return false;
		if (c == '\0')
			break;

		pixel = (c & 0x7f) >> (7 - bits);
		multiplier = c & mask[(int)bits];

		while ((uchar)c >= 0x80) {
			if (!getChar(file, _mangled, &c))
				return false;
			multiplier = (multiplier << 7) + (c & 0x7f);
		}
		multiplier++;
		if (written + multiplier > _size.width())
			multiplier = _size.width() - written;
		memset(buf + written, pixel - 1, multiplier);
		written += multiplier;
	}

	while (written < _size.width())
		buf[written++] = pixel - 1;

	return true;
}

QImage BSBMap::readImage()
{
	QFile file(_fileName);
	char bits;

	if (!file.open(QIODevice::ReadOnly))
		return QImage();
	file.seek(_dataOffset);
	if (!getChar(file, _mangled, &bits))
		return QImage();

	QImage img(_size, QImage::Format_Indexed8);
	img.setColorTable(_palette);

	for (int row = 0; row < _size.height(); row++) {
		uchar *bsb_row = img.scanLine(row);
		if (!readRow(file, bits, bsb_row))
			return QImage();
	}

	return img;
}

BSBMap::BSBMap(const QString &fileName, QObject *parent)
  : Map(parent), _fileName(fileName), _img(0), _ratio(1.0), _dataOffset(-1),
  _valid(false)
{
	QFileInfo fi(fileName);
	QFile file(fileName);

	if (!file.open(QIODevice::ReadOnly)) {
		_errorString = fileName + ": " + file.errorString();
		return;
	}

	_palette.resize(256);
	_mangled = !fi.suffix().compare("no1", Qt::CaseInsensitive);
	if (!readHeader(file, _mangled))
		return;
	_dataOffset = file.pos();

	_valid = true;
}

BSBMap::~BSBMap()
{
	delete _img;
}

QPointF BSBMap::ll2xy(const Coordinates &c)
{
	return QPointF(_transform.proj2img(_projection.ll2xy(c))) / _ratio;
}

Coordinates BSBMap::xy2ll(const QPointF &p)
{
	return _projection.xy2ll(_transform.img2proj(p * _ratio));
}

QRectF BSBMap::bounds()
{
	return QRectF(QPointF(0, 0), _size / _ratio);
}

void BSBMap::draw(QPainter *painter, const QRectF &rect, Flags flags)
{
	if (_img)
		_img->draw(painter, rect, flags);
}

void BSBMap::setDevicePixelRatio(qreal deviceRatio, qreal mapRatio)
{
	Q_UNUSED(deviceRatio);

	_ratio = mapRatio;
	if (_img)
		_img->setDevicePixelRatio(_ratio);
}

void BSBMap::load()
{
	if (!_img)
		_img = new Image(readImage());
}

void BSBMap::unload()
{
	delete _img;
	_img = 0;
}
