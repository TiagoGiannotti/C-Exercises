#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "TDASimpleVec.h"

#define EXAMEN

#ifdef EXAMEN
    #define crearTDASimVec  crearTDASimVecALU
    #define ordenar         ordenarALU
    #define agrupar         agruparALU
    #define destruir        destruirALU
#endif  EXAMEN

int main()
{
    //Movimientos para pruebas, modifique todo lo que considere,
    //el main es de usted pero no modifique ningun prototipo!
    tMovimiento movs[] = {  {"PR01", 10},
                            {"PR02", 5},
                            {"PR01", -1},
                            {"PR03", 98},
                            {"PR01", -5},
                            {"PR02", 2}
                            };
    int i;
    TDASimVec* svm;

    //Crear TDA vector para mis movimientos de prueba
    svm = crearTDASimVec(sizeof(movs[0]));

    //Inserto mis movimientos de prueba
    for(i=0;i<sizeof(movs)/sizeof(movs[0]);i++){
        insertarAlFinal(svm, &movs[i]);
    }
    //amap(svm,mostrarMovimiento);
    printf("\n");
    //Ordeno mis movimientos antes del agrupamiento
    ordenar(svm, cmpMovimiento);

    //amap(svm,mostrarMovimiento);

    //Ahora que estan ordenados agrupo
   agrupar(svm, cmpMovimiento, agruparMovimiento);

    //Muestro para ver si los resultados son correctos
    amap(svm, mostrarMovimiento);

    //Destructores    svm = ini;
    destruir(svm);

    return 0;
}
