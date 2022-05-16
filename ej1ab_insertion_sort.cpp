// (a) Implemente de forma recursiva la función ordenar utilizando la función auxiliar insertarOrdenado.
// (b) Implemente la función auxiliar insertarOrdenado utilizando recursión.
typedef unsigned int uint;
/* Ordena A [1.. n ] de manera creciente . */
void ordenar (float * A, uint n) {
    if (n > 1) {
        ordenar(A, n-1); //acá se aplica la recursión
        insertarOrdenado(A, n-1, A[n]);
    }
};

/* Inserta e en A [1.. n +1] de manera ordenada.
Precondición: n >= 0. Si n >= 1 = > A [1.. n ] está ordenado de manera creciente. A[n +1] es indeterminado.
Postcondición : A[1.. n +1] queda ordenado de manera creciente . */
void insertarOrdenado (float * A, uint n, float e) {
    if (n > 0 && A[n] > e) { //paso recursivo
        A[n+1] = A[n]; //swap
        insertarOrdenado(A, n-1, e); //recursion de cola
    } else A[n+1] = e;
};


