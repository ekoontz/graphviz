# $Id: Makefile.am,v 1.9 2007/08/23 03:17:43 ellson Exp $ $Revision: 1.9 $
## Process this file with automake to produce Makefile.in

pdfdir = $(pkgdatadir)/doc/pdf
pkgconfigdir = $(libdir)/pkgconfig

pkginclude_HEADERS = pathgeom.h pathplan.h
noinst_HEADERS = pathutil.h solvers.h tri.h vis.h vispath.h

noinst_LTLIBRARIES = libpathplan_C.la
lib_LTLIBRARIES = libpathplan.la
pkgconfig_DATA = libpathplan.pc
man_MANS = pathplan.3
pdf_DATA = pathplan.pdf

libpathplan_C_la_SOURCES = cvt.c inpoly.c route.c shortest.c \
	shortestpth.c solvers.c triang.c util.c visibility.c

libpathplan_la_LDFLAGS = -version-info @VERSION_INFO@ -no-undefined
libpathplan_la_SOURCES = $(libpathplan_C_la_SOURCES)
libpathplan_la_LIBADD = @MATH_LIBS@

.3.pdf:
	-groff -Tps -man $< | ps2pdf - - >$@

EXTRA_DIST = $(man_MANS) $(pdf_DATA) Makefile.old path.lefty

DISTCLEANFILES = $(pdf_DATA)
