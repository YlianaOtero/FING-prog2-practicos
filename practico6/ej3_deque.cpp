/* Una Deque es una cola con dos extremos, donde las inserciones y las supresiones pueden efectuarse en
cualquiera de ellos.

(a) Escribir un módulo de definición del TAD Deque no acotada de enteros que incluya procedimientos
para: 

I. Crear una Deque vacía (constructora). */
DequeEnt nullDQ (); //modo de uso: DequeEnt dq = nullDQ();

void nullDQ(DequeEnt &dq); //modo de uso: Deque dq; nullDQ(dq);

/* II. Realizar las inserciones y bajas permitidas (constructoras y destructoras respectivamente). */

// Inserta el entero x al comienzo de la cola DequeEnt dq
void insFrontDQ (int x, DequeEnt &dq);

// Inserta el entero x al final de la cola DequeEnt dq
void insRearDQ (int x, DequeEnt &dq);

// Remueve el primer elemento de la cola DequeEnt dq
// Si dq == NULL, la operación no tiene efecto.
void removeFrontDQ (DequeEnt &dq);

/* III. Obtener los elementos situados en los extremos (selectoras). */

// Devuelve el primer elemento de la cola DequeEnt dq
// PRE: dq != NULL
int frontDQ (DequeEnt dq);

// Devuelve el último elemento de la cola DequeEnt dq
// PRE: dq != NULL
int rearDQ (DequeEnt dq);

/* IV. Determinar si una Deque es vacía o no (predicado). */
bool isEmptyDQ (DequeEnt dq);

/* (b) Desarrolle una implementación completa de tal manera que todas las operaciones tengan O(1) de
tiempo de ejecución en el peor caso. */
struct nodoDQ {
    int dato;
    nodoDQ * sig;
    nodoDQ * ant;
};

typedef nodoDQ * DequeEnt;

struct headDQ {
    nodoDQ * front;
    nodoDQ * rear;
};

typedef headDQ * DequeEnt;

DequeEnt nullDQ () {
    DequeEnt dq = new headDQ;
    dq->front = dq->rear = NULL;
    return dq;
};

void nullDQ(DequeEnt &dq) {

};

void insFrontDQ (int x, DequeEnt &dq) {
    nodoDQ * nuevo = new nodoDQ;
    nuevo->dato = x;
    nuevo->ant = NULL;
    nuevo->sig = dq->front;

    if (dq->rear == NULL) dq->rear = nuevo;
    else dq->front->ant = nuevo;

    dq->front = nuevo;
};

void insRearDQ (int x, DequeEnt &dq) {
    nodoDQ * nuevo = new nodoDQ;
    nuevo->dato = x;
    nuevo->sig = NULL;
    nuevo->ant = dq->rear;

    if (dq->front == NULL) dq->front = nuevo;
    else dq->rear->sig = nuevo;

    dq->rear = nuevo;
};

bool isEmptyDQ (DequeEnt dq) {
    return dq->front == NULL;
};

int frontDQ (DequeEnt dq) {
    return dq->front->dato;
};

void removeFrontDQ (DequeEnt &dq) {
    nodoDQ * aBorrar = dq->front;
    if (dq->front != NULL) {
        dq->front = dq->front->sig;
        if (dq->front != NULL) dq->front->ant = NULL; //dq tiene al menos 2 elementos
        else dq->rear = NULL; //dq tiene un solo elemento
        delete aBorrar;
    };
}
