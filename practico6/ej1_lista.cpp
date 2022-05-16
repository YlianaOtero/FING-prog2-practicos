#include <stdio.h>
/* Considere el siguiente conjunto de operaciones. Las mismas especifican el TAD Lista de enteros (que
presenta el mismo comportamiento LIFO que una Pila). */
/*

// Crea la lista vacía. 
LEnt null () ;

// Inserta el entero x al principio de la lista.
void insertar ( int x , LEnt & l ) ;

// Verifica si la lista está vacía. 
bool esVacia ( LEnt l) ;

// Devuelve el primer elemento de una lista. Devuelve la memoria asociada .
// Pre: ! esVacia (l)
int primero ( LEnt l ) ;

// Devuelve la lista l sin su primer elemento.
//Pre : !esVacia (l) 
void resto ( LEnt & l ) ;

*/

/* (a) Dé una implementación completa (tipo y operaciones) para el TAD Lista no ordenada que garantice la
ejecución de las operaciones en O(1) */

struct nodo {
    int elem;
    nodo * sig;
};

typedef nodo * LEnt;

LEnt null() {
    return NULL;
};

void insertar (int x, LEnt &l) {
    nodo * nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig = l;
    l = nuevo;
};

bool esVacia (LEnt l) {
    return l == NULL;
};

//Precondicion: l != NULL
int primero (LEnt l) {
    return l->elem;
};

//Precondicion: l!= NULL
void resto (LEnt &l) {
    nodo * aBorrar = l;
    l = l->sig;
    delete aBorrar;
};

/* (b) ¿Qué cambios realizaría si insFinal fuera parte del TAD? */
struct cabezal {
    nodo * ini, * fin;
};

typedef cabezal * LEnt;

LEnt null () {
    LEnt l = new cabezal;
    l->ini = NULL;
    l->fin = NULL;
    return l;
};

void insertar (int x, LEnt &L) {
    nodo * nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig = l->ini;
    l->ini = nuevo;
    if (l->fin == NULL) l->fin = nuevo;
};

bool esVacia (LEnt l) {
    return l->ini == NULL;
};

//Precondicion: l != NULL
int primero (LEnt l) {
    return l->ini->elem;
};

//Precondicion: l!= NULL
void resto (LEnt &l) {
    nodo * aBorrar = l->ini;
    l->ini = l->ini->sig;
    delete aBorrar;
};

void insFinal (int x, LEnt &l) {
    if (l->ini == NULL) insertar(x, l);
    else {
        nodo * nuevo = new nodo;
        nuevo->sig = NULL;
        if (l->fin != NULL) l->fin->sig = nuevo;
        else l->ini = nuevo;
        l->fin = nuevo;
    };
};
