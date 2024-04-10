#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_matrix(int *a, int *b, matrix *m, int col1, int col2) {
    swap(a, b);

    for (int i = 0; i < m->nRows; i++) {
        int *row = m->values[i];

        int temp2 = row[col1];
        row[col1] = row[col2];
        row[col2] = temp2;
    }
}
