#ifndef FRACCION_H_INCLUDED
#define FRACCION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int numerador;
    int denominador;
}Fraccion;


///acciones
void ingresar(Fraccion* f,int numerador, int denominador);
void sumar(Fraccion f, Fraccion h, Fraccion* c);
void restar(Fraccion f, Fraccion h, Fraccion* c);
int numerador(Fraccion f);
int denominador(Fraccion f);
void mostrarFraccion(Fraccion f);






#endif // FRACCION_H_INCLUDED
