/**
 * defines.h
 *
 * @file
 * @copyright Copyright (c) 2015 Elektrobit Automotive GmbH. All rights reserved.
 *
 * @date    $Date:: 2016-10-05 #$
 * @version $Revision:: 4678    $
 * @author  $Author:: jevo8330  $
 */

#ifndef EB_ROBINOS_DEFINES_H
#define EB_ROBINOS_DEFINES_H

/**
 * Factor to calculate from angles in degree to radian.
 */
#ifndef DEG_TO_RAD
#define DEG_TO_RAD (0.01745329238)
#endif

/**
 * Factor to calculate from angles in radian to degree.
 */
#ifndef RAD_TO_DEG
#define RAD_TO_DEG (57.295779513)
#endif

/**
 * Calculates the square product.
 */
#define SQ(x) ((x)*(x))
#ifdef M_PI
#undef M_PI
#endif

/**
 * Defines pi constant
 */
#define M_PI   (3.14159265358979323846)
#ifdef M_PI_2
#undef M_PI_2
#endif

/**
 * Defines pi/2 constant
 */
#define M_PI_2 (1.57079632679489661923)
#ifdef M_PI_4
#undef M_PI_4
#endif

/**
 * Defines pi/4 constant
 */
#define M_PI_4 (0.785398163397448309616)

/**
 * Constant to calculate from meter per second to kilometers per hour.
 */
#define MS_TO_KMH (3.6)
/**
 * Constant to calculate from kilometers per hour to meters per second.
 */
#define KMH_TO_MS (0.277777778)


/**
 * Constant to calculate from millimeter per second to kilometers per hour
 */
#define MMS_TO_KMH (0.0036)

#ifdef WIN32
/** Is not a number */
#define ISNAN(x) _isnan(x)
/** Is infinite */
#define ISINF(x) (!_finite(x))
#else
/** Is not a number */
#define ISNAN(x) std::isnan(x)
/** Is infinite */
#define ISINF(x) std::isinf(x)
#endif

/** Floating point unit error. EKF might show numeric instability. */
#define FPU_ERROR(x) (ISINF(x) || ISNAN(x))

/**
 * Returns the absolute value of parameter x
 */
#ifndef ABS
#define ABS(x) ((x > 0)?(x):-(x))
#endif

/**
 * Function to check if a value is inside a defined range
 */
#define BETWEEN(x, minV, maxV) ((x) > (minV) && (x) < (maxV))


/* ********************************************************************************************* */
/* TYPES and SUBTYPES for automated valet parking data structures                                */
/* ********************************************************************************************* */

/** major type for automated valet parking data structures */
#define MEDIA_TYPE_EB_ROBINOS                               (MEDIA_TYPE_USER + 0xeb01)
/** sub type for sEgoData structure */
#define MEDIA_SUBTYPE_EGO_DATA                               0x0001
/** sub type for tPointCloud3d structure */
#define MEDIA_SUBTYPE_POINT_CLOUD_3D                         0x0002
/** sub type for tOdometry structure */
#define MEDIA_SUBTYPE_ODOMETRY                               0x0003
/** sub type for sParavanState structure */
#define MEDIA_SUBTYPE_PARAVAN_STATE                          0x0004
/** sub type for sControlPositions structure */
#define MEDIA_SUBTYPE_CONTROL_ELEMENT_POSITIONS              0x0005
/** sub type for sPathDescription structure */
#define MEDIA_SUBTYPE_PATH_DESCRIPTION                       0x0006
/** sub type for sExtendedPathData structure */
#define MEDIA_SUBTYPE_EXTENDED_PATH_DESCRIPTION              0x0007
/** sub type for sUltrasonicSensor structure */
#define MEDIA_SUBTYPE_ULTRASONIC_SENSOR                      0x0008
/** sub type for sMeasurementDempsterShafer structure */
#define MEDIA_SUBTYPE_MEASUREMENT_DEMPSTER_SHAFER            0x0009
/** sub type for maximum velocity from eHorizon */
#define MEDIA_SUBTYPE_SPEED_LIMIT                            0x000A
/** sub type for sGridFusionVisualisation structure */
#define MEDIA_SUBTYPE_GRID_FUSION_VISUALIZATION              0x0010
/** sub type for tSlotRequest structure */
#define MEDIA_SUBTYPE_SLOT_REQUEST                           0x0011
/** sub type for tExitRequest structure */
#define MEDIA_SUBTYPE_EXIT_REQUEST                           0x0012
/** sub type for tSlotResponse structure */
#define MEDIA_SUBTYPE_SLOT_RESPONSE                          0x0013
/** sub type for tMapResponse structure */
#define MEDIA_SUBTYPE_MAP_RESPONSE                           0x0014
/** sub type for tPathResponse structure */
#define MEDIA_SUBTYPE_PATH_RESPONSE                          0x0015
/** sub type for tPathAcknowledge structure */
#define MEDIA_SUBTYPE_PATH_ACKNOWLEDGE                       0x0016
/** sub type for tStatusRequest structure */
#define MEDIA_SUBTYPE_STATUS_REQUEST                         0x0017
/** sub type for tStatusResponse structure */
#define MEDIA_SUBTYPE_STATUS_RESPONSE                        0x0018
/** sub type for tWarning structure */
#define MEDIA_SUBTYPE_WARNING                                0x0019
/** sub type for tAbort structure */
#define MEDIA_SUBTYPE_ABORT                                  0x0020
/** sub type for sPoint2D structure */
#define MEDIA_SUBTYPE_POINT_2D                               0x0021
/** sub type for sPoint6D structure */
#define MEDIA_SUBTYPE_POINT_6D                               0x0022
/** sub type for sCarCommand structure */
#define MEDIA_SUBTYPE_CAR_COMMAND                            0x0023
/** sub type for sCarState structure */
#define MEDIA_SUBTYPE_CAR_STATE                              0x0024
/** sub type for sParkingFinished structure */
#define MEDIA_SUBTYPE_PARKING_FINISHED                       0x0025
/** sub type for sOdometry structure */
#define MEDIA_SUBTYPE_SFM_ODOMETRY                           0x0026
/** sub type for sPointList2D */
#define MEDIA_SUBTYPE_POINT_LIST_2D                          0x0027
/** sub type for sParavanCommands structure */
#define MEDIA_SUBTYPE_PARAVAN_COMMANDS                       0x0028
/** sub type for sLoggingMessages structure */
#define MEDIA_SUBTYPE_LOGGING_MESSAGES                       0x0029
/** sub type for sOpticalFlowData structure */
#define MEDIA_SUBTYPE_OPTICAL_FLOW_DATA                      0x0030
/** sub type for sMeasurementVelocity structure */
#define MEDIA_SUBTYPE_MEASUREMENT_VELOCITY                   0x0031
/** sub type for sScanData structure */
#define MEDIA_SUBTYPE_SCAN_DATA                              0x0032
/** sub type for sPolylineObjectList structure */
#define MEDIA_SUBTYPE_POLYLINE_OBJECT_LIST                   0x0033
/** sub type for sLocationAndVelocity structure */
#define MEDIA_SUBTYPE_LOCATION_AND_VELOCITY                  0x0034
/** sub type for sAlgorithmVisualizationData structure */
#define MEDIA_SUBTYPE_ALGORITHM_VISUALIZATION_DATA           0x0035
/** sub type for a path planning algorithm */
#define MEDIA_SUBTYPE_PATH_PLANNING_ALGORITHM                0x0036
/** sub type for a configuration space */
#define MEDIA_SUBTYPE_PATH_PLANNING_CONFIGURATION_SPACE      0x0037
/** sub type for cost parameters */
#define MEDIA_SUBTYPE_PATH_PLANNING_COST_PARAMETERS          0x0038
/** sub type for the node based data */
#define MEDIA_SUBTYPE_PATH_PLANNING_NODE_BASED_DATA          0x0039
/** sub type for the precomputed costs */
#define MEDIA_SUBTYPE_PATH_PLANNING_PRECOMPUTED_COSTS        0x003A
/** sub type for a configuration space */
#define MEDIA_SUBTYPE_PATH_PLANNING_DATA_SOURCE              0x003B
/** sub type for golf 7 state */
#define MEDIA_SUBTYPE_GOLF7_STATE                            0x003C
/** sub type for path evaluation data */
#define MEDIA_SUBTYPE_PATH_EVALUATION_DATA                   0x003D
/** sub type for turning radius data */
#define MEDIA_SUBTYPE_TURNING_RADIUS_DATA                    0x003E
/** sub type for AUTOSAR messagebus data frame container */
#define MEDIA_SUBTYPE_GENERIC_AR_MEDIASAMPLE                 0x003F
/** sub type for sMeasurementBayes structure */
#define MEDIA_SUBTYPE_MEASUREMENT_BAYES                      0x0040
/** sub type for osm graph data */
#define MEDIA_SUBTYPE_PATH_PLANNING_OSM_GRAPH                0x0041
/** sub type for Gem measurement data */
#define MEDIA_SUBTYPE_MEASUREMENT_GEM                        0x0042
/** sub type for Gem 3D scan data */
#define MEDIA_SUBTYPE_GEM_SCAN_DATA                          0x0043
/** sub type for Gem filtered 3D scan data */
#define MEDIA_SUBTYPE_GEM_SCAN_DATA_FILTERED                 0x0044
/** sub type for Gem data for the particle filter */
#define MEDIA_SUBTYPE_GEM_DATA_FOR_PARTICLE_FILTER           0x0045
/** sub type for Gem data for HD Positioning */
#define MEDIA_SUBTYPE_EGO_DATA_FOR_HD_POS                    0x0046
/** sub type for particle filter output*/
#define MEDIA_SUBTYPE_GEM_PARTICLE_FILTER_OUTPUT             0x0047
/** sub type for particle filter best match*/
#define MEDIA_SUBTYPE_GEM_PARTICLE_FILTER_BEST_MATCH         0x0048
/** sub type for sensor calibration values*/
#define MEDIA_SUBTYPE_GEM_SENSOR_CALIBRATION                 0x0049

/** major type for hd positioning data structures */
#define MEDIA_TYPE_EB_ROBINOS_HDP                            0x0001EB02
/** sub type for hd positioning local ego data output */
#define MEDIA_SUBTYPE_HDP_EGO_DATA_LOCAL_OUT                 0x0001
/** sub type for hd positioning global ego data output */
#define MEDIA_SUBTYPE_HDP_EGO_DATA_GLOBAL_OUT                0x0002
/** sub type for hd positioning raw data input */
#define MEDIA_SUBTYPE_HDP_RAW_IN                             0x0004

#endif /* EB_ROBINOS_DEFINES_H */
