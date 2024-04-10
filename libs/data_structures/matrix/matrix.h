

#ifndef OP15_MATRIX_H
#define OP15_MATRIX_H

# include <stdint.h>
# include <stdbool.h>
# include <assert.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

#endif //OP15_MATRIX_H
