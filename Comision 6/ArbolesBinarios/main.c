#include <stdio.h>
#include <stdlib.h>

typedef int telemento;
typedef struct nodoA
{
    telemento dato;
    struct nodoA* izq;
    struct nodoA* der;
} nodoA;


nodoA* crearNodoArbol(telemento dato)
{
    nodoA* nuevo = (nodoA*)malloc(sizeof(nodoA));
    nuevo->dato = dato;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;
}

///retorna 1 o 0 si encontro el dato o no respectivamente

int busquedaDato(nodoA* A, telemento dato)
{
    int resp=0;
    if (A != NULL)
    {
        if (A->dato == dato)
            return 1;
        else
            resp = busquedaDato(A->izq,dato);
        if (resp != 1)
        {
            resp = busquedaDato(A->der,dato);
        }

    }
    return resp;

}

int cantGrado1(nodoA* A)
{
    if (A != NULL)
    {
        if ((A->izq != NULL && A->der == NULL) || (A->izq ==NULL && A->der != NULL))
        {
            return 1 + cantGrado1(A->izq) + cantGrado1(A->der);
        }
        else
        {
            return cantGrado1(A->izq) + cantGrado1(A->der);
        }
    }
    else
        return 0;

}





int main()
{
    nodoA* arbol = NULL;
    arbol = crearNodoArbol(4);
    arbol->izq = crearNodoArbol(7);
    arbol->izq->izq = crearNodoArbol(2);
    arbol->izq->izq->izq = crearNodoArbol(1);
    arbol->izq->izq->der = crearNodoArbol(9);
    arbol->izq->izq->der->izq = crearNodoArbol(6);
    arbol->der = crearNodoArbol(10);
    arbol->der->izq= crearNodoArbol(5);
    arbol->der->der = crearNodoArbol(12);
    printf("%i",busquedaDato(arbol,9));
    printf("cant nodos grado 1: %i",cantGrado1(arbol));
    return 0;
}
