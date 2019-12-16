///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class FrameStatistics 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Fri Apr 21 10:22:24 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "TcpFrame_FrameStatistics.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace TcpFrame;

//------------------------------ Constructor -------------------

FrameStatistics::FrameStatistics ( ) 
: itsT1 ( Common::PreciseTimeValue() )
, itsT2 ( Common::PreciseTimeValue() )
, itsNofBytes ( 0 )

{
  /// nothing
}

//------------------------------ Destructor ----------------------------

FrameStatistics::~FrameStatistics (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool FrameStatistics::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //T1  Common::PreciseTimeValue serialization with posix endianess
    {
     if( aByteOffset + sizeof(Common::PreciseTimeValue) > aBufferSize ) return false;
     

     Common::PreciseTimeValue * pTmpT1 = reinterpret_cast< Common::PreciseTimeValue * > ( buffer + aByteOffset );
     *pTmpT1        = itsT1; //FIXME: no endianess checked here
     aByteOffset      += sizeof(Common::PreciseTimeValue);
    }

    //T2  Common::PreciseTimeValue serialization with posix endianess
    {
     if( aByteOffset + sizeof(Common::PreciseTimeValue) > aBufferSize ) return false;
     

     Common::PreciseTimeValue * pTmpT2 = reinterpret_cast< Common::PreciseTimeValue * > ( buffer + aByteOffset );
     *pTmpT2        = itsT2; //FIXME: no endianess checked here
     aByteOffset      += sizeof(Common::PreciseTimeValue);
    }

    //NofBytes  sint8 serialization with posix endianess
    {
     if( aByteOffset + sizeof(sint8) > aBufferSize ) return false;
     

     sint8 * pTmpNofBytes = reinterpret_cast< sint8 * > ( buffer + aByteOffset );
     *pTmpNofBytes        = itsNofBytes; //FIXME: no endianess checked here
     aByteOffset      += sizeof(sint8);
    }

   return true;
}

bool FrameStatistics::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //T1  Common::PreciseTimeValue serialization with posix endianess
    {
     if( aByteOffset + sizeof(Common::PreciseTimeValue) > aBufferSize ) return false;

     const Common::PreciseTimeValue * pTmpT1 = reinterpret_cast< const Common::PreciseTimeValue * > ( buffer + aByteOffset );
     Common::PreciseTimeValue tmpT1 = *pTmpT1; //FIXME: no endianess checked

     

     itsT1     = tmpT1;
     aByteOffset += sizeof(Common::PreciseTimeValue);
    }

    //T2  Common::PreciseTimeValue serialization with posix endianess
    {
     if( aByteOffset + sizeof(Common::PreciseTimeValue) > aBufferSize ) return false;

     const Common::PreciseTimeValue * pTmpT2 = reinterpret_cast< const Common::PreciseTimeValue * > ( buffer + aByteOffset );
     Common::PreciseTimeValue tmpT2 = *pTmpT2; //FIXME: no endianess checked

     

     itsT2     = tmpT2;
     aByteOffset += sizeof(Common::PreciseTimeValue);
    }

    //NofBytes  sint8 serialization with posix endianess
    {
     if( aByteOffset + sizeof(sint8) > aBufferSize ) return false;

     const sint8 * pTmpNofBytes = reinterpret_cast< const sint8 * > ( buffer + aByteOffset );
     sint8 tmpNofBytes = *pTmpNofBytes; //FIXME: no endianess checked

     

     itsNofBytes     = tmpNofBytes;
     aByteOffset += sizeof(sint8);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void FrameStatistics::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void FrameStatistics::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "TcpFrame_FrameStatistics" );
    aLogFormat . LogElement( aStreamRef, "NofBytes" );
    aLogFormat . LogDecValue( aStreamRef, itsNofBytes );

    sint8 duration = itsT2 - itsT1;
    aLogFormat . LogElement( aStreamRef, "duration" );
    aLogFormat . LogDecValue( aStreamRef, duration );

    sint8 tmpDiv =0;
    if (duration) tmpDiv = sint8(1000000) / duration ;

    sint8 bps=0;
    if (duration) bps = itsNofBytes * tmpDiv * 8;
    aLogFormat . LogElement( aStreamRef, "Bits/s" );
    aLogFormat . LogDecValue( aStreamRef, bps );
    
    sint8 fps=0;
    if (duration) fps = tmpDiv;
    aLogFormat . LogElement( aStreamRef, "Frames/s" );
    aLogFormat . LogDecValue( aStreamRef, fps );

   aLogFormat . LogEndStruct( aStreamRef );
}

void FrameStatistics::Start( ) 
{
 itsT1.GetPresentTime();
 itsNofBytes = 0;
}

void FrameStatistics::Update(const sint8 & aNofBytes) 
{
 itsT2.GetPresentTime();
 itsNofBytes += aNofBytes; 
}

//End of File
