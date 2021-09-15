#include "Fila.h"

void inicFila(Fila* f)
{
    (*f).pri = NULL;
    (*f).ult = NULL;
}


nodoD* crearNodo(Telemento dato)
{
    nodoD* nuevo = (nodoD*)malloc(sizeof(nodoD));
    nuevo->dato = dato;
    nuevo->ant= NULL;
    nuevo->sig= NULL;

    return nuevo;
}


void poneFila(Fila* f,Telemento dato)
{
    nodoD* nuevo = crearNodo(dato);
    if((*f).pri == NULL)
    {
        (*f).pri = nuevo;
        (*f).ult = nuevo;
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
    Telemento dato;
    nodoD* aux;

    aux = (*f).pri;
    dato = aux->dato;
    if ((*f).pri == (*f).ult)
    {
        inicFila(f);
    }
    else
    {
        (*f).pri = (*f).pri->sig;
        (*f).pri->ant = NULL;
    }
    free(aux);

    return dato;
}

///otra implementacion
//Telemento sacaFila(Fila* f)
//{
//    Telemento dato;
//    nodoD* aux;
//
//    aux = (*f).pri;
//    dato = aux->dato;
//    (*f).pri = (*f).pri->sig;
//    if ((*f).pri == NULL)
//    {
//        (*f).ult = NULL;
//    }
//    else
//    {
//        (*f).pri->ant = NULL;
//    }
//    free(aux);
//
//    return dato;
//}

//retorna 1 si esta vacia, sino 0
int filaVacia(Fila f)
{
    return (f.pri==NULL);

}


Telemento frente(Fila f)
{
    return f.pri->dato;
}
