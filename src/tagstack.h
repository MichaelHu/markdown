#define TAG_STACK_SIZE 20
#undef _IS_DEBUG_TAGSTACK

/* tag name representing each line */
typedef enum {
    TAG_ERROR

    , TAG_HTMLBLOCK
    , TAG_SCRIPTBLOCK
    , TAG_STYLEBLOCK

    , TAG_SECTION
    , TAG_VSECTION
    , TAG_P
    , TAG_UL
    , TAG_OL
    , TAG_PRE
    , TAG_BLANK
    , TAG_H
    , TAG_EOF

    , TAG_QUOTE_P
    , TAG_QUOTE_UL
    , TAG_QUOTE_OL
    , TAG_QUOTE_PRE
    , TAG_QUOTE_BLANK
    , TAG_QUOTE_H

    , TAG_INDENT_P
    , TAG_INDENT_UL
    , TAG_INDENT_OL
    , TAG_INDENT_PRE

} t_tag; 

typedef struct {
    t_tag tag;
    int indent_level;
} t_tag_item;

typedef struct { 
    int size;
    t_tag_item *arr[TAG_STACK_SIZE];
} t_tag_stack;

void tag_init_stack();
t_tag_item *tag_top_stack();
int tag_empty_stack();
int tag_full_stack();
int tag_in_stack(t_tag tag, int level);
void tag_push_stack(t_tag tag, int level);
void tag_show_stack();
t_tag_item *tag_pop_stack();
t_tag_item *tag_shift_stack();
t_tag_item *tag_latest_stack(t_tag tag);
int is_in_list(int level);

char* tag_check_stack(t_tag tag, int level);
char *get_tag_type(t_tag tag);
int inner_pre_level(int level);
int indent_level(char *s);


