#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

/** La estructura de nuestro tipo de dato
 ,la definicion del comportamiento (acciones), y dependencias **/


typedef char telemento; //alias

typedef struct
{
    telemento arreglo[50];
    int tope; ///ultima posicion valida
}Pila;


////comportamiento , prototipados

void inicPila(Pila*);
void apilar(Pila*, telemento);
telemento desapilar(Pila*);
telemento tope(Pila);
int pilavacia(Pila);




#endif // PILA_H_INCLUDED
