# $Id: graphviz.spec.in,v 1.173 2008/06/04 15:50:22 ellson Exp $ $Revision: 1.173 $
# graphviz.spec.  Generated from graphviz.spec.in by configure.

# Note: pre gd-2.0.34 graphviz uses its own gd tree with gif support and other fixes

#-- Global graphviz rpm and src.rpm tags-------------------------------------
Name:    graphviz
Summary: Graph Visualization Tools
Version: 2.20.2

%define truerelease 1
%{?distroagnostic: %define release %{truerelease}}
%{!?distroagnostic: %define release %{truerelease}%{?dist}}

Release: %{?release}

Group:   Applications/Multimedia
License: CPL
URL:     http://www.graphviz.org/
Source0: http://www.graphviz.org/pub/graphviz/ARCHIVE/graphviz-2.20.2.tar.gz

# graphviz is relocatable - Caution: this feature is used in AT&T,
#   but probably will not be supported in Redhat/Fedora/Centos distros
Prefix: /usr

#-- feature and package selection -------------------------------------------
#   depends on %dist and %fedora (or %rhl or %rhel) which are set
#   in .rpmmacros on each build host

# All features are off (undefined) by default
# To enable, use: <percent>define FEATURE 1
# Available features are:
#    SHARP GUILE _IO JAVA LUA OCAML PERL PHP PYTHON RUBY R_LANG
#    TCL IPSEPCOLA MYLIBGD PANGOCAIRO RSVG GLITZ SMYRNA DEVIL MING GDK_PIXBUF

# SuSE uses a different mechanism to generate BuildRequires
# norootforbuild
# neededforbuild  expat freetype2 freetype2-devel gcc libjpeg libpng-devel-packages tcl tcl-devel tk tk-devel x-devel-packages

BuildRoot:     %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

BuildRequires: zlib-devel libpng-devel libjpeg-devel expat-devel
BuildRequires: /bin/ksh bison m4 flex swig tk tcl >= 8.3 freetype-devel >= 2

#-- Red Hat Linux specific Build Requirements -------------------------------

%if 0%{?rhl}
# ***NB***
#
#  This spec file no longer works for redhat[789].   The rpmbuild
#  on those systems is just too old and broken!
#
%define TCL 1
BuildRequires: XFree86-devel
# This just indicates the requirement for tcl.h, tk.h, but doesn't identify
# where to get them from. In RH9 and earlier they were in the tcl, tk,
# base packages which are always BR'd anyway (above).
BuildRequires:  /usr/include/tcl.h /usr/include/tk.h
%endif

#-- Red Hat Enterprise Linux specific Build Requirements --------------------
%if 0%{?rhel}
%define TCL 1
%if %rhel < 4
BuildRequires:  XFree86-devel
# This just indicates the requirement for tcl.h, tk.h, but doesn't identify
# where to get them from. In RH9 and earlier they were in the tcl, tk,
# base packages which are always BR'd anyway (above).
BuildRequires:  /usr/include/tcl.h /usr/include/tk.h
%endif
%if %rhel >= 3
%define IPSEPCOLA 1
BuildRequires: fontconfig-devel tcl-devel tk-devel 
%endif
%if %rhel == 4
BuildRequires: xorg-x11-devel
%endif
%if %rhel >= 4
# PERL is available earlier, but a suitable SWIG isn't
%define PERL 1
%define RUBY 1
%define GUILE 1
%define PYTHON 1
BuildRequires: perl ruby-devel guile-devel python-devel
%endif
%if %rhel >= 5
%define JAVA 1
%define PANGOCAIRO 1
%define RSVG 1
BuildRequires: libtool-ltdl libtool-ltdl-devel libXaw-devel libSM-devel libICE-devel libXpm-devel libXt-devel libXmu-devel libXext-devel libX11-devel java-devel
BuildRequires: cairo-devel >= 1.1.10 pango-devel gmp-devel gtk2-devel libgnomeui-devel
BuildRequires: librsvg2-devel
%endif
%if %rhel >= 6
%define PHP 1
%define MYLIBGD 1
%define GDK_PIXBUF 1
BuildRequires: gd gd-devel perl-devel php-devel
%endif
%endif

#-- AT&T-internal Red Hat Enterprise Linux specific Build Requirements --------------------
%if 0%{?att_rhel}
%define TCL 1
%if %att_rhel < 4
BuildRequires:  XFree86-devel
# This just indicates the requirement for tcl.h, tk.h, but doesn't identify
# where to get them from. In RH9 and earlier they were in the tcl, tk,
# base packages which are always BR'd anyway (above).
BuildRequires:  /usr/include/tcl.h /usr/include/tk.h
%endif
%if %att_rhel >= 3
%define IPSEPCOLA 1
BuildRequires: fontconfig-devel tcl-devel tk-devel 
%endif
%if %att_rhel == 4
BuildRequires: xorg-x11-devel
%endif
%if %att_rhel >= 4
# PERL is available earlier, but a suitable SWIG isn't
%define PERL 1
%define RUBY 1
%define GUILE 1
%define PYTHON 1
BuildRequires: perl ruby-devel guile-devel python-devel
%endif
%if %att_rhel >= 5
%define JAVA 1
%define PANGOCAIRO 1
%define RSVG 1
%define SFDP 1
BuildRequires: libtool-ltdl libtool-ltdl-devel libXaw-devel libSM-devel libICE-devel libXpm-devel libXt-devel libXmu-devel libXext-devel libX11-devel java-devel
BuildRequires: cairo-devel >= 1.1.10 pango-devel gmp-devel gtk2-devel libgnomeui-devel
BuildRequires: librsvg2-devel
%endif
%if %att_rhel >= 6
%define PHP 1
%define GDK_PIXBUF 1
#%define SMYRNA 1
#BuildRequires: gtkglarea2-devel gtkglext-devel glade3-libgladeui-devel gts-devel
BuildRequires: gd gd-devel perl-devel php-devel
%endif
%endif

#-- Fedora specific Build Requirements --------------------------------------
%if 0%{?fedora}
%define PERL 1
%define TCL 1
BuildRequires: fontconfig-devel tcl-devel tk-devel 
%if %fedora < 3
BuildRequires: XFree86-devel
%endif
%if %fedora == 3
BuildRequires: xorg-x11-devel
%endif
%if %fedora == 4
BuildRequires: xorg-x11-devel
%endif
%if %fedora >= 3
%define IPSEPCOLA 1
%endif
%if %fedora >= 4
%define RUBY 1
%define GUILE 1
%define PYTHON 1
BuildRequires: libtool-ltdl libtool-ltdl-devel ruby ruby-devel guile-devel python-devel
%endif
%if %fedora >= 5
%define PHP 1
%define JAVA 1
BuildRequires: libXaw-devel libSM-devel libICE-devel libXpm-devel libXt-devel libXmu-devel libXext-devel libX11-devel java-devel php-devel
%ifnarch ppc64
%define SHARP 1
%define OCAML 1
BuildRequires: mono-core ocaml
%endif
%endif
%if %fedora >= 6
%define LUA 1
%define PANGOCAIRO 1
%define RSVG 1
BuildRequires: cairo-devel >= 1.1.10 pango-devel gmp-devel lua-devel gtk2-devel libgnomeui-devel
BuildRequires: librsvg2-devel
%endif
%if %fedora >= 7
%define DEVIL 1
%define GDK_PIXBUF 1
BuildRequires: gd gd-devel perl-devel DevIL-devel
%endif
%if %fedora >= 8
%define R_LANG 1
BuildRequires: R-devel swig >= 1.3.33
#
# packaging is ok, but code is not ready for distribution
#
#define SMYRNA 1
# BuildRequires: gtkglarea2-devel gtkglext-devel glade3-libgladeui-devel gts-devel
#define GLITZ 1
# BuildRequires: glitz-devel
%endif
%if %fedora >= 9
#define MING 1
#BuildRequires: ming ming-devel
%endif
%endif

#-- AT&T-internal Fedora specific Build Requirements --------------------------------------
%if 0%{?att_fedora}
%define PERL 1
%define TCL 1
BuildRequires: fontconfig-devel tcl-devel tk-devel 
%if %att_fedora < 3
BuildRequires: XFree86-devel
%endif
%if %att_fedora == 3
BuildRequires: xorg-x11-devel
%endif
%if %att_fedora == 4
BuildRequires: xorg-x11-devel
%endif
%if %att_fedora >= 3
%define IPSEPCOLA 1
%endif
%if %att_fedora >= 4
%define RUBY 1
%define GUILE 1
%define PYTHON 1
BuildRequires: libtool-ltdl libtool-ltdl-devel ruby ruby-devel guile-devel python-devel
%endif
%if %att_fedora >= 5
%define PHP 1
%define JAVA 1
BuildRequires: libXaw-devel libSM-devel libICE-devel libXpm-devel libXt-devel libXmu-devel libXext-devel libX11-devel java-devel php-devel
%ifnarch ppc64
%define SHARP 1
%define OCAML 1
BuildRequires: mono-core ocaml
%endif
%endif
%if %att_fedora >= 6
%define LUA 1
%define PANGOCAIRO 1
%define RSVG 1
BuildRequires: cairo-devel >= 1.1.10 pango-devel gmp-devel lua-devel gtk2-devel libgnomeui-devel
BuildRequires: librsvg2-devel
%endif
%if %att_fedora >= 7
%define DEVIL 1
%define GDK_PIXBUF 1
%define SMYRNA 1
%define SFDP 1
BuildRequires: gd gd-devel perl-devel DevIL-devel
BuildRequires: gtkglarea2-devel gtkglext-devel glade3-libgladeui-devel gts-devel
%endif
%if %att_fedora >= 8
%define R_LANG 1
BuildRequires: R-devel swig >= 1.3.33
#define GLITZ 1
# BuildRequires: glitz-devel
%endif
%if %att_fedora >= 9
#define MING 1
#BuildRequires: ming ming-devel
%endif
%endif

#-- main graphviz rpm ------------------------------------------------
Requires:         urw-fonts
Requires(post):   /sbin/ldconfig
Requires(postun): /sbin/ldconfig

%description
A collection of tools for the manipulation and layout
of graphs (as in nodes and edges, not as in barcharts).

# run "dot -c" to generate plugin config in %{libdir}/graphviz/config
# (don't rely on ldconfig to find libraries since it won't
#  help if --prefix was used to relocate binaries)
%post
LD_LIBRARY_PATH=$RPM_INSTALL_PREFIX0/%{_lib} $RPM_INSTALL_PREFIX0/bin/dot -c
/sbin/ldconfig

# if there is no dot after everything else is done, then remove config
%postun
if [ $1 -eq 0 ]; then
        rm -f $RPM_INSTALL_PREFIX0/%{_lib}/graphviz/config || :
fi
/sbin/ldconfig

%files
%defattr(-,root,root,-)
%doc AUTHORS COPYING ChangeLog NEWS README
%{_bindir}/*
%dir %{_libdir}/graphviz
%{_libdir}/*.so.*
%{_libdir}/graphviz/*.so.*
%{_mandir}/man1/*.1*
%{_mandir}/man7/*.7*
%dir %{_datadir}/graphviz
%{_datadir}/graphviz/lefty
%exclude %{_libdir}/graphviz/libgvplugin_gd.*
%if 0%{?DEVIL}
%exclude %{_libdir}/graphviz/libgvplugin_devil.*
%endif
%if 0%{?MING}
%exclude %{_libdir}/graphviz/libgvplugin_ming.*
%exclude %{_libdir}/graphviz/*fdb
%endif
%if 0%{?SMYRNA}
%{_datadir}/graphviz/smyrna
%{_datadir}/graphviz/examples
%endif

#-- graphviz-gd rpm --------------------------------------------------
%package gd
Group:            Applications/Multimedia
Summary:          Graphviz plugin for renderers based on gd
Requires:         graphviz = %{version}-%{release}

%description gd
Graphviz plugin for renderers based on gd.  (Unless you absolutely have
to use GIF, you are recommended to use the PNG format instead because
of the better quality anti-aliased lines provided by the cairo+pango
based renderer.)

# run "dot -c" to generate plugin config in %{_libdir}/graphviz/config
%post gd
LD_LIBRARY_PATH=$RPM_INSTALL_PREFIX0/%{_lib} $RPM_INSTALL_PREFIX0/bin/dot -c

%postun gd
[ -x $RPM_INSTALL_PREFIX0/bin/dot ] && LD_LIBRARY_PATH=$RPM_INSTALL_PREFIX0/%{_lib} $RPM_INSTALL_PREFIX0/bin/dot -c || :

%files gd
%{_libdir}/graphviz/libgvplugin_gd.so.*

#-- graphviz-devil rpm --------------------------------------------------
%if 0%{?DEVIL}
%package devil
Group:            Applications/Multimedia
Summary:          Graphviz plugin for renderers based on DevIL
Requires:         graphviz = %{version}-%{release}

%description devil
Graphviz plugin for renderers based on DevIL.  (Unless you absolutely have
to use BMP, TIF, or TGA, you are recommended to use the PNG format instead
supported directly by the cairo+pango based renderer in the base graphviz rpm.)

# run "dot -c" to generate plugin config in %{_libdir}/graphviz/config
%post devil
LD_LIBRARY_PATH=$RPM_INSTALL_PREFIX0/%{_lib} $RPM_INSTALL_PREFIX0/bin/dot -c

%postun devil
[ -x $RPM_INSTALL_PREFIX0/bin/dot ] && LD_LIBRARY_PATH=$RPM_INSTALL_PREFIX0/%{_lib} $RPM_INSTALL_PREFIX0/bin/dot -c || :

%files devil
%{_libdir}/graphviz/libgvplugin_devil.so.*
%endif

#-- graphviz-ming rpm --------------------------------------------------
%if 0%{?MING}
%package ming
Group:            Applications/Multimedia
Summary:          Graphviz plugin for flash renderer based on ming
Requires:         graphviz = %{version}-%{release}

%description ming
Graphviz plugin for -Tswf (flash) renderer based on ming.

# run "dot -c" to generate plugin config in %{_libdir}/graphviz/config
%post ming
LD_LIBRARY_PATH=$RPM_INSTALL_PREFIX0/%{_lib} $RPM_INSTALL_PREFIX0/bin/dot -c

%postun ming
[ -x $RPM_INSTALL_PREFIX0/bin/dot ] && LD_LIBRARY_PATH=$RPM_INSTALL_PREFIX0/%{_lib} $RPM_INSTALL_PREFIX0/bin/dot -c || :

%files ming
%{_libdir}/graphviz/libgvplugin_ming.so.*
%{_libdir}/graphviz/*fdb
%endif

#-- graphviz-sharp rpm --------------------------------------------
%if 0%{?SHARP}
%package sharp
Group:          Applications/Multimedia
Summary:        C# extension for graphviz
Requires:       graphviz = %{version}-%{release} mono-core

%description sharp
C# extension for graphviz.

%files sharp
%defattr(-,root,root,-)
%dir %{_libdir}/graphviz/sharp
%{_libdir}/graphviz/sharp/*
%{_mandir}/mann/gv_sharp.n*
%endif

#-- graphviz-guile rpm --------------------------------------------
%if 0%{?GUILE}
%package guile
Group:          Applications/Multimedia
Summary:        Guile extension for graphviz
Requires:       graphviz = %{version}-%{release} guile

%description guile
Guile extension for graphviz.

%files guile
%defattr(-,root,root,-)
%dir %{_libdir}/graphviz/guile
%{_libdir}/graphviz/guile/*
%{_mandir}/mann/gv_guile.n*
%endif

#-- graphviz-io rpm -----------------------------------------------
%if 0%{?_IO}
%package io
Group:          Applications/Multimedia
Summary:        Io extension for graphviz
Requires:       graphviz = %{version}-%{release} io

%description io
Io extension for graphviz.

%files io
%defattr(-,root,root,-)
%dir %{_libdir}/graphviz/io
%{_libdir}/graphviz/io/*
%{_mandir}/mann/gv_io.n*
%endif

#-- graphviz-java rpm ---------------------------------------------
%if 0%{?JAVA}
%package java
Group:          Applications/Multimedia
Summary:        Java extension for graphviz
Requires:       graphviz = %{version}-%{release} java

%description java
Java extension for graphviz.

%files java
%defattr(-,root,root,-)
%dir %{_libdir}/graphviz/java
%{_libdir}/graphviz/java/*
%{_mandir}/mann/gv_java.n*
%endif

#-- graphviz-lua rpm ----------------------------------------------
%if 0%{?LUA}
%package lua
Group:          Applications/Multimedia
Summary:        Lua extension for graphviz
Requires:       graphviz = %{version}-%{release} lua

%description lua
Lua extension for graphviz.

%files lua
%defattr(-,root,root,-)
%dir %{_libdir}/graphviz/lua
%{_libdir}/graphviz/lua/*
%{_libdir}/lua*/*
%{_datadir}/graphviz/demo/*.lua*
%{_mandir}/mann/gv_lua.n*
%endif

#-- graphviz-ocaml rpm --------------------------------------------
%if 0%{?OCAML}
%package ocaml
Group:          Applications/Multimedia
Summary:        Ocaml extension for graphviz
Requires:       graphviz = %{version}-%{release} ocaml

%description ocaml
Ocaml extension for graphviz.

%files ocaml
%defattr(-,root,root,-)
%dir %{_libdir}/graphviz/ocaml
%{_libdir}/graphviz/ocaml/*
%{_mandir}/mann/gv_ocaml.n*
%endif

#-- graphviz-perl rpm ---------------------------------------------
%if 0%{?PERL}
%package perl
Group:          Applications/Multimedia
Summary:        Perl extension for graphviz
Requires:       graphviz = %{version}-%{release} perl

%description perl
Perl extension for graphviz.

%files perl
%defattr(-,root,root,-)
%dir %{_libdir}/graphviz/perl
%{_libdir}/graphviz/perl/*
%{_libdir}/perl*/*
%{_datadir}/graphviz/demo/*.pl*
%{_mandir}/mann/gv_perl.n*
%endif

#-- graphviz-php rpm ----------------------------------------------
%if 0%{?PHP}
%package php
Group:          Applications/Multimedia
Summary:        PHP extension for graphviz
Requires:       graphviz = %{version}-%{release} php

%description php
PHP extension for graphviz.

%files php
%defattr(-,root,root,-)
%dir %{_libdir}/graphviz/php
%{_libdir}/graphviz/php/*
%{_libdir}/php*/*
%{_datadir}/php*/*
%{_datadir}/graphviz/demo/*.php*
%{_mandir}/mann/gv_php.n*
%endif

#-- graphviz-python rpm -------------------------------------------
%if 0%{?PYTHON}
%package python
Group:          Applications/Multimedia
Summary:        Python extension for graphviz
Requires:       graphviz = %{version}-%{release} python

%description python
Python extension for graphviz.

%files python
%defattr(-,root,root,-)
%dir %{_libdir}/graphviz/python
%{_libdir}/graphviz/python/*
%{_libdir}/python*/*
%{_datadir}/graphviz/demo/*.py*
%{_mandir}/mann/gv_python.n*
%endif

#-- graphviz-R rpm ---------------------------------------------
%if 0%{?R_LANG}
%package R
Group:          Applications/Multimedia
Summary:        R extension for graphviz
Requires:       graphviz = %{version}-%{release} R

%description R
R extension for graphviz.

%files R
%defattr(-,root,root,-)
%dir %{_libdir}/graphviz/R
%{_libdir}/graphviz/R/*
%{_mandir}/mann/gv_R.n*
%endif

#-- graphviz-ruby rpm ---------------------------------------------
%if 0%{?RUBY}
%package ruby
Group:          Applications/Multimedia
Summary:        Ruby extension for graphviz
Requires:       graphviz = %{version}-%{release} ruby

%description ruby
Ruby extension for graphviz.

%files ruby
%defattr(-,root,root,-)
%dir %{_libdir}/graphviz/ruby
%{_libdir}/graphviz/ruby/*
%{_libdir}/*ruby*/*
%{_datadir}/graphviz/demo/*.rb*
%{_mandir}/mann/gv_ruby.n*
%endif

#-- graphviz-tcl rpm ----------------------------------------------
%if 0%{?TCL}
%package tcl
Group:          Applications/Multimedia
Summary:        Tcl extension & tools for graphviz
Requires:       graphviz = %{version}-%{release} tcl >= 8.3 tk

%description tcl
Various tcl packages (extensions) for the graphviz tools.

%files tcl
%defattr(-,root,root,-)
%dir %{_libdir}/graphviz/tcl
%{_libdir}/graphviz/tcl/*
%{_libdir}/tcl*/*
%{_datadir}/graphviz/demo/*.tcl*
%{_datadir}/graphviz/demo/*_data
# hack to include gv_tcl.n only if available
#  always includes tcldot.n, gdtclft.n
%{_mandir}/mann/*tcl*.n*
%{_mandir}/mann/tkspline.n*
%endif

#-- graphviz-devel rpm --------------------------------------------
%package devel
Group:          Development/Libraries
Summary:        Development package for graphviz
Requires:       graphviz = %{version}-%{release} pkgconfig

%description devel
A collection of tools for the manipulation and layout
of graphs (as in nodes and edges, not as in barcharts).
This package contains development files for graphviz.

%files devel
%defattr(-,root,root,-)
%{_includedir}/graphviz
%{_libdir}/*.so
%{_libdir}/pkgconfig/*.pc
%{_mandir}/man3/*.3*
%exclude %{_libdir}/graphviz/libgvplugin*
%exclude %{_libdir}/graphviz/*.so

#-- graphviz-graphs rpm -------------------------------------------
%package graphs
Group:          Applications/Multimedia
Summary:        Demo graphs for graphviz

%description graphs
Some demo graphs for graphviz.

%files graphs
%defattr(-,root,root,-)
%dir %{_datadir}/graphviz
%{_datadir}/graphviz/graphs

#-- graphviz-doc rpm ----------------------------------------------
%package doc
Group:          Documentation
Summary:        PDF and HTML documents for graphviz

%description doc
Provides some additional PDF and HTML documentation for graphviz.

%files doc
%defattr(-,root,root,-)
%doc __doc/*

#-- building --------------------------------------------------

%prep
%setup -q

%build
# XXX ix86 only used to have -ffast-math, let's use everywhere
%{expand: %%define optflags %{optflags} -ffast-math}

# %%configure is broken in RH7.3 rpmbuild
CFLAGS="$RPM_OPT_FLAGS" \
./configure \
        --prefix=%{_prefix} \
        --bindir=%{_bindir} \
        --libdir=%{_libdir} \
        --includedir=%{_includedir} \
        --datadir=%{_datadir} \
        --mandir=%{_mandir} \
        --with-x \
	--disable-static \
        --disable-dependency-tracking \
	--enable-sharp%{!?SHARP:=no} \
	--enable-guile%{!?GUILE:=no} \
	--enable-io%{!?_IO:=no} \
	--enable-java%{!?JAVA:=no} \
	--enable-lua%{!?LUA:=no} \
	--enable-ocaml%{!?OCAML:=no} \
	--enable-perl%{!?PERL:=no} \
	--enable-php%{!?PHP:=no} \
	--enable-python%{!?PYTHON:=no} \
	--enable-r%{!?R_LANG:=no} \
	--enable-ruby%{!?RUBY:=no} \
	--enable-tcl%{!?TCL:=no} \
	--with%{!?DEVIL:out}-devil \
	--with%{!?IPSEPCOLA:out}-ipsepcola \
	--with%{!?MING:out}-ming \
	--with%{!?SMYRNA:out}-smyrna \
	--with%{!?SFDP:out}-sfdp \
	--with%{!?GLITZ:out}-glitz \
	--with%{!?PANGOCAIRO:out}-pangocairo \
	--with%{!?RSVG:out}-rsvg \
	--with%{!?GDK_PIXBUF:out}-gdk-pixbuf
make %{?_smp_mflags}

%install
rm -rf %{buildroot} __doc
make DESTDIR=%{buildroot} \
        docdir=%{buildroot}%{_docdir}/%{name} \
        pkgconfigdir=%{_libdir}/pkgconfig \
        install
find %{buildroot} -type f -name "*.la" -exec rm -f {} ';'
chmod -x %{buildroot}%{_datadir}/%{name}/lefty/*
cp -a %{buildroot}%{_datadir}/%{name}/doc __doc
rm -rf %{buildroot}%{_datadir}/%{name}/doc

%clean
# regression test
cd rtest
make rtest
# clean up temporary installation
rm -rf %{buildroot}

#-- changelog --------------------------------------------------

%changelog
* Fri Oct 26 2007 John Ellson <ellson@research.att.com>
- reinstated binary relocatability in AT&T's rpms since we need it internally
* Wed Aug 15 2007 John Ellson <ellson@research.att.com>
- release 2.14.1 - see ChangeLog for details
* Wed Aug 2 2007 John Ellson <ellson@research.att.com>
- release 2.14 - see ChangeLog for details
* Fri Mar 16 2007 Stephen North <north@research.att.com>
- remove xorg-X11-devel from rhel >= 5
* Mon Dec 11 2006 John Ellson <john.ellson@comcast.net>
- fix graphviz-lua description (Fedora BZ#218191)
* Tue Sep 13 2005 John Ellson <ellson@research.att.com>
- split out language bindings into their own rpms so that 
  main rpm doesn't depend on (e.g.) ocaml

* Sat Aug 13 2005 John Ellson <ellson@research.att.com>
- imported various fixes from the Fedora-Extras .spec by Oliver Falk <oliver@linux-kernel.at>

* Wed Jul 20 2005 John Ellson <ellson@research.att.com>
- release 2.4
