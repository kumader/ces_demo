///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CalibStatus2Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class CalibStatus2Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_CalibStatus2Reg_
#define _Rtl16_CalibStatus2Reg_

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

/// The definition of class CalibStatus2Reg
class CalibStatus2Reg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        CalibStatus2Reg( );

   /// Special Constructor 
        CalibStatus2Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~CalibStatus2Reg( );

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
       bool operator == (const CalibStatus2Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const CalibStatus2Reg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0NoWigglingCalibration
         ///  The Get function for member 0NoWigglingCalibration
              uint2   GetNoWigglingCalibration( ) const;
         ///  The Set function for member 0NoWigglingCalibration
              void    SetNoWigglingCalibration( const uint2 & aValue );
         ///  The ConvertToString function for member 0NoWigglingCalibration
              std::string    ConvertToStringNoWigglingCalibration( ) const;
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
         uint2 its0NoWigglingCalibration: 1;

};
};

}; // End of class CalibStatus2Reg

//------------------------------ Inline Functions ----------------------
inline bool CalibStatus2Reg::operator == (const CalibStatus2Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool CalibStatus2Reg::operator < (const CalibStatus2Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const CalibStatus2Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 CalibStatus2Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void CalibStatus2Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 CalibStatus2Reg::GetNoWigglingCalibration( ) const
{
 return its0NoWigglingCalibration;
}

inline void CalibStatus2Reg::SetNoWigglingCalibration( const uint2 & aValue )
{
 its0NoWigglingCalibration = aValue;
}

inline uint2 CalibStatus2Reg::GetReg( ) const
{
 return its0Reg;
}

inline void CalibStatus2Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}




inline std::string CalibStatus2Reg::ConvertToStringNoWigglingCalibration( ) const
{
 switch (its0NoWigglingCalibration)
 {
 case 0: return "0:Wiggling calibration data in NVRAM"; break;
 case 1: return "1:No wiggling calibration data in NVRAM"; break; 
 default: return "unknown value"; 
 }//switch
}





}; // End of namespace Rtl16

#endif
