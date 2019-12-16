///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- DumperUint1Buffer
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class DumperUint1Buffer 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sat Feb 24 16:05:03 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Common_DumperUint1Buffer.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Common;

//------------------------------ Constructor -------------------

DumperUint1Buffer::DumperUint1Buffer ( ) 
: itsBufferPtr ( 0 )
, itsSize ( 0 )

{
  /// nothing
}

//-----------------------Special Constructor -------------------

DumperUint1Buffer::DumperUint1Buffer (const uint1 * aBufferPtr, const uint2 & aSize ) 
: itsBufferPtr ( aBufferPtr )
, itsSize ( aSize )

{
  /// nothing
}
//------------------------------ Destructor ----------------------------

DumperUint1Buffer::~DumperUint1Buffer (  ) 
{
  /// nothing
}



//------------------------------ Logging ------------------------------
void DumperUint1Buffer::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void DumperUint1Buffer::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{

 aLogFormat.LogBeginStruct(aStreamRef, "uint1_Buffer");
 for(uint2 i=0;i<itsSize;++i)
 {
  aLogFormat.LogMapElement(aStreamRef,"",i); 
  aLogFormat.LogHexValue(aStreamRef, itsBufferPtr[i]);       //uint1 value
 }
 aLogFormat.LogEndStruct(aStreamRef);

}

//End of File
