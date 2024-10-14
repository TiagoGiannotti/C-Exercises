#include "stdio.h"
#include "..\..\Bibliotecas\matematica.h"


int main()
{
    int n,m,valorM,valorN,resta,factresta;

    n=ingresaNum();
    while(n<0){
        n=ingresaNum();
    }

    m=ingresaNum();
    while(m<n){
        m=ingresaNum();
    }

    valorM=factorial(m);
    valorN=factorial(n);

    resta= m-n;

    factresta=factorial(resta);

    printf("el numero combinatorio es: %d",factresta);

    return 0;
}
