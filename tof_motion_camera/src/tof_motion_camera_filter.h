/**
 * tof_motion_camera_filter.h
 *
 * @file
 * @copyright Copyright (c) 2015 Elektrobit Automotive GmbH. All rights reserved.
 *
 * @date    $Date:: 2016-08-31 #$
 * @version $Revision:: 3788    $
 * @author  $Author:: pike9269  $
 */

#ifndef EB_ROBINOS_TOF_MOTION_CAMERA_H
#define EB_ROBINOS_TOF_MOTION_CAMERA_H

#include <macro.h>
#include "version.h"
#include "lidar.h"

#include "Common_UseLogger.h"
#include "UdpFrame_FrameController.h"

/**
 * Filter to convert Quanergy LIDAR data into robinos scan data
 */
class cTofMotionCameraFilter : public adtf::cTimeTriggeredFilter
{
    ADTF_TOOLBOX_FILTER(EB_ROBINOS_TOOLBOX,
                        OID_ADTF_TOF_MOTION_CAMERA_FILTER,
                        NAME_ADTF_TOF_MOTION_CAMERA_FILTER,
                        OBJCAT_CameraDevice);

public:
    static const tChar* OID_ADTF_TOF_MOTION_CAMERA_FILTER;
    static const tChar* NAME_ADTF_TOF_MOTION_CAMERA_FILTER;

    /**
    * Standard Constructor
    */
    cTofMotionCameraFilter(const tChar* __info);

    /**
    * Shutdown function
    * @param i_stage see ADTF documentation
    * @return ADTF error code
    */
    tResult Shutdown(tInitStage i_stage, __exception = NULL);

    /**
    * Init function
    * @param i_stage see ADTF documentation
    * @return ADTF error code
    */
    tResult Init(tInitStage i_stage, __exception = NULL);

    /**
    * Cycle function
    * @return ADTF error code
    */
    tResult Cycle(__exception = NULL);


private:

    /**
    * Send converted scan data to other components via output pin
    * @param i_lidarData stores scan data to be sent
    * @return ADTF error code
    */
    tResult SendOutputs();

    /**
    * Changes physical camera's settings based upon filter settings. Note that changing image
    * format from DISTAMP will render the filter unable to read transmitted frames unless other
    * cases are first implemented
    * @param i_logLevel log setting for Cfl::SetController instance
    * @param i_timeoutUsec timeout setting for Cfl::SetController instance
    * @return ADTF error code
    */
    tResult UpdateCameraSettings(const Common::UseLogger::LogLevel_e i_logLevel,
                                 const tUInt32 i_timeoutUsec);

    /**
    * Calculates projection from distance map into 3D point cloud
    * @param N/A
    * @return void
    */
    void PopulatePointCloudFromDistanceMap();

    /**
    * Rotates points in m_scanData3D about the origin
    * @param deltaPitch
    * @param deltaYaw
    * @param deltaRoll
    * @return void
    */
    void RotateScanData(const tFloat64 deltaPitch,
                        const tFloat64 deltaYaw,
                        const tFloat64 deltaRoll);

    /**
    * Scales xyz data in m_scanData3D
    * @param scaleX
    * @param scaleY
    * @param scaleZ
    * @return void
    */
    void ScaleScanData(const tFloat64 scaleX,
        const tFloat64 scaleY,
        const tFloat64 scaleZ);

    /**
    * Translates points in m_scanData3D
    * @param deltaX
    * @param deltaY
    * @param deltaZ
    * @return void
    */
    void TranslateScanData(const tFloat64 deltaX,
                           const tFloat64 deltaY,
                           const tFloat64 deltaZ);

    static void Multiply3x3Matrices(const tFloat64 m1[3][3],
                                    const tFloat64 m2[3][3],
                                    tFloat64 result[3][3]);
    static void ApplyGain(tUInt8* data, const tUInt8 gain, const tInt size);

    static void LogInfo(const cString infoString);
    static void LogError(const cString errorString);
    //static tUInt16 ReverseBits(const tUInt16 num);
    //void ConvertDistanceImage(sScanData* outScanData);
    //static std::vector<tUInt8> convertScalarRasterToRedGreenRaster(tUInt8* input, tUInt64 size);
    //static void interpolateScalarToRedGreen(tUInt16 scalar, tUInt8& outRed, tUInt8& outGreen);

    static const cString PROPERTY_UDP_TIMEOUT_USEC;
    static const cString PROPERTY_UDP_LISTENING_PORT;
    static const cString PROPERTY_CAMERA_MOUNT_POS_X;
    static const cString PROPERTY_CAMERA_MOUNT_POS_Y;
    static const cString PROPERTY_CAMERA_MOUNT_POS_Z;
    static const cString PROPERTY_CAMERA_MOUNT_PITCH;
    static const cString PROPERTY_CAMERA_MOUNT_YAW;
    static const cString PROPERTY_CAMERA_MOUNT_ROLL;
    static const cString PROPERTY_DISTANCE_GAIN;
    static const cString PROPERTY_AMPLITUDE_GAIN;
    static const cString PROPERTY_CAMERA_LOG_LEVEL;
    static const cString PROPERTY_UPDATE_CAMERA_SETTINGS;
    static const cString PROPERTY_CAMERA_SETTINGS_TCPIP_ADDR;
    static const cString PROPERTY_CAMERA_SETTINGS_TCPIP_PORT;
    static const cString PROPERTY_CAMERA_SETTINGS_IMAGE_FORMAT;

    static const tUInt32 PROPERTY_UDP_TIMEOUT_USEC_DEFAULT;
    static const tUInt16 PROPERTY_UDP_LISTENING_PORT_DEFAULT;
    static const tFloat PROPERTY_CAMERA_MOUNT_POS_X_DEFAULT;
    static const tFloat PROPERTY_CAMERA_MOUNT_POS_Y_DEFAULT;
    static const tFloat PROPERTY_CAMERA_MOUNT_POS_Z_DEFAULT;
    static const tFloat PROPERTY_CAMERA_MOUNT_PITCH_DEFAULT;
    static const tFloat PROPERTY_CAMERA_MOUNT_YAW_DEFAULT;
    static const tFloat PROPERTY_CAMERA_MOUNT_ROLL_DEFAULT;
    static const tUInt8 PROPERTY_DISTANCE_GAIN_DEFAULT;
    static const tUInt8 PROPERTY_AMPLITUDE_GAIN_DEFAULT;
    static const tUInt8 PROPERTY_LOG_LEVEL_DEFAULT;
    static const tBool PROPERTY_UPDATE_CAMERA_SETTINGS_DEFAULT;
    static const cString PROPERTY_CAMERA_SETTINGS_TCPIP_ADDR_DEFAULT;
    static const tUInt16 PROPERTY_CAMERA_SETTINGS_TCPIP_PORT_DEFAULT;
    static const tUInt8 PROPERTY_CAMERA_SETTINGS_IMAGE_FORMAT_DEFAULT;

    static const tUInt8 TOF_COLOR_DEPTH_BITS;
    static const tUInt8 TOF_FRAME_HEADER_SIZE_BYTES;
    static const cImage::tPixelFormat TOF_PIXEL_FORMAT;
    static const tUInt16 TOF_RESOLUTION_X;
    static const tUInt16 TOF_RESOLUTION_Y;
    static const tUInt16 TOF_BYTES_PER_LINE;
    static const tUInt32 TOF_FRAME_SIZE;

    static const tFloat TOF_HORIZONTAL_FOV;
    static const tFloat TOF_VERTICAL_FOV;

    std::unique_ptr<UdpFrame::FrameController> m_frameController;
    adtf::cVideoPin m_outputDistanceImage;
    adtf::cVideoPin m_outputAmplitudeImage;
    adtf::cOutputPin m_outputScanData;
    adtf_util::cImage m_distanceImage;
    adtf_util::cImage m_amplitudeImage;
    tInt8 m_distGain;
    tInt8 m_ampGain;
    sScanData3D m_scanData3D;
    tUInt8* m_imageBuffer;
    tUInt8* m_scanDataBuffer;
};
#endif // EB_ROBINOS_TOF_MOTION_CAMERA_H
