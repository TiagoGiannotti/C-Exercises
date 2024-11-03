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





#endif // EXAMEN_H_INCLUDED
