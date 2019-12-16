///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- USERn_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class USERn_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_USERn_Reg_
#define _Rtl16_USERn_Reg_

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

/// The definition of class USERn_Reg
class USERn_Reg: public Virtual16BitReg
{
public:

   //enums

          enum Register_e
          {
          USER0 = 0x111a
         , USER1 = 0x111c
         , USER2 = 0x111e
         , USER3 = 0x1120
         , USER63 = 0x1198 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        USERn_Reg( );

   /// Special Constructor 
        USERn_Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~USERn_Reg( );

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
       bool operator == (const USERn_Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const USERn_Reg & aRef) const;

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
         // The member 0USERn
         ///  The Get function for member 0USERn
              uint2   GetUSERn( ) const;
         ///  The Set function for member 0USERn
              void    SetUSERn( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0USERn: 16;

};
};

}; // End of class USERn_Reg

//------------------------------ Inline Functions ----------------------
inline bool USERn_Reg::operator == (const USERn_Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool USERn_Reg::operator < (const USERn_Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const USERn_Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 USERn_Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void USERn_Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 USERn_Reg::GetReg( ) const
{
 return its0Reg;
}

inline void USERn_Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 USERn_Reg::GetUSERn( ) const
{
 return its0USERn;
}

inline void USERn_Reg::SetUSERn( const uint2 & aValue )
{
 its0USERn = aValue;
}







}; // End of namespace Rtl16

#endif

