///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- RgbLedReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class RgbLedReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_RgbLedReg_
#define _Rtl16_RgbLedReg_

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

/// The definition of class RgbLedReg
class RgbLedReg: public Virtual16BitReg
{
public:

   //enums

          enum RgbLedState_e
          {
          OFF = 0
         , BLUE = 1
         , GREEN = 2
         , RED = 3
         , MAX = 3 
          };


          enum 
          {
          NAME_ID = 0x294 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        RgbLedReg( );

   /// Special Constructor 
        RgbLedReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~RgbLedReg( );

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
       bool operator == (const RgbLedReg & aRef) const;
   
   /// Less operator 
       bool operator < (const RgbLedReg & aRef) const;

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
         // The member 0RgbLedState
         ///  The Get function for member 0RgbLedState
              uint2   GetRgbLedState( ) const;
         ///  The Set function for member 0RgbLedState
              void    SetRgbLedState( const uint2 & aValue );
         ///  The ConvertToString function for member 0RgbLedState
              std::string    ConvertToStringRgbLedState( ) const;

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0RgbLedState: 16;

};
};

}; // End of class RgbLedReg

//------------------------------ Inline Functions ----------------------
inline bool RgbLedReg::operator == (const RgbLedReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool RgbLedReg::operator < (const RgbLedReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const RgbLedReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 RgbLedReg::GetAddr( ) const
{
 return its0Addr;
}

inline void RgbLedReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 RgbLedReg::GetReg( ) const
{
 return its0Reg;
}

inline void RgbLedReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 RgbLedReg::GetRgbLedState( ) const
{
 return its0RgbLedState;
}

inline void RgbLedReg::SetRgbLedState( const uint2 & aValue )
{
 its0RgbLedState = aValue;
}




inline std::string RgbLedReg::ConvertToStringRgbLedState( ) const
{
 switch (its0RgbLedState)
 {
 case 0: return "0:off"; break;
 case 1: return "1:blue"; break;
 case 2: return "2:green"; break;
 case 3: return "3:red"; break; 
 default: return "unknown value"; 
 }//switch
}





}; // End of namespace Rtl16

#endif

