///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- VirtualMat
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class VirtualMat 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Nov 26 17:14:11 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Mat2D_VirtualMat.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Mat2D;



//------------------------------ Constructor -------------------

template <class T>
VirtualMat<T>::VirtualMat ( ) 
: itsVector ( VirtualMat<T>::Vector_t() )
, itsIdx ( VirtualMat<T>::Idx_t() )

{
  /// nothing
}

template <class T>
VirtualMat<T>::VirtualMat ( const uint2 & XRes, const uint2 & YRes ) 
: itsVector ( VirtualMat<T>::Vector_t(YRes * XRes) )
, itsIdx ( VirtualMat<T>::Idx_t(XRes, YRes, &itsVector[0]) )

{
 /// nothing
}




//------------------------------ Destructor ----------------------------
template <class T>
VirtualMat<T>::~VirtualMat (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

template <class T>
bool VirtualMat<T>::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //Idx  VirtualMat<T>::Idx_t serialization with posix endianess
    {
     if( aByteOffset + sizeof(VirtualMat<T>::Idx_t) > aBufferSize ) return false;
     

     VirtualMat<T>::Idx_t * pTmpIdx = reinterpret_cast< VirtualMat<T>::Idx_t * > ( buffer + aByteOffset );
     *pTmpIdx        = itsIdx; //FIXME: no endianess checked here
     aByteOffset      += sizeof(VirtualMat<T>::Idx_t);
    }

    //Vector  VirtualMat<T>::Vector_t serialization with posix endianess
    {
     if( aByteOffset + sizeof(VirtualMat<T>::Vector_t) > aBufferSize ) return false;
     

     VirtualMat<T>::Vector_t * pTmpVector = reinterpret_cast< VirtualMat<T>::Vector_t * > ( buffer + aByteOffset );
     *pTmpVector        = itsVector; //FIXME: no endianess checked here
     aByteOffset      += sizeof(VirtualMat<T>::Vector_t);
    }

   return true;
}

template <class T>
bool VirtualMat<T>::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //Idx  VirtualMat<T>::Idx_t serialization with posix endianess
    {
     if( aByteOffset + sizeof(VirtualMat<T>::Idx_t) > aBufferSize ) return false;

     const VirtualMat<T>::Idx_t * pTmpIdx = reinterpret_cast< const VirtualMat<T>::Idx_t * > ( buffer + aByteOffset );
     VirtualMat<T>::Idx_t tmpIdx = *pTmpIdx; //FIXME: no endianess checked

     

     itsIdx     = tmpIdx;
     aByteOffset += sizeof(VirtualMat<T>::Idx_t);
    }

    //Vector  VirtualMat<T>::Vector_t serialization with posix endianess
    {
     if( aByteOffset + sizeof(VirtualMat<T>::Vector_t) > aBufferSize ) return false;

     const VirtualMat<T>::Vector_t * pTmpVector = reinterpret_cast< const VirtualMat<T>::Vector_t * > ( buffer + aByteOffset );
     VirtualMat<T>::Vector_t tmpVector = *pTmpVector; //FIXME: no endianess checked

     

     itsVector     = tmpVector;
     aByteOffset += sizeof(VirtualMat<T>::Vector_t);
    }

   return true;
}

//------------------------------ Logging ------------------------------
template <class T>
void VirtualMat<T>::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

template <class T>
void VirtualMat<T>::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Mat2D_VirtualMat" );
    itsIdx.LogMat(aStreamRef, aLogFormat);
   aLogFormat . LogEndStruct( aStreamRef );
}


template class VirtualMat<float>;
template class VirtualMat<uint2>;
template class VirtualMat<sint2>;


//End of File
