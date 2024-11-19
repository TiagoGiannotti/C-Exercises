#define MAXLINE1 578
#define MAXLINE2 12
#define TAM 5
#define MAXVEC 50000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gbib.h"

int crearLotePruebaClientes_ALU(const char* nameFile){

FILE* pf;
sClientes vec[]={{1,"John McEnroe","1123512315",200.00},
                  {10,"Jimmy Connors","112355555",300.00},
                  {20,"Steffi Graf","11235545413",100.00},
                  {30,"Monica Seles","112354545",200.00},
                  {45,"Chris Evert","112357989",50.00},
                  {75,"Bjorn Borg","1123512134",300.00},
                  {80,"Billie Jean King","1123578923",10.00},
                  {90,"Gabriela Sabatini","112351111",100.00},
                  };
size_t i;
size_t ce = sizeof(vec)/sizeof(*vec);

pf = fopen(nameFile,"wt");

if(!pf)return 0;

    for(i=0; i<ce; i++){

        fprintf(pf,"%d|%s|%s|%.2f\n",(vec+i)->leg,(vec+i)->nom,(vec+i)->cod,(vec+i)->saldo);
    }

fclose(pf);
return 1;
}

int restaurarArchClientesALU(const char* archOri, const char* archDes){

FILE * pf1;
FILE * pf2;

char linea1[MAXLINE1];
char linea2[MAXLINE2];
sClientes* array1 = malloc(sizeof(sClientes)*MAXVEC);
sIndice*   array2 = malloc(sizeof(sIndice)*MAXVEC);
sClientes aux1;
sIndice   aux2;
size_t count1=0;
size_t count2=0;
int result;
    pf1 = fopen(archOri,"rt");
    if(!pf1)return 0;
    pf2 = fopen("perm.txt","rt");
    if(!pf2){fclose(pf1);
             return 0;}

    while(fgets(linea1,MAXLINE1,pf1)&& fgets(linea2,MAXLINE2,pf2)){

        if(trozarArch1(linea1,&aux1)==1 && trozarArch2(linea2,&aux2)==1){
            //printf("%d|%s|%s|%.2f\n",aux1.leg,aux1.nom,aux1.cod,aux1.saldo);
            //printf("%d - %d \n",aux2.pos,aux2.nroRegistro);
            insertVec(array1,sizeof(sClientes),&aux1,&count1);
            insertVec(array2,sizeof(sIndice),&aux2,&count2);
        }
    }
//printf("%d - %d",count1,count2);
result=processArch(array1,count1,count2,array2);
if(result ==0) printf("error al procesar");

 fclose(pf1);
 fclose(pf2);
    return 1;
}

int trozarArch1(char* linea,sClientes* aux){

char* dirCampo;

 dirCampo=strrchr(linea,'\n');
 if(!dirCampo)return 0;
 *dirCampo='\0';

 dirCampo=strrchr(linea,'|');
 if(!dirCampo)return 0;
 sscanf(dirCampo+1,"%f",&(aux->saldo));
 *dirCampo='\0';

 dirCampo=strrchr(linea,'|');
 if(!dirCampo)return 0;
 strcpy((aux->cod),dirCampo+1);
 *dirCampo='\0';

 dirCampo=strrchr(linea,'|');
 if(!dirCampo)return 0;
 strcpy((aux->nom),dirCampo+1);
 *dirCampo='\0';

 sscanf(linea,"%d",&(aux->leg));

 return 1;

}

int trozarArch2(char* linea,sIndice* aux){
char* dirCampo;

    dirCampo = strrchr(linea,'\n');
    if(!dirCampo)return 0;
    *dirCampo= '\0';

    dirCampo -= TAM;
    sscanf(dirCampo,"%d",&(aux->nroRegistro));
    *dirCampo = '\0';

    dirCampo -= TAM;
    sscanf(dirCampo,"%d",&(aux->pos));
    *dirCampo = '\0';

    return 1;
}

void insertVec(void* arr, size_t elemSize,void* aux, size_t* count){

    memcpy((char*)arr + (*count)* elemSize,aux,elemSize);
    (*count)++;
}

int processArch(sClientes* array1,size_t count1, size_t count2, sIndice* array2){

FILE* pf;
int i;
int nroPos, nroReg;
float aux;

    //if(count1 != count2)return 0;
    if(count2 == 0) printf("No se encuentran registros");

    for(i=count2-1; i>=0; i--){

        nroPos = (array2+i)->pos;
        nroReg = (array2+i)->nroRegistro;

                           aux = (array1+nroPos)->saldo;
        (array1+nroPos)->saldo = (array1+nroReg)->saldo;
        (array1+nroReg)->saldo = aux;

    }


pf = fopen("OUTPUT.txt","wt");

if(!pf)return 0;

    for(i=0; i<count1; i++){
    printf("%d|%s|%s|%.2f\n",(array1+i)->leg,(array1+i)->nom,(array1+i)->cod,(array1+i)->saldo);
    fprintf(pf,"%d|%s|%s|%.2f\n",(array1+i)->leg,(array1+i)->nom,(array1+i)->cod,(array1+i)->saldo);
    }

fclose(pf);
return 1;


}




