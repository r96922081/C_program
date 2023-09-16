#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

typedef struct Stack Stack;

typedef struct Stack {
    LinkedList* list;
    void (*Push)(Stack*, void*);
    void* (*Peek)(Stack*);
    void* (*Pop)(Stack*);
    int (*IsEmpty)(Stack*);
    int (*GetSize)(Stack*);
} Stack;

Stack* NewStack();
void DeleteStack(Stack*);


#endif