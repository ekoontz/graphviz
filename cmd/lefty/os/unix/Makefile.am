# $Id: Makefile.am,v 1.3 2006/04/07 18:50:31 ellson Exp $ $Revision: 1.3 $
## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = -I$(top_srcdir)/cmd/lefty

if WITH_X
noinst_LTLIBRARIES = libos.la
endif

libos_la_SOURCES = io.c

EXTRA_DIST = $(libos_la_SOURCES)
