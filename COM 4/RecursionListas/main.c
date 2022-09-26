#include <stdio.h>
#include <stdlib.h>

typedef int telemento;

typedef struct nodo
{
    telemento dato;
    struct nodo* siguiente;
} nodo;


void recorrerLista(nodo* lista)
{
    while (lista != NULL)
    {
        printf("%i ",lista->dato);
        lista = lista->siguiente;
    }

}

void recorrerListaRec(nodo* lista)
{
    if (lista != NULL)
    {
        recorrerListaRec(lista->siguiente);
        printf("%i ", lista->dato);


    }
}

//    pantalla : 7  5  3
//
//     recorrerListaRec()          recorrerListaRec()         recorrerListaRec()       recorrerListaRec()
//    lista 3->5->7->NULL          lista 5->7->NULL           lista 7->NULL              lista NULL
//



///BUSCAR UN DATO LISTA DESORDENADA

/**
CASO BASE
     LISTA == NULL
     lista != NULL && lista == dato

CASO RECURSIVO
     LISTA != NULL && dato != LISTA->DATO

**/

int busquedaDatoRec(nodo* lista, int dato)
{
    if (lista != NULL)
    {
        if (lista->dato == dato) ///caso base
        {
            return 1;
        }
        else ///caso recursivo
        {

            return busquedaDatoRec(lista->siguiente,dato);
        }
    }
    else ///CASO BASE
    {
        return 0;
    }
}

lista 3->5->7->NULL
dato 7
void busquedaDatoRec2(nodo* lista, int dato, int* enc) ///enc = 0x17
{
    if (lista != NULL)
    {
        if (lista->dato == dato) ///caso base
        {
            *enc = 1;
        }
        else ///caso recursivo
        {
            busquedaDatoRec(lista->siguiente,dato,enc);
        }

    }
    else ///caso base
    {
        *enc = 0;
    }

}

lista 3->4->5->7->NULL
dato 6

CASO BASE
lista == NULL  4
lista != NULL && dato < lista->dato  1
lista != NULL && dato == lista->dato  2
CASO RECURSIVO
lista != NULL && dato > lista->dato   3


int busquedaDatoRecOrdenada(nodo* lista, int dato)
{
    if (lista != NULL)
    {
        if (dato < lista->dato) ///caso base 1
        {
            return 0;
        }
        else
        {
            if (lista->dato == dato) ///caso base 2
            {
                return 1;
            }
            else ///caso recursivo 3
            {
                return busquedaDatoRecOrdenada(lista->siguiente,dato);
            }
        }

    }
    else ///caso base 4
    {
        return 0;
    }

}

///tarea: realizar la busqueda ordenada con una funcion void








int main()
{
    nodo* lista = NULL;
    ///cargamos la lista
    recorrerLista(lista);

    return 0;
}
