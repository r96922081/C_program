#include "ArrayList.h"
#include "util.h"

typedef struct ArrayList ArrayList;

ArrayList* NewArrayList();
void DeleteArrayList(ArrayList* list) ;

static void Append(ArrayList* list, void* value);
static void* Get(ArrayList* list, int index);
static void Set(ArrayList* list, int index, void* value);
static void Sort(ArrayList* list, int (*compareFunction)(const void *, const void*));
static void Sort2(ArrayList* list, int low, int high, int (*compareFunction)(const void *, const void*));
static int SortPartition(ArrayList* list, int low, int high, int (*compareFunction)(const void *, const void*));
static void SortSwap(ArrayList* list, int i, int j);


ArrayList* NewArrayList() {
    ArrayList* list = calloc(1, sizeof(ArrayList));
    list->capacity = 1;    
    list->data = malloc(1 * sizeof(void*));
    list->Get = Get;
    list->Append = Append;
    list->Set = Set;
    list->Sort = Sort;

    return list;
}

void DeleteArrayList(ArrayList* list) {
    free(list->data);
    free(list);
}

static void Append(ArrayList* list, void* value) {
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

static void* Get(ArrayList* list, int index) {
    return *(list->data + index);
}

static void Set(ArrayList* list, int index, void* value) {
    *(list->data + index) = value;
}

static void SortSwap(ArrayList* list, int i, int j) {
    void* temp = list->Get(list, j);
    void* iValue = list->Get(list, i);
    list->Set(list, j, iValue);
    list->Set(list, i, temp);
}


static int SortPartition(ArrayList* list, int low, int high, int (*compareFunction)(const void *, const void*)) {
    int pivot = list->Get(list, high);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        int jValue = list->Get(list, j);
        if (compareFunction(jValue, pivot) <= 0) {
            i++;
            SortSwap(list, i, j);
        }
    }
    SortSwap(list, i + 1, high);
    return (i + 1);
}

static void Sort2(ArrayList* list, int low, int high, int (*compareFunction)(const void *, const void*)) {
    if (low < high) {
        int pivot = SortPartition(list, low, high, compareFunction);
        Sort2(list, low, pivot - 1, compareFunction);
        Sort2(list, pivot + 1, high, compareFunction);  
    }
}

static void Sort(ArrayList* list, int (*compareFunction)(const void *, const void*)) {
    Sort2(list, 0, list->size - 1, compareFunction);
}