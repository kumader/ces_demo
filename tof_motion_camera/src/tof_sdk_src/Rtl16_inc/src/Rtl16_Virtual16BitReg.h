///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Virtual16BitReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class Virtual16BitReg 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Wed Jul 19 20:33:27 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_Virtual16BitReg_
#define _Rtl16_Virtual16BitReg_

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

/// The namespace Rtl16
namespace Rtl16
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class Virtual16BitReg
class Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        Virtual16BitReg( );

   /// Destructor
        virtual ~Virtual16BitReg( );
 
   /// Write content into buffer
        virtual  bool WriteToBuffer( uint1 * buffer
                          , uint2 aBufferSize
                          , uint2 & aByteOffset ) const=0;
   /// Read content from buffer
        virtual  bool ReadFromBuffer( const uint1 * buffer
                           , uint2 aBufferSize
                           , uint2 & aByteOffset )=0;


   /// Write human readable representation of content
        virtual void Log( std::ostream & aStreamRef ) const;
   
   /// Write human readable representation with indentation
        virtual  void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

   //  Arithmetic operators
   /// Equal operator 
       virtual bool operator == (const Virtual16BitReg & aRef) const;
   
   /// Less operator 
       virtual bool operator < (const Virtual16BitReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         // The member 0Addr
         ///  The Get function for member 0Addr
              virtual uint2   GetAddr( ) const = 0;
         ///  The Set function for member 0Addr
              virtual void    SetAddr( const uint2 & aValue ) = 0;
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              virtual uint2   GetReg( ) const = 0;
         ///  The Set function for member 0Reg
              virtual void    SetReg( const uint2 & aValue ) = 0;
         //----------------------------------------------------

   //@}

private:
 

   // nothing 


}; // End of class Virtual16BitReg

//------------------------------ Inline Functions ----------------------
inline bool Virtual16BitReg::operator == (const Virtual16BitReg & aRef) const
{
   if ( ! (GetAddr() == aRef.GetAddr()) ) return false;
   if ( ! (GetReg() == aRef.GetReg()) ) return false;

   return true;
}

inline bool Virtual16BitReg::operator < (const Virtual16BitReg & aRef) const
{
   if ( ! (GetAddr() < aRef.GetAddr()) ) return false;
   if ( ! (GetReg() < aRef.GetReg()) ) return false;


   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const Virtual16BitReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}



}; // End of namespace Rtl16

#endif

