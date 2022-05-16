/* Una variante importante de listas son las Listas con manejo explícito de posiciones (a veces llamadas Listas
Indizadas). Las operaciones más conocidas de estas listas ya fueron vistas anteriormente en el práctico 1 y
en este práctico se quiere implementarlas mediante estructuras pedidas en forma dinámica.
En estas listas, se manipulan los elementos mediante posiciones, generalizando la idea de los arreglos
para estructuras no acotadas. La posición del primer elemento es la posición 0. Se dice que la posición p
está definida si está entre 0 y m -1, siendo m la longitud de la lista. Utilizando la representación de lista
doblemente encadenada, implemente las siguientes operaciones: */

# include <stdio.h>
# include <iostream>

struct nodo {
    int elem ;
    nodo * sig ;
};

struct cabezal {
    nodo * primero ;
    nodo * actual ;
};

typedef cabezal * lista ;
typedef unsigned int nat;

/* (a) isDefined: dados un natural p y una lista l, retorna verdadero si, y solamente si, existe un elemento en
esa posición. */
bool isDefined (nat p, lista l) {
    bool res = false;
    if (l != NULL) {
        if (p == 0) res = true;
        else {
            int cont = 0;
            nodo * aux = l->primero;
            while (aux->sig != NULL && cont < p) {
                aux = aux->sig;
                cont++;
            };
            return  cont == p;
        };
    };
};

/* (b) insert: dados un entero x, un natural p y una lista l de longitud m, inserta a x en la lista. Si p no esta
definida, inserta a x en la posición m. En otro caso, inserta a x en la posición p y desplaza en una
posición los elementos que estuvieran en las posiciones siguientes */
void insert(int x, nat p, lista &l) {
    if (!isDefined(p, l)) {
        nodo * aux = l->primero;
        while (aux->sig != NULL) aux = aux->sig;
        nodo * nuevo = new nodo;
        nuevo->elem = x;
        nuevo->sig = NULL;
        aux->sig = nuevo;
    } else {
        int cont = 0;
        nodo * aux = l->primero;
        while (aux->sig != NULL && cont < p) {
            aux = aux->sig;
            cont++;
        };
        if (cont == p) {
            aux->elem = x;
        }
    }
}