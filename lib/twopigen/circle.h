/* $Id: circle.h,v 1.2 2005/07/29 22:59:35 erg Exp $ $Revision: 1.2 $ */
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

#ifndef CIRCLE_H
#define CIRCLE_H

#include "render.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
	int nStepsToLeaf;
	int subtreeSize;
	int nChildren;
	int nStepsToCenter;
	node_t *parent;
	double span;
	double theta;
    } rdata;

#define RDATA(n) ((rdata*)((n)->u.alg))
#define SLEAF(n) (RDATA(n)->nStepsToLeaf)
#define STSIZE(n) (RDATA(n)->subtreeSize)
#define NCHILD(n) (RDATA(n)->nChildren)
#define SCENTER(n) (RDATA(n)->nStepsToCenter)
#define SPARENT(n) (RDATA(n)->parent)
#define SPAN(n) (RDATA(n)->span)
#define THETA(n) (RDATA(n)->theta)

    extern void circleLayout(Agraph_t * sg, Agnode_t * center);
    extern void twopi_layout(Agraph_t * g);
    extern void twopi_cleanup(Agraph_t * g);
    extern void twopi_init_graph(graph_t * g);

#ifdef __cplusplus
}
#endif
#endif
