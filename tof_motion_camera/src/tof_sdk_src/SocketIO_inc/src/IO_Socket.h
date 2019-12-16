///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 1895 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++
// DESCRIPTION: The definitions for class Socket
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Dec  2 09:35:53 2007
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _IO_Socket_
#define _IO_Socket_

#ifdef USE_IDENT
#ident "$Header: $"
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>
#include "Common_UseLogger.h"

//------------------------------ Declarations --------------------------
//forward declare
struct sockaddr_in;

/// The namespace IO
namespace IO
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class Socket
   class Socket: public Common::UseLogger
   {
      public:

//   Use Default Copy Constructor
//   Use Default Assignment Operator

/// Default Constructor
         Socket( );

/// Special Constructor
         Socket(  const std::string & aName
            , const Common::UseLogger::LogLevel_e & aLogLevel
            , int aType
            , int aProtocol );                    //PF_INET domain sockets only

/// Destructor
         virtual ~Socket( );

/// Write content into buffer
         virtual bool WriteToBuffer( uint1 * buffer
            , uint2 aBufferSize
            , uint2 & aByteOffset ) const;
/// Read content from buffer
         virtual bool ReadFromBuffer( const uint1 * buffer
            , uint2 aBufferSize
            , uint2 & aByteOffset );

/// Write human readable representation of content
         virtual void Log( std::ostream & aStreamRef ) const;

/// Write human readable representation with indentation
         virtual void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

//  Arithmetic operators
/// Equal operator
         virtual bool operator == (const Socket & aRef) const;

/// Less operator
         virtual bool operator < (const Socket & aRef) const;

///@name Set and Get functions for all members
//@{
// The member Domain
///  The Get function for member Domain
         int   GetDomain( ) const;
///  The Set function for member Domain
         void    SetDomain( int aValue );
//----------------------------------------------------
// The member FD
///  The Get function for member FD
         int   GetFD( ) const;
///  The Set function for member FD
         void    SetFD( int aValue );
//----------------------------------------------------
// The member Protocol
///  The Get function for member Protocol
         int   GetProtocol( ) const;
///  The Set function for member Protocol
         void    SetProtocol( int aValue );
//----------------------------------------------------
// The member Type
///  The Get function for member Type
         int   GetType( ) const;
///  The Set function for member Type
         void    SetType( int aValue );
//----------------------------------------------------
// The member Name
///  The Get function for member Name
         std::string   GetName( ) const;
///  The Set function for member Name
         void    SetName( const std::string & aValue );
//----------------------------------------------------

///  The GetLocalPort function
         uint2   GetLocalPort( ) const;
///  The BindLocalPort function
         void  BindLocalPort( uint2 aValue ) const;
///  The Listen function
         bool Listen( uint2 aBacklog ) const;
///  The Connect function
         bool Connect( const std::string & aPeerAddress, uint2 aPeerPort ) const;
///  The Send function
         int Send( const void * aBuffer, uint4 aBufferLength, int theFlags = 0 ) const;
///  The Recv function
         int Recv( void * aBuffer, uint4 aBufferLength, int theFlags = 0 ) const;
///  The RecvFrom function
         int RecvFrom( void * aBuffer, uint4 aBufferLength, std::string & aPeerAddressRef, uint2 & aPeerPortRef, int theFlags = 0 ) const;
///  The Sendto function
         int Sendto( const std::string & aPeerAddress, uint2 aPeerPort, const void * aBuffer, uint4 aBufferLength, int theFlags = 0 ) const;
///  The SetBlockingMode function
         bool SetBlockingMode( const bool & aBlockingMode); 
///  The AddMembership function
         void AddMembership( const std::string & aMulticastAddress ) const;
///  The DropMembership function
         void DropMembership( const std::string & aMulticastAddress ) const;

//@}

      private:
//helper function
         bool SetHostByName(const std::string & anAddress, uint2 aPort, sockaddr_in & anAddressStructure) const;

//   All the Elements

         int itsDomain;
         int itsFD;
         std::string itsName;
         int itsProtocol;
         int itsType;

   };                                             // End of class Socket

//------------------------------ Inline Functions ----------------------
   inline bool Socket::operator == (const Socket & aRef) const
   {
      if ( itsDomain != aRef.itsDomain ) return false;
      if ( itsFD != aRef.itsFD ) return false;
      if ( itsName != aRef.itsName ) return false;
      if ( itsProtocol != aRef.itsProtocol ) return false;
      if ( itsType != aRef.itsType ) return false;

      return true;
   }

   inline bool Socket::operator < (const Socket & aRef) const
   {
      if ( itsDomain >= aRef.itsDomain ) return false;
      if ( itsFD >= aRef.itsFD ) return false;
      if ( itsName >= aRef.itsName ) return false;
      if ( itsProtocol >= aRef.itsProtocol ) return false;
      if ( itsType >= aRef.itsType ) return false;

      return true;                                //min 1 attribute in class
   }

   inline std::ostream & operator << ( std::ostream & aStreamRef, const Socket & aRef )
   {
      aRef . Log( aStreamRef );
      return aStreamRef;
   }

   inline int Socket::GetDomain( ) const
   {
      return itsDomain;
   }

   inline void Socket::SetDomain( int aValue )
   {
      itsDomain = aValue;
   }
   inline int Socket::GetFD( ) const
   {
      return itsFD;
   }

   inline void Socket::SetFD( int aValue )
   {
      itsFD = aValue;
   }

   inline std::string Socket::GetName( ) const
   {
      return itsName;
   }

   inline void Socket::SetName( const std::string & aValue )
   {
      itsName = aValue;
   }

   inline int Socket::GetProtocol( ) const
   {
      return itsProtocol;
   }

   inline void Socket::SetProtocol( int aValue )
   {
      itsProtocol = aValue;
   }
   inline int Socket::GetType( ) const
   {
      return itsType;
   }

   inline void Socket::SetType( int aValue )
   {
      itsType = aValue;
   }

};                                                // End of namespace IO
#endif
