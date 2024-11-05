#ifndef GENERICOS_H_INCLUDED
#define GENERICOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int insertarOrdenadamente(void *vec, void *valor, unsigned *ce, size_t tamElem, size_t tamMax, int cmp(void *, void *));
void* my_binarySearch(void* arr,const void* value,size_t ce,size_t elemSize, int cmp(const void*, const void*));

#endif // GENERICOS_H_INCLUDED
