/* $Id: heap.h,v 1.2 2005/02/24 00:57:33 ellson Exp $ $Revision: 1.2 $ */
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



#ifndef HEAP_H
#define HEAP_H

#include "hedges.h"

    extern void PQinitialize(void);
    extern void PQcleanup(void);
    extern Halfedge *PQextractmin(void);
    extern Point PQ_min(void);
    extern int PQempty(void);
    extern void PQdelete(Halfedge *);
    extern void PQinsert(Halfedge *, Site *, double);

#endif

#ifdef __cplusplus
}
#endif
