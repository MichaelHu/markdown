typedef struct strbuf {
    char *s;
    int length;
    int size;
    int inc_size;
} t_strbuf, *p_strbuf; 

t_strbuf *strbuf_create(int initial_size, int inc_size);
void strbuf_push(t_strbuf *buf, const char *s); 

