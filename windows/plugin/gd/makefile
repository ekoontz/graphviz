:PACKAGE: graphviz 

.SOURCE.h : ../../lib/cdt ../../lib/graph ../../lib/gvc ../../lib/common \
        ../../lib/pathplan ../../lib/gd

gvplugin_gd $(LIBVERSION) :LIBRARY: gvloadimage_gd.c gvplugin_gd.c \
	gvrender_gd.c gvrender_gd_vrml.c gvtextlayout_gd.c \
	-lgd -lcommon

