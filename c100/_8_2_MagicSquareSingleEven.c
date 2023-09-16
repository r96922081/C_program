#include "Matrix.h"

static void FillMagicSquare(Matrix* m, int startNumber, int startRow, int startCol, int endRow, int endCol)
{
    int value = startNumber;
    int row = startRow;
    int column = (startCol + endCol)/2;
    int count = 0;

    while (count < (endRow - startRow) * (endCol - startCol)) {
        if (m->Get(m, row, column) != 0) {
            row++;
            if (row == endRow)
                row = startRow;
            row++;
            if (row == endRow)
                row = startRow;                
            column--;
            if (column == startCol - 1)
                column = endCol - 1;
        }

        m->Set(m, row, column, value);
        value++;
        row--;
        if (row == startRow - 1)
            row = endRow - 1;
        column++;
        if (column == endCol)
            column = startCol;

        count++;
    }
}

void MagicSquareSingleEven(int m)
{
    Matrix* matrix = NewMatrix(4 * m + 2, 4 * m + 2);

    FillMagicSquare(matrix, 1, 0, 0, 2 * m + 1, 2 * m + 1);
    FillMagicSquare(matrix, (2 * m + 1) * (2 * m + 1) + 1, 2 * m + 1,  2 * m + 1, 2 * (2 * m + 1), 2 * (2 * m + 1));
    FillMagicSquare(matrix, 2 * (2 * m + 1) * (2 * m + 1) + 1, 0,  2 * m + 1, 2 * m + 1, 2 * (2 * m + 1));
    FillMagicSquare(matrix, 3 * (2 * m + 1) * (2 * m + 1) + 1, 2 * m + 1,  0, 2* (2 * m + 1), 2 * m + 1);

    for (int i = 0; i < 2 * m + 1; i++) {
        for (int j = 0; j < (2 * m + 1) / 2; j++) {
            int a = matrix->Get(matrix, i, j);
            int b = matrix->Get(matrix, i + 2 * m + 1, j);
            matrix->Set(matrix, i + 2 * m + 1, j, a);
            matrix->Set(matrix, i, j, b);
        }
    }

    matrix->Print(matrix);

    DeleteMatrix(matrix);
}