/* $Id: pathaccess.c,v 1.2 2007/05/03 19:09:15 erg Exp $ $Revision: 1.2 $ */
/* vim:set shiftwidth=4 ts=8: */

/**********************************************************
*      This software is part of the graphviz package      *
*                http://www.graphviz.org/                 *
*                                                         *
*            Copyright (c) 1994-2004 AT&T Corp.           *
*                and is licensed under the                *
*            Common Public License, Version 1.0           *
*                      by AT&T Corp.                      *
*                                                         *
*        Information and Software Systems Research        *
*              AT&T Research, Florham Park NJ             *
**********************************************************/

/*
 * Glenn Fowler
 * AT&T Bell Laboratories
 *
 * return path to file a/b with access mode using : separated dirs
 * both a and b may be 0
 * if (mode&PATH_REGULAR) then path must not be a directory
 * if (mode&PATH_ABSOLUTE) then path must be rooted
 * path returned in path buffer
 */

#include <ast.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#else
#include <compat_unistd.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>

/* #include <ls.h> */

char *pathcanon(char *path, int flags);

char *pathaccess(register char *path, register const char *dirs,
		 const char *a, const char *b, register int mode)
{
    register int m = 0;
    int sep = ':';
    char cwd[PATH_MAX];
    struct stat st;

#ifdef EFF_ONLY_OK
    m |= EFF_ONLY_OK;
#endif
#ifdef EX_OK
    if (mode == (PATH_EXECUTE | PATH_REGULAR)) {
	mode &= ~PATH_REGULAR;
	m |= EX_OK;
    } else
#endif
    {
	if (mode & PATH_READ)
	    m |= R_OK;
	if (mode & PATH_WRITE)
	    m |= W_OK;
	if (mode & PATH_EXECUTE)
	    m |= X_OK;
    }
    do {
	dirs = pathcat(path, dirs, sep, a, b);
	pathcanon(path, 0);
	if (!access(path, m)) {
	    if ((mode & PATH_REGULAR)
		&& (stat(path, &st) || S_ISDIR(st.st_mode)))
		continue;
	    if (*path == '/' || !(mode & PATH_ABSOLUTE))
		return (path);
	    dirs = getcwd(cwd, sizeof(cwd));
	    sep = 0;
	}
    } while (dirs);
    return (0);
}
