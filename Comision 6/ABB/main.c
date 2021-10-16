#include <stdio.h>
#include <stdlib.h>

typedef int telemento;
typedef struct nodoA
{
    telemento dato;
    struct nodoA* izq;
    struct nodoA* der;

} nodoA;


nodoA* crearNodo(telemento dato)
{
    nodoA* nuevo = (nodoA*)malloc(sizeof(nodoA));
    nuevo->dato = dato;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;
}

void insertarABB(nodoA** arbol, telemento dato)
{
    if (*arbol == NULL)
    {
        *arbol = crearNodo(dato);
    }
    else
    {
        if (dato < (*arbol)->dato)
        {
            insertarABB(&((*arbol)->izq,dato);
        }
        else
        {
            insertarABB(&((*arbol)->der),dato);
        }

    }



}

///retornar 1 si encuentro 0 en caso contrario
int busquedaABB(nodoA* arbol, telemento dato)
{
    if (arbol == NULL)
    {
        return 0;
    }
    else
    {
        if (dato == arbol->dato)
        {
            return 1;
        }
        else
        {

            if (dato < arbol->dato)
            {
                return busquedaABB(arbol->izq,dato);
            }
            else
            {
                return busquedaABB(arbol->der,dato);
            }

        }

    }

}


int busquedaABBiterativo(nodoA* arbol, telemento dato)
{
    while (arbol != NULL && arbol->dato != dato)
    {
        if (dato < arbol->dato)
        {
            arbol = arbol->izq;
        }
        else
        {
            arbol = arbol->der;
        }
    }
    if (arbol != NULL)
        return 1;
    else
        return 0;
    ///return (arbol != NULL);

}

///insercion iterativa HACER


///calcular el nivel de un nodo en el arbol





int main()
{
    nodoA* arbol = NULL;

    return 0;
}
