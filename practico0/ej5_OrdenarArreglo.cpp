/* Escriba un procedimiento que recibe un arreglo de enteros y devuelve un nuevo arreglo que contiene a los
elementos del primero en orden ascendente. Indique qué algoritmos de ordenación utiliza. */

#include <stdio.h>

void OrdenarArr(int NuevoArr[10]) { //procedimiento para ordenar el arreglo mediante selection sort
    int i, j, min, aux;
    for (i = 0; i < 10-1; i++) { //i me deslizara las ventanas
        min = i; //a la izq de i, todo quedara ordenado
        for (j = i+1; j < 10; j++) //buscare el min dentro de la ventana a la der de i
            min = j;
        aux = NuevoArr[i]; //guardo para no perder este valor
        NuevoArr[i] = NuevoArr[min]; //swap
        NuevoArr[min] = NuevoArr[aux];
    }
}