#include <stdio.h>
#include <stdlib.h>
#include "..\..\Bibliotecas\matematica.h"
#include "..\..\Bibliotecas\Vectores.h"
#include "..\..\Bibliotecas\string.h"
#define TAM 100

int main()
{
char cadena[TAM]=  {"holaqunfjsnfjsdholanjsdnkjsdfhola"};
char palabra [TAM]= {"hola"};

int ocurrencias;

ocurrencias=countOcurrences(cadena,palabra);
printf("La cantidad de ocurrencias de la palabra hola es: %d",ocurrencias);

    return 0;
}
