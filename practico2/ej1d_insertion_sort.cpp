//Transforme el algoritmo recursivo de la función auxiliar insertarOrdenado en iterativo.
typedef unsigned int uint;
void insertarOrdenado (float * A, uint n, float e) {
    while (n > 0 && A[n] > e) {
        A[n+1] = A[n];
        n--;
    };
    A[n+1] = e;
};