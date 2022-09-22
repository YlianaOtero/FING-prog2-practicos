// Ejercicio 1 Promedio clase

// Suponga que a los estudiantes de programación 2 se les dice que su calificación final será el promedio de
// las cuatro calificaciones más altas de entre las cinco que hayan obtenido en el curso.

// (a) Escribir una función llamada PromClase con cinco parámetros de entrada (las calificaciones obtenidas)
// y un parámetro de salida (la calificación promedio), que realice dicho cálculo.

// (b) Escribir un programa principal (main()) que permita ejecutar la función PromClase. Dicho programa
// deberá leer de la entrada estándar (teclado) 5 calificaciones, invocar al procedimiento PromClase con
// dichos parámetros, y finalmente mostrar en la salida estándar (pantalla) el resultado.

# include <stdio.h>

int minimo(int a, int b, int c, int d, int e) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    if (e < min) min = e;
    return min;
}

float promClase(int nota1, int nota2, int nota3, int nota4, int nota5) {
    int sumaNota = nota1 + nota2 + nota3 + nota4 + nota5;
    int notaMin = minimo(nota1, nota2, nota3, nota4, nota5);
    float resultado = (sumaNota - notaMin)/4.0;
    return resultado;
}

int main() {
    int a, b, c, d, e;
    printf("Ingrese sus notas: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    printf("El promedio es: %.2f", promClase(a, b, c, d, e));
}
