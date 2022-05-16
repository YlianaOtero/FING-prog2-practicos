# include <stdio.h>
//Considere la representación para una Lista Encadenada de Enteros que se presenta:

struct nodo {
    int elem ;
    nodo * sig ;
};

typedef nodo * lista ;

/* (a) Implemente las siguientes funciones o procedimientos en forma iterativa y sin usar procedimientos auxiliares. 
En el caso de inserciones o eliminaciones se debe modificar los parámetros de entrada y compartir memoria con los mismos */

// I. last: dada una lista no vacía, retorna su último elemento.
int last (lista L) {
    while (L->sig != NULL) L = L->sig;
    return L->elem;
};

// II. average: dada una lista no vacía, retorna el promedio de sus elementos
double average (lista L) {
    int cant = 1; //cantidad de elementos en la lista
    int suma = L->elem; //va sumando los elementos
    while (L->sig != NULL) {
        L = L->sig;
        suma = suma + L->elem;
        cant++;
    };
    return (suma/cant);
};


void insOrd (int x, lista &l) {
    lista nuevo = new nodo;
    nuevo->elem = x;

    if (l == nullptr || l->elem > x) {
        nuevo->sig = l;
        l = nuevo;
        return;
    }

    lista aux = l;
    while (aux->sig != nullptr && aux->sig->elem < x) {
        aux = aux->sig;
    }

    nuevo->sig = aux->sig;
    aux->sig = nuevo;
}

// IV. snoc: dados un entero x y una lista l, inserta x al final de l.
void snoc (int x, lista L) {
    lista nuevo = new nodo;
    nuevo->elem = x;
    nuevo->sig = NULL;
    if (L == NULL) L = nuevo;
    else {
        while (L->sig != NULL) L = L->sig;
        L->sig = nuevo;
    };
};

// V. removeAll: dados un entero x y una lista l, elimina a x de l.
void removeAll(int x, lista &L) {
    while (L != NULL && L->elem == x) {
        lista P = L;
        L = L->sig;
        delete P;
    };
    if (L != NULL) {
        lista P = L;
        while (P->sig != NULL) { 
            if  (P->sig->elem != x) P = P->sig;
            else {
                lista borrar = P->sig;
                P->sig = P->sig->sig;
                delete borrar;
            };
        };
    };  
};

/* VI. isIncluded: dadas dos listas l y p, verifica si l está incluida en p. Una lista l1 está incluida en l2 si
y sólo sí existen dos listas, l3 y l4, tal que cumplen que l2 = l3l1l4. Tenga en cuenta que las listas li,
con i ∈ {1, ..., 4} pueden ser vacías */
bool isIncluded (lista L, lista P) {
    bool res = false;
    if (L == NULL) res = true;
    else {
        lista itera_L, itera_P;
        while (P != NULL && !res) {
            while (P != NULL && P->elem != L->elem) P = P->sig;
            itera_P = P;
            itera_L = L;
            while (itera_P != NULL && itera_L != NULL && itera_P->elem == itera_L->elem) {
                itera_P = itera_P->sig;
                itera_L = itera_L->sig;
            };
            res = itera_L == NULL;
            if (P != NULL) P = P->sig;
        };
    };
    return res;
};

bool isPrefix (lista L, lista P) {
    if (L == NULL) return true;
    else if (P == NULL) return false;
    else return (L->elem == P->elem && isPrefix(L->sig, P->sig));
};

// si quisiera hacer esta funcion recursiva:

bool isIncludedRec (lista L, lista P) {
    if (L == NULL) return true;
    else if (P == NULL) return false;
    else return (L->elem == P->elem && isPrefix(L->sig, P->sig)) || isIncluded(L, P->sig);
};



/* (b) Analice las operaciones anteriores indicando cuáles son totales y cuáles parciales. ¿Es posible en cada
caso pensar en ambas variantes (total y parcial)?. /*

/* I. y II. son parciales porque solo tienen sentido si la lista es no vacía.
El resto son totales porque aplican para todo el dominio de listas. */

void printLista(lista list) {
    while (list != nullptr) {
        printf("%d, ", list->elem);
        list = list->sig;
    }
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