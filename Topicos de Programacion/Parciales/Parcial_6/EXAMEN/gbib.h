#ifndef GBIB_H_INCLUDED
#define GBIB_H_INCLUDED
#define MAXNAME 65
#define MAXCOD  513

typedef struct{

int leg;
char nom[MAXNAME];
char cod[MAXCOD];
float saldo;

}sClientes;

typedef struct{
int pos;
int nroRegistro;
}sIndice;

int crearLotePruebaClientes(const char* nomArchivo);
int permutarArchClientes(const char* archOri, const char* archDes);
int restaurarArchClientes(const char* archOri, const char* archDes);

int crearLotePruebaClientes_ALU(const char* nameFile);
int permutarArchClientesALU(const char* archOri, const char* archDes);
int restaurarArchClientesALU(const char* archOri, const char* archDes);
int trozarArch1(char*linea1,sClientes* aux);
int trozarArch2(char* linea, sIndice* arr);
int processArch(sClientes* array1,size_t count1, size_t count2, sIndice* array2);
void insertVec(void* arr, size_t elemSize,void* aux, size_t*);
int cmpInt(const void*a,const void*b);
int insertarOrdenadamente(void *vec,void *valor,unsigned *ce, size_t tamElem,size_t tamMax,int cmp(const void *, const void *));
#endif // GBIB_H_INCLUDED
