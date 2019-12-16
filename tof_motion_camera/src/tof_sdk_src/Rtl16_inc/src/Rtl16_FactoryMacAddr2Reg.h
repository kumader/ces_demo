///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- FactoryMacAddr2Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FactoryMacAddr2Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_FactoryMacAddr2Reg_
#define _Rtl16_FactoryMacAddr2Reg_

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

/// The definition of class FactoryMacAddr2Reg
class FactoryMacAddr2Reg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        FactoryMacAddr2Reg( );

   /// Special Constructor 
        FactoryMacAddr2Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~FactoryMacAddr2Reg( );

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
       bool operator == (const FactoryMacAddr2Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const FactoryMacAddr2Reg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Byte4
         ///  The Get function for member 0Byte4
              uint2   GetByte4( ) const;
         ///  The Set function for member 0Byte4
              void    SetByte4( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );
         //----------------------------------------------------
         // The member 8Byte5
         ///  The Get function for member 8Byte5
              uint2   GetByte5( ) const;
         ///  The Set function for member 8Byte5
              void    SetByte5( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0Byte4: 8;
         uint2 its8Byte5: 8;

};
};

}; // End of class FactoryMacAddr2Reg

//------------------------------ Inline Functions ----------------------
inline bool FactoryMacAddr2Reg::operator == (const FactoryMacAddr2Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool FactoryMacAddr2Reg::operator < (const FactoryMacAddr2Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FactoryMacAddr2Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 FactoryMacAddr2Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void FactoryMacAddr2Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 FactoryMacAddr2Reg::GetByte4( ) const
{
 return its0Byte4;
}

inline void FactoryMacAddr2Reg::SetByte4( const uint2 & aValue )
{
 its0Byte4 = aValue;
}

inline uint2 FactoryMacAddr2Reg::GetReg( ) const
{
 return its0Reg;
}

inline void FactoryMacAddr2Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 FactoryMacAddr2Reg::GetByte5( ) const
{
 return its8Byte5;
}

inline void FactoryMacAddr2Reg::SetByte5( const uint2 & aValue )
{
 its8Byte5 = aValue;
}







}; // End of namespace Rtl16

#endif

