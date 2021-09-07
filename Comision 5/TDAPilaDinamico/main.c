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

    return 0;
}
