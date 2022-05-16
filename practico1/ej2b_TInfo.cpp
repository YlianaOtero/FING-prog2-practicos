/*La siguiente es la especificación del módulo TInfo. Implemente el módulo de implementación de TInfo.
Implemente otro módulo que use el tipo TInfo, por ejemplo, para almacenar pares (edad, altura) de
un registro pediátrico. En particular, cree 3 variables de tipo TInfo que contengan los valores (3,67.1),
(5,98.3) y (7,103.5) y luego imprima el contenido de cada una de ellas.*/
# ifndef _INFO_H
# define _INFO_H

typedef unsigned int uint;

struct _rep_info {
  uint natural;
  double real;
};

/* Representación de TInfo */
typedef struct _rep_info * TInfo;

/* Operaciones de TInfo */
/*Devuelve un ' TInfo ' compuesto por ' natural ' y ' real '.*/
TInfo crearInfo (uint natural , double real) {
    TInfo nuevo = new _rep_info;
    (*nuevo).natural = natural;
    (*nuevo).real = real;
    return nuevo;
};

/*Devuelve el componente natural de ' info '.*/
uint natInfo ( TInfo info )  {
    uint compNat = (*info).natural;
    return compNat;
};

/*
Devuelve el componente real de ' info '.
*/
double realInfo ( TInfo info )  {
    double compReal = (*info).real;
    return compReal;
};
# endif

typedef struct TInfo * RPediatrico;

struct RPediatrico {
    TInfo Registro[3];
};
RPediatrico crearPediatrico () {
    RPediatrico nuevo = new TInfo;
    return nuevo;
};

//con TInfo directamente:
TInfo RPed1 = crearInfo(3,67.1);
TInfo RPed2 = crearInfo(5,98.3);
TInfo RPed3 = crearInfo(7,103.5);

