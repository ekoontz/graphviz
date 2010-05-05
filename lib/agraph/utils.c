/* $Id: utils.c,v 1.2 2006/07/08 17:33:49 ellson Exp $ $Revision: 1.2 $ */
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

static Agraph_t *Ag_dictop_G;

/* only indirect call through dtopen() is expected */
void *agdictobjmem(Dict_t * dict, Void_t * p, size_t size, Dtdisc_t * disc)
{
    Agraph_t *g;

    NOTUSED(dict);
    NOTUSED(disc);
    g = Ag_dictop_G;
    if (g) {
	if (p)
	    agfree(g, p);
	else
	    return agalloc(g, size);
    } else {
	if (p)
	    free(p);
	else
	    return malloc(size);
    }
    return NIL(void *);
}

void agdictobjfree(Dict_t * dict, Void_t * p, Dtdisc_t * disc)
{
    Agraph_t *g;

    NOTUSED(dict);
    NOTUSED(disc);
    g = Ag_dictop_G;
    if (g)
	agfree(g, p);
    else
	free(p);
}

Dict_t *agdtopen(Agraph_t * g, Dtdisc_t * disc, Dtmethod_t * method)
{
    Dtmemory_f memf;
    Dict_t *d;

    memf = disc->memoryf;
    disc->memoryf = agdictobjmem;
    Ag_dictop_G = g;
    d = dtopen(disc, method);
    disc->memoryf = memf;
    return d;
}

long agdtdelete(Agraph_t * g, Dict_t * dict, void *obj)
{
    Ag_dictop_G = g;
    return (long) dtdelete(dict, obj);
}

int agobjfinalize(Void_t * obj)
{
    agfree(Ag_dictop_G, obj);
    return 0;
}

void agdtclose(Agraph_t * g, Dict_t * dict)
{
    Dtmemory_f memf;
    Dtdisc_t *disc;

    disc = dtdisc(dict, NIL(Dtdisc_t *), 0);
    memf = disc->memoryf;
    disc->memoryf = agdictobjmem;
    Ag_dictop_G = g;
    if (dtclose(dict))
	abort();
    disc->memoryf = memf;
}

void agdtdisc(Agraph_t * g, Dict_t * dict, Dtdisc_t * disc)
{
    if (disc && (dtdisc(dict, NIL(Dtdisc_t *), 0) != disc)) {
	agflatten(g, FALSE);
	dtdisc(dict, disc, 0);
    }
    /* else unchanged, disc is same as old disc */
}
