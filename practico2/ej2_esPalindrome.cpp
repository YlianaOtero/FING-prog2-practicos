//Implemente un algoritmo recursivo que determina si un string es palíndrome. El string está representado en un arreglo.
typedef unsigned int uint;
bool esPalindrome(char * f, uint ini, uint fin) { //función auxiliar
    return fin <= ini || (f[ini] == f[fin] && esPalindrome(f, ini+1, fin-1)); //la primer condición es el paso base
};

bool esPalindrome(char * frase, uint largo) {
    return largo <= 1 || esPalindrome(frase, 0 , largo-1);
};