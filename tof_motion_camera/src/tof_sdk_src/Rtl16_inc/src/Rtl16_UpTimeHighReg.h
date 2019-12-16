///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- UpTimeHighReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class UpTimeHighReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_UpTimeHighReg_
#define _Rtl16_UpTimeHighReg_

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

/// The definition of class UpTimeHighReg
class UpTimeHighReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        UpTimeHighReg( );

   /// Special Constructor 
        UpTimeHighReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~UpTimeHighReg( );

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
       bool operator == (const UpTimeHighReg & aRef) const;
   
   /// Less operator 
       bool operator < (const UpTimeHighReg & aRef) const;

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
         // The member 0UpTimeHigh_s
         ///  The Get function for member 0UpTimeHigh_s
              uint2   GetUpTimeHigh_s( ) const;
         ///  The Set function for member 0UpTimeHigh_s
              void    SetUpTimeHigh_s( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0UpTimeHigh_s: 16;

};
};

}; // End of class UpTimeHighReg

//------------------------------ Inline Functions ----------------------
inline bool UpTimeHighReg::operator == (const UpTimeHighReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool UpTimeHighReg::operator < (const UpTimeHighReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const UpTimeHighReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 UpTimeHighReg::GetAddr( ) const
{
 return its0Addr;
}

inline void UpTimeHighReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 UpTimeHighReg::GetReg( ) const
{
 return its0Reg;
}

inline void UpTimeHighReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 UpTimeHighReg::GetUpTimeHigh_s( ) const
{
 return its0UpTimeHigh_s;
}

inline void UpTimeHighReg::SetUpTimeHigh_s( const uint2 & aValue )
{
 its0UpTimeHigh_s = aValue;
}







}; // End of namespace Rtl16

#endif

