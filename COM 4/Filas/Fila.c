#include "Fila.h"

void inicFila(Fila* F)
{
    (*F).pri = NULL;
    (*F).ult = NULL;
}

void poneFila(Fila* F, telementoF dato)
{
    nodoDF* nuevo = (nodoDF*)malloc(sizeof(nodoDF));
    nuevo->siguiente = NULL;
    nuevo->dato = dato;

    if ((*F).pri != NULL)
    {
        (*F).ult->siguiente = nuevo;
        nuevo->anterior = (*F).ult;
        (*F).ult = nuevo; ///(*F).ult = (*F).ult->siguiente;

    }
    else
    {
        (*F).pri = nuevo;
        (*F).ult = nuevo;
        nuevo->anterior = NULL;
    }

}
/**
1- Si hay un elemento en la fila
2- El resto
**/
telementoF sacaFila(Fila* F)
{
    nodoDF* aux;
    telementoF dato;

    aux = (*F).pri;
    dato = aux->dato;
    if ((*F).pri == (*F).ult) /// hay un solo elemento en la fila
    {

        (*F).pri = NULL;
        (*F).ult = NULL;
        //inicFila(F);
    }
    else
    {
        (*F).pri = (*F).pri->siguiente;
        (*F).pri->anterior = NULL;

    }

    free(aux);
    return dato;
}

telementoF frente(Fila F)
{
    return F.pri->dato;
}


/**
1 si esta vacia
0 si no lo esta
**/
int filavacia(Fila F)
{
    return F.pri == NULL;

}

