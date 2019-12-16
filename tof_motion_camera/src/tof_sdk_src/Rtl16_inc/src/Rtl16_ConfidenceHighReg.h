///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- ConfidenceHighReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class ConfidenceHighReg 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Tue Aug  1 09:27:43 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_ConfidenceHighReg_
#define _Rtl16_ConfidenceHighReg_

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>
#ifdef _TARGET_ARCH_W32_
//ROH: try without #define _WIN32_WINNT _WIN32_WINNT_WIN8
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

/// The definition of class ConfidenceHighReg
class ConfidenceHighReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        ConfidenceHighReg( );

   /// Destructor
        ~ConfidenceHighReg( );

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
       bool operator == (const ConfidenceHighReg & aRef) const;
   
   /// Less operator 
       bool operator < (const ConfidenceHighReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0AmplitudeThresHighWord
         ///  The Get function for member 0AmplitudeThresHighWord
              uint2   GetAmplitudeThresHighWord( ) const;
         ///  The Set function for member 0AmplitudeThresHighWord
              void    SetAmplitudeThresHighWord( const uint2 & aValue );
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
         uint2 its0AmplitudeThresHighWord: 16;

};
};

}; // End of class ConfidenceHighReg

//------------------------------ Inline Functions ----------------------
inline bool ConfidenceHighReg::operator == (const ConfidenceHighReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool ConfidenceHighReg::operator < (const ConfidenceHighReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const ConfidenceHighReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 ConfidenceHighReg::GetAddr( ) const
{
 return its0Addr;
}

inline void ConfidenceHighReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 ConfidenceHighReg::GetAmplitudeThresHighWord( ) const
{
 return its0AmplitudeThresHighWord;
}

inline void ConfidenceHighReg::SetAmplitudeThresHighWord( const uint2 & aValue )
{
 its0AmplitudeThresHighWord = aValue;
}

inline uint2 ConfidenceHighReg::GetReg( ) const
{
 return its0Reg;
}

inline void ConfidenceHighReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}






}; // End of namespace Rtl16

#endif

