///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- SerialNumberHighWordReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class SerialNumberHighWordReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Rtl16_SerialNumberHighWordReg.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Rtl16;

//------------------------------ Constructor -------------------

SerialNumberHighWordReg::SerialNumberHighWordReg ( ) 
: its0Addr ( 0xd )
, its0Reg ( 0 )

{
  /// nothing
}


//------------------------------ Special Constructor -------------------

SerialNumberHighWordReg::SerialNumberHighWordReg ( const uint2 & a0AddrValue, const uint2& a0RegValue ) 
: its0Addr ( a0AddrValue )
, its0Reg  ( a0RegValue )
{
  /// nothing
}



//------------------------------ Destructor ----------------------------

SerialNumberHighWordReg::~SerialNumberHighWordReg (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool SerialNumberHighWordReg::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //0Addr  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its0Addr != 0xd) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp0Addr = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp0Addr        = htons(its0Addr);
     aByteOffset      += sizeof(uint2);
    }

    //0Reg  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp0Reg = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp0Reg        = htons(its0Reg);
     aByteOffset      += sizeof(uint2);
    }

   return true;
}

bool SerialNumberHighWordReg::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //0Addr  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp0Addr = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp0Addr = ntohs(*pTmp0Addr);

     if (tmp0Addr != 0xd) return false; //init value; on false, do not update aByteOffset

     its0Addr     = tmp0Addr;
     aByteOffset += sizeof(uint2);
    }

    //0Reg  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp0Reg = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp0Reg = ntohs(*pTmp0Reg);

     

     its0Reg     = tmp0Reg;
     aByteOffset += sizeof(uint2);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void SerialNumberHighWordReg::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void SerialNumberHighWordReg::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Rtl16_SerialNumberHighWordReg" );
    aLogFormat . LogElement( aStreamRef, "Addr" );
    aLogFormat . LogHexValue( aStreamRef, its0Addr );
    aLogFormat . LogElement( aStreamRef, "SerialNumberHighWord" );
    aLogFormat . LogDecValue( aStreamRef, its0SerialNumberHighWord );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
