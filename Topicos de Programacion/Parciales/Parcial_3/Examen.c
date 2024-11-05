#include "Examen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readFile(const char* namFile,const size_t ce,void processArch(void*)){

FILE* pf;
int i=0;

void* buffer = malloc(ce* sizeof(sTicket));

      if(!buffer)return 0;

      pf = fopen(namFile,"rb");

      if(!pf) return 0;




    while(fread(buffer+(i*sizeof(sTicket)),sizeof(sTicket),1,pf) == 1){

            processArch(buffer+(i*sizeof(sTicket)));
            i++;
    }

    qsort(buffer,ce,sizeof(sTicket),cmp);
    fclose(pf);

    actFile(buffer,ce,namFile);
    free(buffer);

    return 1;
}


void processArch(void* buffer){

if(((sTicket*)buffer)->status == 1){

    ((sTicket*)buffer)->status = 0;

}else{

    printf("La entrada '%s' ya fue usada o no es valida \n",((sTicket*)buffer)->code);
}

}

int actFile(void* buffer,size_t ce, const char* nameFile){

FILE*pf;
int i;

pf = fopen(nameFile,"wb");

    if(!pf) return 0;

    for(i=0; i<ce; i++){

    fwrite(buffer+(i*sizeof(sTicket)),sizeof(sTicket),1,pf);

    }

return 1;

}

size_t getRecords(const char* namFile){

FILE* pf;

size_t bytes,tam;

    pf = fopen(namFile,"rb");

    if(!pf)return 0;

    fseek(pf,0,SEEK_END);

    bytes = ftell(pf); // CANTIDAD DE BYTES DEL ARCHIVO

    fclose(pf);

    tam = bytes / sizeof(sTicket); //CANTIDAD DE REGISTROS

   return tam;

}

int cmp(const void* a, const void* b){

sTicket* x;
sTicket* y;

 x = (sTicket*)a;
 y = (sTicket*)b;

return strcmp(x->code,y->code);
}

