///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4153 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class CalibStatusSet 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Tue Aug 15 16:01:14 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Cfl_CalibStatusSet_
#define _Cfl_CalibStatusSet_

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

/// The definition of class CalibStatusSet
class CalibStatusSet
{
public:

   //enums

          enum Status_e
          {
          IDLE = 0
         , FPPN = 19
         , ERASING_FLASH = 20
         , DISTOFFSET_CALIBRATION = 21
         , OPERATION_DONE = 161
         , REAL_WORLD_X_COORDINATE_VALUE_ZERO_OR_TOO_LARGE = 244
         , WRONG_IMAGEMODE_NEED_DISTANCE = 246
         , OUT_OF_MEMORY = 252
         , GENERIC_ERROR = 255 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        CalibStatusSet( );

   /// Destructor
        ~CalibStatusSet( );

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
       bool operator == (const CalibStatusSet & aRef) const;
   
   /// Less operator 
       bool operator < (const CalibStatusSet & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         // The member CalibErrorOccured
         ///  The Get function for member CalibErrorOccured
              bool   GetCalibErrorOccured( ) const;
         ///  The Set function for member CalibErrorOccured
              void    SetCalibErrorOccured( const bool & aValue );
         //----------------------------------------------------
         // The member NoFPPNCalibrationDataInNVRAM
         ///  The Get function for member NoFPPNCalibrationDataInNVRAM
              bool   GetNoFPPNCalibrationDataInNVRAM( ) const;
         ///  The Set function for member NoFPPNCalibrationDataInNVRAM
              void    SetNoFPPNCalibrationDataInNVRAM( const bool & aValue );
         //----------------------------------------------------
         // The member NoLensCalibrationDataInNVRAM
         ///  The Get function for member NoLensCalibrationDataInNVRAM
              bool   GetNoLensCalibrationDataInNVRAM( ) const;
         ///  The Set function for member NoLensCalibrationDataInNVRAM
              void    SetNoLensCalibrationDataInNVRAM( const bool & aValue );
         //----------------------------------------------------
         // The member NoWigglingCalibrationInNVRAM
         ///  The Get function for member NoWigglingCalibrationInNVRAM
              bool   GetNoWigglingCalibrationInNVRAM( ) const;
         ///  The Set function for member NoWigglingCalibrationInNVRAM
              void    SetNoWigglingCalibrationInNVRAM( const bool & aValue );
         //----------------------------------------------------
         // The member Status
         ///  The Get function for member Status
              uint2   GetStatus( ) const;
         ///  The Set function for member Status
              void    SetStatus( const uint2 & aValue );
         ///  The ConvertToString function for member Status
              std::string    ConvertToStringStatus( const uint2 & aValue ) const;
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         bool itsCalibErrorOccured;
         bool itsNoFPPNCalibrationDataInNVRAM;
         bool itsNoLensCalibrationDataInNVRAM;
         bool itsNoWigglingCalibrationInNVRAM;
         uint2 itsStatus;


}; // End of class CalibStatusSet

//------------------------------ Inline Functions ----------------------
inline bool CalibStatusSet::operator == (const CalibStatusSet & aRef) const
{
   if ( ! (itsCalibErrorOccured == aRef.itsCalibErrorOccured) ) return false;
   if ( ! (itsNoFPPNCalibrationDataInNVRAM == aRef.itsNoFPPNCalibrationDataInNVRAM) ) return false;
   if ( ! (itsNoLensCalibrationDataInNVRAM == aRef.itsNoLensCalibrationDataInNVRAM) ) return false;
   if ( ! (itsNoWigglingCalibrationInNVRAM == aRef.itsNoWigglingCalibrationInNVRAM) ) return false;
   if ( ! (itsStatus == aRef.itsStatus) ) return false;

   return true;
}

inline bool CalibStatusSet::operator < (const CalibStatusSet & aRef) const
{
   if ( ! (itsCalibErrorOccured < aRef.itsCalibErrorOccured) ) return false;
   if ( ! (itsNoFPPNCalibrationDataInNVRAM < aRef.itsNoFPPNCalibrationDataInNVRAM) ) return false;
   if ( ! (itsNoLensCalibrationDataInNVRAM < aRef.itsNoLensCalibrationDataInNVRAM) ) return false;
   if ( ! (itsNoWigglingCalibrationInNVRAM < aRef.itsNoWigglingCalibrationInNVRAM) ) return false;
   if ( ! (itsStatus < aRef.itsStatus) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const CalibStatusSet & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline bool CalibStatusSet::GetCalibErrorOccured( ) const
{
 return itsCalibErrorOccured;
}

inline void CalibStatusSet::SetCalibErrorOccured( const bool & aValue )
{
 itsCalibErrorOccured = aValue;
}

inline bool CalibStatusSet::GetNoFPPNCalibrationDataInNVRAM( ) const
{
 return itsNoFPPNCalibrationDataInNVRAM;
}

inline void CalibStatusSet::SetNoFPPNCalibrationDataInNVRAM( const bool & aValue )
{
 itsNoFPPNCalibrationDataInNVRAM = aValue;
}

inline bool CalibStatusSet::GetNoLensCalibrationDataInNVRAM( ) const
{
 return itsNoLensCalibrationDataInNVRAM;
}

inline void CalibStatusSet::SetNoLensCalibrationDataInNVRAM( const bool & aValue )
{
 itsNoLensCalibrationDataInNVRAM = aValue;
}

inline bool CalibStatusSet::GetNoWigglingCalibrationInNVRAM( ) const
{
 return itsNoWigglingCalibrationInNVRAM;
}

inline void CalibStatusSet::SetNoWigglingCalibrationInNVRAM( const bool & aValue )
{
 itsNoWigglingCalibrationInNVRAM = aValue;
}

inline uint2 CalibStatusSet::GetStatus( ) const
{
 return itsStatus;
}

inline void CalibStatusSet::SetStatus( const uint2 & aValue )
{
 itsStatus = aValue;
}




inline std::string CalibStatusSet::ConvertToStringStatus( const uint2 & aValue ) const
{
 switch (aValue)
 {
 case 0: return "0:Idle"; break;
 case 19: return "19:FPPN calibration"; break;
 case 20: return "20:Erasing flash"; break;
 case 21: return "21:DistOffset calibration"; break;
 case 161: return "161:Operation done"; break;
 case 244: return "23:RealWorldXCoordinate value zero or too large"; break;
 case 246: return "246:Wrong image mode (Need distance)"; break;
 case 252: return "252:Out of memory"; break;
 case 255: return "255:Generic error"; break; 
 default: return "unknown value"; 
 }//switch
}




}; // End of namespace Cfl

#endif

