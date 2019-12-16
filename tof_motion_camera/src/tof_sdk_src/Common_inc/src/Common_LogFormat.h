///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4867 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class LogFormat 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Fri Oct  1 19:20:12 2004
//              automatically generated code
//              manuall modified and updated to new c++ standard 15.07.2005
///////////////////////////////////////////////////////////////////////////

#ifndef _Common_LogFormat_
#define _Common_LogFormat_

#ifdef USE_IDENT
#ident "$Header$" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>
#include <string>

//------------------------------ Declarations --------------------------
class LogCtx;

/// The namespace Common
namespace Common
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class LogFormat
class LogFormat
{
public:

     enum LogMode_e
   {
      /// block oriented logging 
      TEXT_BLOCK 
      /// line oriented logging
   ,  SINGLE_LINE
   };


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        LogFormat( );

   /// Special Constructor
        LogFormat( const uint2 & aMaxDepth       
                 , const uint2 & aMode           = SINGLE_LINE 
                 , const uint2 & anInitIndent    =  0 
                 );

   /// Destructor
        ~LogFormat( );

   /// Write human readable representation of content
        void Log( std::ostream & aStreamRef );
   
   //  Arithmetic operators
   /// Equal operator 
       bool operator == (const LogFormat & aRef) const;
   
   /// Less operator 
       bool operator < (const LogFormat & aRef) const;

   ///@name Set and Get functions for all members 
   //@{
         // The member BeginFieldSeparator
         ///  The Get function for member BeginFieldSeparator
              std::string   GetBeginFieldSeparator( ) const;
         ///  The Set function for member BeginFieldSeparator
              void    SetBeginFieldSeparator( std::string aValue );
         //----------------------------------------------------
         // The member FieldSeparator
         ///  The Get function for member FieldSeparator
	      std::string   GetFieldSeparator( ) const;
         ///  The Set function for member FieldSeparator
              void    SetFieldSeparator( std::string aValue );
         //----------------------------------------------------
         
         // The member CurrentDepth
         ///  The Get function for member CurrentDepth
              uint2   GetCurrentDepth( ) const;
         ///  The Set function for member CurrentDepth
              void    SetCurrentDepth( uint2 aValue );
         //----------------------------------------------------
         // The member Indent
         ///  The Get function for member Indent
              uint2   GetIndent( ) const;
         ///  The Set function for member Indent
              void    SetIndent( uint2 aValue );
         //----------------------------------------------------
         // The member IndentSpaces
         ///  The Get function for member IndentSpaces
	      std::string   GetIndentSpaces( ) const;
         ///  The Set function for member IndentSpaces
              void    SetIndentSpaces( std::string aValue );
         //----------------------------------------------------
         // The member FinalSpaces
         ///  The Get function for member FinalSpaces
	      std::string   GetFinalSpaces( ) const;
         ///  The Set function for member FinalSpaces
              void    SetFinalSpaces( std::string aValue );
         //----------------------------------------------------
         // The member MaxDepth
         ///  The Get function for member MaxDepth
              uint2   GetMaxDepth( ) const;
         ///  The Set function for member MaxDepth
              void    SetMaxDepth( uint2 aValue );
         //----------------------------------------------------
         // The member MiddleFieldSeparator
         ///  The Get function for member MiddleFieldSeparator
	      std::string   GetMiddleFieldSeparator( ) const;
         ///  The Set function for member MiddleFieldSeparator
              void    SetMiddleFieldSeparator( std::string aValue );
         //----------------------------------------------------
         // The member Mode
         ///  The Get function for member Mode
              uint2   GetMode( ) const;
         ///  The Set function for member Mode
              void    SetMode( uint2 aValue );
         //----------------------------------------------------

   //@}

///@name Special Functions
//@{
    /// Begin the logging of a new structure
    void LogBeginStruct( std::ostream & aStreamRef, const std::string & aStructureName );

    /// Close the logging of a new structure
   void LogEndStruct( std::ostream & aStreamRef );

    /// Log the name of a structure element
   void LogElement( std::ostream & aStreamRef, const std::string & anElementName );

    /// Log the name of a uint4 map element 
   void LogMapElement( std::ostream & aStreamRef, const std::string & aMapElementName, const uint4 & anIndex );
    /// Log the hex name of a uint4 map element 
   void LogHexMapElement( std::ostream & aStreamRef, const std::string & aMapElementName, const uint4 & anIndex );
    /// Log the name of a string map element
   void LogMapElement( std::ostream & aStreamRef, const std::string & aMapElementName, const std::string & anIndex );

    /// Log the Null Value
   void LogNull( std::ostream & aStreamRef ) const;

    /// Log an uint1 Value
   void LogDecValue( std::ostream & aStreamRef, const uint1 & aValue ) const;
    /// Log an uint2 Value
   void LogDecValue( std::ostream & aStreamRef, const uint2 & aValue ) const;
    /// Log an uint4 Value
   void LogDecValue( std::ostream & aStreamRef, const uint4 & aValue ) const;
    /// Log a char Value
   void LogDecValue( std::ostream & aStreamRef, const char & aValue ) const;
    /// Log a int Value
   void LogDecValue( std::ostream & aStreamRef, const int & aValue ) const;
    /// Log a long Value
   void LogDecValue( std::ostream & aStreamRef, const long & aValue ) const;
    /// Log a long long Value
   void LogDecValue( std::ostream & aStreamRef, const long long & aValue ) const;
    /// Log a bool Value
   void LogDecValue( std::ostream & aStreamRef, const bool  & aValue ) const;
    /// Log a string Value
   void LogStringValue( std::ostream & aStreamRef, const std::string & aValue ) const;
    /// Log a string Value
   void LogDecValue( std::ostream & aStreamRef, const std::string & aValue ) const;
    /// Log an void * Value
   void LogDecValue( std::ostream & aStreamRef, void * const aValue ) const;
    /// Log an float Value
   void LogDecValue( std::ostream & aStreamRef, const float & aValue ) const;
    /// Log an double Value
   void LogDecValue( std::ostream & aStreamRef, const double & aValue ) const;

    /// Log an uint1 Value in hex
   void LogHexValue( std::ostream & aStreamRef, const uint1 & aValue ) const;
    /// Log an uint2 Value in hex
   void LogHexValue( std::ostream & aStreamRef, const uint2 & aValue ) const;
    /// Log an uint4 Value in hex
   void LogHexValue( std::ostream & aStreamRef, const uint4 & aValue ) const;
    /// Log an void * Value in hex
   void LogHexValue( std::ostream & aStreamRef, void * const aValue ) const;

   /// Dump a uint1 Buffer
   void DumpBuffer( std::ostream & aStreamRef, const uint1 * aBufferPtr, const uint2 & aSize );

//@}

private:
 
   /// Write content into buffer
        bool WriteToBuffer( uint1 * buffer
                          , uint2 aBufferSize
                          , uint2 & aByteOffset ) const;
   /// Read content from buffer
        bool ReadFromBuffer( const uint1 * buffer
                           , uint2 aBufferSize
                           , uint2 & aByteOffset );

   //   All the Elements

	std::string itsBeginFieldSeparator;
         uint2 itsCurrentDepth;
	 std::string itsFieldSeparator;
         uint2 itsIndent;
	 std::string itsIndentSpaces;
	 std::string itsFinalSpaces;
         uint2 itsMaxDepth;
	 std::string itsMiddleFieldSeparator;
         uint2 itsMode;

         bool itsFirstOccurence;

}; // End of class LogFormat

//------------------------------ Inline Functions ----------------------
inline bool LogFormat::operator == (const LogFormat & aRef) const
{
   if ( itsBeginFieldSeparator != aRef.itsBeginFieldSeparator ) return false;
   if ( itsFieldSeparator != aRef.itsFieldSeparator ) return false;
   if ( itsCurrentDepth != aRef.itsCurrentDepth ) return false;
   if ( itsIndent != aRef.itsIndent ) return false;
   if ( itsIndentSpaces != aRef.itsIndentSpaces ) return false;
   if ( itsFinalSpaces != aRef.itsFinalSpaces ) return false;
   if ( itsMaxDepth != aRef.itsMaxDepth ) return false;
   if ( itsMiddleFieldSeparator != aRef.itsMiddleFieldSeparator ) return false;
   if ( itsMode != aRef.itsMode ) return false;

   return true;
}

inline bool LogFormat::operator < (const LogFormat & aRef) const
{
   if ( itsBeginFieldSeparator >= aRef.itsBeginFieldSeparator ) return false;
   if ( itsFieldSeparator >= aRef.itsFieldSeparator ) return false;
   if ( itsCurrentDepth >= aRef.itsCurrentDepth ) return false;
   if ( itsIndent >= aRef.itsIndent ) return false;
   if ( itsIndentSpaces >= aRef.itsIndentSpaces ) return false;
   if ( itsFinalSpaces >= aRef.itsFinalSpaces ) return false;
   if ( itsMaxDepth >= aRef.itsMaxDepth ) return false;
   if ( itsMiddleFieldSeparator >= aRef.itsMiddleFieldSeparator ) return false;
   if ( itsMode >= aRef.itsMode ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, LogFormat & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline std::string LogFormat::GetBeginFieldSeparator( ) const
{
 return itsBeginFieldSeparator;
}

inline void LogFormat::SetBeginFieldSeparator( std::string aValue )
{
 itsBeginFieldSeparator = aValue;
}

inline std::string LogFormat::GetFieldSeparator( ) const
{
 return itsFieldSeparator;
}

inline void LogFormat::SetFieldSeparator( std::string aValue )
{
 itsFieldSeparator = aValue;
}

inline uint2 LogFormat::GetCurrentDepth( ) const
{
 return itsCurrentDepth;
}

inline void LogFormat::SetCurrentDepth( uint2 aValue )
{
 itsCurrentDepth = aValue;
}
inline uint2 LogFormat::GetIndent( ) const
{
 return itsIndent;
}

inline void LogFormat::SetIndent( uint2 aValue )
{
 itsIndent = aValue;
}
inline std::string LogFormat::GetIndentSpaces( ) const
{
 return itsIndentSpaces;
}

inline void LogFormat::SetIndentSpaces(std::string aValue )
{
 itsIndentSpaces = aValue;
}
inline std::string LogFormat::GetFinalSpaces( ) const
{
 return itsFinalSpaces;
}

inline void LogFormat::SetFinalSpaces(std::string aValue )
{
 itsFinalSpaces = aValue;
}

inline uint2 LogFormat::GetMaxDepth( ) const
{
 return itsMaxDepth;
}

inline void LogFormat::SetMaxDepth( uint2 aValue )
{
 itsMaxDepth = aValue;
}
inline std::string LogFormat::GetMiddleFieldSeparator( ) const
{
 return itsMiddleFieldSeparator;
}

inline void LogFormat::SetMiddleFieldSeparator( std::string aValue )
{
 itsMiddleFieldSeparator = aValue;
}
inline uint2 LogFormat::GetMode( ) const
{
 return itsMode;
}

inline void LogFormat::SetMode( uint2 aValue )
{
 itsMode = aValue;
}


}; // End of namespace Common

#endif

