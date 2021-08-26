#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define MAX 49

typedef struct
{
    int arreglo[50];
    int tope;
}Pila;

///acciones

void inicPila(Pila*);
void apilar(Pila*,int);
int desapilar(Pila*);
int tope(Pila);
int pilavacia(Pila);
void leer(Pila*);
void mostrar(Pila);


#endif // PILA_H_INCLUDED
