// (a) Utilizando la representación para Lista Encadenada de Enteros del ejercicio 1, implemente los siguientes procedimientos de forma recursiva.
# include <stdio.h>
# include <iostream>
struct nodo {
    int elem ;
    nodo * sig ;
};

typedef nodo * lista ;

typedef unsigned int uint;

// I. insOrd: dados un entero x y una lista l ordenada, inserta a x en l ordenadamente.
void insOrd (int x, lista &L) {
    if (L == NULL || L->elem >= x) {
        lista nuevo = new nodo;
        nuevo->elem = x;
        nuevo->sig = L;
        L = nuevo;
    } else insOrd(x, L->sig);
};

// II. snoc: dados un entero x y una lista l, inserta a x al final de l.
void snoc (int x, lista &L) {
    if (L == NULL) {
        L = new nodo;
        L->elem = x;
        L->sig = NULL;
        return;
    };
    snoc(x, L->sig);
};

// III. removeAll: dados un entero x y una lista l, elimina a x de l.
void removeAll (int x, lista &L) {
    if (L != NULL) {
        if (L->elem == x) {
            L = L->sig;
            removeAll(x, L);
            return;
        };
    } else return; 
    removeAll(x, L->sig);
};

void printLista(lista list) {
    while (list != NULL) {
        printf("%d, ", list->elem);
        list = list->sig;
    };
    printf("\n");
};

int main() {
    lista miLista = new nodo;
    miLista->elem = 3;

    insOrd(2, miLista);
    insOrd(4, miLista);
    insOrd(5, miLista);
    insOrd(6, miLista);

    snoc(3, miLista);
    snoc(3, miLista);

    printLista(miLista);

    removeAll(3, miLista);
    printLista(miLista);

    return 0;
}  