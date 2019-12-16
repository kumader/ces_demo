///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Virtual16BitReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class Virtual16BitReg 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Wed Jul 19 20:33:27 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Rtl16_Virtual16BitReg.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Rtl16;

//------------------------------ Constructor -------------------

Virtual16BitReg::Virtual16BitReg ( ) 
{
  /// nothing
}

//------------------------------ Destructor ----------------------------

Virtual16BitReg::~Virtual16BitReg (  ) 
{
  /// nothing
}


//------------------------------ Logging ------------------------------
void Virtual16BitReg::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void Virtual16BitReg::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Rtl16_Virtual16BitReg" );
    aLogFormat . LogElement( aStreamRef, "Addr" );
    aLogFormat . LogDecValue( aStreamRef, GetAddr() );
    aLogFormat . LogElement( aStreamRef, "Reg" );
    aLogFormat . LogDecValue( aStreamRef, GetReg() );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
