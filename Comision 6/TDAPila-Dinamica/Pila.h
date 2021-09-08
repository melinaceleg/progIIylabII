#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct nodop
{
    int dato;
    struct nodop* sig;
}nodop;

typedef struct nodop* Pila;
///cambiame el nombre de "struct nodop*" a "Pila"



///acciones
void inicPila(nodop**);
void apilar(Pila*,int); ///nodop **
int desapilar(Pila*); ///nodop*
int pilaVacia(Pila); ///nodop*
int tope(Pila);
void leer(Pila*);
void mostrar(Pila);




#endif // PILA_H_INCLUDED
