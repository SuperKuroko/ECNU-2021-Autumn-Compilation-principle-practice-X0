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
    LP = 268,
    RP = 269,
    LB = 270,
    RB = 271,
    LSB = 272,
    RSB = 273,
    MAIN = 274,
    SEMI = 275,
    IF = 276,
    ELSE = 277,
    READ = 278,
    WRITE = 279,
    WHILE = 280,
    BECOMES = 281,
    NUMBER = 282,
    IDENT = 283,
    CHAR = 284,
    INT = 285
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
#define LP 268
#define RP 269
#define LB 270
#define RB 271
#define LSB 272
#define RSB 273
#define MAIN 274
#define SEMI 275
#define IF 276
#define ELSE 277
#define READ 278
#define WRITE 279
#define WHILE 280
#define BECOMES 281
#define NUMBER 282
#define IDENT 283
#define CHAR 284
#define INT 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 82 "X0.y"

    int number;
    char* ident;

#line 122 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
