#include <stdio.h>
#include <stdlib.h>
#include "Examen.h"



int main()
{
    int result;
    size_t tam;

    tam = getRecords("data.dat");

    result = readFile("data.dat",tam);

    if(result =! 1){

        printf("error al leer el archivo");

    }


    return 0;
}
