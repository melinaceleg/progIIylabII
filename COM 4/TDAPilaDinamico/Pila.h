#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdlib.h>

typedef int telemento;

typedef struct nodo
{
    telemento dato;
    struct nodo* siguiente;
}nodo;

typedef nodo* Pila; ///alias


///comportamiento - funciones

void inicPila(Pila*);
void apilar(Pila*, telemento);
telemento desapilar(Pila*);
telemento tope(Pila);
int pilavacia(Pila);


#endif // PILA_H_INCLUDED
