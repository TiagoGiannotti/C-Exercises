#include "Genericos.h"
#include <string.h>
int insertarOrdenadamente(void *vec,void *valor,unsigned *ce, size_t tamElem,size_t tamMax,int cmp(void *, void *)){

    void *pIni = vec;
    void *pFin;
    pFin = (*ce == tamMax)? vec+(*ce)*tamElem-tamElem : vec+(*ce)*tamElem;
    if(*ce == tamMax && cmp(pFin, valor)<0)
        return 0;
    while(pIni<pFin && cmp(pFin-tamElem, valor)>0)
    {
        memcpy(pFin, pFin-tamElem, tamElem);
        pFin-=tamElem;
    }
    memcpy(pFin, valor, tamElem);
    *ce = (*ce ==tamMax)? *ce : *(ce)+1;

    return 1;
}

void* my_binarySearch(void* arr,const void* value,size_t ce,size_t elemSize, int cmp(const void*, const void*)){

void* middleElem;

size_t start,end,half;

int resCmp;

start = 0;

end = ce-1;

    while(start<=end){

        half = start + (end-start)/2;

        middleElem = (char*) arr + half * elemSize;

        resCmp = cmp(value,middleElem);

        if(resCmp<0) end=half;

        else if(resCmp>0) start=half+1;

        else if(resCmp==0)return middleElem;
    }
    return NULL;
}

void* busquedaSecuencial(void* arr, size_t ce, size_t elemSize,const void* value,int cmp(const void*,const void*)){

size_t i;

    for(i=0; i<ce; i++){

        if(cmp(arr+(i*elemSize),value)==0) return (char*)arr+(i*elemSize);
    }

return NULL;
}



int cmpInt(const void*a,const void*b){

int x;
int y;

    x = *(int*)a;
    y = *(int*)b;

return (x>y)-(x<y);
}

int cmpChar(const void* a, const void* b){

char x;
char y;

    x = *(char*)a;
    y = *(char*)b;

    return (x>y)-(x<y);
}

int cmpFloat(const void* a, const void* b){

float x;
float y;

    x = *(float*)a;
    y = *(float*)b;

    return (x>y)-(x<y);
}
//
//int cmpStruct(const void* a, const void* b){
//
//sStruct* x;
//sStruct* y;
//
//    x = (sStruct*)a;
//    y = (sStruct*)b;
//
//    return strcmp(a->code,b->code);
//
//
//}
