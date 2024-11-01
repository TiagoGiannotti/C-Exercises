#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_COD 8
#define TAM_VAL 6
#define TAM_STATUS 12 //total 26
#define TAM_DATE 12

#define TAM_LINEA 40
#define TAM_SENS 20


#define maxCod 9      //+1 por el \0
#define maxStatus 13 //+1 por el \0

typedef struct{

    char cod[maxCod];
    float val;
    char status[maxStatus];

}tSensor;

int trozarLinea(tSensor * auxSens, char* linea);
int leerArchFijo(char *nomArch);
char* trim(char* str);
int getNumericCod(tSensor* auxSens);
void inicializarVector(int *vec, size_t ce);
void inicializarVectorSens(tSensor *arr, size_t ce);
void printArr(tSensor* arr, int* count, size_t ce);
#endif // UTILITIES_H_INCLUDED
