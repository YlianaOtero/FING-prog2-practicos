# include <stdio.h>
// En este práctico se asume definido el tipo para enteros sin signo (naturales):
typedef unsigned int uint;

/* Considere la siguiente definición del tipo AG de árboles generales o finitarios de enteros representados con
árboles binarios con la semántica: primer hijo (pH) – siguiente hermano (sH): */
struct nodoAG {
    int dato;
    nodoAG * pH;
    nodoAG * sH;
};

typedef nodoAG * AG ;

/* Se quieren implementar las siguientes operaciones sobre árboles generales de enteros (representados con
la semántica primer hijo, siguiente hermano) no vacíos y sin elementos repetidos:
(a) arbolHoja: Dado un entero x retorna un árbol que sólo contiene a x (como una hoja). */


/* (b) esArbolHoja: Dado un árbol, retorna true si y solo si el árbol es un árbol hoja (tiene un solo elemento) */

// esHoja es una función auxiliar para esArbolHoja.
bool esHoja(AG t) {
    return t->pH == NULL;
};

bool esArbolHoja(AG t) {
    return esHoja && t->sH == NULL;
}

// (c) pertenece: Dados un árbol y un entero x, retorna true si y solo si x pertenece al árbol.
bool pertenece(uint x, AG t) {
    return t != NULL && (t->dato || pertenece(x, t->pH) || pertenece(x, t->sH));
};

/* (d) insertar: Dados un árbol y dos enteros h y p, inserta a h como el primer hijo de p en el árbol (hijo más
a la izquierda) si p pertenece al árbol y h no pertenece al árbol. En caso contrario la operación no tiene
efecto. */
void insertar (uint h, uint p, AG &g) {
    if (!pertenece(h, g)) {
        AG ptr_p = buscar(p, g);
        if (ptr_p != NULL) {
            AG nuevo = new nodoAG;
            nuevo->dato = h;
            nuevo->sH = ptr_p->pH;
            nuevo->pH = NULL;
            ptr_p->pH = nuevo;
        }
    }
}

/* (e) borrar: Dados un árbol y un entero x, elimina a x del árbol si es una hoja del árbol y no es la raíz
del mismo. En caso contrario la operación no tiene efecto. Al eliminar el elemento se debe liberar la
memoria asignada a él.
(f) borrarSub: Dados un árbol y un entero x, elimina a x del árbol, si pertenece al árbol y no es la raíz
del mismo. En caso contrario la operación no tiene efecto. Al eliminar el elemento se deberá liberar la
memoria asignada a los elementos que están en el subárbol dependiente de éste. */