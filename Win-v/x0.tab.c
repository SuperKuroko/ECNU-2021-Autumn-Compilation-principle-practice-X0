
/*  A Bison parser, made from x0.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	PLUS	257
#define	DIV	258
#define	MINUS	259
#define	MUL	260
#define	EQL	261
#define	GEQ	262
#define	LEQ	263
#define	LSS	264
#define	GTR	265
#define	NEQ	266
#define	CHAR	267
#define	INT	268
#define	BOOL	269
#define	PER	270
#define	XOR	271
#define	OR	272
#define	AND	273
#define	NOT	274
#define	ODD	275
#define	LP	276
#define	RP	277
#define	LB	278
#define	RB	279
#define	LSB	280
#define	RSB	281
#define	MAIN	282
#define	SEMI	283
#define	IF	284
#define	ELSE	285
#define	READ	286
#define	WRITE	287
#define	WHILE	288
#define	BECOMES	289
#define	TRUE	290
#define	FALSE	291
#define	FOR	292
#define	NUMBER	293
#define	IDENT	294

#line 1 "x0.y"

    #define var_name_length 10
    #define table_length 1000
    #define pcode_length 200
	#define address_max 2048
	#define stacksize 3000

    #include <stdio.h>
    #include <stdlib.h>
    #include <malloc.h>
    #include <memory.h>
    #include <string.h>
    #include <stdbool.h>

	int table_pointer;
    int pcode_pointer;
    int lev;
	char fname[20];
    char id[var_name_length];
    int num;
	int array_size;
	int err;
	int var_cnt;
	int var_size;
	int line;
	bool is_write;
	bool is_array_element;
	
    FILE* fin = NULL;     /* input file */
    FILE* ftable = NULL;  /* the file which store the table output */
    FILE* fpcode = NULL;  /* the file which store the pcode output */
    FILE* fout = NULL;    /* output file */
    FILE* fmistake = NULL;  /* the file which store the error infomation (if had) */

    enum object 
	{
        variable,
		array,
        function
    };

	enum xtype
	{
		X0_int,
		X0_char,
		X0_bool
	};
	enum xtype xt;
    struct tablestruct
    {
        char name[var_name_length]; /* char array to store the var name*/
        enum object kind;           /* kind：const，var or procedure */
        int adr;                    /* adr: for all except const var */
        int size;                   /* size to alloc, only for procedure */
		enum xtype X0_type;         /* only for var or const */
    };

    struct tablestruct table[table_length]; 
    enum fct 
    {
        lit,     opr,     lod, 
        sto,     cal,     ini, 
        jmp,     jpc,     pop,
		ast,     ald,
    };

    /* vitrual machine instruction struct */
    struct instruction
    {
        enum fct f;   /* the type of instruction */
        int l;        /* the diff between reference level and declaration level */
        int a;        /* depend on the val of f */
    };
    struct instruction pcode[pcode_length]; /* store pcode array */

	void init();
	void table_add(enum object item);
	void set_address(int n);
	void gen(enum fct x, int y, int z);
    void display_table();
    void display_pcode();
    void interpret();
    int base(int l, int* s, int b);

#line 86 "x0.y"
typedef union{
    int number;
    char* ident;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		133
#define	YYFLAG		-32768
#define	YYNTBASE	41

#define YYTRANSLATE(x) ((unsigned)(x) <= 294 ? yytranslate[x] : 76)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     2,     3,    13,    14,    17,    19,    20,    24,
    31,    33,    35,    37,    39,    44,    47,    48,    50,    52,
    54,    56,    58,    60,    62,    64,    65,    66,    77,    80,
    81,    82,    91,    92,    93,    94,   110,   112,   113,   115,
   116,   118,   119,   120,   124,   128,   132,   135,   139,   141,
   143,   147,   151,   155,   159,   163,   167,   169,   172,   176,
   180,   184,   186,   189,   193,   197,   199,   203,   207,   211,
   215,   217,   219,   221
};

static const short yyrhs[] = {    -1,
     0,     0,    45,    42,    28,    43,    24,    46,    44,    50,
    25,     0,     0,    46,    47,     0,    47,     0,     0,    48,
    40,    29,     0,    48,    40,    26,    39,    27,    29,     0,
    14,     0,    13,     0,    15,     0,    40,     0,    40,    26,
    70,    27,     0,    50,    51,     0,     0,    52,     0,    56,
     0,    67,     0,    65,     0,    68,     0,    58,     0,    69,
     0,    29,     0,     0,     0,    30,    22,    70,    23,    45,
    53,    51,    45,    54,    55,     0,    31,    51,     0,     0,
     0,    34,    22,    45,    70,    23,    45,    57,    51,     0,
     0,     0,     0,    38,    22,    62,    29,    59,    45,    63,
    29,    45,    60,    64,    61,    23,    45,    51,     0,    70,
     0,     0,    71,     0,     0,    70,     0,     0,     0,    33,
    66,    69,     0,    32,    49,    29,     0,    24,    50,    25,
     0,    70,    29,     0,    49,    35,    70,     0,    71,     0,
    72,     0,    72,     7,    72,     0,    72,    12,    72,     0,
    72,    10,    72,     0,    72,     8,    72,     0,    72,    11,
    72,     0,    72,     9,    72,     0,    73,     0,    20,    73,
     0,    72,    19,    73,     0,    72,    18,    73,     0,    72,
    17,    73,     0,    74,     0,    21,    74,     0,    73,     3,
    74,     0,    73,     5,    74,     0,    75,     0,    74,     6,
    75,     0,    74,     4,    75,     0,    74,    16,    75,     0,
    22,    70,    23,     0,    49,     0,    39,     0,    36,     0,
    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   103,   109,   113,   118,   126,   132,   133,   134,   138,   148,
   162,   163,   164,   168,   174,   185,   186,   190,   191,   192,
   193,   194,   195,   196,   197,   201,   205,   212,   218,   219,
   223,   228,   235,   238,   244,   248,   257,   258,   262,   263,
   267,   268,   272,   276,   279,   289,   293,   306,   311,   317,
   318,   322,   326,   330,   334,   338,   346,   347,   351,   355,
   359,   365,   366,   370,   374,   381,   382,   386,   390,   397,
   398,   403,   407,   411
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","PLUS","DIV",
"MINUS","MUL","EQL","GEQ","LEQ","LSS","GTR","NEQ","CHAR","INT","BOOL","PER",
"XOR","OR","AND","NOT","ODD","LP","RP","LB","RB","LSB","RSB","MAIN","SEMI","IF",
"ELSE","READ","WRITE","WHILE","BECOMES","TRUE","FALSE","FOR","NUMBER","IDENT",
"main_function","@1","@2","@3","pcode_register","declaration_list","declaration_stat",
"type","var","statement_list","statement","if_stat","@4","@5","else_stat","while_stat",
"@6","for_stat","@7","@8","@9","for_exp1","for_exp2","for_exp3","write_stat",
"@10","read_stat","compound_stat","expression_stat","expression","simple_expr",
"logic_expr","additive_expr","term","factor", NULL
};
#endif

static const short yyr1[] = {     0,
    42,    43,    44,    41,    45,    46,    46,    46,    47,    47,
    48,    48,    48,    49,    49,    50,    50,    51,    51,    51,
    51,    51,    51,    51,    51,    53,    54,    52,    55,    55,
    57,    56,    59,    60,    61,    58,    62,    62,    63,    63,
    64,    64,    66,    65,    67,    68,    69,    70,    70,    71,
    71,    71,    71,    71,    71,    71,    72,    72,    72,    72,
    72,    73,    73,    73,    73,    74,    74,    74,    74,    75,
    75,    75,    75,    75
};

static const short yyr2[] = {     0,
     0,     0,     0,     9,     0,     2,     1,     0,     3,     6,
     1,     1,     1,     1,     4,     2,     0,     1,     1,     1,
     1,     1,     1,     1,     1,     0,     0,    10,     2,     0,
     0,     8,     0,     0,     0,    15,     1,     0,     1,     0,
     1,     0,     0,     3,     3,     3,     2,     3,     1,     1,
     3,     3,     3,     3,     3,     3,     1,     2,     3,     3,
     3,     1,     2,     3,     3,     1,     3,     3,     3,     3,
     1,     1,     1,     1
};

static const short yydefact[] = {     5,
     1,     0,     2,     0,     8,    12,    11,    13,     3,     7,
     0,    17,     6,     0,     0,     0,     9,     0,     0,     0,
    17,     4,    25,     0,     0,    43,     0,    73,    74,     0,
    72,    14,    71,    16,    18,    19,    23,    21,    20,    22,
    24,     0,    49,    50,    57,    62,    66,     0,    71,    58,
    63,     0,     0,     0,     0,     0,     5,    38,     0,     0,
    47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    70,    46,     0,    45,
    44,     0,     0,    37,     0,    48,    51,    54,    56,    53,
    55,    52,    61,    60,    59,    64,    65,    68,    67,    69,
    10,     5,     0,    33,    15,    26,     5,     5,     0,    31,
    40,     5,     0,     0,    39,    27,    32,     5,    30,    34,
     0,    28,    42,    29,    35,    41,     0,     5,     0,    36,
     0,     0,     0
};

static const short yydefgoto[] = {   131,
     2,     4,    12,     1,     9,    10,    11,    49,    15,    34,
    35,   109,   119,   122,    36,   113,    37,   108,   123,   127,
    83,   114,   125,    38,    56,    39,    40,    41,    42,    43,
    44,    45,    46,    47
};

static const short yypact[] = {-32768,
-32768,   -25,-32768,     2,    43,-32768,-32768,-32768,    43,-32768,
   -33,-32768,-32768,     6,    -9,     1,-32768,    88,    96,    -3,
-32768,-32768,-32768,    28,    20,-32768,    41,-32768,-32768,    42,
-32768,    53,    45,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    54,-32768,   130,    66,    62,-32768,    60,-32768,    66,
    62,    70,    52,    -3,    73,    -3,-32768,    -3,    -3,    -3,
-32768,    -3,    -3,    -3,    -3,    -3,    -3,    88,    88,    88,
    96,    96,    96,    96,    96,    97,-32768,-32768,   106,-32768,
-32768,    -3,   101,-32768,   104,-32768,    78,    78,    78,    78,
    78,    78,    66,    66,    66,    62,    62,-32768,-32768,-32768,
-32768,-32768,   111,-32768,-32768,-32768,-32768,-32768,    83,-32768,
    -3,-32768,    83,   114,-32768,-32768,-32768,-32768,   113,-32768,
    83,-32768,    -3,-32768,-32768,-32768,   122,-32768,    83,-32768,
   146,   150,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,   -53,-32768,   148,-32768,   -15,   137,  -107,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   103,   -12,    49,
    89,   -17,   -10,    26
};


#define	YYLAST		160


static const short yytable[] = {    33,
    50,   112,     3,    82,    33,   117,    14,    52,    51,    55,
    18,    19,    20,   124,    21,    22,    18,    19,    20,    23,
    24,   130,    25,    26,    27,     5,    28,    29,    30,    31,
    32,    16,    28,    29,    17,    31,    32,    33,    33,    48,
    33,    79,    33,    33,    33,    84,    85,    86,   106,    54,
    93,    94,    95,   110,   111,     6,     7,     8,   116,    32,
    96,    97,    57,    58,   120,    73,    33,    74,    71,   103,
    72,    18,    19,    20,   129,    21,    78,    75,    59,    60,
    23,    24,    61,    25,    26,    27,    76,    28,    29,    30,
    31,    32,    77,    33,    68,    69,    70,    33,    98,    99,
   100,    80,    18,    19,    20,    33,    21,    33,    19,    20,
   126,    23,    24,    33,    25,    26,    27,    20,    28,    29,
    30,    31,    32,    28,    29,   101,    31,    32,   102,   104,
   105,    28,    29,   107,    31,    32,    62,    63,    64,    65,
    66,    67,   118,   121,   128,   132,    68,    69,    70,   133,
    87,    88,    89,    90,    91,    92,    13,    53,    81,   115
};

static const short yycheck[] = {    15,
    18,   109,    28,    57,    20,   113,    40,    20,    19,    25,
    20,    21,    22,   121,    24,    25,    20,    21,    22,    29,
    30,   129,    32,    33,    34,    24,    36,    37,    38,    39,
    40,    26,    36,    37,    29,    39,    40,    53,    54,    39,
    56,    54,    58,    59,    60,    58,    59,    60,   102,    22,
    68,    69,    70,   107,   108,    13,    14,    15,   112,    40,
    71,    72,    22,    22,   118,     4,    82,     6,     3,    82,
     5,    20,    21,    22,   128,    24,    25,    16,    26,    35,
    29,    30,    29,    32,    33,    34,    27,    36,    37,    38,
    39,    40,    23,   109,    17,    18,    19,   113,    73,    74,
    75,    29,    20,    21,    22,   121,    24,   123,    21,    22,
   123,    29,    30,   129,    32,    33,    34,    22,    36,    37,
    38,    39,    40,    36,    37,    29,    39,    40,    23,    29,
    27,    36,    37,    23,    39,    40,     7,     8,     9,    10,
    11,    12,    29,    31,    23,     0,    17,    18,    19,     0,
    62,    63,    64,    65,    66,    67,     9,    21,    56,   111
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 105 "x0.y"
{
		gen(jmp, 0, 0);
	;
    break;}
case 2:
#line 109 "x0.y"
{
		pcode[yyvsp[-2].number].a = pcode_pointer;
	;
    break;}
case 3:
#line 114 "x0.y"
{
		set_address(var_cnt);
		gen(ini, 0 ,var_size+3);
	;
    break;}
case 4:
#line 119 "x0.y"
{
		gen(opr, 0, 0);
	;
    break;}
case 5:
#line 127 "x0.y"
{
		yyval.number = pcode_pointer;
	;
    break;}
case 9:
#line 139 "x0.y"
{
		var_size++;
		var_cnt++;
		strcpy(id, yyvsp[-1].ident);
		table_add(variable);
		if(yyvsp[-2].number == 1) table[table_pointer].X0_type = X0_int;
		else if(yyvsp[-2].number == 2)table[table_pointer].X0_type = X0_char;
		else if(yyvsp[-2].number == 3)table[table_pointer].X0_type = X0_bool;
	;
    break;}
case 10:
#line 149 "x0.y"
{
		var_cnt++;
		var_size += yyvsp[-2].number;
		strcpy(id, yyvsp[-4].ident);
		table_add(array);
		table[table_pointer].size = yyvsp[-2].number;
		if(yyvsp[-5].number == 1) table[table_pointer].X0_type = X0_int;
		else if(yyvsp[-5].number == 2)table[table_pointer].X0_type = X0_char;
		else if(yyvsp[-5].number == 3)table[table_pointer].X0_type = X0_bool;
	;
    break;}
case 11:
#line 162 "x0.y"
{yyval.number = 1;;
    break;}
case 12:
#line 163 "x0.y"
{yyval.number = 2;;
    break;}
case 13:
#line 164 "x0.y"
{yyval.number = 3;;
    break;}
case 14:
#line 169 "x0.y"
{
		yyval.number = position(yyvsp[0].ident);
		xt = table[yyval.number].X0_type;
		is_array_element = false;
	;
    break;}
case 15:
#line 175 "x0.y"
{
		yyval.number = position(yyvsp[-3].ident);
		xt = table[yyval.number].X0_type;
		is_array_element = true;
		gen(lit, 0, table[yyval.number].adr);
		gen(opr, 0, 2);
	;
    break;}
case 26:
#line 203 "x0.y"
{
		gen(jpc, 0, 0);
	;
    break;}
case 27:
#line 206 "x0.y"
{
		gen(jmp, 0, 0);
		pcode[yyvsp[-3].number].a = pcode_pointer;

	;
    break;}
case 28:
#line 212 "x0.y"
{
		pcode[yyvsp[-2].number].a = pcode_pointer;
	;
    break;}
case 31:
#line 224 "x0.y"
{
		gen(jpc, 0, 0);
	;
    break;}
case 32:
#line 228 "x0.y"
{
		gen(jmp, 0, yyvsp[-5].number);
		pcode[yyvsp[-2].number].a = pcode_pointer;
	;
    break;}
case 33:
#line 236 "x0.y"
{
		if(yyvsp[-1].number == 0) gen(pop, 0, 1);
	;
    break;}
case 34:
#line 239 "x0.y"
{
		gen(jpc, 0, 0);
		gen(jmp, 0, 0);
	;
    break;}
case 35:
#line 244 "x0.y"
{
		if(yyvsp[0].number == 0) gen(pop, 0, 1);
		gen(jmp, 0, yyvsp[-5].number);
	;
    break;}
case 36:
#line 249 "x0.y"
{
		gen(jmp, 0, yyvsp[-6].number+2);
		pcode[yyvsp[-6].number].a = pcode_pointer;
		pcode[yyvsp[-6].number+1].a = yyvsp[-1].number;
	;
    break;}
case 37:
#line 257 "x0.y"
{yyval.number = 0;;
    break;}
case 38:
#line 258 "x0.y"
{yyval.number = 1;;
    break;}
case 39:
#line 262 "x0.y"
{yyval.number = 0;;
    break;}
case 40:
#line 263 "x0.y"
{yyval.number = 1;;
    break;}
case 41:
#line 267 "x0.y"
{yyval.number = 0;;
    break;}
case 42:
#line 268 "x0.y"
{yyval.number = 1;;
    break;}
case 43:
#line 273 "x0.y"
{
		is_write = true;
	;
    break;}
case 45:
#line 280 "x0.y"
{
		gen(opr, xt, 16);
		if(is_array_element) gen(ast, 0, 0);
		else gen(sto, 0, table[yyvsp[-1].number].adr);
		gen(pop, 0 ,1);
	;
    break;}
case 47:
#line 294 "x0.y"
{
		if(is_write)
		{
			gen(opr, xt, 14);
			gen(opr, 0, 15);
			is_write = false;
		}
		gen(pop, 0, 1);
	;
    break;}
case 48:
#line 307 "x0.y"
{
		if(is_array_element) gen(ast, 0, 0);
		else gen(sto, 0, table[yyvsp[-2].number].adr);
	;
    break;}
case 51:
#line 319 "x0.y"
{
		gen(opr, 0, 8);
	;
    break;}
case 52:
#line 323 "x0.y"
{
		gen(opr, 0, 9);
	;
    break;}
case 53:
#line 327 "x0.y"
{
		gen(opr, 0, 10);
	;
    break;}
case 54:
#line 331 "x0.y"
{
		gen(opr, 0, 11);
	;
    break;}
case 55:
#line 335 "x0.y"
{
		gen(opr, 0, 12);
	;
    break;}
case 56:
#line 339 "x0.y"
{
		gen(opr, 0, 13);
	;
    break;}
case 58:
#line 348 "x0.y"
{
		gen(opr, 0, 19);
	;
    break;}
case 59:
#line 352 "x0.y"
{
		gen(opr, 0, 18);
	;
    break;}
case 60:
#line 356 "x0.y"
{
		gen(opr, 1, 18);
	;
    break;}
case 61:
#line 360 "x0.y"
{
		gen(opr, 2, 18);
	;
    break;}
case 63:
#line 367 "x0.y"
{
		gen(opr, 0, 20);
	;
    break;}
case 64:
#line 371 "x0.y"
{
		gen(opr, 0, 2);
	;
    break;}
case 65:
#line 375 "x0.y"
{
		gen(opr, 0, 3);
	;
    break;}
case 67:
#line 383 "x0.y"
{
		gen(opr, 0, 4);
	;
    break;}
case 68:
#line 387 "x0.y"
{
		gen(opr, 0, 5);
	;
    break;}
case 69:
#line 391 "x0.y"
{
		gen(opr, 0, 17);
	;
    break;}
case 71:
#line 399 "x0.y"
{
		if(is_array_element) gen(ald, 0 ,0);
		else gen(lod, 0, table[yyvsp[0].number].adr);
	;
    break;}
case 72:
#line 404 "x0.y"
{
		gen(lit, 0, yyvsp[0].number);
	;
    break;}
case 73:
#line 408 "x0.y"
{
		gen(lit, 0 ,1);
	;
    break;}
case 74:
#line 412 "x0.y"
{
		gen(lit, 0, 0);
	;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 417 "x0.y"


void yyerror(const char *s){
	//err++;
    printf("error!:%s\n, located at %d line\n", s, line);
}

void init()
{
	table_pointer = 0;
	pcode_pointer = 0;
	lev = 0;
	err = 0;
	var_cnt = 0;
	var_size = 0;
	is_write = false;
	is_array_element = false;
}

int position(char* a)
{
    int i;
    strcpy(table[0].name, a);
    i = table_pointer;
    while(strcmp(table[i].name, a) != 0) --i;
    return i;
}

void table_add(enum object item)
{
	table_pointer++;
	strcpy(table[table_pointer].name, id);
	table[table_pointer].kind = item;
	switch(item)
	{
		case variable:
			table[table_pointer].size = 1;
			break;
		case array:
			break;
		case function:
			break;
	}
}

void set_address(int n)
{
	int i,idx;
	int tar = 3+var_size;
	for(i = 1;i <= n;i++)
	{
		idx = table_pointer - i + 1;
		tar -= table[idx].size;
		table[idx].adr = tar;
	}
}

void gen(enum fct x, int y, int z)
{
	if (pcode_pointer >= pcode_length)
	{
		printf("Program is too long!\n");
		exit(1);
	}
	if (z >= address_max)
	{
		printf("Displacement address is too big!\n");
		exit(1);
	}
	pcode[pcode_pointer].f = x;
	pcode[pcode_pointer].l = y;
	pcode[pcode_pointer].a = z;
	pcode_pointer++;
}

void display_pcode()
{
	int i;
	char name[][5]=
	{
		{"lit"},{"opr"},{"lod"},{"sto"},{"cal"},{"ini"},{"jmp"},{"jpc"},{"pop"},{"ast"},{"ald"}
	};
	
    for (i = 0; i < pcode_pointer; i++)
    {
        printf("%d %s %d %d\n", i, name[pcode[i].f], pcode[i].l, pcode[i].a);
        fprintf(fpcode,"%d %s %d %d\n", i, name[pcode[i].f], pcode[i].l, pcode[i].a);
    }
}

void display_table()
{
	int i;
	char map[][5] = {{"int "},{"char"},{"bool"}};
    printf("num    name    kind      address  size\n");
	for (i = 1; i <= table_pointer; i++)
	{   
		switch (table[i].kind)
		{
			case variable:
				printf("%3d     %s     var:%s     %3d    %3d\n",i,table[i].name,map[table[i].X0_type],table[i].adr,table[i].size);
				fprintf(ftable, "%3d     %s     var:%s     %3d    %3d\n",i,table[i].name,map[table[i].X0_type],table[i].adr,table[i].size);
				break;

			case array:
				printf("%3d     %s     ary:%s     %3d    %3d\n",i,table[i].name,map[table[i].X0_type],table[i].adr,table[i].size);
				fprintf(ftable, "%3d     %s     ary:%s     %3d    %3d\n",i,table[i].name,map[table[i].X0_type],table[i].adr,table[i].size);
				break;

			case function:
				/*
				printf("    %d proc  %s ", i, table[i].name);
				printf("lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);

				fprintf(ftable,"    %d proc  %s ", i, table[i].name);
				fprintf(ftable,"lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
				*/
				break;
		}
	}
	printf("\n");
	fprintf(ftable, "\n");
}

void interpret()
{
	int p = 0; /* 指令指针 */
	int b = 1; /* 指令基址 */
	int t = 0; /* 栈顶指针 */
	struct instruction i;
	int s[stacksize];	

	printf("Start X0\n");
	fprintf(fout,"Start X0\n");
	s[0] = 0; /* s[0]不用 */
	s[1] = 0; /* 主程序的三个联系单元均置为0 */
	s[2] = 0;
	s[3] = 0;
	do {
	    i = pcode[p];	/* 读当前指令 */
		p = p + 1;      
		switch (i.f)
		{
			case pop:
				t = t - i.a;
				break;
			case lit:	/* 将常量a的值取到栈顶 */
				t = t + 1;
				s[t] = i.a;				
				break;
			case opr:	/* 数学、逻辑运算 */
				switch (i.a)
				{
					case 0:  /* 函数调用结束后返回 */
						printf("EDNt = %d\n",t);
						t = b - 1;
						p = s[t + 3];
						b = s[t + 2];
						break;
					case 1: /* 栈顶元素取反 */
						s[t] = - s[t];
						break;
					case 2: /* 次栈顶项加上栈顶项，退两个栈元素，相加值进栈 */
						t = t - 1;
						s[t] = s[t] + s[t + 1];
						break;
					case 3:/* 次栈顶项减去栈顶项 */
						t = t - 1;
						s[t] = s[t] - s[t + 1];
						break;
					case 4:/* 次栈顶项乘以栈顶项 */
						t = t - 1;
						s[t] = s[t] * s[t + 1];
						break;
					case 5:/* 次栈顶项除以栈顶项 */
						t = t - 1;
						s[t] = s[t] / s[t + 1];
						break;
					case 6:/* 栈顶元素的奇偶判断 */
						s[t] = s[t] % 2;
						break;
					case 8:/* 次栈顶项与栈顶项是否相等 */
						t = t - 1;
						s[t] = (s[t] == s[t + 1]);
						break;
					case 9:/* 次栈顶项与栈顶项是否不等 */
						t = t - 1;
						s[t] = (s[t] != s[t + 1]);
						break;
					case 10:/* 次栈顶项是否小于栈顶项 */
						t = t - 1;
						s[t] = (s[t] < s[t + 1]);
						break;
					case 11:/* 次栈顶项是否大于等于栈顶项 */
						t = t - 1;
						s[t] = (s[t] >= s[t + 1]);
						break;
					case 12:/* 次栈顶项是否大于栈顶项 */
						t = t - 1;
						s[t] = (s[t] > s[t + 1]);
						break;
					case 13: /* 次栈顶项是否小于等于栈顶项 */
						t = t - 1;
						s[t] = (s[t] <= s[t + 1]);
						break;
					case 14:/* 栈顶值输出 */
						if(i.l == 0)
						{
							printf("%d", s[t]);
							fprintf(fout, "%d", s[t]);
						}
						else if(i.l == 1)
						{
							printf("%c",s[t]);
							fprintf(fout,"%c",s[t]);
						}
						else if(i.l == 2)
						{
							printf("%s",(s[t]==0)?"false":"true");
							fprintf(fout,"%s",(s[t]==0)?"false":"true");
						}
						break;
					case 15:/* 输出换行符 */
						printf("\n");
						fprintf(fout,"\n");
						break;
					case 16:/* 读入一个输入置于栈顶 */
						t = t + 1;
						printf("?");
						fprintf(fout, "?");
						if(i.l == 0)
						{
							scanf("%d", &(s[t]));
							fprintf(fout, "%d\n", s[t]);	
						}
						else if(i.l == 1)
						{
							scanf(" %c", &(s[t]));
							fprintf(fout, "%c\n", s[t]);	
						}
						else
						{
							scanf("%d", &(s[t]));
							fprintf(fout, "%d\n", s[t]);
							if(s[t] != 0) s[t] = 1;
						}
						break;
					case 17:
						t = t - 1;
						s[t] = s[t] % s[t + 1];
						break;
					case 18:
						t = t - 1;
						if(s[t] != 0) s[t] = 1;
						if(s[t+1] != 0) s[t+1] = 1;
						if(i.l == 0) s[t] = s[t]&s[t+1];
						else if(i.l == 1) s[t] = s[t]|s[t+1];
						else if(i.l == 2) s[t] = s[t]^s[t+1];
						break;
					case 19:
						if(s[t] != 0) s[t] = 0;
						else s[t] = 1;
						break;
					case 20:
						s[t] = s[t]%2;
						break;
					case 21:
						s[t]++;
						break;
					case 22:
						s[t]--;
						break;
				}
				break;
			case lod:	/* 取相对当前过程的数据基地址为a的内存的值到栈顶 */
				t = t + 1;
				s[t] = s[i.a+1];	
				break;
			case sto:	/* 栈顶的值存到相对当前过程的数据基地址为a的内存 */
				s[1+i.a] = s[t];
				break;
			case ast:
				t = t - 1;
				s[s[t]+1] = s[t+1];
				break;
			case ald:
				s[t] = s[s[t]+1];
				break;
			case cal:	/* 调用子过程 */
				s[t + 1] = base(i.l, s, b);	/* 将父过程基地址入栈，即建立静态链 */
				s[t + 2] = b;	/* 将本过程基地址入栈，即建立动态链 */
				s[t + 3] = p;	/* 将当前指令指针入栈，即保存返回地址 */
				b = t + 1;	/* 改变基地址指针值为新过程的基地址 */
				p = i.a;	/* 跳转 */
				break;
			case ini:	/* 在数据栈中为被调用的过程开辟a个单元的数据区 */
				t = t + i.a;	
				printf("STAt = %d\n",t);
				break;
			case jmp:	/* 直接跳转 */
				p = i.a;
				break;
			case jpc:	/* 条件跳转 */
				if (s[t] == 0) 
					p = i.a;
				t = t - 1;
				break;
		}
	} while (p != 0);
	printf("End X0\n");
	fprintf(fout,"End X0\n");
}

int base(int l, int* s, int b)
{
	int b1;
	b1 = b;
	while (l > 0)
	{
		b1 = s[b1];
		l--;
	}
	return b1;
}

int main(){
    printf("Input file  ");
	strcpy(fname,"test.txt");
    scanf("%s", fname);
    if((fin = fopen(fname, "r")) == NULL)
    {
        printf("open file error!\n");
        exit(1);
    }

	if ((fmistake= fopen("error.txt", "w")) == NULL)
  	{
		printf("Can't open the error.txt file!\n");
		exit(1);
	}

	if ((ftable = fopen("table.txt", "w")) == NULL)
	{
		printf("Can't open table.txt file!\n");
		exit(1);
	}	

	if ((fpcode = fopen("code.txt", "w")) == NULL)
	{
		printf("Can't open code.txt file!\n");
		exit(1);
	}		

	if ((fout = fopen("out.txt", "w")) == NULL)
	{
		printf("Can't open out.txt file!\n");
		exit(1);
	}

    redirectInput(fin);
    init();
    yyparse();

	if(err == 0)
	{
		printf("\n===Parsing success!===\n");
		fprintf(fmistake, "\n===Parsing success!===\n");

		display_pcode();
		fclose(fpcode);

		display_table();
		fclose(ftable);
		
		interpret();      	
		fclose(fout);
	}

  	else
	{
		printf("%d errors in X0 program\n", err);
		fprintf(fmistake, "%d errors in X0 program\n", err);
	}
	fclose(fmistake);
	fclose(fin);
    return 0;
}
