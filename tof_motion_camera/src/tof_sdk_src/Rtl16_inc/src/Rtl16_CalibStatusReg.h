///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CalibStatusReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class CalibStatusReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_CalibStatusReg_
#define _Rtl16_CalibStatusReg_

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

/// The definition of class CalibStatusReg
class CalibStatusReg: public Virtual16BitReg
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
        CalibStatusReg( );

   /// Special Constructor 
        CalibStatusReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~CalibStatusReg( );

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
       bool operator == (const CalibStatusReg & aRef) const;
   
   /// Less operator 
       bool operator < (const CalibStatusReg & aRef) const;

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
         // The member 0Status
         ///  The Get function for member 0Status
              uint2   GetStatus( ) const;
         ///  The Set function for member 0Status
              void    SetStatus( const uint2 & aValue );
         ///  The ConvertToString function for member 0Status
              std::string    ConvertToStringStatus( ) const;
         //----------------------------------------------------
         // The member 10ErrorOccured
         ///  The Get function for member 10ErrorOccured
              uint2   GetErrorOccured( ) const;
         ///  The Set function for member 10ErrorOccured
              void    SetErrorOccured( const uint2 & aValue );
         //----------------------------------------------------
         // The member 12NoFPPNCalibrationDataInNVRAM
         ///  The Get function for member 12NoFPPNCalibrationDataInNVRAM
              uint2   GetNoFPPNCalibrationDataInNVRAM( ) const;
         ///  The Set function for member 12NoFPPNCalibrationDataInNVRAM
              void    SetNoFPPNCalibrationDataInNVRAM( const uint2 & aValue );
         //----------------------------------------------------
         // The member 14NoLensCalibrationDataInNVRAM
         ///  The Get function for member 14NoLensCalibrationDataInNVRAM
              uint2   GetNoLensCalibrationDataInNVRAM( ) const;
         ///  The Set function for member 14NoLensCalibrationDataInNVRAM
              void    SetNoLensCalibrationDataInNVRAM( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0Status: 8;
         uint2 its9Reserved: 1;
         uint2 its10ErrorOccured: 1;
         uint2 its11Reserved: 1;
         uint2 its12NoFPPNCalibrationDataInNVRAM: 1;
         uint2 its13Reserved: 1;
         uint2 its14NoLensCalibrationDataInNVRAM: 1;
         uint2 its15Reserved: 1;

};
};

}; // End of class CalibStatusReg

//------------------------------ Inline Functions ----------------------
inline bool CalibStatusReg::operator == (const CalibStatusReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool CalibStatusReg::operator < (const CalibStatusReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const CalibStatusReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 CalibStatusReg::GetAddr( ) const
{
 return its0Addr;
}

inline void CalibStatusReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 CalibStatusReg::GetReg( ) const
{
 return its0Reg;
}

inline void CalibStatusReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 CalibStatusReg::GetStatus( ) const
{
 return its0Status;
}

inline void CalibStatusReg::SetStatus( const uint2 & aValue )
{
 its0Status = aValue;
}

inline uint2 CalibStatusReg::GetErrorOccured( ) const
{
 return its10ErrorOccured;
}

inline void CalibStatusReg::SetErrorOccured( const uint2 & aValue )
{
 its10ErrorOccured = aValue;
}

inline uint2 CalibStatusReg::GetNoFPPNCalibrationDataInNVRAM( ) const
{
 return its12NoFPPNCalibrationDataInNVRAM;
}

inline void CalibStatusReg::SetNoFPPNCalibrationDataInNVRAM( const uint2 & aValue )
{
 its12NoFPPNCalibrationDataInNVRAM = aValue;
}

inline uint2 CalibStatusReg::GetNoLensCalibrationDataInNVRAM( ) const
{
 return its14NoLensCalibrationDataInNVRAM;
}

inline void CalibStatusReg::SetNoLensCalibrationDataInNVRAM( const uint2 & aValue )
{
 its14NoLensCalibrationDataInNVRAM = aValue;
}




inline std::string CalibStatusReg::ConvertToStringStatus( ) const
{
 switch (its0Status)
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





}; // End of namespace Rtl16

#endif

