#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
void** createMatrix(int rows,int cols, size_t elemSize){

void** m;
int j,i;

    m = malloc(rows*sizeof(void**)); //declaramos un array de punteros

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


void fillMatrixConditional(int**matrix,int rows,int cols){

    int i,j;

    int count = 0;

    for(i=0; i<rows; i++){

        for(j=0; j<cols; j++){

            matrix[i][j] = (count++) + 1;
        }
    }

}
void fillMatrixIdentity(int**matrix,int rows,int cols){

    int i,j;

    for(i=0; i<rows; i++){

        for(j=0; j<cols; j++){

            if(i==j){

            matrix[i][j] = 1;

            }else{

            matrix[i][j] = 0;

            }
        }
    }

}
int checkIdentity(int** matrix, int rows, int cols){

int i,j;

int count= 0;

    for(i=0; i<rows; i++){

        for(j=0; j<cols; j++){

            if(i==j && matrix[i][j]== 1){
                count++;
            }
        }
    }

return count;
}

int traceMatrix(int** matrix,int rows, int cols){

int i,j;
int count=0;

    for(i=0; i<rows; i++){

        for(j=0; j<cols; j++){

            if(i==j && matrix[i][j]==1){
                count += matrix[i][j];
            }
        }
    }
return count;
}




void printMatrix (int** matrix, int rows,int cols){

int i,j;

    puts("\n");

    for(i=0; i<rows; i++){

        for(j=0; j<cols; j++){

            printf("%d\t",matrix[i][j]);
        }
    puts("\n");
    }


}
