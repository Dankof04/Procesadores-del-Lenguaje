/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    ID = 259,                      /* ID  */
    IMPRIMIR = 260,                /* IMPRIMIR  */
    SI = 261,                      /* SI  */
    SINO = 262,                    /* SINO  */
    MIENTRAS = 263,                /* MIENTRAS  */
    HACER = 264,                   /* HACER  */
    PUNTO_COMA = 265,              /* PUNTO_COMA  */
    PAREN_IZQ = 266,               /* PAREN_IZQ  */
    PAREN_DER = 267,               /* PAREN_DER  */
    LLAVE_IZQ = 268,               /* LLAVE_IZQ  */
    LLAVE_DER = 269,               /* LLAVE_DER  */
    IGUAL = 270,                   /* IGUAL  */
    MAS_IGUAL = 271,               /* MAS_IGUAL  */
    MENOS_IGUAL = 272,             /* MENOS_IGUAL  */
    MULT_IGUAL = 273,              /* MULT_IGUAL  */
    DIV_IGUAL = 274,               /* DIV_IGUAL  */
    SUMA = 275,                    /* SUMA  */
    RESTA = 276,                   /* RESTA  */
    MULT = 277,                    /* MULT  */
    DIV = 278                      /* DIV  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM 258
#define ID 259
#define IMPRIMIR 260
#define SI 261
#define SINO 262
#define MIENTRAS 263
#define HACER 264
#define PUNTO_COMA 265
#define PAREN_IZQ 266
#define PAREN_DER 267
#define LLAVE_IZQ 268
#define LLAVE_DER 269
#define IGUAL 270
#define MAS_IGUAL 271
#define MENOS_IGUAL 272
#define MULT_IGUAL 273
#define DIV_IGUAL 274
#define SUMA 275
#define RESTA 276
#define MULT 277
#define DIV 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "parser.y"

    char *str;

#line 117 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
