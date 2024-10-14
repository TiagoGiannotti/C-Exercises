#include "matematica.h"
int factorial (int valor){

    int i;
    int acumulador = 1;

    for (i=valor; i>0; i--){
        acumulador*=i;
    }
    return acumulador;
}


int ingresaNum (){
int num;

printf("Ingrese un Numero Natural: ");
scanf ("%d", &num);

return num;

}

int combinatorio (int nro1, int nro2,int factresta){

int n,m,resta;
int valor= 0;


    valor = nro1/(nro2 * factresta);

    return valor;

}
