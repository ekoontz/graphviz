/* $Id: memory.c,v 1.3 2005/10/18 21:06:26 ellson Exp $ $Revision: 1.3 $ */
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <string.h>
#include "memory.h"

void *zmalloc(size_t nbytes)
{
    char *rv;
    if (nbytes == 0)
	return 0;
    rv = gmalloc(nbytes);
    memset(rv, 0, nbytes);
    return rv;
}

void *zrealloc(void *ptr, size_t size, size_t elt, size_t osize)
{
    void *p = realloc(ptr, size * elt);
    if (p == NULL && size) {
	fprintf(stderr, "out of memory\n");
	abort();
    }
    if (osize < size)
	memset((char *) p + (osize * elt), '\0', (size - osize) * elt);
    return p;
}

void *gmalloc(size_t nbytes)
{
    char *rv;
    if (nbytes == 0)
	return NULL;
    rv = malloc(nbytes);
    if (rv == NULL) {
	fprintf(stderr, "out of memory\n");
	abort();
    }
    return rv;
}

void *grealloc(void *ptr, size_t size)
{
    void *p = realloc(ptr, size);
    if (p == NULL && size) {
	fprintf(stderr, "out of memory\n");
	abort();
    }
    return p;
}
