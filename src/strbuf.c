#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strbuf.h"

t_strbuf *strbuf_create(int initial_size, int inc_size){

    t_strbuf *buf = NULL;

    if(( buf = (t_strbuf *) malloc(sizeof(t_strbuf)) )){

        buf -> s = NULL;
        buf -> length = 0;
        buf -> size = 0;
        buf -> inc_size = inc_size;

        if( (  buf -> s = (char *)malloc(initial_size)  ) ){
            buf -> size = initial_size;
        }
        else{
            fprintf(stdout, "strbuf_create: malloc error\n");
            exit(1);
        }
    }
    else{
        fprintf(stdout, "strbuf_create: malloc error\n");
        exit(1);
    }

    return buf;
}

void strbuf_push(t_strbuf *buf, const char *s){ 
    int len = strlen(s);
    int new_size;
    void *p;

    if(len + buf -> length >= buf -> size){
        new_size = ( ( len + buf -> length + 1 ) / buf -> inc_size + 1 ) * buf -> inc_size; 
        p = realloc( buf -> s, new_size );
        if(!p){
            fprintf(stdout, "strbuf_push: realloc error\n");
            exit(1);
        } 
        buf -> s = (char *)p;
        buf -> size = new_size;
    }

    strcat(buf -> s, s);
    buf -> length += len;
}


