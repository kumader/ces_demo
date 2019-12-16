/**
 * common.h
 *
 * @file
 * @copyright Copyright (c) 2015 Elektrobit Automotive GmbH. All rights reserved.
 *
 * @date    $Date:: 2016-10-05 #$
 * @version $Revision:: 4678    $
 * @author  $Author:: jevo8330  $
 */

#ifndef EB_ROBINOS_COMMON_PARAMETERS_H
#define EB_ROBINOS_COMMON_PARAMETERS_H

#include "types.h"
#include "constants.h"
#include "error.h"

#include <limits>
#include <vector>
#include <map>
#include "defines.h"

#include <ostream>
#include <cmath>
#include "memory.h"
#include "stdlib.h"

using namespace std;

/**
 * This structure is representing a two dimensional point. It contains two variables of the template type T.
 */
#pragma pack(push, 1)
template<typename T=tFloat64>
struct sPoint2D
{
    /**
     * The standard constructor is initializing the two variables of the structure with the value 0.
     */
    sPoint2D(): x(0), y(0) {}

    /**
     * This constructor is initializing the member variable with two values that are given by the parameters.
     *
     * @param i_x Initializing x member variable
     * @param i_y Initializing y member variable
     */
    sPoint2D(const T i_x, const T i_y): x(i_x), y(i_y) {}

    /**
     * The copy constructor copies the values from the object given by the parameters. Therefore, the copy constructor
     * is calling the copy constructor of the underlying type.
     *
     * @param other The copy object
     */
    template<typename A>
    sPoint2D(sPoint2D<A> other): x(T(other.x)), y(T(other.y)) {}

    /**
     * @brief Comparison operator for two sPoint2D<T> objects.
     *
     * @param rhs The right hand side sPoint2D<T> object of the comparison.
     * @return True if this sPoint2D<T> object is equal to the given one and false otherwise.
     */
    tBool operator == (const sPoint2D<T>& rhs) const
    {
        return (x == rhs.x) && (y == rhs.y);
    }

    T    x;                    ///< Position on X axis
    T    y;                    ///< Position on Y axis
};
#pragma pack(pop)

/**
 * This operator function checks if two points are equal.
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns true if the points are equal, false otherwise
 */
template<typename T, typename A>
tBool operator==(const sPoint2D<T>& p1, const sPoint2D<A>& p2)
{
    if (p1.x == p2.x && p1.y == p2.y)
    {
        return tTrue;
    }
    else
    {
        return tFalse;
    }
}

/**
 * This operator function checks if two points are not equal.
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns false if the points are equal, true otherwise
 */
template<typename T, typename A>
tBool operator!=(const sPoint2D<T>& p1, const sPoint2D<A>& p2)
{
    return !(p1 == p2);
}

/**
 * This function checks if a point is smaller than another point. The point is considered as being smaller when A: the
 * x-component of point 1 is smaller than the x-component of point 2 or B: when the x-component of both points are
 * equal, but the y-component of point 1 is smaller than the y-component of point 2. In all other cases, point 2 is
 * considered as being bigger.
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns true when point 1 is smaller than point 2
 */
template<typename T, typename A>
tBool operator<(const sPoint2D<T>& p1, const sPoint2D<A>& p2)
{
    if (p1.x < p2.x)
    {
        return tTrue;
    }
    else if (p1.x == p2.x)
    {
        if (p1.y < p2.y)
        {
            return tTrue;
        }
        else
        {
            return tFalse;
        }
    }
    else
    {
        return tFalse;
    }
}

/**
 * This function calculates the difference between two 2D points. It substracts the x and y-components seperately.
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns a point with the difference of point 1 and 2
 */
template<typename T, typename A>
sPoint2D<T> operator-(const sPoint2D<T>& p1, const sPoint2D<A>& p2)
{
    return sPoint2D<T>(p1.x-T(p2.x), p1.y-T(p2.y));
}

/**
 * This function calculates the sum of two 2D points.
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns a point with the sum of point 1 and 2
 */
template<typename T, typename A>
sPoint2D<T> operator+(const sPoint2D<T>& p1, const sPoint2D<A>& p2)
{
    return sPoint2D<T>(p1.x+T(p2.x), p1.y+T(p2.y));
}

/**
 * This function calculates the scalar multiplication of a 2D point.
 *
 * @param p1 Point 1
 * @param m Multiplier
 * @return Returns the point multiplied with the scalar value.
 */
template<typename T>
sPoint2D<T> operator*(const sPoint2D<T>& p1, const T& m)
{
    return sPoint2D<T>(p1.x*m, p1.y*m);
}

/**
 * This function calculates the multiplication of two points according to this:
 * x = x1*x2, y = y1*y2
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns the product of the two points according to the described multiplication
 */
template<typename T, typename A>
sPoint2D<T> operator*(const sPoint2D<T>& p1, const sPoint2D<A>& p2)
{
    return sPoint2D<T>(p1.x*T(p2.x), p1.y*T(p2.y));
}

/**
 * This function calculates the division of two 2D points according to this:
 * x = x1/x2, y = y1/y2
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns the division of the two points according to the described schema
 */
template<typename T, typename A>
sPoint2D<T> operator/(const sPoint2D<T>& p1, const sPoint2D<A>& p2)
{
    return sPoint2D<T>(p1.x/T(p2.x), p1.y/T(p2.y));
}

/**
 * This function calculates the modulo of two points according to this:
 * x = x1%x2, y = y1%y2
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns the modulo of the two points according to the described schema
 */
template<typename T, typename A>
sPoint2D<T> operator%(const sPoint2D<T>& p1, const sPoint2D<A>& p2)
{
    return sPoint2D<T>(p1.x%p2.x, p1.y%p2.y);
}

/**
 * This function creates an stream output for a 2D Point. This can be used to display the points' values.
 *
 * @param i_stream The input stream where to append the new output data
 * @param i_data The 2D point with the data
 * @return Return the new stream object that results from here
 */
template<typename T>
std::ostream &operator<<(std::ostream &i_stream, sPoint2D<T> const &i_data)
{
    return i_stream << "x=" << std::fixed << i_data.x << ", y=" << std::fixed << i_data.y;
}

/**
 * This function calculates the smallest distance between two radian angles.
 *
 * @param i_a Angle a [-2*PI..2*PI]
 * @param i_b Angle b [-2*PI..2*PI]
 * @return Returns the minimum angle difference [0..PI]
 */
template<typename T>
inline T AngleDiff(const T &i_a, const T &i_b)
{
    T i_a_(i_a); T i_b_(i_b);
    if (fabs(i_a_) < M_PI/2 && fabs(i_b_) < M_PI/2)
    {
        return fabs(i_a_ - i_b_);
    }
    i_a_ = T((i_a_ < 0)?i_a_+2*M_PI:i_a_);
    i_b_ = T((i_b_ < 0)?i_b_+2*M_PI:i_b_);
    T i_e = T(fabs(i_a_-i_b_));
    return T((i_e < M_PI)?i_e:2*M_PI-i_e);
}

/**
 * This function norms a value to the interval [0, 2*pi]. If a value is outside of this interval, the corresponding
 * angle in this interval is found.
 *
 * @param i_rad Radian angle
 * @return Returns the radian angle between 0 and 2*pi
 */
template<typename T>
inline T NormRadian2PI(T i_rad)
{
    while (i_rad > 2*M_PI)
    {
        i_rad -= T(2*M_PI);
    }
    while (i_rad < 0)
    {
        i_rad += T(2*M_PI);
    }
    return i_rad;
}

/**
 * This function norms a value to the interval [-pi, pi]. If a value is outside of this interval, the corresponding
 * angle in this interval is found.
 *
 * @param i_rad Radian angle
 * @return Returns the radian angle between -pi and pi
 */
template<typename T>
inline T NormRadianPIPI(T i_rad)
{
    while (i_rad > M_PI)
    {
        i_rad -= T(2*M_PI);
    }
    while (i_rad < -M_PI)
    {
        i_rad += T(2*M_PI);
    }
    return i_rad;
}

/**
 * This function rotates a point around z-axis with a given angle.
 *
 * @param p1 Point
 * @param yaw Angle for rotating
 * @return Returns the rotated point
 */
template<typename T, typename U>
T RotateZ(const T &p1, const U &yaw)
{
    T p2; // this is because the constructor may need more than just x and y (e.g. sPoint3D)
    p2.x = p1.x * cos(yaw) - p1.y * sin(yaw);
    p2.y = p1.x * sin(yaw) + p1.y * cos(yaw);
    return p2;
}

/**
 * This function return the squared distance of a 2D point from the origin.
 *
 * @param p1 Point
 * @return Returns the squared distance
 */
template<typename T>
tFloat64 GetSquaredDistance2D(const T &p1)
{
    return SQ(p1.x)+SQ(p1.y);
}

/**
 * This function returns the distance of a 2D point
 *
 * @param p1 Point
 * @return Returns the distance
 */
template<typename T>
tFloat64 GetDistance2D(const T &p1)
{
    return sqrt(GetSquaredDistance2D(p1));
}

/**
 * This structure is representing a three dimensional point. It contains three variables of the template type T.
 */
#pragma pack(push, 1)
template<typename T=tFloat64>
struct sPoint3D: public sPoint2D<T>
{
    /**
     * The standard constructor is initializing the three variables of the structure with the value 0.
     */
    sPoint3D(): sPoint2D<T>(), z(0) {}

    /**
     * This constructor is initializing the member variable with two values that are given by the parameters.
     *
     * @param i_x Initializing x member variable
     * @param i_y Initializing y member variable
     * @param i_z Initializing z member variable
     */
    sPoint3D(const T &i_x, const T &i_y, const T &i_z): sPoint2D<T>(i_x, i_y), z(i_z) {}

    /**
     * The copy constructor copies the values from the object given by the parameters. Therefore, the copy constructor
     * is calling the copy constructor of the underlying type.
     *
     * @param other The copy object
     */
    template<typename A>
    sPoint3D(sPoint3D<A> other): sPoint2D<T>(other), z(T(other.z)) {}

    T    z;                    ///< Position on Z axis
};
#pragma pack(pop)

/**
 * This function calculates the difference between two 3D points. It subtracts the x, y and z-components separately.
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns a point with the difference of point 1 and 2
 */
template<typename T, typename A>
sPoint3D<T> operator-(const sPoint3D<T>& p1, const sPoint3D<A>& p2)
{
    return sPoint3D<T>(p1.x-T(p2.x), p1.y-T(p2.y), p1.z-T(p2.z));
}

/**
 * This function calculates the sum of two 3D points.
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns a point with the sum of point 1 and 2
 */
template<typename T, typename A>
sPoint3D<T> operator+(const sPoint3D<T>& p1, const sPoint3D<A>& p2)
{
    return sPoint3D<T>(p1.x+T(p2.x), p1.y+T(p2.y), p1.z+T(p2.z));
}

/**
 * This function calculates the scalar multiplication of a 3D point.
 *
 * @param p1 Point 1
 * @param m Multiplier
 * @return Returns the point multiplied with the scalar value.
 */
template<typename T>
sPoint3D<T> operator*(const sPoint3D<T>& p1, const T& m)
{
    return sPoint3D<T>(p1.x*m, p1.y*m, p1.z*m);
}

/**
 * This function calculates the multiplication of two 3D points according to this:
 * x = x1*x2, y = y1*y2, z = z1*z2
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns the product of the two points according to the described multiplication
 */
template<typename T, typename A>
sPoint3D<T> operator*(const sPoint3D<T>& p1, const sPoint3D<A>& p2)
{
    return sPoint3D<T>(p1.x*T(p2.x), p1.y*T(p2.y), p1.z*T(p2.z));
}

/**
 * This function calculates the division of two 3D points according to this:
 * x = x1/x2, y = y1/y2, z = z1/z2
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns the division of the two points according to the described schema
 */
template<typename T, typename A>
sPoint3D<T> operator/(const sPoint3D<T>& p1, const sPoint3D<A>& p2)
{
    return sPoint3D<T>(p1.x/T(p2.x), p1.y/T(p2.y), p1.z/T(p2.z));
}

/**
 * This function creates an stream output for a 3D Point. This can be used to display the points' values.
 *
 * @param i_stream The input stream where to append the new output data
 * @param i_data The 2D point with the data
 * @return Return the new stream object that results from here
 */
template<typename T>
std::ostream &operator<<(std::ostream &i_stream, sPoint3D<T> const &i_data)
{
    return i_stream << *(dynamic_cast<const sPoint2D<T>*>(&i_data)) << ", z=" << i_data.z;
}

/**
 * This operator function checks if two points are equal.
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns true if the points are equal, false otherwise
 */
template<typename T, typename A>
tBool operator<(const sPoint3D<T>& p1, const sPoint3D<A>& p2)
{
    if (p1.x < p2.x)
    {
        return tTrue;
    }
    else if (p1.x == p2.x)
    {
        if (p1.y < p2.y)
        {
            return tTrue;
        }
        else if (p1.y == p2.y)
        {
            if (p1.z < p2.z)
            {
                return tTrue;
            }
            else
            {
                return tFalse;
            }
        }
        else
        {
            return tFalse;
        }
    }
    else
    {
        return tFalse;
    }
}

/**
 * This operator function checks if two 3D points are equal.
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns true if the points are equal, false otherwise
 */
template<typename T, typename A>
tBool operator==(const sPoint3D<T>& p1, const sPoint3D<A>& p2)
{
    if ((p1.x == p2.x) &&
        (p1.y == p2.y) &&
        (p1.z == p2.z))
    {
        return tTrue;
    }
    else
    {
        return tFalse;
    }
}

/**
 * This structure is representing an oriented two dimensional point. It contains a 2D point and an angle.
 */
#pragma pack(push, 1)
template<typename T=tFloat64>
struct sOrientedPoint2D: public sPoint2D<T>
{
    /**
     * The standard constructor is initializing the point and the angle of the structure with the value 0.
     */
    sOrientedPoint2D(): sPoint2D<T>(), yaw(0) {}

    /**
     * This constructor is initializing the member variable with the values that are given by the parameters.
     *
     * @param i_x Initializing x member variable
     * @param i_y Initializing y member variable
     * @param i_yaw Initializing z member variable
     */
    sOrientedPoint2D(const T &i_x, const T &i_y, const T &i_yaw): sPoint2D<T>(i_x, i_y), yaw(i_yaw) {}

    /**
     * The copy constructor copies the values from the object given by the parameters. Therefore, the copy constructor
     * is calling the copy constructor of the underlying type.
     *
     * @param other The other object from that is copied
     */
    template<typename A>
    sOrientedPoint2D(sOrientedPoint2D<A> other): sPoint2D<T>(other), yaw(T(other.yaw)) {}

    T    yaw;                    ///< yaw angle
};
#pragma pack(pop)

/**
 * This structure is representing a two dimensional point with a factor. It contains a point and a factor.
 */
#pragma pack(push, 1)
template<typename T=tInt32>
struct sPoint2DWithFactor: public sPoint2D<T>
{
    /**
     * The standard constructor is initializing the variables of the structure with the value 0.
     */
    sPoint2DWithFactor(): sPoint2D<T>(), factor(0.0) {}

    /**
     * This constructor is initializing the member variables with the values that are given by the parameters.
     *
     * @param i_x Initializing x member variable
     * @param i_y Initializing y member variable
     * @param i_factor Initializing the factor member variable
     */
    sPoint2DWithFactor(const T &i_x, const T &i_y, const tFloat64 &i_factor):
        sPoint2D<T>(i_x, i_y), factor(i_factor) {}

    /**
     * The copy constructor copies the values from the object given by the parameters. Therefore, the copy constructor
     * is calling the copy constructor of the underlying type.
     *
     * @param other The other object from that is copied
     */
    template<typename A>
    sPoint2DWithFactor(sPoint2DWithFactor<A> other): sPoint2D<T>(other), factor(other.factor) {}

    tFloat64    factor;                    ///< factor value
};
#pragma pack(pop)

/**
 * This structure is representing a six dimensional point. It contains six variables of the template type T.
 */
#pragma pack(push, 1)
template<typename T=tFloat64>
struct sPoint6D : public sPoint3D<T>
{
    /**
     * The standard constructor is initializing the six variables of the structure with the value 0.
     */
    sPoint6D(): sPoint3D<T>(), yaw(0), roll(0), pitch(0) {}

    /**
     * This constructor is initializing the member variable with the values that are given by the parameters.
     *
    * @param i_x Initializing x member variable
    * @param i_y Initializing y member variable
    * @param i_z Initializing z member variable
    * @param i_yaw Initializing yaw member variable
    * @param i_roll Initializing roll member variable
    * @param i_pitch Initializing pitch member variable
    */
    sPoint6D(const T &i_x, const T &i_y, const T &i_z, const T &i_yaw, const T &i_roll, const T &i_pitch):
        sPoint3D<T>(i_x, i_y, i_z), yaw(i_yaw), roll(i_roll), pitch(i_pitch) {}

    T    yaw;                  ///< Yaw value
    T    roll;                 ///< Roll value
    T    pitch;                ///< Pitch value
};
#pragma pack(pop)

/**
 * This operator function checks if two 6D points are equal.
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns true if the points are equal, false otherwise
 */
template<typename T, typename A>
tBool operator==(const sPoint6D<T>& p1, const sPoint6D<A>& p2)
{
    if ((p1.x == p2.x)
        && (p1.y == p2.y)
        && (p1.z == p2.z)
        && (p1.pitch == p2.pitch)
        && (p1.roll == p2.roll)
        && (p1.yaw == p2.yaw))
    {
        return tTrue;
    }
    else
    {
        return tFalse;
    }
}

/**
 * This operator function checks if two 6D points are not equal.
 *
 * @param p1 Point 1
 * @param p2 Point 2
 * @return Returns false if the points are equal, true otherwise
 */
template<typename T, typename A>
tBool operator!=(const sPoint6D<T>& p1, const sPoint6D<A>& p2)
{
    return (p1 == p2) ? tFalse : tTrue;
}

/**
 * This structure contains information about occupancy.
 */
#pragma pack(push, 1)
struct sDSOccupancyValue
{
    /**
     * The standard constructor is initializing the two variables of the structure with the value 0.
     */
    sDSOccupancyValue(): occupancy(0.01f), notOccupancy(0.01f) {}

    /**
     * This constructor is initializing the member variable with the values that are given by the parameters.
     *
    * @param i_occupancy Initializing occupancy member variable
    * @param i_notOccupancy Initializing notOccupancy member variable
    */
    sDSOccupancyValue(const tFloat32 &i_occupancy,
                      const tFloat32 &i_notOccupancy)
                      :
                      occupancy(i_occupancy),
                      notOccupancy(i_notOccupancy)
    {}

    tFloat32 occupancy;       ///< Grade of occupancy
    tFloat32 notOccupancy;    ///< Grade of non-occupancy
};
#pragma pack(pop)

/**
 * This structure contains information about occupancy using Bayes theory.
 */
#pragma pack(push, 1)
struct sBinaryBayesValue
{
   /**
    * Default constructor
    */
    sBinaryBayesValue() : probability(0.5f) {}

   /**
    * Constructor with parameter
    * @param i_probability The value used to initialize probability member variable
    */
    sBinaryBayesValue(const tFloat32 &i_probability)
                      :
                      probability(i_probability)
    {}

    tFloat32 probability;    ///< value of probability
};
#pragma pack(pop)

/**
 * This structure contains information about velocity.
 */
#pragma pack(push, 1)
struct sVelocity
{
    /**
     * The standard constructor is initializing the variables of the structure with the value 0.
     */
    sVelocity(): confidence(0.0f) {}

    tFloat32    confidence;    ///< Confidence of current cell velocity information. The range is [0, 1]
    sPoint2D<>  velocity;      ///< Velocity information
};
 #pragma pack(pop)
//typedef sPoint2D<> sVelocity;

/**
 * This function returns the signum of a value.
 *
 * @param val Value to be evaluated
 * @result Returns -1 if negative value, 1 if positive value, 0 if 0
 */
template <typename T> int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

/**
 * This function returns the round value of a number.
 *
 * @param val Value to be rounded
 * @result Returns the rounded value
 */
template <typename T> int round(T val)
{
    return ((int)(val + 0.5 * sgn(val)));
}

/**
 * This structure  allocates a variable size block memory for a given type. The capacity of the structure depends
 * on the given parameter.
 */
#pragma pack(push, 1)
template<typename T>
struct sDynamicArray
{
    /**
     * The standard constructor is initializing the two variables of the structure with the value 0.
     */
    sDynamicArray(): data(NULL), capacity(0) {}

   /**
    * The constructor is allocating dynamic memory to the data member variable
    * depending on the value of the capacity member value
    *
    * @param i_capacity The length of block memory to be allocated
    */
    sDynamicArray(const tUInt32 i_capacity): capacity(i_capacity)
    {
        data = (capacity > 0) ? new T[capacity] : NULL;
    }

    /**
     * The copy constructor copies the values from the object given by the parameters. Therefore, new memory is
     * allocated in this step.
     *
     * @param other Object to copy
     */
    sDynamicArray(const sDynamicArray<T> &other): data(NULL), capacity(other.capacity)
    {
        if (other.data)
        {
            data = new T[capacity];
            memcpy(data, other.data, capacity * sizeof(T));
        }
    }

    /**
     * This function copies data from the referenced object. New memory is allocated.
     *
     * @param other Object to copy from
     * @return Returns this object
     */
    sDynamicArray& operator=(const sDynamicArray<T> &other)
    {
        if (this != &other)
        {
            capacity = other.capacity;
            delete [] data;
            data = NULL;
            capacity = other.capacity;
            if (other.data)
            {
                data = new T[capacity];
                memcpy(data, other.data, capacity * sizeof(T));
            }
        }
        return *this;
    }

   /**
    * The destructor deallocates the memory of data member variable.
    */
    ~sDynamicArray() { delete [] data; }

   /**
    * This function returns the capacity member. The method is used to get the capacity of the dynamic
    * array to make checks to avoid accessing memory outside of allocated block.
    *
    * @return Returns the capacity member
    */
    tUInt32 GetCapacity() const
    { 
        return capacity; 
    }

    /**
     * @brief Comparison operator for two sDynamicArray<T> objects.
     *
     * @param rhs The right hand side sDynamicArray<T> object of the comparison.
     * @return True if this sDynamicArray<T> object is equal to the given one and false otherwise.
     */
    tBool operator == (const sDynamicArray<T>& rhs) const
    {
        return (capacity == rhs.capacity) 
            && (0 == memcmp(data, rhs.data, capacity));
    }

    T          *data;       ///< Usable data

private:
   /**
    * The length of block memory to be allocated. It is not allowed to modify this member after its initialization, so
    * it is a private member.
    */
    tUInt32    capacity;
};
#pragma pack(pop)

/**
 * This structure contains GPS (latitude and longitude) coordinates
 */
#pragma pack(push, 1)
template<typename T=tFloat64>
struct sGPSCoordinate
{
    /**
     * The standard constructor is initializing the variables of the structure with the value 0.
     */
    sGPSCoordinate(): latitude(0.0), longitude(0.0) {}

    /**
     * This constructor is initializing the member variable with the values that are given by the parameters.
     *
     * @param i_latitude latitude coordinate
     * @param i_longitude longitude coordinate
     */
    sGPSCoordinate(const T i_latitude, const T i_longitude):
        latitude(i_latitude), longitude(i_longitude)
    {}

    /**
     * The copy constructor copies the values from the object given by the parameters. Therefore, the copy constructor
     * is calling the copy constructor of the underlying type.
     *
     * @param other The other object from that is copied
     */
    template<typename A>
    sGPSCoordinate(sGPSCoordinate<A> other): latitude(T(other.latitude)),
        longitude(T(other.longitude)) {}

    /**
     * @brief Comparison operator for two sGPSCoordinate<T> objects.
     *
     * @param rhs The right hand side sGPSCoordinate<T> object of the comparison.
     * @return True if this sGPSCoordinate<T> object is equal to the given one and false
     * otherwise.
     */
    tBool operator == (const sGPSCoordinate<T>& rhs) const
    {
        return (latitude == rhs.latitude) && (longitude == rhs.longitude);
    }

    /**
     * @brief Not-equal-to operator for two sGPSCoordinate<T> objects.
     *
     * @param rhs The right hand side sGPSCoordinate<T> object of the comparison.
     * @return True if this sGPSCoordinate<T> object is not equal to the given one and false
     * otherwise.
     */
    tBool operator != (const sGPSCoordinate<T>& rhs) const
    {
        return !(*this == rhs);
    }

    T   latitude;  ///< latitude position in [deg.]
    T   longitude; ///< longitude position in [deg.]
};
#pragma pack(pop)

/**
 * This structure stores a list of sPoint2D elements. Its size is dynamic.
 */
#pragma pack(push, 1)
struct sPointList2D
{
    /**
     * The standard constructor is initializing the two variables of the structure with the value 0.
     */
    sPointList2D(): numberOfElements(0), elements(NULL)
    {
    };

    /**
     * The constructor sets a number of elements and allocates memory for them.
     *
     * @param i_numberOfElements The number of elements
     */
    sPointList2D(const tUInt32 &i_numberOfElements): numberOfElements(i_numberOfElements)
    {
        elements = new sPoint2D<tFloat64>[numberOfElements];
    }

    /**
     * The copy constructor copies the values from the object given by the parameters.
     *
     * @param other Object to copy
     */
    sPointList2D(const sPointList2D &other)
    {
        numberOfElements = other.numberOfElements;
        elements = new sPoint2D<tFloat64>[numberOfElements];

        for (tUInt32 i(0); i < numberOfElements; ++i)
        {
            elements[i] = other.elements[i];
        }
    }

    /**
     * This function copies data from the referenced object. New memory is allocated.
     *
     * @param other Object to copy
     * @return Return this object
     */
    sPointList2D &operator=(const sPointList2D & other)
    {
        numberOfElements = other.numberOfElements;

        if (&other != this)
        {
            delete [] elements;
            elements = new sPoint2D<tFloat64>[numberOfElements];

            for (tUInt32 i(0); i < numberOfElements; ++i)
            {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    /**
     * The destructor deallocates all memory.
     */
    ~sPointList2D()
    {
        delete [] elements;
        elements = NULL;
    }

    tUInt32 numberOfElements;       ///< Number of elements
    sPoint2D<tFloat64> *elements;   ///< Pointer to the data
};
#pragma pack(pop)

/**
 * This structure stores a list of sOrientedPoint2D elements. Its size is dynamic.
 */
#pragma pack(push, 1)
struct sOrientedPointList2D
{
    /**
     * The standard constructor is initializing the two variables of the structure with the value 0.
     */
    sOrientedPointList2D(): numberOfElements(0), elements(NULL)
    {
    }

    /**
     * The constructor sets a number of elements and allocates memory for them.
     *
     * @param i_orientedPointList The vector of sOrientedPoint2D
     */
    sOrientedPointList2D(const std::vector<sOrientedPoint2D<tFloat64> > &i_orientedPointList)
        : numberOfElements(static_cast<tUInt32>(i_orientedPointList.size())),
          elements(NULL)
    {
        elements = new sOrientedPoint2D<tFloat64> [numberOfElements];

        for (tUInt32 i(0); i < numberOfElements; ++i)
        {
            elements[i] = i_orientedPointList[i];
        }
    }

    /**
     * The copy constructor copies the values from the object given by the parameters.
     *
     * @param other Object to copy
     */
    sOrientedPointList2D(const sOrientedPointList2D &other)
    {
        numberOfElements = other.numberOfElements;
        elements = new sOrientedPoint2D<tFloat64>[numberOfElements];

        for (tUInt32 i(0); i < numberOfElements; ++i)
        {
            elements[i] = other.elements[i];
        }
    }

    /**
     * This function copies data from the referenced object. New memory is allocated.
     *
     * @param other Object to copy
     * @return Self
     */
    sOrientedPointList2D &operator=(const sOrientedPointList2D & other)
    {
        numberOfElements = other.numberOfElements;

        if (&other != this)
        {
            delete [] elements;
            elements = new sOrientedPoint2D<tFloat64>[numberOfElements];

            for (tUInt32 i(0); i < numberOfElements; ++i)
            {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    /**
     * The destructor deallocates all memory.
     */
    ~sOrientedPointList2D()
    {
        delete [] elements;
        elements = NULL;
    }

    tUInt32 numberOfElements;               ///< Number of elements
    sOrientedPoint2D<tFloat64> *elements;   ///< Pointer to the data
};
#pragma pack(pop)


/**
 * This function copies an unsigned integer 32 variable into a defined position in a buffer.
 * The buffer position counter is incremented in this function.
 *
 * @param i_val The value to be copied
 * @param io_buffer The buffer to be modified
 * @param io_bufferCount The position for the data to be inserted (incremented by UInt32 size)
 * @return Standard ADTF return code
 */
inline void CopyUInt32ValToBuffer(const tUInt32 &i_val, tUInt8 *&io_buffer, tUInt32 &io_bufferCount)
{
    const tUInt32 newSize(sizeof(i_val));
    memcpy(
        &(io_buffer[io_bufferCount]),
        &i_val,
        newSize);
    io_bufferCount += newSize;
}

/**
 * This function returns an unsigned integer 32 variable.
 * The value is defined by a given buffer and a given position inside this buffer.
 * The buffer position counter is incremented in this function.
 *
 * @param i_buffer The buffer in which the value is located
 * @param io_bufferCount The position at which the value is located (incremented by UInt32 size)
 * @return The value
 */
inline tUInt32 GetUInt32FromBuffer(const tUInt8 *i_buffer, tUInt32 &io_bufferCount)
{
    tUInt32 val;
    const tUInt32 newSize(sizeof(val));
    memcpy(
        &val,
        &(i_buffer[io_bufferCount]),
        newSize);
    io_bufferCount += newSize;
    return val;
}

/**
 * This function copies an unsigned integer 16 variable into a defined position in a buffer.
 * The buffer position counter is incremented in this function.
 *
 * @param i_val The value to be copied
 * @param io_buffer The buffer to be modified
 * @param io_bufferCount The position for the data to be inserted (incremented by UInt16 size)
 * @return Standard ADTF return code
 */
inline void CopyUInt16ValToBuffer(const tUInt16 &i_val, tUInt8 *&io_buffer, tUInt32 &io_bufferCount)
{
    const tUInt32 newSize(sizeof(i_val));
    memcpy(
        &(io_buffer[io_bufferCount]),
        &i_val,
        newSize);
    io_bufferCount += newSize;
}

/**
 * This function returns an unsigned integer 16 variable.
 * The value is defined by a given buffer and a given position inside this buffer.
 * The buffer position counter is incremented in this function.
 *
 * @param i_buffer The buffer in which the value is located
 * @param io_bufferCount The position at which the value is located (incremented by UInt16 size)
 * @return The value
 */
inline tUInt16 GetUInt16FromBuffer(const tUInt8 *i_buffer, tUInt32 &io_bufferCount)
{
    tUInt16 val;
    const tUInt32 newSize(sizeof(val));
    memcpy(
        &val,
        &(i_buffer[io_bufferCount]),
        newSize);
    io_bufferCount += newSize;
    return val;
}

/**
 * This function copies a float 64 variable into a defined position in a buffer.
 * The buffer position counter is incremented in this function.
 *
 * @param i_val The value to be copied
 * @param io_buffer The buffer to be modified
 * @param io_bufferCount The position for the data to be inserted (incremented by Float64 size)
 * @return Standard ADTF return code
 */
inline void CopyFloat64ValToBuffer(const tFloat64 &i_val, tUInt8 *&io_buffer, tUInt32 &io_bufferCount)
{
    const tUInt32 newSize(sizeof(i_val));
    memcpy(
        &(io_buffer[io_bufferCount]),
        &i_val,
        newSize);
    io_bufferCount += newSize;
}

/**
 * This function returns a float 64 variable.
 * The value is defined by a given buffer and a given position inside this buffer.
 * The buffer position counter is incremented in this function.
 *
 * @param i_buffer The buffer in which the value is located
 * @param io_bufferCount The position at which the value is located (incremented by Float64 size)
 * @return The value
 */
inline tFloat64 GetFloat64FromBuffer(const tUInt8 *i_buffer, tUInt32 &io_bufferCount)
{
    tFloat64 val;
    const tUInt32 newSize(sizeof(val));
    memcpy(
        &val,
        &(i_buffer[io_bufferCount]),
        newSize);
    io_bufferCount += newSize;
    return val;
}

/**
 * This function copies a boolean variable into a defined position in a buffer.
 * The buffer position counter is incremented in this function.
 *
 * @param i_val The value to be copied
 * @param io_buffer The buffer to be modified
 * @param io_bufferCount The position for the data to be inserted (incremented by Bool size)
 * @return Standard ADTF return code
 */
inline void CopyBoolValToBuffer(const tBool &i_val, tUInt8 *&io_buffer, tUInt32 &io_bufferCount)
{
    const tUInt32 newSize(sizeof(i_val));
    memcpy(
        &(io_buffer[io_bufferCount]),
        &i_val,
        newSize);
    io_bufferCount += newSize;
}

/**
 * This function returns a boolean variable.
 * The value is defined by a given buffer and a given position inside this buffer.
 * The buffer position counter is incremented in this function.
 *
 * @param i_buffer The buffer in which the value is located
 * @param io_bufferCount The position at which the value is located (incremented by Bool size)
 * @return The value
 */
inline tBool GetBoolFromBuffer(const tUInt8 *i_buffer, tUInt32 &io_bufferCount)
{
    tBool val;
    const tUInt32 newSize(sizeof(val));
    memcpy(
        &val,
        &(i_buffer[io_bufferCount]),
        newSize);
    io_bufferCount += newSize;
    return val;
}


/**
 * This enum describes the movement state of the car.
 */
enum eMovementState
{
    MOVEMENT_STATE_MOVING_FORWARD,
    MOVEMENT_STATE_MOVING_BACKWARD,
    MOVEMENT_STATE_STOPPED,
    MOVEMENT_STATE_UNKNOWN
};

/**
 * This function calculates the movement direction of a position
 * based on the orientation of the vehicle and a given speed vector.
 *
 * @param i_speedVector The speed vector of the vehicle
 * @param i_positionYawValue The given orientation of the vehicle
 * @return Returns the movement direction (FORWARD, BACKWARD)
 */
inline eMovementState CalculateMovementDirection(const sPoint2D<tFloat64> &i_speedVector,
                                                 const tFloat64 &i_positionYawValue)
{
    // calculate the orientation of the speed vector
    const tFloat64 speedOrientation(NormRadian2PI(atan2(i_speedVector.y, i_speedVector.x)));

    // compare the orientations
    const tFloat64 angleDiff(AngleDiff(NormRadian2PI(i_positionYawValue), speedOrientation));

    if (angleDiff <= M_PI_2)
    {
        return MOVEMENT_STATE_MOVING_FORWARD;
    }
    else
    {
        return MOVEMENT_STATE_MOVING_BACKWARD;
    }
}

/**
 * This enum contains the gear state of the car.
 */
enum eGearDirection
{
    GEAR_DIRECTION_FORWARD,
    GEAR_DIRECTION_BACKWARD,
    GEAR_DIRECTION_UNKNOWN
};


/**
 * Structure that holds boundary information about an osm map
 */
struct sOsmBounds
{
    /**
        * Default constructor
        */
    sOsmBounds() : minLat(0.f), minLon(0.f), maxLat(0.f), maxLon(0.f) {}
    /**
        * Initialization constructor
        * @param i_minLat minimum lattitude
        * @param i_minLon minimum longitude
        * @param i_maxLat maximum lattitude
        * @param i_maxLon maximum longitude
        */
    sOsmBounds(const tFloat64 &i_minLat, const tFloat64 &i_minLon, const tFloat64 &i_maxLat, const tFloat64 &i_maxLon)
        : minLat(i_minLat), minLon(i_minLon), maxLat(i_maxLat), maxLon(i_maxLon) {}
    tFloat64 minLat;      ///< minimal map latitude
    tFloat64 minLon;      ///< minimal map longitude
    tFloat64 maxLat;      ///< maximal map latitude
    tFloat64 maxLon;      ///< maximal map longitude
};
/**
 * Structure that holds member information of osm relations
 */
struct sOsmMember
{
    /**
        * Initialization constructor
        * @param i_type member type
        * @param i_ref reference id
        * @param i_role role
        */
    sOsmMember(const std::string &i_type, const std::string &i_ref, const std::string &i_role)
        : elementType(i_type), refId(i_ref), role(i_role) {}
    std::string elementType;     ///< member type (e.g. node, way)
    std::string refId;      ///< reference id
    std::string role;     ///< role
};
/**
 * Base struct for some osm elements
 */
struct sOsmElements {
    /**
        * Default constructor
        */
    sOsmElements() : id(""), action(""), user(""), uid(0L), visible(false),
        timestamp(""), changeSet(0L), m_tags() {}
    /**
        * Initialization constructor
        * @param i_id element id
        * @param i_action latest element action
        * @param i_user latest user who modified the element
        * @param i_uid id of user who modified the element at last
        * @param i_visible elements map visibility
        * @param i_timestamp time of last modification
        * @param i_changeSet change set in which the object was updated
        */
    sOsmElements(const std::string &i_id, const std::string &i_action, const std::string &i_user, const long &i_uid,
        const bool &i_visible, const std::string &i_timestamp, const long &i_changeSet)
        : id(i_id), action(i_action), user(i_user), uid(i_uid), visible(i_visible),
        timestamp(i_timestamp), changeSet(i_changeSet), m_tags() {}
    std::string id;                           ///< unique identifier
    std::string action;                       ///< last action on the element? (no official description)
    std::string user;                         ///< user who last modified the object
    long uid;                                 ///< id of user who last modified the object
    bool visible;                             ///< map visibility
    std::string timestamp;                    ///< time of last modification (W3C format)
    long changeSet;                           ///< change set in which the object was updated
    std::map<std::string, std::string> m_tags;  ///< key value store for information
};

/**
 * Structure that keeps information about a way/path of an osm map
 */
struct sOsmWay : sOsmElements
{
    /**
    * Default constructor
    */
    sOsmWay() : sOsmElements(), version(0), node_ids() {}

    /**
    * Initialization Constructor
    * @param i_id element id
    * @param i_action latest element action
    * @param i_user latest user who modified the element
    * @param i_uid id of user who modified the element at last
    * @param i_visible elements map visibility
    * @param i_timestamp time of last modification
    * @param i_changeSet change set in which the object was updated
    * @param i_version version number
    */
    sOsmWay(const std::string &i_id, const std::string &i_action, const std::string &i_user, const long &i_uid,
        const bool &i_visible, const std::string &i_timestamp, const long &i_changeSet, const int &i_version)
        : sOsmElements(i_id, i_action, i_user, i_uid, i_visible, i_timestamp, i_changeSet),
            version(i_version)  {}

    int version;                      ///< version information
    std::vector<std::string> node_ids;     ///< contains all node ids of a the way
};
/**
 * Structure that keeps information about a node of an osm map
 */
struct sOsmNode : sOsmElements
{
    /**
    * Default constructor
    */
    sOsmNode() : sOsmElements(), lat(0.0), lon(0.0) {}
    /**
    * Initialization constructor
    * @param i_id element id
    * @param i_action latest element action
    * @param i_user latest user who modified the element
    * @param i_uid id of user who modified the element at last
    * @param i_visible elements map visibility
    * @param i_timestamp time of last modification
    * @param i_changeSet change set in which the object was updated
    * @param i_lat node lattitude
    * @param i_lon node longitude
    */
    sOsmNode(const std::string &i_id, const tFloat64 &i_lat, const tFloat64 &i_lon,
        const std::string &i_action, const std::string &i_user, const long &i_uid,
        const bool &i_visible, const std::string &i_timestamp, const long &i_changeSet) :
    sOsmElements(i_id, i_action, i_user, i_uid, i_visible, i_timestamp, i_changeSet),
        lat(i_lat), lon(i_lon) {};
    tFloat64 lat;     ///< node lattitude
    tFloat64 lon;     ///< node longitude
};

/**
 * Structure that keeps osm relation information
 */
struct sOsmRelation :sOsmElements
{
    /**
        * Default constructor
        */
    sOsmRelation() : sOsmElements(), version(0) {}
    /**
        * Initialization constructor
        * @param i_id element id
        * @param i_action latest element action
        * @param i_user latest user who modified the element
        * @param i_uid id of user who modified the element at last
        * @param i_visible elements map visibility
        * @param i_timestamp time of last modification
        * @param i_changeSet change set in which the object was updated
        * @param i_version version number
        */
    sOsmRelation(const std::string i_id, const std::string i_action, const std::string i_user, const long i_uid,
        const bool i_visible, const std::string i_timestamp, const long i_changeSet, const int i_version)
        : sOsmElements(i_id, i_action, i_user, i_uid, i_visible, i_timestamp, i_changeSet), version(i_version) {};
    int version;                  ///< version information
    std::vector<sOsmMember> members; ///< member (element information) which are associated to this relation
};

/**
 * Structure that keeps essential way information from osm ways
 */
struct sOsmPolyLine {
    std::map<std::string, std::string> tags;  ///< additional k, v information about polygon
    std::vector<sPoint2D<> > points;  ///< points of polygon
};

/**
 * Structure that keeps a vector of sPolyLines
 */
struct sOsmPolyLineVector {
    std::vector<sOsmPolyLine> polyLineVec;       ///< vector of polygons
};

#endif // EB_ROBINOS_COMMON_PARAMETERS_H
