#include "tagstack.h"

typedef struct blocknode {
    t_tag tag;
    int indent_level;
    int nops;
    char **ops;
    struct blocknode *next;
} t_blocknode;

t_blocknode *blocknode_create(t_tag tag, int level, int nops, ...);
char* blocknode_show(t_blocknode *node);
char* blocknode_parse(t_blocknode *node);
void blocklist_parse();





/* blocknode stack */
#define BLOCKNODE_STACK_SIZE 20

typedef struct { 
    int size;
    t_blocknode *arr[TAG_STACK_SIZE];
} t_blocknode_stack;

void blocknode_init_stack();
t_blocknode *blocknode_top_stack();
int blocknode_empty_stack();
int blocknode_full_stack();
int blocknode_in_stack(t_tag tag, int level);
void blocknode_push_stack(t_blocknode *node);
void blocknode_show_stack();
t_blocknode *blocknode_pop_stack();
t_blocknode *blocknode_shift_stack();
