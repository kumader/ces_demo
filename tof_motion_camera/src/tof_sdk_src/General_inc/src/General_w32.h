/***********************************************************************
 *
 *     PROJECT: cpp 
 *   COPYRIGHT: Robert Hranitzky 
 *    $RCSfile$
 *   $Revision: 2286 $
 *      AUTHOR: Robert Hranitzky 
 *    LANGUAGE: C++
 * DESCRIPTION: architecture specific general definitions for w32.
 *
 ************************************************************************/

#ifndef _GENERAL_W32_H_
#define _GENERAL_W32_H_

#ifdef USE_IDENT
# ident "$Id:"
#endif


/* this is valid only for W32 building */
#ifdef _TARGET_ARCH_W32_


/*------------------------------ Pragmas -------------------------------*/

/* currently no w32 specific pragmas necessary */


/*----------------------------- Constants ------------------------------*/


/*------------------------ Macros and Definitions ----------------------*/


/*------------------------------ Types ---------------------------------*/

/*
 * artificial types. they shall be defined architecture/compiler specific in
 * order to meet the defined storage sizes.
 */
typedef unsigned char  uint1;          /* must be 1 byte unsigned */
typedef unsigned short uint2;          /* must be 2 byte unsigned */
typedef unsigned long  uint4;          /* must be 4 byte unsigned */
typedef unsigned long  uint8;          /* FIXME: must be 8 byte unsigned, but remapped to 4 bytes */

typedef signed char    sint1;          /* must be 1 byte signed */
typedef short          sint2;          /* must be 2 byte signed */
typedef long           sint4;          /* must be 4 byte signed */
typedef long           sint8;          /* FIXME: must be 8 byte signed, but remapped to 4 bytes */    

#endif  /* _TARGET_ARCH_W32_ */

#endif  /* ! _GENERAL_W32_H_ */

/* End of file */
