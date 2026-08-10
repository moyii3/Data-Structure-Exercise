#include "whole.h"

int InitStack(stack* s){
    (*s) = NULL;
    return OK;
}

int Push(stack* s, biNode* b){
    stack p = (stack)malloc(sizeof(stackNode));
    if(!p) return ERROR;
    p->node = b;
    p->next = *s;
    (*s) = p;
    return OK;
}

int Pop(stack* s, biTree* b){
    if(!(*s)) return ERROR;
    *b = (*s)->node;
    stack p = *s;
    *s = (*s)->next;
    free(p);
    return OK;
}

int IsEmptyStack(stack s){
    if(!s) return 1;
    else return 0;
}