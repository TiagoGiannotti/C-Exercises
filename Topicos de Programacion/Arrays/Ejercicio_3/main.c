#include <stdio.h>
#include <stdlib.h>
#include "..\..\Bibliotecas\matematica.h"
#include "..\..\Bibliotecas\Vectores.h"
#define TAM 100
int main()
{
    int vec[TAM]={0,1,2,3,4,5,6,7,8,9};
    int pos = 0;
    int ce=10;

    printf("ingrese la posicion a eliminar: ");
    scanf("%d",&pos);

    MostrarVec(vec,ce);
    EliminaPos(vec,pos,&ce);
    MostrarVec(vec,ce);
    return 0;
}
