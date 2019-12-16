///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- VirtualMat
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class VirtualMat 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Nov 26 17:14:11 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Mat2D_VirtualMat_
#define _Mat2D_VirtualMat_

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

#include <vector>
#include "Mat2D_MatIdx.h"

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace Mat2D
namespace Mat2D
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class VirtualMat
template <class T> class VirtualMat
{
public:

   //typedefs
        typedef T * TPtr_t;
        typedef std::vector<T> Vector_t;
        typedef Mat2D::MatIdx<T> Idx_t;

   //enums
      

   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        VirtualMat( );

   /// Special Constructor
        VirtualMat( const uint2 & XRes, const uint2 & YRes );

   /// Destructor
        virtual ~VirtualMat( );

   /// Write content into buffer
        virtual bool WriteToBuffer( uint1 * buffer
                          , uint2 aBufferSize
                          , uint2 & aByteOffset ) const;
   /// Read content from buffer
        virtual bool ReadFromBuffer( const uint1 * buffer
                           , uint2 aBufferSize
                           , uint2 & aByteOffset );

   /// Write human readable representation of content
        virtual void Log( std::ostream & aStreamRef ) const;
   
   /// Write human readable representation with indentation
        virtual void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

   //  Arithmetic operators
   /// Equal operator 
       virtual bool operator == (const VirtualMat & aRef) const;
   
   /// Less operator 
       virtual bool operator < (const VirtualMat & aRef) const;

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

protected:
  

   //   All the Elements

    std::vector<T> itsVector;
    Mat2D::MatIdx<T> itsIdx;


}; // End of class VirtualMat

//------------------------------ Inline Functions ----------------------
template <class T> 
inline bool VirtualMat<T>::operator == (const VirtualMat & aRef) const
{
   if ( ! (itsIdx == aRef.itsIdx) ) return false;
   if ( ! (itsVector == aRef.itsVector) ) return false;

   return true;
}

template <class T> 
inline bool VirtualMat<T>::operator < (const VirtualMat & aRef) const
{
   if ( ! (itsIdx < aRef.itsIdx) ) return false;
   if ( ! (itsVector < aRef.itsVector) ) return false;

   return true; //min 1 attribute in class
}


template <class T> 
inline std::ostream & operator << ( std::ostream & aStreamRef, const VirtualMat<T> & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

template <class T> 
inline uint4 VirtualMat<T>::index ( const uint2 & aX, const uint2 & aY ) const
{
  return itsIdx.index(aX,aY);
}

template <class T> 
inline T & VirtualMat<T>::operator () ( const uint2 & aX, const uint2 & aY )
{
   return itsIdx(aX,aY);
}

template <class T> 
inline T  VirtualMat<T>::operator () ( const uint2 & aX, const uint2 & aY ) const
{
   return itsIdx(aX,aY);
}

template <class T> 
inline const typename VirtualMat<T>::TPtr_t VirtualMat<T>::operator [] (const uint2 & aY) const
{
  return itsIdx[aY];
}

template <class T> 
inline typename VirtualMat<T>::TPtr_t VirtualMat<T>::begin( ) const
{

 return itsIdx.GetPtr();  //points to first element
}

template <class T> 
inline typename VirtualMat<T>::TPtr_t VirtualMat<T>::end( ) const
{
 return itsIdx.end();  //points 1 element beyond the memory
}

template <class T> 
inline uint4 VirtualMat<T>::GetMatSizeOf( ) const
{
 return itsIdx.GetMatSizeOf( );
}

template <class T> 
inline typename VirtualMat<T>::TPtr_t VirtualMat<T>::GetPtr( ) const
{
 return itsIdx.GetPtr();
}

template <class T>
inline uint2 VirtualMat<T>::GetXRes( ) const
{
 return itsIdx.GetXRes();
}

template <class T> 
inline uint2 VirtualMat<T>::GetYRes( ) const
{
 return itsIdx.GetYRes();
}



}; // End of namespace Mat2D

#endif

