#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

int main()
{
    Pila p;
    inicPila(&p);
    apilar(&p,5);
    apilar(&p,6);
    leer(&p);
    mostrar(p);
    ///p.arreglo[0] acceder de esta manera destruye el significado de TDA
    ///estamos invadiendo la estructura interna
    printf("El tope es %i", tope(p));
    return 0;
}
