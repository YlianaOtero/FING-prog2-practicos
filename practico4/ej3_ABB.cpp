# include <stdio.h>
# include ".../ej1_AB.cpp"
// En este práctico se asume definido el tipo para enteros sin signo (naturales):
typedef unsigned int uint;

// Considere la siguiente representación para un árbol binario de búsqueda (ABB) de Naturales:
struct nodoABB {
    uint elem ;
    nodoABB * izq , * der ;
};

typedef nodoABB * ABB ;

/* Utilice la representación dada para implementar las siguientes operaciones:
(a) procedimiento insertarABB: que recibe un natural x, y un ABB b, e inserta x en b manteniendo su
cualidad de árbol binario de búsqueda. Si x pertenece al árbol la operación no tiene efecto. */
void insertarABB (uint x, ABB &b) {
    if (b == NULL) {
        ABB nuevo = new nodoABB;
        nuevo->elem = x;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        b = nuevo;
    } else if (x < b->elem) insertarABB(x, b->izq);
    else if (x > b->elem) insertarABB(x, b->der);
}

/* (b) función perteneceABB: que recibe un natural x y un ABB b y devuelve true si y solo si x es un elemento
del árbol b. */
bool perteneceABB(uint x, ABB b) {
    if (b == NULL) return false;
    else if (x == b->elem) return true;
    else if (x < b->elem) return perteneceABB(x, b->izq);
    else return perteneceABB(x, b->der);
}

/* (c) función maxABB: que recibe un ABB no vacío b y devuelve el elemento de máximo valor en b. */
int maxABB(ABB b) {
    if (b->der == NULL) return b->elem;
    else maxABB(b->der);
};

/* (d) procedimiento removerMaxABB: que recibe un ABB no vacío b y elimina el elemento de máximo valor
en b. */
void removerMaxABB(ABB &b) {
    if (b->der != NULL) removerMaxABB(b->der);
    else {
        ABB borrar = b;
        b = b->izq;
        delete borrar;
    }
}

/* (e) procedimiento removerABB: que recibe un natural x y un ABB b y elimina el elemento de valor x de b,
manteniendo su cualidad de ABB */
void removerABB(uint x, ABB &b) {
    if (b != NULL) {
        if (x == b->elem) {
            if (b->izq == NULL) {
                ABB borrar = b->der;
                delete borrar;
            } else if (b->der == NULL) {
                ABB borrar = b->izq;
                delete borrar;
            } else {
                b->elem = maxABB(b->izq);
                removerMaxABB(b->izq);
            }
        } else if (x < b->elem) removerABB(x, b->izq);
        else removerABB(x, b->der);
    }
}

/* (f) función k-esimo: que recibe un natural k y un ABB b y retorna el subárbol que tiene al k-ésimo menor
elemento de b como raíz. Si en b hay menos de k elementos o k es cero, la función debe retornar el
árbol vacío. Si k es 1, se refiere al menor elemento del árbol, si k es 2 al 2do elemento más pequeño
del árbol y así sucesivamente. La solución no puede visitar ningún nodo más de una vez. */

// procedimiento auxiliar para kesimo:
void kesimoAux(uint &k, ABB b, ABB &t) {
    t == NULL;
    if (k > 0 && t != NULL) {
        uint faltan = k;
        kesimoAux(faltan, b->izq, t);
        if (faltan > 0) {
            faltan--;
            if (faltan == 0) t = b;
            else kesimoAux(faltan, b->der, t)
        }
    }
}

ABB kesimo(uint k, ABB b) {
    if (k == 0 || b == NULL) return NULL;
    else {
        ABB t = NULL;
        kesimoAux(k, b, t);
        return t;
    }
}