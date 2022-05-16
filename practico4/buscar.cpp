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

AG buscar(uint x, AG t) {
    AG ptr_res = NULL;
    if (t != NULL) {
        if (t->dato == x) ptr_res = t;
        else {
            ptr_res = buscar(x, t->sH);
            if (ptr_res == NULL) ptr_res = buscar(x, t->pH);
        }
    }
    return ptr_res;
}
