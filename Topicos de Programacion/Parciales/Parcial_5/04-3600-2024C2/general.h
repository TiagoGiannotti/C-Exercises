#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

#define TAMCOD 11

typedef struct{
    char CodProducto[TAMCOD];
    int cantidad;
}tMovimiento;

typedef struct{
    int legajo;
    char noyAp[46];
}tEmpleado;


int mostrarMovimiento(void* v);
int cmpMovimiento(const void* a, const void* b);
int agruparMovimiento(void*dest, const void* origen);

int mostrarMovimientoALU(void* v);
int cmpMovimientoALU(const void* a, const void* b);
int agruparMovimientoALU(void*dest, const void* origen);


#endif // EXAMEN_H_INCLUDED
