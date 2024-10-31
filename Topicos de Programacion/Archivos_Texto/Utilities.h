#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#define MAXNAME 50
#define TAM_LEG  4
#define TAM_NAME 23
#define TAM_PROM 7
//TOTAL 34

#define MAXLINE 36
#define FORMATO "%4d%23s%7.2f\n" //ARCHIVO CON TEXTO FIJO
//#define FORMATO "%d|%s|%.2f\n"   //ARCHIVO CON TEXTO VARIABLE

typedef struct{

    int leg;
    char name[MAXNAME];
    float prom;

}student;


int crearLotePruebas(const char* nomArch);
int leerArchFijo(const char* nomArch);
int trozarArchFijo(student* stu,char * linea);



#endif // UTILITIES_H_INCLUDED
