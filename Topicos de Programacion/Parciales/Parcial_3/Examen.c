#include "Examen.h"
#include <stdio.h>
#include <stdlib.h>

int readFile(const char* namFile,const size_t tam,void processArch(void*)){

FILE* pf;

void* buffer = malloc(tam* sizeof(sTicket));

      if(!buffer)return 0;

      pf = fopen(namFile,"rb");

      if(!pf) return 0;


      while(fread(buffer,tam,1,pf)){

            processArch(buffer);
      }

    fclose(pf);
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
