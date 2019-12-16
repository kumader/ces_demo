///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 2383 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class FrameController 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Apr 17 14:27:18 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"

//#include <unistd.h>
#include <cstring>

#include "UdpFrame_FrameController.h"
#include "Common_LogFormat.h"
#include "UdpFrame_UdpDataInterfaceHeaderV1.h"
#include "UdpFrame_FrameDataInterfaceHeaderV31.h"


#ifdef _TARGET_ARCH_W32_
//ROH: try without #define _WIN32_WINNT _WIN32_WINNT_WIN8 // Windows 8.0
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>                            //inet_ functions
#endif

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace UdpFrame;

//------------------------------ Constructor -------------------

FrameController::FrameController ( ) 
: UseLogger ( ) 
, itsUdpSocket ( IO::Socket() )
, itsUdpSelect ( IO::SelectWithSockets() )
, itsSecondsTimeout ( 0 )
, itsMicroSecondsTimeout ( 0 )
, itsLocalUdpPort ( 93 )

{
  /// nothing
}


//------------------------------ Special Constructor -------------------

FrameController::FrameController( const std::string & aName
			      , const uint2 & aLocalUdpPort
			      , const Common::UseLogger::LogLevel_e & aLogLevel 
			      , const uint4 & aSecondsTimeout
			      , const uint4 & aMicroSecondsTimeout
			      )
: UseLogger (
 0
, aLogLevel
, aName
)
, itsUdpSocket ( aName, aLogLevel, SOCK_DGRAM, IPPROTO_UDP )
, itsUdpSelect ( aName, aLogLevel )
, itsSecondsTimeout ( aSecondsTimeout )
, itsMicroSecondsTimeout ( aMicroSecondsTimeout )
, itsLocalUdpPort ( aLocalUdpPort )
{
  //initialise IO
  itsUdpSocket.BindLocalPort(itsLocalUdpPort);
  //TST itsUdpSocket.AddMembership("224.0.0.1");       //multicast default group //FIXME: use parameter
  itsUdpSelect.Add(itsUdpSocket);
}

//------------------------------ Destructor ----------------------------

FrameController::~FrameController (  ) 
{
 //close IO
#ifdef _TARGET_ARCH_W32_
 closesocket(itsUdpSocket.GetFD());
#else
 close(itsUdpSocket.GetFD());
#endif
}

//------------------------------ Logging ------------------------------
void FrameController::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void FrameController::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "UdpFrame_FrameController" );
    aLogFormat . LogElement( aStreamRef, "UdpSocket" );
    itsUdpSocket . Log(aStreamRef, aLogFormat);
    aLogFormat . LogElement( aStreamRef, "UdpSelect" );
    itsUdpSelect . Log(aStreamRef, aLogFormat); 
    aLogFormat . LogElement( aStreamRef, "SecondsTimeout" );
    aLogFormat . LogDecValue( aStreamRef, itsSecondsTimeout );
    aLogFormat . LogElement( aStreamRef, "MicroSecondsTimeout" );
    aLogFormat . LogDecValue( aStreamRef, itsMicroSecondsTimeout );
    aLogFormat . LogElement( aStreamRef, "LocalUdpPort" );
    aLogFormat . LogDecValue( aStreamRef, itsLocalUdpPort );

   aLogFormat . LogEndStruct( aStreamRef );
}

bool FrameController::GetFrame (uint1 * aFramePtr, const uint4 & aFrameSize, uint4 & aFrameOffsetRef)
{

  //parameter check
  LOG_ASSERT(aFramePtr, "aFramePtr == 0, but expect preallocated memory");

  //prepare select
  IO::SelectWithSockets::SocketList_t sl;

  //prepare frame_counter
  uint2 frame_ctr = 0;
  //prepare packet counter
  uint2 packet_ctr = 0;

  //prepare for memory check
  uint4 max_frame_size = 0;

  //prepare udp receive buffer   
  const uint2 C_UDP_SIZE = 8192;                //single udp packet
  uint1 udp_data [C_UDP_SIZE];                   //reserve on stack

  while(1)
    {
      int can_read;
      if (itsSecondsTimeout || itsMicroSecondsTimeout) can_read = itsUdpSelect.Can_Read(itsSecondsTimeout, itsMicroSecondsTimeout,sl);
      else can_read = itsUdpSelect.Can_Read(sl);

      if (can_read < 0)
      {
       ERRORLOG() << "can read error"<<std::endl;
       return false;
      }

      if (can_read == 0)
      {
       WARNLOG() << "timeout after "<<itsSecondsTimeout<<" s, "<<itsMicroSecondsTimeout<<" us"<<std::endl;
       return false;
      }

      size_t nr_bytes = sl.front().Recv(udp_data, C_UDP_SIZE, 0);   //blocking recv

      UdpFrame::UdpDataInterfaceHeaderV1 uh;

      uint2 udp_offset = 0;
      bool ufound = uh.ReadFromBuffer(udp_data , nr_bytes, udp_offset);
      if (!ufound)
      {
       WARNLOG() << "no udp data interface V1 found at "<<udp_offset<<std::endl;
       continue;
      }

      DEBUGLOG() << uh << std::endl;

      if (ufound && uh.Get4PacketCounter( ) == 0)   //indicates first frame packet
      {
       //check for frame data header
       UdpFrame::FrameDataInterfaceHeaderV31 dh;

       uint2 frame_header_offset = udp_offset;
       bool dfound = dh.ReadFromBuffer(udp_data, nr_bytes - frame_header_offset, frame_header_offset);
       if (!dfound)
       {
        WARNLOG() << "no frame data interface V31 found at "<<frame_header_offset<<std::endl;
        continue;
       }

       DEBUGLOG() << dh << std::endl;

       //buffer size consistency check
       max_frame_size = uh.Get8FrameSize( );
       LOG_ASSERT(aFrameSize >= max_frame_size, "aFrameSize "<<aFrameSize<< "<"<<max_frame_size<<std::endl);

       //keep what we got
       //copy data buffer
       memcpy(aFramePtr, udp_data + udp_offset, nr_bytes - udp_offset); //include frame header
       aFrameOffsetRef = nr_bytes - udp_offset;


       if (frame_ctr && frame_ctr + 1 != uh.Get2FrameCounter()) 
       {
         WARNLOG() << "frame slip, frame ("<<frame_ctr + 1<<" ? "<<uh.Get2FrameCounter()<<")"<<std::endl; 
         //accept frame anyway
       }

       frame_ctr    = uh.Get2FrameCounter();
       packet_ctr = 1;   //expect this as next data packet
       //TST only SetCycle(frame_ctr);

      }//if
      else
      {
       //udp data interface V1,  out of sync
       if (packet_ctr != uh.Get4PacketCounter( ) || frame_ctr != uh.Get2FrameCounter())
       {
        WARNLOG() << "packet slip ("<<packet_ctr<<" ? "<<uh.Get4PacketCounter()<<"), frame ("<<frame_ctr<<" ? "<<uh.Get2FrameCounter()<<")"<<std::endl;
        //do not accept packet
        continue;
       }

       //in sync
       //keep what we got
       memcpy(aFramePtr + aFrameOffsetRef , udp_data + udp_offset, nr_bytes - udp_offset);
       aFrameOffsetRef += nr_bytes - udp_offset;
       ++ packet_ctr; //expect this as next data packet

       //all frame bytes copied, then break from while loop
       if (aFrameOffsetRef >= max_frame_size)   break;       //use the given frame size from packet 0 
      } //else
  } //while

    //slurped 1 complete frame 
    INFOLOG() << "frame "<<frame_ctr<<", read "<<packet_ctr<< " packets, "<<aFrameOffsetRef<< " bytes"<<std::endl;
    return true;

} //GetFrame()






//End of File
