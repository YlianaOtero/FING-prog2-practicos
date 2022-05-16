/* Ejercicio 4 Es Palíndrome
Considere ahora que la frase se representa como un arreglo de caracteres implementado como char *frase.

(a) ¿Qué diferencias hay entre esta representación y la que utilizó en el Ejercicio 3?
char * frase lo usamos al no saber el largo, porque estamos utilizando memoria dinamica: el * es para trabajar con punteros.

(b) Escriba una función EsPalindrome que recibe una frase representada como un puntero a caracter y
devuelve TRUE si la misma es un palíndrome, FALSE en otro caso. */

#include <stdio.h>
#include <string.h>
bool EsPalindrome(char * frase) {
    int largo = strlen(frase);
    int i = 0;
    while (frase[i] == frase[largo - i - 1] && i < (largo/2)) i++;
    return i == largo/2;
}

int main() {
    char * frase;
    frase = new char;
    printf("Ingrese una frase: ");
    gets(frase);
    bool respuesta;
    if (EsPalindrome(frase)) {
        printf("Esa frase es un palindrome");
    }
    else printf("Esa frase no es un palindrome");
  
    return 0;
}