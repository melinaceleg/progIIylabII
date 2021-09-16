#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

/**en esta implementacion dinamica, recorrer una fila implica eliminar nodos, por lo tanto
se debe trabajar por referencia continuamente */

void mostrarFila(Fila* f)
{
    Telemento dato;
    Fila aux;
    inicFila(&aux);
    while (!filaVacia(*f))
    {
        printf("%i ",frente(*f));
        poneFila(&aux,sacaFila(f));
    }
    while(!filaVacia(aux))
    {
        poneFila(f,sacaFila(&aux));
    }
}



int main()
{
    Fila f;
    inicFila(&f);
    poneFila(&f,1);
    poneFila(&f,3);
    poneFila(&f,5);
    mostrarFila(&f);
    printf("bueno ya mostre, voy a mostrar otra vez por las dudas\n");
    mostrarFila(&f);
    return 0;
}
