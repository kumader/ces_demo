///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- ImageDataFormatReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class ImageDataFormatReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_ImageDataFormatReg_
#define _Rtl16_ImageDataFormatReg_

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

/// The definition of class ImageDataFormatReg
class ImageDataFormatReg: public Virtual16BitReg
{
public:

   //enums

          enum ImageDataFormat_e
          {
          DISTAMP = 0
         , XYZ = 3
         , XYZA = 4
         , DISTXYZ = 9
         , OPTAXIS = 10
         , TESTMODE = 11
         , DIST = 12
         , RAWDISTAMP = 13
         , DISTAMPBAL = 23
         , RAWPHASES = 24 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        ImageDataFormatReg( );

   /// Special Constructor 
        ImageDataFormatReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~ImageDataFormatReg( );

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
       bool operator == (const ImageDataFormatReg & aRef) const;
   
   /// Less operator 
       bool operator < (const ImageDataFormatReg & aRef) const;

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
         // The member 3ImageDataFormat
         ///  The Get function for member 3ImageDataFormat
              uint2   GetImageDataFormat( ) const;
         ///  The Set function for member 3ImageDataFormat
              void    SetImageDataFormat( const uint2 & aValue );
         ///  The ConvertToString function for member 3ImageDataFormat
              std::string    ConvertToStringImageDataFormat( ) const;
         ///  The SetFromString function for member 3ImageDataFormat
              bool           SetFromStringImageDataFormat( const std::string & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0Reserved: 1;
         uint2 its1Reserved: 1;
         uint2 its2Reserved: 1;
         uint2 its3ImageDataFormat: 8;

};
};

}; // End of class ImageDataFormatReg

//------------------------------ Inline Functions ----------------------
inline bool ImageDataFormatReg::operator == (const ImageDataFormatReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool ImageDataFormatReg::operator < (const ImageDataFormatReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const ImageDataFormatReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 ImageDataFormatReg::GetAddr( ) const
{
 return its0Addr;
}

inline void ImageDataFormatReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 ImageDataFormatReg::GetReg( ) const
{
 return its0Reg;
}

inline void ImageDataFormatReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 ImageDataFormatReg::GetImageDataFormat( ) const
{
 return its3ImageDataFormat;
}

inline void ImageDataFormatReg::SetImageDataFormat( const uint2 & aValue )
{
 its3ImageDataFormat = aValue;
}




inline std::string ImageDataFormatReg::ConvertToStringImageDataFormat( ) const
{
 switch (its3ImageDataFormat)
 {
 case 0: return "0:distance and amplitude"; break;
 case 3: return "3:X/Y/Z coordinates"; break;
 case 4: return "4:X/Y/Z coordinates and amplitude"; break;
 case 9: return "9:distance and X/Y/Z coordinates"; break;
 case 10: return "10:optical axis coordinate and amplitude"; break;
 case 11: return "11:4 channels test mode"; break;
 case 12: return "12:distance"; break;
 case 13: return "13:raw distance and amplitude"; break;
 case 23: return "23:distance and amplitude and balance"; break;
 case 24: return "24:raw phases (1-8 channels)"; break; 
 default: return "unknown value"; 
 }//switch
}




inline bool ImageDataFormatReg::SetFromStringImageDataFormat( const std::string & aValue )
{
 if (0) { }
 else if (aValue ==  "DIST") { its3ImageDataFormat = 12; return true; }
 else if (aValue ==  "DISTAMP") { its3ImageDataFormat = 0; return true; }
 else if (aValue ==  "DISTAMPBAL") { its3ImageDataFormat = 23; return true; }
 else if (aValue ==  "DISTXYZ") { its3ImageDataFormat = 9; return true; }
 else if (aValue ==  "OPTAXIS") { its3ImageDataFormat = 10; return true; }
 else if (aValue ==  "RAWDISTAMP") { its3ImageDataFormat = 13; return true; }
 else if (aValue ==  "RAWPHASES") { its3ImageDataFormat = 24; return true; }
 else if (aValue ==  "TESTMODE") { its3ImageDataFormat = 11; return true; }
 else if (aValue ==  "XYZ") { its3ImageDataFormat = 3; return true; }
 else if (aValue ==  "XYZA") { its3ImageDataFormat = 4; return true; } 
 return false; 
}



}; // End of namespace Rtl16

#endif

