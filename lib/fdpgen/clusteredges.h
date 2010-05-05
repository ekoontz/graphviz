/* $Id: clusteredges.h,v 1.2 2008/04/08 21:34:51 erg Exp $ $Revision: 1.2 $ */
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

#ifndef CLUSTEREDGES_H
#define CLUSTEREDGES_H

#include <render.h>
#include <adjust.h>

    extern int compoundEdges(graph_t * g, expand_t* pm, int splines);

#endif

#ifdef __cplusplus
}
#endif
