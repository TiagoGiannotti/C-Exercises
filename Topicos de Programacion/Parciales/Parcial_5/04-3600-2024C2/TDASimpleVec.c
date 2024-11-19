///A Implementar por el alumno
#include "TDASimpleVec.h"


TDASimVec* crearTDASimVecALU(unsigned tamEle){
    TDASimVec* tda = malloc(sizeof(TDASimVec));
    if(!tda)return NULL;

    tda->tamEle = tamEle;
    tda->maxEle = MIN_ELE;
    tda->ce     = 0;
    tda->vec    = malloc(tamEle*MIN_ELE);

    if (!tda->vec){return NULL;
                   free(tda);}
    return tda;
};

int insertarAlFinalALU(TDASimVec* sv, void* ele)
{
    void* temp;

    if(sv->ce==sv->maxEle){
        sv->maxEle += 1;
        temp= realloc(sv->vec,sv->maxEle * sv->tamEle);
        if(!temp)return 0;

        sv->vec=temp;
    }
    memcpy((char*)sv->vec + sv->ce *sv->tamEle,ele,sv->tamEle);
    sv->ce++;
   return 1;
}

TDASimVec* ordenarALU(TDASimVec* sv, int cmp(const void*a, const void* b))
{
    qsort(sv->vec,sv->ce,sv->tamEle,cmp);

  return sv;
}

TDASimVec* agruparALU(TDASimVec* sv, int cmp(const void*, const void*), int fagrup(void*dest, const void* origen))
{
TDASimVec* aux;
int i,result;
void* finalPos;
    // [1,2,3,4,5] = SV
    // [1] = AUX
    aux=crearTDASimVecALU(sv->tamEle);
    if(!aux)return 0;
    result=insertarAlFinalALU(aux,sv->vec);
    if(result==0)printf("error al insertar");

    for(i=1; i<sv->ce; i++){

        finalPos=(char*)aux->vec + (aux->ce-1)*aux->tamEle;

        if(cmp(finalPos,(char*)sv->vec + i * sv->tamEle)==0){

            fagrup(finalPos,(char*)sv->vec + i * sv->tamEle);

        }else{
            insertarAlFinalALU(aux,(char*)sv->vec + i * sv->tamEle);
        }
    }
  sv->ce     = aux->ce;
  sv->maxEle = aux->maxEle;
  free(sv->vec);
  sv->vec    = aux->vec;
  free(aux);
  return sv;
}

void destruirALU(TDASimVec* sv)
{
    free(sv);
    sv->maxEle=0;
    sv->tamEle=0;
    sv->ce=0;

};
