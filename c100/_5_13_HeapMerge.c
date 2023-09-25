#include "Util.h"

static int compareFunction(const void* i, const void* j) {
    return (int)i - (int)j;
}

int ReadIntFromFile(FILE* file, int* offset) {
    fseek(file, *offset, SEEK_SET);

    char buffer[100];
    if (fgets(buffer, sizeof(buffer), file) == NULL)
        return -1;

    *offset = ftell(file);
    return atoi(buffer);   
}

void _5_13_HeapMerge() {
    FILE* f1 = fopen("./input/_5_13_HeapMerge_5.txt", "r");

    int offset = 0;
    int xd = ReadIntFromFile(f1, &offset);
    while (xd != -1) {
        printf("%d\n", xd);
        xd = ReadIntFromFile(f1, &offset);
    }

    fclose(f1);
}