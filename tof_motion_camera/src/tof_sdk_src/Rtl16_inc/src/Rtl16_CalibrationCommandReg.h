///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CalibrationCommandReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class CalibrationCommandReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_CalibrationCommandReg_
#define _Rtl16_CalibrationCommandReg_

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

/// The definition of class CalibrationCommandReg
class CalibrationCommandReg: public Virtual16BitReg
{
public:

   //enums

          enum CmdCode_e
          {
          SET_FPPN = 13
         , CLEAR_FPPN = 16
         , CALIBRATE_DISTOFFSET = 19 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        CalibrationCommandReg( );

   /// Special Constructor 
        CalibrationCommandReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~CalibrationCommandReg( );

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
       bool operator == (const CalibrationCommandReg & aRef) const;
   
   /// Less operator 
       bool operator < (const CalibrationCommandReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0CmdCode
         ///  The Get function for member 0CmdCode
              uint2   GetCmdCode( ) const;
         ///  The Set function for member 0CmdCode
              void    SetCmdCode( const uint2 & aValue );
         ///  The ConvertToString function for member 0CmdCode
              std::string    ConvertToStringCmdCode( ) const;
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0CmdCode: 8;

};
};

}; // End of class CalibrationCommandReg

//------------------------------ Inline Functions ----------------------
inline bool CalibrationCommandReg::operator == (const CalibrationCommandReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool CalibrationCommandReg::operator < (const CalibrationCommandReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const CalibrationCommandReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 CalibrationCommandReg::GetAddr( ) const
{
 return its0Addr;
}

inline void CalibrationCommandReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 CalibrationCommandReg::GetCmdCode( ) const
{
 return its0CmdCode;
}

inline void CalibrationCommandReg::SetCmdCode( const uint2 & aValue )
{
 its0CmdCode = aValue;
}

inline uint2 CalibrationCommandReg::GetReg( ) const
{
 return its0Reg;
}

inline void CalibrationCommandReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}




inline std::string CalibrationCommandReg::ConvertToStringCmdCode( ) const
{
 switch (its0CmdCode)
 {
 case 13: return "0:FPPN on the current modulation frequency"; break;
 case 16: return "19:Clear FPPN calibration data for current modulation frequency"; break;
 case 19: return "20:Calibrate DistOffset of the current modulation frequency"; break; 
 default: return "unknown value"; 
 }//switch
}





}; // End of namespace Rtl16

#endif

