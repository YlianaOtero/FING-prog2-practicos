/*Ejercicio 4 Máximo Común Divisor
Implemente un algoritmo recursivo que calcule el máximo común divisor de dos enteros positivos.*/
// OBS mia: MCD(a,0) = a: MCD(a, b) = (b, a mod b)

#include <stdio.h>
typedef unsigned int uint;

uint MCD(uint a, uint b) {
    uint respuesta;
    if (a == 0 && b != 0) respuesta = b;
    else if (b == 0 && a != 0) respuesta = a;
    else if (b == a && b != 0) respuesta = a;
    else {
        respuesta = MCD(b, a % b);
    };
    return respuesta;
}


int main() {
    uint a = 60;
    uint b = 48;
    uint mcd = MCD(a, b);
    printf("%d", mcd);
}