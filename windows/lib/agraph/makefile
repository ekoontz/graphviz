:PACKAGE: graphviz

.SOURCE.h : ../cdt

agraph $(LIBVERSION) :LIBRARY: agraph.3 agerror.c apply.c attr.c edge.c \
	flatten.c grammar.c graph.c id.c imap.c io.c mem.c node.c obj.c \
	pend.c rec.c refstr.c scan.c subg.c utils.c write.c -lcdt

$(INCLUDEDIR) :INSTALLDIR: agraph.h

grammar.h : .TERMINAL

:: agraph.pdf
