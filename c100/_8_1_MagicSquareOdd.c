#include "../ds/Matrix.h"

void MagicSquareOdd(int odd)
{
    Matrix* m = malloc(sizeof(Matrix));
    InitMatrix(m, odd, odd);

    int value = 1;
    int row = 0;
    int column = odd/2;    
    while (value <= odd * odd) {
        if (m->Get(m, row, column) != 0) {
            row++;
            if (row == odd)
                row = 0;
            row++;
            if (row == odd)
                row = 0;                
            column--;
            if (column == -1)
                column = odd - 1;
        }

        m->Set(m, row, column, value);
        value++;
        row--;
        if (row == -1)
            row = odd - 1;
        column++;
        if (column == odd)
            column = 0;
    }

    m->Print(m);

    DeleteMatrix(m);
}