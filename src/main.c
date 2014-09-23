#include <stdio.h>
#include "htmltags.h" 
#include "blocknode.h" 
#include "markdown.y.h"

/* declare external variables and function prototypes */
extern int yylineno;
extern char *yytext;

extern void markdown();

/* input.c */
int GetNextChar(char *b, int maxBuffer);
int getNextLine(void);
int setInputFile(FILE *input);
void PrintError(char *errorstring, ...);



extern void yyerror(char *s) {
    /*
    fprintf(stderr
            , "[ %d:%d,%d:%d ] " 
            , yylloc.first_line
            , yylloc.first_column
            , yylloc.last_line
            , yylloc.last_column
        );
    */
    fprintf(stderr, "line %d: %s %s\n", yylineno, s, yytext);
    PrintError(s);
}

int main(int argc, char **argv){
    FILE *input;
    input = fopen(argv[1], "r");
    if(setInputFile(input)){
        if(getNextLine() == 0){
            markdown();
        }
    }
    fclose(input);
}

