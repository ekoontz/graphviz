# $Id: Makefile.am,v 1.4 2006/06/01 12:37:36 ellson Exp $ $Revision: 1.4 $
## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = @X_CFLAGS@ \
	$(XAW_INCLUDES)

noinst_HEADERS = SFinternal.h SFDecls.h xstat.h SF.h
if WITH_X
if WITH_XAW
noinst_LTLIBRARIES = libfilereq.la
endif
endif

libfilereq_la_SOURCES = Dir.c Draw.c Path.c SelFile.c
libfilereq_la_LIBADD = $(XAW_LIBS)

EXTRA_DIST = README.selfile
