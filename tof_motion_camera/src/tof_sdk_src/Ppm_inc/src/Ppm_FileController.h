///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- FileController
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FileController 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Wed Nov 28 09:59:42 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Ppm_FileController_
#define _Ppm_FileController_

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
#include "Common_UseLogger.h"
#include "Mat2D_MatIdx.h"
#include "Mat2D_VirtualMat.h"

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace Ppm
namespace Ppm
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class FileController
class FileController : public Common::UseLogger
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor (USE ONLY FOR REGRESSIONTEST)
        FileController( );

   /// Destructor
        ~FileController( );

   ///Special Constructor 
        FileController( const std::string & aName
                      , const Common::UseLogger::LogLevel_e & aLogLevel       = Common::UseLogger::S_INFO
                      );   


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

   //  Arithmetic operators
   /// Equal operator 
       bool operator == (const FileController & aRef) const;
   
   /// Less operator 
       bool operator < (const FileController & aRef) const;

    bool WritePpm( const uint4& aXRes
             , const uint4 & aYRes
             , const std::string & aFileName
             , const Mat2D::MatIdx<uint2> & aMatIdx 
             , const Mat2D::VirtualMat<float> & aColorMap
             , const uint2 & aFrameCounter
             , const uint4 & aFrameTimeStamp
             , const bool & aUseScalingFactor
             );  
     bool ReadPpm( const uint4& aXRes
             , const uint4& aYRes
             , const std::string & aFileName
             , uint1 * aBufferPtr
             , const uint4 & aBufferSize
            );


   ///@name Set, Get and other functions for all members 
   //@{
         // The member NrReads
         ///  The Get function for member NrReads
              uint4   GetNrReads( ) const;
         ///  The Set function for member NrReads
              void    SetNrReads( const uint4 & aValue );
         //----------------------------------------------------
         // The member NrWrites
         ///  The Get function for member NrWrites
              uint4   GetNrWrites( ) const;
         ///  The Set function for member NrWrites
              void    SetNrWrites( const uint4 & aValue );
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         uint4 itsNrReads;
         uint4 itsNrWrites;


}; // End of class FileController

//------------------------------ Inline Functions ----------------------
inline bool FileController::operator == (const FileController & aRef) const
{
   if ( ! (itsNrReads == aRef.itsNrReads) ) return false;
   if ( ! (itsNrWrites == aRef.itsNrWrites) ) return false;

   return true;
}

inline bool FileController::operator < (const FileController & aRef) const
{
   if ( ! (itsNrReads < aRef.itsNrReads) ) return false;
   if ( ! (itsNrWrites < aRef.itsNrWrites) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FileController & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint4 FileController::GetNrReads( ) const
{
 return itsNrReads;
}

inline void FileController::SetNrReads( const uint4 & aValue )
{
 itsNrReads = aValue;
}

inline uint4 FileController::GetNrWrites( ) const
{
 return itsNrWrites;
}

inline void FileController::SetNrWrites( const uint4 & aValue )
{
 itsNrWrites = aValue;
}






}; // End of namespace Ppm

#endif

