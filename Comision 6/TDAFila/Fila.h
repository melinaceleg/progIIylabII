#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef char Telemento;

typedef struct nodoD
{
    Telemento dato;
    struct nodoD* ant;
    struct nodoD* sig;
}nodoD;


typedef struct {
    nodoD* pri;
    nodoD* ult;
}Fila;

///funciones
void inicFila(Fila*);
nodoD* crearNodo(Telemento);
void poneFila(Fila*,Telemento);
Telemento sacaFila(Fila*);
int filaVacia(Fila);
Telemento frente(Fila);



#endif // FILA_H_INCLUDED
