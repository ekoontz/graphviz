/* $Id: bfs.c,v 1.3 2006/12/07 22:49:36 erg Exp $ $Revision: 1.3 $ */
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


/******************************************

	Breadth First Search
	Computes single-source distances for
	unweighted graphs

******************************************/

#include "bfs.h"
#include <stdlib.h>
/* #include <math.h> */

void bfs(int vertex, vtx_data * graph, int n, DistType * dist, Queue * Q)
 /* compute vector 'dist' of distances of all nodes from 'vertex' */
{
    int i;
    int closestVertex, neighbor;
    DistType closestDist = INT_MAX;

    /* initial distances with edge weights: */
    for (i = 0; i < n; i++)
	dist[i] = -1;
    dist[vertex] = 0;

    initQueue(Q, vertex);

    if (graph[0].ewgts == NULL) {
	while (deQueue(Q, &closestVertex)) {
	    closestDist = dist[closestVertex];
	    for (i = 1; i < graph[closestVertex].nedges; i++) {
		neighbor = graph[closestVertex].edges[i];
		if (dist[neighbor] < -0.5) {	/* first time to reach neighbor */
		    dist[neighbor] = closestDist + 1;
		    enQueue(Q, neighbor);
		}
	    }
	}
    } else {
	while (deQueue(Q, &closestVertex)) {
	    closestDist = dist[closestVertex];
	    for (i = 1; i < graph[closestVertex].nedges; i++) {
		neighbor = graph[closestVertex].edges[i];
		if (dist[neighbor] < -0.5) {	/* first time to reach neighbor */
		    dist[neighbor] =
			closestDist +
			(DistType) graph[closestVertex].ewgts[i];
		    enQueue(Q, neighbor);
		}
	    }
	}
    }

    /* For dealing with disconnected graphs: */
    for (i = 0; i < n; i++)
	if (dist[i] < -0.5)	/* 'i' is not connected to 'vertex' */
	    dist[i] = closestDist + 10;
}

int
bfs_bounded(int vertex, vtx_data * graph, int n, DistType * dist,
	    Queue * Q, int bound, int *visited_nodes)
 /* compute vector 'dist' of distances of all nodes  from 'vertex' */
 /* ignore nodes whose distance to 'vertex' is more than bound */
{
    /* we assume here, that all distances are initialized with -1 !!!! */

    int i;
    int num_visit;
    int closestVertex, neighbor;
    DistType closestDist;
    /* initialize distances with edge weights: */
    /* for (i=0; i<n; i++)  */
    /* dist[i]=-1; */

    dist[vertex] = 0;

    initQueue(Q, vertex);

    num_visit = 0;
    while (deQueue(Q, &closestVertex)) {
	closestDist = dist[closestVertex];
	if (closestDist > bound) {
	    dist[closestVertex] = -1;
	    break;
	} else {
	    visited_nodes[num_visit++] = closestVertex;
	}
	for (i = 1; i < graph[closestVertex].nedges; i++) {
	    neighbor = graph[closestVertex].edges[i];
	    if (dist[neighbor] < -0.5) {	/* first time to reach neighbor */
		dist[neighbor] = closestDist + 1;
		enQueue(Q, neighbor);
	    }
	}
    }

    /* set distances of all nodes in Queue to -1 */
    /* for next run */
    while (deQueue(Q, &closestVertex)) {
	dist[closestVertex] = -1;
    }
    dist[vertex] = -1;
    return num_visit;
}

#ifndef __cplusplus

void mkQueue(Queue * qp, int size)
{
    qp->data = N_GNEW(size, int);
    qp->queueSize = size;
    qp->start = qp->end = 0;
}

Queue *newQueue(int size)
{
    Queue *qp = GNEW(Queue);
    mkQueue(qp, size);
    return qp;
}

void freeQueue(Queue * qp)
{
    free(qp->data);
}

void delQueue(Queue * qp)
{
    free(qp->data);
    free(qp);
}

void initQueue(Queue * qp, int startVertex)
{
    qp->data[0] = startVertex;
    qp->start = 0;
    qp->end = 1;
}

boolean deQueue(Queue * qp, int *vertex)
{
    if (qp->start >= qp->end)
	return FALSE;		/* underflow */
    *vertex = qp->data[qp->start++];
    return TRUE;
}

boolean enQueue(Queue * qp, int vertex)
{
    if (qp->end >= qp->queueSize)
	return FALSE;		/* overflow */
    qp->data[qp->end++] = vertex;
    return TRUE;
}

#endif
