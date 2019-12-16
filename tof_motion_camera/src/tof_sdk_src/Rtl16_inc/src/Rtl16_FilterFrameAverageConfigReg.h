///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- FilterFrameAverageConfigReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FilterFrameAverageConfigReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_FilterFrameAverageConfigReg_
#define _Rtl16_FilterFrameAverageConfigReg_

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

/// The definition of class FilterFrameAverageConfigReg
class FilterFrameAverageConfigReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        FilterFrameAverageConfigReg( );

   /// Special Constructor 
        FilterFrameAverageConfigReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~FilterFrameAverageConfigReg( );

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
       bool operator == (const FilterFrameAverageConfigReg & aRef) const;
   
   /// Less operator 
       bool operator < (const FilterFrameAverageConfigReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0NumberOfFrames
         ///  The Get function for member 0NumberOfFrames
              uint2   GetNumberOfFrames( ) const;
         ///  The Set function for member 0NumberOfFrames
              void    SetNumberOfFrames( const uint2 & aValue );
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
         uint2 its0NumberOfFrames: 4;

};
};

}; // End of class FilterFrameAverageConfigReg

//------------------------------ Inline Functions ----------------------
inline bool FilterFrameAverageConfigReg::operator == (const FilterFrameAverageConfigReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool FilterFrameAverageConfigReg::operator < (const FilterFrameAverageConfigReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FilterFrameAverageConfigReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 FilterFrameAverageConfigReg::GetAddr( ) const
{
 return its0Addr;
}

inline void FilterFrameAverageConfigReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 FilterFrameAverageConfigReg::GetNumberOfFrames( ) const
{
 return its0NumberOfFrames;
}

inline void FilterFrameAverageConfigReg::SetNumberOfFrames( const uint2 & aValue )
{
 its0NumberOfFrames = aValue;
}

inline uint2 FilterFrameAverageConfigReg::GetReg( ) const
{
 return its0Reg;
}

inline void FilterFrameAverageConfigReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}







}; // End of namespace Rtl16

#endif

