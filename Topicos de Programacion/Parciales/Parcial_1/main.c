#include <stdio.h>
#include <stdlib.h>
#include "Examen.h"
#define TAM 100
#define ROWS 4
#define COLS 4

int main(){
//---------------------DECLARACIONES--PUNTO 1---------------------//

    char palabra1[TAM] = "Tiago";
    char palabra2[TAM] = "Giannotti";
    char* nombreYapellido;
    size_t elemSize= sizeof(char*);
    size_t ce= sizeof(nombreYapellido)/sizeof(nombreYapellido[0]); //para hacerlo generico


//---------------------DECLARACIONES--PUNTO 2---------------------//

    int** matrix;
    int rows= ROWS;
    int cols = COLS;
    size_t elemSize_2 = sizeof(int);
    int result_1=0;
    int result_2=0;
    int resultado=0;

//---------------------DECLARACIONES--PUNTO 3---------------------//

    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int search = 5;
    size_t elemSize_3= sizeof(int);
    size_t ce_2= sizeof(arr)/sizeof(arr[0]);

    int* result;


//------------------------------------------DESARROLLO--PUNTO 1------------------------------------------//

    printf("Nombre: %s\n",palabra1);
    printf("Apellido: %s\n",palabra2);
    nombreYapellido=my_strcat(palabra1,palabra2);
    printf("\n");

    printf("El nombre y apellido concatenado es: \n");
    printArr(nombreYapellido,ce,elemSize,action);
    printf("\n");
    printf("\n");

//------------------------------------------DESARROLLO--PUNTO 2------------------------------------------//

    matrix = (int**) createMatrix(rows,cols,elemSize_2);

    fillMatrixConditional(matrix,rows,cols);

    result_1=sumDiagonalInfMatrix(matrix,rows,cols);

    result_2=sumDiagonalInfMatrix_2(matrix,rows,cols);

    destroyMatrix((void**)matrix,rows);

    resultado= result_1+result_2;

    printf("La suma de los elementos debajo de las diagonales de una matriz es: %d",resultado);
    printf("\n");
    printf("\n");
//------------------------------------------DESARROLLO--PUNTO 3------------------------------------------//

    result = my_binarySearch(arr,&search,ce_2,elemSize_3,cmp);

    if (result != NULL) {
        printf("Elemento encontrado: %d\n", *result);
    } else {
        printf("Elemento no encontrado.\n");
    }

    return 0;
}

