/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    SEMI_t = 280,
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
#define SEMI_t 280
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
#line 30 "pl0.y"

    int NUM;
    char* VAR;
    char* OP;

#line 137 "yacc.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_H_INCLUDED  */
