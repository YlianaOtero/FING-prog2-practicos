/*Ejercicio 5 Torres de Hanoi
Escenario: existen tres cilindros verticales, A, B y C, en los que es posible insertar discos. En el cilindro
A hay n discos todos de diferente tamaño, colocados en orden de tamaño con el más chico arriba. Los
otros dos cilindros están vacíos. El problema es pasar la torre de discos al cilindro C usando como único
movimiento elemental el cambio de un disco de un cilindro a otro cualquiera, sin que en ningún momento
un disco vaya a colocarse encima de otro más chico que él. La Figura 2 presenta los estados inicial y
final de este problema para 3 discos.
Implememte un algoritmo para imprimir las secuencias de movimientos elementales que resuelvan el
problema de las torres de Hanoi, de cualquier tamaño. Los movimientos elementales son de la forma: MOVER
DISCO i DEL cilindro x AL cilindro y. */
#include <stdio.h>
typedef unsigned int uint;
void hanoi(uint n) {
    hanoiRec(n, A, B, C);
}
void hanoiRec(uint n, char origen, char aux, char dest) {
    if (n > 0) {
        hanoiRec(n-1, origen, dest, aux);
        printf("%d %c %c \n", n, origen, dest);
        hanoiRec(n-1, aux, origen, dest);
    }
}