///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Viridis
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class Viridis 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Nov 26 18:34:32 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "ColorMap_Viridis.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace ColorMap;


//colormap, created with octave
//v=viridis;
//for i=1:64
//printf("{%f,%f,%f},\n",v(i,1),v(i,2),v(i,3))
//endfor

static const float colormap [][3] = {
					{0.267004,0.004874,0.329415},
					{0.272652,0.025846,0.353367},
					{0.277106,0.050914,0.376236},
					{0.280356,0.074201,0.397901},
					{0.282390,0.095954,0.418251},
					{0.283205,0.116893,0.437179},
					{0.282809,0.137350,0.454596},
					{0.281231,0.157480,0.470434},
					{0.278516,0.177348,0.484654},
					{0.274736,0.196969,0.497250},
					{0.269982,0.216330,0.508255},
					{0.264369,0.235405,0.517732},
					{0.258026,0.254162,0.525780},
					{0.251099,0.272573,0.532522},
					{0.243733,0.290620,0.538097},
					{0.236073,0.308291,0.542652},
					{0.228263,0.325586,0.546335},
					{0.220425,0.342517,0.549287},
					{0.212667,0.359102,0.551635},
					{0.205079,0.375366,0.553493},
					{0.197722,0.391341,0.554953},
					{0.190631,0.407061,0.556089},
					{0.183819,0.422564,0.556952},
					{0.177272,0.437886,0.557576},
					{0.170958,0.453063,0.557974},
					{0.164833,0.468130,0.558143},
					{0.158845,0.483117,0.558059},
					{0.152951,0.498053,0.557685},
					{0.147132,0.512959,0.556973},
					{0.141402,0.527854,0.555864},
					{0.135833,0.542750,0.554289},
					{0.130582,0.557652,0.552176},
					{0.125898,0.572563,0.549445},
					{0.122163,0.587476,0.546023},
					{0.119872,0.602382,0.541831},
					{0.119627,0.617266,0.536796},
					{0.122046,0.632107,0.530848},
					{0.127668,0.646882,0.523924},
					{0.136835,0.661563,0.515967},
					{0.149643,0.676120,0.506924},
					{0.165967,0.690519,0.496752},
					{0.185538,0.704725,0.485412},
					{0.208030,0.718701,0.472873},
					{0.233127,0.732406,0.459106},
					{0.260531,0.745802,0.444096},
					{0.290001,0.758846,0.427826},
					{0.321330,0.771498,0.410293},
					{0.354355,0.783714,0.391488},
					{0.388930,0.795453,0.371421},
					{0.424933,0.806674,0.350099},
					{0.462247,0.817338,0.327545},
					{0.500754,0.827409,0.303799},
					{0.540337,0.836858,0.278917},
					{0.580861,0.845663,0.253001},
					{0.622171,0.853816,0.226224},
					{0.664087,0.861321,0.198879},
					{0.706404,0.868206,0.171495},
					{0.748885,0.874522,0.145038},
					{0.791273,0.880346,0.121291},
					{0.833302,0.885780,0.103326},
					{0.874718,0.890945,0.095351},
					{0.915296,0.895973,0.100470},
					{0.954840,0.901006,0.117876},
					{0.993248,0.906157,0.143936}
                                    };


//------------------------------ Constructor -------------------

Viridis::Viridis ( ) 
: Mat2D::VirtualMat<float>()

{
  /// nothing
}
Viridis::Viridis ( const uint2 & N ) 
: Mat2D::VirtualMat<float>(3,N)

{

  assert(N>1 && "Viridis: N must be >1");  

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

Viridis::~Viridis (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

//------------------------------ Logging ------------------------------
void Viridis::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void Viridis::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "ColorMap_Viridis" );
    itsIdx.LogMat(aStreamRef, aLogFormat);
   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
