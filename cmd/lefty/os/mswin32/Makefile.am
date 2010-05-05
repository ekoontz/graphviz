# $Id: Makefile.am,v 1.2 2007/03/13 18:52:22 ellson Exp $ $Revision: 1.2 $
## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = -I$(top_srcdir)/cmd/lefty

if WITH_WIN32
noinst_LTLIBRARIES = libos.la
endif

libos_la_SOURCES = io.c

EXTRA_DIST = $(libos_la_SOURCES)
