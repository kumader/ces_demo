/**
 * math3d.cpp
 *
 * @file
 * @copyright Copyright (c) 2015 Elektrobit Automotive GmbH. All rights reserved.
 *
 * @date    $Date:: 2019-12-30  $
 * @version $Revision:: 3801    $
 * @author  $Author:: kumader   $
 */

#include "stdafx.h"
#include <sstream>

#include "math3d.h"

void Math3D::RotateScanData(sScanData3D* scanData,
                            const tFloat64 deltaPitch,
                            const tFloat64 deltaYaw,
                            const tFloat64 deltaRoll)
{
    //set up rotation matrices
    tFloat64 xRotMatrix[3][3] = { {1.0, 0.0, 0.0},
                                  {0.0, cos(deltaPitch), sin(deltaPitch)},
                                  {0.0, -sin(deltaPitch), cos(deltaPitch)} };
    tFloat64 yRotMatrix[3][3] = { {cos(deltaYaw), 0.0, -sin(deltaYaw)},
                                  {0.0, 1.0, 0.0},
                                  {sin(deltaYaw), 0.0, cos(deltaYaw)} };
    tFloat64 zRotMatrix[3][3] = { {cos(deltaRoll), sin(deltaRoll), 0.0},
                                  {-sin(deltaRoll), cos(deltaRoll), 0.0},
                                  {0.0, 0.0, 1.0} };
    tFloat64 xyResult[3][3] = { {0.0, 0.0, 0.0},
                                {0.0, 0.0, 0.0},
                                {0.0, 0.0, 0.0} };
    tFloat64 result[3][3] = { {0.0, 0.0, 0.0},
                              {0.0, 0.0, 0.0},
                              {0.0, 0.0, 0.0} };

    //concatenate x, y, and z matrices
    Multiply3x3Matrices(xRotMatrix, yRotMatrix, xyResult);
    Multiply3x3Matrices(xyResult, zRotMatrix, result);

    for (tUInt32 i = 0; i < scanData->pointsCount; ++i)
    {
        tFloat32 x = scanData->points[i].lidarPoint.x;
        tFloat32 y = scanData->points[i].lidarPoint.y;
        tFloat32 z = scanData->points[i].lidarPoint.z;

        tFloat32 xPrime = static_cast<tFloat32>((result[0][0] * x) + (result[0][1] * y) + (result[0][2] * z));
        tFloat32 yPrime = static_cast<tFloat32>((result[1][0] * x) + (result[1][1] * y) + (result[1][2] * z));
        tFloat32 zPrime = static_cast<tFloat32>((result[2][0] * x) + (result[2][1] * y) + (result[2][2] * z));

        scanData->points[i].lidarPoint.x = xPrime;
        scanData->points[i].lidarPoint.y = yPrime;
        scanData->points[i].lidarPoint.z = zPrime;
    }
}

void Math3D::ScaleScanData(sScanData3D* scanData,
                           const tFloat64 scaleX,
                           const tFloat64 scaleY,
                           const tFloat64 scaleZ)
{
    for (tUInt32 i = 0; i < scanData->pointsCount; ++i)
    {
        scanData->points[i].lidarPoint.x = static_cast<tFloat32>(scanData->points[i].lidarPoint.x * scaleX);
        scanData->points[i].lidarPoint.y = static_cast<tFloat32>(scanData->points[i].lidarPoint.y * scaleY);
        scanData->points[i].lidarPoint.z = static_cast<tFloat32>(scanData->points[i].lidarPoint.z * scaleZ);
    }
}

void Math3D::TranslateScanData(sScanData3D* scanData,
                               const tFloat64 deltaX,
                               const tFloat64 deltaY,
                               const tFloat64 deltaZ)
{
    for (tUInt32 i = 0; i < scanData->pointsCount; ++i)
    {
        scanData->points[i].lidarPoint.x += static_cast<tFloat32>(deltaX);
        scanData->points[i].lidarPoint.y += static_cast<tFloat32>(deltaY);
        scanData->points[i].lidarPoint.z += static_cast<tFloat32>(deltaZ);
    }
}

void Math3D::Multiply3x3Matrices(const tFloat64 m1[3][3],
                                 const tFloat64 m2[3][3],
                                 tFloat64 result[3][3])
{
    for (tUInt8 i = 0; i < 3; ++i)
    {
        for (tUInt8 j = 0; j < 3; ++j)
        {
            tFloat sum = 0.0f;

            for (tUInt8 k = 0; k < 3; ++k)
            {
                sum += m1[j][k] * m2[k][i];
            }

            result[j][i] = sum;
        }
    }
}

void Math3D::PopulateScanDataFromDistanceMap(const tUInt8* distanceMap,
                                             const tInt distanceMapSize,
                                             const tUInt16 distanceMapResolutionX,
                                             const tUInt16 distanceMapResolutionY,
                                             const tFloat64 horizontalFoV,
                                             const tFloat64 verticalFoV,
                                             sScanData3D* scanData)
{
    //FILE* f = fopen("d:\\pcl.txt", "a");
    //fputs("start\n", f);

    for (tInt i = 0; i < distanceMapSize / 2; ++i)
    {
        tInt mapIndex = 2 * i;

        tUInt sampleY = i / distanceMapResolutionX;
        tUInt sampleX = i % distanceMapResolutionX;

        //tUInt16 depth = distMap[mapIndex] << 8 | distMap[mapIndex + 1]; //nope, looks terrible
        tUInt16 depth = distanceMap[mapIndex + 1] << 8 | distanceMap[mapIndex]; //why does reversed order bytes provide the most sensical depth values?
        //tUInt16 depth = ReverseBits(distMap[mapIndex] << 8 | distMap[mapIndex + 1]); //nope, looks terrible

        tFloat64 alphaH = (M_PI - horizontalFoV) / 2;
        tFloat64 gammaH = alphaH + (sampleX * (horizontalFoV / distanceMapResolutionX));
        //m_scanData3D.points[i].lidarPoint.x = static_cast<tFloat32>(depth / tan(gammaH));
        tFloat32 x = static_cast<tFloat32>(depth / tan(gammaH));

        tFloat64 alphaV = (2 * M_PI) - (verticalFoV / 2);
        tFloat64 gammaV = alphaV + (sampleY * (verticalFoV / distanceMapResolutionY));
        //m_scanData3D.points[i].lidarPoint.y = static_cast<tFloat32>(-depth * tan(gammaV));
        tFloat32 y = static_cast<tFloat32>(-depth * tan(gammaV));

        //m_scanData3D.points[i].lidarPoint.z = depth;
        tFloat32 z = depth;

        scanData->points[i].lidarPoint.x = x;
        scanData->points[i].lidarPoint.y = y;
        scanData->points[i].lidarPoint.z = z;
    }

    //rotate dataset to about camera origin before translating to mounting position
    RotateScanData(scanData,
                   scanData->mountingPosition.pitch,
                   scanData->mountingPosition.yaw,
                   scanData->mountingPosition.roll);

    //rescale dataset from millimeters to meters
    ScaleScanData(scanData, 0.001, 0.001, 0.001);

    //translate dataset from camera origin to mounting position
    TranslateScanData(scanData,
                      scanData->mountingPosition.x,
                      scanData->mountingPosition.y,
                      scanData->mountingPosition.z);

    //for (tUInt32 i = 0; i < scanData->pointsCount; ++i)
    //{
    //    stringstream ss;
    //    ss << scanData->points[i].lidarPoint.x << " " << scanData->points[i].lidarPoint.y << " " << scanData->points[i].lidarPoint.z << endl;

    //    fputs(ss.str().c_str(), f);
    //}

    //fputs("end\n", f);
    //fclose(f);
}
