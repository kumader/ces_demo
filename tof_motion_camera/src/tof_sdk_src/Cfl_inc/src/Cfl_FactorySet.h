///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- FactorySet
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FactorySet 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Sep  2 10:14:10 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Cfl_FactorySet_
#define _Cfl_FactorySet_

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

/// The namespace Cfl
namespace Cfl
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class FactorySet
class FactorySet
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        FactorySet( );

   /// Destructor
        ~FactorySet( );

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
       bool operator == (const FactorySet & aRef) const;
   
   /// Less operator 
       bool operator < (const FactorySet & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         // The member FactoryBuildInfo
         ///  The Get function for member FactoryBuildInfo
              std::string   GetFactoryBuildInfo( ) const;
         ///  The Set function for member FactoryBuildInfo
              void    SetFactoryBuildInfo( const std::string & aValue );
         //----------------------------------------------------
         // The member FactoryMacAddress
         ///  The Get function for member FactoryMacAddress
              std::string   GetFactoryMacAddress( ) const;
         ///  The Set function for member FactoryMacAddress
              void    SetFactoryMacAddress( const std::string & aValue );
         //----------------------------------------------------
         // The member FirmwareBuildInfo
         ///  The Get function for member FirmwareBuildInfo
              std::string   GetFirmwareBuildInfo( ) const;
         ///  The Set function for member FirmwareBuildInfo
              void    SetFirmwareBuildInfo( const std::string & aValue );
         //----------------------------------------------------
         // The member FirmwareLoadCounter
         ///  The Get function for member FirmwareLoadCounter
              uint2   GetFirmwareLoadCounter( ) const;
         ///  The Set function for member FirmwareLoadCounter
              void    SetFirmwareLoadCounter( const uint2 & aValue );
         //----------------------------------------------------
         // The member FirmwareRevisionInfo
         ///  The Get function for member FirmwareRevisionInfo
              std::string   GetFirmwareRevisionInfo( ) const;
         ///  The Set function for member FirmwareRevisionInfo
              void    SetFirmwareRevisionInfo( const std::string & aValue );
         //----------------------------------------------------
         // The member HardwareSpecificIdentification
         ///  The Get function for member HardwareSpecificIdentification
              uint2   GetHardwareSpecificIdentification( ) const;
         ///  The Set function for member HardwareSpecificIdentification
              void    SetHardwareSpecificIdentification( const uint2 & aValue );
         //----------------------------------------------------
         // The member SerialNumber
         ///  The Get function for member SerialNumber
              uint4   GetSerialNumber( ) const;
         ///  The Set function for member SerialNumber
              void    SetSerialNumber( const uint4 & aValue );
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         std::string itsFactoryBuildInfo;
         std::string itsFactoryMacAddress;
         std::string itsFirmwareBuildInfo;
         uint2 itsFirmwareLoadCounter;
         std::string itsFirmwareRevisionInfo;
         uint2 itsHardwareSpecificIdentification;
         uint4 itsSerialNumber;


}; // End of class FactorySet

//------------------------------ Inline Functions ----------------------
inline bool FactorySet::operator == (const FactorySet & aRef) const
{
   if ( ! (itsFactoryBuildInfo == aRef.itsFactoryBuildInfo) ) return false;
   if ( ! (itsFactoryMacAddress == aRef.itsFactoryMacAddress) ) return false;
   if ( ! (itsFirmwareBuildInfo == aRef.itsFirmwareBuildInfo) ) return false;
   if ( ! (itsFirmwareLoadCounter == aRef.itsFirmwareLoadCounter) ) return false;
   if ( ! (itsFirmwareRevisionInfo == aRef.itsFirmwareRevisionInfo) ) return false;
   if ( ! (itsHardwareSpecificIdentification == aRef.itsHardwareSpecificIdentification) ) return false;
   if ( ! (itsSerialNumber == aRef.itsSerialNumber) ) return false;

   return true;
}

inline bool FactorySet::operator < (const FactorySet & aRef) const
{
   if ( ! (itsFactoryBuildInfo < aRef.itsFactoryBuildInfo) ) return false;
   if ( ! (itsFactoryMacAddress < aRef.itsFactoryMacAddress) ) return false;
   if ( ! (itsFirmwareBuildInfo < aRef.itsFirmwareBuildInfo) ) return false;
   if ( ! (itsFirmwareLoadCounter < aRef.itsFirmwareLoadCounter) ) return false;
   if ( ! (itsFirmwareRevisionInfo < aRef.itsFirmwareRevisionInfo) ) return false;
   if ( ! (itsHardwareSpecificIdentification < aRef.itsHardwareSpecificIdentification) ) return false;
   if ( ! (itsSerialNumber < aRef.itsSerialNumber) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FactorySet & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline std::string FactorySet::GetFactoryBuildInfo( ) const
{
 return itsFactoryBuildInfo;
}

inline void FactorySet::SetFactoryBuildInfo( const std::string & aValue )
{
 itsFactoryBuildInfo = aValue;
}

inline std::string FactorySet::GetFactoryMacAddress( ) const
{
 return itsFactoryMacAddress;
}

inline void FactorySet::SetFactoryMacAddress( const std::string & aValue )
{
 itsFactoryMacAddress = aValue;
}

inline std::string FactorySet::GetFirmwareBuildInfo( ) const
{
 return itsFirmwareBuildInfo;
}

inline void FactorySet::SetFirmwareBuildInfo( const std::string & aValue )
{
 itsFirmwareBuildInfo = aValue;
}

inline uint2 FactorySet::GetFirmwareLoadCounter( ) const
{
 return itsFirmwareLoadCounter;
}

inline void FactorySet::SetFirmwareLoadCounter( const uint2 & aValue )
{
 itsFirmwareLoadCounter = aValue;
}

inline std::string FactorySet::GetFirmwareRevisionInfo( ) const
{
 return itsFirmwareRevisionInfo;
}

inline void FactorySet::SetFirmwareRevisionInfo( const std::string & aValue )
{
 itsFirmwareRevisionInfo = aValue;
}

inline uint2 FactorySet::GetHardwareSpecificIdentification( ) const
{
 return itsHardwareSpecificIdentification;
}

inline void FactorySet::SetHardwareSpecificIdentification( const uint2 & aValue )
{
 itsHardwareSpecificIdentification = aValue;
}

inline uint4 FactorySet::GetSerialNumber( ) const
{
 return itsSerialNumber;
}

inline void FactorySet::SetSerialNumber( const uint4 & aValue )
{
 itsSerialNumber = aValue;
}






}; // End of namespace Cfl

#endif

