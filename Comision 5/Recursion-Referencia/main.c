#include <stdio.h>
#include <stdlib.h>

void busquedaMenor(int arreglo[],int u, int* pos)
{
    if (u == 0)
    {
        *pos = 0;
    }
    else
    {
        busquedaMenor(arreglo,u-1,pos);
        if (arreglo[*pos] > arreglo[u])
        {
            *pos = u;
        }
    }
}



int main()
{
    int arreglo[] = {8,5,2,7,9};
    int validos = 5;
    int pos;
    busquedaMenor(arreglo,validos-1,&pos);
    printf("El menor numero es: %i", arreglo[pos]);

    return 0;
}
