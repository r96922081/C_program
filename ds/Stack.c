#include "Stack.h"

void InitStack(Stack* s);
void DeleteStack(Stack* s);

/*
typedef struct Stack {
    LinkedList* list;
    void (*Push)(Stack*, void*);
    void* (*Peek)(Stack*);
    void* (*Pop)(Stack*);
    int (*IsEmpty(Stack*)
} Stack;
*/

void InitStack(Stack* s) {
    memset(s, 0, sizeof(Stack));
    InitLinkedList(s->list);
}

void DeleteStack(Stack* s) {
    free(s);
}