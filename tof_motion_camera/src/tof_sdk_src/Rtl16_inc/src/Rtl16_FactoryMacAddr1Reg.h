///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- FactoryMacAddr1Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FactoryMacAddr1Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_FactoryMacAddr1Reg_
#define _Rtl16_FactoryMacAddr1Reg_

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

/// The definition of class FactoryMacAddr1Reg
class FactoryMacAddr1Reg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        FactoryMacAddr1Reg( );

   /// Special Constructor 
        FactoryMacAddr1Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~FactoryMacAddr1Reg( );

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
       bool operator == (const FactoryMacAddr1Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const FactoryMacAddr1Reg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Byte2
         ///  The Get function for member 0Byte2
              uint2   GetByte2( ) const;
         ///  The Set function for member 0Byte2
              void    SetByte2( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );
         //----------------------------------------------------
         // The member 8Byte3
         ///  The Get function for member 8Byte3
              uint2   GetByte3( ) const;
         ///  The Set function for member 8Byte3
              void    SetByte3( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0Byte2: 8;
         uint2 its8Byte3: 8;

};
};

}; // End of class FactoryMacAddr1Reg

//------------------------------ Inline Functions ----------------------
inline bool FactoryMacAddr1Reg::operator == (const FactoryMacAddr1Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool FactoryMacAddr1Reg::operator < (const FactoryMacAddr1Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FactoryMacAddr1Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 FactoryMacAddr1Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void FactoryMacAddr1Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 FactoryMacAddr1Reg::GetByte2( ) const
{
 return its0Byte2;
}

inline void FactoryMacAddr1Reg::SetByte2( const uint2 & aValue )
{
 its0Byte2 = aValue;
}

inline uint2 FactoryMacAddr1Reg::GetReg( ) const
{
 return its0Reg;
}

inline void FactoryMacAddr1Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 FactoryMacAddr1Reg::GetByte3( ) const
{
 return its8Byte3;
}

inline void FactoryMacAddr1Reg::SetByte3( const uint2 & aValue )
{
 its8Byte3 = aValue;
}







}; // End of namespace Rtl16

#endif

