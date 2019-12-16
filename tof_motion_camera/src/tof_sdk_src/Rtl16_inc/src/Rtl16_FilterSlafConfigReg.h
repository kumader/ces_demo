///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- FilterSlafConfigReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FilterSlafConfigReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_FilterSlafConfigReg_
#define _Rtl16_FilterSlafConfigReg_

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

/// The definition of class FilterSlafConfigReg
class FilterSlafConfigReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        FilterSlafConfigReg( );

   /// Special Constructor 
        FilterSlafConfigReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~FilterSlafConfigReg( );

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
       bool operator == (const FilterSlafConfigReg & aRef) const;
   
   /// Less operator 
       bool operator < (const FilterSlafConfigReg & aRef) const;

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
         // The member 0WindowSize
         ///  The Get function for member 0WindowSize
              uint2   GetWindowSize( ) const;
         ///  The Set function for member 0WindowSize
              void    SetWindowSize( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0WindowSize: 8;

};
};

}; // End of class FilterSlafConfigReg

//------------------------------ Inline Functions ----------------------
inline bool FilterSlafConfigReg::operator == (const FilterSlafConfigReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool FilterSlafConfigReg::operator < (const FilterSlafConfigReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FilterSlafConfigReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 FilterSlafConfigReg::GetAddr( ) const
{
 return its0Addr;
}

inline void FilterSlafConfigReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 FilterSlafConfigReg::GetReg( ) const
{
 return its0Reg;
}

inline void FilterSlafConfigReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 FilterSlafConfigReg::GetWindowSize( ) const
{
 return its0WindowSize;
}

inline void FilterSlafConfigReg::SetWindowSize( const uint2 & aValue )
{
 its0WindowSize = aValue;
}







}; // End of namespace Rtl16

#endif
