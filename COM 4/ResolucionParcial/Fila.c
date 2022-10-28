#include "Fila.h"

nodoD* crearNodoD(Telemento p)
{
    nodoD* nuevo= (nodoD*)malloc(sizeof(nodoD));
    nuevo->dato = p;
    nuevo->ant=NULL;
    nuevo->sig=NULL;
    return nuevo;
}


void inicFila(Fila* F)
{
  (*F).pri=NULL;
  (*F).ult=NULL;
}

void poneFila(Fila* F, Telemento dato)
{
    nodoD* nuevo = crearNodoD(dato);
    if ((*F).pri == NULL)
    {
        (*F).pri=nuevo;
        (*F).ult=nuevo;
    }
    else
    {
        (*F).ult->sig = nuevo;
         nuevo->ant= (*F).ult;
        (*F).ult=nuevo;

    }
}

Telemento sacaFila(Fila* F)
{
   nodoD* aux = (*F).pri;
    Telemento elemento = (*F).pri->dato;

    if ((*F).pri == (*F).ult)
    {
        (*F).pri = NULL;
        (*F).ult = NULL;
    }
    else
        (*F).pri = (*F).pri->sig;
    free(aux);

    return elemento;
}

int Filavacia(Fila F)
{

  return (F.pri == NULL); //1 si es verdadero , 0 si es falso
}

Telemento frente(Fila F)
{
    return F.pri->dato;
}


