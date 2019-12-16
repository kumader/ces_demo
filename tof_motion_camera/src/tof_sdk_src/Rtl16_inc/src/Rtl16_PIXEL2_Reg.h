///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- PIXEL2_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class PIXEL2_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_PIXEL2_Reg_
#define _Rtl16_PIXEL2_Reg_

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

/// The definition of class PIXEL2_Reg
class PIXEL2_Reg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        PIXEL2_Reg( );

   /// Special Constructor 
        PIXEL2_Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~PIXEL2_Reg( );

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
       bool operator == (const PIXEL2_Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const PIXEL2_Reg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0PIXEL2_X
         ///  The Get function for member 0PIXEL2_X
              uint2   GetPIXEL2_X( ) const;
         ///  The Set function for member 0PIXEL2_X
              void    SetPIXEL2_X( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );
         //----------------------------------------------------
         // The member 8PIXEL2_Y
         ///  The Get function for member 8PIXEL2_Y
              uint2   GetPIXEL2_Y( ) const;
         ///  The Set function for member 8PIXEL2_Y
              void    SetPIXEL2_Y( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0PIXEL2_X: 8;
         uint2 its8PIXEL2_Y: 8;

};
};

}; // End of class PIXEL2_Reg

//------------------------------ Inline Functions ----------------------
inline bool PIXEL2_Reg::operator == (const PIXEL2_Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool PIXEL2_Reg::operator < (const PIXEL2_Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const PIXEL2_Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 PIXEL2_Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void PIXEL2_Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 PIXEL2_Reg::GetPIXEL2_X( ) const
{
 return its0PIXEL2_X;
}

inline void PIXEL2_Reg::SetPIXEL2_X( const uint2 & aValue )
{
 its0PIXEL2_X = aValue;
}

inline uint2 PIXEL2_Reg::GetReg( ) const
{
 return its0Reg;
}

inline void PIXEL2_Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 PIXEL2_Reg::GetPIXEL2_Y( ) const
{
 return its8PIXEL2_Y;
}

inline void PIXEL2_Reg::SetPIXEL2_Y( const uint2 & aValue )
{
 its8PIXEL2_Y = aValue;
}







}; // End of namespace Rtl16

#endif

