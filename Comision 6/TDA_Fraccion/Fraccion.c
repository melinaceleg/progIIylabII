#include "Fraccion.h"

void ingresar(Fraccion* f,int numerador,int denominador)
{
    (*f).numerador = numerador;
    (*f).denominador = denominador;
}

///consideramos denominadores iguales
void suma(Fraccion a, Fraccion b, Fraccion* c)
{
   (*c).numerador = a.numerador + b.numerador;
}

///consideramos denominadores iguales
void resta(Fraccion a, Fraccion b, Fraccion* c)
{
    (*c).numerador = a.numerador - b.numerador;
}

int numerador(Fraccion f)
{
    return f.numerador;
}

int denominador(Fraccion f)
{
    return f.denominador;
}
