/* Considere ahora que cuenta con la siguiente interfaz del tipo de datos TFecha. 
Implemente la interfaz utilizando la representación de fecha dada en la parte (a). Reescriba la función
main() haciendo uso de las operaciones implementadas en la interfaz y sin acceder a la representación. */

#include <stdio.h>
typedef unsigned int uint;
// Registro con dia d , mes m y año a
struct rep_fecha {
    unsigned int d ;
    unsigned int m ;
    unsigned int a ;
};
typedef struct rep_fecha * TFecha;
TFecha crear_fecha(unsigned int d , unsigned int m , unsigned int a); //Devuelve un 'TFecha' con dia d , mes m y año a
bool comparar_fechas(TFecha f1 , TFecha f2); // Devuelve true si f1 es anterior a f2, false en otro caso
unsigned int dia(TFecha fecha); //Devuelve el día correspondiente a fecha
unsigned int mes(TFecha fecha); //Devuelve el mes correspondiente a fecha
unsigned int anio(TFecha fecha); //Devuelve el año correspondiente a fecha

int main() {
    uint n = 4;
    TFecha fechas[n];
    TFecha aux[n];
    fechas[0] = crear_fecha(10, 10, 2022);
    fechas[1] = crear_fecha(15, 5, 2022);
    fechas[2] = crear_fecha(20, 11, 1992);
    fechas[3] = crear_fecha(7, 7, 1992);
    int i, j, min;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (comparar_fechas(fechas[j], fechas[min])) min = j;
        aux[i] = fechas[i];
        fechas[i] = fechas[min];
        fechas[min] = aux[i];
    };
    for (i = 0; i < n; i++) //imprimo arreglo
        printf("%d %d %d \n", dia(fechas[i]), mes(fechas[i]), anio(fechas[i]));
}

