unix:!macx {
    TARGET = gpxsee
} else {
    TARGET = GPXSee
}
VERSION = 10.0

QT += core \
    gui \
    gui-private \
    network \
    sql \
    concurrent \
    widgets \
    printsupport \
    positioning
greaterThan(QT_MAJOR_VERSION, 5) {
    QT += openglwidgets \
          core5compat
}

CONFIG += object_parallel_to_source
INCLUDEPATH += ./src
HEADERS += src/common/config.h \
    src/GUI/crosshairitem.h \
    src/GUI/motioninfoitem.h \
    src/GUI/pluginparameters.h \
    src/common/garmin.h \
    src/common/coordinates.h \
    src/common/range.h \
    src/common/rectc.h \
    src/common/textcodec.h \
    src/common/treenode.h \
    src/common/wgs84.h \
    src/common/util.h \
    src/common/rtree.h \
    src/common/kv.h \
    src/common/greatcircle.h \
    src/common/programpaths.h \
    src/common/tifffile.h \
    src/common/downloader.h \
    src/common/polygon.h \
    src/common/color.h \
    src/GUI/authenticationwidget.h \
    src/GUI/axislabelitem.h \
    src/GUI/dirselectwidget.h \
    src/GUI/flowlayout.h \
    src/GUI/graphicsscene.h \
    src/GUI/infolabel.h \
    src/GUI/mapaction.h \
    src/GUI/mapitem.h \
    src/GUI/marginswidget.h \
    src/GUI/markerinfoitem.h \
    src/GUI/planeitem.h \
    src/GUI/poiaction.h \
    src/GUI/popup.h \
    src/GUI/thumbnail.h \
    src/GUI/app.h \
    src/GUI/icons.h \
    src/GUI/gui.h \
    src/GUI/axisitem.h \
    src/GUI/keys.h \
    src/GUI/slideritem.h \
    src/GUI/markeritem.h \
    src/GUI/infoitem.h \
    src/GUI/elevationgraph.h \
    src/GUI/speedgraph.h \
    src/GUI/sliderinfoitem.h \
    src/GUI/filebrowser.h \
    src/GUI/units.h \
    src/GUI/scaleitem.h \
    src/GUI/graphview.h \
    src/GUI/waypointitem.h \
    src/GUI/palette.h \
    src/GUI/heartrategraph.h \
    src/GUI/trackinfo.h \
    src/GUI/fileselectwidget.h \
    src/GUI/temperaturegraph.h \
    src/GUI/graphtab.h \
    src/GUI/trackitem.h \
    src/GUI/tooltip.h \
    src/GUI/routeitem.h \
    src/GUI/graphitem.h \
    src/GUI/pathitem.h \
    src/GUI/griditem.h \
    src/GUI/format.h \
    src/GUI/cadencegraph.h \
    src/GUI/powergraph.h \
    src/GUI/gearratiograph.h \
    src/GUI/optionsdialog.h \
    src/GUI/colorbox.h \
    src/GUI/stylecombobox.h \
    src/GUI/timetype.h \
    src/GUI/percentslider.h \
    src/GUI/elevationgraphitem.h \
    src/GUI/speedgraphitem.h \
    src/GUI/heartrategraphitem.h \
    src/GUI/temperaturegraphitem.h \
    src/GUI/cadencegraphitem.h \
    src/GUI/powergraphitem.h \
    src/GUI/gearratiographitem.h \
    src/GUI/oddspinbox.h \
    src/GUI/settings.h \
    src/GUI/searchpointer.h \
    src/GUI/mapview.h \
    src/GUI/font.h \
    src/GUI/areaitem.h \
    src/GUI/coordinatesitem.h \
    src/GUI/projectioncombobox.h \
    src/GUI/pathtickitem.h \
    src/GUI/pdfexportdialog.h \
    src/GUI/pngexportdialog.h \
    src/GUI/timezoneinfo.h \
    src/GUI/passwordedit.h \
    src/map/proj/polyconic.h \
    src/map/proj/webmercator.h \
    src/map/proj/transversemercator.h \
    src/map/proj/latlon.h \
    src/map/proj/lambertconic.h \
    src/map/proj/lambertazimuthal.h \
    src/map/proj/albersequal.h \
    src/map/proj/mercator.h \
    src/map/proj/krovak.h \
    src/map/proj/polarstereographic.h \
    src/map/proj/obliquestereographic.h \
    src/map/IMG/bitmapline.h \
    src/map/IMG/bitstream.h \
    src/map/IMG/deltastream.h \
    src/map/IMG/gmapdata.h \
    src/map/IMG/huffmanbuffer.h \
    src/map/IMG/huffmanstream.h \
    src/map/IMG/huffmantable.h \
    src/map/IMG/huffmantext.h \
    src/map/IMG/nodfile.h \
    src/map/IMG/mapdata.h \
    src/map/IMG/raster.h \
    src/map/IMG/rastertile.h \
    src/map/IMG/shield.h \
    src/map/IMG/imgdata.h \
    src/map/IMG/subfile.h \
    src/map/IMG/trefile.h \
    src/map/IMG/rgnfile.h \
    src/map/IMG/lblfile.h \
    src/map/IMG/vectortile.h \
    src/map/IMG/subdiv.h \
    src/map/IMG/style.h \
    src/map/IMG/netfile.h \
    src/map/IMG/label.h \
    src/map/mapsforge/style.h \
    src/map/mapsforge/mapdata.h \
    src/map/mapsforge/rastertile.h \
    src/map/mapsforge/subfile.h \
    src/map/qctmap.h \
    src/map/textpathitem.h \
    src/map/textpointitem.h \
    src/map/prjfile.h \
    src/map/bsbmap.h \
    src/map/invalidmap.h \
    src/map/kmzmap.h \
    src/map/projection.h \
    src/map/ellipsoid.h \
    src/map/datum.h \
    src/map/sqlitemap.h \
    src/map/utm.h \
    src/map/map.h \
    src/map/maplist.h \
    src/map/onlinemap.h \
    src/map/tile.h \
    src/map/emptymap.h \
    src/map/ozimap.h \
    src/map/tar.h \
    src/map/ozf.h \
    src/map/atlas.h \
    src/map/matrix.h \
    src/map/geotiff.h \
    src/map/pcs.h \
    src/map/transform.h \
    src/map/mapfile.h \
    src/map/gcs.h \
    src/map/angularunits.h \
    src/map/primemeridian.h \
    src/map/linearunits.h \
    src/map/ct.h \
    src/map/mapsource.h \
    src/map/tileloader.h \
    src/map/wldfile.h \
    src/map/wmtsmap.h \
    src/map/wmts.h \
    src/map/wmsmap.h \
    src/map/wms.h \
    src/map/crs.h \
    src/map/coordinatesystem.h \
    src/map/pointd.h \
    src/map/rectd.h \
    src/map/geocentric.h \
    src/map/jnxmap.h \
    src/map/geotiffmap.h \
    src/map/image.h \
    src/map/mbtilesmap.h \
    src/map/osm.h \
    src/map/rmap.h \
    src/map/calibrationpoint.h \
    src/map/textitem.h \
    src/map/aqmmap.h \
    src/map/mapsforgemap.h \
    src/map/worldfilemap.h \
    src/map/imgmap.h \
    src/data/itnparser.h \
    src/data/link.h \
    src/data/onmoveparsers.h \
    src/data/ov2parser.h \
    src/data/graph.h \
    src/data/poi.h \
    src/data/waypoint.h \
    src/data/track.h \
    src/data/route.h \
    src/data/trackpoint.h \
    src/data/data.h \
    src/data/parser.h \
    src/data/trackdata.h \
    src/data/routedata.h \
    src/data/path.h \
    src/data/gpxparser.h \
    src/data/tcxparser.h \
    src/data/csvparser.h \
    src/data/kmlparser.h \
    src/data/fitparser.h \
    src/data/igcparser.h \
    src/data/nmeaparser.h \
    src/data/oziparsers.h \
    src/data/locparser.h \
    src/data/slfparser.h \
    src/data/dem.h \
    src/data/demloader.h \
    src/data/area.h \
    src/data/exifparser.h \
    src/data/csv.h \
    src/data/cupparser.h \
    src/data/gpiparser.h \
    src/data/address.h \
    src/data/smlparser.h \
    src/data/geojsonparser.h

SOURCES += src/main.cpp \
    src/GUI/crosshairitem.cpp \
    src/GUI/motioninfoitem.cpp \
    src/GUI/pluginparameters.cpp \
    src/common/coordinates.cpp \
    src/common/rectc.cpp \
    src/common/range.cpp \
    src/common/textcodec.cpp \
    src/common/util.cpp \
    src/common/greatcircle.cpp \
    src/common/programpaths.cpp \
    src/common/tifffile.cpp \
    src/common/downloader.cpp \
    src/GUI/authenticationwidget.cpp \
    src/GUI/axislabelitem.cpp \
    src/GUI/dirselectwidget.cpp \
    src/GUI/flowlayout.cpp \
    src/GUI/infolabel.cpp \
    src/GUI/mapitem.cpp \
    src/GUI/marginswidget.cpp \
    src/GUI/markerinfoitem.cpp \
    src/GUI/popup.cpp \
    src/GUI/thumbnail.cpp \
    src/GUI/app.cpp \
    src/GUI/gui.cpp \
    src/GUI/axisitem.cpp \
    src/GUI/slideritem.cpp \
    src/GUI/markeritem.cpp \
    src/GUI/infoitem.cpp \
    src/GUI/elevationgraph.cpp \
    src/GUI/speedgraph.cpp \
    src/GUI/sliderinfoitem.cpp \
    src/GUI/filebrowser.cpp \
    src/GUI/scaleitem.cpp \
    src/GUI/graphview.cpp \
    src/GUI/waypointitem.cpp \
    src/GUI/palette.cpp \
    src/GUI/heartrategraph.cpp \
    src/GUI/trackinfo.cpp \
    src/GUI/fileselectwidget.cpp \
    src/GUI/temperaturegraph.cpp \
    src/GUI/trackitem.cpp \
    src/GUI/routeitem.cpp \
    src/GUI/graphitem.cpp \
    src/GUI/pathitem.cpp \
    src/GUI/griditem.cpp \
    src/GUI/format.cpp \
    src/GUI/cadencegraph.cpp \
    src/GUI/powergraph.cpp \
    src/GUI/gearratiograph.cpp \
    src/GUI/optionsdialog.cpp \
    src/GUI/colorbox.cpp \
    src/GUI/stylecombobox.cpp \
    src/GUI/oddspinbox.cpp \
    src/GUI/percentslider.cpp \
    src/GUI/elevationgraphitem.cpp \
    src/GUI/speedgraphitem.cpp \
    src/GUI/heartrategraphitem.cpp \
    src/GUI/temperaturegraphitem.cpp \
    src/GUI/cadencegraphitem.cpp \
    src/GUI/powergraphitem.cpp \
    src/GUI/gearratiographitem.cpp \
    src/GUI/mapview.cpp \
    src/GUI/areaitem.cpp \
    src/GUI/coordinatesitem.cpp \
    src/GUI/pathtickitem.cpp \
    src/GUI/graphicsscene.cpp \
    src/GUI/pdfexportdialog.cpp \
    src/GUI/pngexportdialog.cpp \
    src/GUI/projectioncombobox.cpp \
    src/GUI/passwordedit.cpp \
    src/map/proj/polyconic.cpp \
    src/map/proj/webmercator.cpp \
    src/map/proj/transversemercator.cpp \
    src/map/proj/lambertconic.cpp \
    src/map/proj/albersequal.cpp \
    src/map/proj/lambertazimuthal.cpp \
    src/map/proj/mercator.cpp \
    src/map/proj/krovak.cpp \
    src/map/proj/polarstereographic.cpp \
    src/map/proj/obliquestereographic.cpp \
    src/map/IMG/bitmapline.cpp \
    src/map/IMG/bitstream.cpp \
    src/map/IMG/deltastream.cpp \
    src/map/IMG/gmapdata.cpp \
    src/map/IMG/huffmanbuffer.cpp \
    src/map/IMG/huffmanstream.cpp \
    src/map/IMG/huffmantable.cpp \
    src/map/IMG/huffmantext.cpp \
    src/map/IMG/nodfile.cpp \
    src/map/IMG/mapdata.cpp \
    src/map/IMG/rastertile.cpp \
    src/map/IMG/imgdata.cpp \
    src/map/IMG/subfile.cpp \
    src/map/IMG/trefile.cpp \
    src/map/IMG/rgnfile.cpp \
    src/map/IMG/lblfile.cpp \
    src/map/IMG/vectortile.cpp \
    src/map/IMG/style.cpp \
    src/map/IMG/netfile.cpp \
    src/map/mapsforge/style.cpp \
    src/map/mapsforge/mapdata.cpp \
    src/map/mapsforge/rastertile.cpp \
    src/map/mapsforge/subfile.cpp \
    src/map/imgmap.cpp \
    src/map/prjfile.cpp \
    src/map/qctmap.cpp \
    src/map/textpathitem.cpp \
    src/map/textpointitem.cpp \
    src/map/bsbmap.cpp \
    src/map/kmzmap.cpp \
    src/map/maplist.cpp \
    src/map/onlinemap.cpp \
    src/map/emptymap.cpp \
    src/map/ozimap.cpp \
    src/map/sqlitemap.cpp \
    src/map/tar.cpp \
    src/map/atlas.cpp \
    src/map/ozf.cpp \
    src/map/matrix.cpp \
    src/map/ellipsoid.cpp \
    src/map/datum.cpp \
    src/map/utm.cpp \
    src/map/geotiff.cpp \
    src/map/pcs.cpp \
    src/map/transform.cpp \
    src/map/mapfile.cpp \
    src/map/projection.cpp \
    src/map/gcs.cpp \
    src/map/angularunits.cpp \
    src/map/primemeridian.cpp \
    src/map/linearunits.cpp \
    src/map/mapsource.cpp \
    src/map/tileloader.cpp \
    src/map/wldfile.cpp \
    src/map/wmtsmap.cpp \
    src/map/wmts.cpp \
    src/map/wmsmap.cpp \
    src/map/wms.cpp \
    src/map/crs.cpp \
    src/map/coordinatesystem.cpp \
    src/map/geocentric.cpp \
    src/map/jnxmap.cpp \
    src/map/map.cpp \
    src/map/geotiffmap.cpp \
    src/map/image.cpp \
    src/map/mbtilesmap.cpp \
    src/map/osm.cpp \
    src/map/rectd.cpp \
    src/map/rmap.cpp \
    src/map/textitem.cpp \
    src/map/aqmmap.cpp \
    src/map/mapsforgemap.cpp \
    src/map/worldfilemap.cpp \
    src/data/address.cpp \
    src/data/itnparser.cpp \
    src/data/onmoveparsers.cpp \
    src/data/ov2parser.cpp \
    src/data/waypoint.cpp \
    src/data/data.cpp \
    src/data/poi.cpp \
    src/data/track.cpp \
    src/data/route.cpp \
    src/data/path.cpp \
    src/data/gpxparser.cpp \
    src/data/tcxparser.cpp \
    src/data/csvparser.cpp \
    src/data/kmlparser.cpp \
    src/data/fitparser.cpp \
    src/data/igcparser.cpp \
    src/data/nmeaparser.cpp \
    src/data/oziparsers.cpp \
    src/data/locparser.cpp \
    src/data/slfparser.cpp \
    src/data/dem.cpp \
    src/data/demloader.cpp \
    src/data/exifparser.cpp \
    src/data/csv.cpp \
    src/data/cupparser.cpp \
    src/data/gpiparser.cpp \
    src/data/smlparser.cpp \
    src/data/geojsonparser.cpp

DEFINES += APP_VERSION=\\\"$$VERSION\\\" \
    QT_NO_DEPRECATED_WARNINGS

RESOURCES += gpxsee.qrc
TRANSLATIONS = lang/gpxsee_en.ts \
    lang/gpxsee_cs.ts \
    lang/gpxsee_sv.ts \
    lang/gpxsee_de.ts \
    lang/gpxsee_ru.ts \
    lang/gpxsee_fi.ts \
    lang/gpxsee_fr.ts \
    lang/gpxsee_pl.ts \
    lang/gpxsee_nb.ts \
    lang/gpxsee_da.ts \
    lang/gpxsee_tr.ts \
    lang/gpxsee_es.ts \
    lang/gpxsee_pt_BR.ts \
    lang/gpxsee_uk.ts \
    lang/gpxsee_hu.ts \
    lang/gpxsee_it.ts \
    lang/gpxsee_eo.ts \
    lang/gpxsee_zh.ts

macx {
    ICON = icons/app/gpxsee.icns
    QMAKE_INFO_PLIST = pkg/Info.plist
    locale.path = Contents/Resources/translations
    locale.files = $$files(lang/*.qm)
    csv.path = Contents/Resources
    csv.files = pkg/csv
    maps.path = Contents/Resources
    maps.files = pkg/maps
    symbols.path = Contents/Resources/symbols
    symbols.files = $$files(icons/symbols/*.png)
    icons.path = Contents/Resources/icons
    icons.files = $$files(icons/formats/*.icns)

    QMAKE_BUNDLE_DATA += locale maps symbols icons csv
}

win32 {
    RC_ICONS = icons/app/gpxsee.ico \
        icons/formats/gpx.ico \
        icons/formats/tcx.ico \
        icons/formats/kml.ico \
        icons/formats/fit.ico \
        icons/formats/igc.ico \
        icons/formats/nmea.ico \
        icons/formats/plt.ico \
        icons/formats/rte.ico \
        icons/formats/wpt.ico \
        icons/formats/loc.ico \
        icons/formats/slf.ico \
        icons/formats/json.ico \
        icons/formats/cup.ico \
        icons/formats/gpi.ico \
        icons/formats/sml.ico \
        icons/formats/img.ico \
        icons/formats/jnx.ico \
        icons/formats/kap.ico \
        icons/formats/map.ico \
        icons/formats/mbts.ico \
        icons/formats/rmap.ico \
        icons/formats/tba.ico \
        icons/formats/aqm.ico \
        icons/formats/sqlt.ico \
        icons/formats/ov2.ico \
        icons/formats/itn.ico \
        icons/formats/wld.ico \
        icons/formats/omd.ico \
        icons/formats/ghp.ico \
        icons/formats/qct.ico
    DEFINES += _USE_MATH_DEFINES \
        NOGDI
}

unix:!macx {
    isEmpty(PREFIX):PREFIX = /usr/local

    maps.files = $$files(pkg/maps/*)
    maps.path = $$PREFIX/share/gpxsee/maps
    csv.files = $$files(pkg/csv/*)
    csv.path = $$PREFIX/share/gpxsee/csv
    symbols.files = $$files(icons/symbols/*.png)
    symbols.path = $$PREFIX/share/gpxsee/symbols
    locale.files = $$files(lang/*.qm)
    locale.path = $$PREFIX/share/gpxsee/translations
    icon.files = $$files(icons/app/hicolor/*)
    icon.path = $$PREFIX/share/icons/hicolor
    desktop.files = pkg/gpxsee.desktop
    desktop.path = $$PREFIX/share/applications
    mime.files = pkg/gpxsee.xml
    mime.path = $$PREFIX/share/mime/packages
    target.path = $$PREFIX/bin
    INSTALLS += target maps csv symbols locale icon desktop mime
}
