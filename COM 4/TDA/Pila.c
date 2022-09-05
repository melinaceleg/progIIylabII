#include "Pila.h"

void inicPila(Pila* p)
{
    (*p).tope = -1;
}

void apilar(Pila* p, telemento dato)
{
    if ((*p).tope < 49)
    {
        (*p).tope++;
        (*p).arreglo[(*p).tope] = dato;
    }

}

telemento desapilar(Pila* p)
{
    telemento dato = (*p).arreglo[(*p).tope];
    (*p).tope--;

    return dato;
}

telemento tope(Pila p)
{
    return p.arreglo[p.tope];
}

int pilavacia(Pila p)
{
    return (p.tope == -1);
}

