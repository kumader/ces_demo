///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 1895 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++
// DESCRIPTION: The implementation for class Socket
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Dec  2 09:35:53 2007
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $"
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "IO_Socket.h"
#include "Common_LogFormat.h"

#ifdef _TARGET_ARCH_W32_
//ROH: try without #define _WIN32_WINNT _WIN32_WINNT_WIN8 // Windows 8.0
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>


#else
//const char* inet_ntop(int af, const void* src, char* dst, int cnt);
#include <sys/socket.h>
#include <netinet/in.h>                           //address structures
#include <netdb.h>                                //hostent
#include <arpa/inet.h>                            //inet_ functions
#endif

#include <sys/types.h>                            //data types
#include <sstream>                                //ostringstream
#include <errno.h>                                //errno
#include <string.h>                               //memset
#include <fcntl.h>                                //fcntl 


//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace IO;

//------------------------------ Constructor -------------------

Socket::Socket ( )
: Common::UseLogger (  )
, itsDomain ( -92 )
, itsFD ( -91 )
, itsName ( "" )
, itsProtocol ( -94 )
, itsType ( -93 )

{
/// nothing
}


Socket::Socket (const string & aName, const LogLevel_e & aLogLevel, int aType, int aProtocol  )
: Common::UseLogger ( 0, aLogLevel, aName )
, itsDomain ( PF_INET )
, itsFD ( -1 )
, itsName ( aName )
, itsProtocol ( aProtocol )
, itsType ( aType )
{

   itsFD = socket ( itsDomain, itsType, itsProtocol);
   LOG_ASSERT(itsFD >= 0, "Socket: socket creation failed with error " << errno << ":"<<strerror(errno) );

}


//------------------------------ Destructor ----------------------------

Socket::~Socket (  )
{
///nothing
//NOTE: close socket FD explicitely !
}


//------------------------------ Pickling ------------------------------

bool Socket::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{
   if( aByteOffset + sizeof(int) > aBufferSize ) return false;
   int * pTmpDomain = reinterpret_cast< int * > ( buffer + aByteOffset );
   *pTmpDomain = itsDomain;
   aByteOffset += sizeof(int);
   if( aByteOffset + sizeof(int) > aBufferSize ) return false;
   int * pTmpFD = reinterpret_cast< int * > ( buffer + aByteOffset );
   *pTmpFD = itsFD;
   aByteOffset += sizeof(int);
   if( aByteOffset + sizeof(int) > aBufferSize ) return false;
   int * pTmpProtocol = reinterpret_cast< int * > ( buffer + aByteOffset );
   *pTmpProtocol = itsProtocol;
   aByteOffset += sizeof(int);
   if( aByteOffset + sizeof(int) > aBufferSize ) return false;
   int * pTmpType = reinterpret_cast< int * > ( buffer + aByteOffset );
   *pTmpType = itsType;
   aByteOffset += sizeof(int);

   return true;
}


bool Socket::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{
   if( aByteOffset + sizeof(int) > aBufferSize ) return false;
   const int * pTmpDomain = reinterpret_cast< const int * > ( buffer + aByteOffset );
   itsDomain = *pTmpDomain;
   aByteOffset += sizeof(int);
   if( aByteOffset + sizeof(int) > aBufferSize ) return false;
   const int * pTmpFD = reinterpret_cast< const int * > ( buffer + aByteOffset );
   itsFD = *pTmpFD;
   aByteOffset += sizeof(int);
   if( aByteOffset + sizeof(int) > aBufferSize ) return false;
   const int * pTmpProtocol = reinterpret_cast< const int * > ( buffer + aByteOffset );
   itsProtocol = *pTmpProtocol;
   aByteOffset += sizeof(int);
   if( aByteOffset + sizeof(int) > aBufferSize ) return false;
   const int * pTmpType = reinterpret_cast< const int * > ( buffer + aByteOffset );
   itsType = *pTmpType;
   aByteOffset += sizeof(int);

   return true;
}


uint2 Socket::GetLocalPort( ) const
{
   sockaddr_in tmpAddress;                        //address structure
                                                  //address size
   socklen_t  tmpAddress_length = sizeof(tmpAddress);

   int return_value = getsockname(itsFD, (sockaddr *) &tmpAddress, &tmpAddress_length);
   LOG_ASSERT(return_value >= 0, "GetLocalPort: getsockname failed with error " << errno << ":"<<strerror(errno) );

   return ntohs(tmpAddress.sin_port);
}


void Socket::BindLocalPort( uint2 aValue ) const
{
   sockaddr_in tmpAddress;                        //address structure
                                                  //address size
   socklen_t  tmpAddress_length = sizeof(tmpAddress);
   memset (&tmpAddress, 0, sizeof(tmpAddress));   //clear structure
   tmpAddress.sin_family = AF_INET;               //address type
   tmpAddress.sin_addr.s_addr = htonl(INADDR_ANY);//any client address
   tmpAddress.sin_port = htons(aValue);           //port

   int return_value = bind(itsFD, (sockaddr *) &tmpAddress, tmpAddress_length);
   LOG_ASSERT(return_value >= 0, "SetLocalPort: bind failed with error " << errno << ":"<<strerror(errno) );
}


//for bind sockets only !
bool Socket::Listen( uint2 aBacklog ) const
{

   int return_value = listen(itsFD, aBacklog);
   if (return_value < 0)
   {
      WARNLOG() << "Listen: failed with error " << errno << ":"<<strerror(errno) << endl;
      return false;
   }

   return true;
}


bool Socket::Connect( const string & aPeerAddress, uint2 aPeerPort ) const
{
   sockaddr_in tmpAddress;                        //address structure
                                                  //address size
   socklen_t  tmpAddress_length = sizeof(tmpAddress);

   bool result = SetHostByName( aPeerAddress, aPeerPort, tmpAddress);
   if (!result)
   {
      WARNLOG() << "Connect: failed in SetHostByName" << endl;
      return false;
   }

   int return_value = connect(itsFD, (sockaddr *) &tmpAddress, tmpAddress_length);
   if (return_value < 0)
   {
      WARNLOG() << "Connect: failed with error " << errno << ":"<<strerror(errno) << endl;
      return false;
   }

   return true;
}

void Socket::AddMembership( const string & aMulticastAddress ) const
{
   struct ip_mreq tmpReq;
   tmpReq.imr_multiaddr.s_addr = inet_addr(aMulticastAddress.c_str());
   tmpReq.imr_interface.s_addr = htonl(INADDR_ANY);
   
   int return_value = setsockopt(itsFD, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*)&tmpReq, sizeof(tmpReq));
   LOG_ASSERT(return_value >= 0, "AddMembership: IP_ADD_MEMBERSHIP failed with error " << errno << ":"<<strerror(errno) );
}

void Socket::DropMembership( const string & aMulticastAddress ) const
{
   struct ip_mreq tmpReq;
   tmpReq.imr_multiaddr.s_addr = inet_addr(aMulticastAddress.c_str());
   tmpReq.imr_interface.s_addr = htonl(INADDR_ANY);
   
   int return_value = setsockopt(itsFD, IPPROTO_IP, IP_DROP_MEMBERSHIP, (char*)&tmpReq, sizeof(tmpReq));
   LOG_ASSERT(return_value >= 0, "DropMembership: IP_DROP_MEMBERSHIP failed with error " << errno << ":"<<strerror(errno) );
}


//for connected sockets only !
//FIXME: handle short send
int Socket::Send( const void * aBuffer, uint4 aBufferLength, int theFlags ) const
{
   int return_value = send(itsFD, (char *) aBuffer, aBufferLength, theFlags);   //for w32
   if (return_value < 0)
   {
      WARNLOG() << "Send: send failed with error " << errno << ":"<<strerror(errno) << endl;
   }

   return return_value;
}


//for bind sockets only !
//FIXME: handle short receive
int Socket::Recv( void * aBuffer, uint4 aBufferLength, int theFlags ) const
{
   int return_value = recv(itsFD, (char *) aBuffer, aBufferLength, theFlags); //for w32
   if (return_value < 0)
   {
      WARNLOG() << "Recv: recv failed with error " << errno << ":"<<strerror(errno) << endl;
   }

   return return_value;
}

//for connectionless sockets !
//FIXME: handle short receive
int Socket::RecvFrom( void * aBuffer, uint4 aBufferLength, std::string & aPeerAddressRef, uint2 & aPeerPortRef, int theFlags ) const
{
   sockaddr_in tmpAddress;                        //address structure
                                                  //address size
   socklen_t  tmpAddress_length = sizeof(tmpAddress);

   //TST DEBUGLOG() << "RecvFrom: socket "<<*this<<endl;

   int return_value = recvfrom(itsFD, (char *) aBuffer, aBufferLength, theFlags, (sockaddr *) & tmpAddress, & tmpAddress_length); //for w32
   if (return_value < 0)
   {
      WARNLOG() << "RecvFrom: recv failed with error " << errno << ":"<<strerror(errno) << endl;
   }
   else
   {
    //set Peer Address 
    aPeerPortRef     = ntohs(tmpAddress.sin_port);     //get uint2 port number

    char tmpString[INET_ADDRSTRLEN];
    const char * pReturnString = inet_ntop(AF_INET, reinterpret_cast<PVOID>(&(tmpAddress.sin_addr)), tmpString, INET_ADDRSTRLEN); //get string of dotted internet address, e.g. "192.168.1.0"

    LOG_ASSERT(pReturnString, "RecvFrom: ntop failed with error "<<errno << ":"<<strerror(errno) );

    aPeerAddressRef  = tmpString; 

   } //else

   return return_value;
}


//for connectionless sockets !
//FIXME: handle short send
int Socket::Sendto( const string & aPeerAddress, uint2 aPeerPort, const void * aBuffer, uint4 aBufferLength, int theFlags) const
{
   sockaddr_in tmpAddress;                        //address structure
                                                  //address size
   socklen_t  tmpAddress_length = sizeof(tmpAddress);

   bool result = SetHostByName( aPeerAddress, aPeerPort, tmpAddress);
   if (!result)
   {
      WARNLOG() << "Sendto: failed in SetHostByName" << endl;
      return -1;
   }

   int return_value = sendto(itsFD, (char *) aBuffer, aBufferLength, theFlags, (sockaddr *) &tmpAddress, tmpAddress_length); //for w32
   if (return_value < 0)
   {
      WARNLOG() << "Sendto: send failed with error " << errno << ":"<<strerror(errno) << endl;
   }

   return return_value;
}

bool Socket::SetBlockingMode( const bool & aBlockingMode)
{

#ifdef _TARGET_ARCH_W32_

   unsigned long  mode = aBlockingMode ? 0 : 1;
   return (ioctlsocket(itsFD, FIONBIO, &mode) == 0) ? true : false;

#else

  int flags = fcntl(itsFD, F_GETFL, 0);
  if (flags < 0) return false;
  flags = aBlockingMode ? (flags&~O_NONBLOCK) : (flags|O_NONBLOCK);
  return (fcntl(itsFD, F_SETFL, flags) == 0) ? true : false; 

#endif  

}



//------------------------------ Logging ------------------------------
void Socket::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}


void Socket::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "IO_Socket" );
   aLogFormat . LogElement( aStreamRef, "Domain" );
   aLogFormat . LogDecValue( aStreamRef, itsDomain );
   aLogFormat . LogElement( aStreamRef, "FD" );
   aLogFormat . LogDecValue( aStreamRef, itsFD );
   aLogFormat . LogElement( aStreamRef, "Name" );
   aLogFormat . LogDecValue( aStreamRef, itsName );
   aLogFormat . LogElement( aStreamRef, "Protocol" );
   aLogFormat . LogDecValue( aStreamRef, itsProtocol );
   aLogFormat . LogElement( aStreamRef, "Type" );
   aLogFormat . LogDecValue( aStreamRef, itsType );

   aLogFormat . LogEndStruct( aStreamRef );
}


bool Socket::SetHostByName(const string & anAddress, uint2 aPort, sockaddr_in & anAddressStructure) const
{
   hostent * tmpHost = gethostbyname(anAddress.c_str());      //NOTE: valgrind reports errors ?! //NOTE: outdated: replace with getaddrinfo
   if (!tmpHost)
   {
      WARNLOG() << "SetHostByName: gethostbyname failed with " << h_errno << ":"<<strerror(h_errno) << endl;
      return false;
   }

   memset(&anAddressStructure, 0, sizeof(anAddressStructure));
   anAddressStructure.sin_family = AF_INET;
   anAddressStructure.sin_addr.s_addr = *((unsigned long *) tmpHost->h_addr_list[0]);
   anAddressStructure.sin_port = htons(aPort);

   return true;
}

#ifdef _TARGET_ARCH_W32_
//from https://memset.wordpress.com/2010/10/09/inet_ntop-for-win32/ 
const char* inet_ntop(int af, const void* src, char* dst, int cnt){
 
    struct sockaddr_in srcaddr;
 
    memset(&srcaddr, 0, sizeof(struct sockaddr_in));
    memcpy(&(srcaddr.sin_addr), src, sizeof(srcaddr.sin_addr));
 
    srcaddr.sin_family = af;
    if (WSAAddressToString((struct sockaddr*) &srcaddr, sizeof(struct sockaddr_in), 0, dst, (LPDWORD) &cnt) != 0) {
        DWORD rv = WSAGetLastError();

        errno = rv;  //FIXME: better way to report the error ?

        return NULL;
    }
    return dst;
}
#endif


//End of File
