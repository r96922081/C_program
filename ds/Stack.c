#include "Stack.h"

Stack* NewStack();
void DeleteStack(Stack* s);

static void Push(Stack*, void*);
static void* Peek(Stack*);
static void* Pop(Stack*);
static int IsEmpty(Stack*);

Stack* NewStack() {
    Stack* s = malloc(sizeof(Stack));
    s->list = NewLinkedList();
    s->Push = Push;
    s->Peek = Peek;
    s->Pop = Pop;
    s->IsEmpty = IsEmpty;

    return s;
}

void DeleteStack(Stack* s) {
    DeleteLinkedList(s->list);
    free(s);
}

static void Push(Stack* s, void* v) {
    s->list->Append(s->list, v);
}

static void* Peek(Stack* s) {
    return s->list->tail->value;
}

static void* Pop(Stack* s) {
    void* ret = s->Peek(s);
    s->list->Delete(s->list, s->list->tail);
    return ret;
}

static int IsEmpty(Stack* s) {
    if (s->list->size == 0)
        return 1;
    else
        return 0;
}