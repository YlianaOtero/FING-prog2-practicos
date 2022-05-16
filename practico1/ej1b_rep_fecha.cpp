/* Considere ahora la siguiente representación de fecha. 
Modifique el main() implementado en la parte (a) de manera que se adecúe a la nueva representación. */

#include <stdio.h>
typedef unsigned int uint;

struct rep_fecha {
unsigned int f ; // AAAAMMDD
};

int main() {
    rep_fecha aux;
    uint n = 4;
    rep_fecha fecha[n];
    fecha[0] = {20221010}; //cambio el formato de las fechas
    fecha[1] = {20220515};
    fecha[2] = {19921120};
    fecha[3] = {19920707};
    int i, j, min;
    for (i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++) 
            if (fecha[j].f < fecha[min].f) //ahora el if es mas parecido al alg. original del selection sort
                min = j;
        aux = fecha[i];
        fecha[i] = fecha[min];
        fecha[min] = aux;
    }
    for (int i = 0; i < n; i++) {
        printf("%d/%d/%d\n", //ajusto para que las fechas salgan con formato tipico de fecha, y no con el que estan
        fecha[i].f%100, (fecha[i].f/100)%100, fecha[i].f/10000); // DD/MM/AA
    }
}