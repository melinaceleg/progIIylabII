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
    printf("El tope es %i",tope(p));

    ///p.tope = 18;
    ///invasion a la integridad de la pila
    ///NO ES UN TDA


    return 0;
}
