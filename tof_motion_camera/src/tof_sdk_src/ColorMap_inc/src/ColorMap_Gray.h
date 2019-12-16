///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Gray
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class Gray 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Nov 25 22:11:15 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _ColorMap_Gray_
#define _ColorMap_Gray_

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

#include "Mat2D_VirtualMat.h"

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace ColorMap
namespace ColorMap
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class Gray
class Gray : public Mat2D::VirtualMat<float>
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        Gray( );

   /// Special Constructor
        Gray( const uint2 & N );

   /// Destructor
        ~Gray( );

/// Write human readable representation of content
        void Log( std::ostream & aStreamRef ) const;
   
   /// Write human readable representation with indentation
        void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

private:
  

   //   All the Elements



}; // End of class Gray


}; // End of namespace ColorMap

#endif

