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

void insertionSortBySumRows(int *rows, matrix *m) {
    for (size_t i = 1; i < m->nRows; i++) {
        int t = rows[i];
        int *row = m->values[i];
        int j = i;
        while (j > 0 && rows[j - 1] > t) {
            rows[j] = rows[j - 1];
            m->values[j] = m->values[j - 1];
            j--;
        }
        rows[j] = t;
        m->values[j] = row;
    }
}

void selectionSortBySumCols(int *a, matrix *m) {
    for (int i = 0; i < m->nCols - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < m->nCols; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap_matrix(&a[i], &a[minPos], m, i, minPos);
    }
}

//--------------------------------------------------------------

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        free(m->values[i]);
    }

    free(m->values);

    m->values = NULL;
    m->nRows = 0;
    m->nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(&ms[i]);
    }
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        int *row = m->values[i];
        for (int j = 0; j < m->nCols; j++) {
            scanf("%d", &row[j]);
        }
    }
}

void outputMatrix(matrix m) {
    outputMatrixSum(m, false);
}

void outputMatrixSum(matrix m, bool showSum) {
    for (int i = 0; i < m.nRows; i++) {
        int sum = 0;
        for (int j = 0; j < m.nCols; j++) {
            //printf("%d\t", m.values[i][j]);
            sum += m.values[i][j];
        }
        if (showSum) {
            //printf("=%d\n", sum);
        } else {
            //printf("\n");
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int a = 0; a < nMatrices; a++) {
        inputMatrix(&ms[a]);
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int a = 0; a < nMatrices; a++) {
        outputMatrix(ms[a]);
        printf("\n");
    }
}