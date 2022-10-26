#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct {
      int nro_mesa;
      char DNI[9];
      char nombre_cliente[30];
      float total;
      float totalConDescuento;
  }Ticket;

typedef Ticket Telemento;

typedef struct nodoD
{
    Telemento dato;
    struct nodoD* ant;
    struct nodoD* sig;
}nodoD;


typedef struct
{
    nodoD* pri;
    nodoD* ult;
}Fila;

nodoD* crearNodoFila(Telemento, int);
void inicFila(Fila *);
void poneFila(Fila*, Telemento);
Telemento sacaFila(Fila*);
int Filavacia(Fila);
Telemento frente(Fila);
#endif // FILA_H_INCLUDED
