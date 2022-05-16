/*Ejercicio 6 Factorial
La versión recursiva vista de factorial no presenta recursión de cola. Use un acumulador para obtener
una versión recursiva que presente recursión de cola.*/
#include <stdio.h>
typedef unsigned int uint;

// Devuelve el producto de factorial (n) por ' acum '. 
uint factAcum(uint n, int acum) {
    uint respuesta;
    if (n == 1 || n == 0) respuesta = 1 * acum;
    else respuesta = n * factAcum(n - 1, acum);
    return respuesta;
}

int main() {
    uint acum = 1; //el acumulador debe incializarse en 1 porque voy a acumular productos.
    uint num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    uint factorial = factAcum(num, acum);
    printf("El factorial de %d es %d", num, factorial);
    return 0;
}