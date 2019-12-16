///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- TstConfigReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class TstConfigReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_TstConfigReg_
#define _Rtl16_TstConfigReg_

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

/// The definition of class TstConfigReg
class TstConfigReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        TstConfigReg( );

   /// Special Constructor 
        TstConfigReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~TstConfigReg( );

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
       bool operator == (const TstConfigReg & aRef) const;
   
   /// Less operator 
       bool operator < (const TstConfigReg & aRef) const;

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
         // The member 0TestConfig
         ///  The Get function for member 0TestConfig
              uint2   GetTestConfig( ) const;
         ///  The Set function for member 0TestConfig
              void    SetTestConfig( const uint2 & aValue );
         ///  The ConvertToString function for member 0TestConfig
              std::string    ConvertToStringTestConfig( ) const;

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0TestConfig: 1;

};
};

}; // End of class TstConfigReg

//------------------------------ Inline Functions ----------------------
inline bool TstConfigReg::operator == (const TstConfigReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool TstConfigReg::operator < (const TstConfigReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const TstConfigReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 TstConfigReg::GetAddr( ) const
{
 return its0Addr;
}

inline void TstConfigReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 TstConfigReg::GetReg( ) const
{
 return its0Reg;
}

inline void TstConfigReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 TstConfigReg::GetTestConfig( ) const
{
 return its0TestConfig;
}

inline void TstConfigReg::SetTestConfig( const uint2 & aValue )
{
 its0TestConfig = aValue;
}




inline std::string TstConfigReg::ConvertToStringTestConfig( ) const
{
 switch (its0TestConfig)
 {
 case 1: return "1:Watchdog Test"; break; 
 default: return "unknown value"; 
 }//switch
}





}; // End of namespace Rtl16

#endif

