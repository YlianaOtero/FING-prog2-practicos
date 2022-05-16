# include <stdio.h>
// En este práctico se asume definido el tipo para enteros sin signo (naturales):
typedef unsigned int uint;

// Considere la siguiente representación para un árbol binario de Naturales:
struct nodoAB {
    uint elem;
    nodoAB * izq, * der;
};

typedef nodoAB * AB ;

// (a) ¿Cómo representaría al árbol vacío con dicha representación?
AB crearAB() { // esta función crea un arbol vacío nuevo.
    AB nuevo = NULL;
    return NULL;
};

// (b) Utilice la representación dada para implementar las siguientes operaciones:
// I. función consArbol: que retorna un árbol no vacío a partir de un natural y otros dos árboles.
AB consArbol(uint nat, AB arbol0, AB arbol1) {
    AB nuevo = new nodoAB;
    nuevo->elem = nat; // la letra no especifica donde colocar al natural,
    nuevo->izq = arbol0; // ni en qué orden colocar a los arboles.
    nuevo->der = arbol1;
    return nuevo;
};

// II. función contarElems: que recibe un árbol y retorna la cantidad de elementos del mismo.
uint contarElems(AB arbol) {
    if (arbol == NULL) return 0;
    else return 1 + contarElems(arbol->izq) + contarElems(arbol->der);
};

// III. función contarHojas: que recibe un árbol y retorna la cantidad de hojas (nodos cuyos ambos
// subárboles son vacíos) del mismo.
uint contarHojas(AB arbol) {
    if (arbol == NULL) return 0; // caso base: arbol vacío
    else if (arbol->izq == NULL && arbol->der == NULL) return 1; // caso base: arbol hoja
    else return contarHojas(arbol->izq) + contarHojas(arbol->der);
};

// IV. función altura: que recibe un árbol y retorna la altura del mismo. Si el árbol es vacío su altura es 0.

// función auxiliar
uint max(uint a, uint b) { 
    if (a >= b) return a;
    else return b;
};

uint altura(AB arbol) {
    if (arbol == NULL) return 0;
    else return 1 + max(altura(arbol->izq), altura(arbol->der));
};

// V. función copiar: que recibe un árbol y retorna una copia limpia (que no comparte registros de
// memoria) del mismo.
AB copiar(AB arbol) {
    if (arbol == NULL) return NULL;
    else {
        AB nuevo = new nodoAB;
        nuevo->elem = arbol->elem;
        nuevo->izq = copiar(arbol->izq);
        nuevo->der = copiar(arbol->der);
        return nuevo;
    }
};

// VI. procedimiento liberarArbol: que recibe un árbol y elimina del mismo todos los nodos, liberando
// la memoria asociada a cada uno de ellos.
void liberarArbol(AB arbol) {
    if (arbol != NULL) {
        liberarArbol(arbol->izq);
        liberarArbol(arbol->der);
        delete arbol;
    };
};

// (c) La estructura que devuelve su solución de consArbol, ¿comparte memoria con los parámetros? En
// caso afirmativo, ¿qué problemas puede acarrear esto? 
/* Creo que comparte memoria con arbol0 y arbol1, pues apunté la izquierda de mi nuevo nodo que contiene 
a nat a la dirección del arbol0, y la derecha a la dirección de memoria del arbol1. Esto podría causar
problemas, pues quizá yo quiero modificar nodos dentro del arbol0 o del arbol1, pero quiero dejar el
nuevo arbol que creé con consArbol igual que antes, y al compartir memoria se cambiaría todo junto. */