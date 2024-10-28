#include "..\..\Bibliotecas\Matrix.h"
#define ROWS 4
#define COLS 4
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int rows= ROWS;
    int cols= COLS;
    int result;
    int order= cols; // o rows es lo mismo ya que es matrix cuadrada
    size_t elemSize = sizeof(int);

    int** matrix;

    matrix = (int**)createMatrix(rows,cols,elemSize);

    fillMatrixIdentity(matrix,rows,cols);

    result=checkIdentity(matrix,rows,cols);

    if(result == order ){
        printf("la matriz de orden %d es la matriz identidad \n",order);
    }
    else{
        printf("la matriz de orden %d no es la matriz identidad \n",order);
        }

    printMatrix(matrix,rows,cols);

    free(matrix);

    return 0;
}

