#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
void printMatrix (int** matrix,  int rows,  int cols);
void** createMatrix(int rows,  int cols,size_t elemSize);
void fillMatrixConditional(int**matrix,  int rows,  int cols);
void fillMatrixIdentity(int**matrix,int rows,int cols);
int checkIdentity(int** matrix, int rows, int cols);
int traceMatrix(int** matrix,int rows, int cols);

#endif // MATRIX_H_INCLUDED
