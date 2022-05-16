# include <stdio.h>
# include ".../ej1_AB.cpp"
// En este práctico se asume definido el tipo para enteros sin signo (naturales):
typedef unsigned int uint;


/* Sea ABB un tipo que representa árboles binarios de búsqueda cuyos elementos son del tipo EstInfo.
EstInfo representa a un estudiante a partir de una identificación (ci) y la nota obtenida en un curso (nota).
Los nodos de ABB están ordenados según el campo ci. En la figura siguiente se presenta a continuación
la estructura de EstInfo y de ABB */

struct EstInfo {
    uint nota ; // dato
    int ci ; // clave
};
struct nodoABB {
    EstInfo info ;
    nodoABB * izq , * der ;
};

typedef nodoABB * ABB ;

// Se dispone de las operaciones maxABB y removerMaxABB definidas en el ejercicio anterior:

/* maxABB: recibe un ABB no vacío b y devuelve el elemento de máximo valor en b. */
int maxABB(ABB b) {
    if (b->der == NULL) return b->elem;
    else maxABB(b->der);
};

/* removerMaxABB: recibe un ABB no vacío b y elimina el elemento de máximo valor en b. */
void removerMaxABB(ABB &b) {
    if (b->der != NULL) removerMaxABB(b->der);
    else {
        ABB borrar = b;
        b = b->izq;
        delete borrar;
    }
}

/* Se debe implementar la función filtrado, sin definir procedimientos auxiliares, para obtener un nuevo árbol
solo con los estudiantes que superen una determinada nota */
ABB filtrado(ABB b, uint cota) {
    if (b == NULL) return NULL;
    else {
        ABB fizq = filtrado(b->izq, cota);
        ABB fder = filtrado(b->der, cota);
        EstInfo estudiante = b->info;
        if (estudiante->nota > cota) {
            ABB nuevo = new nodoABB;
            nuevo->izq = fizq;
            nuevo->der = fder;
            nuevo->info = estudiante;
            return nuevo;
        } else if (fizq == NULL) return fder;
        else if (fder == NULL) return fizq;
        else {
            EstInfo est = maxABB(fizq);
            removerMaxABB(fizq);
            ABB nuevo = new nodoABB;
            nuevo->izq = fizq;
            nuevo->der = fder;
            nuevo->info = est;
            return nuevo;
        }
    }
}

