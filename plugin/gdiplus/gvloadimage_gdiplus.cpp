/* $Id: gvloadimage_gdiplus.cpp,v 1.1 2008/04/18 14:10:43 glenlow Exp $ $Revision: 1.1 $ */
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

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "gvplugin_loadimage.h"
#include "gvplugin_gdiplus.h"

#include <windows.h>
#include "GdiPlus.h"

#include "FileStream.h"

using namespace Gdiplus;

static void gdiplus_freeimage(usershape_t *us)
{
	delete (Image*)us->data;
}

static Image* gdiplus_loadimage(GVJ_t * job, usershape_t *us)
{
    assert(job);
    assert(us);
    assert(us->name);

    if (us->data && us->datafree != gdiplus_freeimage) {
	     us->datafree(us);        /* free incompatible cache data */
	     us->data = NULL;
	     us->datafree = NULL;
	}
    
    if (!us->data) { /* read file into cache */
		if (!gvusershape_file_access(us))
			return NULL;

		/* create image from the usershape file */
		/* NOTE: since Image::FromStream consumes the stream, we assume FileStream's lifetime should be shorter than us->name and us->f... */	
		IStream *stream = FileStream::Create(us->name, us->f);
		us->data = Image::FromStream (stream);
		
		/* clean up */
		if (us->data)
			us->datafree = gdiplus_freeimage;
		stream->Release();
			
		gvusershape_file_release(us);
    }
    return (Image *)(us->data);
}

static void gdiplus_loadimage_gdiplus(GVJ_t * job, usershape_t *us, boxf b, boolean filled)
{
	/* get the image from usershape details, then blit it to the context */
	Image *image = gdiplus_loadimage(job, us);
	if (image)
		((Graphics *)job->context)->DrawImage(image, RectF(b.LL.x, b.LL.y, b.UR.x - b.LL.x, b.UR.y - b.LL.y));
}

static gvloadimage_engine_t engine = {
    gdiplus_loadimage_gdiplus
};

gvplugin_installed_t gvloadimage_gdiplus_types[] = {
	{FORMAT_BMP, "bmp:gdiplus", 8, &engine, NULL},
	{FORMAT_GIF, "gif:gdiplus", 8, &engine, NULL},
	{FORMAT_JPEG, "jpe:gdiplus", 8, &engine, NULL},
	{FORMAT_JPEG, "jpeg:gdiplus", 8, &engine, NULL},
	{FORMAT_JPEG, "jpg:gdiplus", 8, &engine, NULL},
	{FORMAT_PNG, "png:gdiplus", 8, &engine, NULL},
	{0, NULL, 0, NULL, NULL}
};
