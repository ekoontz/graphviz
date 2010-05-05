:PACKAGE: graphviz 

.SOURCE.h : ../../lib/cdt ../../lib/graph ../../lib/gvc ../../lib/common \
        ../../lib/pathplan

gvplugin_core $(LIBVERSION) :LIBRARY: gvplugin_core.c gvrender_core_ps.c \
	gvrender_core_svg.c gvrender_core_map.c gvloadimage_core.c \
	gvrender_core.c gvrender_core_dot.c gvrender_core_fig.c \
	-lcommon

