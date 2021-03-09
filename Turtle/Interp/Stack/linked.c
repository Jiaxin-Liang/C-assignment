#include "stack.h"

stack* stack_init(void)
{
    stack* s = (stack*) ncalloc(1, sizeof(stack));
    s->size = 0;
    return s;
}

void stack_push(stack* s, double d)
{
    dataframe* f;
    if(s){
        f = ncalloc(sizeof(dataframe), 1);
        f->i = d;
        f->next = s->start;
        s->start = f;
        s->size = s->size + 1;
    }
}

bool stack_pop(stack* s, double* d)
{
    dataframe* f;
    if((s == NULL) || (s->start == NULL)){
        return false;
    }
    f = s->start->next;
    *d = s->start->i;
    free(s->start);
    s->start = f;
    s->size = s->size - 1;
    return true;
}

bool stack_peek(stack* s, double* d)
{
    if((s==NULL) || (s->start==NULL)){
        return false;
    }
    *d = s->start->i;
    return true;
}

bool stack_free(stack* s)
{
    if(s){
        dataframe* tmp;
        dataframe* p = s->start;
        while(p != NULL){
            tmp = p->next;
            free(p);
            p = tmp;
        }
        free(s);
    }
    return true;
}

