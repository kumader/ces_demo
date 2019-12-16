///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- SupervisorAliveReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class SupervisorAliveReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_SupervisorAliveReg_
#define _Rtl16_SupervisorAliveReg_

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

/// The definition of class SupervisorAliveReg
class SupervisorAliveReg: public Virtual16BitReg
{
public:

   //enums

          enum 
          {
          NAME_ID = 0x29a 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        SupervisorAliveReg( );

   /// Special Constructor 
        SupervisorAliveReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~SupervisorAliveReg( );

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
       bool operator == (const SupervisorAliveReg & aRef) const;
   
   /// Less operator 
       bool operator < (const SupervisorAliveReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0AliveCtr
         ///  The Get function for member 0AliveCtr
              uint2   GetAliveCtr( ) const;
         ///  The Set function for member 0AliveCtr
              void    SetAliveCtr( const uint2 & aValue );
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
         uint2 its0AliveCtr: 16;

};
};

}; // End of class SupervisorAliveReg

//------------------------------ Inline Functions ----------------------
inline bool SupervisorAliveReg::operator == (const SupervisorAliveReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool SupervisorAliveReg::operator < (const SupervisorAliveReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const SupervisorAliveReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 SupervisorAliveReg::GetAddr( ) const
{
 return its0Addr;
}

inline void SupervisorAliveReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 SupervisorAliveReg::GetAliveCtr( ) const
{
 return its0AliveCtr;
}

inline void SupervisorAliveReg::SetAliveCtr( const uint2 & aValue )
{
 its0AliveCtr = aValue;
}

inline uint2 SupervisorAliveReg::GetReg( ) const
{
 return its0Reg;
}

inline void SupervisorAliveReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}







}; // End of namespace Rtl16

#endif

