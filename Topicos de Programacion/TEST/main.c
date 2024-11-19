#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nroRegistro;  // Número de registro del cliente
    char nombre[100];  // Nombre del cliente
    long telefono;     // Teléfono del cliente
    float saldo;       // Sueldo del cliente
} Cliente;

typedef struct {
    int nroRegistro;  // Número de registro a intercambiar
    int pos;          // Número de registro con el cual se intercambia
} Permutacion;

int main() {
    // Supongamos que tenemos los siguientes datos:
    Cliente array1[] = {
        {0, "John McEnroe", 1123512315, 300.00},
        {10, "Jimmy Connors", 112355555, 200.00},
        {20, "Steffi Graf", 11235545413, 10.00},
        {30, "Monica Seles", 112354545, 50.00},
        {45, "Chris Evert", 112357989, 300.00},
        {75, "Bjorn Borg", 1123512134, 200.00},
        {80, "Billie Jean King", 1123578923, 100.00},
        {90, "Gabriela Sabatini", 112351111, 100.00}
    };

    Permutacion array[] = {
        {0, 1},
        {1, 3},
        {2, 6},
        {3, 4},
        {4, 1},
        {5, 4},
        {6, 6},
        {7, 6}
    };

    int ce = 8;  // Número de permutaciones (es decir, el tamaño del arreglo `array`)

    // Realizamos los intercambios de sueldos
    for (int i = 0; i < ce; i++) {
        float aux;

        // Obtener los índices de los registros a intercambiar
        int registro1 = (array + i)->nroRegistro;  // Primer cliente a intercambiar
        int registro2 = (array + i)->pos;          // Segundo cliente con el cual se intercambia

        // Intercambiar los sueldos
        aux = (array1 + registro1)->saldo;        // Obtener el sueldo del primer cliente
        (array1 + registro1)->saldo = (array1 + registro2)->saldo;  // Asignar el sueldo del segundo cliente
        (array1 + registro2)->saldo = aux;        // Asignar el sueldo original del primer cliente al segundo
    }

    // Mostrar el resultado final
    for (int i = 0; i < 8; i++) {
        printf("%d|%s|%ld|%.2f\n", array1[i].nroRegistro, array1[i].nombre, array1[i].telefono, array1[i].saldo);
    }

    return 0;
}



