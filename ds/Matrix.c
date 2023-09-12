#include "Matrix.h"
#include "ArrayList.h"

void MatrixPrint(Matrix*);
void MatrixSet(Matrix* matrix, int row, int column, void* value);
void* MatrixGet(Matrix* matrix, int row, int column);

void InitMatrix(Matrix* matrix, int rowCount, int columnCount) {
    memset(matrix, 0, sizeof(matrix));
    matrix->row = rowCount;
    matrix->column = columnCount;
    matrix->list = malloc(sizeof(ArrayList));
    InitArrayList(matrix->list);

    for (int i = 0; i < rowCount; i++) {
        ArrayList* row = malloc(sizeof(ArrayList));
        InitArrayList(row);
        for (int j = 0; j < columnCount; j++) {
            row->Append(row, 0);
        }
        matrix->list->Append(matrix->list, row);
    }        
    matrix->Get = MatrixGet;
    matrix->Set = MatrixSet;
    matrix->Print = MatrixPrint;
}

void MatrixPrint(Matrix* matrix) {
    for (int i = 0; i < matrix->row; i++) {
        ArrayList* row = matrix->list->Get(matrix->list, i);
        printf("%d", row->Get(row, 0));
        for (int j = 1; j < matrix->column; j++) {
            printf(",%d", row->Get(row, j));
        }
        printf("\n");
    }
    printf("\n");
}

void MatrixSet(Matrix* matrix, int rowIndex, int column, void* value) {
    ArrayList* row = matrix->list->Get(matrix->list, rowIndex);
    row->Set(row, column, value);
}

void* MatrixGet(Matrix* matrix, int rowIndex, int column) {
    ArrayList* row = matrix->list->Get(matrix->list, rowIndex);
    return row->Get(row, column);
}

void DeleteMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->row; i++) {
        ArrayList* row = matrix->list->Get(matrix->list, i);
        DeleteArrayList(row);
    }
    DeleteArrayList(matrix->list);
    free(matrix);
}