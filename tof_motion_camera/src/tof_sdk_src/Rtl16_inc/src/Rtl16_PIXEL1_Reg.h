///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- PIXEL1_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class PIXEL1_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_PIXEL1_Reg_
#define _Rtl16_PIXEL1_Reg_

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

/// The definition of class PIXEL1_Reg
class PIXEL1_Reg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        PIXEL1_Reg( );

   /// Special Constructor 
        PIXEL1_Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~PIXEL1_Reg( );

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
       bool operator == (const PIXEL1_Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const PIXEL1_Reg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0PIXEL1_X
         ///  The Get function for member 0PIXEL1_X
              uint2   GetPIXEL1_X( ) const;
         ///  The Set function for member 0PIXEL1_X
              void    SetPIXEL1_X( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );
         //----------------------------------------------------
         // The member 8PIXEL1_Y
         ///  The Get function for member 8PIXEL1_Y
              uint2   GetPIXEL1_Y( ) const;
         ///  The Set function for member 8PIXEL1_Y
              void    SetPIXEL1_Y( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0PIXEL1_X: 8;
         uint2 its8PIXEL1_Y: 8;

};
};

}; // End of class PIXEL1_Reg

//------------------------------ Inline Functions ----------------------
inline bool PIXEL1_Reg::operator == (const PIXEL1_Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool PIXEL1_Reg::operator < (const PIXEL1_Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const PIXEL1_Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 PIXEL1_Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void PIXEL1_Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 PIXEL1_Reg::GetPIXEL1_X( ) const
{
 return its0PIXEL1_X;
}

inline void PIXEL1_Reg::SetPIXEL1_X( const uint2 & aValue )
{
 its0PIXEL1_X = aValue;
}

inline uint2 PIXEL1_Reg::GetReg( ) const
{
 return its0Reg;
}

inline void PIXEL1_Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 PIXEL1_Reg::GetPIXEL1_Y( ) const
{
 return its8PIXEL1_Y;
}

inline void PIXEL1_Reg::SetPIXEL1_Y( const uint2 & aValue )
{
 its8PIXEL1_Y = aValue;
}







}; // End of namespace Rtl16

#endif

