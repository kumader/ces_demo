///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- TcpControlInterfaceHeaderV3_RegisterRead
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class TcpControlInterfaceHeaderV3_RegisterRead 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Fri Feb  9 17:10:45 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _TcpFrame_TcpControlInterfaceHeaderV3_RegisterRead_
#define _TcpFrame_TcpControlInterfaceHeaderV3_RegisterRead_

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

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace TcpFrame
namespace TcpFrame
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class TcpControlInterfaceHeaderV3_RegisterRead
class TcpControlInterfaceHeaderV3_RegisterRead
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        TcpControlInterfaceHeaderV3_RegisterRead( );

   /// Destructor
        ~TcpControlInterfaceHeaderV3_RegisterRead( );

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
       bool operator == (const TcpControlInterfaceHeaderV3_RegisterRead & aRef) const;
   
   /// Less operator 
       bool operator < (const TcpControlInterfaceHeaderV3_RegisterRead & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         // The member 5Status
         ///  The Get function for member 5Status
              uint1   Get5Status( ) const;
         ///  The Set function for member 5Status
              void    Set5Status( const uint1 & aValue );
         //----------------------------------------------------
         // The member 6Flags
         ///  The Get function for member 6Flags
              uint2   Get6Flags( ) const;
         ///  The Set function for member 6Flags
              void    Set6Flags( const uint2 & aValue );
         //----------------------------------------------------
         //----------------------------------------------------
         // The member 12RegisterAddress
         ///  The Get function for member 12RegisterAddress
              uint2   Get12RegisterAddress( ) const;
         ///  The Set function for member 12RegisterAddress
              void    Set12RegisterAddress( const uint2 & aValue );
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         //----------------------------------------------------
         // The member 58DataCrc32
         ///  The Get function for member 58DataCrc32
              uint4   Get58DataCrc32( ) const;
         ///  The Set function for member 58DataCrc32
              void    Set58DataCrc32( const uint4 & aValue );
         //----------------------------------------------------
         // The member 62HeaderCrc16
         ///  The Get function for member 62HeaderCrc16
              uint2   Get62HeaderCrc16( ) const;
         ///  The Set function for member 62HeaderCrc16
              void    Set62HeaderCrc16( const uint2 & aValue );
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         uint2 its0Preamble;
         uint1 its2ProtocolVersion;
         uint1 its3Command;
         uint1 its4SubCommand;
         uint1 its5Status;
         uint2 its6Flags;
         uint4 its8Length;
         uint2 its12RegisterAddress;
         uint1 its14HeaderData2;
         uint1 its15HeaderData3;
         uint1 its16CallbackIpVersion;
         uint1 its17Reserved;
         uint2 its18Reserved;
         uint4 its20Reserved;
         uint4 its24Reserved;
         uint4 its28Reserved;
         uint4 its32Reserved;
         uint4 its36Reserved;
         uint4 its40Reserved;
         uint4 its44Reserved;
         uint4 its48Reserved;
         uint4 its52Reserved;
         uint2 its56Reserved;
         uint4 its58DataCrc32;
         uint2 its62HeaderCrc16;


}; // End of class TcpControlInterfaceHeaderV3_RegisterRead

//------------------------------ Inline Functions ----------------------
inline bool TcpControlInterfaceHeaderV3_RegisterRead::operator == (const TcpControlInterfaceHeaderV3_RegisterRead & aRef) const
{
   if ( ! (its0Preamble == aRef.its0Preamble) ) return false;
   if ( ! (its2ProtocolVersion == aRef.its2ProtocolVersion) ) return false;
   if ( ! (its3Command == aRef.its3Command) ) return false;
   if ( ! (its4SubCommand == aRef.its4SubCommand) ) return false;
   if ( ! (its5Status == aRef.its5Status) ) return false;
   if ( ! (its6Flags == aRef.its6Flags) ) return false;
   if ( ! (its8Length == aRef.its8Length) ) return false;
   if ( ! (its12RegisterAddress == aRef.its12RegisterAddress) ) return false;
   if ( ! (its14HeaderData2 == aRef.its14HeaderData2) ) return false;
   if ( ! (its15HeaderData3 == aRef.its15HeaderData3) ) return false;
   if ( ! (its16CallbackIpVersion == aRef.its16CallbackIpVersion) ) return false;
   if ( ! (its17Reserved == aRef.its17Reserved) ) return false;
   if ( ! (its18Reserved == aRef.its18Reserved) ) return false;
   if ( ! (its20Reserved == aRef.its20Reserved) ) return false;
   if ( ! (its24Reserved == aRef.its24Reserved) ) return false;
   if ( ! (its28Reserved == aRef.its28Reserved) ) return false;
   if ( ! (its32Reserved == aRef.its32Reserved) ) return false;
   if ( ! (its36Reserved == aRef.its36Reserved) ) return false;
   if ( ! (its40Reserved == aRef.its40Reserved) ) return false;
   if ( ! (its44Reserved == aRef.its44Reserved) ) return false;
   if ( ! (its48Reserved == aRef.its48Reserved) ) return false;
   if ( ! (its52Reserved == aRef.its52Reserved) ) return false;
   if ( ! (its56Reserved == aRef.its56Reserved) ) return false;
   if ( ! (its58DataCrc32 == aRef.its58DataCrc32) ) return false;
   if ( ! (its62HeaderCrc16 == aRef.its62HeaderCrc16) ) return false;

   return true;
}

inline bool TcpControlInterfaceHeaderV3_RegisterRead::operator < (const TcpControlInterfaceHeaderV3_RegisterRead & aRef) const
{
   if ( ! (its0Preamble < aRef.its0Preamble) ) return false;
   if ( ! (its2ProtocolVersion < aRef.its2ProtocolVersion) ) return false;
   if ( ! (its3Command < aRef.its3Command) ) return false;
   if ( ! (its4SubCommand < aRef.its4SubCommand) ) return false;
   if ( ! (its5Status < aRef.its5Status) ) return false;
   if ( ! (its6Flags < aRef.its6Flags) ) return false;
   if ( ! (its8Length < aRef.its8Length) ) return false;
   if ( ! (its12RegisterAddress < aRef.its12RegisterAddress) ) return false;
   if ( ! (its14HeaderData2 < aRef.its14HeaderData2) ) return false;
   if ( ! (its15HeaderData3 < aRef.its15HeaderData3) ) return false;
   if ( ! (its16CallbackIpVersion < aRef.its16CallbackIpVersion) ) return false;
   if ( ! (its17Reserved < aRef.its17Reserved) ) return false;
   if ( ! (its18Reserved < aRef.its18Reserved) ) return false;
   if ( ! (its20Reserved < aRef.its20Reserved) ) return false;
   if ( ! (its24Reserved < aRef.its24Reserved) ) return false;
   if ( ! (its28Reserved < aRef.its28Reserved) ) return false;
   if ( ! (its32Reserved < aRef.its32Reserved) ) return false;
   if ( ! (its36Reserved < aRef.its36Reserved) ) return false;
   if ( ! (its40Reserved < aRef.its40Reserved) ) return false;
   if ( ! (its44Reserved < aRef.its44Reserved) ) return false;
   if ( ! (its48Reserved < aRef.its48Reserved) ) return false;
   if ( ! (its52Reserved < aRef.its52Reserved) ) return false;
   if ( ! (its56Reserved < aRef.its56Reserved) ) return false;
   if ( ! (its58DataCrc32 < aRef.its58DataCrc32) ) return false;
   if ( ! (its62HeaderCrc16 < aRef.its62HeaderCrc16) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const TcpControlInterfaceHeaderV3_RegisterRead & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint1 TcpControlInterfaceHeaderV3_RegisterRead::Get5Status( ) const
{
 return its5Status;
}

inline void TcpControlInterfaceHeaderV3_RegisterRead::Set5Status( const uint1 & aValue )
{
 its5Status = aValue;
}

inline uint2 TcpControlInterfaceHeaderV3_RegisterRead::Get6Flags( ) const
{
 return its6Flags;
}

inline void TcpControlInterfaceHeaderV3_RegisterRead::Set6Flags( const uint2 & aValue )
{
 its6Flags = aValue;
}

inline uint2 TcpControlInterfaceHeaderV3_RegisterRead::Get12RegisterAddress( ) const
{
 return its12RegisterAddress;
}

inline void TcpControlInterfaceHeaderV3_RegisterRead::Set12RegisterAddress( const uint2 & aValue )
{
 its12RegisterAddress = aValue;
}

inline uint4 TcpControlInterfaceHeaderV3_RegisterRead::Get58DataCrc32( ) const
{
 return its58DataCrc32;
}

inline void TcpControlInterfaceHeaderV3_RegisterRead::Set58DataCrc32( const uint4 & aValue )
{
 its58DataCrc32 = aValue;
}

inline uint2 TcpControlInterfaceHeaderV3_RegisterRead::Get62HeaderCrc16( ) const
{
 return its62HeaderCrc16;
}

inline void TcpControlInterfaceHeaderV3_RegisterRead::Set62HeaderCrc16( const uint2 & aValue )
{
 its62HeaderCrc16 = aValue;
}






}; // End of namespace TcpFrame

#endif

