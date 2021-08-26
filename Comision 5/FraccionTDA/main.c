#include <stdio.h>
#include <stdlib.h>
#include "Fraccion.h"

int main()
{
    Fraccion j;
    Fraccion f;
    Fraccion h;
    ingresar(&j,2,5);
    ingresar(&f,1,5);
    sumar(f,j,&h);
   // printf("el numerador es %i", f.numerador); ///NO
    ///estoy invadiendo la estructura interna de mi TDA

    printf("el numerador es %i\n", numerador(f));

    ///printf("la suma es %i / %i",numerador(h),denominador(h));
    mostrarFraccion(h);


    return 0;
}
