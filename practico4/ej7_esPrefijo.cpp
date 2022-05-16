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

/* Defina una función recursiva esPrefijo que dada una lista de enteros y un árbol general de enteros, retorne
TRUE si y sólo si la lista es un prefijo de algún camino del árbol general, comenzando desde la raíz. Se dice
que la secuencia x es prefijo de la secuencia z si z es xy, esto es, la concatenación de x e y. Cualquiera
de las secuencias x, y, z pueden ser vacías. En particular si x es vacía es prefijo de cualquier secuencia, y
toda secuencia es prfijo de de sí misma. No se deben usar funciones o procedimientos auxiliares en este
ejercicio. Utilice la definición de lista presentada en el ejercicio 2. */
struct nodoLista {
    uint elem ;
    nodoLista * sig ;
};

typedef nodoLista * Lista ;

bool esPrefijo(Lista l, AG g) {
    if (l == NULL) return true;
    else if (g == NULL) return false;
    else if (l->sig == NULL && l->dato == g->dato) return true;
    else return (g->dato == l->dato && esPrefijo(l->sig, g->pH));
}