# $Id: Makefile.am,v 1.15 2008/05/21 20:37:40 ellson Exp $ $Revision: 1.15 $
## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/lib/common \
	-I$(top_srcdir)/lib/pathplan \
	-I$(top_srcdir)/lib/gvc \
	-I$(top_srcdir)/lib/graph \
	-I$(top_srcdir)/lib/cdt \
	$(GD_INCLUDES) $(LIBGVC_CFLAGS)

noinst_LTLIBRARIES = libgvplugin_gd_C.la

if WITH_WIN32
lib_LTLIBRARIES = libgvplugin_gd.la
else
pkglib_LTLIBRARIES = libgvplugin_gd.la
endif

libgvplugin_gd_C_la_SOURCES = \
	gvplugin_gd.c \
	gvrender_gd.c \
	gvrender_gd_vrml.c \
	gvtextlayout_gd.c \
	gvloadimage_gd.c \
	gvdevice_gd.c

libgvplugin_gd_la_LDFLAGS = -version-info @GVPLUGIN_VERSION_INFO@
libgvplugin_gd_la_SOURCES = $(libgvplugin_gd_C_la_SOURCES)
if WITH_MYLIBGD
libgvplugin_gd_la_LIBADD = \
	$(top_builddir)/lib/gd/libgvgd_C.la \
	$(top_builddir)/lib/gvc/libgvc.la \
	$(top_builddir)/lib/graph/libgraph.la \
	$(top_builddir)/lib/cdt/libcdt.la \
	@ICONV_LIBS@ @FONTCONFIG_LIBS@ @FREETYPE2_LIBS@ @JPEG_LIBS@ @PNG_LIBS@ @EXPAT_LIBS@ @Z_LIBS@ @MATH_LIBS@
AM_CPPFLAGS += -DNONDLL
else
libgvplugin_gd_la_LIBADD = \
	$(top_builddir)/lib/gvc/libgvc.la \
	$(top_builddir)/lib/graph/libgraph.la \
	$(top_builddir)/lib/cdt/libcdt.la @GD_LIBS@ @MATH_LIBS@
endif

if WITH_WIN32
libgvplugin_gd_la_LDFLAGS += -no-undefined
libgvplugin_gd_la_LIBADD += $(top_builddir)/lib/graph/libgraph.la $(top_builddir)/lib/pathplan/libpathplan.la
endif

if WITH_DARWIN9
libgvplugin_gd_la_LDFLAGS += -Wl,-exported_symbol,_gvplugin_gd_LTX_library
endif

EXTRA_DIST = Makefile.old

