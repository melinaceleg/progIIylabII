#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef int telemento;

typedef struct nodop {

  telemento dato;
  struct nodop* sig;
}nodop;

typedef struct nodop* Pila;
///cambiame el nombre "struct nodop *" a "Pila"


///acciones

void inicPila(Pila*); ///(nodop**)
void apilar(Pila*,int);
int desapilar(Pila*);
int pilaVacia(Pila);
int tope(Pila);
void leer(Pila*);
void mostrar(Pila);


#endif // PILA_H_INCLUDED
