%{

#include <string.h>
#include "blocknode.h"
#include "markdown.y.h"

#undef _ISDEBUGLEX

#ifdef _ISDEBUGLEX
#define P(token) printf("token: %s\n", token); BeginToken(yytext);
#else
#define P(token) BeginToken(yytext);
#endif

#define YY_INPUT(buf,result,max_size)  { \
    result = GetNextChar(buf, max_size); \
    if (  result <= 0  ) \
      result = YY_NULL; \
}

/* prototypes */
int yylineno;

/* input.c */
int GetNextChar(char *b, int maxBuffer);
void BeginToken(char *t);;

%}

%x ESCAPE CODEBLOCK CODESPAN XCODESPAN 
%x INDENTLIST SHTMLBLOCK SCRIPTBLOCK STYLEBLOCK

    /* blankline ^[ ]{0,4}\r?\n */
blankline ^[ \t]*\r?\n
quoteblankline ^>[ ]{0,4}\r?\n

%%

    /* special chars: "\[]^-?.*+|()$/{}%<> */

{blankline}                             { yylineno++; P("BLANKLINE"); return BLANKLINE; }
    /* !!! note: quoteblankline has no effect */
^>\r?\n                                    { yylineno++; P("QUOTEBLANKLINE"); return QUOTEBLANKLINE; }
^>" "\r?\n                                 { yylineno++; P("QUOTEBLANKLINE"); return QUOTEBLANKLINE; }
^>"  "\r?\n                                { yylineno++; P("QUOTEBLANKLINE"); return QUOTEBLANKLINE; }
^>"   "\r?\n                               { yylineno++; P("QUOTEBLANKLINE"); return QUOTEBLANKLINE; }
^>"    "\r?\n                              { yylineno++; P("QUOTEBLANKLINE"); return QUOTEBLANKLINE; }

^>                                      { P("LARGERTHAN"); return LARGERTHAN; }

^@s.*                                   { P("SECTION"); 
                                            yylval.text = strdup(yytext);
                                            return SECTION; }
^@vs.*                                  { P("VSECTION"); 
                                            yylval.text = strdup(yytext);
                                            return VSECTION; }


\\                                      { P("ESCAPE"); BEGIN ESCAPE; }
<ESCAPE>[\\`*_{}()#+\-.!]               { BEGIN INITIAL; yylval.text = strdup(yytext); P("SPECIALCHAR"); return SPECIALCHAR; }
<ESCAPE>.                               { BEGIN INITIAL; yylval.text = strdup(yytext); P("SPECIALCHAR"); return SPECIALCHAR; }

"`"                                     { P("BACKTICK"); BEGIN CODESPAN; return BACKTICK; }
<CODESPAN>\\`                           { P("SPECIALCHAR"); 
                                            yylval.text = strdup("`"); return SPECIALCHAR; }
<CODESPAN>[^`\\\r\n]+                   { P("CODETEXT"); yylval.text = strdup(yytext); return CODETEXT; }
<CODESPAN>\r?\n|\\                      { P("CODETEXT"); yylval.text = strdup(yytext); 
                                            yylineno++; return CODETEXT; }
<CODESPAN>`                             { P("BACKTICK"); BEGIN INITIAL; return BACKTICK; }

"``"                                    { P("DOUBLEBACKTICK"); BEGIN XCODESPAN; return DOUBLEBACKTICK; }
<XCODESPAN>.                            { P("CODETEXT"); yylval.text = strdup(yytext); return CODETEXT; }
<XCODESPAN>\r?\n                        { P("CODETEXT"); yylval.text = strdup(yytext);
                                            yylineno++; return CODETEXT; }
<XCODESPAN>``                           { P("DOUBLEBACKTICK"); BEGIN INITIAL; return DOUBLEBACKTICK; }



^" "{0,3}[*+-][ ]+                      { P("ULSTART"); return ULSTART; }
^>" "+[*+-][ ]+                         { P("QUOTEULSTART"); return QUOTEULSTART; }
^" "{0,3}[1-9][0-9]*\.[ ]+              { P("OLSTART"); return OLSTART; }
^>" "+[1-9][0-9]*\.[ ]+                 { P("QUOTEOLSTART"); return QUOTEOLSTART; }



^(\t|[ ]{4})+/[ ]{0,3}[*+][ ]+            { 
                                            /* indent ul list */
                                            if(is_in_list(indent_level(yytext))){
                                                BEGIN INDENTLIST;
                                                yylval.text = strdup(yytext);
                                                P("INDENT"); return INDENT; 
                                            }
                                            else{
                                                BEGIN CODEBLOCK; 
                                                yylval.text = strdup(yytext);
                                                P("INDENT"); return INDENT;
                                            }
                                        }   
^(\t|[ ]{4})+/[ ]{0,3}[1-9][0-9]*\.[ ]+ { 
                                            /* indent ol list */
                                            if(is_in_list(indent_level(yytext))){
                                                BEGIN INDENTLIST;
                                                yylval.text = strdup(yytext);
                                                P("INDENT"); return INDENT; 
                                            }
                                            else{
                                                BEGIN CODEBLOCK; 
                                                yylval.text = strdup(yytext);
                                                P("INDENT"); return INDENT;
                                            }
                                        }   
^(\t|[ ]{4})+/.                         { 
                                            /* indent p */
                                            if(is_in_list(indent_level(yytext))){
                                                yylval.text = strdup(yytext);
                                                P("INDENT"); return INDENT; 
                                            }
                                            else{
                                                BEGIN CODEBLOCK; 
                                                yylval.text = strdup(yytext);
                                                P("INDENT"); return INDENT;
                                            }
                                        }
<CODEBLOCK>.+                           { yylval.text = strdup(yytext); P("CODETEXT"); return CODETEXT; }
<CODEBLOCK>\r?\n                        { P(""); BEGIN INITIAL; yylineno++; }

<INDENTLIST>[ ]{0,3}[*+][ ]+            { BEGIN INITIAL; P("ULSTART"); return ULSTART; }
<INDENTLIST>[ ]{0,3}[1-9][0-9]*\.[ ]+   { BEGIN INITIAL; P("OLSTART"); return OLSTART; }


^#{1,6}                       { yylval.text = strdup(yytext); P("H"); return H; }
^>" "+#{1,6}                  { yylval.text = strdup(yytext); P("QUOTEH"); return QUOTEH; }

    /* block and functional html tags must be in one line and must start at first column */
^\<\/?(div|p|table|tbody|tr|td|th|h[1-6]|dl|dt|dd|iframe|form|hr|section|header|footer|ul|ol|li|aside|canvas|center)[^>]*\>   { 
                                            yylval.text = strdup(yytext); 
                                            P("HTMLBLOCK"); 
                                            BEGIN SHTMLBLOCK; 
                                            return HTMLBLOCK; 
                                        }
<SHTMLBLOCK>.+          { yylval.text = strdup(yytext); P("TEXT"); return TEXT; }
<SHTMLBLOCK>\r?\n       { yylineno++; P("LINEBREAK"); BEGIN INITIAL;  return LINEBREAK; }



    /* script block */
^\<script[^>]*>/(.|[\r\n])*\<\/script>  {
                                            yylval.text = strdup(yytext); 
                                            P("SCRIPTSTART"); 
                                            BEGIN SCRIPTBLOCK; 
                                            return SCRIPTSTART; 
                                        }
<SCRIPTBLOCK>.                          { yylval.text = strdup(yytext); P("TEXT"); return TEXT; }
<SCRIPTBLOCK>\r?\n                      { 
                                            yylineno++; 
                                            yylval.text = strdup(yytext); 
                                            P("TEXT"); 
                                            return TEXT; 
                                        }
<SCRIPTBLOCK>\<\/script>.*\r?\n         { 
                                            yylval.text = "</script>"; 
                                            P("SCRIPTEND"); 
                                            BEGIN INITIAL; 
                                            return SCRIPTEND;
                                        }





    /* style block */
^\<style[^>]*>/(.|[\r\n])*\<\/style>    {
                                            yylval.text = strdup(yytext); 
                                            P("STYLESTART"); 
                                            BEGIN STYLEBLOCK; 
                                            return STYLESTART; 
                                        }
<STYLEBLOCK>.                           { yylval.text = strdup(yytext); P("TEXT"); return TEXT; }
<STYLEBLOCK>\r?\n                       { 
                                            yylineno++; 
                                            yylval.text = strdup(yytext); 
                                            P("TEXT"); 
                                            return TEXT; 
                                        }
<STYLEBLOCK>\<\/style>.*\r?\n          { 
                                            yylval.text = "</style>"; 
                                            P("STYLEEND"); 
                                            BEGIN INITIAL; 
                                            return STYLEEND;
                                        }





.                             { yylval.text = strdup(yytext); P("TEXT"); return TEXT; }
\r?\n                         { yylineno++; P("LINEBREAK"); return LINEBREAK; }


%%

int yywrap(){
    return 1;
}

    /*
    int main(int argc, char **argv){
        yyin = fopen(argv[1], "r");
        yylex();
        fclose(yyin);
    }
    */



