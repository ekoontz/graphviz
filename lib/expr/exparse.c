/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with ex or EX, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define EXBISON 1

/* Bison version.  */
#define EXBISON_VERSION "2.3"

/* Skeleton name.  */
#define EXSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define EXPURE 0

/* Using locations.  */
#define EXLSP_NEEDED 0



/* Tokens.  */
#ifndef EXTOKENTYPE
# define EXTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum extokentype {
     MINTOKEN = 258,
     INT = 259,
     INTEGER = 260,
     UNSIGNED = 261,
     CHAR = 262,
     FLOATING = 263,
     STRING = 264,
     VOID = 265,
     ADDRESS = 266,
     ARRAY = 267,
     BREAK = 268,
     CALL = 269,
     CASE = 270,
     CONSTANT = 271,
     CONTINUE = 272,
     DECLARE = 273,
     DEFAULT = 274,
     DYNAMIC = 275,
     ELSE = 276,
     EXIT = 277,
     FOR = 278,
     FUNCTION = 279,
     GSUB = 280,
     ITERATE = 281,
     ID = 282,
     IF = 283,
     LABEL = 284,
     MEMBER = 285,
     NAME = 286,
     POS = 287,
     PRAGMA = 288,
     PRE = 289,
     PRINT = 290,
     PRINTF = 291,
     PROCEDURE = 292,
     QUERY = 293,
     RAND = 294,
     RETURN = 295,
     SCANF = 296,
     SPRINTF = 297,
     SRAND = 298,
     SSCANF = 299,
     SUB = 300,
     SUBSTR = 301,
     SWITCH = 302,
     WHILE = 303,
     F2I = 304,
     F2S = 305,
     I2F = 306,
     I2S = 307,
     S2B = 308,
     S2F = 309,
     S2I = 310,
     F2X = 311,
     I2X = 312,
     S2X = 313,
     X2F = 314,
     X2I = 315,
     X2S = 316,
     X2X = 317,
     XPRINT = 318,
     OR = 319,
     AND = 320,
     NE = 321,
     EQ = 322,
     GE = 323,
     LE = 324,
     RS = 325,
     LS = 326,
     UNARY = 327,
     DEC = 328,
     INC = 329,
     CAST = 330,
     MAXTOKEN = 331
   };
#endif
/* Tokens.  */
#define MINTOKEN 258
#define INT 259
#define INTEGER 260
#define UNSIGNED 261
#define CHAR 262
#define FLOATING 263
#define STRING 264
#define VOID 265
#define ADDRESS 266
#define ARRAY 267
#define BREAK 268
#define CALL 269
#define CASE 270
#define CONSTANT 271
#define CONTINUE 272
#define DECLARE 273
#define DEFAULT 274
#define DYNAMIC 275
#define ELSE 276
#define EXIT 277
#define FOR 278
#define FUNCTION 279
#define GSUB 280
#define ITERATE 281
#define ID 282
#define IF 283
#define LABEL 284
#define MEMBER 285
#define NAME 286
#define POS 287
#define PRAGMA 288
#define PRE 289
#define PRINT 290
#define PRINTF 291
#define PROCEDURE 292
#define QUERY 293
#define RAND 294
#define RETURN 295
#define SCANF 296
#define SPRINTF 297
#define SRAND 298
#define SSCANF 299
#define SUB 300
#define SUBSTR 301
#define SWITCH 302
#define WHILE 303
#define F2I 304
#define F2S 305
#define I2F 306
#define I2S 307
#define S2B 308
#define S2F 309
#define S2I 310
#define F2X 311
#define I2X 312
#define S2X 313
#define X2F 314
#define X2I 315
#define X2S 316
#define X2X 317
#define XPRINT 318
#define OR 319
#define AND 320
#define NE 321
#define EQ 322
#define GE 323
#define LE 324
#define RS 325
#define LS 326
#define UNARY 327
#define DEC 328
#define INC 329
#define CAST 330
#define MAXTOKEN 331




/* Copy the first part of user declarations.  */
#line 17 "../../lib/expr/exparse.y"



/*
 * Glenn Fowler
 * AT&T Research
 *
 * expression library grammar and compiler
 *
 * NOTE: procedure arguments not implemented yet
 */

#ifdef WIN32
#include <config.h>

#ifdef GVDLL
#define _BLD_sfio 1
#endif
#endif

#include <stdio.h>
#include <ast.h>

#undef	RS	/* hp.pa <signal.h> grabs this!! */



/* Enabling traces.  */
#ifndef EXDEBUG
# define EXDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef EXERROR_VERBOSE
# undef EXERROR_VERBOSE
# define EXERROR_VERBOSE 1
#else
# define EXERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef EXTOKEN_TABLE
# define EXTOKEN_TABLE 0
#endif

#if ! defined EXSTYPE && ! defined EXSTYPE_IS_DECLARED
typedef union EXSTYPE
#line 45 "../../lib/expr/exparse.y"
{
	struct Exnode_s*expr;
	double		floating;
	struct Exref_s*	reference;
	struct Exid_s*	id;
	Sflong_t	integer;
	int		op;
	char*		string;
	void*		user;
	struct Exbuf_s*	buffer;
}
/* Line 187 of yacc.c.  */
#line 287 "y.tab.c"
	EXSTYPE;
# define exstype EXSTYPE /* obsolescent; will be withdrawn */
# define EXSTYPE_IS_DECLARED 1
# define EXSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 165 "../../lib/expr/exparse.y"


#include "exgram.h"



/* Line 216 of yacc.c.  */
#line 305 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef EXTYPE_UINT8
typedef EXTYPE_UINT8 extype_uint8;
#else
typedef unsigned char extype_uint8;
#endif

#ifdef EXTYPE_INT8
typedef EXTYPE_INT8 extype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char extype_int8;
#else
typedef short int extype_int8;
#endif

#ifdef EXTYPE_UINT16
typedef EXTYPE_UINT16 extype_uint16;
#else
typedef unsigned short int extype_uint16;
#endif

#ifdef EXTYPE_INT16
typedef EXTYPE_INT16 extype_int16;
#else
typedef short int extype_int16;
#endif

#ifndef EXSIZE_T
# ifdef __SIZE_TYPE__
#  define EXSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define EXSIZE_T size_t
# elif ! defined EXSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define EXSIZE_T size_t
# else
#  define EXSIZE_T unsigned int
# endif
#endif

#define EXSIZE_MAXIMUM ((EXSIZE_T) -1)

#ifndef EX_
# if EXENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define EX_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef EX_
#  define EX_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define EXUSE(e) ((void) (e))
#else
# define EXUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define EXID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
EXID (int i)
#else
static int
EXID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined exoverflow || EXERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef EXSTACK_USE_ALLOCA
#  if EXSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define EXSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define EXSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define EXSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef EXSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define EXSTACK_FREE(Ptr) do { /* empty */; } while (EXID (0))
#  ifndef EXSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define EXSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define EXSTACK_ALLOC EXMALLOC
#  define EXSTACK_FREE EXFREE
#  ifndef EXSTACK_ALLOC_MAXIMUM
#   define EXSTACK_ALLOC_MAXIMUM EXSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined EXMALLOC || defined malloc) \
	     && (defined EXFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef EXMALLOC
#   define EXMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (EXSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef EXFREE
#   define EXFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined exoverflow || EXERROR_VERBOSE */


#if (! defined exoverflow \
     && (! defined __cplusplus \
	 || (defined EXSTYPE_IS_TRIVIAL && EXSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union exalloc
{
  extype_int16 exss;
  EXSTYPE exvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define EXSTACK_GAP_MAXIMUM (sizeof (union exalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define EXSTACK_BYTES(N) \
     ((N) * (sizeof (extype_int16) + sizeof (EXSTYPE)) \
      + EXSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef EXCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define EXCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define EXCOPY(To, From, Count)		\
      do					\
	{					\
	  EXSIZE_T exi;				\
	  for (exi = 0; exi < (Count); exi++)	\
	    (To)[exi] = (From)[exi];		\
	}					\
      while (EXID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables EXSIZE and EXSTACKSIZE give the old and new number of
   elements in the stack, and EXPTR gives the new location of the
   stack.  Advance EXPTR to a properly aligned location for the next
   stack.  */
# define EXSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	EXSIZE_T exnewbytes;						\
	EXCOPY (&exptr->Stack, Stack, exsize);				\
	Stack = &exptr->Stack;						\
	exnewbytes = exstacksize * sizeof (*Stack) + EXSTACK_GAP_MAXIMUM; \
	exptr += exnewbytes / sizeof (*exptr);				\
      }									\
    while (EXID (0))

#endif

/* EXFINAL -- State number of the termination state.  */
#define EXFINAL  3
/* EXLAST -- Last index in EXTABLE.  */
#define EXLAST   894

/* EXNTOKENS -- Number of terminals.  */
#define EXNTOKENS  101
/* EXNNTS -- Number of nonterminals.  */
#define EXNNTS  41
/* EXNRULES -- Number of rules.  */
#define EXNRULES  130
/* EXNRULES -- Number of states.  */
#define EXNSTATES  256

/* EXTRANSLATE(EXLEX) -- Bison symbol number corresponding to EXLEX.  */
#define EXUNDEFTOK  2
#define EXMAXUTOK   331

#define EXTRANSLATE(EXX)						\
  ((unsigned int) (EXX) <= EXMAXUTOK ? extranslate[EXX] : EXUNDEFTOK)

/* EXTRANSLATE[EXLEX] -- Bison symbol number corresponding to EXLEX.  */
static const extype_uint8 extranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    86,     2,     2,     2,    85,    72,     2,
      92,    97,    83,    81,    64,    82,   100,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    96,
      75,    65,    76,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    98,     2,    99,    71,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    94,    70,    95,    87,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    68,
      69,    73,    74,    77,    78,    79,    80,    88,    89,    90,
      91,    93
};

#if EXDEBUG
/* EXPRHS[EXN] -- Index of the first RHS symbol of rule number EXN in
   EXRHS.  */
static const extype_uint16 exprhs[] =
{
       0,     0,     3,     6,     7,    10,    11,    16,    17,    20,
      24,    27,    28,    33,    40,    46,    56,    62,    63,    72,
      76,    80,    84,    85,    88,    91,    93,    96,   100,   103,
     105,   109,   110,   115,   117,   119,   121,   123,   125,   127,
     128,   131,   132,   134,   138,   143,   147,   151,   155,   159,
     163,   167,   171,   175,   179,   183,   187,   191,   195,   199,
     203,   207,   211,   215,   219,   220,   221,   229,   232,   235,
     238,   241,   244,   249,   254,   259,   264,   269,   274,   278,
     282,   287,   292,   297,   302,   307,   310,   313,   316,   319,
     322,   324,   326,   328,   330,   332,   334,   336,   338,   340,
     342,   344,   347,   351,   353,   354,   357,   361,   362,   366,
     367,   369,   371,   375,   376,   378,   380,   382,   386,   387,
     391,   392,   394,   398,   401,   404,   405,   408,   410,   411,
     412
};

/* EXRHS -- A `-1'-separated list of the rules' RHS.  */
static const extype_int16 exrhs[] =
{
     102,     0,    -1,   106,   103,    -1,    -1,   103,   104,    -1,
      -1,    29,    67,   105,   106,    -1,    -1,   106,   107,    -1,
      94,   106,    95,    -1,   120,    96,    -1,    -1,    18,   108,
     114,    96,    -1,    28,    92,   121,    97,   107,   119,    -1,
      23,    92,   127,    97,   107,    -1,    23,    92,   120,    96,
     120,    96,   120,    97,   107,    -1,    48,    92,   121,    97,
     107,    -1,    -1,    47,    92,   121,   109,    97,    94,   110,
      95,    -1,    13,   120,    96,    -1,    17,   120,    96,    -1,
      40,   120,    96,    -1,    -1,   110,   111,    -1,   112,   106,
      -1,   113,    -1,   112,   113,    -1,    15,   124,    67,    -1,
      19,    67,    -1,   115,    -1,   114,    64,   115,    -1,    -1,
     117,   116,   128,   139,    -1,    31,    -1,    20,    -1,    27,
      -1,    24,    -1,    31,    -1,    20,    -1,    -1,    21,   107,
      -1,    -1,   121,    -1,    92,   121,    97,    -1,    92,    18,
      97,   121,    -1,   121,    75,   121,    -1,   121,    82,   121,
      -1,   121,    83,   121,    -1,   121,    84,   121,    -1,   121,
      85,   121,    -1,   121,    80,   121,    -1,   121,    79,   121,
      -1,   121,    76,   121,    -1,   121,    78,   121,    -1,   121,
      77,   121,    -1,   121,    74,   121,    -1,   121,    73,   121,
      -1,   121,    72,   121,    -1,   121,    70,   121,    -1,   121,
      71,   121,    -1,   121,    81,   121,    -1,   121,    69,   121,
      -1,   121,    68,   121,    -1,   121,    64,   121,    -1,    -1,
      -1,   121,    66,   122,   121,    67,   123,   121,    -1,    86,
     121,    -1,    87,   121,    -1,    82,   121,    -1,    81,   121,
      -1,    72,   127,    -1,    12,    98,   130,    99,    -1,    24,
      92,   130,    97,    -1,    25,    92,   130,    97,    -1,    45,
      92,   130,    97,    -1,    46,    92,   130,    97,    -1,    22,
      92,   121,    97,    -1,    39,    92,    97,    -1,    43,    92,
      97,    -1,    43,    92,   121,    97,    -1,    37,    92,   130,
      97,    -1,    35,    92,   130,    97,    -1,   125,    92,   130,
      97,    -1,   126,    92,   130,    97,    -1,   127,   138,    -1,
      90,   127,    -1,   127,    90,    -1,    89,   127,    -1,   127,
      89,    -1,   124,    -1,    16,    -1,     8,    -1,     5,    -1,
       9,    -1,     6,    -1,    36,    -1,    38,    -1,    42,    -1,
      41,    -1,    44,    -1,    27,   136,    -1,    20,   129,   136,
      -1,    31,    -1,    -1,    98,    99,    -1,    98,    18,    99,
      -1,    -1,    98,   121,    99,    -1,    -1,   131,    -1,   121,
      -1,   131,    64,   121,    -1,    -1,    18,    -1,   133,    -1,
     134,    -1,   133,    64,   134,    -1,    -1,    18,   135,   118,
      -1,    -1,   137,    -1,   100,    27,   137,    -1,   100,    27,
      -1,   100,    31,    -1,    -1,    65,   121,    -1,   138,    -1,
      -1,    -1,    92,   140,   132,   141,    97,    94,   106,    95,
      -1
};

/* EXRLINE[EXN] -- source line where rule number EXN was defined.  */
static const extype_uint16 exrline[] =
{
       0,   173,   173,   194,   195,   198,   198,   234,   237,   252,
     256,   260,   260,   264,   274,   287,   302,   312,   312,   323,
     335,   339,   352,   381,   384,   413,   414,   417,   438,   444,
     445,   452,   452,   501,   502,   503,   504,   507,   508,   512,
     515,   522,   525,   528,   532,   536,   581,   585,   589,   593,
     597,   601,   605,   609,   613,   617,   621,   625,   629,   633,
     637,   641,   654,   658,   667,   667,   667,   706,   726,   730,
     734,   738,   742,   746,   750,   754,   758,   762,   768,   772,
     776,   782,   787,   791,   815,   850,   874,   882,   890,   894,
     898,   901,   908,   913,   918,   923,   930,   931,   932,   935,
     936,   939,   943,   963,   976,   979,   983,   997,  1000,  1007,
    1010,  1018,  1023,  1030,  1033,  1039,  1042,  1046,  1057,  1057,
    1069,  1072,  1084,  1103,  1107,  1114,  1117,  1124,  1125,  1138,
    1125
};
#endif

#if EXDEBUG || EXERROR_VERBOSE || EXTOKEN_TABLE
/* EXTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at EXNTOKENS, nonterminals.  */
static const char *const extname[] =
{
  "$end", "error", "$undefined", "MINTOKEN", "INT", "INTEGER", "UNSIGNED",
  "CHAR", "FLOATING", "STRING", "VOID", "ADDRESS", "ARRAY", "BREAK",
  "CALL", "CASE", "CONSTANT", "CONTINUE", "DECLARE", "DEFAULT", "DYNAMIC",
  "ELSE", "EXIT", "FOR", "FUNCTION", "GSUB", "ITERATE", "ID", "IF",
  "LABEL", "MEMBER", "NAME", "POS", "PRAGMA", "PRE", "PRINT", "PRINTF",
  "PROCEDURE", "QUERY", "RAND", "RETURN", "SCANF", "SPRINTF", "SRAND",
  "SSCANF", "SUB", "SUBSTR", "SWITCH", "WHILE", "F2I", "F2S", "I2F", "I2S",
  "S2B", "S2F", "S2I", "F2X", "I2X", "S2X", "X2F", "X2I", "X2S", "X2X",
  "XPRINT", "','", "'='", "'?'", "':'", "OR", "AND", "'|'", "'^'", "'&'",
  "NE", "EQ", "'<'", "'>'", "GE", "LE", "RS", "LS", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "'~'", "UNARY", "DEC", "INC", "CAST", "'('",
  "MAXTOKEN", "'{'", "'}'", "';'", "')'", "'['", "']'", "'.'", "$accept",
  "program", "action_list", "action", "@1", "statement_list", "statement",
  "@2", "@3", "switch_list", "switch_item", "case_list", "case_item",
  "dcl_list", "dcl_item", "@4", "dcl_name", "name", "else_opt", "expr_opt",
  "expr", "@5", "@6", "constant", "print", "scan", "variable", "array",
  "index", "args", "arg_list", "formals", "formal_list", "formal_item",
  "@7", "members", "member", "assign", "initialize", "@8", "@9", 0
};
#endif

# ifdef EXPRINT
/* EXTOKNUM[EXLEX-NUM] -- Internal token number corresponding to
   token EXLEX-NUM.  */
static const extype_uint16 extoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    44,    61,    63,    58,   319,   320,
     124,    94,    38,   321,   322,    60,    62,   323,   324,   325,
     326,    43,    45,    42,    47,    37,    33,   126,   327,   328,
     329,   330,    40,   331,   123,   125,    59,    41,    91,    93,
      46
};
# endif

/* EXR1[EXN] -- Symbol number of symbol that rule EXN derives.  */
static const extype_uint8 exr1[] =
{
       0,   101,   102,   103,   103,   105,   104,   106,   106,   107,
     107,   108,   107,   107,   107,   107,   107,   109,   107,   107,
     107,   107,   110,   110,   111,   112,   112,   113,   113,   114,
     114,   116,   115,   117,   117,   117,   117,   118,   118,   119,
     119,   120,   120,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   122,   123,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   124,   124,   124,   124,   124,   125,   125,   125,   126,
     126,   127,   127,   127,   128,   128,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   132,   133,   133,   135,   134,
     136,   136,   136,   137,   137,   138,   138,   139,   140,   141,
     139
};

/* EXR2[EXN] -- Number of symbols composing right hand side of rule EXN.  */
static const extype_uint8 exr2[] =
{
       0,     2,     2,     0,     2,     0,     4,     0,     2,     3,
       2,     0,     4,     6,     5,     9,     5,     0,     8,     3,
       3,     3,     0,     2,     2,     1,     2,     3,     2,     1,
       3,     0,     4,     1,     1,     1,     1,     1,     1,     0,
       2,     0,     1,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     0,     0,     7,     2,     2,     2,
       2,     2,     4,     4,     4,     4,     4,     4,     3,     3,
       4,     4,     4,     4,     4,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     0,     2,     3,     0,     3,     0,
       1,     1,     3,     0,     1,     1,     1,     3,     0,     3,
       0,     1,     3,     2,     2,     0,     2,     1,     0,     0,
       8
};

/* EXDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when EXTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const extype_uint8 exdefact[] =
{
       7,     0,     3,     1,    93,    95,    92,    94,     0,    41,
      91,    41,    11,   107,     0,     0,     0,     0,   120,     0,
     103,     0,    96,     0,    97,     0,    41,    99,    98,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     2,     8,     0,    42,    90,     0,
       0,   125,   109,     0,     0,     0,     0,   120,     0,    41,
     109,   109,     0,   101,   121,     0,   109,   109,     0,     0,
       0,   109,   109,     0,     0,    71,    70,    69,    67,    68,
      88,    86,     0,     0,    41,     0,     4,    10,     0,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   109,
       0,    89,    87,    85,   111,     0,   110,    19,    20,    34,
      36,    35,    33,     0,    29,    31,     0,   102,     0,     0,
     125,     0,     0,   123,   124,     0,     0,     0,    78,    21,
      79,     0,     0,     0,    17,     0,     0,    43,     9,     5,
      63,     0,    62,    61,    58,    59,    57,    56,    55,    45,
      52,    54,    53,    51,    50,    60,    46,    47,    48,    49,
       0,     0,   126,    72,     0,     0,    12,   104,   108,    77,
      41,    41,    73,    74,     0,   122,    41,    82,    81,    80,
      75,    76,     0,    41,    44,     7,     0,    83,    84,   112,
      30,     0,   125,     0,    14,   123,    39,     0,    16,     6,
      65,     0,   105,   128,   127,    32,    41,    41,    13,    22,
       0,   106,   113,     0,    40,     0,    66,   118,   129,   115,
     116,    41,     0,     0,    18,    23,     7,    25,     0,     0,
       0,    15,     0,    28,    24,    26,    38,    37,   119,     0,
     118,   117,    27,     7,    41,   130
};

/* EXDEFGOTO[NTERM-NUM].  */
static const extype_int16 exdefgoto[] =
{
      -1,     1,    44,    86,   195,     2,    45,    55,   192,   225,
     235,   236,   237,   123,   124,   177,   125,   248,   218,    46,
      47,   151,   220,    48,    49,    50,    51,   202,    57,   115,
     116,   228,   229,   230,   238,    63,    64,   113,   215,   222,
     239
};

/* EXPACT[STATE-NUM] -- Index in EXTABLE of the portion describing
   STATE-NUM.  */
#define EXPACT_NINF -139
static const extype_int16 expact[] =
{
    -139,    14,   189,  -139,  -139,  -139,  -139,  -139,   -79,   641,
    -139,   641,  -139,   -61,   -48,   -38,   -35,   -11,   -18,    -3,
    -139,    -2,  -139,     0,  -139,     2,   641,  -139,  -139,     3,
    -139,     5,    16,    19,    20,    -4,   641,   641,   641,   641,
      -4,    -4,   553,  -139,    23,  -139,   -12,   690,  -139,    24,
      29,   -40,   641,    31,    44,    76,   641,   -18,   641,   641,
     641,   641,   -14,  -139,  -139,   641,   641,   641,    48,    50,
      93,   641,   641,   641,   641,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,    51,   267,   281,    74,  -139,  -139,   641,  -139,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,  -139,  -139,  -139,   710,    52,    89,  -139,  -139,  -139,
    -139,  -139,  -139,   -49,  -139,  -139,   174,  -139,   358,    65,
     -44,    66,    67,    47,  -139,   449,    69,    70,  -139,  -139,
    -139,   536,    71,    72,   690,   624,   641,  -139,  -139,  -139,
     710,   641,   727,   743,   758,   772,   785,   798,   798,   809,
     809,   809,   809,    75,    75,   -53,   -53,  -139,  -139,  -139,
      73,    79,   710,  -139,   641,    76,  -139,    64,  -139,  -139,
     641,   463,  -139,  -139,    60,  -139,   463,  -139,  -139,  -139,
    -139,  -139,    80,   463,  -139,  -139,   668,  -139,  -139,   710,
    -139,   -16,   -56,    77,  -139,  -139,   150,    84,  -139,   189,
    -139,    82,  -139,  -139,  -139,  -139,   641,   463,  -139,  -139,
     641,  -139,   166,    90,  -139,    -7,   710,    92,  -139,   122,
    -139,   463,   117,   129,  -139,  -139,    91,  -139,    -9,   102,
     182,  -139,   136,  -139,   189,  -139,  -139,  -139,  -139,   110,
    -139,  -139,  -139,  -139,   372,  -139
};

/* EXPGOTO[NTERM-NUM].  */
static const extype_int16 expgoto[] =
{
    -139,  -139,  -139,  -139,  -139,   -43,  -138,  -139,  -139,  -139,
    -139,  -139,   -21,  -139,    43,  -139,  -139,  -139,  -139,    -8,
     -32,  -139,  -139,   -13,  -139,  -139,    45,  -139,  -139,    83,
    -139,  -139,  -139,   -19,  -139,   165,   106,    21,  -139,  -139,
    -139
};

/* EXTABLE[EXPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what EXDEFACT says.
   If EXTABLE_NINF, syntax error.  */
#define EXTABLE_NINF -115
static const extype_int16 extable[] =
{
      84,    53,   211,    54,    76,    77,    78,    79,   232,   110,
      83,   246,   233,   133,     3,   175,    13,   134,    69,    52,
     114,   110,   247,    18,   126,   110,   128,    20,   114,   114,
     105,   106,   107,   135,   114,   114,   213,    56,   141,   114,
     114,   144,   145,   204,    58,   111,   112,   176,   206,   111,
     112,   129,    85,   181,    59,   208,   150,    60,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   114,   114,   172,   224,
      75,    61,    62,   212,    87,    80,    81,   205,   234,    65,
      66,   134,    67,   241,    68,    70,   119,    71,     4,     5,
     120,     6,     7,   121,   130,     8,   232,   122,    72,    10,
     233,    73,    74,    13,   194,    14,   108,    16,    17,   196,
      18,   109,     4,     5,    20,     6,     7,   117,    21,    22,
      23,    24,    25,    10,    27,    28,    29,    30,    31,    32,
     118,   149,   199,   131,   132,   138,   139,   184,   146,   136,
     137,   173,   209,   174,   142,   143,   103,   104,   105,   106,
     107,   180,   201,   182,   183,    35,   187,   188,   190,   191,
     197,   217,   203,   216,    36,    37,   198,   207,   219,    38,
      39,   221,    40,    41,   227,    42,   240,   231,   226,  -114,
     140,   170,   171,   244,     4,     5,   243,     6,     7,   249,
     250,     8,     9,   252,   253,    10,    11,    12,   223,    13,
     254,    14,    15,    16,    17,   245,    18,    19,   200,   242,
      20,   251,   127,   214,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    88,   185,
      89,     0,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,    35,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,     0,   178,     0,    38,    39,     0,    40,    41,
       0,    42,     0,    43,     0,   -41,     4,     5,     0,     6,
       7,     0,     0,     8,     9,     0,     0,    10,    11,    12,
       0,    13,     0,    14,    15,    16,    17,     0,    18,    19,
       0,     0,    20,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,    88,     0,    89,     0,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    35,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    37,   147,     0,     0,    38,    39,     0,
      40,    41,     0,    42,     0,    43,   148,     4,     5,     0,
       6,     7,     0,     0,     8,     9,     0,     0,    10,    11,
      12,     0,    13,     0,    14,    15,    16,    17,     0,    18,
      19,     0,     0,    20,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,    88,     0,    89,     0,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    35,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,   179,     0,     0,    38,    39,
       0,    40,    41,     0,    42,     0,    43,   255,     4,     5,
       0,     6,     7,     0,     0,     8,     9,     0,     0,    10,
      11,    12,     0,    13,     0,    14,    15,    16,    17,     0,
      18,    19,     0,     0,    20,     0,     0,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,    88,     0,    89,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    35,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,   186,     0,     0,    38,
      39,     0,    40,    41,     0,    42,     0,    43,     4,     5,
       0,     6,     7,     0,     0,     8,     0,     0,     0,    10,
       0,    82,     0,    13,     0,    14,     0,    16,    17,     0,
      18,     0,     0,     0,    20,     0,     0,     0,    21,    22,
      23,    24,    25,     0,    27,    28,    29,    30,    31,    32,
      88,     0,    89,     0,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,   189,    36,    37,     0,     0,     0,    38,
      39,     0,    40,    41,     0,    42,     4,     5,     0,     6,
       7,     0,     0,     8,     0,     0,     0,    10,     0,     0,
       0,    13,     0,    14,     0,    16,    17,     0,    18,     0,
       0,     0,    20,     0,     0,     0,    21,    22,    23,    24,
      25,     0,    27,    28,    29,    30,    31,    32,    88,     0,
      89,     0,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,   193,    36,    37,     0,     0,     0,    38,    39,     0,
      40,    41,    88,    42,    89,   210,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    88,     0,    89,     0,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    89,     0,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,  -115,  -115,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,  -115,  -115,  -115,  -115,   101,   102,
     103,   104,   105,   106,   107
};

static const extype_int16 excheck[] =
{
      43,     9,    18,    11,    36,    37,    38,    39,    15,    65,
      42,    20,    19,    27,     0,    64,    20,    31,    26,    98,
      52,    65,    31,    27,    56,    65,    58,    31,    60,    61,
      83,    84,    85,    65,    66,    67,    92,    98,    70,    71,
      72,    73,    74,   181,    92,    89,    90,    96,   186,    89,
      90,    59,    29,    97,    92,   193,    88,    92,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   217,
      35,    92,   100,    99,    96,    40,    41,    27,    95,    92,
      92,    31,    92,   231,    92,    92,    20,    92,     5,     6,
      24,     8,     9,    27,    59,    12,    15,    31,    92,    16,
      19,    92,    92,    20,   146,    22,    92,    24,    25,   151,
      27,    92,     5,     6,    31,     8,     9,    96,    35,    36,
      37,    38,    39,    16,    41,    42,    43,    44,    45,    46,
      96,    67,   174,    60,    61,    97,    96,   100,    97,    66,
      67,    99,   195,    64,    71,    72,    81,    82,    83,    84,
      85,    96,    98,    97,    97,    72,    97,    97,    97,    97,
      97,    21,   180,    96,    81,    82,    97,    97,    94,    86,
      87,    99,    89,    90,    18,    92,    64,    97,   220,    97,
      97,   108,   109,   236,     5,     6,    67,     8,     9,    97,
      18,    12,    13,    67,    94,    16,    17,    18,   216,    20,
     253,    22,    23,    24,    25,   236,    27,    28,   175,   232,
      31,   240,    57,   202,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    64,   133,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    99,    -1,    86,    87,    -1,    89,    90,
      -1,    92,    -1,    94,    -1,    96,     5,     6,    -1,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    16,    17,    18,
      -1,    20,    -1,    22,    23,    24,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    64,    -1,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    97,    -1,    -1,    86,    87,    -1,
      89,    90,    -1,    92,    -1,    94,    95,     5,     6,    -1,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    16,    17,
      18,    -1,    20,    -1,    22,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    64,    -1,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    97,    -1,    -1,    86,    87,
      -1,    89,    90,    -1,    92,    -1,    94,    95,     5,     6,
      -1,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    16,
      17,    18,    -1,    20,    -1,    22,    23,    24,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    64,    -1,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    97,    -1,    -1,    86,
      87,    -1,    89,    90,    -1,    92,    -1,    94,     5,     6,
      -1,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,    16,
      -1,    18,    -1,    20,    -1,    22,    -1,    24,    25,    -1,
      27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    -1,    41,    42,    43,    44,    45,    46,
      64,    -1,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    81,    82,    -1,    -1,    -1,    86,
      87,    -1,    89,    90,    -1,    92,     5,     6,    -1,     8,
       9,    -1,    -1,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    25,    -1,    27,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    64,    -1,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    81,    82,    -1,    -1,    -1,    86,    87,    -1,
      89,    90,    64,    92,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    64,    -1,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85
};

/* EXSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const extype_uint8 exstos[] =
{
       0,   102,   106,     0,     5,     6,     8,     9,    12,    13,
      16,    17,    18,    20,    22,    23,    24,    25,    27,    28,
      31,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    72,    81,    82,    86,    87,
      89,    90,    92,    94,   103,   107,   120,   121,   124,   125,
     126,   127,    98,   120,   120,   108,    98,   129,    92,    92,
      92,    92,   100,   136,   137,    92,    92,    92,    92,   120,
      92,    92,    92,    92,    92,   127,   121,   121,   121,   121,
     127,   127,    18,   121,   106,    29,   104,    96,    64,    66,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    92,    92,
      65,    89,    90,   138,   121,   130,   131,    96,    96,    20,
      24,    27,    31,   114,   115,   117,   121,   136,   121,   120,
     127,   130,   130,    27,    31,   121,   130,   130,    97,    96,
      97,   121,   130,   130,   121,   121,    97,    97,    95,    67,
     121,   122,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     130,   130,   121,    99,    64,    64,    96,   116,    99,    97,
      96,    97,    97,    97,   100,   137,    97,    97,    97,    97,
      97,    97,   109,    97,   121,   105,   121,    97,    97,   121,
     115,    98,   128,   120,   107,    27,   107,    97,   107,   106,
      67,    18,    99,    92,   138,   139,    96,    21,   119,    94,
     123,    99,   140,   120,   107,   110,   121,    18,   132,   133,
     134,    97,    15,    19,    95,   111,   112,   113,   135,   141,
      64,   107,   124,    67,   106,   113,    20,    31,   118,    97,
      18,   134,    67,    94,   106,    95
};

#define exerrok		(exerrstatus = 0)
#define exclearin	(exchar = EXEMPTY)
#define EXEMPTY		(-2)
#define EXEOF		0

#define EXACCEPT	goto exacceptlab
#define EXABORT		goto exabortlab
#define EXERROR		goto exerrorlab


/* Like EXERROR except do call exerror.  This remains here temporarily
   to ease the transition to the new meaning of EXERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define EXFAIL		goto exerrlab

#define EXRECOVERING()  (!!exerrstatus)

#define EXBACKUP(Token, Value)					\
do								\
  if (exchar == EXEMPTY && exlen == 1)				\
    {								\
      exchar = (Token);						\
      exlval = (Value);						\
      extoken = EXTRANSLATE (exchar);				\
      EXPOPSTACK (1);						\
      goto exbackup;						\
    }								\
  else								\
    {								\
      exerror (EX_("syntax error: cannot back up")); \
      EXERROR;							\
    }								\
while (EXID (0))


#define EXTERROR	1
#define EXERRCODE	256


/* EXLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define EXRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef EXLLOC_DEFAULT
# define EXLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (EXID (N))                                                    \
	{								\
	  (Current).first_line   = EXRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = EXRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = EXRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = EXRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    EXRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    EXRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (EXID (0))
#endif


/* EX_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef EX_LOCATION_PRINT
# if EXLTYPE_IS_TRIVIAL
#  define EX_LOCATION_PRINT(File, Loc)			\
     sfprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define EX_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* EXLEX -- calling `exlex' with the right arguments.  */

#ifdef EXLEX_PARAM
# define EXLEX exlex (EXLEX_PARAM)
#else
# define EXLEX exlex ()
#endif

/* Enable debugging if requested.  */
#if EXDEBUG

# ifndef EXFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define EXFPRINTF sfprintf
# endif

# define EXDPRINTF(Args)			\
do {						\
  if (exdebug)					\
    EXFPRINTF Args;				\
} while (EXID (0))

# define EX_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (exdebug)								  \
    {									  \
      EXFPRINTF (sfstderr, "%s ", Title);					  \
      ex_symbol_print (sfstderr,						  \
		  Type, Value); \
      EXFPRINTF (sfstderr, "\n");						  \
    }									  \
} while (EXID (0))


/*--------------------------------.
| Print this symbol on EXOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
ex_symbol_value_print (Sfio_t *exoutput, int extype, EXSTYPE const * const exvaluep)
#else
static void
ex_symbol_value_print (exoutput, extype, exvaluep)
    Sfio_t *exoutput;
    int extype;
    EXSTYPE const * const exvaluep;
#endif
{
  if (!exvaluep)
    return;
# ifdef EXPRINT
  if (extype < EXNTOKENS)
    EXPRINT (exoutput, extoknum[extype], *exvaluep);
# else
  EXUSE (exoutput);
# endif
  switch (extype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on EXOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
ex_symbol_print (Sfio_t *exoutput, int extype, EXSTYPE const * const exvaluep)
#else
static void
ex_symbol_print (exoutput, extype, exvaluep)
    Sfio_t *exoutput;
    int extype;
    EXSTYPE const * const exvaluep;
#endif
{
  if (extype < EXNTOKENS)
    EXFPRINTF (exoutput, "token %s (", extname[extype]);
  else
    EXFPRINTF (exoutput, "nterm %s (", extname[extype]);

  ex_symbol_value_print (exoutput, extype, exvaluep);
  EXFPRINTF (exoutput, ")");
}

/*------------------------------------------------------------------.
| ex_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
ex_stack_print (extype_int16 *bottom, extype_int16 *top)
#else
static void
ex_stack_print (bottom, top)
    extype_int16 *bottom;
    extype_int16 *top;
#endif
{
  EXFPRINTF (sfstderr, "Stack now");
  for (; bottom <= top; ++bottom)
    EXFPRINTF (sfstderr, " %d", *bottom);
  EXFPRINTF (sfstderr, "\n");
}

# define EX_STACK_PRINT(Bottom, Top)				\
do {								\
  if (exdebug)							\
    ex_stack_print ((Bottom), (Top));				\
} while (EXID (0))


/*------------------------------------------------.
| Report that the EXRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
ex_reduce_print (EXSTYPE *exvsp, int exrule)
#else
static void
ex_reduce_print (exvsp, exrule)
    EXSTYPE *exvsp;
    int exrule;
#endif
{
  int exnrhs = exr2[exrule];
  int exi;
  unsigned long int exlno = exrline[exrule];
  EXFPRINTF (sfstderr, "Reducing stack by rule %d (line %lu):\n",
	     exrule - 1, exlno);
  /* The symbols being reduced.  */
  for (exi = 0; exi < exnrhs; exi++)
    {
      sfprintf (sfstderr, "   $%d = ", exi + 1);
      ex_symbol_print (sfstderr, exrhs[exprhs[exrule] + exi],
		       &(exvsp[(exi + 1) - (exnrhs)])
		       		       );
      sfprintf (sfstderr, "\n");
    }
}

# define EX_REDUCE_PRINT(Rule)		\
do {					\
  if (exdebug)				\
    ex_reduce_print (exvsp, Rule); \
} while (EXID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int exdebug;
#else /* !EXDEBUG */
# define EXDPRINTF(Args)
# define EX_SYMBOL_PRINT(Title, Type, Value, Location)
# define EX_STACK_PRINT(Bottom, Top)
# define EX_REDUCE_PRINT(Rule)
#endif /* !EXDEBUG */


/* EXINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	EXINITDEPTH
# define EXINITDEPTH 200
#endif

/* EXMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   EXSTACK_ALLOC_MAXIMUM < EXSTACK_BYTES (EXMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef EXMAXDEPTH
# define EXMAXDEPTH 10000
#endif



#if EXERROR_VERBOSE

# ifndef exstrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define exstrlen strlen
#  else
/* Return the length of EXSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static EXSIZE_T
exstrlen (const char *exstr)
#else
static EXSIZE_T
exstrlen (exstr)
    const char *exstr;
#endif
{
  EXSIZE_T exlen;
  for (exlen = 0; exstr[exlen]; exlen++)
    continue;
  return exlen;
}
#  endif
# endif

# ifndef exstpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define exstpcpy stpcpy
#  else
/* Copy EXSRC to EXDEST, returning the address of the terminating '\0' in
   EXDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
exstpcpy (char *exdest, const char *exsrc)
#else
static char *
exstpcpy (exdest, exsrc)
    char *exdest;
    const char *exsrc;
#endif
{
  char *exd = exdest;
  const char *exs = exsrc;

  while ((*exd++ = *exs++) != '\0')
    continue;

  return exd - 1;
}
#  endif
# endif

# ifndef extnamerr
/* Copy to EXRES the contents of EXSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for exerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  EXSTR is taken from extname.  If EXRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static EXSIZE_T
extnamerr (char *exres, const char *exstr)
{
  if (*exstr == '"')
    {
      EXSIZE_T exn = 0;
      char const *exp = exstr;

      for (;;)
	switch (*++exp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++exp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (exres)
	      exres[exn] = *exp;
	    exn++;
	    break;

	  case '"':
	    if (exres)
	      exres[exn] = '\0';
	    return exn;
	  }
    do_not_strip_quotes: ;
    }

  if (! exres)
    return exstrlen (exstr);

  return exstpcpy (exres, exstr) - exres;
}
# endif

/* Copy into EXRESULT an error message about the unexpected token
   EXCHAR while in state EXSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If EXRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return EXSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static EXSIZE_T
exsyntax_error (char *exresult, int exstate, int exchar)
{
  int exn = expact[exstate];

  if (! (EXPACT_NINF < exn && exn <= EXLAST))
    return 0;
  else
    {
      int extype = EXTRANSLATE (exchar);
      EXSIZE_T exsize0 = extnamerr (0, extname[extype]);
      EXSIZE_T exsize = exsize0;
      EXSIZE_T exsize1;
      int exsize_overflow = 0;
      enum { EXERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *exarg[EXERROR_VERBOSE_ARGS_MAXIMUM];
      int exx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      EX_("syntax error, unexpected %s");
      EX_("syntax error, unexpected %s, expecting %s");
      EX_("syntax error, unexpected %s, expecting %s or %s");
      EX_("syntax error, unexpected %s, expecting %s or %s or %s");
      EX_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *exfmt;
      char const *exf;
      static char const exunexpected[] = "syntax error, unexpected %s";
      static char const exexpecting[] = ", expecting %s";
      static char const exor[] = " or %s";
      char exformat[sizeof exunexpected
		    + sizeof exexpecting - 1
		    + ((EXERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof exor - 1))];
      char const *exprefix = exexpecting;

      /* Start EXX at -EXN if negative to avoid negative indexes in
	 EXCHECK.  */
      int exxbegin = exn < 0 ? -exn : 0;

      /* Stay within bounds of both excheck and extname.  */
      int exchecklim = EXLAST - exn + 1;
      int exxend = exchecklim < EXNTOKENS ? exchecklim : EXNTOKENS;
      int excount = 1;

      exarg[0] = extname[extype];
      exfmt = exstpcpy (exformat, exunexpected);

      for (exx = exxbegin; exx < exxend; ++exx)
	if (excheck[exx + exn] == exx && exx != EXTERROR)
	  {
	    if (excount == EXERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		excount = 1;
		exsize = exsize0;
		exformat[sizeof exunexpected - 1] = '\0';
		break;
	      }
	    exarg[excount++] = extname[exx];
	    exsize1 = exsize + extnamerr (0, extname[exx]);
	    exsize_overflow |= (exsize1 < exsize);
	    exsize = exsize1;
	    exfmt = exstpcpy (exfmt, exprefix);
	    exprefix = exor;
	  }

      exf = EX_(exformat);
      exsize1 = exsize + exstrlen (exf);
      exsize_overflow |= (exsize1 < exsize);
      exsize = exsize1;

      if (exsize_overflow)
	return EXSIZE_MAXIMUM;

      if (exresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *exp = exresult;
	  int exi = 0;
	  while ((*exp = *exf) != '\0')
	    {
	      if (*exp == '%' && exf[1] == 's' && exi < excount)
		{
		  exp += extnamerr (exp, exarg[exi++]);
		  exf += 2;
		}
	      else
		{
		  exp++;
		  exf++;
		}
	    }
	}
      return exsize;
    }
}
#endif /* EXERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
exdestruct (const char *exmsg, int extype, EXSTYPE *exvaluep)
#else
static void
exdestruct (exmsg, extype, exvaluep)
    const char *exmsg;
    int extype;
    EXSTYPE *exvaluep;
#endif
{
  EXUSE (exvaluep);

  if (!exmsg)
    exmsg = "Deleting";
  EX_SYMBOL_PRINT (exmsg, extype, exvaluep, exlocationp);

  switch (extype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef EXPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int exparse (void *EXPARSE_PARAM);
#else
int exparse ();
#endif
#else /* ! EXPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int exparse (void);
#else
int exparse ();
#endif
#endif /* ! EXPARSE_PARAM */



/* The look-ahead symbol.  */
int exchar;

/* The semantic value of the look-ahead symbol.  */
EXSTYPE exlval;

/* Number of syntax errors so far.  */
int exnerrs;



/*----------.
| exparse.  |
`----------*/

#ifdef EXPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
exparse (void *EXPARSE_PARAM)
#else
int
exparse (EXPARSE_PARAM)
    void *EXPARSE_PARAM;
#endif
#else /* ! EXPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
exparse (void)
#else
int
exparse ()

#endif
#endif
{
  
  int exstate;
  int exn;
  int exresult;
  /* Number of tokens to shift before error messages enabled.  */
  int exerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int extoken = 0;
#if EXERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char exmsgbuf[128];
  char *exmsg = exmsgbuf;
  EXSIZE_T exmsg_alloc = sizeof exmsgbuf;
#endif

  /* Three stacks and their tools:
     `exss': related to states,
     `exvs': related to semantic values,
     `exls': related to locations.

     Refer to the stacks thru separate pointers, to allow exoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  extype_int16 exssa[EXINITDEPTH];
  extype_int16 *exss = exssa;
  extype_int16 *exssp;

  /* The semantic value stack.  */
  EXSTYPE exvsa[EXINITDEPTH];
  EXSTYPE *exvs = exvsa;
  EXSTYPE *exvsp;



#define EXPOPSTACK(N)   (exvsp -= (N), exssp -= (N))

  EXSIZE_T exstacksize = EXINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  EXSTYPE exval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int exlen = 0;

  EXDPRINTF ((sfstderr, "Starting parse\n"));

  exstate = 0;
  exerrstatus = 0;
  exnerrs = 0;
  exchar = EXEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  exssp = exss;
  exvsp = exvs;

  goto exsetstate;

/*------------------------------------------------------------.
| exnewstate -- Push a new state, which is found in exstate.  |
`------------------------------------------------------------*/
 exnewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  exssp++;

 exsetstate:
  *exssp = exstate;

  if (exss + exstacksize - 1 <= exssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      EXSIZE_T exsize = exssp - exss + 1;

#ifdef exoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	EXSTYPE *exvs1 = exvs;
	extype_int16 *exss1 = exss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if exoverflow is a macro.  */
	exoverflow (EX_("memory exhausted"),
		    &exss1, exsize * sizeof (*exssp),
		    &exvs1, exsize * sizeof (*exvsp),

		    &exstacksize);

	exss = exss1;
	exvs = exvs1;
      }
#else /* no exoverflow */
# ifndef EXSTACK_RELOCATE
      goto exexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (EXMAXDEPTH <= exstacksize)
	goto exexhaustedlab;
      exstacksize *= 2;
      if (EXMAXDEPTH < exstacksize)
	exstacksize = EXMAXDEPTH;

      {
	extype_int16 *exss1 = exss;
	union exalloc *exptr =
	  (union exalloc *) EXSTACK_ALLOC (EXSTACK_BYTES (exstacksize));
	if (! exptr)
	  goto exexhaustedlab;
	EXSTACK_RELOCATE (exss);
	EXSTACK_RELOCATE (exvs);

#  undef EXSTACK_RELOCATE
	if (exss1 != exssa)
	  EXSTACK_FREE (exss1);
      }
# endif
#endif /* no exoverflow */

      exssp = exss + exsize - 1;
      exvsp = exvs + exsize - 1;


      EXDPRINTF ((sfstderr, "Stack size increased to %lu\n",
		  (unsigned long int) exstacksize));

      if (exss + exstacksize - 1 <= exssp)
	EXABORT;
    }

  EXDPRINTF ((sfstderr, "Entering state %d\n", exstate));

  goto exbackup;

/*-----------.
| exbackup.  |
`-----------*/
exbackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  exn = expact[exstate];
  if (exn == EXPACT_NINF)
    goto exdefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* EXCHAR is either EXEMPTY or EXEOF or a valid look-ahead symbol.  */
  if (exchar == EXEMPTY)
    {
      EXDPRINTF ((sfstderr, "Reading a token: "));
      exchar = EXLEX;
    }

  if (exchar <= EXEOF)
    {
      exchar = extoken = EXEOF;
      EXDPRINTF ((sfstderr, "Now at end of input.\n"));
    }
  else
    {
      extoken = EXTRANSLATE (exchar);
      EX_SYMBOL_PRINT ("Next token is", extoken, &exlval, &exlloc);
    }

  /* If the proper action on seeing token EXTOKEN is to reduce or to
     detect an error, take that action.  */
  exn += extoken;
  if (exn < 0 || EXLAST < exn || excheck[exn] != extoken)
    goto exdefault;
  exn = extable[exn];
  if (exn <= 0)
    {
      if (exn == 0 || exn == EXTABLE_NINF)
	goto exerrlab;
      exn = -exn;
      goto exreduce;
    }

  if (exn == EXFINAL)
    EXACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (exerrstatus)
    exerrstatus--;

  /* Shift the look-ahead token.  */
  EX_SYMBOL_PRINT ("Shifting", extoken, &exlval, &exlloc);

  /* Discard the shifted token unless it is eof.  */
  if (exchar != EXEOF)
    exchar = EXEMPTY;

  exstate = exn;
  *++exvsp = exlval;

  goto exnewstate;


/*-----------------------------------------------------------.
| exdefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
exdefault:
  exn = exdefact[exstate];
  if (exn == 0)
    goto exerrlab;
  goto exreduce;


/*-----------------------------.
| exreduce -- Do a reduction.  |
`-----------------------------*/
exreduce:
  /* exn is the number of a rule to reduce with.  */
  exlen = exr2[exn];

  /* If EXLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets EXVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to EXVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that EXVAL may be used uninitialized.  */
  exval = exvsp[1-exlen];


  EX_REDUCE_PRINT (exn);
  switch (exn)
    {
        case 2:
#line 174 "../../lib/expr/exparse.y"
    {
			if ((exvsp[(1) - (2)].expr) && !(expr.program->disc->flags & EX_STRICT))
			{
				if (expr.program->main.value && !(expr.program->disc->flags & EX_RETAIN))
					exfreenode(expr.program, expr.program->main.value);
				if ((exvsp[(1) - (2)].expr)->op == S2B)
				{
					Exnode_t*	x;

					x = (exvsp[(1) - (2)].expr);
					(exvsp[(1) - (2)].expr) = x->data.operand.left;
					x->data.operand.left = 0;
					exfreenode(expr.program, x);
				}
				expr.program->main.lex = PROCEDURE;
				expr.program->main.value = exnewnode(expr.program, PROCEDURE, 1, (exvsp[(1) - (2)].expr)->type, NiL, (exvsp[(1) - (2)].expr));
			}
		}
    break;

  case 5:
#line 198 "../../lib/expr/exparse.y"
    {
				register Dtdisc_t*	disc;

				if (expr.procedure)
					exerror("no nested function definitions");
				(exvsp[(1) - (2)].id)->lex = PROCEDURE;
				expr.procedure = (exvsp[(1) - (2)].id)->value = exnewnode(expr.program, PROCEDURE, 1, (exvsp[(1) - (2)].id)->type, NiL, NiL);
				expr.procedure->type = INTEGER;
				if (!(disc = newof(0, Dtdisc_t, 1, 0)))
					exerror("out of space [frame discipline]");
				disc->key = offsetof(Exid_t, name);
				if (!(expr.procedure->data.procedure.frame = dtopen(disc, Dtset)) || !dtview(expr.procedure->data.procedure.frame, expr.program->symbols))
					exerror("out of space [frame table]");
				expr.program->symbols = expr.program->frame = expr.procedure->data.procedure.frame;
			}
    break;

  case 6:
#line 213 "../../lib/expr/exparse.y"
    {
			expr.procedure = 0;
			if (expr.program->frame)
			{
				expr.program->symbols = expr.program->frame->view;
				dtview(expr.program->frame, NiL);
			}
			if ((exvsp[(4) - (4)].expr) && (exvsp[(4) - (4)].expr)->op == S2B)
			{
				Exnode_t*	x;

				x = (exvsp[(4) - (4)].expr);
				(exvsp[(4) - (4)].expr) = x->data.operand.left;
				x->data.operand.left = 0;
				exfreenode(expr.program, x);
			}
			(exvsp[(1) - (4)].id)->value->data.operand.right = excast(expr.program, (exvsp[(4) - (4)].expr), (exvsp[(1) - (4)].id)->type, NiL, 0);
		}
    break;

  case 7:
#line 234 "../../lib/expr/exparse.y"
    {
			(exval.expr) = 0;
		}
    break;

  case 8:
#line 238 "../../lib/expr/exparse.y"
    {
			if (!(exvsp[(1) - (2)].expr))
				(exval.expr) = (exvsp[(2) - (2)].expr);
			else if (!(exvsp[(2) - (2)].expr))
				(exval.expr) = (exvsp[(1) - (2)].expr);
			else if ((exvsp[(1) - (2)].expr)->op == CONSTANT)
			{
				exfreenode(expr.program, (exvsp[(1) - (2)].expr));
				(exval.expr) = (exvsp[(2) - (2)].expr);
			}
			else (exval.expr) = exnewnode(expr.program, ';', 1, (exvsp[(2) - (2)].expr)->type, (exvsp[(1) - (2)].expr), (exvsp[(2) - (2)].expr));
		}
    break;

  case 9:
#line 253 "../../lib/expr/exparse.y"
    {
			(exval.expr) = (exvsp[(2) - (3)].expr);
		}
    break;

  case 10:
#line 257 "../../lib/expr/exparse.y"
    {
			(exval.expr) = ((exvsp[(1) - (2)].expr) && (exvsp[(1) - (2)].expr)->type == STRING) ? exnewnode(expr.program, S2B, 1, INTEGER, (exvsp[(1) - (2)].expr), NiL) : (exvsp[(1) - (2)].expr);
		}
    break;

  case 11:
#line 260 "../../lib/expr/exparse.y"
    {expr.declare=(exvsp[(1) - (1)].id)->type;}
    break;

  case 12:
#line 261 "../../lib/expr/exparse.y"
    {
			(exval.expr) = (exvsp[(3) - (4)].expr);
		}
    break;

  case 13:
#line 265 "../../lib/expr/exparse.y"
    {
			if (exisAssign ((exvsp[(3) - (6)].expr)))
				exwarn ("assignment used as boolean in if statement");
			if ((exvsp[(3) - (6)].expr)->type == STRING)
				(exvsp[(3) - (6)].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (exvsp[(3) - (6)].expr), NiL);
			else if (!INTEGRAL((exvsp[(3) - (6)].expr)->type))
				(exvsp[(3) - (6)].expr) = excast(expr.program, (exvsp[(3) - (6)].expr), INTEGER, NiL, 0);
			(exval.expr) = exnewnode(expr.program, (exvsp[(1) - (6)].id)->index, 1, INTEGER, (exvsp[(3) - (6)].expr), exnewnode(expr.program, ':', 1, (exvsp[(5) - (6)].expr) ? (exvsp[(5) - (6)].expr)->type : 0, (exvsp[(5) - (6)].expr), (exvsp[(6) - (6)].expr)));
		}
    break;

  case 14:
#line 275 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, ITERATE, 0, INTEGER, NiL, NiL);
			(exval.expr)->data.generate.array = (exvsp[(3) - (5)].expr);
			if (!(exvsp[(3) - (5)].expr)->data.variable.index || (exvsp[(3) - (5)].expr)->data.variable.index->op != DYNAMIC)
				exerror("simple index variable expected");
			(exval.expr)->data.generate.index = (exvsp[(3) - (5)].expr)->data.variable.index->data.variable.symbol;
			if ((exvsp[(3) - (5)].expr)->op == ID && (exval.expr)->data.generate.index->type != INTEGER)
				exerror("integer index variable expected");
			exfreenode(expr.program, (exvsp[(3) - (5)].expr)->data.variable.index);
			(exvsp[(3) - (5)].expr)->data.variable.index = 0;
			(exval.expr)->data.generate.statement = (exvsp[(5) - (5)].expr);
		}
    break;

  case 15:
#line 288 "../../lib/expr/exparse.y"
    {
			if (!(exvsp[(5) - (9)].expr))
			{
				(exvsp[(5) - (9)].expr) = exnewnode(expr.program, CONSTANT, 0, INTEGER, NiL, NiL);
				(exvsp[(5) - (9)].expr)->data.constant.value.integer = 1;
			}
			else if ((exvsp[(5) - (9)].expr)->type == STRING)
				(exvsp[(5) - (9)].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (exvsp[(5) - (9)].expr), NiL);
			else if (!INTEGRAL((exvsp[(5) - (9)].expr)->type))
				(exvsp[(5) - (9)].expr) = excast(expr.program, (exvsp[(5) - (9)].expr), INTEGER, NiL, 0);
			(exval.expr) = exnewnode(expr.program, (exvsp[(1) - (9)].id)->index, 1, INTEGER, (exvsp[(5) - (9)].expr), exnewnode(expr.program, ';', 1, 0, (exvsp[(7) - (9)].expr), (exvsp[(9) - (9)].expr)));
			if ((exvsp[(3) - (9)].expr))
				(exval.expr) = exnewnode(expr.program, ';', 1, INTEGER, (exvsp[(3) - (9)].expr), (exval.expr));
		}
    break;

  case 16:
#line 303 "../../lib/expr/exparse.y"
    {
			if (exisAssign ((exvsp[(3) - (5)].expr)))
				exwarn ("assignment used as boolean in while statement");
			if ((exvsp[(3) - (5)].expr)->type == STRING)
				(exvsp[(3) - (5)].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (exvsp[(3) - (5)].expr), NiL);
			else if (!INTEGRAL((exvsp[(3) - (5)].expr)->type))
				(exvsp[(3) - (5)].expr) = excast(expr.program, (exvsp[(3) - (5)].expr), INTEGER, NiL, 0);
			(exval.expr) = exnewnode(expr.program, (exvsp[(1) - (5)].id)->index, 1, INTEGER, (exvsp[(3) - (5)].expr), exnewnode(expr.program, ';', 1, 0, NiL, (exvsp[(5) - (5)].expr)));
		}
    break;

  case 17:
#line 312 "../../lib/expr/exparse.y"
    {expr.declare=(exvsp[(3) - (3)].expr)->type;}
    break;

  case 18:
#line 313 "../../lib/expr/exparse.y"
    {
			register Switch_t*	sw = expr.swstate;

			(exval.expr) = exnewnode(expr.program, (exvsp[(1) - (8)].id)->index, 1, INTEGER, (exvsp[(3) - (8)].expr), exnewnode(expr.program, DEFAULT, 1, 0, sw->defcase, sw->firstcase));
			expr.swstate = expr.swstate->prev;
			if (sw->base)
				free(sw->base);
			if (sw != &swstate)
				free(sw);
		}
    break;

  case 19:
#line 324 "../../lib/expr/exparse.y"
    {
		loopop:
			if (!(exvsp[(2) - (3)].expr))
			{
				(exvsp[(2) - (3)].expr) = exnewnode(expr.program, CONSTANT, 0, INTEGER, NiL, NiL);
				(exvsp[(2) - (3)].expr)->data.constant.value.integer = 1;
			}
			else if (!INTEGRAL((exvsp[(2) - (3)].expr)->type))
				(exvsp[(2) - (3)].expr) = excast(expr.program, (exvsp[(2) - (3)].expr), INTEGER, NiL, 0);
			(exval.expr) = exnewnode(expr.program, (exvsp[(1) - (3)].id)->index, 1, INTEGER, (exvsp[(2) - (3)].expr), NiL);
		}
    break;

  case 20:
#line 336 "../../lib/expr/exparse.y"
    {
			goto loopop;
		}
    break;

  case 21:
#line 340 "../../lib/expr/exparse.y"
    {
			if ((exvsp[(2) - (3)].expr))
			{
				if (expr.procedure && !expr.procedure->type)
					exerror("return in void function");
				(exvsp[(2) - (3)].expr) = excast(expr.program, (exvsp[(2) - (3)].expr), expr.procedure ? expr.procedure->type : INTEGER, NiL, 0);
			}
			(exval.expr) = exnewnode(expr.program, RETURN, 1, (exvsp[(2) - (3)].expr) ? (exvsp[(2) - (3)].expr)->type : 0, (exvsp[(2) - (3)].expr), NiL);
		}
    break;

  case 22:
#line 352 "../../lib/expr/exparse.y"
    {
			register Switch_t*		sw;
			int				n;

			if (expr.swstate)
			{
				if (!(sw = newof(0, Switch_t, 1, 0)))
				{
					exerror("out of space [switch]");
					sw = &swstate;
				}
				sw->prev = expr.swstate;
			}
			else sw = &swstate;
			expr.swstate = sw;
			sw->type = expr.declare;
			sw->firstcase = 0;
			sw->lastcase = 0;
			sw->defcase = 0;
			sw->def = 0;
			n = 8;
			if (!(sw->base = newof(0, Extype_t*, n, 0)))
			{
				exerror("out of space [case]");
				n = 0;
			}
			sw->cur = sw->base;
			sw->last = sw->base + n;
		}
    break;

  case 24:
#line 385 "../../lib/expr/exparse.y"
    {
			register Switch_t*	sw = expr.swstate;
			int			n;

			(exval.expr) = exnewnode(expr.program, CASE, 1, 0, (exvsp[(2) - (2)].expr), NiL);
			if (sw->cur > sw->base)
			{
				if (sw->lastcase)
					sw->lastcase->data.select.next = (exval.expr);
				else sw->firstcase = (exval.expr);
				sw->lastcase = (exval.expr);
				n = sw->cur - sw->base;
				sw->cur = sw->base;
				(exval.expr)->data.select.constant = (Extype_t**)exalloc(expr.program, (n + 1) * sizeof(Extype_t*));
				memcpy((exval.expr)->data.select.constant, sw->base, n * sizeof(Extype_t*));
				(exval.expr)->data.select.constant[n] = 0;
			}
			else (exval.expr)->data.select.constant = 0;
			if (sw->def)
			{
				sw->def = 0;
				if (sw->defcase)
					exerror("duplicate default in switch");
				else sw->defcase = (exvsp[(2) - (2)].expr);
			}
		}
    break;

  case 27:
#line 418 "../../lib/expr/exparse.y"
    {
			int	n;

			if (expr.swstate->cur >= expr.swstate->last)
			{
				n = expr.swstate->cur - expr.swstate->base;
				if (!(expr.swstate->base = newof(expr.swstate->base, Extype_t*, 2 * n, 0)))
				{
					exerror("too many case labels for switch");
					n = 0;
				}
				expr.swstate->cur = expr.swstate->base + n;
				expr.swstate->last = expr.swstate->base + 2 * n;
			}
			if (expr.swstate->cur)
			{
				(exvsp[(2) - (3)].expr) = excast(expr.program, (exvsp[(2) - (3)].expr), expr.swstate->type, NiL, 0);
				*expr.swstate->cur++ = &((exvsp[(2) - (3)].expr)->data.constant.value);
			}
		}
    break;

  case 28:
#line 439 "../../lib/expr/exparse.y"
    {
			expr.swstate->def = 1;
		}
    break;

  case 30:
#line 446 "../../lib/expr/exparse.y"
    {
			if ((exvsp[(3) - (3)].expr))
				(exval.expr) = (exvsp[(1) - (3)].expr) ? exnewnode(expr.program, ',', 1, (exvsp[(3) - (3)].expr)->type, (exvsp[(1) - (3)].expr), (exvsp[(3) - (3)].expr)) : (exvsp[(3) - (3)].expr);
		}
    break;

  case 31:
#line 452 "../../lib/expr/exparse.y"
    {checkName ((exvsp[(1) - (1)].id)); expr.id=(exvsp[(1) - (1)].id);}
    break;

  case 32:
#line 453 "../../lib/expr/exparse.y"
    {
			(exval.expr) = 0;
			(exvsp[(1) - (4)].id)->type = expr.declare;
			if ((exvsp[(4) - (4)].expr) && (exvsp[(4) - (4)].expr)->op == PROCEDURE)
			{
				(exvsp[(1) - (4)].id)->lex = PROCEDURE;
				(exvsp[(1) - (4)].id)->type = (exvsp[(4) - (4)].expr)->type;
				(exvsp[(1) - (4)].id)->value = (exvsp[(4) - (4)].expr);
			}
			else
			{
				(exvsp[(1) - (4)].id)->lex = DYNAMIC;
				(exvsp[(1) - (4)].id)->value = exnewnode(expr.program, 0, 0, 0, NiL, NiL);
				if ((exvsp[(3) - (4)].integer) && !(exvsp[(1) - (4)].id)->local.pointer)
				{
					Dtdisc_t*	disc;

					if (!(disc = newof(0, Dtdisc_t, 1, 0)))
						exerror("out of space [associative array]");
					if ((exvsp[(3) - (4)].integer) == INTEGER) {
						disc->key = offsetof(Exassoc_t, key);
						disc->size = sizeof(Extype_t);
						disc->comparf = (Dtcompar_f)cmpKey;
					}
					else {
						disc->key = offsetof(Exassoc_t, name);
					}
					if (!((exvsp[(1) - (4)].id)->local.pointer = (char*)dtopen(disc, Dtoset)))
						exerror("%s: cannot initialize associative array", (exvsp[(1) - (4)].id)->name);
					(exvsp[(1) - (4)].id)->index_type = (exvsp[(3) - (4)].integer); /* -1 indicates no typechecking */
				}
				if ((exvsp[(4) - (4)].expr))
				{
					if ((exvsp[(4) - (4)].expr)->type != (exvsp[(1) - (4)].id)->type)
					{
						(exvsp[(4) - (4)].expr)->type = (exvsp[(1) - (4)].id)->type;
						(exvsp[(4) - (4)].expr)->data.operand.right = excast(expr.program, (exvsp[(4) - (4)].expr)->data.operand.right, (exvsp[(1) - (4)].id)->type, NiL, 0);
					}
					(exvsp[(4) - (4)].expr)->data.operand.left = exnewnode(expr.program, DYNAMIC, 0, (exvsp[(1) - (4)].id)->type, NiL, NiL);
					(exvsp[(4) - (4)].expr)->data.operand.left->data.variable.symbol = (exvsp[(1) - (4)].id);
					(exval.expr) = (exvsp[(4) - (4)].expr);
				}
				else if (!(exvsp[(3) - (4)].integer))
					(exvsp[(1) - (4)].id)->value->data.value = exzero((exvsp[(1) - (4)].id)->type);
			}
		}
    break;

  case 39:
#line 512 "../../lib/expr/exparse.y"
    {
			(exval.expr) = 0;
		}
    break;

  case 40:
#line 516 "../../lib/expr/exparse.y"
    {
			(exval.expr) = (exvsp[(2) - (2)].expr);
		}
    break;

  case 41:
#line 522 "../../lib/expr/exparse.y"
    {
			(exval.expr) = 0;
		}
    break;

  case 43:
#line 529 "../../lib/expr/exparse.y"
    {
			(exval.expr) = (exvsp[(2) - (3)].expr);
		}
    break;

  case 44:
#line 533 "../../lib/expr/exparse.y"
    {
			(exval.expr) = ((exvsp[(4) - (4)].expr)->type == (exvsp[(2) - (4)].id)->type) ? (exvsp[(4) - (4)].expr) : excast(expr.program, (exvsp[(4) - (4)].expr), (exvsp[(2) - (4)].id)->type, NiL, 0);
		}
    break;

  case 45:
#line 537 "../../lib/expr/exparse.y"
    {
			int	rel;

		relational:
			rel = INTEGER;
			goto coerce;
		binary:
			rel = 0;
		coerce:
			if (!(exvsp[(1) - (3)].expr)->type)
			{
				if (!(exvsp[(3) - (3)].expr)->type)
					(exvsp[(1) - (3)].expr)->type = (exvsp[(3) - (3)].expr)->type = rel ? STRING : INTEGER;
				else (exvsp[(1) - (3)].expr)->type = (exvsp[(3) - (3)].expr)->type;
			}
			else if (!(exvsp[(3) - (3)].expr)->type) (exvsp[(3) - (3)].expr)->type = (exvsp[(1) - (3)].expr)->type;
			if ((exvsp[(1) - (3)].expr)->type != (exvsp[(3) - (3)].expr)->type)
			{
				if ((exvsp[(1) - (3)].expr)->type == STRING)
					(exvsp[(1) - (3)].expr) = excast(expr.program, (exvsp[(1) - (3)].expr), (exvsp[(3) - (3)].expr)->type, (exvsp[(3) - (3)].expr), 0);
				else if ((exvsp[(3) - (3)].expr)->type == STRING)
					(exvsp[(3) - (3)].expr) = excast(expr.program, (exvsp[(3) - (3)].expr), (exvsp[(1) - (3)].expr)->type, (exvsp[(1) - (3)].expr), 0);
				else if ((exvsp[(1) - (3)].expr)->type == FLOATING)
					(exvsp[(3) - (3)].expr) = excast(expr.program, (exvsp[(3) - (3)].expr), FLOATING, (exvsp[(1) - (3)].expr), 0);
				else if ((exvsp[(3) - (3)].expr)->type == FLOATING)
					(exvsp[(1) - (3)].expr) = excast(expr.program, (exvsp[(1) - (3)].expr), FLOATING, (exvsp[(3) - (3)].expr), 0);
			}
			if (!rel)
				rel = ((exvsp[(1) - (3)].expr)->type == STRING) ? STRING : (((exvsp[(1) - (3)].expr)->type == UNSIGNED) ? UNSIGNED : (exvsp[(3) - (3)].expr)->type);
			(exval.expr) = exnewnode(expr.program, (exvsp[(2) - (3)].op), 1, rel, (exvsp[(1) - (3)].expr), (exvsp[(3) - (3)].expr));
			if (!expr.program->errors && (exvsp[(1) - (3)].expr)->op == CONSTANT && (exvsp[(3) - (3)].expr)->op == CONSTANT)
			{
				expr.program->vc = expr.program->vm;
				(exval.expr)->data.constant.value = exeval(expr.program, (exval.expr), NiL);
				expr.program->vc = expr.program->ve;
				(exval.expr)->binary = 0;
				(exval.expr)->op = CONSTANT;
				exfreenode(expr.program, (exvsp[(1) - (3)].expr));
				exfreenode(expr.program, (exvsp[(3) - (3)].expr));
			}
			else if (!BUILTIN((exvsp[(1) - (3)].expr)->type) || !BUILTIN((exvsp[(3) - (3)].expr)->type)) {
				checkBinary(expr.program, (exvsp[(1) - (3)].expr), (exval.expr), (exvsp[(3) - (3)].expr));
			}
		}
    break;

  case 46:
#line 582 "../../lib/expr/exparse.y"
    {
			goto binary;
		}
    break;

  case 47:
#line 586 "../../lib/expr/exparse.y"
    {
			goto binary;
		}
    break;

  case 48:
#line 590 "../../lib/expr/exparse.y"
    {
			goto binary;
		}
    break;

  case 49:
#line 594 "../../lib/expr/exparse.y"
    {
			goto binary;
		}
    break;

  case 50:
#line 598 "../../lib/expr/exparse.y"
    {
			goto binary;
		}
    break;

  case 51:
#line 602 "../../lib/expr/exparse.y"
    {
			goto binary;
		}
    break;

  case 52:
#line 606 "../../lib/expr/exparse.y"
    {
			goto relational;
		}
    break;

  case 53:
#line 610 "../../lib/expr/exparse.y"
    {
			goto relational;
		}
    break;

  case 54:
#line 614 "../../lib/expr/exparse.y"
    {
			goto relational;
		}
    break;

  case 55:
#line 618 "../../lib/expr/exparse.y"
    {
			goto relational;
		}
    break;

  case 56:
#line 622 "../../lib/expr/exparse.y"
    {
			goto relational;
		}
    break;

  case 57:
#line 626 "../../lib/expr/exparse.y"
    {
			goto binary;
		}
    break;

  case 58:
#line 630 "../../lib/expr/exparse.y"
    {
			goto binary;
		}
    break;

  case 59:
#line 634 "../../lib/expr/exparse.y"
    {
			goto binary;
		}
    break;

  case 60:
#line 638 "../../lib/expr/exparse.y"
    {
			goto binary;
		}
    break;

  case 61:
#line 642 "../../lib/expr/exparse.y"
    {
		logical:
			if ((exvsp[(1) - (3)].expr)->type == STRING)
				(exvsp[(1) - (3)].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (exvsp[(1) - (3)].expr), NiL);
			else if (!BUILTIN((exvsp[(1) - (3)].expr)->type))
				(exvsp[(1) - (3)].expr) = excast(expr.program, (exvsp[(1) - (3)].expr), INTEGER, NiL, 0);
			if ((exvsp[(3) - (3)].expr)->type == STRING)
				(exvsp[(3) - (3)].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (exvsp[(3) - (3)].expr), NiL);
			else if (!BUILTIN((exvsp[(3) - (3)].expr)->type))
				(exvsp[(3) - (3)].expr) = excast(expr.program, (exvsp[(3) - (3)].expr), INTEGER, NiL, 0);
			goto binary;
		}
    break;

  case 62:
#line 655 "../../lib/expr/exparse.y"
    {
			goto logical;
		}
    break;

  case 63:
#line 659 "../../lib/expr/exparse.y"
    {
			if ((exvsp[(1) - (3)].expr)->op == CONSTANT)
			{
				exfreenode(expr.program, (exvsp[(1) - (3)].expr));
				(exval.expr) = (exvsp[(3) - (3)].expr);
			}
			else (exval.expr) = exnewnode(expr.program, ',', 1, (exvsp[(3) - (3)].expr)->type, (exvsp[(1) - (3)].expr), (exvsp[(3) - (3)].expr));
		}
    break;

  case 64:
#line 667 "../../lib/expr/exparse.y"
    {expr.nolabel=1;}
    break;

  case 65:
#line 667 "../../lib/expr/exparse.y"
    {expr.nolabel=0;}
    break;

  case 66:
#line 668 "../../lib/expr/exparse.y"
    {
			if (!(exvsp[(4) - (7)].expr)->type)
			{
				if (!(exvsp[(7) - (7)].expr)->type)
					(exvsp[(4) - (7)].expr)->type = (exvsp[(7) - (7)].expr)->type = INTEGER;
				else (exvsp[(4) - (7)].expr)->type = (exvsp[(7) - (7)].expr)->type;
			}
			else if (!(exvsp[(7) - (7)].expr)->type)
				(exvsp[(7) - (7)].expr)->type = (exvsp[(4) - (7)].expr)->type;
			if ((exvsp[(1) - (7)].expr)->type == STRING)
				(exvsp[(1) - (7)].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (exvsp[(1) - (7)].expr), NiL);
			else if (!INTEGRAL((exvsp[(1) - (7)].expr)->type))
				(exvsp[(1) - (7)].expr) = excast(expr.program, (exvsp[(1) - (7)].expr), INTEGER, NiL, 0);
			if ((exvsp[(4) - (7)].expr)->type != (exvsp[(7) - (7)].expr)->type)
			{
				if ((exvsp[(4) - (7)].expr)->type == STRING || (exvsp[(7) - (7)].expr)->type == STRING)
					exerror("if statement string type mismatch");
				else if ((exvsp[(4) - (7)].expr)->type == FLOATING)
					(exvsp[(7) - (7)].expr) = excast(expr.program, (exvsp[(7) - (7)].expr), FLOATING, NiL, 0);
				else if ((exvsp[(7) - (7)].expr)->type == FLOATING)
					(exvsp[(4) - (7)].expr) = excast(expr.program, (exvsp[(4) - (7)].expr), FLOATING, NiL, 0);
			}
			if ((exvsp[(1) - (7)].expr)->op == CONSTANT)
			{
				if ((exvsp[(1) - (7)].expr)->data.constant.value.integer)
				{
					(exval.expr) = (exvsp[(4) - (7)].expr);
					exfreenode(expr.program, (exvsp[(7) - (7)].expr));
				}
				else
				{
					(exval.expr) = (exvsp[(7) - (7)].expr);
					exfreenode(expr.program, (exvsp[(4) - (7)].expr));
				}
				exfreenode(expr.program, (exvsp[(1) - (7)].expr));
			}
			else (exval.expr) = exnewnode(expr.program, '?', 1, (exvsp[(4) - (7)].expr)->type, (exvsp[(1) - (7)].expr), exnewnode(expr.program, ':', 1, (exvsp[(4) - (7)].expr)->type, (exvsp[(4) - (7)].expr), (exvsp[(7) - (7)].expr)));
		}
    break;

  case 67:
#line 707 "../../lib/expr/exparse.y"
    {
		iunary:
			if ((exvsp[(2) - (2)].expr)->type == STRING)
				(exvsp[(2) - (2)].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (exvsp[(2) - (2)].expr), NiL);
			else if (!INTEGRAL((exvsp[(2) - (2)].expr)->type))
				(exvsp[(2) - (2)].expr) = excast(expr.program, (exvsp[(2) - (2)].expr), INTEGER, NiL, 0);
		unary:
			(exval.expr) = exnewnode(expr.program, (exvsp[(1) - (2)].op), 1, (exvsp[(2) - (2)].expr)->type == UNSIGNED ? INTEGER : (exvsp[(2) - (2)].expr)->type, (exvsp[(2) - (2)].expr), NiL);
			if ((exvsp[(2) - (2)].expr)->op == CONSTANT)
			{
				(exval.expr)->data.constant.value = exeval(expr.program, (exval.expr), NiL);
				(exval.expr)->binary = 0;
				(exval.expr)->op = CONSTANT;
				exfreenode(expr.program, (exvsp[(2) - (2)].expr));
			}
			else if (!BUILTIN((exvsp[(2) - (2)].expr)->type)) {
				checkBinary(expr.program, (exvsp[(2) - (2)].expr), (exval.expr), 0);
			}
		}
    break;

  case 68:
#line 727 "../../lib/expr/exparse.y"
    {
			goto iunary;
		}
    break;

  case 69:
#line 731 "../../lib/expr/exparse.y"
    {
			goto unary;
		}
    break;

  case 70:
#line 735 "../../lib/expr/exparse.y"
    {
			(exval.expr) = (exvsp[(2) - (2)].expr);
		}
    break;

  case 71:
#line 739 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, ADDRESS, 0, T((exvsp[(2) - (2)].expr)->type), (exvsp[(2) - (2)].expr), NiL);
		}
    break;

  case 72:
#line 743 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, ARRAY, 1, T((exvsp[(1) - (4)].id)->type), call(0, (exvsp[(1) - (4)].id), (exvsp[(3) - (4)].expr)), (exvsp[(3) - (4)].expr));
		}
    break;

  case 73:
#line 747 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, FUNCTION, 1, T((exvsp[(1) - (4)].id)->type), call(0, (exvsp[(1) - (4)].id), (exvsp[(3) - (4)].expr)), (exvsp[(3) - (4)].expr));
		}
    break;

  case 74:
#line 751 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewsub (expr.program, (exvsp[(3) - (4)].expr), GSUB);
		}
    break;

  case 75:
#line 755 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewsub (expr.program, (exvsp[(3) - (4)].expr), SUB);
		}
    break;

  case 76:
#line 759 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewsubstr (expr.program, (exvsp[(3) - (4)].expr));
		}
    break;

  case 77:
#line 763 "../../lib/expr/exparse.y"
    {
			if (!INTEGRAL((exvsp[(3) - (4)].expr)->type))
				(exvsp[(3) - (4)].expr) = excast(expr.program, (exvsp[(3) - (4)].expr), INTEGER, NiL, 0);
			(exval.expr) = exnewnode(expr.program, EXIT, 1, INTEGER, (exvsp[(3) - (4)].expr), NiL);
		}
    break;

  case 78:
#line 769 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, RAND, 0, FLOATING, NiL, NiL);
		}
    break;

  case 79:
#line 773 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, SRAND, 0, INTEGER, NiL, NiL);
		}
    break;

  case 80:
#line 777 "../../lib/expr/exparse.y"
    {
			if (!INTEGRAL((exvsp[(3) - (4)].expr)->type))
				(exvsp[(3) - (4)].expr) = excast(expr.program, (exvsp[(3) - (4)].expr), INTEGER, NiL, 0);
			(exval.expr) = exnewnode(expr.program, SRAND, 1, INTEGER, (exvsp[(3) - (4)].expr), NiL);
		}
    break;

  case 81:
#line 783 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, CALL, 1, (exvsp[(1) - (4)].id)->type, NiL, (exvsp[(3) - (4)].expr));
			(exval.expr)->data.call.procedure = (exvsp[(1) - (4)].id);
		}
    break;

  case 82:
#line 788 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exprint(expr.program, (exvsp[(1) - (4)].id), (exvsp[(3) - (4)].expr));
		}
    break;

  case 83:
#line 792 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, (exvsp[(1) - (4)].id)->index, 0, (exvsp[(1) - (4)].id)->type, NiL, NiL);
			if ((exvsp[(3) - (4)].expr) && (exvsp[(3) - (4)].expr)->data.operand.left->type == INTEGER)
			{
				(exval.expr)->data.print.descriptor = (exvsp[(3) - (4)].expr)->data.operand.left;
				(exvsp[(3) - (4)].expr) = (exvsp[(3) - (4)].expr)->data.operand.right;
			}
			else switch ((exvsp[(1) - (4)].id)->index)
			{
			case QUERY:
				(exval.expr)->data.print.descriptor = exnewnode(expr.program, CONSTANT, 0, INTEGER, NiL, NiL);
				(exval.expr)->data.print.descriptor->data.constant.value.integer = 2;
				break;
			case PRINTF:
				(exval.expr)->data.print.descriptor = exnewnode(expr.program, CONSTANT, 0, INTEGER, NiL, NiL);
				(exval.expr)->data.print.descriptor->data.constant.value.integer = 1;
				break;
			case SPRINTF:
				(exval.expr)->data.print.descriptor = 0;
				break;
			}
			(exval.expr)->data.print.args = preprint((exvsp[(3) - (4)].expr));
		}
    break;

  case 84:
#line 816 "../../lib/expr/exparse.y"
    {
			register Exnode_t*	x;

			(exval.expr) = exnewnode(expr.program, (exvsp[(1) - (4)].id)->index, 0, (exvsp[(1) - (4)].id)->type, NiL, NiL);
			if ((exvsp[(3) - (4)].expr) && (exvsp[(3) - (4)].expr)->data.operand.left->type == INTEGER)
			{
				(exval.expr)->data.scan.descriptor = (exvsp[(3) - (4)].expr)->data.operand.left;
				(exvsp[(3) - (4)].expr) = (exvsp[(3) - (4)].expr)->data.operand.right;
			}
			else switch ((exvsp[(1) - (4)].id)->index)
			{
			case SCANF:
				(exval.expr)->data.scan.descriptor = 0;
				break;
			case SSCANF:
				if ((exvsp[(3) - (4)].expr) && (exvsp[(3) - (4)].expr)->data.operand.left->type == STRING)
				{
					(exval.expr)->data.scan.descriptor = (exvsp[(3) - (4)].expr)->data.operand.left;
					(exvsp[(3) - (4)].expr) = (exvsp[(3) - (4)].expr)->data.operand.right;
				}
				else
					exerror("%s: string argument expected", (exvsp[(1) - (4)].id)->name);
				break;
			}
			if (!(exvsp[(3) - (4)].expr) || !(exvsp[(3) - (4)].expr)->data.operand.left || (exvsp[(3) - (4)].expr)->data.operand.left->type != STRING)
				exerror("%s: format argument expected", (exvsp[(1) - (4)].id)->name);
			(exval.expr)->data.scan.format = (exvsp[(3) - (4)].expr)->data.operand.left;
			for (x = (exval.expr)->data.scan.args = (exvsp[(3) - (4)].expr)->data.operand.right; x; x = x->data.operand.right)
			{
                if (x->data.operand.left->op != ADDRESS)
                    exerror("%s: address argument expected", (exvsp[(1) - (4)].id)->name);
                x->data.operand.left = x->data.operand.left->data.operand.left;
			}
		}
    break;

  case 85:
#line 851 "../../lib/expr/exparse.y"
    {
			if ((exvsp[(2) - (2)].expr))
			{
				if ((exvsp[(1) - (2)].expr)->op == ID && !expr.program->disc->setf)
					exerror("%s: variable assignment not supported", (exvsp[(1) - (2)].expr)->data.variable.symbol->name);
				else
				{
					if (!(exvsp[(1) - (2)].expr)->type)
						(exvsp[(1) - (2)].expr)->type = (exvsp[(2) - (2)].expr)->type;
#if 0
					else if ((exvsp[(2) - (2)].expr)->type != (exvsp[(1) - (2)].expr)->type && (exvsp[(1) - (2)].expr)->type >= 0200)
#else
					else if ((exvsp[(2) - (2)].expr)->type != (exvsp[(1) - (2)].expr)->type)
#endif
					{
						(exvsp[(2) - (2)].expr)->type = (exvsp[(1) - (2)].expr)->type;
						(exvsp[(2) - (2)].expr)->data.operand.right = excast(expr.program, (exvsp[(2) - (2)].expr)->data.operand.right, (exvsp[(1) - (2)].expr)->type, NiL, 0);
					}
					(exvsp[(2) - (2)].expr)->data.operand.left = (exvsp[(1) - (2)].expr);
					(exval.expr) = (exvsp[(2) - (2)].expr);
				}
			}
		}
    break;

  case 86:
#line 875 "../../lib/expr/exparse.y"
    {
		pre:
			if ((exvsp[(2) - (2)].expr)->type == STRING)
				exerror("++ and -- invalid for string variables");
			(exval.expr) = exnewnode(expr.program, (exvsp[(1) - (2)].op), 0, (exvsp[(2) - (2)].expr)->type, (exvsp[(2) - (2)].expr), NiL);
			(exval.expr)->subop = PRE;
		}
    break;

  case 87:
#line 883 "../../lib/expr/exparse.y"
    {
		pos:
			if ((exvsp[(1) - (2)].expr)->type == STRING)
				exerror("++ and -- invalid for string variables");
			(exval.expr) = exnewnode(expr.program, (exvsp[(2) - (2)].op), 0, (exvsp[(1) - (2)].expr)->type, (exvsp[(1) - (2)].expr), NiL);
			(exval.expr)->subop = POS;
		}
    break;

  case 88:
#line 891 "../../lib/expr/exparse.y"
    {
			goto pre;
		}
    break;

  case 89:
#line 895 "../../lib/expr/exparse.y"
    {
			goto pos;
		}
    break;

  case 91:
#line 902 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, CONSTANT, 0, (exvsp[(1) - (1)].id)->type, NiL, NiL);
			if (!expr.program->disc->reff)
				exerror("%s: identifier references not supported", (exvsp[(1) - (1)].id)->name);
			else (exval.expr)->data.constant.value = (*expr.program->disc->reff)(expr.program, (exval.expr), (exvsp[(1) - (1)].id), NiL, NiL, EX_SCALAR, expr.program->disc);
		}
    break;

  case 92:
#line 909 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, CONSTANT, 0, FLOATING, NiL, NiL);
			(exval.expr)->data.constant.value.floating = (exvsp[(1) - (1)].floating);
		}
    break;

  case 93:
#line 914 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, CONSTANT, 0, INTEGER, NiL, NiL);
			(exval.expr)->data.constant.value.integer = (exvsp[(1) - (1)].integer);
		}
    break;

  case 94:
#line 919 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, CONSTANT, 0, STRING, NiL, NiL);
			(exval.expr)->data.constant.value.string = (exvsp[(1) - (1)].string);
		}
    break;

  case 95:
#line 924 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, CONSTANT, 0, UNSIGNED, NiL, NiL);
			(exval.expr)->data.constant.value.integer = (exvsp[(1) - (1)].integer);
		}
    break;

  case 101:
#line 940 "../../lib/expr/exparse.y"
    {
			(exval.expr) = makeVar(expr.program, (exvsp[(1) - (2)].id), 0, 0, (exvsp[(2) - (2)].reference));
		}
    break;

  case 102:
#line 944 "../../lib/expr/exparse.y"
    {
            Exnode_t*   n;

            n = exnewnode(expr.program, DYNAMIC, 0, (exvsp[(1) - (3)].id)->type, NiL, NiL);
            n->data.variable.symbol = (exvsp[(1) - (3)].id);
            n->data.variable.reference = 0;
            if (((n->data.variable.index = (exvsp[(2) - (3)].expr)) == 0) != ((exvsp[(1) - (3)].id)->local.pointer == 0))
              exerror("%s: is%s an array", (exvsp[(1) - (3)].id)->name, (exvsp[(1) - (3)].id)->local.pointer ? "" : " not");
			if ((exvsp[(1) - (3)].id)->local.pointer && ((exvsp[(1) - (3)].id)->index_type > 0)) {
				if ((exvsp[(2) - (3)].expr)->type != (exvsp[(1) - (3)].id)->index_type)
            		exerror("%s: indices must have type %s", 
						(exvsp[(1) - (3)].id)->name, extypename(expr.program, (exvsp[(1) - (3)].id)->index_type));
			}
			if ((exvsp[(3) - (3)].reference)) {
              n->data.variable.dyna =exnewnode(expr.program, 0, 0, 0, NiL, NiL);
              (exval.expr) = makeVar(expr.program, (exvsp[(1) - (3)].id), (exvsp[(2) - (3)].expr), n, (exvsp[(3) - (3)].reference));
            }
            else (exval.expr) = n;
		}
    break;

  case 103:
#line 964 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, ID, 0, STRING, NiL, NiL);
			(exval.expr)->data.variable.symbol = (exvsp[(1) - (1)].id);
			(exval.expr)->data.variable.reference = 0;
			(exval.expr)->data.variable.index = 0;
			(exval.expr)->data.variable.dyna = 0;
			if (!(expr.program->disc->flags & EX_UNDECLARED))
				exerror("unknown identifier");
		}
    break;

  case 104:
#line 976 "../../lib/expr/exparse.y"
    {
			(exval.integer) = 0;
		}
    break;

  case 105:
#line 980 "../../lib/expr/exparse.y"
    {
			(exval.integer) = -1;
		}
    break;

  case 106:
#line 984 "../../lib/expr/exparse.y"
    {
			/* If DECLARE is VOID, its type is 0, so this acts like
			 * the empty case.
			 */
			if (INTEGRAL((exvsp[(2) - (3)].id)->type))
				(exval.integer) = INTEGER;
			else
				(exval.integer) = (exvsp[(2) - (3)].id)->type;
				
		}
    break;

  case 107:
#line 997 "../../lib/expr/exparse.y"
    {
			(exval.expr) = 0;
		}
    break;

  case 108:
#line 1001 "../../lib/expr/exparse.y"
    {
			(exval.expr) = (exvsp[(2) - (3)].expr);
		}
    break;

  case 109:
#line 1007 "../../lib/expr/exparse.y"
    {
			(exval.expr) = 0;
		}
    break;

  case 110:
#line 1011 "../../lib/expr/exparse.y"
    {
			(exval.expr) = (exvsp[(1) - (1)].expr)->data.operand.left;
			(exvsp[(1) - (1)].expr)->data.operand.left = (exvsp[(1) - (1)].expr)->data.operand.right = 0;
			exfreenode(expr.program, (exvsp[(1) - (1)].expr));
		}
    break;

  case 111:
#line 1019 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, ',', 1, 0, exnewnode(expr.program, ',', 1, (exvsp[(1) - (1)].expr)->type, (exvsp[(1) - (1)].expr), NiL), NiL);
			(exval.expr)->data.operand.right = (exval.expr)->data.operand.left;
		}
    break;

  case 112:
#line 1024 "../../lib/expr/exparse.y"
    {
			(exvsp[(1) - (3)].expr)->data.operand.right = (exvsp[(1) - (3)].expr)->data.operand.right->data.operand.right = exnewnode(expr.program, ',', 1, (exvsp[(1) - (3)].expr)->type, (exvsp[(3) - (3)].expr), NiL);
		}
    break;

  case 113:
#line 1030 "../../lib/expr/exparse.y"
    {
			(exval.expr) = 0;
		}
    break;

  case 114:
#line 1034 "../../lib/expr/exparse.y"
    {
			(exval.expr) = 0;
			if ((exvsp[(1) - (1)].id)->type)
				exerror("(void) expected");
		}
    break;

  case 116:
#line 1043 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, ',', 1, (exvsp[(1) - (1)].expr)->type, (exvsp[(1) - (1)].expr), NiL);
		}
    break;

  case 117:
#line 1047 "../../lib/expr/exparse.y"
    {
			register Exnode_t*	x;
			register Exnode_t*	y;

			(exval.expr) = (exvsp[(1) - (3)].expr);
			for (x = (exvsp[(1) - (3)].expr); (y = x->data.operand.right); x = y);
			x->data.operand.right = exnewnode(expr.program, ',', 1, (exvsp[(3) - (3)].expr)->type, (exvsp[(3) - (3)].expr), NiL);
		}
    break;

  case 118:
#line 1057 "../../lib/expr/exparse.y"
    {expr.declare=(exvsp[(1) - (1)].id)->type;}
    break;

  case 119:
#line 1058 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, ID, 0, (exvsp[(1) - (3)].id)->type, NiL, NiL);
			(exval.expr)->data.variable.symbol = (exvsp[(3) - (3)].id);
			(exvsp[(3) - (3)].id)->lex = DYNAMIC;
			(exvsp[(3) - (3)].id)->type = (exvsp[(1) - (3)].id)->type;
			(exvsp[(3) - (3)].id)->value = exnewnode(expr.program, 0, 0, 0, NiL, NiL);
			expr.procedure->data.procedure.arity++;
		}
    break;

  case 120:
#line 1069 "../../lib/expr/exparse.y"
    {
			(exval.reference) = expr.refs = expr.lastref = 0;
		}
    break;

  case 121:
#line 1073 "../../lib/expr/exparse.y"
    {
			Exref_t*	r;

			r = ALLOCATE(expr.program, Exref_t);
			r->symbol = (exvsp[(1) - (1)].id);
			expr.refs = r;
			expr.lastref = r;
			r->next = 0;
			r->index = 0;
			(exval.reference) = expr.refs;
		}
    break;

  case 122:
#line 1085 "../../lib/expr/exparse.y"
    {
			Exref_t*	r;
			Exref_t*	l;

			r = ALLOCATE(expr.program, Exref_t);
			r->symbol = (exvsp[(3) - (3)].id);
			r->index = 0;
			r->next = 0;
			l = ALLOCATE(expr.program, Exref_t);
			l->symbol = (exvsp[(2) - (3)].id);
			l->index = 0;
			l->next = r;
			expr.refs = l;
			expr.lastref = r;
			(exval.reference) = expr.refs;
        }
    break;

  case 123:
#line 1104 "../../lib/expr/exparse.y"
    {
			(exval.id) = (exvsp[(2) - (2)].id);
		}
    break;

  case 124:
#line 1108 "../../lib/expr/exparse.y"
    {
			(exval.id) = (exvsp[(2) - (2)].id);
		}
    break;

  case 125:
#line 1114 "../../lib/expr/exparse.y"
    {
			(exval.expr) = 0;
		}
    break;

  case 126:
#line 1118 "../../lib/expr/exparse.y"
    {
			(exval.expr) = exnewnode(expr.program, '=', 1, (exvsp[(2) - (2)].expr)->type, NiL, (exvsp[(2) - (2)].expr));
			(exval.expr)->subop = (exvsp[(1) - (2)].op);
		}
    break;

  case 128:
#line 1125 "../../lib/expr/exparse.y"
    {
				register Dtdisc_t*	disc;

				if (expr.procedure)
					exerror("no nested function definitions");
				expr.procedure = exnewnode(expr.program, PROCEDURE, 1, expr.declare, NiL, NiL);
				if (!(disc = newof(0, Dtdisc_t, 1, 0)))
					exerror("out of space [frame discipline]");
				disc->key = offsetof(Exid_t, name);
				if (!(expr.procedure->data.procedure.frame = dtopen(disc, Dtset)) || !dtview(expr.procedure->data.procedure.frame, expr.program->symbols))
					exerror("out of space [frame table]");
				expr.program->symbols = expr.program->frame = expr.procedure->data.procedure.frame;
				expr.program->formals = 1;
			}
    break;

  case 129:
#line 1138 "../../lib/expr/exparse.y"
    {
				expr.program->formals = 0;
				expr.id->lex = PROCEDURE;
				expr.id->type = expr.declare;
			}
    break;

  case 130:
#line 1143 "../../lib/expr/exparse.y"
    {
			(exval.expr) = expr.procedure;
			expr.procedure = 0;
			if (expr.program->frame)
			{
				expr.program->symbols = expr.program->frame->view;
				dtview(expr.program->frame, NiL);
			}
			(exval.expr)->data.operand.left = (exvsp[(3) - (8)].expr);
			(exval.expr)->data.operand.right = excast(expr.program, (exvsp[(7) - (8)].expr), (exval.expr)->type, NiL, 0);

			/*
			 * NOTE: procedure definition was slipped into the
			 *	 declaration initializer statement production,
			 *	 therefore requiring the statement terminator
			 */

			exunlex(expr.program, ';');
		}
    break;


/* Line 1267 of yacc.c.  */
#line 3123 "y.tab.c"
      default: break;
    }
  EX_SYMBOL_PRINT ("-> $$ =", exr1[exn], &exval, &exloc);

  EXPOPSTACK (exlen);
  exlen = 0;
  EX_STACK_PRINT (exss, exssp);

  *++exvsp = exval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  exn = exr1[exn];

  exstate = expgoto[exn - EXNTOKENS] + *exssp;
  if (0 <= exstate && exstate <= EXLAST && excheck[exstate] == *exssp)
    exstate = extable[exstate];
  else
    exstate = exdefgoto[exn - EXNTOKENS];

  goto exnewstate;


/*------------------------------------.
| exerrlab -- here on detecting error |
`------------------------------------*/
exerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!exerrstatus)
    {
      ++exnerrs;
#if ! EXERROR_VERBOSE
      exerror (EX_("syntax error"));
#else
      {
	EXSIZE_T exsize = exsyntax_error (0, exstate, exchar);
	if (exmsg_alloc < exsize && exmsg_alloc < EXSTACK_ALLOC_MAXIMUM)
	  {
	    EXSIZE_T exalloc = 2 * exsize;
	    if (! (exsize <= exalloc && exalloc <= EXSTACK_ALLOC_MAXIMUM))
	      exalloc = EXSTACK_ALLOC_MAXIMUM;
	    if (exmsg != exmsgbuf)
	      EXSTACK_FREE (exmsg);
	    exmsg = (char *) EXSTACK_ALLOC (exalloc);
	    if (exmsg)
	      exmsg_alloc = exalloc;
	    else
	      {
		exmsg = exmsgbuf;
		exmsg_alloc = sizeof exmsgbuf;
	      }
	  }

	if (0 < exsize && exsize <= exmsg_alloc)
	  {
	    (void) exsyntax_error (exmsg, exstate, exchar);
	    exerror (exmsg);
	  }
	else
	  {
	    exerror (EX_("syntax error"));
	    if (exsize != 0)
	      goto exexhaustedlab;
	  }
      }
#endif
    }



  if (exerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (exchar <= EXEOF)
	{
	  /* Return failure if at end of input.  */
	  if (exchar == EXEOF)
	    EXABORT;
	}
      else
	{
	  exdestruct ("Error: discarding",
		      extoken, &exlval);
	  exchar = EXEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto exerrlab1;


/*---------------------------------------------------.
| exerrorlab -- error raised explicitly by EXERROR.  |
`---------------------------------------------------*/
exerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     EXERROR and the label exerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto exerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this EXERROR.  */
  EXPOPSTACK (exlen);
  exlen = 0;
  EX_STACK_PRINT (exss, exssp);
  exstate = *exssp;
  goto exerrlab1;


/*-------------------------------------------------------------.
| exerrlab1 -- common code for both syntax error and EXERROR.  |
`-------------------------------------------------------------*/
exerrlab1:
  exerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      exn = expact[exstate];
      if (exn != EXPACT_NINF)
	{
	  exn += EXTERROR;
	  if (0 <= exn && exn <= EXLAST && excheck[exn] == EXTERROR)
	    {
	      exn = extable[exn];
	      if (0 < exn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (exssp == exss)
	EXABORT;


      exdestruct ("Error: popping",
		  exstos[exstate], exvsp);
      EXPOPSTACK (1);
      exstate = *exssp;
      EX_STACK_PRINT (exss, exssp);
    }

  if (exn == EXFINAL)
    EXACCEPT;

  *++exvsp = exlval;


  /* Shift the error token.  */
  EX_SYMBOL_PRINT ("Shifting", exstos[exn], exvsp, exlsp);

  exstate = exn;
  goto exnewstate;


/*-------------------------------------.
| exacceptlab -- EXACCEPT comes here.  |
`-------------------------------------*/
exacceptlab:
  exresult = 0;
  goto exreturn;

/*-----------------------------------.
| exabortlab -- EXABORT comes here.  |
`-----------------------------------*/
exabortlab:
  exresult = 1;
  goto exreturn;

#ifndef exoverflow
/*-------------------------------------------------.
| exexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
exexhaustedlab:
  exerror (EX_("memory exhausted"));
  exresult = 2;
  /* Fall through.  */
#endif

exreturn:
  if (exchar != EXEOF && exchar != EXEMPTY)
     exdestruct ("Cleanup: discarding lookahead",
		 extoken, &exlval);
  /* Do not reclaim the symbols of the rule which action triggered
     this EXABORT or EXACCEPT.  */
  EXPOPSTACK (exlen);
  EX_STACK_PRINT (exss, exssp);
  while (exssp != exss)
    {
      exdestruct ("Cleanup: popping",
		  exstos[*exssp], exvsp);
      EXPOPSTACK (1);
    }
#ifndef exoverflow
  if (exss != exssa)
    EXSTACK_FREE (exss);
#endif
#if EXERROR_VERBOSE
  if (exmsg != exmsgbuf)
    EXSTACK_FREE (exmsg);
#endif
  /* Make sure EXID is used.  */
  return EXID (exresult);
}


#line 1164 "../../lib/expr/exparse.y"


#include "exgram.h"

