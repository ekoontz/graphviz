/* $Id: flatten.c,v 1.4 2008/04/23 18:21:41 ellson Exp $ $Revision: 1.4 $ */
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


#include "aghdr.h"

void agflatten_elist(Dict_t * d, Dtlink_t ** lptr)
{
    dtrestore(d, *lptr);
    (void) dtflatten(d);
    *lptr = dtextract(d);
}

void agflatten_edges(Agraph_t * g, Agnode_t * n)
{

    union {
    	Dtlink_t **dtlink;
    	Agedge_t **agedge;
	} out, in;

    out.agedge = & (n->out);
    in.agedge = & (n->in);
    agflatten_elist(g->e_seq, out.dtlink);
    agflatten_elist(g->e_seq, in.dtlink);

}

void agflatten(Agraph_t * g, int flag)
{
    Agnode_t *n;

    if (flag) {
	if (g->desc.flatlock == FALSE) {
	    dtflatten(g->n_seq);
	    g->desc.flatlock = TRUE;
	    for (n = agfstnode(g); n; n = agnxtnode(n))
		agflatten_edges(g, n);
	}
    } else {
	if (g->desc.flatlock) {
	    g->desc.flatlock = FALSE;
	}
    }
}

void agnotflat(Agraph_t * g)
{
    if (g->desc.flatlock)
	agerror(AGERROR_FLAT, "");
}
