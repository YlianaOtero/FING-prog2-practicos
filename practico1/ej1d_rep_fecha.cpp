/*Vuelva a implementar la interfaz pero con la representación de fecha dada en la parte (b). Realice los
cambios necesarios en la función main() escrita en la parte (c)*/
#include <stdio.h>
typedef unsigned int uint;

struct rep_fecha {
unsigned int f ; // AAAAMMDD
};
typedef struct rep_fecha * TFecha;
TFecha crear_fecha(unsigned int f); //Devuelve un 'TFecha' formato aaaammdd
bool comparar_fechas(TFecha f1 , TFecha f2); // Devuelve true si f1 es anterior a f2, false en otro caso
unsigned int dia(TFecha fecha); //Devuelve el día correspondiente a fecha
unsigned int mes(TFecha fecha); //Devuelve el mes correspondiente a fecha
unsigned int anio(TFecha fecha); //Devuelve el año correspondiente a fecha

int main() {
    uint n = 4;
    TFecha fechas[n];
    TFecha aux[n];
    fechas[0] = crear_fecha(20221010);
    fechas[1] = crear_fecha(20220515);
    fechas[2] = crear_fecha(19921120);
    fechas[3] = crear_fecha(19920707);
    int i, j, min;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (comparar_fechas(fechas[j], fechas[min])) min = j;
        aux[i] = fechas[i];
        fechas[i] = fechas[min];
        fechas[min] = aux[i];
    };
    for (int i = 0; i < n; i++) {
        printf("%d/%d/%d\n", dia(fechas[i]), mes(fechas[i]), anio(fechas[i]));
}
}