///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- SupervisorStatusReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class SupervisorStatusReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_SupervisorStatusReg_
#define _Rtl16_SupervisorStatusReg_

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

/// The definition of class SupervisorStatusReg
class SupervisorStatusReg: public Virtual16BitReg
{
public:

   //enums

          enum 
          {
          NAME_ID = 0x29b 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        SupervisorStatusReg( );

   /// Special Constructor 
        SupervisorStatusReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~SupervisorStatusReg( );

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
       bool operator == (const SupervisorStatusReg & aRef) const;
   
   /// Less operator 
       bool operator < (const SupervisorStatusReg & aRef) const;

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
         // The member 0StatusCtr
         ///  The Get function for member 0StatusCtr
              uint2   GetStatusCtr( ) const;
         ///  The Set function for member 0StatusCtr
              void    SetStatusCtr( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0StatusCtr: 16;

};
};

}; // End of class SupervisorStatusReg

//------------------------------ Inline Functions ----------------------
inline bool SupervisorStatusReg::operator == (const SupervisorStatusReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool SupervisorStatusReg::operator < (const SupervisorStatusReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const SupervisorStatusReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 SupervisorStatusReg::GetAddr( ) const
{
 return its0Addr;
}

inline void SupervisorStatusReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 SupervisorStatusReg::GetReg( ) const
{
 return its0Reg;
}

inline void SupervisorStatusReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 SupervisorStatusReg::GetStatusCtr( ) const
{
 return its0StatusCtr;
}

inline void SupervisorStatusReg::SetStatusCtr( const uint2 & aValue )
{
 its0StatusCtr = aValue;
}







}; // End of namespace Rtl16

#endif

