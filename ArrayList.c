#include "ArrayList.h"
#include "util.h"

typedef struct ArrayList ArrayList;

/*
typedef struct ArrayList {
    int size;
    void* data;
    void (*Insert)(ArrayList*, void* value);
    void (*Append)(ArrayList*, void* value);
    void* (*Get)(ArrayList*, int index);
    void (*Delete)(ArrayList*, int index);
} ArrayList;
*/

void InitArrayList(ArrayList*);
void ArrayListUt();
void ArrayListUt_Get_Set_Append();
void ArrayListAppend(ArrayList* list, void* value);
void* ArrayListGet(ArrayList* list, int index);
void ArrayListSet(ArrayList* list, int index, void* value);
void ArrayListSort(ArrayList* list, int (*compareFunction)(const void *, const void*));
void ArrayListSort2(ArrayList* list, int low, int high, int (*compareFunction)(const void *, const void*));
int ArrayListSortPartition(ArrayList* list, int low, int high, int (*compareFunction)(const void *, const void*));
void ArrayListSortSwap(ArrayList* list, int i, int j);

int compareFunction(const void* i, const void* j) {
    return (int)i - (int)j;
}

void ArrayListUt_Get_Set_Append() {
    ArrayList l2;
    ArrayList* l = &l2;
    InitArrayList(l);

    for (int i = 0; i < 100; i++) {
        l->Append(l, i);
    }

    check(l->size == 100);
    for (int i = 0; i < 100; i++) {
        check(l->Get(l, i) == i);
    }  

    l->Set(l, 1, 111);
    check(l->Get(l, 1) == 111);
}

void ArrayListUt_Sort() {
    ArrayList l2;
    ArrayList* l = &l2;
    InitArrayList(l);

    for (int i = 0; i < 100; i++) {
        l->Append(l, 99 - i);
    }

    l->Sort(l, compareFunction);

    for (int i = 0; i < 100; i++) {
        check(l->Get(l, i) == i);
    }      
}

void ArrayListUt() {
    ArrayListUt_Get_Set_Append();
    ArrayListUt_Sort();
}

void InitArrayList(ArrayList* list) {
    memset(list, 0, sizeof(ArrayList));
    list->capacity = 1;    
    list->data = malloc(1 * sizeof(void*));
    list->Get = ArrayListGet;
    list->Append = ArrayListAppend;
    list->Set = ArrayListSet;
    list->Sort = ArrayListSort;
}

void DeleteArrayList(ArrayList* list) {
    free(list->data);
    free(list);
}

void ArrayListAppend(ArrayList* list, void* value) {
    if (list->size + 1 > list->capacity) {
        list->capacity *= 2;
        void** data2 = malloc(list->capacity * sizeof(void*));
        memcpy(data2, list->data, sizeof(void*) * list->capacity/2);
        free(list->data);
        list->data = data2;
    }

    void** dest = (list->data + list->size);
    *dest = value;
    list->size++;
}

void* ArrayListGet(ArrayList* list, int index) {
    return *(list->data + index);
}

void ArrayListSet(ArrayList* list, int index, void* value) {
    *(list->data + index) = value;
}

void ArrayListSortSwap(ArrayList* list, int i, int j) {
    void* temp = list->Get(list, j);
    void* iValue = list->Get(list, i);
    list->Set(list, j, iValue);
    list->Set(list, i, temp);
}


int ArrayListSortPartition(ArrayList* list, int low, int high, int (*compareFunction)(const void *, const void*)) {
    int pivot = list->Get(list, high);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        int jValue = list->Get(list, j);
        if (compareFunction(jValue, pivot) <= 0) {
            i++;
            ArrayListSortSwap(list, i, j);
        }
    }
    ArrayListSortSwap(list, i + 1, high);
    return (i + 1);
}

void ArrayListSort2(ArrayList* list, int low, int high, int (*compareFunction)(const void *, const void*)) {
    if (low < high) {
        int pivot = ArrayListSortPartition(list, low, high, compareFunction);
        ArrayListSort2(list, low, pivot - 1, compareFunction);
        ArrayListSort2(list, pivot + 1, high, compareFunction);  
    }
}

void ArrayListSort(ArrayList* list, int (*compareFunction)(const void *, const void*)) {
    ArrayListSort2(list, 0, list->size - 1, compareFunction);
}