#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define MAXCODE 16

typedef struct {

    char code [MAXCODE];
    int status;  //1 available or 0 used

}sTicket;

typedef struct {

    char code [MAXCODE];

}sAccess;



size_t getRecords(const char* namFile);
void processArch(void* buffer);
int readFile(const char* namFile,const size_t tam,void processArch(void*));
int cmp(const void* a, const void* b);
int actFile(void* buffer,size_t ce, const char* nameFile);

#endif // EXAMEN_H_INCLUDED
