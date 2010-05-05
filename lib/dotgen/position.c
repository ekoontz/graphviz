/* $Id: position.c,v 1.15 2008/04/28 16:48:30 erg Exp $ $Revision: 1.15 $ */
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
 * position(g): set ND_coord_i(n) (x and y) for all nodes n of g, using GD_rank(g).
 * (the graph may be modified by merging certain edges with a common endpoint.)
 * the coordinates are computed by constructing and ranking an auxiliary graph.
 * then leaf nodes are inserted in the fast graph.  cluster boundary nodes are
 * created and correctly separated.
 */

#include "dot.h"

static int nsiter2(graph_t * g);
static void create_aux_edges(graph_t * g);
static void remove_aux_edges(graph_t * g);
static void set_xcoords(graph_t * g);
static void set_ycoords(graph_t * g);
static void set_aspect(graph_t * g);
static void expand_leaves(graph_t * g);
static void make_lrvn(graph_t * g);
static void contain_nodes(graph_t * g);
static boolean idealsize(graph_t * g, double);

#ifdef DEBUG
static void
dumpNS (graph_t * g)
{
    node_t* n = GD_nlist(g);
    elist el;
    edge_t* e;
    int i;

    while (n) {
	el = ND_out(n);
	for (i = 0; i < el.size; i++) {
	    e = el.list[i];
	    fprintf (stderr, "%s(%x) -> %s(%x) : %d\n", e->tail->name,e->tail, e->head->name, e->head,
		ED_minlen(e));
	}
	n = ND_next(n); 
    }
}
#endif

static void
largeMinlen (int l)
{
    agerr (AGERR, "Edge length %d larger than maximum %u allowed.\nCheck for overwide node(s).\n", l, USHRT_MAX); 
    exit (1);
}

/* connectGraph:
 * When source and/or sink nodes are defined, it is possible that
 * after the auxiliary edges are added, the graph may still have 2 or
 * 3 components. To fix this, we put trivial constraints connecting the
 * first items of each rank.
 */
static void
connectGraph (graph_t* g)
{
    int i, j, r, found;
    node_t* tp;
    node_t* hp;
    node_t* sn;
    edge_t* e;
    rank_t* rp;

    for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
	rp = GD_rank(g)+r;
	found =FALSE;
        tp = NULL;
	for (i = 0; i < rp->n; i++) {
	    tp = rp->v[i];
	    if (ND_save_out(tp).list) {
        	for (j = 0; (e = ND_save_out(tp).list[j]); j++) {
		    if ((ND_rank(e->head) > r) || (ND_rank(e->tail) > r)) {
			found = TRUE;
			break;
		    }
        	}
		if (found) break;
	    }
	    if (ND_save_in(tp).list) {
        	for (j = 0; (e = ND_save_in(tp).list[j]); j++) {
		    if ((ND_rank(e->tail) > r) || (ND_rank(e->head) > r)) {
			found = TRUE;
			break;
		    }
        	}
		if (found) break;
	    }
	}
	if (found || !tp) continue;
	tp = rp->v[0];
	if (r < GD_maxrank(g)) hp = (rp+1)->v[0];
	else hp = (rp-1)->v[0];
	assert (hp);
	sn = virtual_node(g);
	ND_node_type(sn) = SLACKNODE;
	make_aux_edge(sn, tp, 0, 0);
	make_aux_edge(sn, hp, 0, 0);
	ND_rank(sn) = MIN(ND_rank(tp), ND_rank(hp));
    }
}

void dot_position(graph_t * g)
{
    if (GD_nlist(g) == NULL)
	return;			/* ignore empty graph */
    mark_lowclusters(g);	/* we could remove from splines.c now */
    set_ycoords(g);
    if (Concentrate)
	dot_concentrate(g);
    expand_leaves(g);
    if (flat_edges(g))
	set_ycoords(g);
    create_aux_edges(g);
    if (rank(g, 2, nsiter2(g))) { /* LR balance == 2 */
	connectGraph (g);
	assert(rank(g, 2, nsiter2(g)) == 0);
    }
    set_xcoords(g);
    set_aspect(g);
    remove_aux_edges(g);	/* must come after set_aspect since we now
				 * use GD_ln and GD_rn for bbox width.
				 */
}

static int nsiter2(graph_t * g)
{
    int maxiter = INT_MAX;
    char *s;

    if ((s = agget(g, "nslimit")))
	maxiter = atof(s) * agnnodes(g);
    return maxiter;
}

static int go(node_t * u, node_t * v)
{
    int i;
    edge_t *e;

    if (u == v)
	return TRUE;
    for (i = 0; (e = ND_out(u).list[i]); i++) {
	if (go(e->head, v))
	    return TRUE;
    }
    return FALSE;
}

static int canreach(node_t * u, node_t * v)
{
    return go(u, v);
}

edge_t *make_aux_edge(node_t * u, node_t * v, int len, int wt)
{
    edge_t *e;

    e = NEW(edge_t);
    e->tail = u;
    e->head = v;
    if (len > USHRT_MAX)
	largeMinlen (len);
    ED_minlen(e) = len;
    ED_weight(e) = wt;
    fast_edge(e);
    return e;
}

static void allocate_aux_edges(graph_t * g)
{
    int i, j, n_in;
    node_t *n;

    /* allocate space for aux edge lists */
    for (n = GD_nlist(g); n; n = ND_next(n)) {
	ND_save_in(n) = ND_in(n);
	ND_save_out(n) = ND_out(n);
	for (i = 0; ND_out(n).list[i]; i++);
	for (j = 0; ND_in(n).list[j]; j++);
	n_in = i + j;
	alloc_elist(n_in + 3, ND_in(n));
	alloc_elist(3, ND_out(n));
    }
}

/* make_LR_constraints:
 */
static void 
make_LR_constraints(graph_t * g)
{
    int i, j, k;
    int sw;			/* self width */
    int m0, m1;
    int width, sep[2];
    int nodesep;      /* separation between nodes on same rank */
    edge_t *e, *e0, *e1, *ff;
    node_t *u, *v, *t0, *h0;
    rank_t *rank = GD_rank(g);

    /* Use smaller separation on odd ranks if g has edge labels */
    if (GD_has_labels(g) & EDGE_LABEL) {
	sep[0] = GD_nodesep(g);
	sep[1] = 5;
    }
    else {
	sep[1] = sep[0] = GD_nodesep(g);
    }
    /* make edges to constrain left-to-right ordering */
    for (i = GD_minrank(g); i <= GD_maxrank(g); i++) {
	int last;
	last = rank[i].v[0]->u.rank = 0;
	nodesep = sep[i & 1];
	for (j = 0; j < rank[i].n; j++) {
	    u = rank[i].v[j];
	    ND_mval(u) = ND_rw_i(u);	/* keep it somewhere safe */
	    if (ND_other(u).size > 0) {	/* compute self size */
		/* FIX: dot assumes all self-edges go to the right. This
                 * is no longer true, though makeSelfEdge still attempts to
                 * put as many as reasonable on the right. The dot code
                 * should be modified to allow a box reflecting the placement
                 * of all self-edges, and use that to reposition the nodes.
                 * Note that this would not only affect left and right
                 * positioning but may also affect interrank spacing.
                 */
		sw = 0;
		for (k = 0; (e = ND_other(u).list[k]); k++) {
		    if (e->tail == e->head) {
			sw += selfRightSpace (e);
		    }
		}
		ND_rw_i(u) += sw;	/* increment to include self edges */
	    }
	    v = rank[i].v[j + 1];
	    if (v) {
		width = ND_rw_i(u) + ND_lw_i(v) + nodesep;
		e0 = make_aux_edge(u, v, width, 0);
		last = (ND_rank(v) = last + width);
	    }

	    /* constraints from labels of flat edges on previous rank */
	    if ((e = (edge_t*)ND_alg(u))) {
		e0 = ND_save_out(u).list[0];
		e1 = ND_save_out(u).list[1];
		if (ND_order(e0->head) > ND_order(e1->head)) {
		    ff = e0;
		    e0 = e1;
		    e1 = ff;
		}
		m0 = (ED_minlen(e) * GD_nodesep(g)) / 2;
		m1 = m0 + ND_rw_i(e0->head) + ND_lw_i(e0->tail);
		/* these guards are needed because the flat edges
		 * work very poorly with cluster layout */
		if (canreach(e0->tail, e0->head) == FALSE)
		    make_aux_edge(e0->head, e0->tail, m1,
			ED_weight(e));
		m1 = m0 + ND_rw_i(e1->tail) + ND_lw_i(e1->head);
		if (canreach(e1->head, e1->tail) == FALSE)
		    make_aux_edge(e1->tail, e1->head, m1,
			ED_weight(e));
	    }

	    /* position flat edge endpoints */
	    for (k = 0; k < ND_flat_out(u).size; k++) {
		e = ND_flat_out(u).list[k];
		if (ND_order(e->tail) < ND_order(e->head)) {
		    t0 = e->tail;
		    h0 = e->head;
		} else {
		    t0 = e->head;
		    h0 = e->tail;
		}

		width = ND_rw_i(t0) + ND_lw_i(h0);
		m0 = ED_minlen(e) * GD_nodesep(g) + width;

		if ((e0 = find_fast_edge(t0, h0))) {
		    /* flat edge between adjacent neighbors 
                     * ED_dist contains the largest label width.
                     */
		    m0 = MAX(m0, width + GD_nodesep(g) + ROUND(ED_dist(e)));
		    if (m0 > USHRT_MAX)
			largeMinlen (m0);
		    ED_minlen(e0) = MAX(ED_minlen(e0), m0);
		}
		else if (!ED_label(e)) {
		    /* unlabeled flat edge between non-neighbors 
		     * ED_minlen(e) is max of ED_minlen of all equivalent 
                     * edges.
                     */
		    make_aux_edge(t0, h0, m0, ED_weight(e));
		}
		/* labeled flat edges between non-neighbors have already
                 * been constrained by the label above. 
                 */ 
	    }
	}
    }
}

/* make_edge_pairs: make virtual edge pairs corresponding to input edges */
static void make_edge_pairs(graph_t * g)
{
    int i, m0, m1;
    node_t *n, *sn;
    edge_t *e;

    for (n = GD_nlist(g); n; n = ND_next(n)) {
	if (ND_save_out(n).list)
	    for (i = 0; (e = ND_save_out(n).list[i]); i++) {
		sn = virtual_node(g);
		ND_node_type(sn) = SLACKNODE;
		m0 = (ED_head_port(e).p.x - ED_tail_port(e).p.x);
		if (m0 > 0)
		    m1 = 0;
		else {
		    m1 = -m0;
		    m0 = 0;
		}
#ifdef NOTDEF
/* was trying to improve LR balance */
		if ((ND_save_out(n).size % 2 == 0)
		    && (i == ND_save_out(n).size / 2 - 1)) {
		    node_t *u = ND_save_out(n).list[i]->head;
		    node_t *v = ND_save_out(n).list[i + 1]->head;
		    int width = ND_rw_i(u) + ND_lw_i(v) + GD_nodesep(g);
		    m0 = width / 2 - 1;
		}
#endif
		make_aux_edge(sn, e->tail, m0 + 1, ED_weight(e));
		make_aux_edge(sn, e->head, m1 + 1, ED_weight(e));
		ND_rank(sn) =
		    MIN(ND_rank(e->tail) - m0 - 1,
			ND_rank(e->head) - m1 - 1);
	    }
    }
}

static void contain_clustnodes(graph_t * g)
{
    int c;
    edge_t	*e;

    if (g != g->root) {
	contain_nodes(g);
	if ((e = find_fast_edge(GD_ln(g),GD_rn(g))))	/* maybe from lrvn()?*/
	    ED_weight(e) += 128;
	else
	    make_aux_edge(GD_ln(g), GD_rn(g), 1, 128);	/* clust compaction edge */
    }
    for (c = 1; c <= GD_n_cluster(g); c++)
	contain_clustnodes(GD_clust(g)[c]);
}

static int vnode_not_related_to(graph_t * g, node_t * v)
{
    edge_t *e;

    if (ND_node_type(v) != VIRTUAL)
	return FALSE;
    for (e = ND_save_out(v).list[0]; ED_to_orig(e); e = ED_to_orig(e));
    if (agcontains(g, e->tail))
	return FALSE;
    if (agcontains(g, e->head))
	return FALSE;
    return TRUE;
}

/* keepout_othernodes:
 * Guarantee nodes outside the cluster g are placed outside of it.
 * This is done by adding constraints to make sure such nodes have
 * a gap of CL_OFFSET from the left or right bounding box node ln or rn.
 * 
 * We could probably reduce some of these constraints by checking if
 * the node is in a cluster, since elsewhere we make constrain a
 * separate between clusters. Also, we should be able to skip the
 * first loop if g is the root graph.
 */
static void keepout_othernodes(graph_t * g)
{
    int i, c, r;
    node_t *u, *v;

    for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
	if (GD_rank(g)[r].n == 0)
	    continue;
	v = GD_rank(g)[r].v[0];
	if (v == NULL)
	    continue;
	for (i = ND_order(v) - 1; i >= 0; i--) {
	    u = GD_rank(g->root)[r].v[i];
	    /* can't use "is_a_vnode_of" because elists are swapped */
	    if ((ND_node_type(u) == NORMAL) || vnode_not_related_to(g, u)) {
		make_aux_edge(u, GD_ln(g), CL_OFFSET + ND_rw_i(u), 0);
		break;
	    }
	}
	for (i = ND_order(v) + GD_rank(g)[r].n; i < GD_rank(g->root)[r].n;
	     i++) {
	    u = ND_rank(g->root)[r].v[i];
	    if ((ND_node_type(u) == NORMAL) || vnode_not_related_to(g, u)) {
		make_aux_edge(GD_rn(g), u, CL_OFFSET + ND_lw_i(u), 0);
		break;
	    }
	}
    }

    for (c = 1; c <= GD_n_cluster(g); c++)
	keepout_othernodes(GD_clust(g)[c]);
}

/* contain_subclust:
 * Make sure boxes of subclusters of g are offset from the
 * box of g. This is done by a constraint between the left and
 * right bounding box nodes ln and rn of g and a subcluster.
 * The gap needs to include any left or right labels.
 */
static void contain_subclust(graph_t * g)
{
    int c;
    graph_t *subg;

    make_lrvn(g);
    for (c = 1; c <= GD_n_cluster(g); c++) {
	subg = GD_clust(g)[c];
	make_lrvn(subg);
	make_aux_edge(GD_ln(g), GD_ln(subg),
		      CL_OFFSET + GD_border(g)[LEFT_IX].x, 0);
	make_aux_edge(GD_rn(subg), GD_rn(g),
		      CL_OFFSET + GD_border(g)[RIGHT_IX].x, 0);
	contain_subclust(subg);
    }
}

/* separate_subclust:
 * Guarantee space between subcluster of g.
 * This is done by adding a constraint between the right bbox node rn
 * of the left cluster and the left bbox node ln of the right cluster.
 * This is only done if the two clusters overlap in some rank.
 */
static void separate_subclust(graph_t * g)
{
    int i, j;
    graph_t *low, *high;
    graph_t *left, *right;

    for (i = 1; i <= GD_n_cluster(g); i++)
	make_lrvn(GD_clust(g)[i]);
    for (i = 1; i <= GD_n_cluster(g); i++) {
	for (j = i + 1; j <= GD_n_cluster(g); j++) {
	    low = GD_clust(g)[i];
	    high = GD_clust(g)[j];
	    if (GD_minrank(low) > GD_minrank(high)) {
		graph_t *temp = low;
		low = high;
		high = temp;
	    }
	    if (GD_maxrank(low) < GD_minrank(high))
		continue;
	    if (ND_order(GD_rank(low)[GD_minrank(high)].v[0])
		< ND_order(GD_rank(high)[GD_minrank(high)].v[0])) {
		left = low;
		right = high;
	    } else {
		left = high;
		right = low;
	    }
	    make_aux_edge(GD_rn(left), GD_ln(right), CL_OFFSET, 0);
	}
	separate_subclust(GD_clust(g)[i]);
    }
}

/* pos_clusters: create constraints for:
 *	node containment in clusters,
 *	cluster containment in clusters,
 *	separation of sibling clusters.
 */
static void pos_clusters(graph_t * g)
{
    if (GD_n_cluster(g) > 0) {
	contain_clustnodes(g);
	keepout_othernodes(g);
	contain_subclust(g);
	separate_subclust(g);
    }
}

static void compress_graph(graph_t * g)
{
    double x;
    point p;

    if (GD_drawing(g)->ratio_kind != R_COMPRESS)
	return;
    p = GD_drawing(g)->size;
    if (p.x * p.y <= 1)
	return;
    contain_nodes(g);
    if (GD_flip(g) == FALSE)
	x = p.x;
    else
	x = p.y;
    make_aux_edge(GD_ln(g), GD_rn(g), (int) x, 1000);
}

static void create_aux_edges(graph_t * g)
{
    allocate_aux_edges(g);
    make_LR_constraints(g);
    make_edge_pairs(g);
    pos_clusters(g);
    compress_graph(g);
}

static void remove_aux_edges(graph_t * g)
{
    int i;
    node_t *n, *nnext, *nprev;
    edge_t *e;

    for (n = GD_nlist(g); n; n = ND_next(n)) {
	for (i = 0; (e = ND_out(n).list[i]); i++)
	    free(e);
	free_list(ND_out(n));
	free_list(ND_in(n));
	ND_out(n) = ND_save_out(n);
	ND_in(n) = ND_save_in(n);
    }
    /* cannot be merged with previous loop */
    nprev = NULL;
    for (n = GD_nlist(g); n; n = nnext) {
	nnext = ND_next(n);
	if (ND_node_type(n) == SLACKNODE) {
	    if (nprev)
		ND_next(nprev) = nnext;
	    else
		GD_nlist(g) = nnext;
	    free(n);
	} else
	    nprev = n;
    }
    GD_nlist(g)->u.prev = NULL;
}

/* set_xcoords:
 * Set x coords of nodes.
 */
static void 
set_xcoords(graph_t * g)
{
    int i, j;
    node_t *v;
    rank_t *rank = GD_rank(g);

    for (i = GD_minrank(g); i <= GD_maxrank(g); i++) {
	for (j = 0; j < rank[i].n; j++) {
	    v = rank[i].v[j];
	    ND_coord_i(v).x = ND_rank(v);
	    ND_rank(v) = i;
	}
    }
}

/* adjustEqual:
 * Expand cluster g vertically by delta, assuming ranks
 * are equally spaced. We first try to split delta evenly
 * using any available space at the top and bottom. If there
 * is not enough, we have to widen the space between the ranks.
 * We divide delta equally within the ranks of g plus its ht1
 * and ht2. To preserve equality of ranks, we add this space
 * between every pair of ranks.
 *
 * There is probably some way to add less than delta, by using
 * whatever available space there is at top and bottom, but for
 * now, trying to figure that out seems more trouble than it is worth.
 */
static void adjustEqual(graph_t * g, int delta)
{
    int r, avail, half, deltop, delbottom;
    graph_t *root = g->root;
    rank_t *rank = GD_rank(root);
    int maxr = GD_maxrank(g);
    int minr = GD_minrank(g);

    deltop = rank[minr].ht2 - GD_ht2(g);
    delbottom = rank[maxr].ht1 - GD_ht1(g);
    avail = deltop + delbottom;
    if (avail >= delta) {
 	half = (delta+1) / 2;
	if (deltop <= delbottom) {
	    if (half <= deltop) {
		GD_ht2(g) += half;
		GD_ht1(g) += (delta - half);
	    }
	    else {    
		GD_ht2(g) += deltop;
		GD_ht1(g) += (delta - deltop);
	    }
	}
	else {
	    if (half <= delbottom) {
		GD_ht1(g) += half;
		GD_ht2(g) += (delta - half);
	    }
	    else {    
		GD_ht1(g) += delbottom;
		GD_ht2(g) += (delta - delbottom);
	    }
	}
    }
    else {
	int gaps = maxr - minr + 2;
	int yoff = (delta + (gaps - 1)) / gaps;
	int y = yoff;
	for (r = GD_maxrank(root) - 1; r >= GD_minrank(root); r--) {
	    if (rank[r].n > 0)
		rank[r].v[0]->u.coord.y += y;
	    y += yoff;
	}
	GD_ht2(g) += yoff;
	GD_ht1(g) += yoff;
    }
}

/* adjustSimple:
 * Expand cluster height by delta, adding half to top
 * and half to bottom. If the bottom expansion exceeds the
 * ht1 of the rank, shift the ranks in the cluster up.
 * If the top expansion, including any shift from the bottom
 * expansion, exceeds to ht2 of the rank, shift the ranks above
 * the cluster up.
 */
static void adjustSimple(graph_t * g, int delta)
{
    int r, bottom, deltop, delbottom;
    graph_t *root = g->root;
    rank_t *rank = GD_rank(root);
    int maxr = GD_maxrank(g);
    int minr = GD_minrank(g);

    bottom = (delta+1) / 2;
    delbottom = GD_ht1(g) + bottom - rank[maxr].ht1;
    if (delbottom > 0) {
	for (r = maxr; r >= minr; r--) {
	    if (rank[r].n > 0)
		rank[r].v[0]->u.coord.y += delbottom;
 	}
	deltop = GD_ht2(g) + (delta-bottom) + delbottom - rank[minr].ht2;
    }
    else
	deltop = GD_ht2(g) + (delta-bottom) - rank[minr].ht2;
    if (deltop > 0) {
	for (r = minr-1; r >= GD_minrank(root); r--) {
	    if (rank[r].n > 0)
		rank[r].v[0]->u.coord.y += deltop;
	}
    }
    GD_ht2(g) += (delta - bottom);
    GD_ht1(g) += bottom;
}

/* adjustRanks:
 * Recursively adjust ranks to take into account
 * wide cluster labels when rankdir=LR.
 * We divide the extra space between the top and bottom.
 * Adjust the ht1 and ht2 values in the process.
 */
static void adjustRanks(graph_t * g, int equal)
{
    int lht;			/* label height */
    int rht;			/* height between top and bottom ranks */
    int delta, maxr, minr;
    int c, ht1, ht2;
    rank_t *rank = GD_rank(g->root);

    ht1 = GD_ht1(g);
    ht2 = GD_ht2(g);

    for (c = 1; c <= GD_n_cluster(g); c++) {
	graph_t *subg = GD_clust(g)[c];
	adjustRanks(subg, equal);
	if (GD_maxrank(subg) == GD_maxrank(g))
	    ht1 = MAX(ht1, GD_ht1(subg) + CL_OFFSET);
	if (GD_minrank(subg) == GD_minrank(g))
	    ht2 = MAX(ht2, GD_ht2(subg) + CL_OFFSET);
    }

    GD_ht1(g) = ht1;
    GD_ht2(g) = ht2;

    if ((g != g->root) && GD_label(g)) {
	lht = MAX(GD_border(g)[LEFT_IX].y, GD_border(g)[RIGHT_IX].y);
	maxr = GD_maxrank(g);
	minr = GD_minrank(g);
	rht =
	    ND_coord_i(rank[minr].v[0]).y - ND_coord_i(rank[maxr].v[0]).y;
	delta = lht - (rht + ht1 + ht2);
	if (delta > 0) {
	    if (equal)
		adjustEqual(g, delta);
	    else
		adjustSimple(g, delta);
	}
    }

    /* update the global ranks */
    if (g != g->root) {
	rank[GD_minrank(g)].ht2 = MAX(rank[GD_minrank(g)].ht2, GD_ht2(g));
	rank[GD_maxrank(g)].ht1 = MAX(rank[GD_maxrank(g)].ht1, GD_ht1(g));
    }
}

/* clust_ht:
 * recursively compute cluster ht requirements.  assumes GD_ht1(subg) and ht2
 * are computed from primitive nodes only.  updates ht1 and ht2 to reflect
 * cluster nesting and labels.  also maintains global rank ht1 and ht2.
 * Return true if some cluster has a label.
 */
static int clust_ht(Agraph_t * g)
{
    int c, ht1, ht2;
    graph_t *subg;
    rank_t *rank = GD_rank(g->root);
    int haveClustLabel = 0;

    ht1 = GD_ht1(g);
    ht2 = GD_ht2(g);

    /* account for sub-clusters */
    for (c = 1; c <= GD_n_cluster(g); c++) {
	subg = GD_clust(g)[c];
	haveClustLabel |= clust_ht(subg);
	if (GD_maxrank(subg) == GD_maxrank(g))
	    ht1 = MAX(ht1, GD_ht1(subg) + CL_OFFSET);
	if (GD_minrank(subg) == GD_minrank(g))
	    ht2 = MAX(ht2, GD_ht2(subg) + CL_OFFSET);
    }

    /* account for a possible cluster label in clusters */
    /* room for root graph label is handled in dotneato_postprocess */
    if ((g != g->root) && GD_label(g)) {
	haveClustLabel = 1;
	if (!GD_flip(g->root)) {
	    ht1 += GD_border(g)[BOTTOM_IX].y;
	    ht2 += GD_border(g)[TOP_IX].y;
	}
    }
    GD_ht1(g) = ht1;
    GD_ht2(g) = ht2;

    /* update the global ranks */
    if (g != g->root) {
	rank[GD_minrank(g)].ht2 = MAX(rank[GD_minrank(g)].ht2, ht2);
	rank[GD_maxrank(g)].ht1 = MAX(rank[GD_maxrank(g)].ht1, ht1);
    }

    return haveClustLabel;
}

/* set y coordinates of nodes, a rank at a time */
static void set_ycoords(graph_t * g)
{
    int i, j, r, ht2, maxht, delta, d0, d1;
    node_t *n;
    edge_t *e;
    rank_t *rank = GD_rank(g);
    graph_t *clust;
    int lbl;

    ht2 = maxht = 0;

    /* scan ranks for tallest nodes.  */
    for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
	for (i = 0; i < rank[r].n; i++) {
	    n = rank[r].v[i];

	    /* assumes symmetry, ht1 = ht2 */
	    ht2 = (ND_ht_i(n) + 1) / 2;


	    /* have to look for high self-edge labels, too */
	    if (ND_other(n).list)
		for (j = 0; (e = ND_other(n).list[j]); j++) {
		    if (e->tail == e->head) {
			if (ED_label(e))
			    ht2 = MAX(ht2, ED_label(e)->dimen.y / 2);
		    }
		}

	    /* update global rank ht */
	    if (rank[r].pht2 < ht2)
		rank[r].pht2 = rank[r].ht2 = ht2;
	    if (rank[r].pht1 < ht2)
		rank[r].pht1 = rank[r].ht1 = ht2;

	    /* update nearest enclosing cluster rank ht */
	    if ((clust = ND_clust(n))) {
		int yoff = (clust == g ? 0 : CL_OFFSET);
		if (ND_rank(n) == GD_minrank(clust))
		    GD_ht2(clust) = MAX(GD_ht2(clust), ht2 + yoff);
		if (ND_rank(n) == GD_maxrank(clust))
		    GD_ht1(clust) = MAX(GD_ht1(clust), ht2 + yoff);
	    }
	}
    }

    /* scan sub-clusters */
    lbl = clust_ht(g);

    /* make the initial assignment of ycoords to leftmost nodes by ranks */
    maxht = 0;
    r = GD_maxrank(g);
    rank[r].v[0]->u.coord.y = rank[r].ht1;
    while (--r >= GD_minrank(g)) {
	d0 = rank[r + 1].pht2 + rank[r].pht1 + GD_ranksep(g);	/* prim node sep */
	d1 = rank[r + 1].ht2 + rank[r].ht1 + CL_OFFSET;	/* cluster sep */
	delta = MAX(d0, d1);
	if (rank[r].n > 0)	/* this may reflect some problem */
	    rank[r].v[0]->u.coord.y = rank[r + 1].v[0]->u.coord.y + delta;
#ifdef DEBUG
	else
	    fprintf(stderr, "dot set_ycoords: rank %d is empty\n",
		    rank[r].n);
#endif
	maxht = MAX(maxht, delta);
    }

    /* re-assign if ranks are equally spaced */
    if (GD_exact_ranksep(g)) {
	for (r = GD_maxrank(g) - 1; r >= GD_minrank(g); r--)
	    if (rank[r].n > 0)	/* this may reflect the same problem :-() */
		rank[r].v[0]->u.coord.y =
		    rank[r + 1].v[0]->u.coord.y + maxht;
    }

    if (lbl && GD_flip(g))
	adjustRanks(g, GD_exact_ranksep(g));

    /* copy ycoord assignment from leftmost nodes to others */
    for (n = GD_nlist(g); n; n = ND_next(n))
	ND_coord_i(n).y = rank[ND_rank(n)].v[0]->u.coord.y;
}

/* dot_compute_bb:
 * Compute bounding box of g.
 * The x limits of clusters are given by the x positions of ln and rn.
 * This information is stored in the rank field, since it was calculated
 * using network simplex.
 * For the root graph, we don't enforce all the constraints on lr and 
 * rn, so we traverse the nodes and subclusters.
 */
static void dot_compute_bb(graph_t * g, graph_t * root)
{
    int r, c, x, offset;
    node_t *v;
    point LL, UR;

    if (g == g->root) {
	LL.x = INT_MAX;
	UR.x = -INT_MAX;
	for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
	    int rnkn = GD_rank(g)[r].n;
	    if (rnkn == 0)
		continue;
	    if ((v = GD_rank(g)[r].v[0]) == NULL)
		continue;
	    for (c = 1; (ND_node_type(v) != NORMAL) && c < rnkn; c++)
		v = GD_rank(g)[r].v[c];
	    if (ND_node_type(v) == NORMAL) {
		x = ND_coord_i(v).x - ND_lw_i(v);
		LL.x = MIN(LL.x, x);
	    }
	    else continue;
		/* At this point, we know the rank contains a NORMAL node */
	    v = GD_rank(g)[r].v[rnkn - 1];
	    for (c = rnkn-2; ND_node_type(v) != NORMAL; c--)
		v = GD_rank(g)[r].v[c];
	    x = ND_coord_i(v).x + ND_rw_i(v);
	    UR.x = MAX(UR.x, x);
	}
	offset = CL_OFFSET;
	for (c = 1; c <= GD_n_cluster(g); c++) {
	    x = GD_clust(g)[c]->u.bb.LL.x - offset;
	    LL.x = MIN(LL.x, x);
	    x = GD_clust(g)[c]->u.bb.UR.x + offset;
	    UR.x = MAX(UR.x, x);
	}
    } else {
	LL.x = ND_rank(GD_ln(g));
	UR.x = ND_rank(GD_rn(g));
    }
    LL.y = ND_rank(root)[GD_maxrank(g)].v[0]->u.coord.y - GD_ht1(g);
    UR.y = ND_rank(root)[GD_minrank(g)].v[0]->u.coord.y + GD_ht2(g);
    GD_bb(g).LL = LL;
    GD_bb(g).UR = UR;
}

static void rec_bb(graph_t * g, graph_t * root)
{
    int c;
    for (c = 1; c <= GD_n_cluster(g); c++)
	rec_bb(GD_clust(g)[c], root);
    dot_compute_bb(g, root);
}

/* scale_bb:
 * Recursively rescale all bounding boxes using scale factors
 * xf and yf. We assume all the bboxes have been computed.
 */
static void scale_bb(graph_t * g, graph_t * root, double xf, double yf)
{
    int c;

    for (c = 1; c <= GD_n_cluster(g); c++)
	scale_bb(GD_clust(g)[c], root, xf, yf);
    GD_bb(g).LL.x *= xf;
    GD_bb(g).LL.y *= yf;
    GD_bb(g).UR.x *= xf;
    GD_bb(g).UR.y *= yf;
}

/* set_aspect:
 * Set bounding boxes and, if ratio is set, rescale graph.
 * Note that if some dimension shrinks, there may be problems
 * with labels.
 */
static void set_aspect(graph_t * g)
{
    double xf = 0.0, yf = 0.0, actual, desired;
    node_t *n;
    boolean scale_it, filled;
    point sz;

    rec_bb(g, g);
    if ((GD_maxrank(g) > 0) && (GD_drawing(g)->ratio_kind)) {
	sz.x = GD_bb(g).UR.x - GD_bb(g).LL.x;
	sz.y = GD_bb(g).UR.y - GD_bb(g).LL.y;	/* normalize */
	if (GD_flip(g)) {
	    int t = sz.x;
	    sz.x = sz.y;
	    sz.y = t;
	}
	scale_it = TRUE;
	if (GD_drawing(g)->ratio_kind == R_AUTO)
	    filled = idealsize(g, .5);
	else
	    filled = (GD_drawing(g)->ratio_kind == R_FILL);
	if (filled) {
	    /* fill is weird because both X and Y can stretch */
	    if (GD_drawing(g)->size.x <= 0)
		scale_it = FALSE;
	    else {
		xf = (double) GD_drawing(g)->size.x / (double) sz.x;
		yf = (double) GD_drawing(g)->size.y / (double) sz.y;
		if ((xf < 1.0) || (yf < 1.0)) {
		    if (xf < yf) {
			yf = yf / xf;
			xf = 1.0;
		    } else {
			xf = xf / yf;
			yf = 1.0;
		    }
		}
	    }
	} else if (GD_drawing(g)->ratio_kind == R_EXPAND) {
	    if (GD_drawing(g)->size.x <= 0)
		scale_it = FALSE;
	    else {
		xf = (double) GD_drawing(g)->size.x /
		    (double) GD_bb(g).UR.x;
		yf = (double) GD_drawing(g)->size.y /
		    (double) GD_bb(g).UR.y;
		if ((xf > 1.0) && (yf > 1.0)) {
		    double scale = MIN(xf, yf);
		    xf = yf = scale;
		} else
		    scale_it = FALSE;
	    }
	} else if (GD_drawing(g)->ratio_kind == R_VALUE) {
	    desired = GD_drawing(g)->ratio;
	    actual = ((double) sz.y) / ((double) sz.x);
	    if (actual < desired) {
		yf = desired / actual;
		xf = 1.0;
	    } else {
		xf = actual / desired;
		yf = 1.0;
	    }
	} else
	    scale_it = FALSE;
	if (scale_it) {
	    if (GD_flip(g)) {
		double t = xf;
		xf = yf;
		yf = t;
	    }
	    for (n = GD_nlist(g); n; n = ND_next(n)) {
		ND_coord_i(n).x = ND_coord_i(n).x * xf;
		ND_coord_i(n).y = ND_coord_i(n).y * yf;
	    }
	    scale_bb(g, g, xf, yf);
	}
    }
}

static point resize_leaf(node_t * leaf, point lbound)
{
    dot_nodesize(leaf, GD_flip(leaf->graph));
    ND_coord_i(leaf).y = lbound.y;
    ND_coord_i(leaf).x = lbound.x + ND_lw_i(leaf);
    lbound.x =
	lbound.x + ND_lw_i(leaf) + ND_rw_i(leaf) + GD_nodesep(leaf->graph);
    return lbound;
}

static point place_leaf(node_t * leaf, point lbound, int order)
{
    node_t *leader;
    graph_t *g = leaf->graph;

    leader = UF_find(leaf);
    if (leaf != leader)
	fast_nodeapp(leader, leaf);
    ND_order(leaf) = order;
    ND_rank(leaf) = ND_rank(leader);
    GD_rank(g)[ND_rank(leaf)].v[ND_order(leaf)] = leaf;
    return resize_leaf(leaf, lbound);
}

/* make space for the leaf nodes of each rank */
static void make_leafslots(graph_t * g)
{
    int i, j, r;
    node_t *v;

    for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
	j = 0;
	for (i = 0; i < GD_rank(g)[r].n; i++) {
	    v = GD_rank(g)[r].v[i];
	    ND_order(v) = j;
	    if (ND_ranktype(v) == LEAFSET)
		j = j + ND_UF_size(v);
	    else
		j++;
	}
	if (j <= GD_rank(g)[r].n)
	    continue;
	GD_rank(g)[r].v = ALLOC(j + 1, GD_rank(g)[r].v, node_t *);
	for (i = GD_rank(g)[r].n - 1; i >= 0; i--) {
	    v = GD_rank(g)[r].v[i];
	    GD_rank(g)[r].v[ND_order(v)] = v;
	}
	GD_rank(g)[r].n = j;
	GD_rank(g)[r].v[j] = NULL;
    }
}

static void do_leaves(graph_t * g, node_t * leader)
{
    int j;
    point lbound;
    node_t *n;
    edge_t *e;

    if (ND_UF_size(leader) <= 1)
	return;
    lbound.x = ND_coord_i(leader).x - ND_lw_i(leader);
    lbound.y = ND_coord_i(leader).y;
    lbound = resize_leaf(leader, lbound);
    if (ND_out(leader).size > 0) {	/* in-edge leaves */
	n = ND_out(leader).list[0]->head;
	j = ND_order(leader) + 1;
	for (e = agfstin(g, n); e; e = agnxtin(g, e)) {
	    if ((e->tail != leader) && (UF_find(e->tail) == leader)) {
		lbound = place_leaf(e->tail, lbound, j++);
		unmerge_oneway(e);
		elist_append(e, ND_in(e->head));
	    }
	}
    } else {			/* out edge leaves */
	n = ND_in(leader).list[0]->tail;
	j = ND_order(leader) + 1;
	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
	    if ((e->head != leader) && (UF_find(e->head) == leader)) {
		lbound = place_leaf(e->head, lbound, j++);
		unmerge_oneway(e);
		elist_append(e, ND_out(e->tail));
	    }
	}
    }
}

int ports_eq(edge_t * e, edge_t * f)
{
    return ((ED_head_port(e).defined == ED_head_port(f).defined)
	    && (((ED_head_port(e).p.x == ED_head_port(f).p.x) &&
		 (ED_head_port(e).p.y == ED_head_port(f).p.y))
		|| (ED_head_port(e).defined == FALSE))
	    && (((ED_tail_port(e).p.x == ED_tail_port(f).p.x) &&
		 (ED_tail_port(e).p.y == ED_tail_port(f).p.y))
		|| (ED_tail_port(e).defined == FALSE))
	);
}

static void expand_leaves(graph_t * g)
{
    int i, d;
    node_t *n;
    edge_t *e, *f;

    make_leafslots(g);
    for (n = GD_nlist(g); n; n = ND_next(n)) {
	if (ND_inleaf(n))
	    do_leaves(g, ND_inleaf(n));
	if (ND_outleaf(n))
	    do_leaves(g, ND_outleaf(n));
	if (ND_other(n).list)
	    for (i = 0; (e = ND_other(n).list[i]); i++) {
		if ((d = ND_rank(e->head) - ND_rank(e->head)) == 0)
		    continue;
		f = ED_to_orig(e);
		if (ports_eq(e, f) == FALSE) {
		    zapinlist(&(ND_other(n)), e);
		    if (d == 1)
			fast_edge(e);
		    /*else unitize(e); ### */
		    i--;
		}
	    }
    }
}

/* make_lrvn:
 * Add left and right slacknodes to a cluster which
 * are used in the LP to constrain nodes not in g but
 * sharing its ranks to be to the left or right of g
 * by a specified amount.
 * The slacknodes ln and rn give the x position of the
 * left and right side of the cluster's bounding box. In
 * particular, any cluster labels on the left or right side
 * are inside.
 * If a cluster has a label, and we have rankdir!=LR, we make
 * sure the cluster is wide enough for the label. Note that
 * if the label is wider than the cluster, the nodes in the
 * cluster may not be centered.
 */
static void make_lrvn(graph_t * g)
{
    node_t *ln, *rn;

    if (GD_ln(g))
	return;
    ln = virtual_node(g->root);
    ND_node_type(ln) = SLACKNODE;
    rn = virtual_node(g->root);
    ND_node_type(rn) = SLACKNODE;

    if (GD_label(g) && (g != g->root) && !GD_flip(g->root)) {
	int w = MAX(GD_border(g)[BOTTOM_IX].x, GD_border(g)[TOP_IX].x);
	make_aux_edge(ln, rn, w, 0);
    }

    GD_ln(g) = ln;
    GD_rn(g) = rn;
}

/* contain_nodes: 
 * make left and right bounding box virtual nodes ln and rn
 * constrain interior nodes
 */
static void contain_nodes(graph_t * g)
{
    int r;
    node_t *ln, *rn, *v;

    make_lrvn(g);
    ln = GD_ln(g);
    rn = GD_rn(g);
    for (r = GD_minrank(g); r <= GD_maxrank(g); r++) {
	if (GD_rank(g)[r].n == 0)
	    continue;
	v = GD_rank(g)[r].v[0];
	if (v == NULL) {
	    agerr(AGERR, "contain_nodes clust %s rank %d missing node\n",
		  g->name, r);
	    continue;
	}
	make_aux_edge(ln, v,
		      ND_lw_i(v) + CL_OFFSET + GD_border(g)[LEFT_IX].x, 0);
	v = GD_rank(g)[r].v[GD_rank(g)[r].n - 1];
	make_aux_edge(v, rn,
		      ND_rw_i(v) + CL_OFFSET + GD_border(g)[RIGHT_IX].x,
		      0);
    }
}

/* idealsize:
 * set g->drawing->size to a reasonable default.
 * returns a boolean to indicate if drawing is to
 * be scaled and filled */
static boolean idealsize(graph_t * g, double minallowed)
{
    double xf, yf, f, R;
    point b, relpage, margin;

    /* try for one page */
    relpage = GD_drawing(g)->page;
    if (relpage.x == 0)
	return FALSE;		/* no page was specified */
    margin = GD_drawing(g)->margin;
    relpage = sub_points(relpage, margin);
    relpage = sub_points(relpage, margin);
    b.x = GD_bb(g).UR.x;
    b.y = GD_bb(g).UR.y;
    xf = (double) relpage.x / b.x;
    yf = (double) relpage.y / b.y;
    if ((xf >= 1.0) && (yf >= 1.0))
	return FALSE;		/* fits on one page */

    f = MIN(xf, yf);
    xf = yf = MAX(f, minallowed);

    R = ceil((xf * b.x) / relpage.x);
    xf = ((R * relpage.x) / b.x);
    R = ceil((yf * b.y) / relpage.y);
    yf = ((R * relpage.y) / b.y);
    GD_drawing(g)->size.x = b.x * xf;
    GD_drawing(g)->size.y = b.y * yf;
    return TRUE;
}
