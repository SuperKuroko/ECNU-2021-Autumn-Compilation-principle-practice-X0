
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
	char function_name[var_name_length];
    int num;
	int array_size;
	int err;
	int var_cnt;
	int var_size;
	int line;
	bool is_write;
	bool is_array_element;
	
    FILE* fin = NULL;    
    FILE* ftable = NULL; 
    FILE* fpcode = NULL; 
    FILE* fout = NULL;    
    FILE* fmistake = NULL;  

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
        char name[var_name_length]; 
        enum object kind;           
        int adr;                   
        int size;                   
		enum xtype X0_type;
		char master[var_name_length];
    };
    struct tablestruct table[table_length]; 

    enum fct 
    {
        lit,     opr,     lod, 
        sto,     cal,     ini, 
        jmp,     jpc,     pop,
		ast,     ald,
    };

    struct instruction
    {
        enum fct f;   
        int l;        
        int a;        
    };
    struct instruction pcode[pcode_length];

	void init();
	void table_add(enum object item, int type_id, int size);
	void set_address(int n);
	void gen(enum fct x, int y, int z);
    void display_table();
    void display_pcode();
    void interpret();
	void reset();

#line 88 "x0.y"
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



#define	YYFINAL		149
#define	YYFLAG		-32768
#define	YYNTBASE	41

#define YYTRANSLATE(x) ((unsigned)(x) <= 294 ? yytranslate[x] : 82)

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
     0,     1,     2,     3,    15,    16,    17,    32,    33,    34,
    35,    36,    37,    40,    42,    43,    47,    54,    56,    58,
    60,    62,    67,    70,    71,    73,    75,    77,    79,    81,
    83,    85,    87,    88,    89,   100,   103,   104,   105,   114,
   115,   116,   117,   133,   135,   136,   138,   139,   141,   142,
   143,   147,   151,   155,   158,   162,   164,   166,   170,   174,
   178,   182,   186,   190,   192,   195,   199,   203,   207,   209,
   212,   216,   220,   222,   226,   230,   234,   238,   240,   242,
   244
};

static const short yyrhs[] = {    -1,
     0,     0,    50,    42,    45,    28,    43,    51,    24,    52,
    44,    56,    25,     0,     0,     0,    54,    40,    22,    46,
    51,    48,    23,    24,    52,    47,    56,    49,    25,    45,
     0,     0,     0,     0,     0,     0,    52,    53,     0,    53,
     0,     0,    54,    40,    29,     0,    54,    40,    26,    39,
    27,    29,     0,    14,     0,    13,     0,    15,     0,    40,
     0,    40,    26,    76,    27,     0,    56,    57,     0,     0,
    58,     0,    62,     0,    73,     0,    71,     0,    74,     0,
    64,     0,    75,     0,    29,     0,     0,     0,    30,    22,
    76,    23,    50,    59,    57,    50,    60,    61,     0,    31,
    57,     0,     0,     0,    34,    22,    50,    76,    23,    50,
    63,    57,     0,     0,     0,     0,    38,    22,    68,    29,
    65,    50,    69,    29,    50,    66,    70,    67,    23,    50,
    57,     0,    76,     0,     0,    77,     0,     0,    76,     0,
     0,     0,    33,    72,    75,     0,    32,    55,    29,     0,
    24,    56,    25,     0,    76,    29,     0,    55,    35,    76,
     0,    77,     0,    78,     0,    78,     7,    78,     0,    78,
    12,    78,     0,    78,    10,    78,     0,    78,     8,    78,
     0,    78,    11,    78,     0,    78,     9,    78,     0,    79,
     0,    20,    79,     0,    78,    19,    79,     0,    78,    18,
    79,     0,    78,    17,    79,     0,    80,     0,    21,    80,
     0,    79,     3,    80,     0,    79,     5,    80,     0,    81,
     0,    80,     6,    81,     0,    80,     4,    81,     0,    80,
    16,    81,     0,    22,    76,    23,     0,    55,     0,    39,
     0,    36,     0,    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   105,   111,   120,   127,   134,   141,   147,   149,   153,   157,
   161,   168,   175,   176,   177,   181,   188,   198,   199,   200,
   204,   210,   221,   222,   226,   227,   228,   229,   230,   231,
   232,   233,   237,   241,   248,   254,   255,   259,   264,   271,
   274,   280,   284,   293,   294,   298,   299,   303,   304,   308,
   312,   315,   325,   329,   342,   347,   353,   354,   358,   362,
   366,   370,   374,   382,   383,   387,   391,   395,   401,   402,
   406,   410,   417,   418,   422,   426,   433,   434,   439,   443,
   447
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","PLUS","DIV",
"MINUS","MUL","EQL","GEQ","LEQ","LSS","GTR","NEQ","CHAR","INT","BOOL","PER",
"XOR","OR","AND","NOT","ODD","LP","RP","LB","RB","LSB","RSB","MAIN","SEMI","IF",
"ELSE","READ","WRITE","WHILE","BECOMES","TRUE","FALSE","FOR","NUMBER","IDENT",
"main_function","@1","@2","@3","def_function","@4","@5","paremeter","return_stat",
"pcode_register","table_register","declaration_list","declaration_stat","type",
"var","statement_list","statement","if_stat","@6","@7","else_stat","while_stat",
"@8","for_stat","@9","@10","@11","for_exp1","for_exp2","for_exp3","write_stat",
"@12","read_stat","compound_stat","expression_stat","expression","simple_expr",
"logic_expr","additive_expr","term","factor", NULL
};
#endif

static const short yyr1[] = {     0,
    42,    43,    44,    41,    46,    47,    45,    45,    48,    49,
    50,    51,    52,    52,    52,    53,    53,    54,    54,    54,
    55,    55,    56,    56,    57,    57,    57,    57,    57,    57,
    57,    57,    59,    60,    58,    61,    61,    63,    62,    65,
    66,    67,    64,    68,    68,    69,    69,    70,    70,    72,
    71,    73,    74,    75,    76,    76,    77,    77,    77,    77,
    77,    77,    77,    78,    78,    78,    78,    78,    79,    79,
    79,    79,    80,    80,    80,    80,    81,    81,    81,    81,
    81
};

static const short yyr2[] = {     0,
     0,     0,     0,    11,     0,     0,    14,     0,     0,     0,
     0,     0,     2,     1,     0,     3,     6,     1,     1,     1,
     1,     4,     2,     0,     1,     1,     1,     1,     1,     1,
     1,     1,     0,     0,    10,     2,     0,     0,     8,     0,
     0,     0,    15,     1,     0,     1,     0,     1,     0,     0,
     3,     3,     3,     2,     3,     1,     1,     3,     3,     3,
     3,     3,     3,     1,     2,     3,     3,     3,     1,     2,
     3,     3,     1,     3,     3,     3,     3,     1,     1,     1,
     1
};

static const short yydefact[] = {    11,
     1,     8,    19,    18,    20,     0,     0,     2,     0,    12,
     5,     0,    12,    15,     9,     3,    14,     0,     0,    24,
    13,     0,     0,     0,     0,    16,    15,     0,     0,     0,
    24,     4,    32,     0,     0,    50,     0,    80,    81,     0,
    79,    21,    78,    23,    25,    26,    30,    28,    27,    29,
    31,     0,    56,    57,    64,    69,    73,     0,     6,    78,
    65,    70,     0,     0,     0,     0,     0,    11,    45,     0,
     0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    24,    77,    53,
     0,    52,    51,     0,     0,    44,     0,    55,    58,    61,
    63,    60,    62,    59,    68,    67,    66,    71,    72,    75,
    74,    76,    17,    10,    11,     0,    40,    22,     0,    33,
    11,    11,     8,     0,    38,    47,     7,    11,     0,     0,
    46,    34,    39,    11,    37,    41,     0,    35,    49,    36,
    42,    48,     0,    11,     0,    43,     0,     0,     0
};

static const short yydefgoto[] = {   147,
     2,    10,    20,     6,    13,    88,    19,   119,     1,    12,
    16,    17,    18,    60,    24,    44,    45,   124,   135,   138,
    46,   129,    47,   122,   139,   143,    95,   130,   141,    48,
    67,    49,    50,    51,    52,    53,    54,    55,    56,    57
};

static const short yypact[] = {-32768,
-32768,    83,-32768,-32768,-32768,    -4,   -36,-32768,    20,-32768,
-32768,    -3,-32768,    83,-32768,    83,-32768,    13,    31,-32768,
-32768,   -10,    33,    -7,    35,-32768,    83,    80,   116,   108,
-32768,-32768,-32768,    42,    32,-32768,    60,-32768,-32768,    61,
-32768,    73,    51,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    74,-32768,   150,    64,    62,-32768,    77,    83,-32768,
    64,    62,    91,    55,   108,    97,   108,-32768,   108,   108,
   108,-32768,   108,   108,   108,   108,   108,   108,    80,    80,
    80,   116,   116,   116,   116,   116,   102,-32768,-32768,-32768,
   111,-32768,-32768,   108,   117,-32768,    85,-32768,    89,    89,
    89,    89,    89,    89,    64,    64,    64,    62,    62,-32768,
-32768,-32768,-32768,   103,-32768,   126,-32768,-32768,   125,-32768,
-32768,-32768,    83,   103,-32768,   108,-32768,-32768,   103,   122,
-32768,-32768,-32768,-32768,   123,-32768,   103,-32768,   108,-32768,
-32768,-32768,   140,-32768,   103,-32768,   164,   165,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,    43,-32768,-32768,-32768,-32768,   -63,   157,
   144,    -8,    -1,   -24,   -28,  -117,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   105,   -21,    47,   -39,   -18,   -27,    25
};


#define	YYLAST		173


static const short yytable[] = {    43,
     7,    62,    64,     9,    94,    43,   128,    21,    63,    61,
    66,   133,    28,    29,    30,    25,    31,    32,    26,   140,
    14,    33,    34,     8,    35,    36,    37,   146,    38,    39,
    40,    41,    42,    99,   100,   101,   102,   103,   104,    43,
    43,    11,    43,    91,    43,    43,    43,    96,    97,    98,
    21,   120,    22,    23,   108,   109,    27,   125,   126,   114,
   105,   106,   107,    65,   132,    84,    82,    85,    83,    43,
   136,    42,   116,    58,    28,    29,    30,    86,    31,    90,
   145,    68,    69,    33,    34,    71,    35,    36,    37,    43,
    38,    39,    40,    41,    42,     3,     4,     5,    70,    43,
    29,    30,    72,    87,    43,    79,    80,    81,   110,   111,
   112,   118,    43,    89,    43,    38,    39,   142,    41,    42,
    43,     7,    28,    29,    30,    92,    31,    28,    29,    30,
   113,    33,    34,   115,    35,    36,    37,    30,    38,    39,
    40,    41,    42,    38,    39,   117,    41,    42,   121,   123,
   134,    38,    39,   137,    41,    42,    73,    74,    75,    76,
    77,    78,   144,   148,   149,   127,    79,    80,    81,    15,
    59,    93,   131
};

static const short yycheck[] = {    24,
     2,    29,    31,    40,    68,    30,   124,    16,    30,    28,
    35,   129,    20,    21,    22,    26,    24,    25,    29,   137,
    24,    29,    30,    28,    32,    33,    34,   145,    36,    37,
    38,    39,    40,    73,    74,    75,    76,    77,    78,    64,
    65,    22,    67,    65,    69,    70,    71,    69,    70,    71,
    59,   115,    40,    23,    82,    83,    24,   121,   122,    88,
    79,    80,    81,    22,   128,     4,     3,     6,     5,    94,
   134,    40,    94,    39,    20,    21,    22,    16,    24,    25,
   144,    22,    22,    29,    30,    35,    32,    33,    34,   114,
    36,    37,    38,    39,    40,    13,    14,    15,    26,   124,
    21,    22,    29,    27,   129,    17,    18,    19,    84,    85,
    86,    27,   137,    23,   139,    36,    37,   139,    39,    40,
   145,   123,    20,    21,    22,    29,    24,    20,    21,    22,
    29,    29,    30,    23,    32,    33,    34,    22,    36,    37,
    38,    39,    40,    36,    37,    29,    39,    40,    23,    25,
    29,    36,    37,    31,    39,    40,     7,     8,     9,    10,
    11,    12,    23,     0,     0,   123,    17,    18,    19,    13,
    27,    67,   126
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
#line 107 "x0.y"
{
		gen(jmp, 0, 0);
	;
    break;}
case 2:
#line 112 "x0.y"
{
		strcpy(function_name,"main");
		strcpy(id, "main");
		table_add(function, 0, 0);
		table[table_pointer].adr = pcode_pointer;
		pcode[yyvsp[-3].number].a = pcode_pointer;
		reset();
	;
    break;}
case 3:
#line 122 "x0.y"
{
		table[yyvsp[-2].number].size = var_size;
		set_address(var_cnt);
		gen(ini, 0 ,var_size+3);
	;
    break;}
case 4:
#line 128 "x0.y"
{
		gen(opr, 0, 0);
	;
    break;}
case 5:
#line 135 "x0.y"
{
		strcpy(function_name,yyvsp[-1].ident);
		strcpy(id, yyvsp[-1].ident);
		table_add(function, yyvsp[-2].number, 0);
		table[table_pointer].adr = pcode_pointer;
		reset();
	;
    break;}
case 6:
#line 143 "x0.y"
{
		table[yyvsp[-4].number].size = var_size;
		set_address(var_cnt);
		gen(ini, 0 ,var_size+3);
	;
    break;}
case 11:
#line 162 "x0.y"
{
		yyval.number = pcode_pointer;
	;
    break;}
case 12:
#line 169 "x0.y"
{
		yyval.number = table_pointer;
	;
    break;}
case 16:
#line 182 "x0.y"
{
		var_size++;
		var_cnt++;
		strcpy(id, yyvsp[-1].ident);
		table_add(variable, yyvsp[-2].number, 1);
	;
    break;}
case 17:
#line 189 "x0.y"
{
		var_cnt++;
		var_size += yyvsp[-2].number;
		strcpy(id, yyvsp[-4].ident);
		table_add(array, yyvsp[-5].number, yyvsp[-2].number);
	;
    break;}
case 18:
#line 198 "x0.y"
{yyval.number = 0;;
    break;}
case 19:
#line 199 "x0.y"
{yyval.number = 1;;
    break;}
case 20:
#line 200 "x0.y"
{yyval.number = 2;;
    break;}
case 21:
#line 205 "x0.y"
{
		yyval.number = position(yyvsp[0].ident);
		xt = table[yyval.number].X0_type;
		is_array_element = false;
	;
    break;}
case 22:
#line 211 "x0.y"
{
		yyval.number = position(yyvsp[-3].ident);
		xt = table[yyval.number].X0_type;
		is_array_element = true;
		gen(lit, 0, table[yyval.number].adr);
		gen(opr, 0, 2);
	;
    break;}
case 33:
#line 239 "x0.y"
{
		gen(jpc, 0, 0);
	;
    break;}
case 34:
#line 242 "x0.y"
{
		gen(jmp, 0, 0);
		pcode[yyvsp[-3].number].a = pcode_pointer;

	;
    break;}
case 35:
#line 248 "x0.y"
{
		pcode[yyvsp[-2].number].a = pcode_pointer;
	;
    break;}
case 38:
#line 260 "x0.y"
{
		gen(jpc, 0, 0);
	;
    break;}
case 39:
#line 264 "x0.y"
{
		gen(jmp, 0, yyvsp[-5].number);
		pcode[yyvsp[-2].number].a = pcode_pointer;
	;
    break;}
case 40:
#line 272 "x0.y"
{
		if(yyvsp[-1].number == 0) gen(pop, 0, 1);
	;
    break;}
case 41:
#line 275 "x0.y"
{
		gen(jpc, 0, 0);
		gen(jmp, 0, 0);
	;
    break;}
case 42:
#line 280 "x0.y"
{
		if(yyvsp[0].number == 0) gen(pop, 0, 1);
		gen(jmp, 0, yyvsp[-5].number);
	;
    break;}
case 43:
#line 285 "x0.y"
{
		gen(jmp, 0, yyvsp[-6].number+2);
		pcode[yyvsp[-6].number].a = pcode_pointer;
		pcode[yyvsp[-6].number+1].a = yyvsp[-1].number;
	;
    break;}
case 44:
#line 293 "x0.y"
{yyval.number = 0;;
    break;}
case 45:
#line 294 "x0.y"
{yyval.number = 1;;
    break;}
case 46:
#line 298 "x0.y"
{yyval.number = 0;;
    break;}
case 47:
#line 299 "x0.y"
{yyval.number = 1;;
    break;}
case 48:
#line 303 "x0.y"
{yyval.number = 0;;
    break;}
case 49:
#line 304 "x0.y"
{yyval.number = 1;;
    break;}
case 50:
#line 309 "x0.y"
{
		is_write = true;
	;
    break;}
case 52:
#line 316 "x0.y"
{
		gen(opr, xt, 16);
		if(is_array_element) gen(ast, 0, 0);
		else gen(sto, 0, table[yyvsp[-1].number].adr);
		gen(pop, 0 ,1);
	;
    break;}
case 54:
#line 330 "x0.y"
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
case 55:
#line 343 "x0.y"
{
		if(is_array_element) gen(ast, 0, 0);
		else gen(sto, 0, table[yyvsp[-2].number].adr);
	;
    break;}
case 58:
#line 355 "x0.y"
{
		gen(opr, 0, 8);
	;
    break;}
case 59:
#line 359 "x0.y"
{
		gen(opr, 0, 9);
	;
    break;}
case 60:
#line 363 "x0.y"
{
		gen(opr, 0, 10);
	;
    break;}
case 61:
#line 367 "x0.y"
{
		gen(opr, 0, 11);
	;
    break;}
case 62:
#line 371 "x0.y"
{
		gen(opr, 0, 12);
	;
    break;}
case 63:
#line 375 "x0.y"
{
		gen(opr, 0, 13);
	;
    break;}
case 65:
#line 384 "x0.y"
{
		gen(opr, 0, 19);
	;
    break;}
case 66:
#line 388 "x0.y"
{
		gen(opr, 0, 18);
	;
    break;}
case 67:
#line 392 "x0.y"
{
		gen(opr, 1, 18);
	;
    break;}
case 68:
#line 396 "x0.y"
{
		gen(opr, 2, 18);
	;
    break;}
case 70:
#line 403 "x0.y"
{
		gen(opr, 0, 20);
	;
    break;}
case 71:
#line 407 "x0.y"
{
		gen(opr, 0, 2);
	;
    break;}
case 72:
#line 411 "x0.y"
{
		gen(opr, 0, 3);
	;
    break;}
case 74:
#line 419 "x0.y"
{
		gen(opr, 0, 4);
	;
    break;}
case 75:
#line 423 "x0.y"
{
		gen(opr, 0, 5);
	;
    break;}
case 76:
#line 427 "x0.y"
{
		gen(opr, 0, 17);
	;
    break;}
case 78:
#line 435 "x0.y"
{
		if(is_array_element) gen(ald, 0 ,0);
		else gen(lod, 0, table[yyvsp[0].number].adr);
	;
    break;}
case 79:
#line 440 "x0.y"
{
		gen(lit, 0, yyvsp[0].number);
	;
    break;}
case 80:
#line 444 "x0.y"
{
		gen(lit, 0 ,1);
	;
    break;}
case 81:
#line 448 "x0.y"
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
#line 453 "x0.y"


void yyerror(const char *s){
	err++;
    printf("error!:%s, located at %d line\n", s, line);
}

void init()
{
	table_pointer = 0;
	pcode_pointer = 0;
	err = 0;
	var_cnt = 0;
	var_size = 0;
	is_write = false;
	is_array_element = false;
}

void reset()
{
	var_cnt = 0;
	var_size = 0;
}

int position(char* a)
{
    int i;
    strcpy(table[0].name, a);
    i = table_pointer;
    while(strcmp(table[i].name, a) != 0) --i;
    return i;
}

void table_add(enum object item, int type_id, int size)
{
	enum xtype map[3] = {X0_int, X0_char, X0_char};
	table_pointer++;
	strcpy(table[table_pointer].name, id);
	strcpy(table[table_pointer].master, function_name);
	table[table_pointer].kind = item;
	table[table_pointer].size = size;
	table[table_pointer].X0_type = map[type_id];
}

void set_address(int n)
{
	int i,idx;
	int tar = 3+var_size;
	for(i = 1;i <= n;i++)
	{
		idx = table_pointer - i + 1;
		if(table[idx].kind == function) continue;
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
	char m1[][5] = {{"int "},{"char"},{"bool"}};
	char m2[][10] = {{"variable"},{"  array "},{"function"}};
    printf("num    name       kind       type     master   address   size\n");
	
	for (i = 1; i <= table_pointer; i++)
	{   
		if(table[i].kind == function && i > 1)
		{
			printf("\n",table[i].name);
			fprintf(ftable,"\n",table[i].name);
		}
		printf("%2d     %4s     %s     %s     %4s      %3d      %3d\n",i,table[i].name,m2[table[i].kind],m1[table[i].X0_type],table[i].master,table[i].adr,table[i].size);
		fprintf(ftable,"%2d     %4s     %s     %s     %4s      %3d      %3d\n",i,table[i].name,m2[table[i].kind],m1[table[i].X0_type],table[i].master,table[i].adr,table[i].size);
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
						printf("EndT = %d\n",t);
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
				}
				break;
			case lod:	/* 取相对当前过程的数据基地址为a的内存的值到栈顶 */
				t = t + 1;
				s[t] = s[i.a+b];	
				break;
			case sto:	/* 栈顶的值存到相对当前过程的数据基地址为a的内存 */
				s[b+i.a] = s[t];
				break;
			case ast:
				t = t - 1;
				s[s[t]+b] = s[t+1];
				break;
			case ald:
				s[t] = s[s[t]+b];
				break;
			case cal:	/* 调用子过程 */
				s[t + 2] = b;	/* 将本过程基地址入栈，即建立动态链 */
				s[t + 3] = p;	/* 将当前指令指针入栈，即保存返回地址 */
				b = t + 1;	/* 改变基地址指针值为新过程的基地址 */
				p = i.a;	/* 跳转 */
				break;
			case ini:	/* 在数据栈中为被调用的过程开辟a个单元的数据区 */
				t = t + i.a;	
				printf("StaT = %d\n",t);
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


int main(){
	strcpy(fname,"test.txt");
    //scanf("%s", fname);
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
