#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

char* my_strcat(char* destination, char* source);
void printArr(void* nombreYapellido, size_t ce,size_t elemSize,void(*p)(void* arr));
void action (void* arr);

//---------------------------------------------------------------------------------//

void** createMatrix(int rows,int cols, size_t elemSize);
void destroyMatrix(void** arr,int rows);
void fillMatrixConditional(int** matrix,int rows,int cols);
int sumDiagonalInfMatrix(int** matrix, int rows, int cols);
void printMatrix(int** matrix, int rows,int cols);
int sumDiagonalInfMatrix_2(int** matrix, int rows, int cols);
//---------------------------------------------------------------------------------//
void* my_binarySearch(void* arr, const void* value, size_t ce, size_t elemSize, int cmp(const void*, const void*));
int cmp (const void* ,const void*);
#endif // EXAMEN_H_INCLUDED
