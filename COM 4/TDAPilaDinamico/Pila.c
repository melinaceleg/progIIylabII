#include "Pila.h"

void inicPila(Pila* p)
{
  *p = NULL;

}

//nodo* crearNodo(telemento dato)
//{
//    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
//    nuevo->dato = dato;
//    nuevo->siguiente = NULL;
//    return nuevo;
//}


void apilar(Pila* p, telemento dato)
{
  //nodo* nuevo = crearNodo(dato);
   ///crearNodo
   nodo* nuevo = (nodo*)malloc(sizeof(nodo));
   nuevo->dato = dato;

   ///agregar al principio
   nuevo->siguiente = *p;
   *p = nuevo;
}

telemento desapilar(Pila* p)
{
    telemento dato;
    nodo* aux;
    aux = *p;
    *p = (*p)->siguiente;
    dato = aux->dato;
    free(aux);

    return dato;
}

telemento tope(Pila p)
{
    return p->dato;
}

int pilavacia(Pila p)
{
     return  (p == NULL);
}

