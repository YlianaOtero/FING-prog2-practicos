/*Escriba un procedimiento que calcule e imprima en pantalla todos los números primos entre dos enteros
positivos A y B cualesquiera. */

#include <stdio.h>
using namespace std;

bool EsPrimo(int num) { //estudia si un numero es primo o no
    int cont = 2;
    int tope = (num/2) + 1;
    while( (cont < tope) && (num % cont != 0) ) cont++; //si el contador llega a tope, 
    return (tope == cont); //es porque no es divisible entre otro numero ademas de 1 y si mismo
}

void Solucion(int A, int B) {
    int cont = 0;
    for(int i = A; i < B; i++) {
        if(EsPrimo(i)) {
            printf("%d \n", i);
        }
    }
}

int main() {
    printf("Ingrese los extremos de un intervalo: ");
    int inf, max;
    scanf("%d %d", &inf, &max);
    printf("Los numeros primos en ese intervalo son: ");
    Solucion(inf, max);
    return 0;
}