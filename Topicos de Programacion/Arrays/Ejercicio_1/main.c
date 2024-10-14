#include <stdio.h>
#include <stdlib.h>
#include "..\..\Bibliotecas\matematica.h"
#include "..\..\Bibliotecas\Vectores.h"


int main(){

int vec[100]={0,1,2,3,4,5,6,7,8,9};
int tam = 10;
int num = 0;
int pos = 0;

//Numero que queremos ingresar
num=ingresaNum();

//Posicion del vector que queremos reemplazar
pos=ingresaNum();

InsertarVec(vec,num,pos);

MostrarVec(vec,tam);


return 0;
}
