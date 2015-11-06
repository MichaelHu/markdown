/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TEXT = 258,
     SPECIALCHAR = 259,
     CODETEXT = 260,
     INDENT = 261,
     H = 262,
     QUOTEH = 263,
     HTMLBLOCK = 264,
     SECTION = 265,
     VSECTION = 266,
     SCRIPTSTART = 267,
     SCRIPTEND = 268,
     STYLESTART = 269,
     STYLEEND = 270,
     LINK = 271,
     EXCLAMATION = 272,
     MINUS = 273,
     PLUS = 274,
     RIGHTPARENTHESES = 275,
     LEFTPARENTHESES = 276,
     RIGHTSQUARE = 277,
     LEFTSQUARE = 278,
     UNDERSCORE = 279,
     STAR = 280,
     BACKTICK = 281,
     BLANKLINE = 282,
     LINEBREAK = 283,
     LARGERTHAN = 284,
     DOUBLESTAR = 285,
     DOUBLEUNDERSCORE = 286,
     OLSTART = 287,
     ULSTART = 288,
     DOUBLEBACKTICK = 289,
     QUOTEBLANKLINE = 290,
     QUOTEOLSTART = 291,
     QUOTEULSTART = 292,
     STARX = 293
   };
#endif
/* Tokens.  */
#define TEXT 258
#define SPECIALCHAR 259
#define CODETEXT 260
#define INDENT 261
#define H 262
#define QUOTEH 263
#define HTMLBLOCK 264
#define SECTION 265
#define VSECTION 266
#define SCRIPTSTART 267
#define SCRIPTEND 268
#define STYLESTART 269
#define STYLEEND 270
#define LINK 271
#define EXCLAMATION 272
#define MINUS 273
#define PLUS 274
#define RIGHTPARENTHESES 275
#define LEFTPARENTHESES 276
#define RIGHTSQUARE 277
#define LEFTSQUARE 278
#define UNDERSCORE 279
#define STAR 280
#define BACKTICK 281
#define BLANKLINE 282
#define LINEBREAK 283
#define LARGERTHAN 284
#define DOUBLESTAR 285
#define DOUBLEUNDERSCORE 286
#define OLSTART 287
#define ULSTART 288
#define DOUBLEBACKTICK 289
#define QUOTEBLANKLINE 290
#define QUOTEOLSTART 291
#define QUOTEULSTART 292
#define STARX 293




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "markdown.y"
{
    char *text;
    t_blocknode *node;
}
/* Line 1529 of yacc.c.  */
#line 130 "markdown.y.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;
