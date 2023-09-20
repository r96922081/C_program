#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct ArrayList ArrayList;

typedef struct ArrayList {
    int size;
    int capacity;
    void** data;
    void (*Set)(ArrayList*, int index, void* value);
    void (*Append)(ArrayList*, void* value);
    void* (*Get)(ArrayList*, int index);
    void (*Delete)(ArrayList*, int index);
    void (*Sort)(ArrayList* list, int (*compareFunction)(const void *, const void*));
    void (*Print)(ArrayList*);
} ArrayList;

ArrayList* NewArrayList();
ArrayList* NewArrayList2(int size);
void DeleteArrayList(ArrayList*);

void ArrayListUt();

#endif