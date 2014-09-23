#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "blocknode.h"
#include "markdown.y.h"

/* make sure bison switch `-t --locations` is on*/
extern YYLTYPE yylloc;

static FILE *file;
static int eof = 0;
static int nRow = 0;
static int nBuffer = 0;
static int lBuffer = 0;
static int nTokenStart = 0;
static int nTokenLength = 0; 
static int nTokenNextStart = 0;
static int lMaxBuffer = 1000; 
static char *buffer;
static char *tokenText = "";

extern int setInputFile(FILE *input){
    if(input){
        file = input;
        buffer = (char *)malloc(lMaxBuffer);
        if(!buffer){
            fprintf(stderr, "error in allocating memory for buffer");
            return 0;
        }
        return 1;
    }
    return 0;
}

extern int getNextLine(void) {
  char *p;
  
  nBuffer = 0;
  nTokenStart = -1;
  nTokenNextStart = 1;
  eof = 0;

  p = fgets(buffer, lMaxBuffer, file);
  if (  p == NULL  ) {
    if (  ferror(file)  )
      return -1;
    eof = 1;
    return 1;
  }

  nRow += 1;
  lBuffer = strlen(buffer);

  return 0;
}

extern int GetNextChar(char *b, int maxBuffer) {
  int frc;
  
  if (  eof  )
    return 0;
  
  while (  nBuffer >= lBuffer  ) {
    frc = getNextLine();
    if (  frc != 0  )
      return 0;
    }

  b[0] = buffer[nBuffer];
  nBuffer += 1;

  return b[0]==0?0:1;
}

extern void BeginToken(char *t) {

  nTokenStart = nTokenNextStart;
  nTokenLength = strlen(t);
  nTokenNextStart = nBuffer; // + 1;

  /*================================================================*/
  /* location for bison --------------------------------------------*/
  yylloc.first_line = nRow;
  yylloc.first_column = nTokenStart;
  yylloc.last_line = nRow;
  yylloc.last_column = nTokenStart + nTokenLength - 1;

  tokenText = t;
}

extern void PrintError(char *errorstring, ...) {
  static char errmsg[10000];
  va_list args;

  int start=nTokenStart;
  int end=start + nTokenLength - 1;
  int i;

    fprintf(stderr, "...... !");

  /*================================================================*/
  /* simple version ------------------------------------------------*/
/*
    fprintf(stderr, "...... !");
    for (i=0; i<nBuffer; i++)
      fprintf(stderr, ".");
    fprintf(stderr, "^\n");
*/

  /*================================================================*/
  /* a bit more complicate version ---------------------------------*/
/* */
  if (  eof  ) {
    fprintf(stderr, "...... !");
    for (i=0; i<lBuffer; i++)
      fprintf(stderr, ".");
    fprintf(stderr, "^-EOF\n");
  }
  else {
    fprintf(stderr, "...... !");
    for (i=1; i<start; i++)
      fprintf(stderr, ".");
    for (i=start; i<=end; i++)
      fprintf(stderr, "^");
    for (i=end+1; i<lBuffer; i++)
      fprintf(stderr, ".");
    fprintf(stderr, "   token%d:%d[%s]\n", start, end, tokenText);
  }
/* */

  /*================================================================*/
  /* print it using variable arguments -----------------------------*/
  va_start(args, errorstring);
  vsprintf(errmsg, errorstring, args);
  va_end(args);

  fprintf(stderr, "Error: %s\n", errmsg);
}
