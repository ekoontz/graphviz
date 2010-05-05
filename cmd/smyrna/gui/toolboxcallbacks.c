/* $Id: toolboxcallbacks.c,v 1.3 2008/03/19 21:43:59 erg Exp $ $Revision: 1.3 $ */
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

#include "toolboxcallbacks.h"
#include "viewport.h"
#include "selection.h"
#include "gltemplate.h"


void btnToolSingleSelect_clicked(GtkWidget * widget, gpointer user_data)
{
    deselect_all(view->g[view->activeGraph]);
    switch_Mouse(NULL, 3);
}

void btnToolRectSelect_clicked(GtkWidget * widget, gpointer user_data)
{

    deselect_all(view->g[view->activeGraph]);
    view->Selection.Anti = 0;
    switch_Mouse(NULL, 4);
}

void btnToolRectXSelect_clicked(GtkWidget * widget, gpointer user_data)
{
    deselect_all(view->g[view->activeGraph]);
    view->Selection.Anti = 0;
    switch_Mouse(NULL, 5);
}

void btnToolAntiRectSelect_clicked(GtkWidget * widget, gpointer user_data)
{
    view->Selection.Anti = 1;
    switch_Mouse(NULL, 4);

}

void btnToolAntiRectXSelect_clicked(GtkWidget * widget, gpointer user_data)
{
    view->Selection.Anti = 1;
    switch_Mouse(NULL, 5);

}


void btnToolPan_clicked(GtkWidget * widget, gpointer user_data)
{
    switch_Mouse(NULL, 0);
}

void btnToolZoom_clicked(GtkWidget * widget, gpointer user_data)
{
    switch_Mouse(NULL, 1);
}

void btnToolZoomIn_clicked(GtkWidget * widget, gpointer user_data)
{
    view->zoom = view->zoom + ZOOM_STEP;
    if (view->zoom > MAX_ZOOM)
	view->zoom = (float) MAX_ZOOM;
    glexpose();

}

void btnToolZoomOut_clicked(GtkWidget * widget, gpointer user_data)
{
    view->zoom = view->zoom - ZOOM_STEP;
    if (view->zoom < MIN_ZOOM)
	view->zoom = MIN_ZOOM;
    expose_event(view->drawing_area, NULL, NULL);
}

void btnToolFit_clicked(GtkWidget * widget, gpointer user_data)
{
}
void btnToolMove_clicked(GtkWidget * widget, gpointer user_data)
{
    switch_Mouse(NULL, 10);
}

void btnToolAddNode_clicked(GtkWidget * widget, gpointer user_data)
{
}
void btnToolDeleteNode_clicked(GtkWidget * widget, gpointer user_data)
{
}
void btnToolFindNode_clicked(GtkWidget * widget, gpointer user_data)
{
}
void btnToolAddEdge_clicked(GtkWidget * widget, gpointer user_data)
{
}
void btnToolDeleteEdge_clicked(GtkWidget * widget, gpointer user_data)
{
}
void btnToolFindEdge_clicked(GtkWidget * widget, gpointer user_data)
{
}
