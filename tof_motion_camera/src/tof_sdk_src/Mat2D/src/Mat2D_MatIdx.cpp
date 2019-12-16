///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- MatIdx
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class MatIdx 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Sep 23 22:07:48 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Mat2D_MatIdx.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Mat2D;



//------------------------------ Constructor -------------------

template <class T>
MatIdx<T>::MatIdx ( ) 
: itsPtr ( 0 )
, itsXRes ( 0 )
, itsYRes ( 0 )

{
  /// nothing
}

template <class T>
MatIdx<T>::MatIdx (const uint2 & aXRes, const uint2 & aYRes, const TPtr_t & aPtr ) 
: itsPtr ( aPtr )
, itsXRes ( aXRes )
, itsYRes ( aYRes )

{
  /// nothing
}

template <class T>
MatIdx<T>::MatIdx (const uint2 & aXRes, const uint2 & aYRes, const Uint1Ptr_t & aPtr ) 
: itsPtr ( reinterpret_cast<TPtr_t> (aPtr) )
, itsXRes ( aXRes )
, itsYRes ( aYRes )

{
  /// nothing
}



//------------------------------ Destructor ----------------------------

template <class T>
MatIdx<T>::~MatIdx (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

template <class T>
bool MatIdx<T>::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //Ptr  TPtr_t serialization with posix endianess
    {
     if( aByteOffset + sizeof(TPtr_t) > aBufferSize ) return false;
     

     TPtr_t * pTmpPtr = reinterpret_cast< TPtr_t * > ( buffer + aByteOffset );
     *pTmpPtr        = itsPtr; //FIXME: no endianess checked here
     aByteOffset      += sizeof(TPtr_t);
    }

    //XRes  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmpXRes = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmpXRes        = htons(itsXRes);
     aByteOffset      += sizeof(uint2);
    }

    //YRes  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmpYRes = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmpYRes        = htons(itsYRes);
     aByteOffset      += sizeof(uint2);
    }

   return true;
}

template <class T>
bool MatIdx<T>::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //Ptr  TPtr_t serialization with posix endianess
    {
     if( aByteOffset + sizeof(TPtr_t) > aBufferSize ) return false;

     const TPtr_t * pTmpPtr = reinterpret_cast< const TPtr_t * > ( buffer + aByteOffset );
     TPtr_t tmpPtr = *pTmpPtr; //FIXME: no endianess checked

     

     itsPtr     = tmpPtr;
     aByteOffset += sizeof(TPtr_t);
    }

    //XRes  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmpXRes = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmpXRes = ntohs(*pTmpXRes);

     

     itsXRes     = tmpXRes;
     aByteOffset += sizeof(uint2);
    }

    //YRes  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmpYRes = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmpYRes = ntohs(*pTmpYRes);

     

     itsYRes     = tmpYRes;
     aByteOffset += sizeof(uint2);
    }

   return true;
}

//------------------------------ Logging ------------------------------

template <class T>
void MatIdx<T>::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

template <class T>
void MatIdx<T>::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Mat2D_MatIdx" );
    aLogFormat . LogElement( aStreamRef, "Ptr" );
    aLogFormat . LogDecValue( aStreamRef, itsPtr );
    aLogFormat . LogElement( aStreamRef, "XRes" );
    aLogFormat . LogDecValue( aStreamRef, itsXRes );
    aLogFormat . LogElement( aStreamRef, "YRes" );
    aLogFormat . LogDecValue( aStreamRef, itsYRes );

   aLogFormat . LogEndStruct( aStreamRef );
}

template <class T>
void MatIdx<T>::LogMat( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "*Mat2D_MatIdx" );
    aLogFormat . LogElement( aStreamRef, "Ptr" );
    aLogFormat . LogDecValue( aStreamRef, itsPtr );
    aLogFormat . LogElement( aStreamRef, "YRes" );
    aLogFormat . LogDecValue( aStreamRef, itsYRes );
    aLogFormat . LogElement( aStreamRef, "XRes" );
    aLogFormat . LogDecValue( aStreamRef, itsXRes );
   for(uint2 y=0;y<itsYRes;++y)
   {
     aLogFormat . LogMapElement( aStreamRef, "", y );
    for(uint2 x=0;x<itsXRes;++x)
    {
     aLogFormat . LogStringValue( aStreamRef, " " );
     aLogFormat . LogDecValue( aStreamRef, MatIdx<T>::operator() (x,y) );
    } //for
   }//for
   aLogFormat . LogEndStruct( aStreamRef );
}




//explicit template instantiation
template class MatIdx<uint2>;
template class MatIdx<sint2>;
template class MatIdx<float>;

//End of File
