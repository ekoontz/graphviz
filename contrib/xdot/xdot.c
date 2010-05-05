/* vim:set shiftwidth=4 ts=8: */

/**********************************************************
*      This software is part of the graphviz package      *
*                http://www.graphviz.org/                 *
*                                                         *
*            Copyright (c) 1994-2007 AT&T Corp.           *
*                and is licensed under the                *
*            Common Public License, Version 1.0           *
*                      by AT&T Corp.                      *
*                                                         *
*        Information and Software Systems Research        *
*              AT&T Research, Florham Park NJ             *
**********************************************************/

#include <xdot.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define NEW(t)           (t*)malloc(sizeof(t))
#define N_NEW(n,t)       (t*)malloc((n)*sizeof(t))
#define RALLOC(size,ptr,type) ((type*)realloc(ptr,(size)*sizeof(type)))
#define ALLOC(size,ptr,type) (ptr? RALLOC(size,ptr,type):N_NEW(size,type))

#define streq(x,y) (!strcmp(x,y))

static char*
parseFloat (char* s, float* fp)
{
    int r, sz;
    r = sscanf(s, "%f%n", fp, &sz);
    assert (r == 1);
    return (s+sz);
}

static char*
parseInt (char* s, int* ip)
{
    int r, sz;
    r = sscanf(s, "%d%n", ip, &sz);
    assert (r == 1);
    return (s+sz);
}

static char*
parsePoint (char* s, xdot_point* pp)
{
    int r, sz;
    r = sscanf(s, "%d %d%n", &(pp->x), &(pp->y), &sz);
    assert (r == 2);
    return (s+sz);
}

static char*
parseRect (char* s, xdot_rect* rp)
{
    int r, sz;
    r = sscanf(s, "%d %d %d %d%n", &(rp->x), &(rp->y), &(rp->w), &(rp->h), &sz);
    assert (r == 4);
    return (s+sz);
}

static char*
parsePolyline (char* s, xdot_polyline* pp)
{
    int i;
    xdot_point* pts;

    s = parseInt (s, &i);
    pts = N_NEW(i, xdot_point);
    pp->cnt = i;
    for (i = 0; i < pp->cnt; i++)
	s = parsePoint (s, pts+i);
    pp->pts = pts;
    return s;
}

static char*
parseString (char* s, char** sp)
{
    int i;
    char* c;
    s = parseInt (s, &i);
    c = N_NEW(i+1, char);
    while (*s++ != '-');
    memcpy (c, s, i);
    c[i] = '\0';
    *sp = c;
    return (s+i);
}

static char*
parseAlign (char* s, xdot_align* ap)
{
    int i;
    s = parseInt (s, &i);
    if (i < 0) *ap = xd_left;
    else if (i > 0) *ap = xd_right;
    else *ap = xd_center;
    return s;
}

static char*
parseOp (xdot_op* op, char* s)
{
    if (!s) return s;

    while (isspace(*s)) s++;
    switch (*s++) {
    case 'E' :
	op->kind = xd_filled_ellipse;
	s = parseRect (s, &op->u.ellipse);
	break;
    case 'e' :
	op->kind = xd_unfilled_ellipse;
	s = parseRect (s, &op->u.ellipse);
	break;
    case 'P' :
	op->kind = xd_filled_polygon;
	s = parsePolyline (s, &op->u.polygon);
	break;
    case 'p' :
	op->kind = xd_unfilled_polygon;
	s = parsePolyline (s, &op->u.polygon);
	break;
    case 'b' :
	op->kind = xd_filled_bezier;
	s = parsePolyline (s, &op->u.bezier);
	break;
    case 'B' :
	op->kind = xd_unfilled_bezier;
	s = parsePolyline (s, &op->u.bezier);
	break;
    case 'c' :
	op->kind = xd_pen_color;
	s = parseString (s, &op->u.color);
	break;
    case 'C' :
	op->kind = xd_fill_color;
	s = parseString (s, &op->u.color);
	break;
    case 'L' :
	op->kind = xd_polyline;
	s = parsePolyline (s, &op->u.polyline);
	break;
    case 'T' :
	op->kind = xd_text;
	s = parseInt (s, &op->u.text.x);
	s = parseInt (s, &op->u.text.y);
	s = parseAlign (s, &op->u.text.align);
	s = parseInt (s, &op->u.text.width);
	s = parseString (s, &op->u.text.text);
	break;
    case 'F' :
	op->kind = xd_font;
	s = parseFloat (s, &op->u.font.size);
	s = parseString (s, &op->u.font.name);
	break;
    case 'S' :
	op->kind = xd_style;
	s = parseString (s, &op->u.style);
	break;
    case 'I' :
	op->kind = xd_image;
	s = parseRect (s, &op->u.image.pos);
	s = parseString (s, &op->u.image.name);
	break;
    default :
	s = 0;
	break;
    }
    return s;
}

#define XDBSIZE 100

xdot*
parseXDot (char* s)
{
    xdot* x = NEW(xdot);
    xdot_op op;
    int bufsz = XDBSIZE;
    xdot_op* ops = N_NEW(XDBSIZE, xdot_op);

    x->cnt = 0;
    while ((s = parseOp (&op, s))) {
	if (x->cnt == bufsz) {
	    bufsz += XDBSIZE;
	    ops = RALLOC (bufsz, ops, xdot_op);
	} 
	ops[x->cnt] = op;
	x->cnt++;
    }
    if (x->cnt)
	x->ops = RALLOC (x->cnt, ops, xdot_op);
    else {
	free (x);
	x = 0;
    }
    return x;
}

typedef void (*pf)(char*, void*);

static void
printRect (xdot_rect* r, pf print, void* info)
{
    char buf[128];

    sprintf (buf, " %d %d %d %d", r->x, r->y, r->w, r->h);
    print (buf, info);
}

static void
printPolyline (xdot_polyline* p, pf print, void* info)
{
    int i;
    char buf[64];

    sprintf (buf, " %d", p->cnt);
    print (buf, info);
    for (i = 0; i< p->cnt; i++) {
	sprintf (buf, " %d %d", p->pts[i].x, p->pts[i].y);
	print (buf, info);
    }
}

static void
printString (char* p, pf print, void* info)
{
    char buf[30];

    sprintf (buf, " %d -", (int)strlen(p));
    print (buf, info);
    print (p, info);
}

static void
printInt (int i, pf print, void* info)
{
    char buf[30];

    sprintf (buf, " %d", i);
    print (buf, info);
}

static void
printFloat (float f, pf print, void* info)
{
    char buf[128];

    sprintf (buf, " %f", f);
    print (buf, info);
}

static void
printAlign (xdot_align a, pf print, void* info)
{
    switch (a) {
    case xd_left : 
	print (" -1", info);
	break;
    case xd_right : 
	print (" 1", info);
	break;
    case xd_center : 
	print (" 0", info);
	break;
    }
}

static void
printXDot_Op (xdot_op* op, pf print, void* info)
{
    switch (op->kind) {
    case xd_filled_ellipse :
	print ("E", info);
	printRect (&op->u.ellipse, print, info);
	break;
    case xd_unfilled_ellipse :
	print ("e", info);
	printRect (&op->u.ellipse, print, info);
	break;
    case xd_filled_polygon :
	print ("P", info);
	printPolyline (&op->u.polygon, print, info);
	break;
    case xd_unfilled_polygon :
	print ("p", info);
	printPolyline (&op->u.polygon, print, info);
	break;
    case xd_filled_bezier :
	print ("b", info);
	op->kind = xd_filled_bezier;
	printPolyline (&op->u.bezier, print, info);
	break;
    case xd_unfilled_bezier :
	print ("B", info);
	printPolyline (&op->u.bezier, print, info);
	break;
    case xd_pen_color :
	print ("c", info);
	printString (op->u.color, print, info);
	break;
    case xd_fill_color :
	print ("C", info);
	printString (op->u.color, print, info);
	break;
    case xd_polyline :
	print ("L", info);
	printPolyline (&op->u.polyline, print, info);
	break;
    case xd_text :
	print ("T", info);
	printInt (op->u.text.x, print, info);
	printInt (op->u.text.y, print, info);
	printAlign (op->u.text.align, print, info);
	printInt (op->u.text.width, print, info);
	printString (op->u.text.text, print, info);
	break;
    case xd_font :
	print ("F", info);
	op->kind = xd_font;
	printFloat (op->u.font.size, print, info);
	printString (op->u.font.name, print, info);
	break;
    case xd_style :
	print ("S", info);
	printString (op->u.style, print, info);
	break;
    case xd_image :
	print ("I", info);
	printRect (&op->u.image.pos, print, info);
	printString (op->u.image.name, print, info);
	break;
    }
}

static void
_printXDot (xdot* x, pf print, void* info)
{
    int i;
    for (i = 0; i < x->cnt; i++) {
	printXDot_Op (x->ops+i, print, info);
	if (i < x->cnt-1) print (" ", info);
    }
}
 
typedef struct {
    unsigned char *buf;	/* start of buffer */
    unsigned char *ptr;	/* next place to write */
    unsigned char *eptr;	/* end of buffer */
    int dyna;		/* true if buffer is malloc'ed */
} agxbuf;

#define agxbputc(X,C) ((((X)->ptr >= (X)->eptr) ? agxbmore(X,1) : 0), \
          (int)(*(X)->ptr++ = ((unsigned char)C)))
#define agxbuse(X) (agxbputc(X,'\0'),(char*)((X)->ptr = (X)->buf))

static void
agxbinit(agxbuf * xb, unsigned int hint, unsigned char *init)
{
    if (init) {
	xb->buf = init;
	xb->dyna = 0;
    } else {
	if (hint == 0)
	    hint = BUFSIZ;
	xb->dyna = 1;
	xb->buf = N_NEW(hint, unsigned char);
    }
    xb->eptr = xb->buf + hint;
    xb->ptr = xb->buf;
    *xb->ptr = '\0';
}
static int
agxbmore(agxbuf * xb, unsigned int ssz)
{
    int cnt;			/* current no. of characters in buffer */
    int size;			/* current buffer size */
    int nsize;			/* new buffer size */
    unsigned char *nbuf;	/* new buffer */

    size = xb->eptr - xb->buf;
    nsize = 2 * size;
    if (size + ssz > nsize)
	nsize = size + ssz;
    cnt = xb->ptr - xb->buf;
    if (xb->dyna) {
	nbuf = realloc(xb->buf, nsize);
    } else {
	nbuf = N_NEW(nsize, unsigned char);
	memcpy(nbuf, xb->buf, cnt);
	xb->dyna = 1;
    }
    xb->buf = nbuf;
    xb->ptr = xb->buf + cnt;
    xb->eptr = xb->buf + nsize;
    return 0;
}

static int
agxbput(char* s, agxbuf * xb)
{
    unsigned int ssz = strlen (s);
    if (xb->ptr + ssz > xb->eptr)
	agxbmore(xb, ssz);
    memcpy(xb->ptr, s, ssz);
    xb->ptr += ssz;
    return ssz;
}

/* agxbfree:
 * Free any malloced resources.
 */
static void 
agxbfree(agxbuf * xb)
{
    if (xb->dyna)
	free(xb->buf);
}

char* 
sprintXDot (xdot* x)
{
    char* s;
    unsigned char buf[BUFSIZ];
    agxbuf xb;
    agxbinit (&xb, BUFSIZ, buf);
    _printXDot (x, (pf)agxbput, &xb);
    s = strdup(agxbuse (&xb));
    agxbfree (&xb);

    return s;
}

void 
fprintXDot (FILE* fp, xdot* x)
{
    _printXDot (x, (pf)fputs, fp);
}

static void 
freeXOpData (xdot_op* x)
{
    switch (x->kind) {
    case xd_filled_polygon :
    case xd_unfilled_polygon :
	free (x->u.polyline.pts);
	break;
    case xd_filled_bezier :
    case xd_unfilled_bezier :
	free (x->u.polyline.pts);
	break;
    case xd_polyline :
	free (x->u.polyline.pts);
	break;
    case xd_text :
	free (x->u.text.text);
	break;
    case xd_fill_color :     
    case xd_pen_color : 
	free (x->u.color);
	break;
    case xd_font : 
	free (x->u.font.name);
	break;
    case xd_style : 
	free (x->u.style);
	break;
    case xd_image :
	free (x->u.image.name);
	break;
    default :
	break;
    }
}

void 
freeXDot (xdot* x)
{
    int i;
    for (i = 0; i < x->cnt; i++) freeXOpData (x->ops+i);
    free (x->ops);
    free (x);
}

static void
freeXSFn (xstyle_item* x)
{
    int i;
    free (x->u.fn.name);
    for (i = 0; i < x->u.fn.n_args; i++) free (x->u.fn.args[i]);
    free (x->u.fn.args);
}

static void
freeXItem (xstyle_item* x)
{
    switch (x->kind) {
    case xs_string :
	free (x->u.string);
	break;
    case xs_function :
	freeXSFn (x);
	break;
    default :
	break;
    }
}

void
freeXStyle (xstyle* x)
{
    int i;
    for (i = 0; i < x->cnt; i++) freeXItem (x->items+i);
    free (x->items);
    free (x);
}

static int
is_style_delim(int c)
{
    switch (c) {
    case '(':
    case ')':
    case ',':
    case '\0':
        return 1;
    default:
        return 0;
    }
}   

/* parseName:
 * Skip initial spaces and commas.
 * Store chars in xb, stopping at 0, (, ) or ,.
 * Returns NULL on failure.
 * Returns pointer to a delimiter char on success,
 * with value stored in xb.
 */
static char*
parseName (char* s, agxbuf* xb)
{
    char c;
    while (*s && (isspace(*s) || (*s == ',')))
        s++;
    switch (*s) {
    case '\0':
    case '(':
    case ')':
        return 0;
        break;
    default:
        while (!is_style_delim(c = *s)) {
            agxbputc(xb, c);
            s++;
        }
    }
    return s; 

}

/* parseFunction:
 * Assume we've seen "fnname (", fnname stored in it.
 * Parses name(,name)*
 * Returns NULL on failure.
 * On success, stores values in it and returns 
 */
#define XARGSZ 5
static char*
parseFunction (xstyle_item* it, char* f, agxbuf* xb)
{
    int bufsz = 0;
    char* s = f;

    do {
	s = parseName (s, xb);
	if (!s || (*s == '(') || (*s == '\0')) {
	    fprintf (stderr, "Incorrect function syntax: %s(%s\n", it->u.fn.name, f); 
	    freeXSFn (it);
	    return 0;
	}
	if (it->u.fn.n_args >= bufsz) {
	    bufsz += XARGSZ;
	    it->u.fn.args = ALLOC(bufsz, it->u.fn.args, char*); 
	}
	it->u.fn.args[it->u.fn.n_args++] = strdup (agxbuse (xb));
    } while (*s == ',');

    /* *s == ')' */
    s++;
    if (streq (it->u.fn.name, "setlinewidth")) {
	char* eptr;
	float v = strtod (it->u.fn.args[0], &eptr);

	freeXSFn (it);
	if ((it->u.fn.n_args > 1) || (eptr == it->u.fn.args[0]) || (v < 0)) {
	    *s = '\0';
	    fprintf (stderr, "Incorrect syntax: setlinewidth(%s\n", f); 
	    return 0;
	}
	it->kind = xs_line_width;
	it->u.line_width = v;
    }
    else {
	it->u.fn.args = RALLOC(it->u.fn.n_args, it->u.fn.args, char*); 
	it->kind = xs_function;
    }
    return s;
}

static char*
parseItem (xstyle_item* it, char* s, agxbuf* xb)
{
    char* t;
    char* name;

    s = parseName (s, xb);
    if (!s) return s;
    name = t = agxbuse (xb);
    if (*s == '(') {
	it->u.fn.n_args = 0;
	it->u.fn.args = 0;
	it->u.fn.name = strdup (name);
	s = parseFunction (it, s+1, xb);
	return s;
    }
    if (*s == ')') {
	fprintf (stderr, "Incorrect style syntax \"%s)\"\n", name); 
	return 0;
    }

    /* *s == \0 or , */
    switch (*t++) {
    case 'b' :
	if (streq(t,"old"))
	    it->kind = xs_bold;
	else {
	    it->kind = xs_string;
	    it->u.string = strdup (name);
	}
	break;
    case 'd' :
	if (streq(t,"ashed"))
	    it->kind = xs_dashed;
	else if (streq(t,"otted"))
	    it->kind = xs_dotted;
	else if (streq(t,"iagonals"))
	    it->kind = xs_diagonals;
	else {
	    it->kind = xs_string;
	    it->u.string = strdup (name);
	}
	break;
    case 'f' :
	if (streq(t,"illed"))
	    it->kind = xs_filled;
	else {
	    it->kind = xs_string;
	    it->u.string = strdup (name);
	}
	break;
    case 'i' :
	if (streq(t,"nvis"))
	    it->kind = xs_invis;
	else {
	    it->kind = xs_string;
	    it->u.string = strdup (name);
	}
	break;
    case 'r' :
	if (streq(t,"ounded"))
	    it->kind = xs_rounded;
	else {
	    it->kind = xs_string;
	    it->u.string = strdup (name);
	}
	break;
    case 's' :
	if (streq(t,"olid"))
	    it->kind = xs_solid;
	else {
	    it->kind = xs_string;
	    it->u.string = strdup (name);
	}
	break;
    default :
	it->kind = xs_string;
	it->u.string = strdup (name);
	break;
    }
    return s;
}

xstyle*
parseXStyle (char* s)
{
    xstyle* x = NEW(xstyle);
    xstyle_item item;
    int bufsz = XDBSIZE;
    xstyle_item* items = N_NEW(XDBSIZE, xstyle_item);
    unsigned char buf[BUFSIZ];
    agxbuf xb;

    agxbinit (&xb, BUFSIZ, buf);

    x->cnt = 0;
    while ((s = parseItem (&item, s, &xb))) {
	if (x->cnt == bufsz) {
	    bufsz += XDBSIZE;
	    items = RALLOC (bufsz, items, xstyle_item);
	} 
	items[x->cnt] = item;
	x->cnt++;
    }
    if (x->cnt)
	x->items = RALLOC (x->cnt, items, xstyle_item);
    else {
	free (x);
	x = 0;
    }
    agxbfree (&xb);
    return x;
}

static void
printXStyleItem (xstyle_item* it, pf print, void* info)
{
    char buf[100];
    int i;

    switch (it->kind) {
    case xs_dashed :
	print ("dashed", info);
	break;
    case xs_dotted :
	print ("dotted", info);
	break;
    case xs_solid :
	print ("solid", info);
	break;
    case xs_invis :
	print ("invis", info);
	break;
    case xs_bold :
	print ("bold", info);
	break;
    case xs_filled :
	print ("filled", info);
	break;
    case xs_diagonals :
	print ("diagonals", info);
	break;
    case xs_rounded :
	print ("rounded", info);
	break;
    case xs_line_width :
	print ("setlinewidth(", info);
	sprintf (buf, "%g", it->u.line_width); 
	print (buf, info);
	print (")", info);
	break;
    case xs_function :
	print (it->u.fn.name, info);
	print ("(", info);
	for (i=0; i < it->u.fn.n_args; i++) {
	    if (i > 0) print (",", info);
	    print (it->u.fn.args[i], info);
	}
	print (")", info);
	break;
    case xs_string :
	print (it->u.string, info);
	break;
    }
}

static void
_printXStyle (xstyle* x, pf print, void* info)
{
    int i;
    for (i = 0; i < x->cnt; i++) {
	printXStyleItem (x->items+i, print, info);
	if (i < x->cnt-1) print (",", info);
    }
}
 
char*
sprintXStyle (xstyle* xs)
{
    char* s;
    unsigned char buf[BUFSIZ];
    agxbuf xb;
    agxbinit (&xb, BUFSIZ, buf);
    _printXStyle (xs, (pf)agxbput, &xb);
    s = strdup(agxbuse (&xb));
    agxbfree (&xb);

    return s;
}

void 
fprintXStyle (FILE* fp, xstyle* xs)
{
    _printXStyle (xs, (pf)fputs, fp);
}

