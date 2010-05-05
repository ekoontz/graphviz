/* $Id: gvcolor.c,v 1.6 2008/01/09 20:50:35 erg Exp $ $Revision: 1.6 $ */
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


/*
 * Written by Stephen North
 * Updated by Emden Gansner
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* if NC changes, a bunch of scanf calls below are in trouble */
#define	NC	3		/* size of HSB color vector */

#ifdef USE_CGRAPH
#include <cgraph.h>
#include <stdlib.h>
typedef struct Agnodeinfo_t {
    Agrec_t h;
    double relrank;	/* coordinate of its rank, smaller means lower rank */
    double x[NC];	/* color vector */
} Agnodeinfo_t;

#define ND_relrank(n) (((Agnodeinfo_t*)((n)->base.data))->relrank)
#define ND_x(n) (((Agnodeinfo_t*)((n)->base.data))->x)

#else
typedef struct Agnodeinfo_t {
    double relrank;		/* coordinate of its rank, smaller means lower rank */
    double x[NC];		/* color vector */
} Agnodeinfo_t;

typedef struct Agedgeinfo_t {
    char for_ansi_C;
} Agedgeinfo_t;
typedef struct Agraphinfo_t {
    char for_ansi_C;
} Agraphinfo_t;

#define ND_relrank(n) (n)->u.relrank
#define ND_x(n) (n)->u.x
#define aghead(e) ((e)->head)
#define agtail(e) ((e)->tail)

#include <graph.h>
#endif
#include <ingraphs.h>
#include <stdio.h>
#ifdef HAVE_UNISTD_H
#include	<unistd.h>
#endif

#ifdef HAVE_GETOPT_H
#include <getopt.h>
#else
#include "compat_getopt.h"
#endif

double Defcolor[NC] = { 0.0, 0.0, 1.0 };	/* white */
int Forward = 1;		/* how to propagate colors w.r.t. ranks */
int LR = 0;			/* rank orientation */

int AdjustSaturation;
double MinRankSaturation;
double MaxRankSaturation;

extern char *colorxlate(char *str, char *buf);

static int cmpf(Agnode_t ** n0, Agnode_t ** n1)
{
    double t;
    t = ND_relrank(*n0) - ND_relrank(*n1);
    if (t < 0.0)
	return -1;
    if (t > 0.0)
	return 1;
    return 0;
}

static void setcolor(char *p, double *v)
{
    char buf[64];
    if ((sscanf(p, "%lf %lf %lf", v, v + 1, v + 2) != 3) && p[0]) {
	colorxlate(p, buf);
	sscanf(buf, "%lf %lf %lf", v, v + 1, v + 2);
    }
}

static char **Files;

static char *useString = "Usage: gvcolor [-?] <files>\n\
  -? - print usage\n\
If no files are specified, stdin is used\n";

static void usage(int v)
{
    printf(useString);
    exit(v);
}

static void init(int argc, char *argv[])
{
    int c;

    while ((c = getopt(argc, argv, ":?")) != -1) {
	switch (c) {
	case '?':
	    if (optopt == '?')
		usage(0);
	    else
		fprintf(stderr, "gvcolor: option -%c unrecognized - ignored\n",
			optopt);
	    break;
	}
    }
    argv += optind;
    argc -= optind;

    if (argc)
	Files = argv;
}

static void color(Agraph_t * g)
{
    int nn, i, j, cnt;
    Agnode_t *n, *v, **nlist;
    Agedge_t *e;
    char *p;
    double x, y, maxrank = 0.0;
    double sum[NC], d, lowsat, highsat;

#ifdef USE_CGRAPH
    if (agattr(g, AGNODE, "pos", 0) == NULL) {
#else
    if (agfindattr(g->proto->n, "pos") == NULL) {
#endif
	fprintf(stderr,
		"graph must be run through 'dot' before 'gvcolor'\n");
	exit(1);
    }
#ifdef USE_CGRAPH
    aginit(g, AGNODE, "nodeinfo", sizeof(Agnodeinfo_t), TRUE);
    if (agattr(g, AGNODE, "style", 0) == NULL)
	agattr(g, AGNODE, "style", "filled");
#else
    if (agfindattr(g->proto->n, "style") == NULL)
	agnodeattr(g, "style", "filled");
#endif
    if ((p = agget(g, "Defcolor")))
	setcolor(p, Defcolor);

    if ((p = agget(g, "rankdir")) && (p[0] == 'L'))
	LR = 1;
    if ((p = agget(g, "flow")) && (p[0] == 'b'))
	Forward = 0;
    if ((p = agget(g, "saturation"))) {
	if (sscanf(p, "%lf,%lf", &lowsat, &highsat) == 2) {
	    MinRankSaturation = lowsat;
	    MaxRankSaturation = highsat;
	    AdjustSaturation = 1;
	}
    }

    /* assemble the sorted list of nodes and store the initial colors */
    nn = agnnodes(g);
    nlist = (Agnode_t **) malloc(nn * sizeof(Agnode_t *));
    i = 0;
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	nlist[i++] = n;
	if ((p = agget(n, "color")))
	    setcolor(p, ND_x(n));
	p = agget(n, "pos");
	sscanf(p, "%lf,%lf", &x, &y);
	ND_relrank(n) = (LR ? x : y);
	if (maxrank < ND_relrank(n))
	    maxrank = ND_relrank(n);
    }
    if (LR != Forward)
	for (i = 0; i < nn; i++) {
	    n = nlist[i];
	    ND_relrank(n) = maxrank - ND_relrank(n);
	}
    qsort((void *) nlist, (size_t) nn, sizeof(Agnode_t *),
	  (int (*)(const void *, const void *)) cmpf);

    /* this is the pass that pushes the colors through the edges */
    for (i = 0; i < nn; i++) {
	n = nlist[i];

	/* skip nodes that were manually colored */
	cnt = 0;
	for (j = 0; j < NC; j++)
	    if (ND_x(n)[j] != 0.0)
		cnt++;
	if (cnt > 0)
	    continue;

	for (j = 0; j < NC; j++)
	    sum[j] = 0.0;
	cnt = 0;
	for (e = agfstedge(g, n); e; e = agnxtedge(g, e, n)) {
	    v = aghead(e);
	    if (v == n)
		v = agtail(e);
	    d = ND_relrank(v) - ND_relrank(n) - 0.01;
	    if (d < 0) {
		double t = 0.0;
		for (j = 0; j < NC; j++) {
		    t += ND_x(v)[j];
		    sum[j] += ND_x(v)[j];
		}
		if (t > 0.0)
		    cnt++;
	    }
	}
	if (cnt)
	    for (j = 0; j < NC; j++)
		ND_x(n)[j] = sum[j] / cnt;
    }

    /* apply saturation adjustment and convert color to string */
    for (i = 0; i < nn; i++) {
	double h, s, b, t;
	char buf[64];

	n = nlist[i];

	t = 0.0;
	for (j = 0; j < NC; j++)
	    t += ND_x(n)[j];
	if (t > 0.0) {
	    h = ND_x(n)[0];
	    if (AdjustSaturation) {
		s = ND_relrank(n) / maxrank;
		if (!Forward)
		    s = 1.0 - s;
		s = MinRankSaturation
		    + s * (MaxRankSaturation - MinRankSaturation);
	    } else
		s = 1.0;
	    s = s * ND_x(n)[1];
	    b = ND_x(n)[2];
	} else {
	    h = Defcolor[0];
	    s = Defcolor[1];
	    b = Defcolor[2];
	}
	sprintf(buf, "%f %f %f", h, s, b);
	agset(n, "color", buf);
    }
}

#ifdef USE_CGRAPH
static Agraph_t *gread(FILE * fp)
{
    return agread(fp, (Agdisc_t *) 0);
}
#endif

int main(int argc, char **argv)
{
    Agraph_t *g;
    ingraph_state ig;

    init(argc, argv);
#ifdef USE_CGRAPH
    newIngraph(&ig, Files, gread);
#else
    newIngraph(&ig, Files, agread);
    aginit();
#endif

    while ((g = nextGraph(&ig)) != 0) {
	color(g);
	agwrite(g, stdout);
	fflush(stdout);
	agclose(g);
    }

    exit(0);
}
