#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

#define MAXCODE 9
#define MAXLINE 128
#define MAXVEC 20

#include <stdio.h>
#include <stdlib.h>

typedef struct{

 float lat;
 float longi;
char code[MAXCODE];

}sEmb;

typedef struct{

 float lat;
 float longi;
char code[MAXCODE];
 float dist;

}sEmb_2;

int readFile(const char* namFile);
int trozarLinea(char* linea,sEmb* auxEmb);
float haversine(float lat1, float lon1, float lat2, float lon2);
float toRadians(float degree);
int cmp(const void* a, const void* b);
void printArray(sEmb_2* array, size_t ce);
void* busquedaSecuencial(void* array, void* value, size_t ce, size_t elemSize,int cmp(const void*,const void*));

#endif // EXAMEN_H_INCLUDED
