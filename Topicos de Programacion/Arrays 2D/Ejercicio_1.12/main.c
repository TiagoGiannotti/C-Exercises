#include "..\..\Bibliotecas\Matrix.h"
#define ROWS 4
#define COLS 4
#include <stdio.h>
#include <stdlib.h>


int main()
{   int** matrix;
    int rows= ROWS;
    int cols= COLS;
    size_t elemSize = sizeof(int);
    int result;


    matrix = (int**) createMatrix(rows,cols,elemSize);
    fillMatrixConditional(matrix,rows,cols);
    puts("MATRIZ");
    printMatrix(matrix,rows,cols);
    printf("\n");

    puts("EN REFERENCIA A LA DIAGONAL PRINCIPAL...");
    printf("\n");

    puts("TRIANGULO SUPERIOR DERECHO");
    upperRightDiagonalMatrix(matrix,rows,cols);
    result = sumUpperRightDiagonalMatrix(matrix,rows,cols);

    printf("\n La sumatoria del triangulo superior derecho es: %d ",result);
    printf("\n");
    printf("\n");
    printf("\n");

    puts("TRIANGULO INFERIOR IZQUIERDO");
    lowerLeftDiagonalMatrix(matrix,rows,cols);
    result=sumLowerLeftDiagonalMatrix(matrix,rows,cols);

    printf("\n La sumatoria del triangulo inferior izquierdo es: %d ",result);
    printf("\n");
    printf("\n");
    printf("\n");

    puts("EN REFERENCIA A LA DIAGONAL SECUNDARIA...");
    printf("\n");
    puts("TRIANGULO SUPERIOR IZQUIERDO");

    upperLeftDiagonalMatrix(matrix,rows,cols);
    result=sumUpperLeftDiagonalMatrix(matrix,rows,cols);
    printf("\n La sumatoria del triangulo superior izquierdo es: %d ",result);
    printf("\n");
    printf("\n");
    printf("\n");



    return 0;
}

