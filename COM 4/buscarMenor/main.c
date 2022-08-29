#include <stdio.h>
#include <stdlib.h>
/**

7. Buscar el menor elemento de un arreglo en forma recursiva.
**/

CASO BASE
i == N

CASO RECURSIVO
i < validos

int menorElemento(int arreglo[],int N,int i)
{
    int menor;
    if ( i == N)
    {
        return arreglo[N];
    }
    else
    {
        menor = menorElemento(arreglo,N,i+1);
        if (arreglo[i] < menor)
        {
            menor = arreglo[i];
        }

        return menor;
    }

}

int menorElementoSini(int arreglo[], int N)
{
    int menor;
    if (N == 0)
    {
        return arreglo[0];
    }
    else
    {
        menor = menorElementoSini(arreglo,N-1);
        if (arreglo[N] < menor)
        {
            menor = arreglo[N];
        }

        return menor;
    }

}

void menorElementoRef(int arreglo[], int N, int* menor)
{
    if (N == 0)
    {
        *menor = arreglo[0];
    }
    else
    {
        menorElementoRef(arreglo,N-1,menor);
        if (arreglo[N] < *menor)
        {
            *menor = arreglo[N];
        }

    }

}

void menorElementoRefIda(int arreglo[],int validos, int i, int* menor)
{
    if (i == 0) ///caso recursivo
    {
        *menor = arreglo[0];
        menorElementoRefIda(arreglo,validos,i+1,menor);
    }
    else
    {
        if (i < validos)
        {
            if (arreglo[i] < *menor)
            {
                *menor = arreglo[i];
            }

            menorElementoRefIda(arreglo,validos,i+1,menor);
        }


    }
}
///generar la funcion por referencia que calcule el menor EN LA VUELTA
///generar la funcion por referencia que calcule el menor sin i (con N) vuelta

    int main()
    {
        int arreglo[] = {2, 4, 1, 7,9};
        int validos = 5;
        int menor;
        menor = menorElementoRefIda(arreglo,validos,0,&menor);



        return 0;
    }
