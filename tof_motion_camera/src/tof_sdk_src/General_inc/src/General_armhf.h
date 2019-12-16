/***********************************************************************
 *
 *     PROJECT: cpp 
 *   COPYRIGHT: Robert Hranitzky 
 *    $RCSfile$
 *   $Revision: 3772 $
 *      AUTHOR: Robert Hranitzky 
 *    LANGUAGE: C++
 * DESCRIPTION: architecture specific general definitions for armhf.
 *
 ************************************************************************/

#ifndef _GENERAL_ARMHF_H_
#define _GENERAL_ARMHF_H_

#ifdef USE_IDENT
# ident "$Id:"
#endif


/* this is valid only for armhf building */
#ifdef _TARGET_ARCH_ARMHF_


/*------------------------------ Pragmas -------------------------------*/

/* currently no x86-hostsim specific pragmas necessary */


/*----------------------------- Constants ------------------------------*/


/*------------------------ Macros and Definitions ----------------------*/


/*------------------------------ Types ---------------------------------*/

/*
 * artificial types. they shall be defined architecture/compiler specific in
 * order to meet the defined storage sizes.
 */
typedef unsigned char  uint1;          /* must be 1 byte unsigned */
typedef unsigned short uint2;          /* must be 2 byte unsigned */
typedef unsigned int   uint4;          /* must be 4 byte unsigned */
typedef unsigned long int   uint8;     /* must be 8 byte unsigned */

typedef signed char    sint1;          /* must be 1 byte signed */
typedef short          sint2;          /* must be 2 byte signed */
typedef int            sint4;          /* must be 4 byte signed */
typedef long int       sint8;          /* must be 4 byte signed */

#endif  /* _TARGET_ARCH_ARMHF_ */

#endif  /* ! _GENERAL_ARMHF_ */

/* End of file */
