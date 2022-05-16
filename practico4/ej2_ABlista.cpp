# include <stdio.h>
# include ".../ej1_AB.cpp"
// En este práctico se asume definido el tipo para enteros sin signo (naturales):
typedef unsigned int uint;

/* Considere la representación para árbol binario de Naturales del ejercicio 1 y la siguiente representación de
Lista de Naturales: */

struct nodoLista {
    uint elem ;
    nodoLista * sig ;
};

typedef nodoLista * Lista ;

struct nodoAB {
    uint elem;
    nodoAB * izq, * der;
};

typedef nodoAB * AB ;

// (a) Utilícelas para implementar las siguientes funciones:
/* I. enOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la
recorrida en orden de b. */
void enOrdenRec(AB arbol, Lista &lista, Lista &last) {
    if (arbol != NULL) {
        enOrdenRec(arbol->izq, lista, last); // primero llamo recursivamente por la izquierda.

        // luego ejecuto la acción que quiero:
        if (lista == NULL) {
            lista = new nodoLista;
            lista->elem = arbol->elem;
            lista->sig = NULL;
            last = lista;
        } else {
            Lista sig = new nodoLista;
            sig->elem = arbol->elem;
            last->sig = sig;
            last = sig;
        }

        enOrdenRec(arbol->der, lista, last); // y después llamo recursivamente por la derecha.
    }
}

Lista enOrden(AB b) {
    Lista res = NULL;
    Lista ult = NULL;
    enOrdenRec(b, res, ult);
    return res;
};

// SOLUCIÓN VISTA EN CLASE:
// concatenar es una función recursiva auxiliar que concatena dos listas.
Lista concatenar(Lista l1, Lista l2) {
    if (l1 == NULL) return l2;
    else if (l1->sig == NULL) {
        l1->sig = l2;
        return l1;
    } else {
        l1->sig = concatenar(l1->sig, l2);
        return l1;
    }
}

// enOrden_clase es la resolución para enOrden que vimos en clase de práctico.
Lista enOrden_clase(AB b) {
    if (b== NULL) return NULL;
    else {
        Lista lizq = enOrden_clase(b->izq);
        Lista lraiz = new nodoLista;
        lraiz->elem = b->elem;
        lraiz->sig = enOrden_clase(b->der);
        return concatenar(lizq, lder);
    }
}

// También vimos un procedimiento para imprimir un arbol siguiendo enOrden:
void imprimir(AB b) {
    if (b != NULL) {
        imprimir(b->izq);
        printf("%d/n", b->elem);
        imprimir(b->der);
    }
}

// II. preOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la
// recorrida en pre orden de b
void preOrdenRec(AB arbol, Lista &lista, Lista &last) {
    if (arbol != NULL) {
        // primero ejecuto la acción que quiero:
        if (lista == NULL) {
            lista = new nodoLista;
            lista->elem = arbol->elem;
            lista->sig = NULL;
            last = lista;
        } else {
            Lista sig = new nodoLista;
            sig->elem = arbol->elem;
            last->sig = sig;
            last = sig;
        }

        preOrdenRec(arbol->izq, lista, last); // luego llamo recursivamente por la izquierda.
        preOrdenRec(arbol->der, lista, last); // y por último llamo recursivamente por la derecha.
    }
}

Lista preOrden(AB b) {
    Lista res = NULL;
    Lista ult = NULL;
    preOrdenRec(b, res, ult);
    return res;
};

// III. postOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la
// recorrida en post orden de b.
void postOrdenRec(AB arbol, Lista &lista, Lista &last) {
    if (arbol != NULL) {
        postOrdenRec(arbol->izq, lista, last); // primero llamo recursivamente por la izquierda.
        postOrdenRec(arbol->der, lista, last); // y después llamo recursivamente por la derecha.

        // por último ejecuto la acción que quiero:
        if (lista == NULL) {
            lista = new nodoLista;
            lista->elem = arbol->elem;
            lista->sig = NULL;
            last = lista;
        } else {
            Lista sig = new nodoLista;
            sig->elem = arbol->elem;
            last->sig = sig;
            last = sig;
        }
    }
}

Lista postOrden(AB b) {
    Lista res = NULL;
    Lista ult = NULL;
    postOrdenRec(b, res, ult);
    return res;
};

/* V. esCamino: que recibe un árbol b y una lista l, y retorna TRUE si y solo si l es igual a un camino
desde la raíz a un hoja de b. */

// esHoja es una función auxiliar para esCaminoAux.
bool esHoja(AB b) {
    return b->izq == NULL && b->der == NULL;
}

// esCaminoAux es una función recursiva auxiliar para esCamino.
bool esCaminoAux(AB b, Lista l) {
    if (b == NULL || l == NULL) return false;
    else if (b->elem != l->elem) return false;
    else if (l->sig == NULL && esHoja(b)) return true;
    else return esCaminoAux(b->izq, l->sig) || esCaminoAux(b->der, l->sig);
}

bool esCamino(AB b, Lista l) {
    if (b == NULL && l == NULL) return true;
    else return esCaminoAux(b, l);
}

/* V. caminoMasLargo: que recibe un árbol b y retorna una lista con los elementos del camino más
largo de b (desde la raíz a una hoja). En caso de haber más de un camino de igual longitud a la del
camino más largo, retorna cualquiera de ellos. */

// caminoMasLargoRec es un procedimiento recursivo auxiliar para caminoMasLargo.
void caminoMasLargoRec (AB b, Lista &l, int &largo) {
    if (b == NULL) {
        l = NULL;
        largo = 0;
    } else {
        Lista l1, l2;
        int largo1, largo2;
        caminoMasLargoRec(b->izq, l1, largo1);
        caminoMasLargoRec(b->der, l2, largo2);
        Lista nuevo = new nodoLista;
        nuevo->elem = b->elem;
    }
}

Lista caminoMasLargo(AB b) {
    Lista l;
    int largo;
    caminoMasLargoRec(b, l, largo);
    return l;
};

/* (b) Se dice que un árbol es perfecto si todas las hojas están en el mismo nivel, o sea, si todos los niveles
están completos. ¿Cuántos nodos tiene un árbol binario perfecto de altura h? Escriba una función
booleana que dados un árbol binario b y un natural h, retorne TRUE si y solo si b es un árbol perfecto de
altura h. Implemente dicha función sin usar operaciones auxiliares para calcular la cantidad de nodos
o la altura de un árbol. Cada nodo se puede visitar a lo sumo una vez y no se deben visitar nodos
innecesarios.

(c) ¿Cuántos nodos tiene como mínimo y cómo máximo el camino más largo desde la raíz a una hoja,
para un árbol binario de n nodos? Justifique.

(d) Se dice que un árbol es completo si todos los niveles están completos, excepto tal vez el más profundo
al que le pueden faltar nodos a la derecha. Escriba una función booleana que dados un árbol binario b
y un natural h, retorne TRUE si y solo si b es un árbol completo de altura h. Cada nodo se puede visitar
a lo sumo una vez y no se deben visitar nodos innecesarios. */