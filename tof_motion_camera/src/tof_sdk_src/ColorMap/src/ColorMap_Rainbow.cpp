///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Rainbow
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class Rainbow 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Nov 26 00:41:38 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "ColorMap_Rainbow.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace ColorMap;


//colormap, created with octave
//r=rainbow;
//for i=1:64
//printf("{%f,%f,%f},\n",r(i,1),r(i,2),r(i,3))
//endfor

static const float colormap [][3] = {
					{1.000000,0.000000,0.000000},
					{1.000000,0.039683,0.000000},
					{1.000000,0.079365,0.000000},
					{1.000000,0.119048,0.000000},
					{1.000000,0.158730,0.000000},
					{1.000000,0.198413,0.000000},
					{1.000000,0.238095,0.000000},
					{1.000000,0.277778,0.000000},
					{1.000000,0.317460,0.000000},
					{1.000000,0.357143,0.000000},
					{1.000000,0.396825,0.000000},
					{1.000000,0.436508,0.000000},
					{1.000000,0.476190,0.000000},
					{1.000000,0.515873,0.000000},
					{1.000000,0.555556,0.000000},
					{1.000000,0.595238,0.000000},
					{1.000000,0.634921,0.000000},
					{1.000000,0.674603,0.000000},
					{1.000000,0.714286,0.000000},
					{1.000000,0.753968,0.000000},
					{1.000000,0.793651,0.000000},
					{1.000000,0.833333,0.000000},
					{1.000000,0.873016,0.000000},
					{1.000000,0.912698,0.000000},
					{1.000000,0.952381,0.000000},
					{1.000000,0.992063,0.000000},
					{0.936508,1.000000,0.000000},
					{0.857143,1.000000,0.000000},
					{0.777778,1.000000,0.000000},
					{0.698413,1.000000,0.000000},
					{0.619048,1.000000,0.000000},
					{0.539683,1.000000,0.000000},
					{0.460317,1.000000,0.000000},
					{0.380952,1.000000,0.000000},
					{0.301587,1.000000,0.000000},
					{0.222222,1.000000,0.000000},
					{0.142857,1.000000,0.000000},
					{0.063492,1.000000,0.000000},
					{0.000000,0.984127,0.015873},
					{0.000000,0.904762,0.095238},
					{0.000000,0.825397,0.174603},
					{0.000000,0.746032,0.253968},
					{0.000000,0.666667,0.333333},
					{0.000000,0.587302,0.412698},
					{0.000000,0.507937,0.492063},
					{0.000000,0.428571,0.571429},
					{0.000000,0.349206,0.650794},
					{0.000000,0.269841,0.730159},
					{0.000000,0.190476,0.809524},
					{0.000000,0.111111,0.888889},
					{0.000000,0.031746,0.968254},
					{0.031746,0.000000,1.000000},
					{0.084656,0.000000,1.000000},
					{0.137566,0.000000,1.000000},
					{0.190476,0.000000,1.000000},
					{0.243386,0.000000,1.000000},
					{0.296296,0.000000,1.000000},
					{0.349206,0.000000,1.000000},
					{0.402116,0.000000,1.000000},
					{0.455026,0.000000,1.000000},
					{0.507937,0.000000,1.000000},
					{0.560847,0.000000,1.000000},
					{0.613757,0.000000,1.000000},
					{0.666667,0.000000,1.000000}
                                    };


//------------------------------ Constructor -------------------

Rainbow::Rainbow ( ) 
: Mat2D::VirtualMat<float>()

{
  /// nothing
}

Rainbow::Rainbow ( const uint2 & N ) 
: Mat2D::VirtualMat<float>(3,N)

{

  assert(N>1 && "Rainbow: N must be >1");  

  for (uint2 y = 0; y < N; ++y)
  {

            uint2 tmpValue = y;
            //color table interpolation and lookup
            uint4 rgb = 63.0 * tmpValue / (N-1);
            float res   = 63.0 * tmpValue / (N-1) - rgb;
            rgb = rgb % 64;
            uint4 rgb1 = rgb +1;
            if (rgb1>63) rgb1 = 63;

            float kr = res * (colormap[rgb1][0] - colormap[rgb][0]) + colormap[rgb][0];  //interpolation of red value
            float kg = res * (colormap[rgb1][1] - colormap[rgb][1]) + colormap[rgb][1];  //interpolation of green value
            float kb = res * (colormap[rgb1][2] - colormap[rgb][2]) + colormap[rgb][2];  //interpolation of blue value

            itsIdx(0,y) = kr;
            itsIdx(1,y) = kg;
            itsIdx(2,y) = kb;
    } //for

}




//------------------------------ Destructor ----------------------------

Rainbow::~Rainbow (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

//------------------------------ Logging ------------------------------
void Rainbow::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void Rainbow::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "ColorMap_Rainbow" );
    itsIdx.LogMat(aStreamRef, aLogFormat);
   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
