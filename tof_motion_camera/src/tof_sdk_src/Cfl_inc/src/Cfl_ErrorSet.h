///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4153 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class ErrorSet 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Tue Aug 15 16:01:18 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Cfl_ErrorSet_
#define _Cfl_ErrorSet_

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>
#ifdef _TARGET_ARCH_W32_
//ROH: try without #define _WIN32_WINNT _WIN32_WINNT_WIN8
#define WIN32_LEAN_AND_MEAN
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#endif

#include <string>

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace Cfl
namespace Cfl
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class ErrorSet
class ErrorSet
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        ErrorSet( );

   /// Destructor
        ~ErrorSet( );

   /// Write content into buffer
        bool WriteToBuffer( uint1 * buffer
                          , uint2 aBufferSize
                          , uint2 & aByteOffset ) const;
   /// Read content from buffer
        bool ReadFromBuffer( const uint1 * buffer
                           , uint2 aBufferSize
                           , uint2 & aByteOffset );

   /// Write human readable representation of content
        void Log( std::ostream & aStreamRef ) const;
   
   /// Write human readable representation with indentation
        void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

   //  Arithmetic operators
   /// Equal operator 
       bool operator == (const ErrorSet & aRef) const;
   
   /// Less operator 
       bool operator < (const ErrorSet & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         // The member ApplicationProcessorTooHot
         ///  The Get function for member ApplicationProcessorTooHot
              bool   GetApplicationProcessorTooHot( ) const;
         ///  The Set function for member ApplicationProcessorTooHot
              void    SetApplicationProcessorTooHot( const bool & aValue );
         //----------------------------------------------------
         // The member CalibrationDataMissing
         ///  The Get function for member CalibrationDataMissing
              bool   GetCalibrationDataMissing( ) const;
         ///  The Set function for member CalibrationDataMissing
              void    SetCalibrationDataMissing( const bool & aValue );
         //----------------------------------------------------
         // The member CaptureError
         ///  The Get function for member CaptureError
              bool   GetCaptureError( ) const;
         ///  The Set function for member CaptureError
              void    SetCaptureError( const bool & aValue );
         //----------------------------------------------------
         // The member CaptureTimeout
         ///  The Get function for member CaptureTimeout
              bool   GetCaptureTimeout( ) const;
         ///  The Set function for member CaptureTimeout
              void    SetCaptureTimeout( const bool & aValue );
         //----------------------------------------------------
         // The member IlluminationError
         ///  The Get function for member IlluminationError
              bool   GetIlluminationError( ) const;
         ///  The Set function for member IlluminationError
              void    SetIlluminationError( const bool & aValue );
         //----------------------------------------------------
         // The member IlluminationOverTemperature
         ///  The Get function for member IlluminationOverTemperature
              bool   GetIlluminationOverTemperature( ) const;
         ///  The Set function for member IlluminationOverTemperature
              void    SetIlluminationOverTemperature( const bool & aValue );
         //----------------------------------------------------
         // The member IlluminationTemperatureSensorError
         ///  The Get function for member IlluminationTemperatureSensorError
              bool   GetIlluminationTemperatureSensorError( ) const;
         ///  The Set function for member IlluminationTemperatureSensorError
              void    SetIlluminationTemperatureSensorError( const bool & aValue );
         //----------------------------------------------------
         // The member SerdesError
         ///  The Get function for member SerdesError
              bool   GetSerdesError( ) const;
         ///  The Set function for member SerdesError
              void    SetSerdesError( const bool & aValue );
         //----------------------------------------------------
         // The member TofCCPLLConfigurationError
         ///  The Get function for member TofCCPLLConfigurationError
              bool   GetTofCCPLLConfigurationError( ) const;
         ///  The Set function for member TofCCPLLConfigurationError
              void    SetTofCCPLLConfigurationError( const bool & aValue );
         //----------------------------------------------------
         // The member TofCCTemperatureError
         ///  The Get function for member TofCCTemperatureError
              bool   GetTofCCTemperatureError( ) const;
         ///  The Set function for member TofCCTemperatureError
              void    SetTofCCTemperatureError( const bool & aValue );
         //----------------------------------------------------
         // The member TofSensorTemperatureSensorError
         ///  The Get function for member TofSensorTemperatureSensorError
              bool   GetTofSensorTemperatureSensorError( ) const;
         ///  The Set function for member TofSensorTemperatureSensorError
              void    SetTofSensorTemperatureSensorError( const bool & aValue );
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         bool itsApplicationProcessorTooHot;
         bool itsCalibrationDataMissing;
         bool itsCaptureError;
         bool itsCaptureTimeout;
         bool itsIlluminationError;
         bool itsIlluminationOverTemperature;
         bool itsIlluminationTemperatureSensorError;
         bool itsSerdesError;
         bool itsTofCCPLLConfigurationError;
         bool itsTofCCTemperatureError;
         bool itsTofSensorTemperatureSensorError;


}; // End of class ErrorSet

//------------------------------ Inline Functions ----------------------
inline bool ErrorSet::operator == (const ErrorSet & aRef) const
{
   if ( ! (itsApplicationProcessorTooHot == aRef.itsApplicationProcessorTooHot) ) return false;
   if ( ! (itsCalibrationDataMissing == aRef.itsCalibrationDataMissing) ) return false;
   if ( ! (itsCaptureError == aRef.itsCaptureError) ) return false;
   if ( ! (itsCaptureTimeout == aRef.itsCaptureTimeout) ) return false;
   if ( ! (itsIlluminationError == aRef.itsIlluminationError) ) return false;
   if ( ! (itsIlluminationOverTemperature == aRef.itsIlluminationOverTemperature) ) return false;
   if ( ! (itsIlluminationTemperatureSensorError == aRef.itsIlluminationTemperatureSensorError) ) return false;
   if ( ! (itsSerdesError == aRef.itsSerdesError) ) return false;
   if ( ! (itsTofCCPLLConfigurationError == aRef.itsTofCCPLLConfigurationError) ) return false;
   if ( ! (itsTofCCTemperatureError == aRef.itsTofCCTemperatureError) ) return false;
   if ( ! (itsTofSensorTemperatureSensorError == aRef.itsTofSensorTemperatureSensorError) ) return false;

   return true;
}

inline bool ErrorSet::operator < (const ErrorSet & aRef) const
{
   if ( ! (itsApplicationProcessorTooHot < aRef.itsApplicationProcessorTooHot) ) return false;
   if ( ! (itsCalibrationDataMissing < aRef.itsCalibrationDataMissing) ) return false;
   if ( ! (itsCaptureError < aRef.itsCaptureError) ) return false;
   if ( ! (itsCaptureTimeout < aRef.itsCaptureTimeout) ) return false;
   if ( ! (itsIlluminationError < aRef.itsIlluminationError) ) return false;
   if ( ! (itsIlluminationOverTemperature < aRef.itsIlluminationOverTemperature) ) return false;
   if ( ! (itsIlluminationTemperatureSensorError < aRef.itsIlluminationTemperatureSensorError) ) return false;
   if ( ! (itsSerdesError < aRef.itsSerdesError) ) return false;
   if ( ! (itsTofCCPLLConfigurationError < aRef.itsTofCCPLLConfigurationError) ) return false;
   if ( ! (itsTofCCTemperatureError < aRef.itsTofCCTemperatureError) ) return false;
   if ( ! (itsTofSensorTemperatureSensorError < aRef.itsTofSensorTemperatureSensorError) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const ErrorSet & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline bool ErrorSet::GetApplicationProcessorTooHot( ) const
{
 return itsApplicationProcessorTooHot;
}

inline void ErrorSet::SetApplicationProcessorTooHot( const bool & aValue )
{
 itsApplicationProcessorTooHot = aValue;
}

inline bool ErrorSet::GetCalibrationDataMissing( ) const
{
 return itsCalibrationDataMissing;
}

inline void ErrorSet::SetCalibrationDataMissing( const bool & aValue )
{
 itsCalibrationDataMissing = aValue;
}

inline bool ErrorSet::GetCaptureError( ) const
{
 return itsCaptureError;
}

inline void ErrorSet::SetCaptureError( const bool & aValue )
{
 itsCaptureError = aValue;
}

inline bool ErrorSet::GetCaptureTimeout( ) const
{
 return itsCaptureTimeout;
}

inline void ErrorSet::SetCaptureTimeout( const bool & aValue )
{
 itsCaptureTimeout = aValue;
}

inline bool ErrorSet::GetIlluminationError( ) const
{
 return itsIlluminationError;
}

inline void ErrorSet::SetIlluminationError( const bool & aValue )
{
 itsIlluminationError = aValue;
}

inline bool ErrorSet::GetIlluminationOverTemperature( ) const
{
 return itsIlluminationOverTemperature;
}

inline void ErrorSet::SetIlluminationOverTemperature( const bool & aValue )
{
 itsIlluminationOverTemperature = aValue;
}

inline bool ErrorSet::GetIlluminationTemperatureSensorError( ) const
{
 return itsIlluminationTemperatureSensorError;
}

inline void ErrorSet::SetIlluminationTemperatureSensorError( const bool & aValue )
{
 itsIlluminationTemperatureSensorError = aValue;
}

inline bool ErrorSet::GetSerdesError( ) const
{
 return itsSerdesError;
}

inline void ErrorSet::SetSerdesError( const bool & aValue )
{
 itsSerdesError = aValue;
}

inline bool ErrorSet::GetTofCCPLLConfigurationError( ) const
{
 return itsTofCCPLLConfigurationError;
}

inline void ErrorSet::SetTofCCPLLConfigurationError( const bool & aValue )
{
 itsTofCCPLLConfigurationError = aValue;
}

inline bool ErrorSet::GetTofCCTemperatureError( ) const
{
 return itsTofCCTemperatureError;
}

inline void ErrorSet::SetTofCCTemperatureError( const bool & aValue )
{
 itsTofCCTemperatureError = aValue;
}

inline bool ErrorSet::GetTofSensorTemperatureSensorError( ) const
{
 return itsTofSensorTemperatureSensorError;
}

inline void ErrorSet::SetTofSensorTemperatureSensorError( const bool & aValue )
{
 itsTofSensorTemperatureSensorError = aValue;
}






}; // End of namespace Cfl

#endif

