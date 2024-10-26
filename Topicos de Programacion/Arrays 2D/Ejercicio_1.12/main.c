#include <stdio.h>
#include <stdlib.h>
#include "..\..\Bibliotecas\matematica.h"
#include "..\..\Bibliotecas\Vectores.h"
#include "..\..\Bibliotecas\string.h"
#define ROWS 4
#define COLS 4

void printMatrix (int** matrix, int rows, int cols);

int main()
{
    int matrix[ROWS][COLS]= {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10,11,12},
                             {13,14,15,16}};
    int rows= ROWS;
    int cols= COLS;

    printMatrix(matrix,rows,cols);

    return 0;s
}

void printMatrix (int** matrix, int rows, int cols){

int i,j;

    printf("\n");

    for(i=0; i<rows; i++){

        for(j=0; j<cols; j++){

            printf("%d\t",matrix[i][j]);
        }
    printf("\n");
    }


}
