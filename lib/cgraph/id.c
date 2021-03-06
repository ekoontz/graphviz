/* $Id: id.c,v 1.2 2007/11/08 21:41:21 erg Exp $ $Revision: 1.2 $ */
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

#include <stdio.h>
#include <cghdr.h>

/* a default ID allocator that works off the shared string lib */

static void *idopen(Agraph_t * g)
{
    return g;
}

static long idmap(void *state, int objtype, char *str, unsigned long *id,
		  int createflag)
{
    char *s;
    static unsigned long ctr = 1;

    NOTUSED(objtype);
    if (str) {
	Agraph_t *g;
	g = state;
	if (createflag)
	    s = agstrdup(g, str);
	else
	    s = agstrbind(g, str);
	*id = (unsigned long) s;
    } else {
	*id = ctr;
	ctr += 2;
    }
    return TRUE;
}

	/* we don't allow users to explicitly set IDs, either */
static long idalloc(void *state, int objtype, unsigned long request)
{
    NOTUSED(state);
    NOTUSED(objtype);
    NOTUSED(request);
    return FALSE;
}

static void idfree(void *state, int objtype, unsigned long id)
{
    NOTUSED(objtype);
    if (id % 2 == 0)
	agstrfree((Agraph_t *) state, (char *) id);
}

static char *idprint(void *state, int objtype, unsigned long id)
{
    NOTUSED(state);
    NOTUSED(objtype);
    if (id % 2 == 0)
	return (char *) id;
    else
	return NILstr;
}

static void idclose(void *state)
{
    NOTUSED(state);
}

Agiddisc_t AgIdDisc = {
    idopen,
    idmap,
    idalloc,
    idfree,
    idprint,
    idclose
};

/* aux functions incl. support for disciplines with anonymous IDs */

int agmapnametoid(Agraph_t * g, int objtype, char *str,
		  unsigned long *result, int createflag)
{
    int rv;

    if (str && (str[0] != LOCALNAMEPREFIX)) {
	rv = AGDISC(g, id)->map(AGCLOS(g, id), objtype, str, result,
				createflag);
	if (rv)
	    return rv;
    }

    /* either an internal ID, or disc. can't map strings */
    if (str) {
	rv = aginternalmaplookup(g, objtype, str, result);
	if (rv)
	    return rv;
    } else
	rv = 0;

    if (createflag) {
	/* get a new anonymous ID, and store in the internal map */
	rv = AGDISC(g, id)->map(AGCLOS(g, id), objtype, NILstr, result,
				createflag);
	if (rv && str)
	    aginternalmapinsert(g, objtype, str, *result);
    }
    return rv;
}

int agallocid(Agraph_t * g, int objtype, unsigned long request)
{
    return AGDISC(g, id)->alloc(AGCLOS(g, id), objtype, request);
}

void agfreeid(Agraph_t * g, int objtype, unsigned long id)
{
    (void) aginternalmapdelete(g, objtype, id);
    (AGDISC(g, id)->free) (AGCLOS(g, id), objtype, id);
}

/* agnameof:
 * Return string representation of object.
 * In general, returns the name of node or graph,
 * and the key of an edge. If edge is anonymous, returns NULL.
 * Uses static buffer for anonymous graphs.
 */
char *agnameof(void *obj)
{
    Agraph_t *g;
    char *rv;
    static char buf[32];

    /* perform internal lookup first */
    g = agraphof(obj);
    if ((rv = aginternalmapprint(g, AGTYPE(obj), AGID(obj))))
	return rv;

    if (AGDISC(g, id)->print) {
	if ((rv =
	     AGDISC(g, id)->print(AGCLOS(g, id), AGTYPE(obj), AGID(obj))))
	    return rv;
    }
    if (AGTYPE(obj) != AGEDGE) {
	sprintf(buf, "%c%ld", LOCALNAMEPREFIX, AGID(obj));
	rv = buf;
    }
    else
	rv = 0;
    return rv;
}
