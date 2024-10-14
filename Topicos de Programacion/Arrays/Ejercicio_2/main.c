#include <stdio.h>
#include <stdlib.h>
#include "..\..\Bibliotecas\matematica.h"
#include "..\..\Bibliotecas\Vectores.h"

#define TAM 100

int main()
{
    int vec[TAM]={0,1,2,3,4,5,6,7,8,9};
    int num = 0;
    int pos = 0;
    int n=10;

//Numero que vamos a insertar
num=ingresaNum();

//Posicion que vamos a insertar el numero
pos=ingresaNum();

InsertarVec_2(&n ,vec,num,pos);

MostrarVec(vec,n);


    return 0;
}
