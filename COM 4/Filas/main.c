#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void recorrerFila(Fila* F)
{
    telementoF dato;
    Fila aux;
    inicFila(&aux);
    while (!filavacia(*F))
    {
        printf("%i ", frente(*F));
        poneFila(&aux,sacaFila(F));
    }
    while (!filavacia(aux))
    {
        poneFila(F,sacaFila(&aux));
    }
}



int main()
{
    Fila F;
    inicFila(&F);
    poneFila(&F,3);
    poneFila(&F,5);
    poneFila(&F,7);
    printf("\n pri: %p \n ", F.pri); ///DONI NO!!
    recorrerFila(&F);
    printf("\nMostrando por 2da vez"); ///DONI NO!!
    recorrerFila(&F);
    printf("\n pri: %p \n", F.pri);

    return 0;
}
