///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- FirmwareInfoReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FirmwareInfoReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_FirmwareInfoReg_
#define _Rtl16_FirmwareInfoReg_

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

/// The definition of class FirmwareInfoReg
class FirmwareInfoReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        FirmwareInfoReg( );

   /// Special Constructor 
        FirmwareInfoReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~FirmwareInfoReg( );

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
       bool operator == (const FirmwareInfoReg & aRef) const;
   
   /// Less operator 
       bool operator < (const FirmwareInfoReg & aRef) const;

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
         // The member 0RevisionNonFunctional
         ///  The Get function for member 0RevisionNonFunctional
              uint2   GetRevisionNonFunctional( ) const;
         ///  The Set function for member 0RevisionNonFunctional
              void    SetRevisionNonFunctional( const uint2 & aValue );
         //----------------------------------------------------
         // The member 6RevisionMinor
         ///  The Get function for member 6RevisionMinor
              uint2   GetRevisionMinor( ) const;
         ///  The Set function for member 6RevisionMinor
              void    SetRevisionMinor( const uint2 & aValue );
         //----------------------------------------------------
         // The member 11RevisionMajor
         ///  The Get function for member 11RevisionMajor
              uint2   GetRevisionMajor( ) const;
         ///  The Set function for member 11RevisionMajor
              void    SetRevisionMajor( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0RevisionNonFunctional: 6;
         uint2 its6RevisionMinor: 5;
         uint2 its11RevisionMajor: 5;

};
};

}; // End of class FirmwareInfoReg

//------------------------------ Inline Functions ----------------------
inline bool FirmwareInfoReg::operator == (const FirmwareInfoReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool FirmwareInfoReg::operator < (const FirmwareInfoReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FirmwareInfoReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 FirmwareInfoReg::GetAddr( ) const
{
 return its0Addr;
}

inline void FirmwareInfoReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 FirmwareInfoReg::GetReg( ) const
{
 return its0Reg;
}

inline void FirmwareInfoReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 FirmwareInfoReg::GetRevisionNonFunctional( ) const
{
 return its0RevisionNonFunctional;
}

inline void FirmwareInfoReg::SetRevisionNonFunctional( const uint2 & aValue )
{
 its0RevisionNonFunctional = aValue;
}

inline uint2 FirmwareInfoReg::GetRevisionMinor( ) const
{
 return its6RevisionMinor;
}

inline void FirmwareInfoReg::SetRevisionMinor( const uint2 & aValue )
{
 its6RevisionMinor = aValue;
}

inline uint2 FirmwareInfoReg::GetRevisionMajor( ) const
{
 return its11RevisionMajor;
}

inline void FirmwareInfoReg::SetRevisionMajor( const uint2 & aValue )
{
 its11RevisionMajor = aValue;
}







}; // End of namespace Rtl16

#endif

