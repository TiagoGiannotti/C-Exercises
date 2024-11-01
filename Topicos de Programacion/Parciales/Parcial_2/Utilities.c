#include "Utilities.h"
#include <string.h>
#include <ctype.h>


int leerArchFijo(char *nomArch)
{
    char linea[TAM_LINEA];

    tSensor sens[TAM_SENS];
    tSensor AuxSens;
    char* aux;
    int pos;
    int vecCont[TAM_SENS];
    FILE *pf = fopen(nomArch, "rt");

    if(pf == NULL)
        return 0;

    inicializarVector(vecCont,TAM_SENS);
    inicializarVectorSens(sens,TAM_SENS);

    while(fgets(linea, TAM_LINEA, pf))
    {
        if(trozarLinea(&AuxSens, linea)){

             //printf("%s - \t%.2f\t - %s\n",AuxSens.cod,AuxSens.val,AuxSens.status);

            aux = trim(AuxSens.status);

            strcpy(AuxSens.status,aux);

            aux = trim(AuxSens.cod);

            strcpy(AuxSens.cod,aux);

            pos = getNumericCod(&AuxSens); //DEV08 = 8

            strcpy((sens + pos)->cod, AuxSens.cod);

            if(strncmp(AuxSens.status,"READY",TAM_STATUS) == 0 ){

                (sens + pos)->val += AuxSens.val;

                vecCont[pos] ++;

            }

        }

     }


    printArr(sens,vecCont,TAM_SENS);



    fclose(pf);
    return 1;
}

int getNumericCod(tSensor* auxSens){
    int code;
    code = atoi(auxSens->cod+3);
    // printf("%d\n",code);
    return code;
}

void printArr(tSensor* arr, int* count, size_t ce) {
    size_t i;
    float prom;
    for (i = 0; i < ce; i++) {

        if((arr + i)->val != 0){

             prom= (arr+i)->val / *(count+i);

            printf("%s\t - %.2f\t\n", (arr + i)->cod, prom);

        }
        else if(*(count+i) == 0 && strcmp((arr+i)->cod," "))

            printf("%s -Sin informacion confiable\n", (arr + i)->cod);
    }
}




void inicializarVector(int *vec, size_t ce) {
    size_t i;
    for (i = 0; i < ce; i++) {
        *(vec + i) = 0;
    }
}

void inicializarVectorSens(tSensor *arr, size_t ce) {
    size_t i;
    for (i = 0; i < ce; i++) {
        (arr + i)->val = 0;
        strcpy( (arr + i)->cod," ");
    }

    //printf("%s - \t%.2f\n", (arr + i)->cod, (arr + i)->val);
}


int trozarLinea(tSensor * auxSens, char* linea){

     char* posCampo = linea;


    if( strlen(linea) != TAM_LINEA - 1) return 0;

     posCampo = strrchr(linea ,'\n');

      if (posCampo == NULL) {
        return 0; // Retornar error si no se encuentra \n
    }

    *posCampo ='\0'; //piso el \n

    posCampo -= TAM_STATUS;
    strcpy(auxSens->status, posCampo);
    *posCampo ='\0';

    posCampo -= TAM_VAL;
    sscanf(posCampo,"%f", &auxSens->val);
    *posCampo ='\0';

    posCampo -= TAM_COD;
    strcpy(auxSens->cod, posCampo);

    return 1;


}

char* trim(char* str){

    char* end;

    // ELIMINAMOS LOS ESPACIOS DEL INICIO
    while(*str == ' '){
        str++;
    }

    // ELIMINAMOS ESPACIOS AL FINAL
    end = str + strlen(str) - 1;

    while(end > str && *end == ' '){
        end--;
    }

    *(end+1) = '\0';

    return str;
}














