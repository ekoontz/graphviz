/* $Id: tester.c,v 1.2 2006/07/08 17:33:49 ellson Exp $ $Revision: 1.2 $ */
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


#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include "agraph.h"

#define NILgraph			NIL(Agraph_t*)
#define NILnode				NIL(Agnode_t*)
#define NILedge				NIL(Agedge_t*)
#define NILsym				NIL(Agsym_t*)
#define NILstr				NIL(char*)

main()
{
    Agraph_t *g;
    Agnode_t *n;
    Agedge_t *e;
    Agsym_t *sym;
    char *val;

    while (g = agread(stdin, NIL(Agdisc_t *))) {
	for (n = agfstnode(g); n; n = agnxtnode(n)) {
	    /*fprintf(stderr,"%s\n", agnameof(n)); */
	    for (sym = agnxtattr(g, AGNODE, 0); sym;
		 sym = agnxtattr(g, AGNODE, sym)) {
		val = agxget(n, sym);
		/*fprintf(stderr,"\t%s=%s\n",sym->name,val); */
	    }
	}
	agwrite(g, stdout);
    }
}
