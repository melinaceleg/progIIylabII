#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

void mostrarPila(Pila* p)
{
    Pila auxPila;
    inicPila(&auxPila);
    printf("tope -- ");
    while (!pilavacia(*p))
    {
        printf("%i ", tope(*p));
        apilar(&auxPila,desapilar(p));
    }
    printf("-- base");
    while (!pilavacia(auxPila))
    {
        apilar(p,desapilar(&auxPila));
    }
}

/**
tengo que tener cuidado que para recorrer una pila DINAMICA al hacer desapilar ELIMINO NODOS, por lo tanto
no importa si la variable contenedora del primer nodo es por referencia o no, esto no lo evita
debo agregar a mi manual de usuario que las funciones de recorrido de la pila, utilice de parametro una pila
por REFERENCIA **/


int main()
{
    Pila p;
    inicPila(&p);
    apilar(&p,3);
    apilar(&p,5);
    apilar(&p,7);
    mostrarPila(&p);
    printf("\nvuelvo a mostrar la pila: ");
    mostrarPila(&p);

    return 0;
}
