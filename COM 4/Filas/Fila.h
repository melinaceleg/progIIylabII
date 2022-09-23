#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdlib.h>
#include "Proceso.h"

typedef Proceso telementoF;

typedef struct nodoDF
{
    telementoF dato;
    struct nodoDF* anterior;
    struct nodoDF* siguiente;
}nodoDF;


typedef struct
{
    nodoDF* pri; ///info del primero
    nodoDF* ult; ///info del final
}Fila;



///comportamiento
void inicFila(Fila*);
void poneFila(Fila*,telementoF);
telementoF sacaFila(Fila*);
telementoF frente(Fila);
int filavacia(Fila);


#endif // FILA_H_INCLUDED
