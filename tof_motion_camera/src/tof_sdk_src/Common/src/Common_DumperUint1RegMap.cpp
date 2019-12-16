///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- DumperUint1RegMap
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class DumperUint1RegMap 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sat Feb 24 15:51:30 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Common_DumperUint1RegMap.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Common;

//------------------------------ Constructor -------------------

DumperUint1RegMap::DumperUint1RegMap ( ) 
: itsBufferPtr ( 0 )
, itsSize ( 0 )

{
  /// nothing
}

//-----------------------Special Constructor -------------------

DumperUint1RegMap::DumperUint1RegMap (const uint1 * aBufferPtr, const uint2 & aSize ) 
: itsBufferPtr ( aBufferPtr )
, itsSize ( aSize )

{
  /// nothing
}
//------------------------------ Destructor ----------------------------

DumperUint1RegMap::~DumperUint1RegMap (  ) 
{
  /// nothing
}



//------------------------------ Logging ------------------------------
void DumperUint1RegMap::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void DumperUint1RegMap::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{

 aLogFormat.LogBeginStruct(aStreamRef, "uint1_RegMap");
 for(uint2 i=0;i<itsSize;)
 {
  aLogFormat.LogHexMapElement(aStreamRef,"", itsBufferPtr[i++]); //uint1 register 
  aLogFormat.LogHexValue(aStreamRef, itsBufferPtr[i++]);       //uint1 value
 }
 aLogFormat.LogEndStruct(aStreamRef);

}

//End of File
