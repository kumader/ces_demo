///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- RealWorldXcoordinateReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class RealWorldXcoordinateReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_RealWorldXcoordinateReg_
#define _Rtl16_RealWorldXcoordinateReg_

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

/// The definition of class RealWorldXcoordinateReg
class RealWorldXcoordinateReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        RealWorldXcoordinateReg( );

   /// Special Constructor 
        RealWorldXcoordinateReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~RealWorldXcoordinateReg( );

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
       bool operator == (const RealWorldXcoordinateReg & aRef) const;
   
   /// Less operator 
       bool operator < (const RealWorldXcoordinateReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0DistanceToCalibrationTarget_mm
         ///  The Get function for member 0DistanceToCalibrationTarget_mm
              uint2   GetDistanceToCalibrationTarget_mm( ) const;
         ///  The Set function for member 0DistanceToCalibrationTarget_mm
              void    SetDistanceToCalibrationTarget_mm( const uint2 & aValue );
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
         uint2 its0DistanceToCalibrationTarget_mm: 16;

};
};

}; // End of class RealWorldXcoordinateReg

//------------------------------ Inline Functions ----------------------
inline bool RealWorldXcoordinateReg::operator == (const RealWorldXcoordinateReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool RealWorldXcoordinateReg::operator < (const RealWorldXcoordinateReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const RealWorldXcoordinateReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 RealWorldXcoordinateReg::GetAddr( ) const
{
 return its0Addr;
}

inline void RealWorldXcoordinateReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 RealWorldXcoordinateReg::GetDistanceToCalibrationTarget_mm( ) const
{
 return its0DistanceToCalibrationTarget_mm;
}

inline void RealWorldXcoordinateReg::SetDistanceToCalibrationTarget_mm( const uint2 & aValue )
{
 its0DistanceToCalibrationTarget_mm = aValue;
}

inline uint2 RealWorldXcoordinateReg::GetReg( ) const
{
 return its0Reg;
}

inline void RealWorldXcoordinateReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}







}; // End of namespace Rtl16

#endif

