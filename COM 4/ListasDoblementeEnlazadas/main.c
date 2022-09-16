#include <stdio.h>
#include <stdlib.h>

typedef int telemento;

typedef struct nodoD
{
    telemento dato;
    struct nodoD* siguiente;
    struct nodoD* anterior;
}nodoD;

void insertarAlPrincipio(nodoD**, telemento);
nodoD* crearNodoD(telemento);
void insertarAlFinal(nodoD**, telemento)

nodoD* crearNodo(telemento dato)
{
    nodoD* nuevo = (nodoD*)malloc(sizeof(nodoD));
    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    return nuevo;
}


void insertarAlPrincipio(nodoD** lista, telemento dato)
{
    nodoD* nuevo = crearNodoD(dato);
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        nuevo->siguiente = *lista;
        (*lista)->anterior = nuevo;
         *lista = nuevo;
    }

}

void insertarAlFinal(nodoD** lista, telemento dato)
{
    nodoD* seg;
    nodoD* nuevo = crearNodoD(dato);
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        seg = *lista;
        while (seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }

        seg->siguiente = nuevo;
        nuevo->anterior = seg; ///esto es nuevo
    }

}



int main()
{
    nodoD* lista = NULL;

    return 0;
}
