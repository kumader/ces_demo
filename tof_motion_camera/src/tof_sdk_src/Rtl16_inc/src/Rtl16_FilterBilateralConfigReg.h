///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- FilterBilateralConfigReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FilterBilateralConfigReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_FilterBilateralConfigReg_
#define _Rtl16_FilterBilateralConfigReg_

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

/// The definition of class FilterBilateralConfigReg
class FilterBilateralConfigReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        FilterBilateralConfigReg( );

   /// Special Constructor 
        FilterBilateralConfigReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~FilterBilateralConfigReg( );

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
       bool operator == (const FilterBilateralConfigReg & aRef) const;
   
   /// Less operator 
       bool operator < (const FilterBilateralConfigReg & aRef) const;

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
         // The member 0SigmaR
         ///  The Get function for member 0SigmaR
              uint2   GetSigmaR( ) const;
         ///  The Set function for member 0SigmaR
              void    SetSigmaR( const uint2 & aValue );
         //----------------------------------------------------
         // The member 6SigmaS
         ///  The Get function for member 6SigmaS
              uint2   GetSigmaS( ) const;
         ///  The Set function for member 6SigmaS
              void    SetSigmaS( const uint2 & aValue );
         //----------------------------------------------------
         // The member 12NoOfIterations
         ///  The Get function for member 12NoOfIterations
              uint2   GetNoOfIterations( ) const;
         ///  The Set function for member 12NoOfIterations
              void    SetNoOfIterations( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0SigmaR: 6;
         uint2 its6SigmaS: 6;
         uint2 its12NoOfIterations: 4;

};
};

}; // End of class FilterBilateralConfigReg

//------------------------------ Inline Functions ----------------------
inline bool FilterBilateralConfigReg::operator == (const FilterBilateralConfigReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool FilterBilateralConfigReg::operator < (const FilterBilateralConfigReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FilterBilateralConfigReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 FilterBilateralConfigReg::GetAddr( ) const
{
 return its0Addr;
}

inline void FilterBilateralConfigReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 FilterBilateralConfigReg::GetReg( ) const
{
 return its0Reg;
}

inline void FilterBilateralConfigReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 FilterBilateralConfigReg::GetSigmaR( ) const
{
 return its0SigmaR;
}

inline void FilterBilateralConfigReg::SetSigmaR( const uint2 & aValue )
{
 its0SigmaR = aValue;
}

inline uint2 FilterBilateralConfigReg::GetSigmaS( ) const
{
 return its6SigmaS;
}

inline void FilterBilateralConfigReg::SetSigmaS( const uint2 & aValue )
{
 its6SigmaS = aValue;
}

inline uint2 FilterBilateralConfigReg::GetNoOfIterations( ) const
{
 return its12NoOfIterations;
}

inline void FilterBilateralConfigReg::SetNoOfIterations( const uint2 & aValue )
{
 its12NoOfIterations = aValue;
}







}; // End of namespace Rtl16

#endif

