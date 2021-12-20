
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
#define	COMMA	276
#define	LP	277
#define	RP	278
#define	LB	279
#define	RB	280
#define	LSB	281
#define	RSB	282
#define	MAIN	283
#define	SEMI	284
#define	IF	285
#define	ELSE	286
#define	READ	287
#define	WRITE	288
#define	WHILE	289
#define	BECOMES	290
#define	TRUE	291
#define	FALSE	292
#define	FOR	293
#define	RETURN	294
#define	NUMBER	295
#define	IDENT	296

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
	bool has_return;
	int pidx;
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
		int count;                   
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
    void X0_Compiler(const char *file);

#line 94 "x0.y"
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



#define	YYFINAL		173
#define	YYFLAG		-32768
#define	YYNTBASE	43

#define YYTRANSLATE(x) ((unsigned)(x) <= 296 ? yytranslate[x] : 94)

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
    37,    38,    39,    40,    41,    42
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     2,     3,    15,    16,    17,    18,    33,    34,
    35,    40,    41,    42,    48,    49,    50,    54,    55,    56,
    61,    62,    63,    67,    68,    69,    72,    74,    75,    79,
    86,    88,    90,    92,    94,    99,   100,   106,   109,   110,
   112,   114,   116,   118,   120,   122,   124,   126,   128,   129,
   130,   141,   144,   145,   146,   155,   156,   157,   158,   174,
   176,   177,   179,   180,   182,   183,   184,   188,   192,   196,
   199,   203,   205,   207,   211,   215,   219,   223,   227,   231,
   233,   236,   240,   244,   248,   250,   253,   257,   261,   263,
   267,   271,   275,   279,   281,   283,   285
};

static const short yyrhs[] = {    -1,
     0,     0,    61,    44,    47,    29,    45,    62,    25,    63,
    46,    68,    26,     0,     0,     0,     0,    65,    42,    23,
    48,    62,    51,    24,    25,    63,    49,    68,    26,    50,
    47,     0,     0,     0,    65,    42,    52,    53,     0,     0,
     0,    22,    65,    42,    54,    53,     0,     0,     0,    88,
    56,    57,     0,     0,     0,    22,    88,    58,    57,     0,
     0,     0,    40,    60,    87,     0,     0,     0,    63,    64,
     0,    64,     0,     0,    65,    42,    30,     0,    65,    42,
    27,    41,    28,    30,     0,    14,     0,    13,     0,    15,
     0,    42,     0,    42,    27,    88,    28,     0,     0,    42,
    67,    23,    55,    24,     0,    68,    69,     0,     0,    70,
     0,    74,     0,    85,     0,    83,     0,    86,     0,    76,
     0,    87,     0,    59,     0,    30,     0,     0,     0,    31,
    23,    88,    24,    61,    71,    69,    61,    72,    73,     0,
    32,    69,     0,     0,     0,    35,    23,    61,    88,    24,
    61,    75,    69,     0,     0,     0,     0,    39,    23,    80,
    30,    77,    61,    81,    30,    61,    78,    82,    79,    24,
    61,    69,     0,    88,     0,     0,    89,     0,     0,    88,
     0,     0,     0,    34,    84,    87,     0,    33,    66,    30,
     0,    25,    68,    26,     0,    88,    30,     0,    66,    36,
    88,     0,    89,     0,    90,     0,    90,     7,    90,     0,
    90,    12,    90,     0,    90,    10,    90,     0,    90,     8,
    90,     0,    90,    11,    90,     0,    90,     9,    90,     0,
    91,     0,    20,    91,     0,    90,    19,    91,     0,    90,
    18,    91,     0,    90,    17,    91,     0,    92,     0,    21,
    92,     0,    91,     3,    92,     0,    91,     5,    92,     0,
    93,     0,    92,     6,    93,     0,    92,     4,    93,     0,
    92,    16,    93,     0,    23,    88,    24,     0,    66,     0,
    41,     0,    37,     0,    38,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   111,   117,   126,   134,   141,   148,   156,   163,   163,   167,
   174,   174,   178,   185,   185,   189,   195,   195,   199,   205,
   205,   209,   215,   218,   225,   232,   233,   234,   238,   245,
   255,   256,   257,   261,   270,   280,   283,   295,   296,   300,
   301,   302,   303,   304,   305,   306,   307,   308,   312,   316,
   322,   328,   329,   333,   338,   345,   348,   354,   358,   367,
   368,   372,   373,   377,   378,   382,   386,   389,   400,   404,
   424,   430,   436,   437,   441,   445,   449,   453,   457,   465,
   466,   470,   474,   478,   484,   485,   489,   493,   500,   501,
   505,   509,   516,   517,   522,   526,   530
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","PLUS","DIV",
"MINUS","MUL","EQL","GEQ","LEQ","LSS","GTR","NEQ","CHAR","INT","BOOL","PER",
"XOR","OR","AND","NOT","ODD","COMMA","LP","RP","LB","RB","LSB","RSB","MAIN",
"SEMI","IF","ELSE","READ","WRITE","WHILE","BECOMES","TRUE","FALSE","FOR","RETURN",
"NUMBER","IDENT","main_function","@1","@2","@3","def_function","@4","@5","@6",
"parameters","@7","parameter","@8","call_parameters","@9","call_parameter","@10",
"return_stat","@11","pcode_register","table_register","declaration_list","declaration_stat",
"type","var","@12","statement_list","statement","if_stat","@13","@14","else_stat",
"while_stat","@15","for_stat","@16","@17","@18","for_exp1","for_exp2","for_exp3",
"write_stat","@19","read_stat","compound_stat","expression_stat","expression",
"simple_expr","logic_expr","additive_expr","term","factor", NULL
};
#endif

static const short yyr1[] = {     0,
    44,    45,    46,    43,    48,    49,    50,    47,    47,    52,
    51,    51,    54,    53,    53,    56,    55,    55,    58,    57,
    57,    60,    59,    61,    62,    63,    63,    63,    64,    64,
    65,    65,    65,    66,    66,    67,    66,    68,    68,    69,
    69,    69,    69,    69,    69,    69,    69,    69,    71,    72,
    70,    73,    73,    75,    74,    77,    78,    79,    76,    80,
    80,    81,    81,    82,    82,    84,    83,    85,    86,    87,
    88,    88,    89,    89,    89,    89,    89,    89,    89,    90,
    90,    90,    90,    90,    91,    91,    91,    91,    92,    92,
    92,    92,    93,    93,    93,    93,    93
};

static const short yyr2[] = {     0,
     0,     0,     0,    11,     0,     0,     0,    14,     0,     0,
     4,     0,     0,     5,     0,     0,     3,     0,     0,     4,
     0,     0,     3,     0,     0,     2,     1,     0,     3,     6,
     1,     1,     1,     1,     4,     0,     5,     2,     0,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
    10,     2,     0,     0,     8,     0,     0,     0,    15,     1,
     0,     1,     0,     1,     0,     0,     3,     3,     3,     2,
     3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
     2,     3,     3,     3,     1,     2,     3,     3,     1,     3,
     3,     3,     3,     1,     1,     1,     1
};

static const short yydefact[] = {    24,
     1,     9,    32,    31,    33,     0,     0,     2,     0,    25,
     5,     0,    25,    28,    12,     3,    27,     0,     0,     0,
    39,    26,     0,     0,    10,     0,     0,    29,    28,    15,
     0,     0,     0,    39,     4,    48,     0,     0,    66,     0,
    96,    97,     0,    22,    95,    34,    47,    94,    38,    40,
    41,    45,    43,    42,    44,    46,     0,    72,    73,    80,
    85,    89,     0,     6,     0,    11,    94,    81,    86,     0,
     0,     0,     0,     0,    24,    61,     0,     0,     0,     0,
    70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    39,     0,    93,    69,
     0,    68,    67,     0,     0,    60,    23,     0,    18,    71,
    74,    77,    79,    76,    78,    75,    84,    83,    82,    87,
    88,    91,    90,    92,    30,     0,    13,    24,     0,    56,
    35,     0,    16,     7,    15,    49,    24,    24,    37,    21,
     9,    14,     0,    54,    63,     0,    17,     8,    24,     0,
     0,    62,    19,    50,    55,    24,    21,    53,    57,    20,
     0,    51,    65,    52,    58,    64,     0,    24,     0,    59,
     0,     0,     0
};

static const short yydefgoto[] = {   171,
     2,    10,    21,     6,    13,    97,   141,    19,    30,    66,
   135,   132,   140,   147,   157,    47,    77,     1,    12,    16,
    17,    18,    48,    79,    26,    49,    50,   143,   158,   162,
    51,   150,    52,   138,   163,   167,   105,   151,   165,    53,
    74,    54,    55,    56,    57,    58,    59,    60,    61,    62
};

static const short yypact[] = {-32768,
-32768,    28,-32768,-32768,-32768,     0,    -7,-32768,     7,-32768,
-32768,    13,-32768,    28,    28,    28,-32768,    11,    31,    15,
-32768,-32768,   -19,    39,-32768,   117,    35,-32768,    28,    43,
    33,   -17,    -5,-32768,-32768,-32768,    50,    57,-32768,    77,
-32768,-32768,    89,-32768,-32768,    -1,-32768,    79,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    87,-32768,    86,    42,
     3,-32768,    88,    28,    28,-32768,-32768,    42,     3,    94,
   140,    -5,    91,    -5,-32768,    -5,    -5,    -5,    96,    -5,
-32768,    -5,    -5,    -5,    -5,    -5,    -5,    33,    33,    33,
   -17,   -17,   -17,   -17,   -17,    92,-32768,    81,-32768,-32768,
   100,-32768,-32768,    -5,    95,-32768,-32768,    98,    -5,-32768,
    32,    32,    32,    32,    32,    32,    42,    42,    42,     3,
     3,-32768,-32768,-32768,-32768,   163,-32768,-32768,   103,-32768,
-32768,   104,-32768,-32768,    43,-32768,-32768,-32768,-32768,   107,
    28,-32768,   186,-32768,    -5,    -5,-32768,-32768,-32768,   186,
   105,-32768,-32768,-32768,-32768,-32768,   107,   101,-32768,-32768,
   186,-32768,    -5,-32768,-32768,-32768,   106,-32768,   186,-32768,
   134,   136,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,     4,-32768,-32768,-32768,-32768,-32768,     9,
-32768,-32768,-32768,   -11,-32768,-32768,-32768,   -36,   149,   120,
   -12,    -2,    -4,-32768,   -31,  -138,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   -60,   -32,     8,    24,   -21,   -30,   -35
};


#define	YYLAST		228


static const short yytable[] = {     7,
    70,    69,    71,    22,   149,    33,    93,    27,    94,    68,
    28,   155,    20,   103,    31,    32,   107,    33,    95,    41,
    42,   -36,   164,    45,    46,    78,    67,    67,     8,    11,
   170,    41,    42,    73,     9,    45,    46,    14,   104,   101,
     3,     4,     5,   106,    91,   108,    92,   110,    88,    89,
    90,    22,    23,    32,    24,    33,    25,   122,   123,   124,
   120,   121,    98,    29,    65,   126,   117,   118,   119,    41,
    42,   129,    72,    45,    46,    63,   133,    67,    67,    67,
    67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
    67,   136,    82,    83,    84,    85,    86,    87,    46,    75,
   144,   145,    88,    89,    90,   111,   112,   113,   114,   115,
   116,    76,   154,   153,    80,    96,    81,    99,   109,   159,
   102,   125,   127,   128,   130,   131,   137,   139,   146,   168,
   166,   169,   161,   172,   156,   173,    31,    32,     7,    33,
    67,    34,    35,   142,   148,   160,    36,    37,    64,    38,
    39,    40,   152,    41,    42,    43,    44,    45,    46,    31,
    32,    15,    33,     0,    34,   100,     0,     0,     0,    36,
    37,     0,    38,    39,    40,     0,    41,    42,    43,    44,
    45,    46,    31,    32,     0,    33,     0,    34,   134,     0,
     0,     0,    36,    37,     0,    38,    39,    40,     0,    41,
    42,    43,    44,    45,    46,    31,    32,     0,    33,     0,
    34,     0,     0,     0,     0,    36,    37,     0,    38,    39,
    40,     0,    41,    42,    43,    44,    45,    46
};

static const short yycheck[] = {     2,
    33,    32,    34,    16,   143,    23,     4,    27,     6,    31,
    30,   150,    15,    74,    20,    21,    77,    23,    16,    37,
    38,    23,   161,    41,    42,    27,    31,    32,    29,    23,
   169,    37,    38,    38,    42,    41,    42,    25,    75,    72,
    13,    14,    15,    76,     3,    78,     5,    80,    17,    18,
    19,    64,    42,    21,    24,    23,    42,    93,    94,    95,
    91,    92,    65,    25,    22,    97,    88,    89,    90,    37,
    38,   104,    23,    41,    42,    41,   109,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,   128,     7,     8,     9,    10,    11,    12,    42,    23,
   137,   138,    17,    18,    19,    82,    83,    84,    85,    86,
    87,    23,   149,   146,    36,    28,    30,    24,    23,   156,
    30,    30,    42,    24,    30,    28,    24,    24,    22,    24,
   163,   168,    32,     0,    30,     0,    20,    21,   141,    23,
   145,    25,    26,   135,   141,   157,    30,    31,    29,    33,
    34,    35,   145,    37,    38,    39,    40,    41,    42,    20,
    21,    13,    23,    -1,    25,    26,    -1,    -1,    -1,    30,
    31,    -1,    33,    34,    35,    -1,    37,    38,    39,    40,
    41,    42,    20,    21,    -1,    23,    -1,    25,    26,    -1,
    -1,    -1,    30,    31,    -1,    33,    34,    35,    -1,    37,
    38,    39,    40,    41,    42,    20,    21,    -1,    23,    -1,
    25,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
    35,    -1,    37,    38,    39,    40,    41,    42
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
#line 113 "x0.y"
{
		gen(jmp, 0, 0);
	;
    break;}
case 2:
#line 118 "x0.y"
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
#line 128 "x0.y"
{
		table[yyvsp[-2].number].size = var_size;
		table[yyvsp[-2].number].count = var_cnt;
		set_address(var_cnt);
		gen(ini, 0 ,var_size+3);
	;
    break;}
case 4:
#line 135 "x0.y"
{
		gen(opr, 0, 0);
	;
    break;}
case 5:
#line 142 "x0.y"
{
		strcpy(function_name,yyvsp[-1].ident);
		strcpy(id, yyvsp[-1].ident);
		table_add(function, yyvsp[-2].number, 0);
		table[table_pointer].adr = pcode_pointer;
		reset();
	;
    break;}
case 6:
#line 150 "x0.y"
{
		table[yyvsp[-4].number].size = var_size;
		table[yyvsp[-4].number].count = var_cnt;
		set_address(var_cnt);
		gen(ini, 0 ,var_size+3);
	;
    break;}
case 7:
#line 157 "x0.y"
{
		if(has_return == false)
		{
			gen(opr, 1 , 0);
		}
	;
    break;}
case 10:
#line 168 "x0.y"
{
		var_size++;
		var_cnt++;
		strcpy(id, yyvsp[0].ident);
		table_add(variable, yyvsp[-1].number, 1);
	;
    break;}
case 12:
#line 174 "x0.y"
{;
    break;}
case 13:
#line 179 "x0.y"
{
		var_size++;
		var_cnt++;
		strcpy(id, yyvsp[0].ident);
		table_add(variable, yyvsp[-1].number, 1);
	;
    break;}
case 16:
#line 190 "x0.y"
{
		gen(sto, 1, pidx);
		gen(pop, 0 , 1);
		pidx++;
	;
    break;}
case 18:
#line 195 "x0.y"
{;
    break;}
case 19:
#line 200 "x0.y"
{
		gen(sto, 1, pidx);
		gen(pop, 0 , 1);
		pidx++;
	;
    break;}
case 21:
#line 205 "x0.y"
{;
    break;}
case 22:
#line 210 "x0.y"
{
		if(strcmp(function_name,"main") == 0) yyerror("can't use return in main function");
		is_return = true;
		has_return = true;
	;
    break;}
case 24:
#line 219 "x0.y"
{
		yyval.number = pcode_pointer;
	;
    break;}
case 25:
#line 226 "x0.y"
{
		yyval.number = table_pointer;
	;
    break;}
case 29:
#line 239 "x0.y"
{
		var_size++;
		var_cnt++;
		strcpy(id, yyvsp[-1].ident);
		table_add(variable, yyvsp[-2].number, 1);
	;
    break;}
case 30:
#line 246 "x0.y"
{
		var_cnt++;
		var_size += yyvsp[-2].number;
		strcpy(id, yyvsp[-4].ident);
		table_add(array, yyvsp[-5].number, yyvsp[-2].number);
	;
    break;}
case 31:
#line 255 "x0.y"
{yyval.number = 0;;
    break;}
case 32:
#line 256 "x0.y"
{yyval.number = 1;;
    break;}
case 33:
#line 257 "x0.y"
{yyval.number = 2;;
    break;}
case 34:
#line 262 "x0.y"
{
		yyval.number = position(yyvsp[0].ident);
		if(table[yyval.number].kind == array) yyerror("can't use array directly");
		if(table[yyval.number].kind == function) yyerror("can't use function directly");
		xt = table[yyval.number].X0_type;
		Kind = table[yyval.number].kind;
		printf("%s: %d",yyvsp[0].ident,Kind);
	;
    break;}
case 35:
#line 271 "x0.y"
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
case 36:
#line 281 "x0.y"
{
		pidx = 3;
	;
    break;}
case 37:
#line 284 "x0.y"
{
		yyval.number = position_fun(yyvsp[-4].ident);
		if(table[yyval.number].kind != function) myerror("%s is not a function",yyvsp[-4].ident);
		Kind = table[yyval.number].kind;
		has_return = false;
		gen(cal, 0, table[yyval.number].adr);
	;
    break;}
case 49:
#line 314 "x0.y"
{
		gen(jpc, 0, 0);
	;
    break;}
case 50:
#line 317 "x0.y"
{
		gen(jmp, 0, 0);
		pcode[yyvsp[-3].number].a = pcode_pointer;
	;
    break;}
case 51:
#line 322 "x0.y"
{
		pcode[yyvsp[-2].number].a = pcode_pointer;
	;
    break;}
case 54:
#line 334 "x0.y"
{
		gen(jpc, 0, 0);
	;
    break;}
case 55:
#line 338 "x0.y"
{
		gen(jmp, 0, yyvsp[-5].number);
		pcode[yyvsp[-2].number].a = pcode_pointer;
	;
    break;}
case 56:
#line 346 "x0.y"
{
		if(yyvsp[-1].number == 0) gen(pop, 0, 1);
	;
    break;}
case 57:
#line 349 "x0.y"
{
		gen(jpc, 0, 0);
		gen(jmp, 0, 0);
	;
    break;}
case 58:
#line 354 "x0.y"
{
		if(yyvsp[0].number == 0) gen(pop, 0, 1);
		gen(jmp, 0, yyvsp[-5].number);
	;
    break;}
case 59:
#line 359 "x0.y"
{
		gen(jmp, 0, yyvsp[-6].number+2);
		pcode[yyvsp[-6].number].a = pcode_pointer;
		pcode[yyvsp[-6].number+1].a = yyvsp[-1].number;
	;
    break;}
case 60:
#line 367 "x0.y"
{yyval.number = 0;;
    break;}
case 61:
#line 368 "x0.y"
{yyval.number = 1;;
    break;}
case 62:
#line 372 "x0.y"
{yyval.number = 0;;
    break;}
case 63:
#line 373 "x0.y"
{yyval.number = 1;;
    break;}
case 64:
#line 377 "x0.y"
{yyval.number = 0;;
    break;}
case 65:
#line 378 "x0.y"
{yyval.number = 1;;
    break;}
case 66:
#line 383 "x0.y"
{
		is_write = true;
	;
    break;}
case 68:
#line 390 "x0.y"
{
		gen(opr, xt, 16);
		if(Kind == array) gen(ast, 0, 0);
		else if(Kind == variable) gen(sto, 0, table[yyvsp[-1].number].adr);
		else yyerror("can't read a function");
		gen(pop, 0 ,1);
	;
    break;}
case 70:
#line 405 "x0.y"
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
case 71:
#line 425 "x0.y"
{
		if(Kind == array) gen(ast, 0, 0);
		else if (Kind == variable) gen(sto, 0, table[yyvsp[-2].number].adr);
		else yyerror("can't allocate a value to a function");
	;
    break;}
case 74:
#line 438 "x0.y"
{
		gen(opr, 0, 8);
	;
    break;}
case 75:
#line 442 "x0.y"
{
		gen(opr, 0, 9);
	;
    break;}
case 76:
#line 446 "x0.y"
{
		gen(opr, 0, 10);
	;
    break;}
case 77:
#line 450 "x0.y"
{
		gen(opr, 0, 11);
	;
    break;}
case 78:
#line 454 "x0.y"
{
		gen(opr, 0, 12);
	;
    break;}
case 79:
#line 458 "x0.y"
{
		gen(opr, 0, 13);
	;
    break;}
case 81:
#line 467 "x0.y"
{
		gen(opr, 0, 19);
	;
    break;}
case 82:
#line 471 "x0.y"
{
		gen(opr, 0, 18);
	;
    break;}
case 83:
#line 475 "x0.y"
{
		gen(opr, 1, 18);
	;
    break;}
case 84:
#line 479 "x0.y"
{
		gen(opr, 2, 18);
	;
    break;}
case 86:
#line 486 "x0.y"
{
		gen(opr, 0, 20);
	;
    break;}
case 87:
#line 490 "x0.y"
{
		gen(opr, 0, 2);
	;
    break;}
case 88:
#line 494 "x0.y"
{
		gen(opr, 0, 3);
	;
    break;}
case 90:
#line 502 "x0.y"
{
		gen(opr, 0, 4);
	;
    break;}
case 91:
#line 506 "x0.y"
{
		gen(opr, 0, 5);
	;
    break;}
case 92:
#line 510 "x0.y"
{
		gen(opr, 0, 17);
	;
    break;}
case 94:
#line 518 "x0.y"
{
		if(Kind == array) gen(ald, 0 ,0);
		else if(Kind == variable) gen(lod, 0, table[yyvsp[0].number].adr);
	;
    break;}
case 95:
#line 523 "x0.y"
{
		gen(lit, 0, yyvsp[0].number);
	;
    break;}
case 96:
#line 527 "x0.y"
{
		gen(lit, 0 ,1);
	;
    break;}
case 97:
#line 531 "x0.y"
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
#line 536 "x0.y"


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
	has_return = false;
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
	enum xtype map[3] = {X0_int, X0_char, X0_bool};
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
				if(i.l == 0) s[b+i.a] = s[t];
				else if(i.l == 1) s[t+i.a] = s[t];
				break;
			case stv:
				s[b] = s[t];
				break;
			case ast:
				t = t - 1;
				s[s[t]+b] = s[t+1];
				s[t] = s[t+1];
				break;
			case ald:
				s[t] = s[s[t]+b];
				break;
			case cal:	        /* 调用子过程 */
				s[t + 1] = 0;
				s[t + 2] = b;	/* 将本过程基地址入栈，即建立动态链 */
				s[t + 3] = p;	/* 将当前指令指针入栈，即保存返回地址 */
				b = t + 1;	    /* 改变基地址指针值为新过程的基地址 */
				p = i.a;	    /* 跳转 */
				break;
			case ini:	
				t = t + i.a;	
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


void X0_Compiler(const char* file){
    strcpy(fname,file);
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
}
