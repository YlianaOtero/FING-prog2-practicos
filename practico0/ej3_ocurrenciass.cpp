// Ejercicio 3 Ocurrencias

// Se quiere implementar una función que cuente la cantidad de veces que una letra aparece en una frase.
// La frase se representa como un arreglo de caracteres, y dado que se conoce que el largo máximo de
// una frase es de 100 caracteres, la frase se implementa como char frase[100]. Usando esta representación
// escriba una función Ocurrencias que recibe una frase, un natural llamado largo que representa el número
// de caracteres en la frase, y el caracter a buscar (almacenado en la variable letra), y devuelve el número de
// ocurrencias del carácter letra en el arreglo frase.

#include <stdio.h>
#include <ctype.h>

int Ocurrencias(char frase[100], int largo, char letra) {
    int cant = 0;
    char ucletra = toupper(letra); 
    for (int i = 0; i < largo; i++) {
        if (toupper(frase[i]) == ucletra) cant++; 
    }
    return cant;
}

int main() {
    char frase[100];
    char letra;
    
    printf("Ingrese su frase: ");
    gets(frase);

    printf("Ingrese una letra: ");
    scanf("%c", &letra);
    
    int resultado = Ocurrencias(frase, 99, letra);
    printf("%d", resultado);
}
