#include "Examen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// Definimos el radio de la Tierra en kilómetros
#define R 6371.0f

int readFile(const char* namFile){

FILE* pf;

char linea[MAXLINE];
size_t i=0;
sEmb_2* pos;
float distance;

sEmb_2* array = malloc(sizeof(sEmb)*MAXVEC);
sEmb auxEmb;

    pf = fopen(namFile,"rt");

    if(!pf)return 0;

    while(fgets(linea,MAXLINE,pf)){

       if(trozarLinea(linea,&auxEmb)==1){

        //printf("%f - %f - %s\n",auxEmb.lat,auxEmb.longi,auxEmb.code);

//            CHEQUEO QUE NO ESTE EL CODIGO ANTES EN EL VECTOR

            pos = busquedaSecuencial(array,&auxEmb,i,sizeof(sEmb_2),cmp);

                if(pos != NULL){
            //si esta, calculo la distancia de la nueva pos, si es menor la reemplazo en el vector.

                   distance = haversine(auxEmb.lat,auxEmb.longi,pos->lat,pos->longi);


                    if(pos->dist == 0 || distance < pos->dist){
                        pos->dist  = distance;
                        }
                    pos->lat   = auxEmb.lat;
                    pos->longi = auxEmb.longi;

            }if(pos == NULL){

           // si no esta lo agrego: en que pos la agrego? al final
           if(i<MAXCODE){

            strcpy((array+i)->code,auxEmb.code);
           (array+i)->lat   = auxEmb.lat;
           (array+i)->longi = auxEmb.longi;
           (array+i)->dist  = 0;
            i++;

           }
         }

       }
    }

printArray(array,i);
free(array);
fclose(pf);
return 1;

}

int trozarLinea(char* linea,sEmb* auxEmb){

char* posCampo;


    //OBTENGO EL CODIGO
    posCampo = strrchr(linea,',');

    if(!posCampo)return 0;

    sscanf(posCampo+1,"%s",(auxEmb->code));
    *posCampo = '\0';

    //OBTENGO LA LONGITUD

    posCampo = strrchr(linea,',');

    if(!posCampo)return 0;

    sscanf(posCampo+1,"%f",&(auxEmb->longi));

    *posCampo = '\0';

    //OBTENGO LA LATITUD
     sscanf(linea,"%f",&(auxEmb->lat));

return 1;
}

// Función para convertir grados a radianes
float toRadians(float degree) {
    return degree * (M_PI / 180.0f);
}

// Función para calcular la distancia usando la fórmula de Haversine
float haversine(float lat1, float lon1, float lat2, float lon2) {
    // Convertir grados a radianes
    lat1 = toRadians(lat1);
    lon1 = toRadians(lon1);
    lat2 = toRadians(lat2);
    lon2 = toRadians(lon2);

    // Diferencias de coordenadas
    float dlat = lat2 - lat1;
    float dlon = lon2 - lon1;

    // Fórmula de Haversine
    float a = sinf(dlat / 2) * sinf(dlat / 2) +
              cosf(lat1) * cosf(lat2) * sinf(dlon / 2) * sinf(dlon / 2);
    float c = 2 * atan2f(sqrtf(a), sqrtf(1 - a));

    // Distancia
    float distance = R * c;
    return distance;
}

int cmp(const void* a, const void* b){

sEmb_2* x;
sEmb*   y;

 x = (sEmb_2*)a;
 y = (sEmb*)b;

 return strcmp(x->code,y->code);

}
void printArray(sEmb_2* array, size_t ce){

size_t i;

    for(i=0; i<ce; i++){
        printf("%f - %s\n",(array+i)->dist,(array+i)->code);
    }


}

void* busquedaSecuencial(void* array, void* value, size_t ce, size_t elemSize,int cmp(const void*,const void*)){

size_t i;

for(i=0; i<ce; i++){

    if(cmp(array+(i*elemSize),value)==0){

        return ((char*)array + (i*elemSize));
    }
}

return NULL;

}
