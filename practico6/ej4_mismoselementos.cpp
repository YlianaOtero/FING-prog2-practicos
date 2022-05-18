/* Ejercicio 4 Ejercicio de examen Diciembre 2018
Se desea saber si una pila y una cola tienen exactamente los mismos elementos y fueron insertados en ellas
exactamente en el mismo orden. Para esto implemente la función mismosElementos usando las operaciones
de los TADs Pila y Cola. Al terminar, p y c deben quedar vacías. Los elementos de Pila y Cola son de un
tipo genérico que admite los usuales operadores de comparación.
bool mismosElementos ( Pila &p , Cola & c) ;
No se deben hacer comparaciones innecesarias. No se pueden usar funciones auxiliares. */

//Pila:
Pila nullPila();
void push(T t, Pila &p);
bool isEmptyPila(Pila p);
T pop(Pila p);
void pop(Pila &p); //T pop(Pila &p);

//Cola:
bool isEmptyCola(Cola c);
T frontCola(Cola c);
void dequeue(Cola &c);

bool mismosElementos (Pila &p, Cola &c) {
    Pila pilaaux = nullPila();

    while (!isEmptyCola(c)) {
        push(frontCola(c), pilaaux); //agarramos lo que esta en el frente de la cola y lo ponemos en la pila auxiliar
        dequeue(c); //sacamos el primer elemento de la cola
    };

    while (!isEmptyPila(p) && !isEmptyPila(pilaaux) && top(p) == top(pilaaux)) {
        pop(p); //vamos sacando los elementos a las pilas que tenemos,
        pop(pilaaux); //hasta que una (o ambas) sean vacias.
    };
    bool res = isEmptyPila(p) && isEmptyPila(pilaaux);

    while (!isEmptyPila(p)) pop(p);
    while(!isEmptyPila(pilaaux)) pop(pilaaux);

    return res;
};