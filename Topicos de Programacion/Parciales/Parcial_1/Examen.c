#include "Examen.h"

char* my_strcat(char* dest, char* source){

    char* ini = dest;

    while(*dest){

    dest++;

    }
    while (*source){

    *dest=*source;

    source++;
    dest++;


    }
    *dest='\0';

    return ini;
    }

void printArr(void* arr,size_t ce,size_t elemSize,void(*p)(void* arr)){

    action(arr);

}


void action(void* arr){

printf("%s",(char*)arr);

}


void** createMatrix(int rows,int cols, size_t elemSize){

void** m;
int i, j;

    m= malloc(rows*sizeof(void*));

    if(m == NULL){
        printf("Memory allocation failed_1:");
        return NULL;
    }

    for(i=0; i<rows; i++){
        *(m+i)= malloc(cols*elemSize);

        if(*(m+i)== NULL){
            for(j=0; j<cols; j++){
                free(*(m+j));
            }
          printf("Memory allocation failed_2:");
          return NULL;
        }
    }
return m;
}

void destroyMatrix(void** m,int rows){
int i;

for(i=0; i<rows; i++){

    free(*(m+i)); //liberamos array de punteros a int

}
free(m);//liberamos puntero a array de punteros

}

void fillMatrixConditional(int** matrix,int rows,int cols){

int i;
int j;

int count = 0;

    for(i=0; i<rows; i++){

        for(j=0; j<cols; j++){

            matrix[i][j] = (count++) + 1;
        }
    }

}

int sumDiagonalInfMatrix(int** matrix, int rows, int cols){
int i;
int j;
int count=0;;

 printf("\n");

//TRIANGULO INFERIOR EN REFERENCIA A LA DIAGONAL PRINCIPAL
for(i=1; i<rows; i++){

    for(j=0; j<i; j++){

        printf("%d\t",matrix[i][j]);
        count += matrix[i][j];
    }
       printf("\n");
}
 printf("\n");

return count;
}

int sumDiagonalInfMatrix_2(int** matrix, int rows, int cols){
int i;
int j;
int count=0;

 printf("\n");

//TRIANGULO INFERIOR EN REFERENCIA A LA DIAGONAL SECUNDARIA

for(i=1; i<rows; i++){

    for(j=(cols-i); j<cols; j++){

        printf("%d\t",matrix[i][j]);
        count += matrix[i][j];
    }
       printf("\n");
}
 printf("\n");

return count;
}



void printMatrix(int** matrix, int rows,int cols){

int i,j;

  printf("\n");

    for(i=0; i<rows; i++){

        for(j=0; j<cols; j++){

            printf("%d\t",matrix[i][j]);

        }
    printf("\n");
    }
}

void* my_binarySearch(void* arr, const void* value, size_t ce, size_t elemSize, int cmp(const void*, const void*)) {
    // Caso base: Si no hay elementos (rango inválido), retornar NULL
    if (ce == 0) {
        return NULL;
    }

    // Calcular el índice medio
    size_t half = ce / 2;
    void* middleElem = (char*)arr + half * elemSize;

    // Comparar el valor buscado con el elemento medio
    int resCmp = cmp(value, middleElem);

    if (resCmp == 0) {
        // Caso base: elemento encontrado
        return middleElem;
    } else if (resCmp < 0) {
        // Buscar en la mitad izquierda
        return my_binarySearch(arr, value, half, elemSize, cmp);
    } else {
        // Buscar en la mitad derecha
        return my_binarySearch((char*)arr + (half + 1) * elemSize, value, ce - half - 1, elemSize, cmp);
    }
}

int cmp(const void* v1,const void* v2){

int a;
int b;

a = *(int*)v1;
b = *(int*)v2;

return (a>b)- (a<b);


}
