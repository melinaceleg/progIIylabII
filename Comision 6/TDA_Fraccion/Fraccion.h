#ifndef FRACCION_H_INCLUDED
#define FRACCION_H_INCLUDED

typedef struct {
    int numerador;
    int denominador;

}Fraccion;


///Acciones
void ingresar(Fraccion* f,int numerador,int denominador);
void suma(Fraccion a, Fraccion b, Fraccion* c);
void resta(Fraccion a, Fraccion b, Fraccion* c);
int numerador(Fraccion f);
int denominador(Fraccion f);


#endif // FRACCION_H_INCLUDED
