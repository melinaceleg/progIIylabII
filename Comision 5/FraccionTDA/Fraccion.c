#include "Fraccion.h"

void ingresar(Fraccion* f,int numerador, int denominador)
{
    (*f).numerador = numerador;
    (*f).denominador = denominador;
}

///mismo denominador
void sumar(Fraccion f, Fraccion h, Fraccion* c)
{
    (*c).numerador = f.numerador + h.numerador;
    (*c).denominador = f.denominador;

}
///mismo denominador
void restar(Fraccion f, Fraccion h, Fraccion* c)
{
    (*c).numerador = f.numerador - h.numerador;
    (*c).denominador = f.denominador;
}

int numerador(Fraccion f)
{
    return f.numerador;
}
int denominador(Fraccion f)
{
    return f.denominador;
}

void mostrarFraccion(Fraccion f)
{
    printf("%i/%i",f.numerador,f.denominador);
}



