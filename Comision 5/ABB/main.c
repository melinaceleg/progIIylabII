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
    nuevo->dato=dato;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;
}
///1- caso NULL
///2 - caso != NULL
///    a) dato menor a raiz -> voy hacia la izquierda
///    b) dato mayor a raiz -> voy hacia la derecha
///    c) dato igual ? no se puede
void insertar(nodoA** arbol, telemento dato)
{
    if (*arbol == NULL)
    {
        *arbol = crearNodoArbol(dato);
    }
    else
    {
        if (dato < (*arbol)->dato)
        {
            insertar(&(*(arbol)->izq),dato);
        }
        else
        {
            insertar(&((*arbol)->der),dato);
        }

    }

}
///si el arbol tiene datos
int minimoArbol(nodoA* arbol)
{
    if (arbol->izq != NULL)
    {
        return minimoArbol(arbol->izq);
    }
    else
    {
        return arbol->dato;
    }
}
///si el arbol tiene datos
int maximoArbol(nodoA* arbol)
{
    if (arbol->der != NULL)
    {
        return maximoArbol(arbol->der);
    }
    else
    {
        return arbol->dato;
    }
}



///retorna 1 si encontro, 0 contrario
int busquedaClave(nodoA* arbol, telemento clave)
{
    if (arbol != NULL)
    {
        if (arbol->dato == clave)
        {
            return 1;
        }
        else
        {
            if (clave < arbol->dato)
            {
                return busquedaClave(arbol->izq,clave);
            }
            else
            {
                return busquedaClave(arbol->der,clave);
            }
        }
    }
    else
    {
        return 0;
    }
}


int busquedaIterativa(nodoA* arbol, telemento dato)
{
    while (arbol != NULL && arbol->dato != dato)
    {
        if (dato < arbol->dato)
        {
            arbol=arbol->izq;
        }
        else
            arbol=arbol->der;
    }
    if (arbol != NULL)
    {
        return 1;
    }
    else
        return 0;

}



///hacer insercion iterativa



int main()
{
    nodoA* arbol = NULL;

    return 0;
}
