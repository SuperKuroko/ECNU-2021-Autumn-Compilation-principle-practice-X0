/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "pl0.y"

    #define al 10
    #define cxmax 2000
    #define txmax 1000
    #define amax 2048
    #define strmax 20000
    #define stacksize 3000

    #include<stdio.h>
    #include<stdlib.h>
    #include<malloc.h>
    #include<memory.h>
    #include<string.h>
    #include<stdbool.h>
    FILE* fin;
    FILE* foutput;
    FILE* ftable;
    char fname[al];
    
    int tx;/*table */
    int cx;/* code*/
    int px;/*proctable*/
    int lev;
    int proctable[3];
    char id[al];
    extern int line;
    int err;
    int c_num;/* use to record const */
    int fortable[cxmax];
    int foroffset[cxmax];
    int forx;
    int vartable[cxmax];
    int  varx;
    int total_var;
    int tem;
    int offset;
    int preVar;
    int preVar_cnt;
    int proc_p;
    int pass_cnt;
    int isString;
    char buffer[strmax];
    char temstr[strmax];

    enum fct 
    {
        lit,     opr,     lod, 
        sto,     cal,     ini, 
        jmp,     jpc,     
    };
    struct instruction
    {
        enum fct f;   /* 虚拟机代码指令 */
        int l;        /* 引用层与声明层的层次差 */
        int a;        /* 根据f的不同而不同 */
    };
    struct instruction code[cxmax]; /* 存放虚拟机代码的数组 */
    enum object 
    {
        constant, 
        variable, 
        procedure,
    };
    enum type
    {
        xint,
        xchar,
        xvoid
    };

    /* 符号表结构 */
    struct tablestruct
    {
    char name[al];      /* 名字 */
    enum object kind;   /* 类型：const，var或procedure */
    int val;            /* 数值，仅const使用 */
        int level;          /* 所处层，仅const不使用 */ 
        int adr;            /* 地址，仅const不使用 */
        int size;           /* 需要分配的数据区空间, 仅procedure使用 */
    enum type t; /* type */
    int is_arry;
    int parameter_cnt;
    };
    struct tablestruct table[txmax]; /* 符号表 */


    void init();
    void enter(enum object k);
    void _enter(enum object k, int IsArry);
    void setdx(int n);
    void gen(enum fct x, int y, int z);
    void displaytable();
    void listall();
    void interpret();
    int base(int l, int* s, int b);



#line 169 "yacc.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_YACC_H_INCLUDED
# define YY_YY_YACC_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    num = 258,
    var = 259,
    CHAR = 260,
    INT = 261,
    VOID = 262,
    STRING = 263,
    Plus = 264,
    Div = 265,
    Minus = 266,
    Mul = 267,
    EQL = 268,
    GEQ = 269,
    LEQ = 270,
    LSS = 271,
    GTR = 272,
    NEQ = 273,
    END = 274,
    LB = 275,
    RB = 276,
    LP = 277,
    RP = 278,
    MAIN = 279,
    SEMI = 280,
    COMMA = 281,
    CONST = 282,
    PROC = 283,
    IF = 284,
    ELSE = 285,
    READ = 286,
    WRITE = 287,
    FOR = 288,
    WHILE = 289,
    LMB = 290,
    RMB = 291,
    RETURN = 292
  };
#endif
/* Tokens.  */
#define num 258
#define var 259
#define CHAR 260
#define INT 261
#define VOID 262
#define STRING 263
#define Plus 264
#define Div 265
#define Minus 266
#define Mul 267
#define EQL 268
#define GEQ 269
#define LEQ 270
#define LSS 271
#define GTR 272
#define NEQ 273
#define END 274
#define LB 275
#define RB 276
#define LP 277
#define RP 278
#define MAIN 279
#define SEMI 280
#define COMMA 281
#define CONST 282
#define PROC 283
#define IF 284
#define ELSE 285
#define READ 286
#define WRITE 287
#define FOR 288
#define WHILE 289
#define LMB 290
#define RMB 291
#define RETURN 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 99 "pl0.y"

    int NUM;
    char* VAR;
    char* OP;

#line 301 "yacc.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   164

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

#define YYUNDEFTOK  2
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   117,   117,   123,   116,   136,   136,   136,   141,   154,
     161,   140,   167,   169,   170,   174,   176,   185,   198,   197,
     213,   218,   222,   221,   241,   244,   248,   251,   260,   272,
     273,   276,   277,   280,   289,   296,   305,   306,   309,   310,
     311,   312,   313,   314,   315,   316,   318,   320,   321,   324,
     339,   339,   350,   351,   353,   381,   399,   404,   402,   415,
     415,   419,   420,   438,   437,   446,   445,   455,   479,   501,
     505,   509,   513,   517,   521,   525,   528,   529,   533,   534,
     538,   543,   544,   548,   553,   572,   576,   577,   581,   580,
     596,   597,   599,   603,   608
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "num", "var", "CHAR", "INT", "VOID",
  "STRING", "Plus", "Div", "Minus", "Mul", "EQL", "GEQ", "LEQ", "LSS",
  "GTR", "NEQ", "END", "LB", "RB", "LP", "RP", "MAIN", "SEMI", "COMMA",
  "CONST", "PROC", "IF", "ELSE", "READ", "WRITE", "FOR", "WHILE", "LMB",
  "RMB", "RETURN", "$accept", "procstart", "$@1", "$@2", "var_t", "defunc",
  "$@3", "$@4", "$@5", "prevardecl", "prevardef", "block", "$@6",
  "declaration_list", "Vardecl", "$@7", "VarInit", "Vardef", "Constdecl",
  "CONSTInit", "constdef", "var_p", "statements", "statement",
  "asgnstm_semi", "asgnstm_tot", "get_sto", "returnstm", "$@8", "compstm",
  "asgnstm", "callstm", "forstm", "$@9", "for_1", "for_3", "ifstm", "$@10",
  "whilestm", "$@11", "readstm", "writestm", "condition", "expression",
  "term", "factor", "call_func", "$@12", "pass_factor", "get_table_addr",
  "get_code_addr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -144,    19,  -144,  -144,    76,  -144,  -144,  -144,    72,    55,
    -144,  -144,  -144,    65,  -144,    16,    67,    83,    73,  -144,
      76,    76,    77,    44,  -144,  -144,     3,    91,  -144,    93,
      84,    80,   105,    82,    83,    79,    89,   108,   108,    94,
      95,   102,  -144,     3,  -144,    96,  -144,    81,    97,  -144,
    -144,  -144,  -144,  -144,  -144,    85,    99,   100,    90,  -144,
      76,  -144,  -144,  -144,    71,     5,   104,   109,   108,  -144,
      69,  -144,  -144,    71,   108,  -144,   116,  -144,    91,   124,
     110,  -144,  -144,     5,   111,   101,  -144,    71,    71,   112,
      87,    42,  -144,  -144,  -144,  -144,   113,     5,  -144,    75,
     115,  -144,   107,    76,  -144,   114,    16,    30,   119,  -144,
      42,    42,  -144,    71,    71,     5,     5,     5,     5,     5,
       5,    71,    71,  -144,   121,  -144,  -144,  -144,  -144,   125,
    -144,    71,  -144,    42,    42,    75,    75,    75,    75,    75,
      75,  -144,  -144,     5,  -144,  -144,   122,   126,    26,  -144,
    -144,    76,    71,  -144,     3,  -144,  -144,  -144,    26,  -144,
    -144,   130,   127,  -144,  -144,   108,   128,   132,   108,  -144,
    -144,    26,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      94,     0,     2,     1,    12,     6,     5,     7,     0,     0,
       8,     3,    93,     0,    94,    21,     0,     0,     0,    18,
      24,    15,     0,     0,    31,     4,    37,     0,    20,     0,
       0,    13,     0,    30,     0,    34,     0,     0,     0,     0,
       0,     0,    19,    37,    38,     0,    45,     0,    49,    39,
      44,    40,    41,    42,    43,    27,     0,    25,    16,     9,
      15,    33,    29,    32,     0,     0,     0,     0,    60,    94,
       0,    36,    46,     0,     0,    47,     0,    22,     0,     0,
       0,    14,    85,     0,    84,     0,    87,     0,     0,     0,
      75,    78,    81,    67,    68,    59,     0,     0,    55,    54,
       0,    48,     0,    24,    26,     0,    21,     0,     0,    35,
      76,    77,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,     0,    51,    28,    23,    17,     0,
      86,    92,    63,    79,    80,    69,    74,    72,    71,    73,
      70,    83,    82,     0,    94,    10,    90,     0,    50,    94,
      65,    12,    92,    89,    37,    52,    64,    57,    50,    11,
      91,     0,     0,    66,    53,     0,    61,     0,     0,    49,
      62,    50,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,   -15,    -4,  -144,  -144,  -144,    98,
    -144,    47,  -144,  -144,    53,  -144,    86,  -144,   129,  -144,
     123,   -26,   -41,  -138,  -144,   -30,   -10,  -144,  -144,  -143,
    -139,  -144,  -144,  -144,  -144,    -8,  -144,  -144,  -144,  -144,
    -144,  -144,   -94,   -52,   -63,   -60,  -144,  -144,     9,  -144,
     -13
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     4,    13,     8,     9,    12,    80,   151,    30,
      31,    18,    26,    19,    28,   103,    56,    57,    20,    23,
      24,    84,    42,    43,    44,    45,    75,    46,    47,   156,
      48,    49,    50,   162,    96,   167,    51,   148,    52,   158,
      53,    54,    89,    90,    91,    92,    86,   108,   147,    14,
       2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    16,    71,   124,    85,    27,    29,    35,    82,    35,
     155,    66,    67,   100,    87,   163,    88,    41,    99,     3,
     155,   -30,   -30,   -30,   110,   111,   166,    83,   172,   166,
      35,   107,    36,   155,    37,    38,    39,    40,    95,   113,
     -50,   114,    41,    17,   101,    29,   154,   -56,    41,   149,
     133,   134,   121,   130,   122,    36,    97,    37,    38,    39,
      40,   141,   142,   135,   136,   137,   138,   139,   140,    33,
      34,   146,    82,    35,    82,    35,    10,    98,    87,    11,
      88,     5,     6,     7,   113,    15,   114,    22,    27,    21,
      32,    83,   146,    83,    25,    55,   113,    58,   114,   132,
     115,   116,   117,   118,   119,   120,    60,    59,    61,    17,
     143,    65,    35,   161,    64,    70,    68,    69,    73,   102,
      76,    72,    41,    74,    77,    79,    78,   105,    41,    93,
     106,   150,    41,   -88,    94,   112,   157,   109,   123,    41,
     125,   131,    41,   126,   144,    41,   145,   159,   152,   153,
     128,   164,   165,   129,   168,   169,   127,    63,    81,   171,
     170,   160,    62,     0,   104
};

static const yytype_int16 yycheck[] =
{
      26,    14,    43,    97,    64,    20,    21,     4,     3,     4,
     148,    37,    38,    73,     9,   158,    11,    43,    70,     0,
     158,     5,     6,     7,    87,    88,   165,    22,   171,   168,
       4,    83,    29,   171,    31,    32,    33,    34,    68,     9,
      37,    11,    68,    27,    74,    60,    20,    21,    74,   143,
     113,   114,    10,    23,    12,    29,    69,    31,    32,    33,
      34,   121,   122,   115,   116,   117,   118,   119,   120,    25,
      26,   131,     3,     4,     3,     4,     4,     8,     9,    24,
      11,     5,     6,     7,     9,    20,    11,     4,   103,    22,
      13,    22,   152,    22,    21,     4,     9,     4,    11,   112,
      13,    14,    15,    16,    17,    18,    26,    23,     3,    27,
     123,    22,     4,   154,    35,    13,    22,    22,    37,     3,
      35,    25,   148,    26,    25,    35,    26,     3,   154,    25,
      20,   144,   158,    22,    25,    23,   149,    36,    25,   165,
      25,    22,   168,    36,    23,   171,    21,   151,    26,    23,
      36,    21,    25,   106,    26,    23,   103,    34,    60,   169,
     168,   152,    33,    -1,    78
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    88,     0,    40,     5,     6,     7,    42,    43,
       4,    24,    44,    41,    87,    20,    88,    27,    49,    51,
      56,    22,     4,    57,    58,    21,    50,    42,    52,    42,
      47,    48,    13,    25,    26,     4,    29,    31,    32,    33,
      34,    59,    60,    61,    62,    63,    65,    66,    68,    69,
      70,    74,    76,    78,    79,     4,    54,    55,     4,    23,
      26,     3,    56,    58,    35,    22,    59,    59,    22,    22,
      13,    60,    25,    37,    26,    64,    35,    25,    26,    35,
      45,    47,     3,    22,    59,    83,    84,     9,    11,    80,
      81,    82,    83,    25,    25,    63,    72,    88,     8,    81,
      83,    63,     3,    53,    54,     3,    20,    81,    85,    36,
      82,    82,    23,     9,    11,    13,    14,    15,    16,    17,
      18,    10,    12,    25,    80,    25,    36,    52,    36,    49,
      23,    22,    88,    82,    82,    81,    81,    81,    81,    81,
      81,    83,    83,    88,    23,    21,    83,    86,    75,    80,
      88,    46,    26,    23,    20,    61,    67,    88,    77,    43,
      86,    60,    71,    67,    21,    25,    68,    73,    26,    23,
      73,    64,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    40,    41,    39,    42,    42,    42,    44,    45,
      46,    43,    43,    47,    47,    47,    48,    48,    50,    49,
      51,    51,    53,    52,    52,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    59,    59,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    63,    63,    64,
      66,    65,    67,    67,    68,    68,    69,    71,    70,    72,
      72,    73,    73,    75,    74,    77,    76,    78,    79,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    81,
      81,    82,    82,    82,    83,    83,    83,    83,    85,    84,
      86,    86,    86,    87,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     8,     1,     1,     1,     0,     0,
       0,    14,     0,     1,     3,     0,     2,     5,     0,     3,
       2,     0,     0,     5,     0,     1,     3,     1,     4,     4,
       0,     1,     3,     3,     1,     4,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     0,
       0,     4,     1,     3,     3,     3,     0,     0,    13,     1,
       0,     1,     3,     0,     7,     0,     8,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     2,     2,     1,     3,
       3,     1,     3,     3,     1,     1,     3,     1,     0,     5,
       1,     3,     0,     0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 117 "pl0.y"
    {
        preVar_cnt = 0;
        gen(jmp, 0, 0);
    }
#line 1604 "yacc.c"
    break;

  case 3:
#line 123 "pl0.y"
    {
        /* Main procedure */
        strcpy(id, "main");
        _enter(procedure, 0);
        table[tx].adr = cx;
        table[tx].t = xvoid;
        code[(yyvsp[-3].NUM)].a = cx;
        proctable[px] = tx;

    }
#line 1619 "yacc.c"
    break;

  case 5:
#line 136 "pl0.y"
           {(yyval.NUM) = 1;}
#line 1625 "yacc.c"
    break;

  case 6:
#line 136 "pl0.y"
                           {(yyval.NUM) = 2;}
#line 1631 "yacc.c"
    break;

  case 7:
#line 136 "pl0.y"
                                           {(yyval.NUM) = 3;}
#line 1637 "yacc.c"
    break;

  case 8:
#line 141 "pl0.y"
    {
        strcpy(id, (yyvsp[0].VAR));
        _enter(procedure, 0);
        if((yyvsp[-1].NUM) == 1){
            table[tx].t = xint;
        }else if((yyvsp[-1].NUM) == 2){
            table[tx].t = xchar;
        }else if((yyvsp[-1].NUM) == 3){
            table[tx].t = xvoid;
        }
        proc_p = tx;
    }
#line 1654 "yacc.c"
    break;

  case 9:
#line 154 "pl0.y"
    {
        table[(yyvsp[-4].NUM)].adr = (yyvsp[-3].NUM);
        table[(yyvsp[-4].NUM)].parameter_cnt = (yyvsp[-1].NUM);
        printf("pcnt = %d, table addr is %d\n", (yyvsp[-1].NUM), (yyvsp[-3].NUM));
        preVar_cnt = (yyvsp[-1].NUM);
    }
#line 1665 "yacc.c"
    break;

  case 10:
#line 161 "pl0.y"
    {
        preVar_cnt = 0;
        total_var = 0;
        proc_p = 0;
    }
#line 1675 "yacc.c"
    break;

  case 13:
#line 169 "pl0.y"
                      { (yyval.NUM) = (yyvsp[0].NUM) ; }
#line 1681 "yacc.c"
    break;

  case 14:
#line 171 "pl0.y"
    {
        (yyval.NUM) = (yyvsp[-2].NUM) + (yyvsp[0].NUM);
    }
#line 1689 "yacc.c"
    break;

  case 15:
#line 174 "pl0.y"
      { (yyval.NUM) = 0 ;}
#line 1695 "yacc.c"
    break;

  case 16:
#line 177 "pl0.y"
    {
        strcpy(id, (yyvsp[0].VAR));
        _enter(variable, 0);
        if((yyvsp[-1].NUM) == 1) table[tx].t = xint;
        else if((yyvsp[-1].NUM) == 2) table[tx].t = xchar;
        total_var ++;
        (yyval.NUM) = 1;
    }
#line 1708 "yacc.c"
    break;

  case 17:
#line 186 "pl0.y"
    {
        (yyval.NUM) = 1;
        strcpy(id, (yyvsp[-3].VAR));
        _enter(variable, (yyvsp[-1].NUM));
        if((yyvsp[-4].NUM) == 1) table[tx].t = xint;
        else if((yyvsp[-4].NUM) == 2) table[tx].t = xchar;
        total_var += (yyvsp[-1].NUM);
        (yyval.NUM) = 1;
    }
#line 1722 "yacc.c"
    break;

  case 18:
#line 198 "pl0.y"
    {
        setdx((yyvsp[0].NUM) + preVar_cnt);
        gen(ini, 0, total_var + 3);
        for(int i = 0; i < preVar_cnt; i++){
            gen(sto, -1 - i , 2 + preVar_cnt - i);
        }
        
    }
#line 1735 "yacc.c"
    break;

  case 19:
#line 207 "pl0.y"
    {
        gen(opr, preVar_cnt, 0);
    }
#line 1743 "yacc.c"
    break;

  case 20:
#line 214 "pl0.y"
    {
        printf("total_var: %d\n",total_var);
        (yyval.NUM) = (yyvsp[0].NUM);
    }
#line 1752 "yacc.c"
    break;

  case 21:
#line 218 "pl0.y"
     {(yyval.NUM) = 0 ;}
#line 1758 "yacc.c"
    break;

  case 22:
#line 222 "pl0.y"
     {
         if((yyvsp[-2].NUM) == 1){
         while(varx > 0){
             table[vartable[varx - 1]].t = xint;
             --varx;
         }
         }
         else{
             while(varx > 0){
                 table[vartable[varx - 1]].t = xchar;
                 --varx;
             }
         }
     }
#line 1777 "yacc.c"
    break;

  case 23:
#line 237 "pl0.y"
    {
        printf("2: %d, 5: %d\n", (yyvsp[-3].NUM), (yyvsp[0].NUM));
        (yyval.NUM) = (yyvsp[-3].NUM) + (yyvsp[0].NUM);
    }
#line 1786 "yacc.c"
    break;

  case 24:
#line 241 "pl0.y"
      {(yyval.NUM) = 0;}
#line 1792 "yacc.c"
    break;

  case 25:
#line 245 "pl0.y"
    { 
        (yyval.NUM) = (yyvsp[0].NUM);
    }
#line 1800 "yacc.c"
    break;

  case 26:
#line 248 "pl0.y"
                           {(yyval.NUM) = (yyvsp[-2].NUM) + (yyvsp[0].NUM);}
#line 1806 "yacc.c"
    break;

  case 27:
#line 252 "pl0.y"
    {
        ++total_var;
        strcpy(id, (yyvsp[0].VAR));
        _enter(variable, 0);
        (yyval.NUM) = 1;
        vartable[varx] = tx;
        ++varx;
    }
#line 1819 "yacc.c"
    break;

  case 28:
#line 261 "pl0.y"
    {
        total_var += (yyvsp[-1].NUM);
        strcpy(id, (yyvsp[-3].VAR));
        _enter(variable, (yyvsp[-1].NUM));
        (yyval.NUM) = 1;

        vartable[varx] = tx;
        ++varx;
    }
#line 1833 "yacc.c"
    break;

  case 33:
#line 281 "pl0.y"
    {
        strcpy(id, (yyvsp[-2].VAR));
        c_num = (yyvsp[0].NUM);
        _enter(constant, 0);
    }
#line 1843 "yacc.c"
    break;

  case 34:
#line 290 "pl0.y"
    {
        isString = 0;
        (yyval.NUM) = position((yyvsp[0].VAR));
        if(table[(yyval.NUM)].t == xchar) isString = 1;

    }
#line 1854 "yacc.c"
    break;

  case 35:
#line 297 "pl0.y"
    {
        isString = 0;
        (yyval.NUM) = position((yyvsp[-3].VAR));
        gen(lit, 0, table[(yyval.NUM)].adr);
        gen(lit, 0, lev - table[(yyval.NUM)].level);
    }
#line 1865 "yacc.c"
    break;

  case 49:
#line 324 "pl0.y"
    {
        while(forx > 0)
        {
            if(table[fortable[forx - 1]].is_arry){
                gen(sto, 0, 0);
                --forx;
            }else{
                gen(sto, lev - table[fortable[forx - 1]].level, table[fortable[forx - 1]].adr );
                --forx;
            }
        }
    }
#line 1882 "yacc.c"
    break;

  case 50:
#line 339 "pl0.y"
    {
        if(table[proc_p].t == xvoid) yyerror("error void cannot return\n");
    }
#line 1890 "yacc.c"
    break;

  case 51:
#line 344 "pl0.y"
    {
        gen(sto, -1, 0);
        gen(opr, preVar_cnt, 0);
        --px;
    }
#line 1900 "yacc.c"
    break;

  case 54:
#line 355 "pl0.y"
    {
        /*
        if($1 == 0){
            yyerror("Symbol not Exist\n");
        }
        else{
            if(table[$1].kind != variable) yyerror("Symbol not variable\n");
            else{
                if(table[$1].is_arry == 0) {gen(sto, lev - table[$1].level, table[$1].adr);}
                else{
                    gen(sto, 0, 0);
                }
            }
        }
        */
        if((yyvsp[-2].NUM) == 0){
            yyerror("Symbol not Exist\n");
        }
        else{
            if(table[(yyvsp[-2].NUM)].kind != variable) yyerror("Symbol not variable\n");
            else{
                fortable[forx] = (yyvsp[-2].NUM);
                ++forx;
            }
        }
    }
#line 1931 "yacc.c"
    break;

  case 55:
#line 382 "pl0.y"
    {
        printf("-----------qweqwcasdasdasd---------------\n");
        strcpy(temstr, (yyvsp[0].VAR));
        if(isString)
        {
            int teml = table[(yyvsp[-2].NUM)].is_arry;
            for(int i = 0; i < teml; i++){
                gen(lit, 0 , i);
                gen(lit, 0, table[(yyvsp[-2].NUM)].adr);
                gen(lit, 0, lev - table[(yyvsp[-2].NUM)].level);
                gen(lit, 0, temstr[i]);
                fortable[forx] = (yyvsp[-2].NUM);
                ++forx;
            }
        }
    }
#line 1952 "yacc.c"
    break;

  case 57:
#line 404 "pl0.y"
    {
        gen(jpc, 0, 0);
    }
#line 1960 "yacc.c"
    break;

  case 58:
#line 409 "pl0.y"
    {
        gen(jmp, 0, (yyvsp[-8].NUM));
        printf("jpc = %d\n", (yyvsp[-6].NUM));
        code[(yyvsp[-6].NUM)].a = cx;
    }
#line 1970 "yacc.c"
    break;

  case 63:
#line 438 "pl0.y"
    {
        gen(jpc,0,0);
    }
#line 1978 "yacc.c"
    break;

  case 64:
#line 442 "pl0.y"
    {code[(yyvsp[-2].NUM)].a = cx;}
#line 1984 "yacc.c"
    break;

  case 65:
#line 446 "pl0.y"
    {
        gen(jpc, 0, 0);
    }
#line 1992 "yacc.c"
    break;

  case 66:
#line 450 "pl0.y"
    {
        gen(jmp, 0, (yyvsp[-5].NUM));
       code[(yyvsp[-2].NUM)].a = cx;
    }
#line 2001 "yacc.c"
    break;

  case 67:
#line 456 "pl0.y"
    {
        if(table[(yyvsp[-1].NUM)].is_arry == 0){
            gen(opr, 0, 16);
            gen(sto, lev - table[(yyvsp[-1].NUM)].level, table[(yyvsp[-1].NUM)].adr);
        }else {
            if(isString == 0) {
                gen(opr, 0, 16);
                gen(sto, 0, 0);
            }
            else{
                gen(opr, table[(yyvsp[-1].NUM)].is_arry, 16);
                printf("is_arry = %d \n" , table[(yyvsp[-1].NUM)].is_arry);
                for(int i = 0; i < table[(yyvsp[-1].NUM)].is_arry; i++)
                {
                    gen(lit, 0, i);
                    gen(lit, 0, table[(yyvsp[-1].NUM)].adr);
                    gen(lit, 0, lev - table[(yyvsp[-1].NUM)].level);
                    gen(sto, table[(yyvsp[-1].NUM)].is_arry, 0);
                }
            }
        }
    }
#line 2028 "yacc.c"
    break;

  case 68:
#line 480 "pl0.y"
    {
        if(table[(yyvsp[-1].NUM)].is_arry == 0){
            gen(lod, lev - table[(yyvsp[-1].NUM)].level,table[(yyvsp[-1].NUM)].adr);
            gen(opr, 0, 14);   
            gen(opr, 0, 15);
        }else{
            if(isString == 0){
                gen(lod, 0, 0);
                gen(opr, -1, 14);   
                gen(opr, 0, 15);
            }else{
                int str_l = 0;
                for(int i =0; i < table[(yyvsp[-1].NUM)].is_arry; i++){
                    gen(lod, lev - table[(yyvsp[-1].NUM)].level, table[(yyvsp[-1].NUM)].adr + i);
                }
                gen(opr, table[(yyvsp[-1].NUM)].is_arry, 14);
            }
        }
    }
#line 2052 "yacc.c"
    break;

  case 69:
#line 502 "pl0.y"
            {
                gen(opr, 0, 8);
            }
#line 2060 "yacc.c"
    break;

  case 70:
#line 506 "pl0.y"
            {
                gen(opr, 0, 9);
            }
#line 2068 "yacc.c"
    break;

  case 71:
#line 510 "pl0.y"
            {
                gen(opr, 0, 10);
            }
#line 2076 "yacc.c"
    break;

  case 72:
#line 514 "pl0.y"
            {
                gen(opr, 0, 13);
            }
#line 2084 "yacc.c"
    break;

  case 73:
#line 518 "pl0.y"
            {
                gen(opr, 0, 12);
            }
#line 2092 "yacc.c"
    break;

  case 74:
#line 522 "pl0.y"
            {
                gen(opr, 0, 11);
            }
#line 2100 "yacc.c"
    break;

  case 77:
#line 530 "pl0.y"
    {
        gen(opr, 0, 1);
    }
#line 2108 "yacc.c"
    break;

  case 79:
#line 535 "pl0.y"
    {
        gen(opr, 0, 2);
    }
#line 2116 "yacc.c"
    break;

  case 80:
#line 539 "pl0.y"
    {
        gen(opr, 0, 3);
    }
#line 2124 "yacc.c"
    break;

  case 82:
#line 545 "pl0.y"
    {
        gen(opr, 0, 4);
    }
#line 2132 "yacc.c"
    break;

  case 83:
#line 549 "pl0.y"
    {
        gen(opr, 0 , 5);
    }
#line 2140 "yacc.c"
    break;

  case 84:
#line 554 "pl0.y"
    {
        if((yyvsp[0].NUM) == 0) yyerror("Symbol not found \n");
        else{
            if(table[(yyvsp[0].NUM)].kind == procedure) yyerror("procedure can not be variable\n");
            else{
                if(table[(yyvsp[0].NUM)].kind == constant) gen(lit, 0, table[(yyvsp[0].NUM)].val);
                else{
                    if(table[(yyvsp[0].NUM)].is_arry){
                        printf("$1 is :%d, \n", (yyvsp[0].NUM));
                        gen(lod, 0, 0);
                    }else{
                        printf("name %s, adr %d", table[(yyvsp[0].NUM)].name, table[(yyvsp[0].NUM)].adr);
                        gen(lod, lev - table[(yyvsp[0].NUM)].level, table[(yyvsp[0].NUM)].adr);
                    }
                }
            }
        }
    }
#line 2163 "yacc.c"
    break;

  case 85:
#line 573 "pl0.y"
    {
        gen(lit, 0, (yyvsp[0].NUM));
    }
#line 2171 "yacc.c"
    break;

  case 88:
#line 581 "pl0.y"
    {
        ++px;
        proctable[px] = (yyvsp[0].NUM);
    }
#line 2180 "yacc.c"
    break;

  case 89:
#line 586 "pl0.y"
    {
        if(table[(yyvsp[-4].NUM)].kind != procedure) yyerror("Is  not a procedure \n");
        else{
            if((yyvsp[-1].NUM) !=  table[(yyvsp[-4].NUM)].parameter_cnt ) yyerror("parameter number not match\n");
            gen(cal, 0, table[(yyvsp[-4].NUM)].adr);
            if(table[(yyvsp[-4].NUM)].t != xvoid) gen(lod, -1, 0); /* get return */
        }
    }
#line 2193 "yacc.c"
    break;

  case 90:
#line 596 "pl0.y"
                    {(yyval.NUM) = 1;}
#line 2199 "yacc.c"
    break;

  case 91:
#line 598 "pl0.y"
        {(yyval.NUM) = 1 + (yyvsp[0].NUM);}
#line 2205 "yacc.c"
    break;

  case 92:
#line 599 "pl0.y"
      {(yyval.NUM) = 0;}
#line 2211 "yacc.c"
    break;

  case 93:
#line 603 "pl0.y"
    {
        (yyval.NUM) = tx;
    }
#line 2219 "yacc.c"
    break;

  case 94:
#line 608 "pl0.y"
    {
        (yyval.NUM) = cx;
    }
#line 2227 "yacc.c"
    break;


#line 2231 "yacc.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 612 "pl0.y"


yyerror(const char* s){
    printf("error!:%s\n, located at %d line\n", s, line);
}
void init()
{
	tx = 0;
	cx = 0;
	px = 0;
    forx = 0;
    varx = 0;
  lev = 0;   
  proctable[0] = 0;
  c_num = 0;
  err = 0;
  total_var = 0;

  offset = 0;
}
int position(char* a)
{
    int i;
    strcpy(table[0].name, a);
    i = tx;
    while(strcmp(table[i].name, a) != 0) --i;
    return i;
}

void _enter(enum object k, int IsArry)
{
    enter(k);
    table[tx].is_arry = IsArry;
}
void enter(enum object k)
{
	tx = tx + 1;
	strcpy(table[tx].name, id);
	table[tx].kind = k;
	switch (k)
	{
		case constant:	/* 常量 */			
			table[tx].val = c_num; /* 登记常数的值 */
			break;
		case variable:	/* 变量 */
			table[tx].level = lev;	
			break;
		case procedure:	/* 过程 */
			table[tx].level = lev;
			break;
	}
}
void setdx(int n)
{
    printf("---------------%d\n", n);
    int addr = 3 + total_var;
    for(int i = 1; i <= n; i++){
        if(table[tx - i + 1].is_arry){
            addr -= table[tx - i + 1].is_arry;
        }else{
            addr -= 1;
        }
        table[tx - i + 1].adr = addr;
    }
}

void gen(enum fct x, int y, int z)
{
	if (cx >= cxmax)
	{
		printf("Program is too long!\n");	/* 生成的虚拟机代码程序过长 */
		exit(1);
	}
	if ( z >= amax)
	{
		printf("Displacement address is too big!\n");	/* 地址偏移越界 */
		exit(1);
	}
	code[cx].f = x;
	code[cx].l = y;
	code[cx].a = z;
	cx++;
}
void listall()
{
	int i;
	char name[][5]=
	{
		{"lit"},{"opr"},{"lod"},{"sto"},{"cal"},{"int"},{"jmp"},{"jpc"},
	};
	
    for (i = 0; i < cx; i++)
    {
        printf("%d %s %d %d\n", i, name[code[i].f], code[i].l, code[i].a);
        /* fprintf(fcode,"%d %s %d %d\n", i, name[code[i].f], code[i].l, code[i].a);
        */
        
    }
}

void displaytable()
{
	int i;
    /* 输出符号表 */
	printf("tx : %d\n", tx);
	for (i = 1; i <= tx; i++)
		{
            printf("kind : %d\n", table[i].kind);         
			switch (table[i].kind)
			{
				case constant:
					printf("    %d const %s ", i, table[i].name);
					printf("val=%d\n", table[i].val);
					/* fprintf(ftable, "    %d const %s ", i, table[i].name);
					fprintf(ftable, "val=%d\n", table[i].val); */
					break;
				case variable:
					printf("    %d var   %s ", i, table[i].name);
					printf("lev=%d addr=%d ", table[i].level, table[i].adr);
                    if(table[i].t == xint) printf("type = int \n");
                    else printf("type = char \n");
					/* fprintf(ftable, "    %d var   %s ", i, table[i].name);
					fprintf(ftable, "lev=%d addr=%d\n", table[i].level, table[i].adr);
                    */
					break;
				case procedure:
					printf("    %d proc  %s ", i, table[i].name);
					printf("lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
                    /*
					fprintf(ftable,"    %d proc  %s ", i, table[i].name);
					fprintf(ftable,"lev=%d addr=%d size=%d\n", table[i].level, table[i].adr, table[i].size);
                    */
					break;
			}
		}
		printf("\n");
		/* fprintf(ftable, "\n"); */
}
void interpret()
{
	int p = 0; /* 指令指针 */
	int b = 1; /* 指令基址 */
	int t = 0; /* 栈顶指针 */
	struct instruction i;	/* 存放当前指令 */
	int s[stacksize];	/* 栈 */

	printf("Start pl0\n");
	/* fprintf(fresult,"Start pl0\n"); */
	s[0] = 0; /* s[0]不用 */
	s[1] = 0; /* 主程序的三个联系单元均置为0 */
	s[2] = 0;
	s[3] = 0;

	do {
	    i = code[p];	/* 读当前指令 */
		p = p + 1;
		switch (i.f)
		{
			case lit:	/* 将常量a的值取到栈顶 */
				t = t + 1;
				s[t] = i.a;				
				break;
			case opr:	/* 数学、逻辑运算 */
				switch (i.a)
				{
					case 0:  /* 函数调用结束后返回 */
                        t = b - 1;
                        p = s[t + 3];
                        b = s[t + 2];
                        t -= i.l;
                        printf("return to t: %d p: %d b: %d \n *******\n", t, p, b);
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
                        if(i.l == 0){
                            printf("%d", s[t]);
                            /* fprintf(fresult, "%d", s[t]); */
                            t = t - 1;
                        }else if(i.l > 0){
                            memset(buffer, 0, sizeof(buffer));
                            for(int ii = 0; ii < i.l; ii++){
                                printf("t is %d s[t]: %d \n", t ,s[t]);
                                buffer[i.l - ii - 1] = s[t];
                                t = t - 1;
                            }
                            printf("here output %s", buffer);
                        }else if(i.l == -1){
                            char c = s[t];
                            t = t - 1;
                            printf("%c", c);
                        }
						break;
					case 15:/* 输出换行符 */
						printf("\n");
					    /* fprintf(fresult,"\n"); */
						break;
					case 16:/* 读入一个输入置于栈顶 */
                        if(i.l == 0){
                            t = t + 1;
                            printf("?");
                            /* fprintf(fresult, "?"); */
                            scanf("%d", &(s[t]));
                            /* fprintf(fresult, "%d\n", s[t]); */						
                        }else{
                            printf("? (need a string)");
                            scanf("%s", &buffer);
                            int buffer_len = strlen(buffer);

                            printf("i.l %d, t %d \n", i.l, t);
                            for(int cnt_i = 0; cnt_i < i.l; cnt_i++){
                                printf("t %d, buffer %d \n", t, buffer[cnt_i]);
                                t = t + 1;
                                s[t] = buffer[cnt_i];
                            }
                        }

						break;

				}
				break;
			case lod:	/* 取相对当前过程的数据基地址为a的内存的值到栈顶 */
                if(i.l < 0){
                    t = t + 1;
                    s[t] = s[0];
                }
                else if(i.l == 0 && i.a == 0){
                    s[t - 2] = s[base(s[t],s, b) + s[t - 1] + s[t - 2]];
                    t = t - 2;
                }else if(i.l >0 && i.a > 0){
                    t = t + 1;
                    s[t] = s[base(i.l, s, b) + i.a];
                }else{
				    t = t + 1;
				    s[t] = s[base(i.l,s,b) + i.a];				
                }
                    printf("t is %d,lod at : %d  + %d ,%d \n",t ,base(i.l, s, b), i.a, s[base(i.l, s,b) + i.a]);
				break;
			case sto:	/* 栈顶的值存到相对当前过程的数据基地址为a的内存 */
                if(i.l < 0 && i.a != 0){
                    s[b + i.a] = s[b + i.l];   
                    printf("wa!!\n");
                    printf("i.l = %d, i.a = %d\n", i.l, i.a);
                }else if(i.l < 0 && i.a == 0){
                    s[0] = s[t];
                    printf("s[0] is %d \n", s[0]);
                }else if(i.l == 0 && i.a == 0){
                    s[base(s[t - 1], s, b) + s[t - 2] + s[t - 3]] = s[t];
                    t = t - 4;
                }else if(i.l > 0 && i.a == 0){
                    s[base(s[t], s, b) + s[t - 1] + s[t - 2]] = s[t - 2 - i.l + s[t - 2]];
                    printf("t is %d,sto at : %d,  %d , %d \n",
                            t,
                            base(s[t], s, b) + s[t - 1] + s[t - 2],
                            s[t - 2],
                            s[t - 2 - i.l + s[t - 2]]);
                    t = t - 3;
                }else{
				    s[base(i.l, s, b) + i.a] = s[t];
				    t = t - 1;
                }
                    /* printf("t is %d,sto at : %d  + %d , %d \n",t ,base(i.l, s, b), i.a, s[b  + i.a]); */
				break;
			case cal:	/* 调用子过程 */
                printf("now call , t at %d\n", t);
				s[t + 1] = base(i.l, s, b);	/* 将父过程基地址入栈，即建立静态链 */
				s[t + 2] = b;	/* 将本过程基地址入栈，即建立动态链 */
				s[t + 3] = p;	/* 将当前指令指针入栈，即保存返回地址 */
				b = t + 1;	/* 改变基地址指针值为新过程的基地址 */
				p = i.a;	/* 跳转 */
                printf("t: %d p: %d b: %d \n *******\n", t, p, b);
				break;
			case ini:	/* 在数据栈中为被调用的过程开辟a个单元的数据区 */
				t = t + i.a;	
                printf("ini t is %d\n", t);
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
	printf("End pl0\n");
	/*fprintf(fresult,"End pl0\n");*/
}
int base(int l, int* s, int b)
{
    int bl;
    bl = b;
    while(l > 0){
        bl = s[bl];
        l--;
    }
    return bl;
}

int main(){
    printf("Input file        ");
    scanf("%s", fname);
    if((fin = fopen(fname, "r")) == NULL)
    {
        printf("open file error!\n");
        exit(1);
    }
    /* if ((foutput = fopen("foutput.txt", "w")) == NULL)
    {
		printf("Can't open the output file!\n");
		exit(1);
	}
	if ((ftable = fopen("ftable.txt", "w")) == NULL)
	{
		printf("Can't open ftable.txt file!\n");
		exit(1);
	}
    */
    redirectInput(fin);
    init();

    yyparse();
    displaytable();
    listall();
    interpret();
    fclose(fin);
    /* fclose(ftable);
    fclose(foutput);
    */
    return 0;
}
