#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

void check(int ret);

typedef struct Pair {
    void* first;
    void* second;
} Pair;

typedef struct Triple {
    void* first;
    void* second;
    void* third;
} Triple;