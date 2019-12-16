///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- MatIdx
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class MatIdx 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Sep 23 22:09:33 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Mat2D_MatIdx_
#define _Mat2D_MatIdx_

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>

#ifdef _TARGET_ARCH_W32_
#define WIN32_LEAN_AND_MEAN
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#endif

#include <string>
#include <cassert>

//------------------------------ Declarations --------------------------

//access macro
#define MAT2D_IDX(x,y) \
(x)+(y)*itsXRes


namespace Common { class LogFormat; }

/// The namespace Mat2D
namespace Mat2D
{


//------------------------------ Exported Class Definitions ------------

/// The definition of class MatIdx
template <class T> class MatIdx
{
public:

   //enums
      typedef uint1 * Uint1Ptr_t;
      typedef T * TPtr_t;


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor (USE FOR REGRESSIONTEST ONLY)
        MatIdx( );

   /// Special Constructor
        MatIdx(const uint2 & aXRes, const uint2 & aYRes, const TPtr_t & aPtr);
        MatIdx(const uint2 & aXRes, const uint2 & aYRes, const Uint1Ptr_t & aPtr);

   /// Destructor
        ~MatIdx( );

   /// Write content into buffer
        bool WriteToBuffer( uint1 * buffer
                          , uint2 aBufferSize
                          , uint2 & aByteOffset ) const;
   /// Read content from buffer
        bool ReadFromBuffer( const uint1 * buffer
                           , uint2 aBufferSize
                           , uint2 & aByteOffset );

   /// Write human readable representation of content
        void Log( std::ostream & aStreamRef ) const;
   
   /// Write human readable representation with indentation
        void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

   /// Write human readable form of referenced matrix
        void LogMat( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

   //  Arithmetic operators
   /// Equal operator 
       bool operator == (const MatIdx & aRef) const;
   
   /// Less operator 
       bool operator < (const MatIdx & aRef) const;

   /// Access functions

       //give index into linear array
       uint4 index (const uint2 & aX, const uint2 & aY) const;           //column and row

       //access operator function
       T& operator () (const uint2 & aX, const uint2 & aY);           //column and row
       T operator () (const uint2 & aX, const uint2 & aY) const;      //column and row

       //access operator
       TPtr_t operator [] (const uint2 & aY);                             //row-wise access
       const TPtr_t operator [] (const uint2 & aY) const;                 //row-wise access

       //stl compatible 
       TPtr_t begin() const;
       TPtr_t end() const;
        

   /// Size functions
       uint4 GetMatSizeOf () const;  //XRes * YRes * sizeof(T)


   ///@name Set, Get and other functions for all members 
   //@{
         // The member Ptr
         ///  The Get function for member Ptr
              TPtr_t   GetPtr( ) const;
         //----------------------------------------------------
         // The member XRes
         ///  The Get function for member XRes
              uint2   GetXRes( ) const;
         //----------------------------------------------------
         // The member YRes
         ///  The Get function for member YRes
              uint2   GetYRes( ) const;
         //----------------------------------------------------

   //@}

private:
//TST        MatIdx(MatIdx const&);               //copy constructor
//TST        MatIdx& operator=(MatIdx const&);    //assignment operator
  

   //   All the Elements

         TPtr_t itsPtr;
         uint2 itsXRes;
         uint2 itsYRes;


}; // End of class MatIdx

//------------------------------ Inline Functions ----------------------
template <class T> 
inline bool MatIdx<T>::operator == (const MatIdx & aRef) const
{
   if ( ! (itsPtr == aRef.itsPtr) ) return false;
   if ( ! (itsXRes == aRef.itsXRes) ) return false;
   if ( ! (itsYRes == aRef.itsYRes) ) return false;

   return true;
}

template <class T> 
inline bool MatIdx<T>::operator < (const MatIdx & aRef) const
{
   if ( ! (itsPtr  < aRef.itsPtr) )  return false;
   if ( ! (itsXRes < aRef.itsXRes) ) return false;
   if ( ! (itsYRes < aRef.itsYRes) ) return false;

   return true; //min 1 attribute in class
}


template <class T> 
inline std::ostream & operator << ( std::ostream & aStreamRef, const MatIdx<T> & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

template <class T> 
inline uint4 MatIdx<T>::index ( const uint2 & aX, const uint2 & aY ) const
{
   assert(aX < itsXRes);
   assert(aY < itsYRes);
   assert(itsPtr);

   return MAT2D_IDX(aX,aY);
}

template <class T> 
inline T & MatIdx<T>::operator () ( const uint2 & aX, const uint2 & aY )
{
   assert(aX < itsXRes);
   assert(aY < itsYRes);
   assert(itsPtr);

   return itsPtr[MAT2D_IDX(aX,aY)];
}

template <class T> 
inline T  MatIdx<T>::operator () ( const uint2 & aX, const uint2 & aY ) const
{
   assert(aX < itsXRes);
   assert(aY < itsYRes);
   assert(itsPtr);

   return itsPtr[MAT2D_IDX(aX,aY)];
}

template <class T> 
inline typename MatIdx<T>::TPtr_t MatIdx<T>::operator [] (const uint2 & aY)
{
 assert(aY < itsYRes);
 assert(itsPtr);

 return itsPtr + MAT2D_IDX(0,aY);
}

template <class T> 
inline const typename MatIdx<T>::TPtr_t MatIdx<T>::operator [] (const uint2 & aY) const
{
 assert(aY < itsYRes);
 assert(itsPtr);

 return itsPtr + MAT2D_IDX(0,aY);
}

template <class T> 
inline typename MatIdx<T>::TPtr_t MatIdx<T>::begin( ) const
{

 return itsPtr;  //points to first element
}

template <class T> 
inline typename MatIdx<T>::TPtr_t MatIdx<T>::end( ) const
{
 return itsPtr + itsXRes * itsYRes;  //points 1 element beyond the memory
}

template <class T> 
inline uint4 MatIdx<T>::GetMatSizeOf( ) const
{
 return itsXRes * itsYRes * sizeof(T);
}

template <class T> 
inline typename MatIdx<T>::TPtr_t MatIdx<T>::GetPtr( ) const
{
 return itsPtr;
}

template <class T> 
inline uint2 MatIdx<T>::GetXRes( ) const
{
 return itsXRes;
}

template <class T> 
inline uint2 MatIdx<T>::GetYRes( ) const
{
 return itsYRes;
}



}; // End of namespace Mat2D

#endif

