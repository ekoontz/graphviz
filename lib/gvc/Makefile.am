# $Id: Makefile.am,v 1.76 2008/05/01 06:25:50 glenlow Exp $ $Revision: 1.76 $
## Process this file with automake to produce Makefile.in

pdfdir = $(pkgdatadir)/doc/pdf
pkgconfigdir = $(libdir)/pkgconfig

AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/lib/common \
	-I$(top_srcdir)/lib/pathplan \
	-I$(top_srcdir)/lib/graph \
	-I$(top_srcdir)/lib/cdt \
	$(INCLTDL) -I$(top_srcdir)/libltdl \
	-DGVLIBDIR=\"$(pkglibdir)\"

LIBS = $(LIBLTDL) $(SOCKET_LIBS) $(Z_LIBS) $(MATH_LIBS)

pkginclude_HEADERS = gvc.h gvcext.h gvplugin.h gvcjob.h \
	gvcommon.h gvplugin_render.h gvplugin_layout.h \
	gvplugin_textlayout.h gvplugin_device.h gvplugin_loadimage.h \
	dot_builtins.c demand_loading.c no_demand_loading.c
noinst_HEADERS = gvcint.h gvcproc.h
noinst_LTLIBRARIES = libgvc_C.la
lib_LTLIBRARIES = libgvc.la
pkgconfig_DATA = libgvc.pc

# if using plugins, don't bother installing libgvc_builtins
if ENABLE_SHARED
if ENABLE_LTDL
noinst_LTLIBRARIES += libgvc_builtins.la
else
lib_LTLIBRARIES += libgvc_builtins.la
pkgconfig_DATA += libgvc_builtins.pc
endif
else
lib_LTLIBRARIES += libgvc_builtins.la
pkgconfig_DATA += libgvc_builtins.pc
endif

man_MANS = gvc.3
pdf_DATA = gvc.pdf

libgvc_C_la_SOURCES = gvrender.c gvlayout.c gvdevice.c gvloadimage.c \
	gvcontext.c gvjobs.c gvevent.c gvplugin.c gvconfig.c \
	gvtextlayout.c gvusershape.c gvc.c
libgvc_C_la_LIBADD = $(top_builddir)/lib/common/libcommon_C.la \
	$(top_builddir)/lib/pack/libpack_C.la

#For use with plugins.
#   so it is linked with an empty table of builtins.
libgvc_la_LDFLAGS = -version-info @VERSION_INFO@ -no-undefined
libgvc_la_SOURCES = $(libgvc_C_la_SOURCES) no_builtins.c demand_loading.c
libgvc_la_LIBADD = $(libgvc_C_la_LIBADD) \
	$(top_builddir)/lib/cdt/libcdt.la \
	$(top_builddir)/lib/graph/libgraph.la \
	$(top_builddir)/lib/pathplan/libpathplan.la \
	@EXPAT_LIBS@ @Z_LIBS@ @MATH_LIBS@

#For use without plugins.
#  so it needs to be linked with a preset table of builtins, e.g. dot_builtins.c,
#  		with either demand_loading.c or no_demand_loading.c,
#  		and with the plugins themselves, e.g.
#  -lgvplugin_dot_layout -lgvplugin_neato_layout -lgvplugin_gd -lgvplugin_pangocairo
libgvc_builtins_la_LDFLAGS = -version-info @VERSION_INFO@
libgvc_builtins_la_SOURCES = $(libgvc_C_la_SOURCES)
libgvc_builtins_la_LIBADD = $(libgvc_la_LIBADD)

.3.pdf:
	-groff -Tps -man $< | ps2pdf - - > $@

EXTRA_DIST = $(man_MANS) $(pdf_DATA) Makefile.old regex_win32.h regex_win32.c

DISTCLEANFILES = $(pdf_DATA)
