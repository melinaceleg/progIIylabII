#include <stdio.h>
#include <stdlib.h>

void busquedaMenor(int arreglo[], int u, int* menor)
{
    if (u == 0)
    {
        *menor = arreglo[0];
    }
    else
    {
        busquedaMenor(arreglo,u-1,menor);
        if (*menor > arreglo[u])
        {
            *menor = arreglo[u];
        }
    }
}



int main()
{
    int arreglo[] = {6,5,4,7,9};
    int validos = 5;
    int menor;
    busquedaMenor(arreglo,validos-1,&menor);
    printf("El menor es : %i",menor);
    return 0;
}
