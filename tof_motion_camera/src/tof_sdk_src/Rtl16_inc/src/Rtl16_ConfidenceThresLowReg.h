///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- ConfidenceThresLowReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class ConfidenceThresLowReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_ConfidenceThresLowReg_
#define _Rtl16_ConfidenceThresLowReg_

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

/// The definition of class ConfidenceThresLowReg
class ConfidenceThresLowReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        ConfidenceThresLowReg( );

   /// Special Constructor 
        ConfidenceThresLowReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~ConfidenceThresLowReg( );

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
       bool operator == (const ConfidenceThresLowReg & aRef) const;
   
   /// Less operator 
       bool operator < (const ConfidenceThresLowReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0AmplitudeThresLowWord
         ///  The Get function for member 0AmplitudeThresLowWord
              uint2   GetAmplitudeThresLowWord( ) const;
         ///  The Set function for member 0AmplitudeThresLowWord
              void    SetAmplitudeThresLowWord( const uint2 & aValue );
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
         uint2 its0AmplitudeThresLowWord: 16;

};
};

}; // End of class ConfidenceThresLowReg

//------------------------------ Inline Functions ----------------------
inline bool ConfidenceThresLowReg::operator == (const ConfidenceThresLowReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool ConfidenceThresLowReg::operator < (const ConfidenceThresLowReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const ConfidenceThresLowReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 ConfidenceThresLowReg::GetAddr( ) const
{
 return its0Addr;
}

inline void ConfidenceThresLowReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 ConfidenceThresLowReg::GetAmplitudeThresLowWord( ) const
{
 return its0AmplitudeThresLowWord;
}

inline void ConfidenceThresLowReg::SetAmplitudeThresLowWord( const uint2 & aValue )
{
 its0AmplitudeThresLowWord = aValue;
}

inline uint2 ConfidenceThresLowReg::GetReg( ) const
{
 return its0Reg;
}

inline void ConfidenceThresLowReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}







}; // End of namespace Rtl16

#endif

