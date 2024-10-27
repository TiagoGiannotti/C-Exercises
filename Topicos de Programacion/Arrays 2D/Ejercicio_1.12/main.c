#include <stdio.h>
#include <stdlib.h>
#include "..\..\Bibliotecas\matematica.h"
#include "..\..\Bibliotecas\Vectores.h"
#include "..\..\Bibliotecas\string.h"
#define ROWS 4
#define COLS 4

void printMatrix (int** matrix,  int rows,  int cols);
void** createMatrix(int rows,  int cols, size_t elemSize);
void fillMatrix(int**matrix,  int rows,  int cols);


int main()
{
    int rows= ROWS;
    int cols= COLS;
    size_t elemSize = sizeof(int);

    int** matrix;

    matrix = createMatrix(rows,cols,elemSize);

    fillMatrix(matrix,rows,cols);

    printMatrix(matrix,rows,cols);

    free(matrix);

    return 0;
}

void** createMatrix(int rows,  int cols, size_t elemSize){

void** m;
int j,i;

    m = malloc(rows*sizeof(void**)); //declaramos un array de punteros a int

    if (m == NULL){
        printf("Memory allocation failed \n");
        return NULL;
    }

    for(i=0; i<rows; i++){

        *(m+i) = malloc(cols*sizeof(elemSize)); //asignamos memoria a cada fila

    if(*(m+i) == NULL){

        for(j=0; j<cols; j++) free(*(m+j));

          printf("Memory allocation failed \n");
          return NULL;
    }
    }

    return m;
}


void fillMatrix(int**matrix,int rows,int cols){

    int i,j;

    int count = 0;

    for(i=0; i<rows; i++){

        for(j=0; j<cols; j++){

            matrix[i][j] = (count++) + 1;
        }
    }

}


void printMatrix (int** matrix, int rows,int cols){

int i,j;

    printf("\n");

    for(i=0; i<rows; i++){

        for(j=0; j<cols; j++){

            printf("%d\t",matrix[i][j]);
        }
    printf("\n");
    }


}
