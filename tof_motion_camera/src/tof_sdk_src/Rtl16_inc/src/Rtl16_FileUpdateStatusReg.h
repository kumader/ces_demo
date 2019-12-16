///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- FileUpdateStatusReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FileUpdateStatusReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_FileUpdateStatusReg_
#define _Rtl16_FileUpdateStatusReg_

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

/// The definition of class FileUpdateStatusReg
class FileUpdateStatusReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        FileUpdateStatusReg( );

   /// Special Constructor 
        FileUpdateStatusReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~FileUpdateStatusReg( );

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
       bool operator == (const FileUpdateStatusReg & aRef) const;
   
   /// Less operator 
       bool operator < (const FileUpdateStatusReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0FileUpdateStatus
         ///  The Get function for member 0FileUpdateStatus
              uint2   GetFileUpdateStatus( ) const;
         ///  The Set function for member 0FileUpdateStatus
              void    SetFileUpdateStatus( const uint2 & aValue );
         ///  The ConvertToString function for member 0FileUpdateStatus
              std::string    ConvertToStringFileUpdateStatus( ) const;
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
         uint2 its0FileUpdateStatus: 16;

};
};

}; // End of class FileUpdateStatusReg

//------------------------------ Inline Functions ----------------------
inline bool FileUpdateStatusReg::operator == (const FileUpdateStatusReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool FileUpdateStatusReg::operator < (const FileUpdateStatusReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FileUpdateStatusReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 FileUpdateStatusReg::GetAddr( ) const
{
 return its0Addr;
}

inline void FileUpdateStatusReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 FileUpdateStatusReg::GetFileUpdateStatus( ) const
{
 return its0FileUpdateStatus;
}

inline void FileUpdateStatusReg::SetFileUpdateStatus( const uint2 & aValue )
{
 its0FileUpdateStatus = aValue;
}

inline uint2 FileUpdateStatusReg::GetReg( ) const
{
 return its0Reg;
}

inline void FileUpdateStatusReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}




inline std::string FileUpdateStatusReg::ConvertToStringFileUpdateStatus( ) const
{
 switch (its0FileUpdateStatus)
 {
 case 0: return "0:idle"; break;
 case 3: return "3:out_of_memory"; break;
 case 6: return "6:file crc error"; break;
 case 8: return "8:erasing flash"; break;
 case 9: return "9:flashing"; break;
 case 11: return "11:erasing failed"; break;
 case 12: return "12:flashing failed"; break;
 case 14: return "14:update success"; break;
 case 16: return "16:header version conflict"; break;
 case 18: return "18:wrong fw identifier"; break;
 case 20: return "20:data inconsistent"; break;
 case 21: return "21:in progress"; break;
 case 255: return "255:protocol violation"; break; 
 default: return "unknown value"; 
 }//switch
}





}; // End of namespace Rtl16

#endif

