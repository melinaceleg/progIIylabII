#include "Fila.h"

nodoD* crearNodoF(Telemento dato)
{
    nodoD* nuevo = (nodoD*)malloc(sizeof(nodoD));
    nuevo->ant=NULL;
    nuevo->sig=NULL;
    nuevo->dato = dato;
    return nuevo;
}

void inicFila(Fila* f)
{
    (*f).pri = NULL; ///f->pri=NULL;
    (*f).ult = NULL;
}

void poneFila(Fila* f,Telemento dato)
{
    nodoD* nuevo = crearNodoF(dato);
    if ((*f).pri==NULL)
    {
        (*f).pri=nuevo;
        (*f).ult=nuevo;
    }
    else
    {
        (*f).ult->sig = nuevo;
        nuevo->ant = (*f).ult;
        (*f).ult = nuevo;

    }

}

Telemento sacaFila(Fila* f)
{
    nodoD* aux;
    Telemento dato;

    aux = (*f).pri;
    if ((*f).pri == (*f).ult) ///el primero de la fila es a su vez el ultimo?
    {
        /// inicFila(f);
        (*f).pri =NULL;
        (*f).ult = NULL;
    }
    else
    {
        (*f).pri=(*f).pri->sig;
        (*f).pri->ant=NULL;
    }
    dato = aux->dato;
    free(aux);

    return dato;
}

Telemento frente(Fila f)
{
    return f.pri->dato;

}

/// 1 esta vacia, 0 contrario
int filaVacia(Fila f)
{
    return (f.pri==NULL);
}
