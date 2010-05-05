:PACKAGE: graphviz

.SOURCE.h : ../cdt

graph $(LIBVERSION) :LIBRARY: graph.3 agxbuf.c attribs.c edge.c \
	graph.c graphio.c lexer.c node.c parser.c refstr.c trie.c -lcdt

$(INCLUDEDIR) :INSTALLDIR: graph.h

parser.h : .TERMINAL

:: graph.pdf
