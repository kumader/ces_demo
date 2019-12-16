///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4868 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class LogFormat 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Fri Oct  1 19:20:12 2004
//              automatically generated code
//              manually modified
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header$" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Common_LogFormat.h"
#include <iomanip>

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Common;

//------------------------------ Constructor -------------------


///Useless default constructor
///Values are set to anything
///NOTE: this constructor is only for testing
LogFormat::LogFormat ( ) 
: itsBeginFieldSeparator ( " " )
, itsCurrentDepth ( 0 )
, itsFieldSeparator ( itsBeginFieldSeparator )
, itsIndent ( 0 )
, itsIndentSpaces ( "   " )
, itsFinalSpaces ( "  " )
, itsMaxDepth ( 99 )
, itsMiddleFieldSeparator ( "," )    //REQUIRE: same length as itsBeginFieldSeparator
, itsMode ( TEXT_BLOCK )
, itsFirstOccurence ( true)
{
  /// nothing
}

LogFormat::LogFormat ( const uint2 & aMaxDepth    
                     , const uint2 & aMode
                     , const uint2 & anInitIndent
                     ) 
: itsBeginFieldSeparator ( " " )
, itsCurrentDepth ( 0 )
, itsFieldSeparator ( itsBeginFieldSeparator )
, itsIndent ( anInitIndent )
, itsIndentSpaces ( "   " )          
, itsFinalSpaces ( "  " )
, itsMaxDepth ( aMaxDepth )
, itsMiddleFieldSeparator ( "," )    //REQUIRE: same length as itsBeginFieldSeparator
, itsMode ( aMode )
, itsFirstOccurence ( true)

{
  /// nothing
}


//------------------------------ Destructor ----------------------------

LogFormat::~LogFormat (  ) 
{
  /// nothing
}

//------------------------------ Logging ------------------------------
void LogFormat::Log( ostream & aStreamRef )
{
   LogBeginStruct( aStreamRef, "Common_LogFormat" );
   LogElement( aStreamRef, "BeginFieldSeparator" );
   LogDecValue( aStreamRef, itsBeginFieldSeparator );
   LogElement( aStreamRef, "CurrentDepth" );
   LogDecValue( aStreamRef, itsCurrentDepth );
   LogElement( aStreamRef, "FieldSeparator" );
   LogDecValue( aStreamRef, itsFieldSeparator );
   LogElement( aStreamRef, "Indent" );
   LogDecValue( aStreamRef, itsIndent );
   LogElement( aStreamRef, "IndentSpaces" );
   LogElement( aStreamRef, "FinalSpaces" );
   LogDecValue( aStreamRef, itsIndentSpaces );
   LogElement( aStreamRef, "MaxDepth" );
   LogDecValue( aStreamRef, itsMaxDepth );
   LogElement( aStreamRef, "MiddleFieldSeparator" );
   LogDecValue( aStreamRef, itsMiddleFieldSeparator );
   LogElement( aStreamRef, "Mode" );
   LogDecValue( aStreamRef, itsMode );
   LogEndStruct( aStreamRef );
}

void LogFormat::LogBeginStruct( ostream & aStreamRef, const string & aStructName )
{
 if (itsCurrentDepth >= itsMaxDepth)
 { 
 //count depth and indent, no logging
 itsCurrentDepth++;
 itsIndent++;
 return;
 }

 switch (itsMode)
 {
  case TEXT_BLOCK: aStreamRef << aStructName << "\n";
                   for (uint4 i = 0; i<= itsIndent; ++i) aStreamRef << itsIndentSpaces;
                   aStreamRef << "{"; 
                   itsFieldSeparator = itsBeginFieldSeparator;
                   break;
  case SINGLE_LINE: aStreamRef << aStructName; 
                    aStreamRef << "{"; 
                    itsFieldSeparator = ""; //NONE
                    break;
 }//switch

 itsCurrentDepth++;
 itsIndent++;
}

void LogFormat::LogEndStruct( ostream & aStreamRef )
{
 itsCurrentDepth--;  //UNPROTECTED: make sure that your number of LogEndStruct calls matches number of LogBeginStruct calls
 itsIndent--;        //UNPROTECTED: -"-

 if (itsCurrentDepth >= itsMaxDepth) return; 

 itsFirstOccurence = true; //log a ... only once per level

 switch (itsMode)
 {
 case TEXT_BLOCK: aStreamRef << endl;
                  for (uint4 i = 0; i<= itsIndent; ++i) aStreamRef << itsIndentSpaces;
                  aStreamRef << "}"; 
                  break;
 case SINGLE_LINE: aStreamRef << "}"; 
                   break;
 }//switch
 itsFieldSeparator = itsMiddleFieldSeparator;

}

void LogFormat::LogElement( ostream & aStreamRef, const string & anElementName )
{
 
 if (itsCurrentDepth >= itsMaxDepth)
 {
  if (itsFirstOccurence)  
  { 
   aStreamRef << "...";
   itsFirstOccurence = false;
  }
  return;
 }

 switch (itsMode)
 {
 case TEXT_BLOCK: aStreamRef << endl;
                  for (uint4 i = 0; i< itsIndent; ++i) aStreamRef << itsIndentSpaces;
                  aStreamRef << itsFieldSeparator;
                  aStreamRef << itsFinalSpaces;
                  aStreamRef << anElementName << " = ";
                  break;
 case SINGLE_LINE: aStreamRef << itsFieldSeparator;
                   aStreamRef << anElementName << "=";
                   break;
 }

 itsFieldSeparator = itsMiddleFieldSeparator;
}

void LogFormat::LogMapElement( ostream & aStreamRef, const string & anElementName, const uint4 & anIndex )
{
 if (itsCurrentDepth >= itsMaxDepth)
 {
  if (itsFirstOccurence)  
  { 
   aStreamRef << "...";
   itsFirstOccurence = false;
  }
  return;
 }

 switch (itsMode)
 {
 case TEXT_BLOCK: aStreamRef << endl;
                  for (uint4 i = 0; i< itsIndent; ++i) aStreamRef << itsIndentSpaces;
                  aStreamRef << itsFieldSeparator;
                  aStreamRef << itsFinalSpaces;
                  aStreamRef << anElementName << "["<<anIndex<<"]"<<" => ";
                  break;
case SINGLE_LINE: aStreamRef << itsFieldSeparator;
                  aStreamRef << anElementName << "["<<anIndex<<"]"<<"=>";
                  break;
 }

 itsFieldSeparator = itsMiddleFieldSeparator;
}

void LogFormat::LogHexMapElement( ostream & aStreamRef, const string & anElementName, const uint4 & anIndex )
{
 if (itsCurrentDepth >= itsMaxDepth)
 {
  if (itsFirstOccurence)  
  { 
   aStreamRef << "...";
   itsFirstOccurence = false;
  }
  return;
 }

 switch (itsMode)
 {
 case TEXT_BLOCK: aStreamRef << endl;
                  for (uint4 i = 0; i< itsIndent; ++i) aStreamRef << itsIndentSpaces;
                  aStreamRef << itsFieldSeparator;
                  aStreamRef << itsFinalSpaces;
                  aStreamRef << anElementName << "[0x"<<hex<<anIndex<<dec<<"]"<<" => ";
                  break;
case SINGLE_LINE: aStreamRef << itsFieldSeparator;
                  aStreamRef << anElementName << "[0x"<<hex<<anIndex<<dec<<"]"<<"=>";
                  break;
 }

 itsFieldSeparator = itsMiddleFieldSeparator;
}



void LogFormat::LogMapElement( ostream & aStreamRef, const string & anElementName, const string & anIndex )
{
 if (itsCurrentDepth >= itsMaxDepth)
 {
  if (itsFirstOccurence)  
  { 
   aStreamRef << "...";
   itsFirstOccurence = false;
  }
  return;
 }

 switch (itsMode)
 {
 case TEXT_BLOCK: aStreamRef << endl;
                  for (uint4 i = 0; i< itsIndent; ++i) aStreamRef << itsIndentSpaces;
                  aStreamRef << itsFieldSeparator;
                  aStreamRef << itsFinalSpaces;
                  aStreamRef << anElementName << "[\""<<anIndex<<"\"]"<<" => ";
                  break;
 case SINGLE_LINE: aStreamRef << itsFieldSeparator;
                   aStreamRef << anElementName << "[\""<<anIndex<<"\"]"<<"=>";
                   break;

 }

 itsFieldSeparator = itsMiddleFieldSeparator;
}


void LogFormat::LogNull( ostream & aStreamRef ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef << "0*";
}

void LogFormat::LogDecValue( ostream & aStreamRef, const uint4 & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef << aValue ;
}

void LogFormat::LogDecValue( ostream & aStreamRef, const uint2 & aValue ) const 
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef << aValue ;
}

void LogFormat::LogDecValue( ostream & aStreamRef, const uint1 & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef << static_cast<uint2>(aValue) ;
}

void LogFormat::LogDecValue( ostream & aStreamRef, const char & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef <<"'"<< aValue <<"'";
}

void LogFormat::LogDecValue( ostream & aStreamRef, const int & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef << aValue ;
}

void LogFormat::LogDecValue( ostream & aStreamRef, const long & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef << aValue ;
}

void LogFormat::LogDecValue( ostream & aStreamRef, const long long & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef << aValue ;
}


void LogFormat::LogDecValue( ostream & aStreamRef, const string & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef <<"\""<< aValue <<"\"";
}

void LogFormat::LogStringValue( ostream & aStreamRef, const string & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef << aValue;
}

void LogFormat::LogDecValue( ostream & aStreamRef, const bool & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 if (aValue) aStreamRef << "true" ;
 else aStreamRef << "false" ;
}

void LogFormat::LogDecValue( ostream & aStreamRef, void * const aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 if (aValue) aStreamRef << aValue;
 else aStreamRef << "0*";
}

void LogFormat::LogDecValue( ostream & aStreamRef, const float & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef << aValue;
}

void LogFormat::LogDecValue( ostream & aStreamRef, const double & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef <<std::setprecision(12)<< aValue;
}



void LogFormat::LogHexValue( ostream & aStreamRef, const uint1 & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef <<"0x"<<hex<< static_cast<uint2>(aValue) <<dec;
}

void LogFormat::LogHexValue( ostream & aStreamRef, const uint4 & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef <<"0x"<<hex<< aValue <<dec;
}

void LogFormat::LogHexValue( ostream & aStreamRef, const uint2 & aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 aStreamRef <<"0x"<<hex<< aValue <<dec;
}

void LogFormat::LogHexValue( ostream & aStreamRef, void * const aValue ) const
{
 if (itsCurrentDepth >= itsMaxDepth) return;
 if (aValue) aStreamRef << aValue;
 else aStreamRef << "0*";
}


void LogFormat::DumpBuffer( ostream & aStreamRef, const uint1 * aBufferPtr, const uint2 & aSize ) 
{
 LogBeginStruct(aStreamRef, "uint1_Buffer");
 for(uint2 i=0;i<aSize;++i)
 {
  LogMapElement(aStreamRef,"",i); 
  LogHexValue(aStreamRef,aBufferPtr[i]); 
 }
 LogEndStruct(aStreamRef);
}

//End of File
