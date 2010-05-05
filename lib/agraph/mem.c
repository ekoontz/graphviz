/* $Id: mem.c,v 1.3 2006/07/08 21:09:37 ellson Exp $ $Revision: 1.3 $ */
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

/* memory management discipline and entry points */

#if (HAVE_AST || HAVE_VMALLOC)

	/* vmalloc based allocator */
static void *memopen(void)
{
#if DEBUG || MEMDEBUG
    return vmopen(Vmdcheap, Vmdebug,
		  VM_MTDEBUG | VM_DBCHECK | VM_DBABORT | VM_TRACE);
#else
    return vmopen(Vmdcheap, Vmbest, VM_MTBEST);
#endif
}

static void *memalloc(void *heap, size_t request)
{
    void *rv;
    rv = vmalloc((Vmalloc_t *) heap, request);
    memset(rv, 0, request);
    return rv;
}

static void *memresize(void *heap, void *ptr, size_t oldsize,
		       size_t request)
{
    void *rv;

    rv = vmresize((Vmalloc_t *) heap, ptr, request, VM_RSCOPY | VM_RSZERO);
    return rv;
}

static void memfree(void *heap, void *ptr)
{
    vmfree((Vmalloc_t *) heap, ptr);
}

static void memclose(void *heap)
{
    vmclose((Vmalloc_t *) heap);
}

Agmemdisc_t AgMemDisc =
    { memopen, memalloc, memresize, memfree, memclose };

#else

	/* malloc based allocator */

static void *memopen(void)
{
    return NIL(void *);
}

static void *memalloc(void *heap, size_t request)
{
    void *rv;

    NOTUSED(heap);
    rv = malloc(request);
    memset(rv, 0, request);
    return rv;
}

static void *memresize(void *heap, void *ptr, size_t oldsize,
		       size_t request)
{
    void *rv;

    NOTUSED(heap);
    rv = realloc(ptr, request);
    if (request > oldsize)
	memset((char *) rv + oldsize, 0, request - oldsize);
    return rv;
}

static void memfree(void *heap, void *ptr)
{
    NOTUSED(heap);
    free(ptr);
}

#ifndef WRONG
#define memclose 0
#else
static void memclose(void *heap)
{
    NOTUSED(heap);
}
#endif

Agmemdisc_t AgMemDisc =
    { memopen, memalloc, memresize, memfree, memclose };

#endif


void *agalloc(Agraph_t * g, size_t size)
{
    void *mem;

    mem = AGDISC(g, mem)->alloc(AGCLOS(g, mem), size);
    if (mem == NIL(void *))
	 agerror(AGERROR_MEMORY, "");
    return mem;
}

void *agrealloc(Agraph_t * g, void *ptr, size_t oldsize, size_t size)
{
    void *mem;

    if (size > 0) {
	if (ptr == 0)
	    mem = agalloc(g, size);
	else
	    mem =
		AGDISC(g, mem)->resize(AGCLOS(g, mem), ptr, oldsize, size);
	if (mem == NIL(void *))
	     agerror(AGERROR_MEMORY, "");
    } else
	mem = NIL(void *);
    return mem;
}

void agfree(Agraph_t * g, void *ptr)
{
    if (ptr)
	(AGDISC(g, mem)->free) (AGCLOS(g, mem), ptr);
}

#ifndef _VMALLOC_H
struct _vmalloc_s {
    char unused;
};
#endif
struct _vmalloc_s *agheap(Agraph_t * g)
{
    return AGCLOS(g, mem);
}
