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
        *(m+i)= malloc(cols*sizeof(elemSize));

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

void* my_binarySearch(const void* arr, const void* value, size_t ce, size_t elemSize,int(*p2)(const void* value ,const void* middleElem) ){

    size_t half;
    size_t start = 0;
    size_t  end = ce-1;

    const void* middleElem;

    int resCmp;

    // Realizamos el bucle de búsqueda binaria mientras el rango no esté vacío
    while(start<=end){

        //Calculamos el índice medio para dividir el rango en dos partes
        half = start + (end - start)/ 2;

        //Calculamos el puntero al elemento en la posición 'medio'
        middleElem = (char*)arr + half * elemSize; //casteamos a char para movernos byte a byte

        //Comparamos el elemento medio con la clave que estamos buscando
        resCmp=cmp(value,middleElem);

        //Decidimos la siguiente mitad en la que buscar
        if(resCmp<0){

            end=half;// Si la clave es menor que el elemento medio, buscamos en la mitad izquierda

        }else if(resCmp>0){

            start= half +1;      // Si la clave es mayor que el elemento medio, buscamos en la mitad derecha


        }else{

            return (void*)middleElem;    // Si la clave es igual al elemento medio, encontramos el elemento

        }

    }

    return NULL;    // Si no encontramos el elemento, retornamos NULL

}

int cmp(const void* v1,const void* v2){

int a;
int b;

a = *(int*)v1;
b = *(int*)v2;

return (a>b)- (a<b);


}
