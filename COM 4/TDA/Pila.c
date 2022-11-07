#include "Pila.h"

void inicPila(Pila* p)
{
    (*p).tope = -1;
}

void apilar(Pila* p, telemento dato)
{
  ////HACER
}

telemento desapilar(Pila* p)
{
    telemento dato = (*p).arreglo[(*p).tope];
    (*p).tope--; 

    return dato;
}

telemento tope(Pila p)
{
 ////HACER
}

int pilavacia(Pila p)
{
    return (p.tope == -1);
}

