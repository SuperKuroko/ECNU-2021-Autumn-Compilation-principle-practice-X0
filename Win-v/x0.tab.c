
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
#define	RETURN	293
#define	NUMBER	294
#define	IDENT	295

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
	char bug[100];
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
	bool is_return;
	
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
	enum object Kind;

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
		ast,     ald,     stv,
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
	void myerror();
	int position_fun(char* a);

#line 92 "x0.y"
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



#define	YYFINAL		155
#define	YYFLAG		-32768
#define	YYNTBASE	42

#define YYTRANSLATE(x) ((unsigned)(x) <= 295 ? yytranslate[x] : 84)

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
    37,    38,    39,    40,    41
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     2,     3,    15,    16,    17,    31,    32,    33,
    34,    38,    39,    40,    43,    45,    46,    50,    57,    59,
    61,    63,    65,    70,    75,    78,    79,    81,    83,    85,
    87,    89,    91,    93,    95,    97,    98,    99,   110,   113,
   114,   115,   124,   125,   126,   127,   143,   145,   146,   148,
   149,   151,   152,   153,   157,   161,   165,   168,   172,   174,
   176,   180,   184,   188,   192,   196,   200,   202,   205,   209,
   213,   217,   219,   222,   226,   230,   232,   236,   240,   244,
   248,   250,   252,   254
};

static const short yyrhs[] = {    -1,
     0,     0,    52,    43,    46,    28,    44,    53,    24,    54,
    45,    58,    25,     0,     0,     0,    56,    41,    22,    47,
    53,    49,    23,    24,    54,    48,    58,    25,    46,     0,
     0,     0,     0,    39,    51,    77,     0,     0,     0,    54,
    55,     0,    55,     0,     0,    56,    41,    29,     0,    56,
    41,    26,    40,    27,    29,     0,    14,     0,    13,     0,
    15,     0,    41,     0,    41,    26,    78,    27,     0,    41,
    22,    49,    23,     0,    58,    59,     0,     0,    60,     0,
    64,     0,    75,     0,    73,     0,    76,     0,    66,     0,
    77,     0,    50,     0,    29,     0,     0,     0,    30,    22,
    78,    23,    52,    61,    59,    52,    62,    63,     0,    31,
    59,     0,     0,     0,    34,    22,    52,    78,    23,    52,
    65,    59,     0,     0,     0,     0,    38,    22,    70,    29,
    67,    52,    71,    29,    52,    68,    72,    69,    23,    52,
    59,     0,    78,     0,     0,    79,     0,     0,    78,     0,
     0,     0,    33,    74,    77,     0,    32,    57,    29,     0,
    24,    58,    25,     0,    78,    29,     0,    57,    35,    78,
     0,    79,     0,    80,     0,    80,     7,    80,     0,    80,
    12,    80,     0,    80,    10,    80,     0,    80,     8,    80,
     0,    80,    11,    80,     0,    80,     9,    80,     0,    81,
     0,    20,    81,     0,    80,    19,    81,     0,    80,    18,
    81,     0,    80,    17,    81,     0,    82,     0,    21,    82,
     0,    81,     3,    82,     0,    81,     5,    82,     0,    83,
     0,    82,     6,    83,     0,    82,     4,    83,     0,    82,
    16,    83,     0,    22,    78,    23,     0,    57,     0,    40,
     0,    36,     0,    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   109,   115,   124,   131,   138,   145,   152,   153,   157,   161,
   166,   169,   176,   183,   184,   185,   189,   196,   206,   207,
   208,   212,   220,   230,   240,   241,   245,   246,   247,   248,
   249,   250,   251,   252,   253,   257,   261,   267,   273,   274,
   278,   283,   290,   293,   299,   303,   312,   313,   317,   318,
   322,   323,   327,   331,   334,   345,   349,   369,   375,   381,
   382,   386,   390,   394,   398,   402,   410,   411,   415,   419,
   423,   429,   430,   434,   438,   445,   446,   450,   454,   461,
   462,   467,   471,   475
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","PLUS","DIV",
"MINUS","MUL","EQL","GEQ","LEQ","LSS","GTR","NEQ","CHAR","INT","BOOL","PER",
"XOR","OR","AND","NOT","ODD","LP","RP","LB","RB","LSB","RSB","MAIN","SEMI","IF",
"ELSE","READ","WRITE","WHILE","BECOMES","TRUE","FALSE","FOR","RETURN","NUMBER",
"IDENT","main_function","@1","@2","@3","def_function","@4","@5","paremeter",
"return_stat","@6","pcode_register","table_register","declaration_list","declaration_stat",
"type","var","statement_list","statement","if_stat","@7","@8","else_stat","while_stat",
"@9","for_stat","@10","@11","@12","for_exp1","for_exp2","for_exp3","write_stat",
"@13","read_stat","compound_stat","expression_stat","expression","simple_expr",
"logic_expr","additive_expr","term","factor", NULL
};
#endif

static const short yyr1[] = {     0,
    43,    44,    45,    42,    47,    48,    46,    46,    49,    51,
    50,    52,    53,    54,    54,    54,    55,    55,    56,    56,
    56,    57,    57,    57,    58,    58,    59,    59,    59,    59,
    59,    59,    59,    59,    59,    61,    62,    60,    63,    63,
    65,    64,    67,    68,    69,    66,    70,    70,    71,    71,
    72,    72,    74,    73,    75,    76,    77,    78,    78,    79,
    79,    79,    79,    79,    79,    79,    80,    80,    80,    80,
    80,    81,    81,    81,    81,    82,    82,    82,    82,    83,
    83,    83,    83,    83
};

static const short yyr2[] = {     0,
     0,     0,     0,    11,     0,     0,    13,     0,     0,     0,
     3,     0,     0,     2,     1,     0,     3,     6,     1,     1,
     1,     1,     4,     4,     2,     0,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     0,     0,    10,     2,     0,
     0,     8,     0,     0,     0,    15,     1,     0,     1,     0,
     1,     0,     0,     3,     3,     3,     2,     3,     1,     1,
     3,     3,     3,     3,     3,     3,     1,     2,     3,     3,
     3,     1,     2,     3,     3,     1,     3,     3,     3,     3,
     1,     1,     1,     1
};

static const short yydefact[] = {    12,
     1,     8,    20,    19,    21,     0,     0,     2,     0,    13,
     5,     0,    13,    16,     9,     3,    15,     0,     0,    26,
    14,     0,     0,     0,     0,    17,    16,     0,     0,     0,
    26,     4,    35,     0,     0,    53,     0,    83,    84,     0,
    10,    82,    22,    34,    81,    25,    27,    28,    32,    30,
    29,    31,    33,     0,    59,    60,    67,    72,    76,     0,
     6,    81,    68,    73,     0,     0,     0,     0,     0,    12,
    48,     0,     9,     0,     0,    57,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    26,    80,    56,     0,    55,    54,     0,     0,    47,
    11,     0,     0,    58,    61,    64,    66,    63,    65,    62,
    71,    70,    69,    74,    75,    78,    77,    79,    18,     0,
    12,     0,    43,    24,    23,     8,    36,    12,    12,     7,
     0,    41,    50,    12,     0,     0,    49,    37,    42,    12,
    40,    44,     0,    38,    52,    39,    45,    51,     0,    12,
     0,    46,     0,     0,     0
};

static const short yydefgoto[] = {   153,
     2,    10,    20,     6,    13,    92,    19,    44,    72,     1,
    12,    16,    17,    18,    62,    24,    46,    47,   131,   141,
   144,    48,   135,    49,   129,   145,   149,    99,   136,   147,
    50,    69,    51,    52,    53,    54,    55,    56,    57,    58,
    59
};

static const short yypact[] = {-32768,
-32768,    95,-32768,-32768,-32768,   -14,   -38,-32768,     0,-32768,
-32768,    17,-32768,    95,-32768,    95,-32768,     3,    23,-32768,
-32768,    -2,    25,    -4,    14,-32768,    95,    64,   161,    58,
-32768,-32768,-32768,    33,    16,-32768,    42,-32768,-32768,    51,
-32768,-32768,   -17,-32768,    40,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    47,-32768,   105,    35,    66,-32768,    54,
    95,-32768,    35,    66,    61,   111,    58,    68,    58,-32768,
    58,    58,-32768,    58,    58,-32768,    58,    58,    58,    58,
    58,    58,    64,    64,    64,   161,   161,   161,   161,   161,
    73,-32768,-32768,-32768,    80,-32768,-32768,    58,    77,-32768,
-32768,    97,    91,-32768,   120,   120,   120,   120,   120,   120,
    35,    35,    35,    66,    66,-32768,-32768,-32768,-32768,   133,
-32768,   103,-32768,-32768,-32768,    95,-32768,-32768,-32768,-32768,
   155,-32768,    58,-32768,   155,    99,-32768,-32768,-32768,-32768,
    98,-32768,   155,-32768,    58,-32768,-32768,-32768,   119,-32768,
   155,-32768,   134,   146,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,    30,-32768,-32768,   107,-32768,-32768,   -63,
   151,   141,    -8,    -1,   -24,   -29,  -112,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   -59,   -15,    45,    11,   -16,   -25,
    71
};


#define	YYLAST		202


static const short yytable[] = {    45,
     7,    66,     9,    64,    73,    45,    98,    21,    74,    97,
    68,    63,   101,     8,    65,    28,    29,    30,   134,    31,
    32,    11,   139,    25,    33,    34,    26,    35,    36,    37,
   146,    38,    39,    40,    41,    42,    43,    86,   152,    87,
    14,    45,    45,    22,    45,    23,    45,    45,    27,    45,
    45,    95,    21,    60,    67,   100,    43,   127,   103,   104,
   114,   115,   120,    70,   132,   133,   111,   112,   113,    88,
   138,    89,    71,    45,    75,    76,   142,    28,    29,    30,
    91,    90,   122,    93,    29,    30,   151,   105,   106,   107,
   108,   109,   110,    38,    39,    45,    96,    42,    43,    38,
    39,   119,   121,    42,    43,   123,    45,     3,     4,     5,
    45,    77,    78,    79,    80,    81,    82,   125,    45,   124,
    45,    83,    84,    85,     7,   128,    45,   140,   143,   148,
    28,    29,    30,   154,    31,    94,    83,    84,    85,    33,
    34,   150,    35,    36,    37,   155,    38,    39,    40,    41,
    42,    43,    28,    29,    30,   130,    31,   126,   116,   117,
   118,    33,    34,    15,    35,    36,    37,    61,    38,    39,
    40,    41,    42,    43,    28,    29,    30,   137,    31,   102,
     0,     0,    30,    33,    34,     0,    35,    36,    37,     0,
    38,    39,    40,    41,    42,    43,    38,    39,     0,     0,
    42,    43
};

static const short yycheck[] = {    24,
     2,    31,    41,    29,    22,    30,    70,    16,    26,    69,
    35,    28,    72,    28,    30,    20,    21,    22,   131,    24,
    25,    22,   135,    26,    29,    30,    29,    32,    33,    34,
   143,    36,    37,    38,    39,    40,    41,     3,   151,     5,
    24,    66,    67,    41,    69,    23,    71,    72,    24,    74,
    75,    67,    61,    40,    22,    71,    41,   121,    74,    75,
    86,    87,    92,    22,   128,   129,    83,    84,    85,     4,
   134,     6,    22,    98,    35,    29,   140,    20,    21,    22,
    27,    16,    98,    23,    21,    22,   150,    77,    78,    79,
    80,    81,    82,    36,    37,   120,    29,    40,    41,    36,
    37,    29,    23,    40,    41,    29,   131,    13,    14,    15,
   135,     7,     8,     9,    10,    11,    12,    27,   143,    23,
   145,    17,    18,    19,   126,    23,   151,    29,    31,   145,
    20,    21,    22,     0,    24,    25,    17,    18,    19,    29,
    30,    23,    32,    33,    34,     0,    36,    37,    38,    39,
    40,    41,    20,    21,    22,   126,    24,    25,    88,    89,
    90,    29,    30,    13,    32,    33,    34,    27,    36,    37,
    38,    39,    40,    41,    20,    21,    22,   133,    24,    73,
    -1,    -1,    22,    29,    30,    -1,    32,    33,    34,    -1,
    36,    37,    38,    39,    40,    41,    36,    37,    -1,    -1,
    40,    41
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
#line 111 "x0.y"
{
		gen(jmp, 0, 0);
	;
    break;}
case 2:
#line 116 "x0.y"
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
#line 126 "x0.y"
{
		table[yyvsp[-2].number].size = var_size;
		set_address(var_cnt);
		gen(ini, 0 ,var_size+3);
	;
    break;}
case 4:
#line 132 "x0.y"
{
		gen(opr, 0, 0);
	;
    break;}
case 5:
#line 139 "x0.y"
{
		strcpy(function_name,yyvsp[-1].ident);
		strcpy(id, yyvsp[-1].ident);
		table_add(function, yyvsp[-2].number, 0);
		table[table_pointer].adr = pcode_pointer;
		reset();
	;
    break;}
case 6:
#line 147 "x0.y"
{
		table[yyvsp[-4].number].size = var_size;
		set_address(var_cnt);
		gen(ini, 0 ,var_size+3);
	;
    break;}
case 10:
#line 162 "x0.y"
{
		if(strcmp(function_name,"main") == 0) yyerror("can't use return in main function");
		is_return = true;
	;
    break;}
case 12:
#line 170 "x0.y"
{
		yyval.number = pcode_pointer;
	;
    break;}
case 13:
#line 177 "x0.y"
{
		yyval.number = table_pointer;
	;
    break;}
case 17:
#line 190 "x0.y"
{
		var_size++;
		var_cnt++;
		strcpy(id, yyvsp[-1].ident);
		table_add(variable, yyvsp[-2].number, 1);
	;
    break;}
case 18:
#line 197 "x0.y"
{
		var_cnt++;
		var_size += yyvsp[-2].number;
		strcpy(id, yyvsp[-4].ident);
		table_add(array, yyvsp[-5].number, yyvsp[-2].number);
	;
    break;}
case 19:
#line 206 "x0.y"
{yyval.number = 0;;
    break;}
case 20:
#line 207 "x0.y"
{yyval.number = 1;;
    break;}
case 21:
#line 208 "x0.y"
{yyval.number = 2;;
    break;}
case 22:
#line 213 "x0.y"
{
		yyval.number = position(yyvsp[0].ident);
		if(table[yyval.number].kind == array) yyerror("can't use array directly");
		if(table[yyval.number].kind == function) yyerror("can't use function directly");
		xt = table[yyval.number].X0_type;
		Kind = table[yyval.number].kind;
	;
    break;}
case 23:
#line 221 "x0.y"
{
		yyval.number = position(yyvsp[-3].ident);
		if(table[yyval.number].kind == variable) yyerror("can't use variable with []");
		if(table[yyval.number].kind == function) yyerror("can't use function with []");
		xt = table[yyval.number].X0_type;
		Kind = table[yyval.number].kind;
		gen(lit, 0, table[yyval.number].adr);
		gen(opr, 0, 2);
	;
    break;}
case 24:
#line 231 "x0.y"
{
		yyval.number = position_fun(yyvsp[-3].ident);
		if(table[yyval.number].kind != function) myerror("%s is not a function",yyvsp[-3].ident);
		Kind = table[yyval.number].kind;
		gen(cal, 0, table[yyval.number].adr);
	;
    break;}
case 36:
#line 259 "x0.y"
{
		gen(jpc, 0, 0);
	;
    break;}
case 37:
#line 262 "x0.y"
{
		gen(jmp, 0, 0);
		pcode[yyvsp[-3].number].a = pcode_pointer;
	;
    break;}
case 38:
#line 267 "x0.y"
{
		pcode[yyvsp[-2].number].a = pcode_pointer;
	;
    break;}
case 41:
#line 279 "x0.y"
{
		gen(jpc, 0, 0);
	;
    break;}
case 42:
#line 283 "x0.y"
{
		gen(jmp, 0, yyvsp[-5].number);
		pcode[yyvsp[-2].number].a = pcode_pointer;
	;
    break;}
case 43:
#line 291 "x0.y"
{
		if(yyvsp[-1].number == 0) gen(pop, 0, 1);
	;
    break;}
case 44:
#line 294 "x0.y"
{
		gen(jpc, 0, 0);
		gen(jmp, 0, 0);
	;
    break;}
case 45:
#line 299 "x0.y"
{
		if(yyvsp[0].number == 0) gen(pop, 0, 1);
		gen(jmp, 0, yyvsp[-5].number);
	;
    break;}
case 46:
#line 304 "x0.y"
{
		gen(jmp, 0, yyvsp[-6].number+2);
		pcode[yyvsp[-6].number].a = pcode_pointer;
		pcode[yyvsp[-6].number+1].a = yyvsp[-1].number;
	;
    break;}
case 47:
#line 312 "x0.y"
{yyval.number = 0;;
    break;}
case 48:
#line 313 "x0.y"
{yyval.number = 1;;
    break;}
case 49:
#line 317 "x0.y"
{yyval.number = 0;;
    break;}
case 50:
#line 318 "x0.y"
{yyval.number = 1;;
    break;}
case 51:
#line 322 "x0.y"
{yyval.number = 0;;
    break;}
case 52:
#line 323 "x0.y"
{yyval.number = 1;;
    break;}
case 53:
#line 328 "x0.y"
{
		is_write = true;
	;
    break;}
case 55:
#line 335 "x0.y"
{
		gen(opr, xt, 16);
		if(Kind = array) gen(ast, 0, 0);
		else if(Kind == variable) gen(sto, 0, table[yyvsp[-1].number].adr);
		else yyerror("can't read a function");
		gen(pop, 0 ,1);
	;
    break;}
case 57:
#line 350 "x0.y"
{
		if(is_write)
		{
			gen(opr, xt, 14);
			gen(opr, 0, 15);
			is_write = false;
		}
		if(is_return)
		{
			gen(stv, 0, 0);
			gen(opr, 1, 0);
			Kind = function;
			is_return = false;
		}
		gen(pop, 0, 1);
	;
    break;}
case 58:
#line 370 "x0.y"
{
		if(Kind == array) gen(ast, 0, 0);
		else if (Kind == variable) gen(sto, 0, table[yyvsp[-2].number].adr);
		else yyerror("can't allocate a value to a function");
	;
    break;}
case 61:
#line 383 "x0.y"
{
		gen(opr, 0, 8);
	;
    break;}
case 62:
#line 387 "x0.y"
{
		gen(opr, 0, 9);
	;
    break;}
case 63:
#line 391 "x0.y"
{
		gen(opr, 0, 10);
	;
    break;}
case 64:
#line 395 "x0.y"
{
		gen(opr, 0, 11);
	;
    break;}
case 65:
#line 399 "x0.y"
{
		gen(opr, 0, 12);
	;
    break;}
case 66:
#line 403 "x0.y"
{
		gen(opr, 0, 13);
	;
    break;}
case 68:
#line 412 "x0.y"
{
		gen(opr, 0, 19);
	;
    break;}
case 69:
#line 416 "x0.y"
{
		gen(opr, 0, 18);
	;
    break;}
case 70:
#line 420 "x0.y"
{
		gen(opr, 1, 18);
	;
    break;}
case 71:
#line 424 "x0.y"
{
		gen(opr, 2, 18);
	;
    break;}
case 73:
#line 431 "x0.y"
{
		gen(opr, 0, 20);
	;
    break;}
case 74:
#line 435 "x0.y"
{
		gen(opr, 0, 2);
	;
    break;}
case 75:
#line 439 "x0.y"
{
		gen(opr, 0, 3);
	;
    break;}
case 77:
#line 447 "x0.y"
{
		gen(opr, 0, 4);
	;
    break;}
case 78:
#line 451 "x0.y"
{
		gen(opr, 0, 5);
	;
    break;}
case 79:
#line 455 "x0.y"
{
		gen(opr, 0, 17);
	;
    break;}
case 81:
#line 463 "x0.y"
{
		if(Kind == array) gen(ald, 0 ,0);
		else if(Kind == variable) gen(lod, 0, table[yyvsp[0].number].adr);
	;
    break;}
case 82:
#line 468 "x0.y"
{
		gen(lit, 0, yyvsp[0].number);
	;
    break;}
case 83:
#line 472 "x0.y"
{
		gen(lit, 0 ,1);
	;
    break;}
case 84:
#line 476 "x0.y"
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
#line 481 "x0.y"


void yyerror(const char *s){
	err++;
	printf("error:%s! located at %d line\n", s, line);
	fprintf(fmistake, "error:%s! located at %d line\n", s, line);
}

void myerror(const char *s, const char *a)
{
	sprintf(bug,s,a);
	yyerror(bug);
}

void init()
{
	table_pointer = 0;
	pcode_pointer = 0;
	err = 0;
	var_cnt = 0;
	var_size = 0;
	is_write = false;
	is_return = false;
	line = 1;
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
	strcpy(table[0].master, function_name);
    i = table_pointer;
    while(strcmp(table[i].name, a) != 0 || strcmp(table[i].master,function_name)) --i;
	if(i == 0) myerror("%s is not declared",a);
    return i;
}

int position_fun(char* a)
{
    int i;
    strcpy(table[0].name, a);
    i = table_pointer;
    while(strcmp(table[i].name, a) != 0) --i;
	if(i == 0) myerror("%s function is not declared",a);
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
		{"lit"},{"opr"},{"lod"},{"sto"},{"cal"},{"ini"},{"jmp"},{"jpc"},{"pop"},{"ast"},{"ald"},{"stv"}
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
	s[1] = 0; /* SL */
	s[2] = 0; /* DL */
	s[3] = 0; /* RA */
	do {
	    i = pcode[p];	
		p = p + 1;      
		switch (i.f)
		{
			case pop:
				t = t - i.a;
				break;
			case lit:	
				t = t + 1;
				s[t] = i.a;				
				break;
			case opr:	
				switch (i.a)
				{
					case 0:  
						printf("EndT = %d\n",t);
						t = b - 1;
						p = s[t + 3];
						b = s[t + 2];
						t += i.l;
						break;
					case 1:
						s[t] = - s[t];
						break;
					case 2: 
						t = t - 1;
						s[t] = s[t] + s[t + 1];
						break;
					case 3:
						t = t - 1;
						s[t] = s[t] - s[t + 1];
						break;
					case 4:
						t = t - 1;
						s[t] = s[t] * s[t + 1];
						break;
					case 5:
						t = t - 1;
						s[t] = s[t] / s[t + 1];
						break;
					case 6:
						s[t] = s[t] % 2;
						break;
					case 8:
						t = t - 1;
						s[t] = (s[t] == s[t + 1]);
						break;
					case 9:
						t = t - 1;
						s[t] = (s[t] != s[t + 1]);
						break;
					case 10:
						t = t - 1;
						s[t] = (s[t] < s[t + 1]);
						break;
					case 11:
						t = t - 1;
						s[t] = (s[t] >= s[t + 1]);
						break;
					case 12:
						t = t - 1;
						s[t] = (s[t] > s[t + 1]);
						break;
					case 13: 
						t = t - 1;
						s[t] = (s[t] <= s[t + 1]);
						break;
					case 14:
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
					case 15:
						printf("\n");
						fprintf(fout,"\n");
						break;
					case 16:
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
			case lod:	
				t = t + 1;
				s[t] = s[i.a+b];	
				break;
			case sto:	
				s[b+i.a] = s[t];
				break;
			case stv:
				s[b] = s[t];
				break;
			case ast:
				t = t - 1;
				s[s[t]+b] = s[t+1];
				break;
			case ald:
				s[t] = s[s[t]+b];
				break;
			case cal:	        /* 调用子过程 */
				s[t + 2] = b;	/* 将本过程基地址入栈，即建立动态链 */
				s[t + 3] = p;	/* 将当前指令指针入栈，即保存返回地址 */
				b = t + 1;	    /* 改变基地址指针值为新过程的基地址 */
				p = i.a;	    /* 跳转 */
				break;
			case ini:	
				t = t + i.a;	
				printf("StaT = %d\n",t);
				break;
			case jmp:	
				p = i.a;
				break;
			case jpc:	
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
