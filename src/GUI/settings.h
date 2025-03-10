#ifndef SETTINGS_H
#define SETTINGS_H

#define IMPERIAL_UNITS() \
	(QLocale::system().measurementSystem() == QLocale::ImperialSystem)
#define POSITION_PLUGIN() \
	(QGeoPositionInfoSource::availableSources().isEmpty() \
	  ? "" : QGeoPositionInfoSource::availableSources().first())

#define WINDOW_SETTINGS_GROUP             "Window"
#define WINDOW_GEOMETRY_SETTING           "geometry"
#define WINDOW_STATE_SETTING              "state"

#define SETTINGS_SETTINGS_GROUP           "Settings"
#define TIME_TYPE_SETTING                 "timeType"
#define TIME_TYPE_DEFAULT                 Total
#define UNITS_SETTING                     "units"
#define UNITS_DEFAULT                     (IMPERIAL_UNITS() ? Imperial : Metric)
#define COORDINATES_SETTING               "coordinates"
#define COORDINATES_DEFAULT               DecimalDegrees
#define SHOW_TOOLBARS_SETTING             "toolbar"
#define SHOW_TOOLBARS_DEFAULT             true

#define GRAPH_SETTINGS_GROUP              "Graph"
#define SHOW_GRAPHS_SETTING               "show"
#define SHOW_GRAPHS_DEFAULT               true
#define GRAPH_TYPE_SETTING                "type"
#define GRAPH_TYPE_DEFAULT                Distance
#define SHOW_GRAPH_GRIDS_SETTING          "grid"
#define SHOW_GRAPH_GRIDS_DEFAULT          true
#define SHOW_GRAPH_SLIDER_INFO_SETTING    "sliderInfo"
#define SHOW_GRAPH_SLIDER_INFO_DEFAULT    true
#define SHOW_TICKS_SETTING                "pathTicks"
#define SHOW_TICKS_DEFAULT                false

#define MAP_SETTINGS_GROUP                "Map"
#define CURRENT_MAP_SETTING               "map"
#define SHOW_MAP_SETTING                  "show"
#define SHOW_MAP_DEFAULT                  true
#define SHOW_CURSOR_COORDINATES_SETTING   "coordinates"
#define SHOW_CURSOR_COORDINATES_DEFAULT   false

#define POI_SETTINGS_GROUP                "POI"
#define OVERLAP_POI_SETTING               "overlap"
#define OVERLAP_POI_DEFAULT               false

#define POSITION_SETTINGS_GROUP           "Position"
#define SHOW_POSITION_SETTING             "show"
#define SHOW_POSITION_DEFAULT             false
#define FOLLOW_POSITION_SETTING           "follow"
#define FOLLOW_POSITION_DEFAULT           true
#define SHOW_POSITION_COORDINATES_SETTING "coordinates"
#define SHOW_POSITION_COORDINATES_DEFAULT true
#define SHOW_MOTION_INFO_SETTING          "motionInfo"
#define SHOW_MOTION_INFO_DEFAULT          true

#define SHOW_POI_ICONS_SETTING            "icons"
#define SHOW_POI_ICONS_DEFAULT            true
#define SHOW_POI_LABELS_SETTING           "labels"
#define SHOW_POI_LABELS_DEFAULT           true
#define SHOW_POI_SETTING                  "show"
#define SHOW_POI_DEFAULT                  false
#define DISABLED_POI_FILE_SETTINGS_PREFIX "disabled"
#define DISABLED_POI_FILE_SETTING         "file"

#define DATA_SETTINGS_GROUP               "Data"
#define SHOW_TRACKS_SETTING               "tracks"
#define SHOW_TRACKS_DEFAULT               true
#define SHOW_ROUTES_SETTING               "routes"
#define SHOW_ROUTES_DEFAULT               true
#define SHOW_WAYPOINTS_SETTING            "waypoints"
#define SHOW_WAYPOINTS_DEFAULT            true
#define SHOW_AREAS_SETTING                "areas"
#define SHOW_AREAS_DEFAULT                true
#define SHOW_ROUTE_WAYPOINTS_SETTING      "routeWaypoints"
#define SHOW_ROUTE_WAYPOINTS_DEFAULT      true
#define SHOW_WAYPOINT_ICONS_SETTING       "waypointIcons"
#define SHOW_WAYPOINT_ICONS_DEFAULT       false
#define SHOW_WAYPOINT_LABELS_SETTING      "waypointLabels"
#define SHOW_WAYPOINT_LABELS_DEFAULT      true
#define SHOW_MARKERS_SETTING              "positionMarkers"
#define SHOW_MARKERS_DEFAULT              true
#define SHOW_MARKER_INFO_SETTING          "markerInfo"
#define SHOW_MARKER_INFO_DEFAULT          MarkerInfoItem::None

#define PDF_EXPORT_SETTINGS_GROUP         "Export"
#define PAPER_ORIENTATION_SETTING         "orientation"
#define PAPER_ORIENTATION_DEFAULT         QPageLayout::Orientation::Portrait
#define PAPER_SIZE_SETTING                "size"
#define PAPER_SIZE_DEFAULT                (IMPERIAL_UNITS() \
	                                        ? QPageSize::PageSizeId::Letter \
	                                        : QPageSize::PageSizeId::A4)
#define PDF_MARGIN_LEFT_SETTING           "marginLeft"
#define PDF_MARGIN_LEFT_DEFAULT           5 /* mm */
#define PDF_MARGIN_TOP_SETTING            "marginTop"
#define PDF_MARGIN_TOP_DEFAULT            5 /* mm */
#define PDF_MARGIN_RIGHT_SETTING          "marginRight"
#define PDF_MARGIN_RIGHT_DEFAULT          5 /* mm */
#define PDF_MARGIN_BOTTOM_SETTING         "marginBottom"
#define PDF_MARGIN_BOTTOM_DEFAULT         5 /* mm */
#define PDF_FILENAME_SETTING              "fileName"
#define PDF_FILENAME_DEFAULT              QString("%1/export.pdf"). \
                                            arg(QDir::currentPath())
#define RESOLUTION_SETTING                "resolution"
#define RESOLUTION_DEFAULT                600

#define PNG_EXPORT_SETTINGS_GROUP         "PNGExport"
#define PNG_WIDTH_SETTING                 "width"
#define PNG_WIDTH_DEFAULT                 600
#define PNG_HEIGHT_SETTING                "height"
#define PNG_HEIGHT_DEFAULT                800
#define PNG_MARGIN_LEFT_SETTING           "marginLeft"
#define PNG_MARGIN_LEFT_DEFAULT           5 /* px */
#define PNG_MARGIN_TOP_SETTING            "marginTop"
#define PNG_MARGIN_TOP_DEFAULT            5 /* px */
#define PNG_MARGIN_RIGHT_SETTING          "marginRight"
#define PNG_MARGIN_RIGHT_DEFAULT          5 /* px */
#define PNG_MARGIN_BOTTOM_SETTING         "marginBottom"
#define PNG_MARGIN_BOTTOM_DEFAULT         5 /* px */
#define PNG_ANTIALIASING_SETTING          "antialiasing"
#define PNG_ANTIALIASING_DEFAULT          true
#define PNG_FILENAME_SETTING              "fileName"
#define PNG_FILENAME_DEFAULT              QString("%1/export.png"). \
											arg(QDir::currentPath())

#define OPTIONS_SETTINGS_GROUP            "Options"
#define PALETTE_COLOR_SETTING             "paletteColor"
#define PALETTE_COLOR_DEFAULT             QColor(Qt::blue)
#define PALETTE_SHIFT_SETTING             "paletteShift"
#define PALETTE_SHIFT_DEFAULT             0.62
#define MAP_OPACITY_SETTING               "mapOpacity"
#define MAP_OPACITY_DEFAULT               100
#define BACKGROUND_COLOR_SETTING          "backgroundColor"
#define BACKGROUND_COLOR_DEFAULT          QColor(Qt::white)
#define CROSSHAIR_COLOR_SETTING           "crosshairColor"
#define CROSSHAIR_COLOR_DEFAULT           QColor(Qt::red)
#define INFO_COLOR_SETTING                "infoColor"
#define INFO_COLOR_DEFAULT                QColor(Qt::black)
#define INFO_BACKGROUND_SETTING           "infoBackground"
#define INFO_BACKGROUND_DEFAULT           false
#define TRACK_WIDTH_SETTING               "trackWidth"
#define TRACK_WIDTH_DEFAULT               3
#define ROUTE_WIDTH_SETTING               "routeWidth"
#define ROUTE_WIDTH_DEFAULT               3
#define AREA_WIDTH_SETTING                "areaWidth"
#define AREA_WIDTH_DEFAULT                2
#define TRACK_STYLE_SETTING               "trackStyle"
#define TRACK_STYLE_DEFAULT               Qt::SolidLine
#define ROUTE_STYLE_SETTING               "routeStyle"
#define ROUTE_STYLE_DEFAULT               Qt::DotLine
#define AREA_STYLE_SETTING                "areaStyle"
#define AREA_STYLE_DEFAULT                Qt::SolidLine
#define AREA_OPACITY_SETTING              "areaOpacity"
#define AREA_OPACITY_DEFAULT              50
#define WAYPOINT_SIZE_SETTING             "waypointSize"
#define WAYPOINT_SIZE_DEFAULT             8
#define WAYPOINT_COLOR_SETTING            "waypointColor"
#define WAYPOINT_COLOR_DEFAULT            QColor(Qt::black)
#define POI_SIZE_SETTING                  "poiSize"
#define POI_SIZE_DEFAULT                  8
#define POI_COLOR_SETTING                 "poiColor"
#define POI_COLOR_DEFAULT                 QColor(Qt::black)
#define GRAPH_WIDTH_SETTING               "graphWidth"
#define GRAPH_WIDTH_DEFAULT               1
#define PATH_AA_SETTING                   "pathAntiAliasing"
#define PATH_AA_DEFAULT                   true
#define GRAPH_AA_SETTING                  "graphAntiAliasing"
#define GRAPH_AA_DEFAULT                  true
#define ELEVATION_FILTER_SETTING          "elevationFilter"
#define ELEVATION_FILTER_DEFAULT          3
#define SPEED_FILTER_SETTING              "speedFilter"
#define SPEED_FILTER_DEFAULT              5
#define HEARTRATE_FILTER_SETTING          "heartrateFilter"
#define HEARTRATE_FILTER_DEFAULT          3
#define CADENCE_FILTER_SETTING            "cadenceFilter"
#define CADENCE_FILTER_DEFAULT            3
#define POWER_FILTER_SETTING              "powerFilter"
#define POWER_FILTER_DEFAULT              3
#define OUTLIER_ELIMINATE_SETTING         "outlierEliminate"
#define OUTLIER_ELIMINATE_DEFAULT         true
#define AUTOMATIC_PAUSE_SETTING           "automaticPause"
#define AUTOMATIC_PAUSE_DEFAULT           true
#define PAUSE_SPEED_SETTING               "pauseSpeed"
#define PAUSE_SPEED_DEFAULT               0.5 /* m/s */
#define PAUSE_INTERVAL_SETTING            "pauseInterval"
#define PAUSE_INTERVAL_DEFAULT            10 /* s */
#define USE_REPORTED_SPEED_SETTING        "useReportedSpeed"
#define USE_REPORTED_SPEED_DEFAULT        false
#define DATA_USE_DEM_SETTING              "dataUseDEM"
#define DATA_USE_DEM_DEFAULT              false
#define SHOW_SECONDARY_ELEVATION_SETTING  "showSecondaryElevation"
#define SHOW_SECONDARY_ELEVATION_DEFAULT  false
#define SHOW_SECONDARY_SPEED_SETTING      "showSecondarySpeed"
#define SHOW_SECONDARY_SPEED_DEFAULT      false
#define TIME_ZONE_SETTING                 "timeZone"
#define USE_SEGMENTS_SETTING              "useSegments"
#define USE_SEGMENTS_DEFAULT              true
#define POI_RADIUS_SETTING                "poiRadius"
#define POI_RADIUS_DEFAULT                (int)(IMPERIAL_UNITS() ? MIINM : KMINM)
#define DEM_URL_SETTING                   "demURL"
#define DEM_URL_DEFAULT                   ""
#define DEM_AUTH_SETTING                  "demAuthentication"
#define DEM_AUTH_DEFAULT                  false
#define DEM_USERNAME_SETTING              "demUsername"
#define DEM_USERNAME_DEFAULT              ""
#define DEM_PASSWORD_SETTING              "demPassword"
#define DEM_PASSWORD_DEFAULT              ""
#define POSITION_PLUGIN_SETTING           "positionPlugin"
#define POSITION_PLUGIN_DEFAULT           POSITION_PLUGIN()
#define POSITION_PLUGIN_PARAMS_PREFIX     "pluginParameters"
#define POSITION_PLUGIN_PARAMS_PLUGIN     "plugin"
#define POSITION_PLUGIN_PARAMS_PARAM      "parameters"
#define USE_OPENGL_SETTING                "useOpenGL"
#define USE_OPENGL_DEFAULT                false
#define ENABLE_HTTP2_SETTING              "enableHTTP2"
#define ENABLE_HTTP2_DEFAULT              true
#define PIXMAP_CACHE_SETTING              "pixmapCache"
#define PIXMAP_CACHE_DEFAULT              256 /* MB */
#define CONNECTION_TIMEOUT_SETTING        "connectionTimeout"
#define CONNECTION_TIMEOUT_DEFAULT        30 /* s */
#define HIRES_PRINT_SETTING               "hiresPrint"
#define HIRES_PRINT_DEFAULT               false
#define PRINT_NAME_SETTING                "printName"
#define PRINT_NAME_DEFAULT                true
#define PRINT_DATE_SETTING                "printDate"
#define PRINT_DATE_DEFAULT                true
#define PRINT_DISTANCE_SETTING            "printDistance"
#define PRINT_DISTANCE_DEFAULT            true
#define PRINT_TIME_SETTING                "printTime"
#define PRINT_TIME_DEFAULT                true
#define PRINT_MOVING_TIME_SETTING         "printMovingTime"
#define PRINT_MOVING_TIME_DEFAULT         false
#define PRINT_ITEM_COUNT_SETTING          "printItemCount"
#define PRINT_ITEM_COUNT_DEFAULT          true
#define SEPARATE_GRAPH_PAGE_SETTING       "separateGraphPage"
#define SEPARATE_GRAPH_PAGE_DEFAULT       false
#define SLIDER_COLOR_SETTING              "sliderColor"
#define SLIDER_COLOR_DEFAULT              QColor(Qt::red)
#define OUTPUT_PROJECTION_SETTING         "outputProjection"
#define OUTPUT_PROJECTION_DEFAULT         3857
#define INPUT_PROJECTION_SETTING          "inputProjection"
#define INPUT_PROJECTION_DEFAULT          4326
#define HIDPI_MAP_SETTING                 "HiDPIMap"
#define HIDPI_MAP_DEFAULT                 true
#define DATA_PATH_SETTING                 "dataPath"
#define DATA_PATH_DEFAULT                 QString()
#define MAPS_PATH_SETTING                 "mapsPath"
#define MAPS_PATH_DEFAULT                 QString()
#define POI_PATH_SETTING                  "poiPath"
#define POI_PATH_DEFAULT                  QString()

#endif // SETTINGS_H
