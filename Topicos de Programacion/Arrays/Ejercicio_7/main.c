#include <stdio.h>
#include <stdlib.h>
#include "..\..\Bibliotecas\matematica.h"
#include "..\..\Bibliotecas\Vectores.h"
#include "..\..\Bibliotecas\string.h"
#define TAM 100

int main()
{
char cadena[TAM]= {"Hola"};

int numero= ConvierteCadena(cadena);

printf("El valor numerico de la cadena \"%s\" es: %d\n", cadena, numero);


    return 0;
}
