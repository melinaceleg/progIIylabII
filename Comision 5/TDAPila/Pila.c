#include "Pila.h"

void inicPila(Pila* p)
{
    (*p).tope = -1;
}

void apilar(Pila* p,int dato)
{
    if ((*p).tope < MAX)
    {
        (*p).tope++;
        (*p).arreglo[(*p).tope] = dato;
        ///(*p).arreglo[++(*p).tope] = dato; utilizamos el preincremento
    }

}

int desapilar(Pila* p)
{
    int dato;
    dato = (*p).arreglo[(*p).tope];
    (*p).tope--;

    return dato;
}

//int desapilar(Pila* p)
//{
//    return (*p).arreglo[(*p).tope--];
//}

int tope(Pila p)
{
    return p.arreglo[p.tope];
}


int pilavacia(Pila p)
{
  if (p.tope == -1)
        return 1;
  else
        return 0;
}

//int pilavacia(Pila p)
//{
//    return (p.tope == -1);
//}

//void leer(Pila* p)
//{
//    int dato;
//    printf("Ingrese un numero\n");
//    fflush(stdin);
//    scanf("%i",&dato);
//    if ((*p).tope < MAX)
//    {
//        (*p).arreglo[(*p).tope] = dato;
//         (*p).tope++;
//    }
//}

void leer(Pila* p)
{
    int dato;
    printf("Ingrese un numero\n");
    fflush(stdin);
    scanf("%i",&dato);
    apilar(p,dato);
}

void mostrar(Pila p)
{
    printf("BASE --");
    for (int i = 0 ; i <= p.tope ; i++)
    {
        printf("%i ",p.arreglo[i]);
    }
    printf("--TOPE");

}

