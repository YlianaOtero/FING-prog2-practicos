/* Utilizando la representación para Lista Encadenada de Enteros del ejercicio 1, implemente las siguientes
funciones en forma iterativa y sin usar procedimientos auxiliares. Las soluciones retornadas no deben
compartir memoria con los parámetros. */
# include <stdio.h>
# include <iostream>
struct nodo {
    int elem ;
    nodo * sig ;
};

typedef nodo * lista ;
typedef unsigned int uint;

// (a) take: dado un natural i y una lista l, retorna la lista resultado de tomar los primeros i elementos de l.
lista take (lista L, uint i) {
    uint cont = 1;
    lista P = new nodo;
    while (L->sig != NULL && cont <= i) {
        lista nuevo = new nodo;
        nuevo->elem = L->elem;
        if (cont == 1) P = nuevo;
        L = L->sig;
        nuevo->sig = L;
        cont++;
    };
    return P;
};

// (b) drop: dado un natural i y una lista l, retorna la lista resultado de eliminar los primeros i elementos de l.
lista drop (lista L, uint i) {
    uint cont = 1;
    while (L->sig != NULL && cont <= i) {
        L = L->sig;
        cont++;
    };
    lista P = new nodo;
    while (L->sig != NULL) {
        lista nuevo = new nodo;
        nuevo->elem = L->elem;
        if (cont == i) P = nuevo;
        L = L->sig;
        nuevo->sig = L;
        cont++;
    };
    return P;
};

// (c) mergeSort: dadas dos listas ordenadas l y p, genera una lista intercalando ordenadamente ambas listas.
lista mergeSort (lista L, lista P) {
    lista res, dummy = new nodo;
    res = dummy;
    while (L != NULL && P != NULL) {
        res->sig = new nodo;
        res = res->sig;
        if (L->elem < P->elem) {
            res->elem= L->elem;
            L = L->sig;
        } else {
            res->elem = P->elem;
            P = P->sig;
        };
    };
    while (L != NULL) {
        res->sig = new nodo;
        res = res->sig;
        res->elem = L->elem;
        L = L->sig;
    };
    while (P != NULL) {
        res->sig = new nodo;
        res = res->sig;
        res->elem = P->elem;
        P = P->sig;
    }

    res->sig = NULL;
    res = dummy->sig;
    delete dummy;
    
    return res;
};

// (d) concat: dadas dos listas l y p, retorna una lista que contiene a los elementos de l y luego a los elementos de p, en el mismo orden. 
// Comparar con la solución recursiva.
lista concat (lista L, lista P) {
    lista res = new nodo;
    if (L == NULL && P == NULL) res = NULL;
    else {
        lista aux = res;
        while (L != NULL) {
            aux->elem = L->elem;
            aux->sig = NULL;
            L = L->sig;
            if (L != NULL || P != NULL) {
                aux->sig = new nodo;
                aux = aux->sig;
            };
        };

        while (P != NULL) {
            aux->elem = P->elem;
            aux->sig = NULL;
            P = P->sig;
            if (P != NULL) {
                aux->sig = new nodo;
                aux = aux->sig;
            };
        };
    };
    return res;
};