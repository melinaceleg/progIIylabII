#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
///en pila dinamica siempre debo manejarme por referencia ya que elimino nodos al desapilar, y estos existen en todo ambito



void mostrarLaPila(Pila* p)
{
    int d;
    Pila aux;
    inicPila(&aux);
    while (!pilaVacia(*p))
    {
        printf("%i",tope(*p));
        apilar(&aux,desapilar(p));
    }
    while (!pilaVacia(aux))
    {
        apilar(p,desapilar(&aux));
    }
}



int main()
{
   Pila p;
   inicPila(&p);
   apilar(&p,5);
   apilar(&p,7);
   leer(&p);
   int dato = desapilar(&p);
   mostrar(p);
   mostrarLaPila(&p); //p = 0x22
   mostrar(p); //0x22
    return 0;
}
