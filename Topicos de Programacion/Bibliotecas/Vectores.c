#include "vectores.h"
#include <stdio.h>  // Para printf y scanf
#include <ctype.h>

//1.1//Desarrollar una función que inserte un elemento en un arreglo de enteros, dada la posición de
//inserción.

void InsertarVec(int* vec,int num,int pos){

     vec[pos]=num;
}



//1.2//Desarrollar una función que inserte un elemento en un arreglo de enteros, ordenado en forma
//ascendente, de forma de no alterar el orden.

void InsertarVec_2(int* n , int* vec, int num,int pos){

int i=0;

for(i=*n ; i>pos ;i--){

    vec[i]=vec[i-1];

}
vec[pos]=num;

(*n)++;
}

//1.3//Desarrollar una función que elimine el elemento que ocupa una determinada posición de un arreglo
//de enteros.

void EliminaPos(int* vec,int pos,int* n){
    int i=0;
    for (i=pos; i<*n ; i++){

            vec[i]=vec[i+1];
            }
    (*n)--;
}

//1.4 y 1.5//Desarrollar una función que elimine todas las apariciones de un determinado elemento de un arreglo
//de enteros.

void EliminaPr(int* vec,int* n,int num){
int i=0;
int j=0;
for (i=0; i<*n; i++){
    if(*(vec+i)==num){
            for(j=i; j<*n; j++){
                *(vec+j)=*(vec+j+1);
                }
    (*n)--;
    return; //AGREGANDO EL RETURN SALE LA PRIMERA VEZ QUE ENCUENTRA EL NUM
    }

}
}
//1.7//Desarrollar una función que devuelva el valor numérico de una cadena de caracteres (asumiendo que
//los caracteres representan dígitos).

int ConvierteCadena(const char * cadena){

int resultado=0;

while(*cadena){

    if (isdigit((unsigned char)*cadena)){

        resultado=resultado*10 +(*cadena - '0');

    }else {
    //printf("Error: La cadena contiene caracteres no numéricos.\n");
            return -1; // Indicando error
        }

    cadena++;


}

return resultado;

}

//Funcion que muestra el vector//
void MostrarVec(int* vec,int tam){
 int i=0;
for(i=0; i<tam ; i++){

        printf("%d ", *(vec+i));
}
printf("\n");

}

