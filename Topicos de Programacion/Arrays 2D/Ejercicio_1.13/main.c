#include <stdio.h>
#include <stdlib.h>
#include "..\..\Bibliotecas\Matrix.h"
#define ROWS 4
#define COLS 4

int main()
{
    int** matrix;
    int rows= ROWS;
    int cols= COLS;
    size_t elemSize=sizeof(int);
    int result;
    int order=COLS;


    matrix =(int**)createMatrix(rows,cols,elemSize);

    fillMatrixIdentity(matrix,rows,cols);
    result=checkIdentity(matrix,rows,cols);

    if(result!=order){

    printf("the giving matrix is not the identity type");
    return 1;
    }

    printMatrix(matrix,rows,cols);

    result=traceMatrix(matrix,rows,cols);

    printf("the result is: %d",result);


    return 0;
}
