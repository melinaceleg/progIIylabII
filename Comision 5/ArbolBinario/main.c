#include <stdio.h>
#include <stdlib.h>

typedef struct nodoA
{
    int dato;
    struct nodoA* izq;
    struct nodoA* der;
} nodoA;

nodoA* crearNodo(int dato)
{
    nodoA* nuevo = (nodoA*)malloc(sizeof(nodoA));
    nuevo->dato = dato;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;
}

int cantGrad1(nodoA* A)
{
    if (A!= NULL)
    {
        if ((A->izq != NULL && A->der == NULL) || (A->izq == NULL && A->der != NULL))
        {
            return 1 + cantGrad1(A->izq) + cantGrad1(A->der);
        }
        else
            return cantGrad1(A->izq) + cantGrad1(A->der);
    }
    else
        return 0;
}




int main()
{
    nodoA* arbol = NULL;
    arbol = crearNodo(4);
    arbol->izq = crearNodo(7);
    arbol->izq->izq = crearNodo(2);
    arbol->izq->izq->izq = crearNodo(1);
    arbol->izq->izq->der = crearNodo(9);
    arbol->izq->izq->der->izq = crearNodo(6);
    arbol->der = crearNodo(10);
    arbol->der->izq = crearNodo(5);
    arbol->der->der = crearNodo(12);
    printf("%i",cantGrad1(arbol));


    return 0;
}
