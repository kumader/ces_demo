///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- AutoModeReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class AutoModeReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_AutoModeReg_
#define _Rtl16_AutoModeReg_

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

/// The definition of class AutoModeReg
class AutoModeReg: public Virtual16BitReg
{
public:

   //enums

          enum RgbLedState_e
          {
          OFF = 0
         , MAX = 1
         , ON = 1 
          };


          enum 
          {
          NAME_ID = 0x296 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        AutoModeReg( );

   /// Special Constructor 
        AutoModeReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~AutoModeReg( );

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
       bool operator == (const AutoModeReg & aRef) const;
   
   /// Less operator 
       bool operator < (const AutoModeReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0AutoModeState
         ///  The Get function for member 0AutoModeState
              uint2   GetAutoModeState( ) const;
         ///  The Set function for member 0AutoModeState
              void    SetAutoModeState( const uint2 & aValue );
         ///  The ConvertToString function for member 0AutoModeState
              std::string    ConvertToStringAutoModeState( ) const;
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
         uint2 its0AutoModeState: 16;

};
};

}; // End of class AutoModeReg

//------------------------------ Inline Functions ----------------------
inline bool AutoModeReg::operator == (const AutoModeReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool AutoModeReg::operator < (const AutoModeReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const AutoModeReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 AutoModeReg::GetAddr( ) const
{
 return its0Addr;
}

inline void AutoModeReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 AutoModeReg::GetAutoModeState( ) const
{
 return its0AutoModeState;
}

inline void AutoModeReg::SetAutoModeState( const uint2 & aValue )
{
 its0AutoModeState = aValue;
}

inline uint2 AutoModeReg::GetReg( ) const
{
 return its0Reg;
}

inline void AutoModeReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}




inline std::string AutoModeReg::ConvertToStringAutoModeState( ) const
{
 switch (its0AutoModeState)
 {
 case 0: return "0:off"; break;
 case 1: return "1:on"; break; 
 default: return "unknown value"; 
 }//switch
}





}; // End of namespace Rtl16

#endif

