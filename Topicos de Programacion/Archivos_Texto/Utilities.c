#include "Utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int crearLotePruebas(const char* nomArch){

    size_t i;
   student stu[]= {{10,"Tiago Giannotti",7.5},
                   {20,"Ricky Sidoso",1.5},
                   {30,"Maria Telechea",2.5},
                   {40,"Julieta Venegas",9}};

   size_t ce = sizeof(stu) / sizeof(stu[0]);

    FILE* pf;

        pf= fopen(nomArch,"wt");

        if(!pf){
            return 0;
        }

        for(i=0; i<ce; i++){
            fprintf(pf,FORMATO,stu[i].leg,stu[i].name,stu[i].prom);
        }

        fclose(pf);
        return 1;
}
int leerArchFijo(const char* nomArch){

    FILE* pf;

    student stu;

    char linea[MAXLINE];

        pf = fopen(nomArch,"rt");

        if(!pf){
            return 0;
        }

        while(fgets(linea,MAXLINE,pf) && trozarArchFijo(&stu, linea)){

        printf("%d\t - %s\t - %.2f\t \n", stu.leg, stu.name, stu.prom);

}




        fclose(pf);
        return 1;
}

int trozarArchFijo(student* stu, char * linea){

size_t tam = TAM_LEG + TAM_NAME + TAM_PROM;

char* dirCampo = linea + tam;



    if( (tam + 1) != strlen(linea)) return 0; //CHEQUEAMOS QUE AMBOS TAMAÑOS SEAN IGUALES

    *dirCampo ='\0'; //ELIMINAMOS EL SALTO DE LINEA

    dirCampo -= TAM_PROM; //7
     sscanf(dirCampo,"%f",&stu->prom);  //LECTURA PROMEDIO
    *dirCampo ='\0';

    dirCampo -= TAM_NAME; //23
    strcpy(stu->name,dirCampo); //LECTURA NOMBRE
    *dirCampo ='\0';

    dirCampo -= TAM_LEG; //4
    sscanf(dirCampo,"%d",&stu->leg); //LECTURA LEGAJO

    return 1;

}
