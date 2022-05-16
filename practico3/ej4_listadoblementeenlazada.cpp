/* Una variante de listas encadenadas es la llamada Lista Doblemente Encadenada. En dicha implementa-
ción cada elemento de la lista referencia al siguiente elemento y al elemento anterior. */
# include <stdio.h>
# include <iostream>

struct nodo_doble {
    int elem ;
    nodo_doble * sig ;
    nodo_doble * ant ;
};

typedef nodo_doble * lista ;

// I. null: retorna una lista vacía
lista null() {
    lista nuevo = NULL;
    return nuevo;
};

// II. cons: dados un entero x y una lista l, retorna el resultado de insertar x al principio de l.
lista cons(int x, lista l) {
    lista nuevo = new nodo_doble;
    nuevo->elem = x;
    if (l == NULL) {
        l = nuevo;
        l->sig = l;
        l->ant = l;
    } else {
        l->ant->sig = nuevo;
        nuevo->ant = l->ant;
        l->ant = nuevo;
        nuevo->sig = l;
    };
    return nuevo;
};

// III. isEmpty: dada una lista l, verifica si l está vacía
bool isEmpty(lista l) {
    return (l == NULL);
};

// IV. isElement: dados un entero x y una lista l, verifica si x pertenece a l.
bool isElement(lista l, int x) {
    bool res = false;
    if (l != NULL) {
        while(l->sig != NULL && res == false) {
            if (l->elem == x) res = true;
            l = l->sig;
        };
        if (l->sig == NULL) {
            if (l->elem == x) res = true;
        };
    };
    return res;
};

// V. removeAll: dados un entero x y una lista l, retorna el resultado de eliminar todas las ocurrencias de x de l.
lista removeAll(int x, lista l) {
    lista res = new nodo_doble;
    if (l == NULL) res = l;
    else {
        lista aux = l;
        while(aux->sig != l) {
            if (aux->elem == x) {
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
                delete aux;
            } 
            aux = aux->sig;
        }
        if (aux->elem == x) { // estudio el ultimo elemento
            aux->ant->sig = l;
            aux->sig->ant = l->ant->ant;
            delete aux;
        }
    }
    return res;
};

// VI. insOrd: dados un entero x y una lista l ordenada, retorna el resultado de insertar x en l ordenadamente.
void insOrd(int e, lista &L) {
    lista nuevo = new nodo_doble;
    nuevo->elem = e;
    if (L == NULL) {
        nuevo->sig = nuevo;
        L = nuevo;
    } else {
        lista aux = L;
        if (L->elem > e) {
            nuevo->sig = L;
            while (aux->sig != L) aux = aux->sig;
            aux->sig = nuevo;
            L = nuevo;
        } else { //e va en el medio
            while (aux->sig->elem < e && aux->sig != L) aux = aux->sig;
            nuevo->sig = aux->sig;
            aux->sig = nuevo; 
        }
    }
};
