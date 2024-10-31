#include <stdio.h>
#include <stdlib.h>
#include "Utilities.h"






int main()
{
    int result;

    result = crearLotePruebas("Estudiantes.txt");

    if(result == 1){
        printf("archivo creado con exito\n");
    }else{
     printf("error al crear el archivo\n");
    }

    result = leerArchFijo("Estudiantes.txt");

    if(result == 1){
        printf("Lectura correcta\n");
    }else{
     printf("error al leer\n");
    }
    return 0;
}

