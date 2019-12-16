///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- LedBoardTempReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class LedBoardTempReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_LedBoardTempReg_
#define _Rtl16_LedBoardTempReg_

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

/// The definition of class LedBoardTempReg
class LedBoardTempReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        LedBoardTempReg( );

   /// Special Constructor 
        LedBoardTempReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~LedBoardTempReg( );

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
       bool operator == (const LedBoardTempReg & aRef) const;
   
   /// Less operator 
       bool operator < (const LedBoardTempReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0LedBoardTemp_deg100
         ///  The Get function for member 0LedBoardTemp_deg100
              sint2   GetLedBoardTemp_deg100( ) const;
         ///  The Set function for member 0LedBoardTemp_deg100
              void    SetLedBoardTemp_deg100( const sint2 & aValue );
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
         sint2 its0LedBoardTemp_deg100: 16;

};
};

}; // End of class LedBoardTempReg

//------------------------------ Inline Functions ----------------------
inline bool LedBoardTempReg::operator == (const LedBoardTempReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool LedBoardTempReg::operator < (const LedBoardTempReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const LedBoardTempReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 LedBoardTempReg::GetAddr( ) const
{
 return its0Addr;
}

inline void LedBoardTempReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline sint2 LedBoardTempReg::GetLedBoardTemp_deg100( ) const
{
 return its0LedBoardTemp_deg100;
}

inline void LedBoardTempReg::SetLedBoardTemp_deg100( const sint2 & aValue )
{
 its0LedBoardTemp_deg100 = aValue;
}

inline uint2 LedBoardTempReg::GetReg( ) const
{
 return its0Reg;
}

inline void LedBoardTempReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}







}; // End of namespace Rtl16

#endif

