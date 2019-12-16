///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4153 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class ConfigurationSet 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Aug 14 20:54:53 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Cfl_ConfigurationSet_
#define _Cfl_ConfigurationSet_

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

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace Cfl
namespace Cfl
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class ConfigurationSet
class ConfigurationSet
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
        ConfigurationSet( );

   /// Destructor
        ~ConfigurationSet( );

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
       bool operator == (const ConfigurationSet & aRef) const;
   
   /// Less operator 
       bool operator < (const ConfigurationSet & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         // The member EnableDHCPFlag
         ///  The Get function for member EnableDHCPFlag
              bool   GetEnableDHCPFlag( ) const;
         ///  The Set function for member EnableDHCPFlag
              void    SetEnableDHCPFlag( const bool & aValue );
         //----------------------------------------------------
         // The member EnableUdpStreamingFlag
         ///  The Get function for member EnableUdpStreamingFlag
              bool   GetEnableUdpStreamingFlag( ) const;
         ///  The Set function for member EnableUdpStreamingFlag
              void    SetEnableUdpStreamingFlag( const bool & aValue );
         //----------------------------------------------------
         // The member Gateway
         ///  The Get function for member Gateway
              std::string   GetGateway( ) const;
         ///  The Set function for member Gateway
              void    SetGateway( const std::string & aValue );
         //----------------------------------------------------
         // The member IgnoreCrcForUdpStreamingFlag
         ///  The Get function for member IgnoreCrcForUdpStreamingFlag
              bool   GetIgnoreCrcForUdpStreamingFlag( ) const;
         ///  The Set function for member IgnoreCrcForUdpStreamingFlag
              void    SetIgnoreCrcForUdpStreamingFlag( const bool & aValue );
         //----------------------------------------------------
         // The member ImageDataFormat
         ///  The Get function for member ImageDataFormat
              uint2   GetImageDataFormat( ) const;
         ///  The Set function for member ImageDataFormat
              void    SetImageDataFormat( const uint2 & aValue );
         ///  The ConvertToString function for member ImageDataFormat
              std::string    ConvertToStringImageDataFormat( const uint2 & aValue ) const;
         //----------------------------------------------------
         // The member IpAddress
         ///  The Get function for member IpAddress
              std::string   GetIpAddress( ) const;
         ///  The Set function for member IpAddress
              void    SetIpAddress( const std::string & aValue );
         //----------------------------------------------------
         // The member IsInManualTrigger
         ///  The Get function for member IsInManualTrigger
              bool   GetIsInManualTrigger( ) const;
         ///  The Set function for member IsInManualTrigger
              void    SetIsInManualTrigger( const bool & aValue );
         //----------------------------------------------------
         // The member LensOpeningAngleIdentifier
         ///  The Get function for member LensOpeningAngleIdentifier
              uint2   GetLensOpeningAngleIdentifier( ) const;
         ///  The Set function for member LensOpeningAngleIdentifier
              void    SetLensOpeningAngleIdentifier( const uint2 & aValue );
         //----------------------------------------------------
         // The member Netmask
         ///  The Get function for member Netmask
              std::string   GetNetmask( ) const;
         ///  The Set function for member Netmask
              void    SetNetmask( const std::string & aValue );
         //----------------------------------------------------
         // The member TcpCtrlPort
         ///  The Get function for member TcpCtrlPort
              uint2   GetTcpCtrlPort( ) const;
         ///  The Set function for member TcpCtrlPort
              void    SetTcpCtrlPort( const uint2 & aValue );
         //----------------------------------------------------
         // The member UdpStreamAddress
         ///  The Get function for member UdpStreamAddress
              std::string   GetUdpStreamAddress( ) const;
         ///  The Set function for member UdpStreamAddress
              void    SetUdpStreamAddress( const std::string & aValue );
         //----------------------------------------------------
         // The member UdpStreamPort
         ///  The Get function for member UdpStreamPort
              uint2   GetUdpStreamPort( ) const;
         ///  The Set function for member UdpStreamPort
              void    SetUdpStreamPort( const uint2 & aValue );
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         bool itsEnableDHCPFlag;
         bool itsEnableUdpStreamingFlag;
         std::string itsGateway;
         bool itsIgnoreCrcForUdpStreamingFlag;
         uint2 itsImageDataFormat;
         std::string itsIpAddress;
         bool itsIsInManualTrigger;
         uint2 itsLensOpeningAngleIdentifier;
         std::string itsNetmask;
         uint2 itsTcpCtrlPort;
         std::string itsUdpStreamAddress;
         uint2 itsUdpStreamPort;


}; // End of class ConfigurationSet

//------------------------------ Inline Functions ----------------------
inline bool ConfigurationSet::operator == (const ConfigurationSet & aRef) const
{
   if ( ! (itsEnableDHCPFlag == aRef.itsEnableDHCPFlag) ) return false;
   if ( ! (itsEnableUdpStreamingFlag == aRef.itsEnableUdpStreamingFlag) ) return false;
   if ( ! (itsGateway == aRef.itsGateway) ) return false;
   if ( ! (itsIgnoreCrcForUdpStreamingFlag == aRef.itsIgnoreCrcForUdpStreamingFlag) ) return false;
   if ( ! (itsImageDataFormat == aRef.itsImageDataFormat) ) return false;
   if ( ! (itsIpAddress == aRef.itsIpAddress) ) return false;
   if ( ! (itsIsInManualTrigger == aRef.itsIsInManualTrigger) ) return false;
   if ( ! (itsLensOpeningAngleIdentifier == aRef.itsLensOpeningAngleIdentifier) ) return false;
   if ( ! (itsNetmask == aRef.itsNetmask) ) return false;
   if ( ! (itsTcpCtrlPort == aRef.itsTcpCtrlPort) ) return false;
   if ( ! (itsUdpStreamAddress == aRef.itsUdpStreamAddress) ) return false;
   if ( ! (itsUdpStreamPort == aRef.itsUdpStreamPort) ) return false;

   return true;
}

inline bool ConfigurationSet::operator < (const ConfigurationSet & aRef) const
{
   if ( ! (itsEnableDHCPFlag < aRef.itsEnableDHCPFlag) ) return false;
   if ( ! (itsEnableUdpStreamingFlag < aRef.itsEnableUdpStreamingFlag) ) return false;
   if ( ! (itsGateway < aRef.itsGateway) ) return false;
   if ( ! (itsIgnoreCrcForUdpStreamingFlag < aRef.itsIgnoreCrcForUdpStreamingFlag) ) return false;
   if ( ! (itsImageDataFormat < aRef.itsImageDataFormat) ) return false;
   if ( ! (itsIpAddress < aRef.itsIpAddress) ) return false;
   if ( ! (itsIsInManualTrigger < aRef.itsIsInManualTrigger) ) return false;
   if ( ! (itsLensOpeningAngleIdentifier < aRef.itsLensOpeningAngleIdentifier) ) return false;
   if ( ! (itsNetmask < aRef.itsNetmask) ) return false;
   if ( ! (itsTcpCtrlPort < aRef.itsTcpCtrlPort) ) return false;
   if ( ! (itsUdpStreamAddress < aRef.itsUdpStreamAddress) ) return false;
   if ( ! (itsUdpStreamPort < aRef.itsUdpStreamPort) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const ConfigurationSet & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline bool ConfigurationSet::GetEnableDHCPFlag( ) const
{
 return itsEnableDHCPFlag;
}

inline void ConfigurationSet::SetEnableDHCPFlag( const bool & aValue )
{
 itsEnableDHCPFlag = aValue;
}

inline bool ConfigurationSet::GetEnableUdpStreamingFlag( ) const
{
 return itsEnableUdpStreamingFlag;
}

inline void ConfigurationSet::SetEnableUdpStreamingFlag( const bool & aValue )
{
 itsEnableUdpStreamingFlag = aValue;
}

inline std::string ConfigurationSet::GetGateway( ) const
{
 return itsGateway;
}

inline void ConfigurationSet::SetGateway( const std::string & aValue )
{
 itsGateway = aValue;
}

inline bool ConfigurationSet::GetIgnoreCrcForUdpStreamingFlag( ) const
{
 return itsIgnoreCrcForUdpStreamingFlag;
}

inline void ConfigurationSet::SetIgnoreCrcForUdpStreamingFlag( const bool & aValue )
{
 itsIgnoreCrcForUdpStreamingFlag = aValue;
}

inline uint2 ConfigurationSet::GetImageDataFormat( ) const
{
 return itsImageDataFormat;
}

inline void ConfigurationSet::SetImageDataFormat( const uint2 & aValue )
{
 itsImageDataFormat = aValue;
}

inline std::string ConfigurationSet::GetIpAddress( ) const
{
 return itsIpAddress;
}

inline void ConfigurationSet::SetIpAddress( const std::string & aValue )
{
 itsIpAddress = aValue;
}

inline bool ConfigurationSet::GetIsInManualTrigger( ) const
{
 return itsIsInManualTrigger;
}

inline void ConfigurationSet::SetIsInManualTrigger( const bool & aValue )
{
 itsIsInManualTrigger = aValue;
}

inline uint2 ConfigurationSet::GetLensOpeningAngleIdentifier( ) const
{
 return itsLensOpeningAngleIdentifier;
}

inline void ConfigurationSet::SetLensOpeningAngleIdentifier( const uint2 & aValue )
{
 itsLensOpeningAngleIdentifier = aValue;
}

inline std::string ConfigurationSet::GetNetmask( ) const
{
 return itsNetmask;
}

inline void ConfigurationSet::SetNetmask( const std::string & aValue )
{
 itsNetmask = aValue;
}

inline uint2 ConfigurationSet::GetTcpCtrlPort( ) const
{
 return itsTcpCtrlPort;
}

inline void ConfigurationSet::SetTcpCtrlPort( const uint2 & aValue )
{
 itsTcpCtrlPort = aValue;
}

inline std::string ConfigurationSet::GetUdpStreamAddress( ) const
{
 return itsUdpStreamAddress;
}

inline void ConfigurationSet::SetUdpStreamAddress( const std::string & aValue )
{
 itsUdpStreamAddress = aValue;
}

inline uint2 ConfigurationSet::GetUdpStreamPort( ) const
{
 return itsUdpStreamPort;
}

inline void ConfigurationSet::SetUdpStreamPort( const uint2 & aValue )
{
 itsUdpStreamPort = aValue;
}




inline std::string ConfigurationSet::ConvertToStringImageDataFormat( const uint2 & aValue ) const
{
 switch (aValue)
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




}; // End of namespace Cfl

#endif

