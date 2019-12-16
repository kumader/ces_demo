///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- StatusReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class StatusReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_StatusReg_
#define _Rtl16_StatusReg_

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>

#ifdef _TARGET_ARCH_W32_
#define WIN32_LEAN_AND_MEAN
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#endif

#include <string>

#include "Rtl16_Virtual16BitReg.h"

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace Rtl16
namespace Rtl16
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class StatusReg
class StatusReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        StatusReg( );

   /// Special Constructor 
        StatusReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~StatusReg( );

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
       bool operator == (const StatusReg & aRef) const;
   
   /// Less operator 
       bool operator < (const StatusReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );
         //----------------------------------------------------
         // The member 2OngoingCalibration
         ///  The Get function for member 2OngoingCalibration
              uint2   GetOngoingCalibration( ) const;
         ///  The Set function for member 2OngoingCalibration
              void    SetOngoingCalibration( const uint2 & aValue );
         //----------------------------------------------------
         // The member 3IlluminationTemperatureSensorError
         ///  The Get function for member 3IlluminationTemperatureSensorError
              uint2   GetIlluminationTemperatureSensorError( ) const;
         ///  The Set function for member 3IlluminationTemperatureSensorError
              void    SetIlluminationTemperatureSensorError( const uint2 & aValue );
         //----------------------------------------------------
         // The member 4TofSensorTemperatureSensorError
         ///  The Get function for member 4TofSensorTemperatureSensorError
              uint2   GetTofSensorTemperatureSensorError( ) const;
         ///  The Set function for member 4TofSensorTemperatureSensorError
              void    SetTofSensorTemperatureSensorError( const uint2 & aValue );
         //----------------------------------------------------
         // The member 5CalibrationDataMissing
         ///  The Get function for member 5CalibrationDataMissing
              uint2   GetCalibrationDataMissing( ) const;
         ///  The Set function for member 5CalibrationDataMissing
              void    SetCalibrationDataMissing( const uint2 & aValue );
         //----------------------------------------------------
         // The member 6FactoryRegMapWasLoaded
         ///  The Get function for member 6FactoryRegMapWasLoaded
              uint2   GetFactoryRegMapWasLoaded( ) const;
         ///  The Set function for member 6FactoryRegMapWasLoaded
              void    SetFactoryRegMapWasLoaded( const uint2 & aValue );
         //----------------------------------------------------
         // The member 8PreviousFirmwareVersionWasRestored
         ///  The Get function for member 8PreviousFirmwareVersionWasRestored
              uint2   GetPreviousFirmwareVersionWasRestored( ) const;
         ///  The Set function for member 8PreviousFirmwareVersionWasRestored
              void    SetPreviousFirmwareVersionWasRestored( const uint2 & aValue );
         //----------------------------------------------------
         // The member 9IlluminationOverTemperature
         ///  The Get function for member 9IlluminationOverTemperature
              uint2   GetIlluminationOverTemperature( ) const;
         ///  The Set function for member 9IlluminationOverTemperature
              void    SetIlluminationOverTemperature( const uint2 & aValue );
         //----------------------------------------------------
         // The member 11IlluminationError
         ///  The Get function for member 11IlluminationError
              uint2   GetIlluminationError( ) const;
         ///  The Set function for member 11IlluminationError
              void    SetIlluminationError( const uint2 & aValue );
         //----------------------------------------------------
         // The member 14TofCCTemperatureError
         ///  The Get function for member 14TofCCTemperatureError
              uint2   GetTofCCTemperatureError( ) const;
         ///  The Set function for member 14TofCCTemperatureError
              void    SetTofCCTemperatureError( const uint2 & aValue );
         //----------------------------------------------------
         // The member 15TofCCPLLConfigurationError
         ///  The Get function for member 15TofCCPLLConfigurationError
              uint2   GetTofCCPLLConfigurationError( ) const;
         ///  The Set function for member 15TofCCPLLConfigurationError
              void    SetTofCCPLLConfigurationError( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0Reserved: 1;
         uint2 its1Reserved: 1;
         uint2 its2OngoingCalibration: 1;
         uint2 its3IlluminationTemperatureSensorError: 1;
         uint2 its4TofSensorTemperatureSensorError: 1;
         uint2 its5CalibrationDataMissing: 1;
         uint2 its6FactoryRegMapWasLoaded: 1;
         uint2 its7Reserved: 1;
         uint2 its8PreviousFirmwareVersionWasRestored: 1;
         uint2 its9IlluminationOverTemperature: 1;
         uint2 its10Reserved: 1;
         uint2 its11IlluminationError: 1;
         uint2 its12Reserved: 1;
         uint2 its13Reserved: 1;
         uint2 its14TofCCTemperatureError: 1;
         uint2 its15TofCCPLLConfigurationError: 1;

};
};

}; // End of class StatusReg

//------------------------------ Inline Functions ----------------------
inline bool StatusReg::operator == (const StatusReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool StatusReg::operator < (const StatusReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const StatusReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 StatusReg::GetAddr( ) const
{
 return its0Addr;
}

inline void StatusReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 StatusReg::GetReg( ) const
{
 return its0Reg;
}

inline void StatusReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 StatusReg::GetOngoingCalibration( ) const
{
 return its2OngoingCalibration;
}

inline void StatusReg::SetOngoingCalibration( const uint2 & aValue )
{
 its2OngoingCalibration = aValue;
}

inline uint2 StatusReg::GetIlluminationTemperatureSensorError( ) const
{
 return its3IlluminationTemperatureSensorError;
}

inline void StatusReg::SetIlluminationTemperatureSensorError( const uint2 & aValue )
{
 its3IlluminationTemperatureSensorError = aValue;
}

inline uint2 StatusReg::GetTofSensorTemperatureSensorError( ) const
{
 return its4TofSensorTemperatureSensorError;
}

inline void StatusReg::SetTofSensorTemperatureSensorError( const uint2 & aValue )
{
 its4TofSensorTemperatureSensorError = aValue;
}

inline uint2 StatusReg::GetCalibrationDataMissing( ) const
{
 return its5CalibrationDataMissing;
}

inline void StatusReg::SetCalibrationDataMissing( const uint2 & aValue )
{
 its5CalibrationDataMissing = aValue;
}

inline uint2 StatusReg::GetFactoryRegMapWasLoaded( ) const
{
 return its6FactoryRegMapWasLoaded;
}

inline void StatusReg::SetFactoryRegMapWasLoaded( const uint2 & aValue )
{
 its6FactoryRegMapWasLoaded = aValue;
}

inline uint2 StatusReg::GetPreviousFirmwareVersionWasRestored( ) const
{
 return its8PreviousFirmwareVersionWasRestored;
}

inline void StatusReg::SetPreviousFirmwareVersionWasRestored( const uint2 & aValue )
{
 its8PreviousFirmwareVersionWasRestored = aValue;
}

inline uint2 StatusReg::GetIlluminationOverTemperature( ) const
{
 return its9IlluminationOverTemperature;
}

inline void StatusReg::SetIlluminationOverTemperature( const uint2 & aValue )
{
 its9IlluminationOverTemperature = aValue;
}

inline uint2 StatusReg::GetIlluminationError( ) const
{
 return its11IlluminationError;
}

inline void StatusReg::SetIlluminationError( const uint2 & aValue )
{
 its11IlluminationError = aValue;
}

inline uint2 StatusReg::GetTofCCTemperatureError( ) const
{
 return its14TofCCTemperatureError;
}

inline void StatusReg::SetTofCCTemperatureError( const uint2 & aValue )
{
 its14TofCCTemperatureError = aValue;
}

inline uint2 StatusReg::GetTofCCPLLConfigurationError( ) const
{
 return its15TofCCPLLConfigurationError;
}

inline void StatusReg::SetTofCCPLLConfigurationError( const uint2 & aValue )
{
 its15TofCCPLLConfigurationError = aValue;
}







}; // End of namespace Rtl16

#endif

