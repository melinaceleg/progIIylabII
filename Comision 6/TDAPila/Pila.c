#include "Pila.h"

void inicPila(Pila* p)
{
    (*p).tope = -1;
}

int tope(Pila p)
{
    return p.arreglo[p.tope];
}

int pilavacia(Pila p)
{
    return (p.tope == -1);
}


void apilar(Pila* p,int dato)
{
    if ((*p).tope < MAX)
    {
        (*p).tope++;
        (*p).arreglo[(*p).tope] = dato;
    }

}

int desapilar(Pila* p)
{
    int ret;
    ret = (*p).arreglo[(*p).tope];
    (*p).tope--;

    return ret;
    /// return (*p).arreglo[(*p).tope--];
}

void leer(Pila* p)
{
    int dato;
    printf("Ingrese un dato a la pila\n");
    fflush(stdin);
    scanf("%i",&dato);
    // if ((*p).tope < MAX)
    //scanf("%i",(*p).arreglo[++(*p).tope]);
    apilar(p,dato);
}


void mostrar(Pila p)
{
    printf("BASE ....");
    for(int i = 0; i <= p.tope; i++)
    {
        printf("%i ", p.arreglo[i]);
    }
    printf("....TOPE\n");
}

