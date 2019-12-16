///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Eth0TcpCtrlPortReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class Eth0TcpCtrlPortReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_Eth0TcpCtrlPortReg_
#define _Rtl16_Eth0TcpCtrlPortReg_

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

/// The definition of class Eth0TcpCtrlPortReg
class Eth0TcpCtrlPortReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        Eth0TcpCtrlPortReg( );

   /// Special Constructor 
        Eth0TcpCtrlPortReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~Eth0TcpCtrlPortReg( );

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
       bool operator == (const Eth0TcpCtrlPortReg & aRef) const;
   
   /// Less operator 
       bool operator < (const Eth0TcpCtrlPortReg & aRef) const;

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
         // The member 0TcpCtrlPort
         ///  The Get function for member 0TcpCtrlPort
              uint2   GetTcpCtrlPort( ) const;
         ///  The Set function for member 0TcpCtrlPort
              void    SetTcpCtrlPort( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0TcpCtrlPort: 16;

};
};

}; // End of class Eth0TcpCtrlPortReg

//------------------------------ Inline Functions ----------------------
inline bool Eth0TcpCtrlPortReg::operator == (const Eth0TcpCtrlPortReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool Eth0TcpCtrlPortReg::operator < (const Eth0TcpCtrlPortReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const Eth0TcpCtrlPortReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 Eth0TcpCtrlPortReg::GetAddr( ) const
{
 return its0Addr;
}

inline void Eth0TcpCtrlPortReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 Eth0TcpCtrlPortReg::GetReg( ) const
{
 return its0Reg;
}

inline void Eth0TcpCtrlPortReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 Eth0TcpCtrlPortReg::GetTcpCtrlPort( ) const
{
 return its0TcpCtrlPort;
}

inline void Eth0TcpCtrlPortReg::SetTcpCtrlPort( const uint2 & aValue )
{
 its0TcpCtrlPort = aValue;
}







}; // End of namespace Rtl16

#endif

