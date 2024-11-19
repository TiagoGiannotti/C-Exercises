#include <stdio.h>
#include <stdlib.h>
#include "gbib.h"

#define EXAMEN

#define ARCHCLIENTE     "clientes.txt"
#define ARCHCLIENTEPERM "clientesPermutado.txt"
#define ARCHCLIENTEREST "clientesRestaurado.txt"

#ifdef EXAMEN
   #define restaurarArchClientes    restaurarArchClientesALU
#endif // EXAMEN


int main()
{
    //Quite la creacion automatica del lote de prueba
    //para probar con sus propios lotes
    if (!crearLotePruebaClientes_ALU("CLIENTES_ALU.TXT")){
        printf("Ocurrio un error al intentar crear el lote de prueba");
        return 100;
    }
    ///Respetar siempre los prototipos entregados
    //if(!permutarArchClientes(ARCHCLIENTE, ARCHCLIENTEPERM)){
       // printf("Ocurrio un error al intentar permutar el archivo original");
        //return 100;
    else{
  //      if (!restaurarArchClientes(ARCHCLIENTEPERM, ARCHCLIENTEREST)){
  //          printf("Ocurrio un error al intentar reestablecer el archivo original");
 //       }
         if (!restaurarArchClientesALU(ARCHCLIENTEPERM, ARCHCLIENTEREST)){
            printf("Ocurrio un error al intentar reestablecer el archivo original");
        }

    }

    return 0;
}
