#include "stdio.h"
#include "..\..\Bibliotecas\matematica.h"

int main()
{
    int valor;

    valor=ingresaNum();
    printf("el factorial es: %d ",factorial(valor));


    return 0;
}
