:PACKAGE: graphviz

.SOURCE.h : ../cdt ../graph ../common ../pathplan

gvc $(LIBVERSION) :LIBRARY: gvc.c gvc.3 gvconfig.c \
	gvcontext.c gvdevice.c gvevent.c gvjobs.c gvlayout.c gvloadimage.c \
	gvplugin.c gvrender.c gvtextlayout.c gvusershape.c dot_builtins.c \
	-lgraph -lcommon -lpathplan

/* gvc_dot_builtins $(LIBVERSION) :LIBRARY: dot_builtins.c \
	-lgvc -lcdt -lgraph -lpathplan -lcommon
*/

$(INCLUDEDIR) :INSTALLDIR: gvc.h gvcext.h gvcjob.h gvplugin.h \
	gvplugin_layout.h gvplugin_render.h \
    gvcommon.h gvplugin_textlayout.h gvplugin_loadimage.h

:: gvc.pdf
