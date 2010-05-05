/* $Id: gvrender_core_svg.c,v 1.64 2008/04/27 21:48:34 ellson Exp $ $Revision: 1.64 $ */
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

/* Comments on the SVG coordinate system (SN 8 Dec 2006):
   The initial <svg> element defines the SVG coordinate system so
   that the graphviz canvas (in units of points) fits the intended
   absolute size in inches.  After this, the situation should be
   that "px" = "pt" in SVG, so we can dispense with stating units.
   Also, the input units (such as fontsize) should be preserved
   without scaling in the output SVG (as long as the graph size
   was not constrained.)
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "macros.h"
#include "const.h"

#include "gvplugin_render.h"
#include "gvcint.h"
#include "graph.h"
#include "types.h"		/* need the SVG font name schemes */

typedef enum { FORMAT_SVG, FORMAT_SVGZ, } format_type;

extern char *xml_string(char *str);
extern char *xml_url_string(char *str);

/* SVG dash array */
static char *sdasharray = "5,2";
/* SVG dot array */
static char *sdotarray = "1,5";

static void svg_bzptarray(GVJ_t * job, pointf * A, int n)
{
    int i;
    char c;

    c = 'M';			/* first point */
    for (i = 0; i < n; i++) {
	gvdevice_printf(job, "%c%g,%g", c, A[i].x, -A[i].y);
	if (i == 0)
	    c = 'C';		/* second point */
	else
	    c = ' ';		/* remaining points */
    }
}

static void svg_print_color(GVJ_t * job, gvcolor_t color)
{
    switch (color.type) {
    case COLOR_STRING:
	gvdevice_fputs(job, color.u.string);
	break;
    case RGBA_BYTE:
	if (color.u.rgba[3] == 0) /* transparent */
	    gvdevice_fputs(job, "none");
	else
	    gvdevice_printf(job, "#%02x%02x%02x",
		color.u.rgba[0], color.u.rgba[1], color.u.rgba[2]);
	break;
    default:
	assert(0);		/* internal error */
    }
}

static void svg_grstyle(GVJ_t * job, int filled)
{
    obj_state_t *obj = job->obj;

    gvdevice_fputs(job, " style=\"fill:");
    if (filled)
	svg_print_color(job, obj->fillcolor);
    else
	gvdevice_fputs(job, "none");
    gvdevice_fputs(job, ";stroke:");
    svg_print_color(job, obj->pencolor);
    if (obj->penwidth != PENWIDTH_NORMAL)
	gvdevice_printf(job, ";stroke-width:%g", obj->penwidth);
    if (obj->pen == PEN_DASHED) {
	gvdevice_printf(job, ";stroke-dasharray:%s", sdasharray);
    } else if (obj->pen == PEN_DOTTED) {
	gvdevice_printf(job, ";stroke-dasharray:%s", sdotarray);
    }
    gvdevice_fputs(job, ";\"");
}

static void svg_comment(GVJ_t * job, char *str)
{
    gvdevice_fputs(job, "<!-- ");
    gvdevice_fputs(job, xml_string(str));
    gvdevice_fputs(job, " -->\n");
}

/* isAscii:
 * Return true if all characters in the string are ascii.
 */
static int isAscii (char* s)
{
    int c;
    while ((c = *s++) != '\0') {
	if (!isascii (c)) return 0;
    }
    return 1;
}

static void svg_begin_job(GVJ_t * job)
{
    char *s;
    gvdevice_fputs(job, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
    if ((s = agget(job->gvc->g, "stylesheet")) && s[0]) {
        gvdevice_fputs(job, "<?xml-stylesheet href=\"");
        gvdevice_fputs(job, s);
        gvdevice_fputs(job, "\" type=\"text/css\"?>\n");
    }
    gvdevice_fputs(job, "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.0//EN\"\n");
    gvdevice_fputs(job, " \"http://www.w3.org/TR/2001/REC-SVG-20010904/DTD/svg10.dtd\"");

    /* This is to work around a bug in the SVG 1.0 DTD */
    gvdevice_fputs(job, " [\n <!ATTLIST svg xmlns:xlink CDATA #FIXED \"http://www.w3.org/1999/xlink\">\n]");

    gvdevice_fputs(job, ">\n<!-- Generated by ");
    gvdevice_fputs(job, xml_string(job->common->info[0]));
    gvdevice_fputs(job, " version ");
    gvdevice_fputs(job, xml_string(job->common->info[1]));
    gvdevice_fputs(job, " (");
    gvdevice_fputs(job, xml_string(job->common->info[2]));
    /* We have absolutely no idea what character set the username
     * may be in. To be conservative, we only output the username
     * if it is all ascii. Since SVG output is UTF-8, we could check
     * if the string appears to be in this format and allow it.
     */
    if (isAscii (job->common->user)) {
	gvdevice_fputs(job, ")\n     For user: ");
	gvdevice_fputs(job, xml_string(job->common->user));
    }
    else
	gvdevice_fputs(job, ")\n");
    gvdevice_fputs(job, " -->\n");
}

static void svg_begin_graph(GVJ_t * job)
{
    obj_state_t *obj = job->obj;

    gvdevice_fputs(job, "<!--");
    if (obj->u.g->name[0]) {
        gvdevice_fputs(job, " Title: ");
	gvdevice_fputs(job, xml_string(obj->u.g->name));
    }
    gvdevice_printf(job, " Pages: %d -->\n", job->pagesArraySize.x * job->pagesArraySize.y);

    gvdevice_printf(job, "<svg width=\"%dpt\" height=\"%dpt\"\n",
	job->width, job->height);
    gvdevice_printf(job, " viewBox=\"%.2f %.2f %.2f %.2f\"",
        job->canvasBox.LL.x, job->canvasBox.LL.y,
        job->canvasBox.UR.x, job->canvasBox.UR.y);
    /* namespace of svg */
    gvdevice_fputs(job, " xmlns=\"http://www.w3.org/2000/svg\"");
    /* namespace of xlink */
    gvdevice_fputs(job, " xmlns:xlink=\"http://www.w3.org/1999/xlink\"");
    gvdevice_fputs(job, ">\n");
}

static void svg_end_graph(GVJ_t * job)
{
    gvdevice_fputs(job, "</svg>\n");
}

static void svg_begin_layer(GVJ_t * job, char *layername, int layerNum, int numLayers)
{
    gvdevice_fputs(job, "<g id=\"");
    gvdevice_fputs(job, xml_string(layername));
    gvdevice_fputs(job, "\" class=\"layer\">\n");
}

static void svg_end_layer(GVJ_t * job)
{
    gvdevice_fputs(job, "</g>\n");
}

static void svg_begin_page(GVJ_t * job)
{
    obj_state_t *obj = job->obj;

    /* its really just a page of the graph, but its still a graph,
     * and it is the entire graph if we're not currently paging */
    gvdevice_printf(job, "<g id=\"graph%d\" class=\"graph\"", job->common->viewNum);
    gvdevice_printf(job, " transform=\"scale(%g %g) rotate(%d) translate(%g %g)\">\n",
	    job->scale.x, job->scale.y, -job->rotation,
	    job->translation.x, -job->translation.y);
    /* default style */
    if (obj->u.g->name[0]) {
        gvdevice_fputs(job, "<title>");
        gvdevice_fputs(job, xml_string(obj->u.g->name));
        gvdevice_fputs(job, "</title>\n");
    }
}

static void svg_end_page(GVJ_t * job)
{
    gvdevice_fputs(job, "</g>\n");
}

static void svg_begin_cluster(GVJ_t * job)
{
    obj_state_t *obj = job->obj;

    gvdevice_printf(job, "<g id=\"cluster%ld\" class=\"cluster\">",
	    obj->u.sg->meta_node->id);
    gvdevice_fputs(job, "<title>");
    gvdevice_fputs(job, xml_string(obj->u.sg->name));
    gvdevice_fputs(job, "</title>\n");
}

static void svg_end_cluster(GVJ_t * job)
{
    gvdevice_fputs(job, "</g>\n");
}

static void svg_begin_node(GVJ_t * job)
{
    obj_state_t *obj = job->obj;

    gvdevice_printf(job, "<g id=\"node%ld\" class=\"node\">", obj->u.n->id);
    gvdevice_fputs(job, "<title>");
    gvdevice_fputs(job, xml_string(obj->u.n->name));
    gvdevice_fputs(job, "</title>\n");
}

static void svg_end_node(GVJ_t * job)
{
    gvdevice_fputs(job, "</g>\n");
}

static void
svg_begin_edge(GVJ_t * job)
{
    obj_state_t *obj = job->obj;
    char *edgeop;

    gvdevice_printf(job, "<g id=\"edge%ld\" class=\"edge\">", obj->u.e->id);
    if (obj->u.e->tail->graph->root->kind & AGFLAG_DIRECTED)
	edgeop = "&#45;&gt;";
    else
	edgeop = "&#45;&#45;";
    gvdevice_fputs(job, "<title>");
    gvdevice_fputs(job, xml_string(obj->u.e->tail->name));
    gvdevice_fputs(job, edgeop);
    /* can't do this in single gvdevice_printf because
     * xml_string's buffer gets reused. */
    gvdevice_fputs(job, xml_string(obj->u.e->head->name));
    gvdevice_fputs(job, "</title>\n");
}

static void svg_end_edge(GVJ_t * job)
{
    gvdevice_fputs(job, "</g>\n");
}

static void
svg_begin_anchor(GVJ_t * job, char *href, char *tooltip, char *target)
{
    gvdevice_fputs(job, "<a");
    if (href && href[0])
	gvdevice_printf(job, " xlink:href=\"%s\"", xml_url_string(href));
    if (tooltip && tooltip[0])
	gvdevice_printf(job, " xlink:title=\"%s\"", xml_string(tooltip));
    if (target && target[0])
	gvdevice_printf(job, " target=\"%s\"", xml_string(target));
    gvdevice_fputs(job, ">\n");
}

static void svg_end_anchor(GVJ_t * job)
{
    gvdevice_fputs(job, "</a>\n");
}

static void svg_textpara(GVJ_t * job, pointf p, textpara_t * para)
{
    obj_state_t *obj = job->obj;
    PostscriptAlias *pA;

    gvdevice_fputs(job, "<text");
    switch (para->just) {
    case 'l':
	gvdevice_fputs(job, " text-anchor=\"start\"");
	break;
    case 'r':
	gvdevice_fputs(job, " text-anchor=\"end\"");
	break;
    default:
    case 'n':
	gvdevice_fputs(job, " text-anchor=\"middle\"");
	break;
    }
    p.y += para->yoffset_centerline;
    gvdevice_printf(job, " x=\"%g\" y=\"%g\"", p.x, -p.y);
    gvdevice_fputs(job, " style=\"");
    pA = para->postscript_alias;
    if (pA) {
	char *family=NULL, *weight=NULL, *stretch=NULL, *style=NULL;
	switch(GD_fontnames(job->gvc->g)) {
		case PSFONTS:
		    family = pA->name;
		    weight = pA->weight;
		    style = pA->style;
		    break;
		case SVGFONTS:
                    family = pA->svg_font_family;
                    weight = pA->svg_font_weight;
                    style = pA->svg_font_style;
		    break;
		default:
		case NATIVEFONTS:
		    family = pA->family;
		    weight = pA->weight;
		    style = pA->style;
		    break;
	}
	stretch = pA->stretch;

        gvdevice_printf(job, "font-family:%s;", family);
        if (weight) gvdevice_printf(job, "font-weight:%s;", weight);
        if (stretch) gvdevice_printf(job, "font-stretch:%s;", stretch);
        if (style) gvdevice_printf(job, "font-style:%s;", style);
    }
    else
	gvdevice_printf(job, "font-family:%s;", para->fontname);
    gvdevice_printf(job, "font-size:%.2f;", para->fontsize);
    switch (obj->pencolor.type) {
    case COLOR_STRING:
	if (strcasecmp(obj->pencolor.u.string, "black"))
	    gvdevice_printf(job, "fill:%s;", obj->pencolor.u.string);
	break;
    case RGBA_BYTE:
	gvdevice_printf(job, "fill:#%02x%02x%02x;",
		obj->pencolor.u.rgba[0], obj->pencolor.u.rgba[1], obj->pencolor.u.rgba[2]);
	break;
    default:
	assert(0);		/* internal error */
    }
    gvdevice_fputs(job, "\">");
    gvdevice_fputs(job, xml_string(para->str));
    gvdevice_fputs(job, "</text>\n");
}

static void svg_ellipse(GVJ_t * job, pointf * A, int filled)
{
    /* A[] contains 2 points: the center and corner. */
    gvdevice_fputs(job, "<ellipse");
    svg_grstyle(job, filled);
    gvdevice_printf(job, " cx=\"%g\" cy=\"%g\"", A[0].x, -A[0].y);
    gvdevice_printf(job, " rx=\"%g\" ry=\"%g\"",
	    A[1].x - A[0].x, A[1].y - A[0].y);
    gvdevice_fputs(job, "/>\n");
}

static void
svg_bezier(GVJ_t * job, pointf * A, int n, int arrow_at_start,
	      int arrow_at_end, int filled)
{
    gvdevice_fputs(job, "<path");
    svg_grstyle(job, filled);
    gvdevice_fputs(job, " d=\"");
    svg_bzptarray(job, A, n);
    gvdevice_fputs(job, "\"/>\n");
}

static void svg_polygon(GVJ_t * job, pointf * A, int n, int filled)
{
    int i;

    gvdevice_fputs(job, "<polygon");
    svg_grstyle(job, filled);
    gvdevice_fputs(job, " points=\"");
    for (i = 0; i < n; i++)
	gvdevice_printf(job, "%g,%g ", A[i].x, -A[i].y);
    gvdevice_printf(job, "%g,%g", A[0].x, -A[0].y);	/* because Adobe SVG is broken */
    gvdevice_fputs(job, "\"/>\n");
}

static void svg_polyline(GVJ_t * job, pointf * A, int n)
{
    int i;

    gvdevice_fputs(job, "<polyline");
    svg_grstyle(job, 0);
    gvdevice_fputs(job, " points=\"");
    for (i = 0; i < n; i++)
	gvdevice_printf(job, "%g,%g ", A[i].x, -A[i].y);
    gvdevice_fputs(job, "\"/>\n");
}

/* color names from http://www.w3.org/TR/SVG/types.html */
/* NB.  List must be LANG_C sorted */
static char *svg_knowncolors[] = {
    "aliceblue", "antiquewhite", "aqua", "aquamarine", "azure",
    "beige", "bisque", "black", "blanchedalmond", "blue",
    "blueviolet", "brown", "burlywood",
    "cadetblue", "chartreuse", "chocolate", "coral",
    "cornflowerblue", "cornsilk", "crimson", "cyan",
    "darkblue", "darkcyan", "darkgoldenrod", "darkgray",
    "darkgreen", "darkgrey", "darkkhaki", "darkmagenta",
    "darkolivegreen", "darkorange", "darkorchid", "darkred",
    "darksalmon", "darkseagreen", "darkslateblue", "darkslategray",
    "darkslategrey", "darkturquoise", "darkviolet", "deeppink",
    "deepskyblue", "dimgray", "dimgrey", "dodgerblue",
    "firebrick", "floralwhite", "forestgreen", "fuchsia",
    "gainsboro", "ghostwhite", "gold", "goldenrod", "gray",
    "green", "greenyellow", "grey",
    "honeydew", "hotpink", "indianred",
    "indigo", "ivory", "khaki",
    "lavender", "lavenderblush", "lawngreen", "lemonchiffon",
    "lightblue", "lightcoral", "lightcyan", "lightgoldenrodyellow",
    "lightgray", "lightgreen", "lightgrey", "lightpink",
    "lightsalmon", "lightseagreen", "lightskyblue",
    "lightslategray", "lightslategrey", "lightsteelblue",
    "lightyellow", "lime", "limegreen", "linen",
    "magenta", "maroon", "mediumaquamarine", "mediumblue",
    "mediumorchid", "mediumpurple", "mediumseagreen",
    "mediumslateblue", "mediumspringgreen", "mediumturquoise",
    "mediumvioletred", "midnightblue", "mintcream",
    "mistyrose", "moccasin",
    "navajowhite", "navy", "oldlace",
    "olive", "olivedrab", "orange", "orangered", "orchid",
    "palegoldenrod", "palegreen", "paleturquoise",
    "palevioletred", "papayawhip", "peachpuff", "peru", "pink",
    "plum", "powderblue", "purple",
    "red", "rosybrown", "royalblue",
    "saddlebrown", "salmon", "sandybrown", "seagreen", "seashell",
    "sienna", "silver", "skyblue", "slateblue", "slategray",
    "slategrey", "snow", "springgreen", "steelblue",
    "tan", "teal", "thistle", "tomato", "turquoise",
    "violet",
    "wheat", "white", "whitesmoke",
    "yellow", "yellowgreen"
};

gvrender_engine_t svg_engine = {
    svg_begin_job,
    0,				/* svg_end_job */
    svg_begin_graph,
    svg_end_graph,
    svg_begin_layer,
    svg_end_layer,
    svg_begin_page,
    svg_end_page,
    svg_begin_cluster,
    svg_end_cluster,
    0,				/* svg_begin_nodes */
    0,				/* svg_end_nodes */
    0,				/* svg_begin_edges */
    0,				/* svg_end_edges */
    svg_begin_node,
    svg_end_node,
    svg_begin_edge,
    svg_end_edge,
    svg_begin_anchor,
    svg_end_anchor,
    svg_textpara,
    0,				/* svg_resolve_color */
    svg_ellipse,
    svg_polygon,
    svg_bezier,
    svg_polyline,
    svg_comment,
    0,				/* svg_library_shape */
};

gvrender_features_t render_features_svg = {
    GVRENDER_Y_GOES_DOWN
        | GVRENDER_DOES_TRANSFORM
	| GVRENDER_DOES_LABELS
	| GVRENDER_DOES_MAPS
	| GVRENDER_DOES_TARGETS
	| GVRENDER_DOES_TOOLTIPS, /* flags */
    4.,                         /* default pad - graph units */
    svg_knowncolors,		/* knowncolors */
    sizeof(svg_knowncolors) / sizeof(char *),	/* sizeof knowncolors */
    RGBA_BYTE,			/* color_type */
};

gvdevice_features_t device_features_svg = {
    GVDEVICE_DOES_TRUECOLOR,	/* flags */
    {0.,0.},			/* default margin - points */
    {0.,0.},                    /* default page width, height - points */
    {72.,72.},			/* default dpi */
};

gvdevice_features_t device_features_svgz = {
    GVDEVICE_BINARY_FORMAT
      | GVDEVICE_COMPRESSED_FORMAT
      | GVDEVICE_DOES_TRUECOLOR,/* flags */
    {0.,0.},			/* default margin - points */
    {0.,0.},                    /* default page width, height - points */
    {72.,72.},			/* default dpi */
};

gvplugin_installed_t gvrender_svg_types[] = {
    {FORMAT_SVG, "svg", 1, &svg_engine, &render_features_svg},
    {0, NULL, 0, NULL, NULL}
};

gvplugin_installed_t gvdevice_svg_types[] = {
    {FORMAT_SVG, "svg:svg", 1, NULL, &device_features_svg},
#if HAVE_LIBZ
    {FORMAT_SVGZ, "svgz:svg", 1, NULL, &device_features_svgz},
#endif
    {0, NULL, 0, NULL, NULL}
};