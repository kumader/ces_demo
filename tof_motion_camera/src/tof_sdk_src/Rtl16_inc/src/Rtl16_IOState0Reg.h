///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- IOState0Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class IOState0Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_IOState0Reg_
#define _Rtl16_IOState0Reg_

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

/// The definition of class IOState0Reg
class IOState0Reg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        IOState0Reg( );

   /// Special Constructor 
        IOState0Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~IOState0Reg( );

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
       bool operator == (const IOState0Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const IOState0Reg & aRef) const;

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
         // The member 9GPO0
         ///  The Get function for member 9GPO0
              uint2   GetGPO0( ) const;
         ///  The Set function for member 9GPO0
              void    SetGPO0( const uint2 & aValue );
         //----------------------------------------------------
         // The member 10GPO1
         ///  The Get function for member 10GPO1
              uint2   GetGPO1( ) const;
         ///  The Set function for member 10GPO1
              void    SetGPO1( const uint2 & aValue );
         //----------------------------------------------------
         // The member 11GPO2
         ///  The Get function for member 11GPO2
              uint2   GetGPO2( ) const;
         ///  The Set function for member 11GPO2
              void    SetGPO2( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0Reserved: 1;
         uint2 its1Reserved: 1;
         uint2 its2Reserved: 1;
         uint2 its3Reserved: 1;
         uint2 its4Reserved: 1;
         uint2 its5Reserved: 1;
         uint2 its6Reserved: 1;
         uint2 its7Reserved: 1;
         uint2 its8Reserved: 1;
         uint2 its9GPO0: 1;
         uint2 its10GPO1: 1;
         uint2 its11GPO2: 1;

};
};

}; // End of class IOState0Reg

//------------------------------ Inline Functions ----------------------
inline bool IOState0Reg::operator == (const IOState0Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool IOState0Reg::operator < (const IOState0Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const IOState0Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 IOState0Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void IOState0Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 IOState0Reg::GetReg( ) const
{
 return its0Reg;
}

inline void IOState0Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 IOState0Reg::GetGPO0( ) const
{
 return its9GPO0;
}

inline void IOState0Reg::SetGPO0( const uint2 & aValue )
{
 its9GPO0 = aValue;
}

inline uint2 IOState0Reg::GetGPO1( ) const
{
 return its10GPO1;
}

inline void IOState0Reg::SetGPO1( const uint2 & aValue )
{
 its10GPO1 = aValue;
}

inline uint2 IOState0Reg::GetGPO2( ) const
{
 return its11GPO2;
}

inline void IOState0Reg::SetGPO2( const uint2 & aValue )
{
 its11GPO2 = aValue;
}







}; // End of namespace Rtl16

#endif

