/*La siguiente es la especificación del módulo TInfo. Implemente el módulo de implementación de TInfo.*/

// info.h
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