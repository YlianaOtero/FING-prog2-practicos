/* (a) Dada la siguiente representación de fecha, implemente una función main() que inicialice un arreglo de fechas 
(por ejemplo, con las fechas 10/10/2022, 15/5/2022 y 20/11/1992), lo ordene e imprima el resultado. */

#include <stdio.h>
typedef unsigned int uint;

// Registro con dia d , mes m y año a
struct rep_fecha {
    unsigned int d ;
    unsigned int m ;
    unsigned int a ;
};

int main() {
    rep_fecha aux, arr[100];
    uint n = 4;
    rep_fecha fecha[n];
    fecha[0] = {10, 10, 2022};
    fecha[1] = {15, 5, 2022};
    fecha[2] = {20, 11, 1992};
    fecha[3] = {7, 7, 1992};
    int i, j, min;
    for (i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++) 
            if ( (fecha[j].a < fecha[min].a) || (fecha[j].a == fecha[min].a && fecha[j].m < fecha[min].m) || (fecha[j].a == fecha[min].a && (fecha[j].d < fecha[min].d)) )
                min = j;
        aux = fecha[i];
        fecha[i] = fecha[min];
        fecha[min] = aux;
    }
    for (int i = 0; i < n; i++) {
        printf("%d/%d/%d\n", 
        fecha[i].d, fecha[i].m, fecha[i].a);
    }
}

