/* $Id: tri.h,v 1.1.1.1 2004/12/23 04:04:04 ellson Exp $ $Revision: 1.1.1.1 $ */
/* vim:set shiftwidth=4 ts=8: */

/**********************************************************
*      This software is part of the graphviz package      *
*                http://www.graphviz.org/                 *
*                                                         *
*            Copyright (c) 1994-2004 AT&T Corp.           *
*                and is licensed under the                *
*            Common Public License, Version 1.0           *
*                      by AT&T Corp.                      *
*                                                         *
*        Information and Software Systems Research        *
*              AT&T Research, Florham Park NJ             *
**********************************************************/

#ifdef __cplusplus
extern "C" {
#endif


#include <pathgeom.h>
    void Ptriangulate(Ppoly_t * polygon,
		      void (*fn) (void *closure, Ppoint_t tri[]),
		      void *vc);

#ifdef __cplusplus
}
#endif
