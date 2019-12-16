///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- DumperUint2RegMap
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class DumperUint2RegMap 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sat Feb 24 15:41:58 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Common_DumperUint2RegMap.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Common;

//------------------------------ Constructor -------------------

DumperUint2RegMap::DumperUint2RegMap ( ) 
: itsBufferPtr ( 0 )
, itsSize ( 0 )

{
  /// nothing
}

//-----------------------Special Constructor -------------------

DumperUint2RegMap::DumperUint2RegMap (const uint2 * aBufferPtr, const uint2 & aSize ) 
: itsBufferPtr ( aBufferPtr )
, itsSize ( aSize )

{
  /// nothing
}
//------------------------------ Destructor ----------------------------

DumperUint2RegMap::~DumperUint2RegMap (  ) 
{
  /// nothing
}



//------------------------------ Logging ------------------------------
void DumperUint2RegMap::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void DumperUint2RegMap::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{

 aLogFormat.LogBeginStruct(aStreamRef, "uint2_RegMap");
 for(uint2 i=0;i<itsSize;)
 {
  aLogFormat.LogHexMapElement(aStreamRef,"", itsBufferPtr[i++]); //uint2 register 
  aLogFormat.LogHexValue(aStreamRef, itsBufferPtr[i++]);       //uint2 value
 }
 aLogFormat.LogEndStruct(aStreamRef);

}

//End of File
