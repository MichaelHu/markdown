#include <stdio.h>
#include <stddef.h> /* for NULL */
#include <stdlib.h>
#include "blocknode.h"

t_blocknode_stack blocknode_stack;

void blocknode_init_stack(){
    int i = 0;
    blocknode_stack.size = 0;
    for(; i<BLOCKNODE_STACK_SIZE; i++){
        blocknode_stack.arr[i] = NULL;
    }
}

int blocknode_empty_stack(){
    return blocknode_stack.size == 0;
}

int blocknode_full_stack(){
    return blocknode_stack.size == BLOCKNODE_STACK_SIZE;
}

t_blocknode *blocknode_top_stack(){
    if(blocknode_empty_stack()){
        return NULL;
    }
    else{
        return blocknode_stack.arr[blocknode_stack.size - 1];
    }
}

void blocknode_push_stack(t_blocknode *node){
    if(blocknode_full_stack()){
        return;
    }

    blocknode_stack.arr[blocknode_stack.size++] = node;
}

t_blocknode *blocknode_pop_stack(){
    if(blocknode_empty_stack()){
        return NULL;
    }
    return blocknode_stack.arr[--blocknode_stack.size];
}

t_blocknode *blocknode_shift_stack(){
    t_blocknode *item;
    int i;

    if(blocknode_empty_stack()){
        return NULL;
    }
    item = blocknode_stack.arr[0];

    for(i=0; i<blocknode_stack.size - 1; i++){
        blocknode_stack.arr[i] = blocknode_stack.arr[i+1];
    }
    blocknode_stack.size --;

    return item;
}

int blocknode_in_stack(t_tag tag, int level){
    int i;
    for(i=0; i<blocknode_stack.size; i++){
        if(tag == blocknode_stack.arr[i] -> tag
            && level == blocknode_stack.arr[i] -> indent_level){
            return 1;
        }
    }
    return 0;
}
