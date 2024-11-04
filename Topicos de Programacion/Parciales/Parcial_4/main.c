#include <stdio.h>
#include <stdlib.h>
#include "Examen.h"
int main()
{
    int result;

    result = readFile("embarcaciones.csv");

    if(result != 1){
        printf("ARCHIVO LEIDO INCORRECTAMENTE");
    }

    return 0;
}
