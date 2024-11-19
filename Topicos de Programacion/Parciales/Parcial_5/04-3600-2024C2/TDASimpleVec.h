#ifndef TDASIMPLEVEC_H_INCLUDED
#define TDASIMPLEVEC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN_ELE 3


typedef struct{
    //puntero al vector que almacena la informacion
    void* vec;
    //Cantidad de elementos "vivos" en el vector. No es el espacio disponible ver: maxEle
    unsigned ce;
    //Tamanio de la informacion ej int=4 tEmpleado=50
    unsigned tamEle;
    //Maxima cantidad almacenable, si se llena debera ampliarce la memoria, si se eliminan registros
    //debera contraerse.
    unsigned maxEle;
}TDASimVec;

//Implementadas en biblioteca
TDASimVec* crearTDASimVec(unsigned tamEle);
int insertarAlFinal(TDASimVec* sv, void* ele);
TDASimVec* amap(TDASimVec* sv, int accion(void*));
TDASimVec* ordenar(TDASimVec* sv, int cmp(const void*a, const void* b));
TDASimVec* agrupar(TDASimVec* sv, int cmp(const void*, const void*), int fagrup(void*dest, const void* origen));
int cmpSimVec(TDASimVec* sva,TDASimVec* svb);
void destruir(TDASimVec* sv);


///A Implementar por el alumno
TDASimVec* crearTDASimVecALU(unsigned tamEle);
int insertarAlFinalALU(TDASimVec* sv, void* ele);
TDASimVec* ordenarALU(TDASimVec* sv, int cmp(const void*a, const void* b));
TDASimVec* agruparALU(TDASimVec* sv, int cmp(const void*, const void*), int fagrup(void*dest, const void* origen));
void destruirALU(TDASimVec* sv);



#endif // TDASIMPLEVEC_H_INCLUDED
