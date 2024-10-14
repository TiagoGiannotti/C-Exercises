#include <stdio.h>
#include <stdlib.h>
#include "..\..\Bibliotecas\matematica.h"
#include "..\..\Bibliotecas\Vectores.h"
#define TAM 100

int main()
{
    int vec[TAM]={0,1,2,3,4,3,6,3,3,9};
    int num = 0;
    int ce=10;

    printf("ingrese el elemento a eliminar: ");
    scanf("%d",&num);

    MostrarVec(vec,ce);
    EliminaPr(vec,&ce,num);
    MostrarVec(vec,ce);
    return 0;
}
