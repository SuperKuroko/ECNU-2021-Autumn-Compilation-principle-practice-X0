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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PLUS = 258,
    DIV = 259,
    MINUS = 260,
    MUL = 261,
    EQL = 262,
    GEQ = 263,
    LEQ = 264,
    LSS = 265,
    GTR = 266,
    NEQ = 267,
    CHAR = 268,
    INT = 269,
    BOOL = 270,
    PER = 271,
    XOR = 272,
    OR = 273,
    AND = 274,
    NOT = 275,
    ODD = 276,
    LP = 277,
    RP = 278,
    LB = 279,
    RB = 280,
    LSB = 281,
    RSB = 282,
    MAIN = 283,
    SEMI = 284,
    IF = 285,
    ELSE = 286,
    READ = 287,
    WRITE = 288,
    WHILE = 289,
    BECOMES = 290,
    TRUE = 291,
    FALSE = 292,
    FOR = 293,
    NUMBER = 294,
    IDENT = 295
  };
#endif
/* Tokens.  */
#define PLUS 258
#define DIV 259
#define MINUS 260
#define MUL 261
#define EQL 262
#define GEQ 263
#define LEQ 264
#define LSS 265
#define GTR 266
#define NEQ 267
#define CHAR 268
#define INT 269
#define BOOL 270
#define PER 271
#define XOR 272
#define OR 273
#define AND 274
#define NOT 275
#define ODD 276
#define LP 277
#define RP 278
#define LB 279
#define RB 280
#define LSB 281
#define RSB 282
#define MAIN 283
#define SEMI 284
#define IF 285
#define ELSE 286
#define READ 287
#define WRITE 288
#define WHILE 289
#define BECOMES 290
#define TRUE 291
#define FALSE 292
#define FOR 293
#define NUMBER 294
#define IDENT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 86 "X0.y"

    int number;
    char* ident;

#line 142 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
