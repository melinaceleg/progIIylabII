#include <stdio.h>
#include <stdlib.h>
#include "Fraccion.h"

int main()
{
  Fraccion f;
  Fraccion g;
  Fraccion h;
  ///f.numerador = 5; NO ES TDA SI HAGO ESTO
  ingresar(&f,2,5);
  ingresar(&g,2,3);
  suma(f,g,&h);
    return 0;
}
