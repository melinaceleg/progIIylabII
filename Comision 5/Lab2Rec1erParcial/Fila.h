#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef char* Telemento;

typedef struct nodoD{
    Telemento dato;
    struct nodoD* ant;
    struct nodoD* sig;
}nodoD;


typedef struct {
    nodoD* pri;
    nodoD* ult;
}Fila;

///acciones - comportamiento

void inicFila(Fila*);
void poneFila(Fila*,Telemento);
Telemento sacaFila(Fila*);
Telemento frente(Fila);
int filaVacia(Fila);

#endif // FILA_H_INCLUDED
