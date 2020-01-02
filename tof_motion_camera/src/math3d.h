/**
 * math3d.h
 *
 * @file
 * @copyright Copyright (c) 2015 Elektrobit Automotive GmbH. All rights reserved.
 *
 * @date    $Date:: 2019-12-30  $
 * @version $Revision:: 3801    $
 * @author  $Author:: kumader   $
 */

#ifndef EB_ROBINOS_TOF_MOTION_CAMERA_MATH_3D_H
#define EB_ROBINOS_TOF_MOTION_CAMERA_MATH_3D_H

#include <macro.h>
#include "lidar.h"

class Math3D
{
public:
    /**
    * Rotates points in scanData about the origin
    * @param scanData
    * @param deltaPitch
    * @param deltaYaw
    * @param deltaRoll
    * @return void
    */
    static void RotateScanData(sScanData3D* scanData,
                               const tFloat64 deltaPitch,
                               const tFloat64 deltaYaw,
                               const tFloat64 deltaRoll);

    /**
    * Scales xyz data in scanData
    * @param scanData
    * @param scaleX
    * @param scaleY
    * @param scaleZ
    * @return void
    */
    static void ScaleScanData(sScanData3D* scanData,
                              const tFloat64 scaleX,
                              const tFloat64 scaleY,
                              const tFloat64 scaleZ);

    /**
    * Translates points in scanData
    * @param scanData
    * @param deltaX
    * @param deltaY
    * @param deltaZ
    * @return void
    */
    static void TranslateScanData(sScanData3D* scanData,
                                  const tFloat64 deltaX,
                                  const tFloat64 deltaY,
                                  const tFloat64 deltaZ);

    /**
    * Multiplies two 3x3 matrices and stores result in param, "result"
    * @param m1
    * @param m2
    * @param result
    * @return void
    */
    static void Multiply3x3Matrices(const tFloat64 m1[3][3],
                                    const tFloat64 m2[3][3],
                                    tFloat64 result[3][3]);
    /**
    * Populates points in scanData from 16-bit depth map
    * @param scanData
    * @param deltaX
    * @param deltaY
    * @param deltaZ
    * @return void
    */
    static void PopulateScanDataFromDistanceMap(const tUInt8* distanceMap,
                                                const tInt distanceMapSize, //I don't know why Image::GetSize() returns a signed int, oh well
                                                const tUInt16 distanceMapResolutionX,
                                                const tUInt16 distanceMapResolutionY,
                                                const tFloat64 horizontalFoV,
                                                const tFloat64 verticalFoV,
                                                sScanData3D* scanData);
};
#endif EB_ROBINOS_TOF_MOTION_CAMERA_MATH_3D_H
