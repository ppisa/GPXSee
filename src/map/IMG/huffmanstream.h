#ifndef IMG_HUFFMANSTREAM_H
#define IMG_HUFFMANSTREAM_H

#include "bitstream.h"
#include "huffmantable.h"

namespace IMG {

template <class BitStream>
class HuffmanStream {
public:
	HuffmanStream(BitStream &bitstream, const HuffmanTable &table)
	  : _symbolDataSize(0), _symbolData(0), _bs(bitstream), _table(table) {}

	bool read(quint32 bits, quint32 &val);
	bool readSymbol(quint32 &symbol);

	bool atEnd() const
	  {return _symbolDataSize + _bs.bitsAvailable() < _table.symBits();}

protected:
	quint32 _symbolDataSize;
	quint32 _symbolData;

private:
	bool fetchData();

	BitStream &_bs;
	const HuffmanTable &_table;
};

template <class BitStream>
bool HuffmanStream<BitStream>::fetchData()
{
	quint32 next;
	quint8 nextSize = qMin((quint64)(32 - _symbolDataSize), _bs.bitsAvailable());

	if (!_bs.read(nextSize, next))
		return false;

	_symbolData = (nextSize < 32) ? (_symbolData << nextSize) | next : next;
	_symbolDataSize += nextSize;

	return true;
}

template <class BitStream>
bool HuffmanStream<BitStream>::read(quint32 bits, quint32 &val)
{
	if (_symbolDataSize < bits)
		if (!fetchData() || _symbolDataSize < bits)
			return false;

	val = (_symbolData << (32 - _symbolDataSize)) >> (32 - bits);
	_symbolDataSize -= bits;

	return true;
}

template <class BitStream>
bool HuffmanStream<BitStream>::readSymbol(quint32 &symbol)
{
	quint8 size;

	if (_symbolDataSize < _table.symBits())
		if (!fetchData() || !_symbolDataSize)
			return false;

	symbol = _table.symbol(_symbolData << (32 - _symbolDataSize), size);
	if (size > _symbolDataSize)
		return false;

	_symbolDataSize -= size;

	return true;
}

template <class BitStream>
class HuffmanDeltaStream : public HuffmanStream<BitStream>
{
public:
	HuffmanDeltaStream(BitStream &bitstream, const HuffmanTable &table)
	  : HuffmanStream<BitStream>(bitstream, table), _lonSign(0), _latSign(0) {}

	bool readNext(qint32 &lonDelta, qint32 &latDelta)
	{
		if (!(readDelta(_lonSign, lonDelta) && readDelta(_latSign, latDelta)))
			return false;

		return (lonDelta || latDelta);
	}

protected:
	bool sign(int &val);
	bool readDelta(int sign, qint32 &delta);

	int _lonSign, _latSign;
};

template <class BitStream>
bool HuffmanDeltaStream<BitStream>::sign(int &val)
{
	quint32 bit;
	val = 0;

	if (!this->read(1, bit))
		return false;
	if (bit) {
		if (!this->read(1, bit))
			return false;
		val = bit ? -1 : 1;
	}

	return true;
}

template <class BitStream>
bool HuffmanDeltaStream<BitStream>::readDelta(int sign, qint32 &delta)
{
	quint32 symbol;
	if (!this->readSymbol(symbol))
		return false;

	if (symbol && !sign) {
		quint32 bit;
		if (!this->read(1, bit))
			return false;
		sign = bit ? -1 : 1;
	}

	delta = sign * symbol;

	return true;
}

class HuffmanDeltaStreamF : public HuffmanDeltaStream<BitStream4F> {
public:
	HuffmanDeltaStreamF(BitStream4F &bitstream, const HuffmanTable &table)
	  : HuffmanDeltaStream(bitstream, table) {}

	bool init(bool line);
	bool readOffset(qint32 &lonDelta, qint32 &latDelta)
	  {return (readDelta(1, lonDelta) && readDelta(1, latDelta));}
};

class HuffmanDeltaStreamR : public HuffmanDeltaStream<BitStream4R> {
public:
	HuffmanDeltaStreamR(BitStream4R &bitstream, const HuffmanTable &table)
	  : HuffmanDeltaStream(bitstream, table) {}

	bool init();
	bool init(quint32 data, quint32 dataSize);
};

}

#endif // IMG_HUFFMANSTREAM_H
