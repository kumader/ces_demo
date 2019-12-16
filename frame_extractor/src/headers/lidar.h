/**
 * lidar.h
 *
 * @file
 * @copyright Copyright (c) 2015 Elektrobit Automotive GmbH. All rights reserved.
 *
 * @date    $Date:: 2016-06-07 #$
 * @version $Revision:: 2196    $
 * @author  $Author:: casc921   $
 */

#ifndef EB_ROBINOS_LIDAR_H
#define EB_ROBINOS_LIDAR_H

#include "common.h"

#define USE_CUSTOM_SCAN_DATA

#pragma pack(push, 1)
/**
 * Data structure for Lidar Scan Points in 2D
 */
struct sLidarPoint2D
{
    /**
     * Enum that describes the scan point flag
     */
    enum eLidarPointFlag
    {
        LIDAR_POINT_VALID,
        LIDAR_POINT_UNKNOWN,
        LIDAR_POINT_GROUND,
        LIDAR_POINT_DIRT = 42
    };

    sPoint2D<>      lidarPoint; ///< (x, y) Cartesian coordinates
    eLidarPointFlag flag;       ///< Flag, e.g. ground

    /**
     * Default constructor
     */
    sLidarPoint2D(): flag(LIDAR_POINT_UNKNOWN) {}
};
#pragma pack(pop)

#pragma pack(push, 1)
/**
 * Data structure for Lidar Scan Points in 3D
 */
struct sLidarPoint3D
{
    /**
     * Enum that describes the scan point flag
     */

#ifdef USE_CUSTOM_SCAN_DATA
    sPoint3D<tFloat32> lidarPoint; ///< (x, y, z) Cartesian coordinates
#else
    sPoint3D<> lidarPoint; ///< (x, y, z) Cartesian coordinates
#endif
    
    tUInt8 layer; ///< Scan layer, from which the scan point is taken
    tFloat32 radialDistance; ///< Distance between sensor and measured contact in m
    tFloat32 angle; ///< horizontal angle of the ray measuring the point in rad
    sLidarPoint2D::eLidarPointFlag flag; ///< Flag, e.g. ground

    /**
     * Default constructor
     */
    sLidarPoint3D()
    : lidarPoint()
    , layer(0)
    , radialDistance(0.0)
    , angle(0.0)
    , flag(sLidarPoint2D::LIDAR_POINT_UNKNOWN)
    {
    }

    /**
     * @brief Constructor of sLidarPoint3D with values of all members as parameters.
     *
     * @param i_lidarPoint The Lidar measurement point cooridnate as sPoint3D object.
     * @param i_layer The scan data layer of the measurement.
     * @param i_radialDistance The radial distance of the measurement.
     * @param i_angle The horizontal rotation angle of the Lidar scan in [rad].
     * @param i_flag Flag which specify the measurement as e.g. valid, groud, etc.
     */
    sLidarPoint3D(
#ifdef USE_CUSTOM_SCAN_DATA
        sPoint3D<tFloat32> i_lidarPoint,
#else
        sPoint3D<> i_lidarPoint,
#endif
        tUInt8 i_layer,
        tFloat32 i_radialDistance,
        tFloat32 i_angle,
        sLidarPoint2D::eLidarPointFlag i_flag)
    : lidarPoint(i_lidarPoint)
    , layer(i_layer)
    , radialDistance(i_radialDistance)
    , angle(i_angle)
    , flag(i_flag)
    {
    }

    /**
     * @brief Comparison operator.
     *
     * @param i_rhs The right hand side sLidarPoint3D object of the comparison operation.
     * @return True if the given sLidarPoint3D is equal to this one and false if not.
     */
    bool operator == (const sLidarPoint3D& i_rhs) const
    {
        return (lidarPoint == i_rhs.lidarPoint)
            && (layer == i_rhs.layer)
            && (radialDistance == i_rhs.radialDistance)
            && (angle == i_rhs.angle)
            && (flag == i_rhs.flag);
    }
};
#pragma pack(pop)

/**
 * This structure holds the mounting position and the scan data that comes from the LIDAR sensor.
 */
#pragma pack(push, 1)
struct sScanData
{
    sPoint6D<>     mountingPosition; ///< Mounting position of sensor
    tUInt16        pointsCount;      ///< Number of points
    sLidarPoint2D  *points;          ///< The list of points

    /**
     * Default constructor
     */
    sScanData(): pointsCount(0), points(NULL) {}

    /**
     * Constructor that is allocating dynamic memory to the points member variable
     * depending by the value of the i_pointsCount parameter
     *
     * @param i_pointsCount The length of block memory to be allocated
     */
    sScanData(const tUInt16 &i_pointsCount): pointsCount(i_pointsCount), points(NULL)
    {
        if (pointsCount)
        {
            points = new sLidarPoint2D[pointsCount];
        }
    }

    /**
     * Copy constructor
     * @param other object to be copied
     */
    sScanData(const sScanData &other) : mountingPosition(other.mountingPosition),
        pointsCount(other.pointsCount), points(NULL)
    {
        if (pointsCount)
        {
            points = new sLidarPoint2D[pointsCount];
            for (tUInt32 i(0); i < pointsCount; ++i)
            {
                points[i] = other.points[i];
            }
        }
    }

    /**
     * Assignment operator
     * @param other object to be assigned
     * @return *this reference
     */
    sScanData& operator=(const sScanData &other)
    {
        if (this != &other)
        {
            mountingPosition = other.mountingPosition;
            pointsCount = other.pointsCount;

            if (points != NULL)
            {
                delete [] points;
            }
            points = NULL;
            if (pointsCount)
            {
                points = new sLidarPoint2D[pointsCount];
                for (tUInt32 i(0); i < pointsCount; ++i)
                {
                    points[i] = other.points[i];
                }
            }
        }
        return *this;
    }

    /**
     * Destructor
     */
    ~sScanData()
    {
        delete [] points;
    }
};
#pragma pack(pop)

/**
 * This structure holds the mounting position and the 3D scan data that comes from the LIDAR sensor.
 */
#pragma pack(push, 1)
struct sScanData3D
{
    sPoint6D<>     mountingPosition; ///< Mounting position of sensor
#ifdef USE_CUSTOM_SCAN_DATA
    tUInt32        pointsCount;      ///< Number of points
#else
    tUInt16        pointsCount;      ///< Number of points
#endif
    sLidarPoint3D  *points;          ///< The list of points

    /**
     * Default constructor
     */
    sScanData3D(): pointsCount(0), points(NULL) {}

    /**
     * Constructor that is allocating dynamic memory to the points member variable
     * depending by the value of the i_pointsCount parameter
     *
     * @param i_pointsCount The length of block memory to be allocated
     */
    sScanData3D(const tUInt32 &i_pointsCount): pointsCount(i_pointsCount), points(NULL)
     {
        if (pointsCount)
        {
            points = new sLidarPoint3D[pointsCount];
        }
    }

    /**
     * Copy constructor
     * @param other object to be copied
     */
    sScanData3D(const sScanData3D &other) : mountingPosition(other.mountingPosition),
        pointsCount(other.pointsCount), points(NULL)
    {
        if (pointsCount)
        {
            points = new sLidarPoint3D[pointsCount];
            for (tUInt32 i(0); i < pointsCount; ++i)
            {
                points[i] = other.points[i];
            }
        }
    }

    /**
     * Assignment operator
     * @param other object to be assigned
     * @return *this reference
     */
    sScanData3D& operator=(const sScanData3D &other)
    {
        if (this != &other)
        {
            mountingPosition = other.mountingPosition;
            pointsCount = other.pointsCount;

            if (points != NULL)
            {
                delete [] points;
            }
            points = NULL;
            if (pointsCount)
            {
                points = new sLidarPoint3D[pointsCount];
                for (tUInt32 i(0); i < pointsCount; ++i)
                {
                    points[i] = other.points[i];
                }
            }
        }
        return *this;
    }

    /**
     * Destructor
     */
    ~sScanData3D()
    {
        delete [] points;
    }

    /**
     * @brief Comparison operator.
     *
     * @param i_rhs The right hand side tPointCsScanData3Dd object of the comparison operation.
     * @return True if the given sScanData3D is equal to this one and false if not.
     */
    bool operator == (const sScanData3D& i_rhs) const
    {
        bool retVal = (pointsCount == i_rhs.pointsCount) && (mountingPosition == i_rhs.mountingPosition);

        if (retVal)
        {
            for (tUInt32 pointIdx = 0; pointIdx < pointsCount; ++pointIdx)
            {
                retVal = (points[pointIdx] == i_rhs.points[pointIdx]);
                if (!retVal)
                {
                    break;
                }
            }
        }   

        return retVal;
    }
};
#pragma pack(pop)

/**
 * This structure holds a ployline object that comes from the LIDAR sensor.
 */
#pragma pack(push, 1)
struct sPolylineObject
{
    tUInt16 id;                     ///< Unique identifier
    tFloat64 timestamp;             ///< Current timestamp [s]
    tFloat64 age;                   ///< Time since creation [s]
    sPoint2D<> velocity;            ///< Velocity [m/s]
    tUInt16 pointsCount;            ///< Number of contour points
    sPoint2D<>* points;             ///< List of contour points

    /**
     * Default constructor
     */
    sPolylineObject(): id(0), timestamp(0.), age(0.), pointsCount(0), points(NULL) {}

    /**
     * Constructor that is allocating dynamic memory to the points member variable
     * depending by the value of the i_pointsCount parameter
     *
     * @param i_pointsCount the length of block memory to be allocated
     */
    sPolylineObject(const tUInt16 &i_pointsCount): id(0), timestamp(0.), age(0.),
        pointsCount(i_pointsCount), points(NULL)
    {
        if (pointsCount)
        {
            points = new sPoint2D<>[pointsCount];
        }
    }

    /**
     * Copy constructor
     * @param other object to be copied
     */
    sPolylineObject(const sPolylineObject &other) : id(other.id), timestamp(other.timestamp),
        age(other.age), pointsCount(other.pointsCount), points(NULL), velocity(other.velocity)
    {
        if (pointsCount)
        {
            points = new sPoint2D<>[pointsCount];
            for (tUInt32 i(0); i < pointsCount; ++i)
            {
                points[i] = other.points[i];
            }
        }
    }

    /**
     * Assignment operator
     * @param other object to be assigned
     * @return *this reference
     */
    sPolylineObject& operator=(const sPolylineObject &other)
    {
        if (this != &other)
        {
            id = other.id;
            timestamp = other.timestamp;
            age = other.age;
            velocity = other.velocity;
            pointsCount = other.pointsCount;

            if (points != NULL)
            {
                delete [] points;
            }
            points = NULL;

            if (pointsCount)
            {
                points = new sPoint2D<>[pointsCount];

                for (tUInt32 i(0); i < pointsCount; ++i)
                {
                    points[i] = other.points[i];
                }
            }
        }
        return *this;
    }

    /**
     * Destructor
     */
    ~sPolylineObject()
    {
        delete [] points;
    }
};
#pragma pack(pop)

/**
 * This structure holds a list of ployline objects that comes from the LIDAR sensor.
 */
#pragma pack(push, 1)
struct sPolylineObjectList
{
    tUInt16 objectsCount;            ///< Number of objects
    sPolylineObject* objects;        ///< List of objects

    /**
     * Default constructor
     */
    sPolylineObjectList(): objectsCount(0), objects(NULL) {}

    /**
     * Constructor that is allocating dynamic memory to the points member variable
     * depending by the value of the i_objectsCount parameter
     *
     * @param i_objectsCount The length of block memory to be allocated
     */
    sPolylineObjectList(const tUInt16 &i_objectsCount): objectsCount(i_objectsCount), objects(NULL)
    {
        if (objectsCount)
        {
            objects = new sPolylineObject[objectsCount];
        }
    }

    /**
     * Copy constructor
     * @param other object to be copied
     */
    sPolylineObjectList(const sPolylineObjectList &other) : objectsCount(other.objectsCount), objects(NULL)
    {
        if (objectsCount)
        {
            objects = new sPolylineObject[objectsCount];
            for (tUInt32 i(0); i < objectsCount; ++i)
            {
                objects[i] = other.objects[i];
            }
        }
    }

    /**
     * Assignment operator
     * @param other object to be assigned
     * @return *this reference
     */
    sPolylineObjectList& operator=(const sPolylineObjectList &other)
    {
        if (this != &other)
        {
            objectsCount = other.objectsCount;

            if (objects != NULL)
            {
                delete [] objects;
            }
            objects = NULL;

            if (objectsCount)
            {
                objects = new sPolylineObject[objectsCount];

                for (tUInt32 i(0); i < objectsCount; ++i)
                {
                    objects[i] = other.objects[i];
                }
            }
        }
        return *this;
    }

    /**
     * Destructor
     */
    ~sPolylineObjectList()
    {
        delete [] objects;
    }
};
#pragma pack(pop)

/**
* Source type enum.
*/
enum eSrcType : tUInt16 {
    SRCTYPE_UNKNOWN = 0,    ///< default value
    SRCTYPE_SENSOR = 1,     ///< source is a sensor
    SRCTYPE_FUSION = 2      ///< source is a fusion block
};
#define MSGSRC "tMsgSrc"
#pragma pack(push,1)
/**
* Struct representing a message source.
* Size 6 byte.
*/
struct tMsgSrc {
    eSrcType type;  ///< type of the message src
    tUInt32 id;    ///< the pair of type:id should be unique in the system
};
#pragma pack(pop)

#define MSGINFO "tMsgInfo"
#pragma pack(push,1)
/**
* Struct representing further message information.
* Size 12 byte.
*/
struct tMsgInfo {
    tUInt32 vendorID;  ///< unique vendor id (maintained by EB)
    tUInt32 msgType;   ///< vendor specific type identifier
    tUInt32 msgVersion;///< version of the message type
};
#pragma pack(pop)

#define HEADER "tHeader"
#pragma pack(push,1)
/**
* Struct representing the complete header of a message.
* Size 19 byte.
*/
struct tHeader {
    tUInt8 isValid;        ///< valid flag
                            //tTimestamp timestamp;   // timestamp of this message
    tMsgSrc src;            ///< the source of this message
    tMsgInfo info;          ///< further information about this message
};
#pragma pack(pop)


#define ACTUATOR "tActuator"
#pragma pack(push,1)

#define RIGHT_INDICATOR 1
#define LEFT_INDICATOR 2
#define BRAKE_LIGHT 4
#define HEAD_LIGHT 8
#define REVERSE_LIGHT 16

/**
* Struct representing an actuator message.
*/
struct tActuator 
{
    tHeader header;     ///< message header
    tUInt8 lightMask;  ///< | REV | HEADLIGHT | BREAK | TURNL | TURNR | (binary 1 means on)
    tUInt8 controlMask;///< | SPEED | STEERING | (binary 1 means controlled by adtf)
    double speed;       ///< speed in m/s
    double steering;    ///< steering in rad
    double speedPrio;
    double steeringPrio;
};
#pragma pack(pop)

#pragma pack(push,1)
/**
* This structure contains the control to the BFFT model cars. It is especially designed for that car.
*/
struct sModelCarState
{
    tBool turnSignalLeft;   ///< Turn signal left
    tBool turnSignalRight;  ///< Turn signal right
    tBool hazardLight;      ///< Hazard light
    tBool parkingLight;     ///< Parking light
    tBool lowerBeam;        ///< Lower beam
    tBool fullBeam;         ///< Full beam

    tFloat64 speed;			///< Speed
    tFloat64 steerAngle;  	///< Steering angle

    /**
    * default constructor
    */
    sModelCarState() : turnSignalLeft(tFalse), turnSignalRight(tFalse),
        hazardLight(tFalse), parkingLight(tFalse), lowerBeam(tFalse), fullBeam(tFalse), speed(0), steerAngle(0) {}

    /**
    * constructor from actuator
    */
    sModelCarState(tActuator actuator) : parkingLight(tFalse), fullBeam(tFalse) {
        turnSignalLeft = (actuator.lightMask & LEFT_INDICATOR) != 0;
        turnSignalRight = (actuator.lightMask & RIGHT_INDICATOR) != 0;
        if (turnSignalLeft && turnSignalRight) { // Hazard Light
            turnSignalLeft = tFalse;
            turnSignalRight = tFalse;
            hazardLight = tTrue;
        }
        else {
            hazardLight = tFalse;
        }
        lowerBeam = (actuator.lightMask & HEAD_LIGHT) != 0;

        speed = actuator.speed;
        steerAngle = actuator.steering;
    }
};

#pragma pack(pop)

/**
 * This function generates a polyline object list based on a given buffer.
 * The buffer shall contain all polyline object list information in the correct order.
 *
 * @param i_buffer The buffer to be processed
 * @param o_polyLineObjectList the polyline object list to be generated
 * @return Standard ADTF return code
 */
inline tResult GeneratePolyLineListFromBuffer(tUInt8 *i_buffer, sPolylineObjectList &o_polyLineObjectList)
{
    tUInt32 bufferCnt = 0;

    o_polyLineObjectList.objectsCount = GetUInt16FromBuffer(i_buffer, bufferCnt);
    o_polyLineObjectList.objects = new sPolylineObject [o_polyLineObjectList.objectsCount];
    for (tUInt32 i = 0; i < o_polyLineObjectList.objectsCount; i++)
    {
        o_polyLineObjectList.objects[i].id = GetUInt16FromBuffer(i_buffer, bufferCnt);
        o_polyLineObjectList.objects[i].timestamp = GetFloat64FromBuffer(i_buffer, bufferCnt);
        o_polyLineObjectList.objects[i].age = GetFloat64FromBuffer(i_buffer, bufferCnt);

        o_polyLineObjectList.objects[i].velocity.x = GetFloat64FromBuffer(i_buffer, bufferCnt);
        o_polyLineObjectList.objects[i].velocity.y = GetFloat64FromBuffer(i_buffer, bufferCnt);
        o_polyLineObjectList.objects[i].pointsCount = GetUInt16FromBuffer(i_buffer, bufferCnt);

        o_polyLineObjectList.objects[i].points = new sPoint2D<> [o_polyLineObjectList.objects[i].pointsCount];

        for (tUInt32 j = 0; j < o_polyLineObjectList.objects[i].pointsCount; j++)
        {
            o_polyLineObjectList.objects[i].points[j].x = GetFloat64FromBuffer(i_buffer, bufferCnt);
            o_polyLineObjectList.objects[i].points[j].y = GetFloat64FromBuffer(i_buffer, bufferCnt);
        }
    }
    RETURN_NOERROR;
}


/**
 * This function generates a buffer containing a polyline object list object.
 *
 * @param i_polyLineObjectList The polyline object list to be processed.
 * @param o_buffer The buffer to be calculated
 * @param io_bufferCounter First byte position as input, last byte position as output
 * @return Standard ADTF return code
 */
inline tResult GenerateBufferForPolyLineObjectList(const sPolylineObjectList &i_polyLineObjectList,
                                                tUInt8 *&o_buffer,
                                                tUInt32 &io_bufferCounter)
{
    //////////////////////////////////////////////////////////////////////////
    // check the buffer
    if (o_buffer == NULL)
    {
        return ERR_POINTER;
    }

    CopyUInt16ValToBuffer(i_polyLineObjectList.objectsCount, o_buffer, io_bufferCounter);

    for (tUInt16 i = 0; i < i_polyLineObjectList.objectsCount; i++)
    {
        CopyUInt16ValToBuffer(i_polyLineObjectList.objects[i].id, o_buffer, io_bufferCounter);
        CopyFloat64ValToBuffer(i_polyLineObjectList.objects[i].timestamp, o_buffer, io_bufferCounter);
        CopyFloat64ValToBuffer(i_polyLineObjectList.objects[i].age, o_buffer, io_bufferCounter);
        CopyFloat64ValToBuffer(i_polyLineObjectList.objects[i].velocity.x, o_buffer, io_bufferCounter);
        CopyFloat64ValToBuffer(i_polyLineObjectList.objects[i].velocity.y, o_buffer, io_bufferCounter);
        CopyUInt16ValToBuffer(i_polyLineObjectList.objects[i].pointsCount, o_buffer, io_bufferCounter);

        for (tUInt16 j = 0; j < i_polyLineObjectList.objects[i].pointsCount; j++)
        {
            CopyFloat64ValToBuffer(i_polyLineObjectList.objects[i].points[j].x, o_buffer, io_bufferCounter);
            CopyFloat64ValToBuffer(i_polyLineObjectList.objects[i].points[j].y, o_buffer, io_bufferCounter);
        }
    }

    RETURN_NOERROR;
 }



#endif // EB_ROBINOS_LIDAR_H
