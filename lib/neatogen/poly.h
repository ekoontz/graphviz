/* $Id: poly.h,v 1.3 2008/04/08 21:34:51 erg Exp $ $Revision: 1.3 $ */
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

#ifndef POLY_H
#define POLY_H

#include "geometry.h"

    typedef struct {
	Point origin;
	Point corner;
	int nverts;
	Point *verts;
	int kind;
    } Poly;

    extern void polyFree(void);
    extern int polyOverlap(Point, Poly *, Point, Poly *);
    extern void makePoly(Poly *, Agnode_t *, float, float);
    extern void makeAddPoly(Poly *, Agnode_t *, float, float);
    extern void breakPoly(Poly *);

#endif

#ifdef __cplusplus
}
#endif
