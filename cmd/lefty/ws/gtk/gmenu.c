/* $Id: gmenu.c,v 1.1 2005/01/06 15:01:43 ellson Exp $ $Revision: 1.1 $ */
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


#include "common.h"
#include "g.h"
#include "gcommon.h"

#define WMU widget->u.m

static int menupoped;
static int menuselected;

void mwcallback(gpointer * l);

int GMcreatewidget(Gwidget_t * parent, Gwidget_t * widget,
		   int attrn, Gwattr_t * attrp)
{
    int ai;

    for (ai = 0; ai < attrn; ai++) {
	switch (attrp[ai].id) {
	case G_ATTRUSERDATA:
	    widget->udata = attrp[ai].u.u;
	    break;
	default:
	    Gerr(POS, G_ERRBADATTRID, attrp[ai].id);
	    return -1;
	}
    }

    widget->w = gtk_menu_new();
    gtk_menu_attach_to_widget(widget->w, parent->w, mwcallback);
    WMU->count = 0;
    return 0;
}


int GMsetwidgetattr(Gwidget_t * widget, int attrn, Gwattr_t * attrp)
{
    int ai;

    for (ai = 0; ai < attrn; ai++) {
	switch (attrp[ai].id) {
	case G_ATTRUSERDATA:
	    widget->udata = attrp[ai].u.u;
	    break;
	default:
	    Gerr(POS, G_ERRBADATTRID, attrp[ai].id);
	    return -1;
	}
    }
    return 0;
}


int GMgetwidgetattr(Gwidget_t * widget, int attrn, Gwattr_t * attrp)
{
    int ai;

    for (ai = 0; ai < attrn; ai++) {
	switch (attrp[ai].id) {
	case G_ATTRUSERDATA:
	    attrp[ai].u.u = widget->udata;
	    break;
	default:
	    Gerr(POS, G_ERRBADATTRID, attrp[ai].id);
	    return -1;
	}
    }
    return 0;
}


int GMdestroywidget(Gwidget_t * widget)
{
    gtk_widget_destroy(widget->w);
    return 0;
}


int GMmenuaddentries(Gwidget_t * widget, int en, char **ep)
{
    GtkWidget *mep;
    int ei;

    for (ei = 0; ei < en; ei++) {
	mep = gtk_menu_item_new_with_label(ep[ei]);
	gtk_menu_append(GTK_MENU(widget->w), mep);
	gtk_signal_connect_object(GTK_OBJECT(mep), "activate",
				  GTK_SIGNAL_FUNC(mwcallback),
				  GINT_TO_POINTER(WMU->count++));
	gtk_widget_show(mep);
    }

    return 0;
}


int GMmenudisplay(Gwidget_t * parent, Gwidget_t * widget)
{

    gtk_menu_popup(GTK_MENU(widget->w), NULL, NULL, NULL, NULL, 0, 0);
    menupoped = TRUE;
    menuselected = -1;

    while (menupoped) {
	Gprocessevents(TRUE, G_ONEEVENT);

    }
    Gpopdownflag = TRUE;
    return menuselected;
}


void mwcallback(gpointer * l)
{

    if (GPOINTER_TO_INT(l) > -1)
	menuselected = GPOINTER_TO_INT(l);
    menupoped = FALSE;
}
