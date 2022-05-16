/*Se tiene una disposición de n vasos, donde n es par. Los vasos de la primera mitad están llenos y los de
la segunda mitad están vacíos. Se quiere dejar los vasos alternados: los vasos de las posiciones impares
deben quedar llenos y los de las posiciones pares deben quedar vacíos. Sólo se permite verter el contenido
de vasos en otros (es decir, no se puede desplazar vasos).
Implemente un algoritmo recursivo que resuelva el problema. En la siguiente especificación el valor true
representa un vaso lleno y el valor false un vaso vacío.*/

typedef unsigned int uint;
uint inf, sup, n;

/* Modifica V. Solo se permite intercambio entre posiciones.
Precondición: n % 2 == 0
V[1.. n /2] = {true} , V [n /2 + 1.. n] = {false}.
Postcondición: V[i] = true si y solo si i%2 == 1. */
void vasos (bool * V , uint n) {
    vasosRec(V, inf, sup);
};

void vasosRec(bool * V, uint inf, uint sup) {
    if (sup == inf + 3) {
        V[inf + 1] = false;
        V[sup - 1] = true;
    } else vasosRec(V, inf + n, sup-n);
};