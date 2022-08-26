#include <stdio.h>
#include <stdlib.h>

int busca(int arreglo[], int validos, int X)
{
    int i = 0;
    while (i < validos && arreglo[i] != X)
    {
        i++;
    }
    if (i < validos)
    {
        return 1;
    }
    else
        return 0;

}

CONDICIONES BASE
1: i == validos
2: arreglo[i] == X

CONDICION RECURSIVA
1: i<validos
2: arreglo[i] != X


int buscaRecursivoPos(int arreglo[], int validos, int i, int X)
{
    if (i == validos) ///caso base
    {
        return -1;  ///sol trivial
    }
    else
    {
        if (arreglo[i] == X) ///caso base
        {
            return i;  ///sol trivial
        }
        else  ///caso recursivo
        {
            return buscaRecursivo(arreglo,validos,i+1,X); ///llamada recursiva
        }
    }

}

int buscaRecursivo(int arreglo[], int validos, int i, int X)
{
    if (i == validos) ///caso base
    {
        return 0;  ///sol trivial
    }
    else
    {
        if (arreglo[i] == X) ///caso base
        {
            return 1;  ///sol trivial
        }
        else  ///caso recursivo
        {
            return buscaRecursivo(arreglo,validos,i+1,X); ///llamada recursiva
        }
    }

}

CONDICION BASE
1: i == validos

CONDICION RECURSIVO
1: i < validos


///i=0
int suma(int arreglo[], int i, int validos)
{
    if (i< validos) ///caso recursivo
    {
        return arreglo[i] + suma(arreglo,i+1,validos);

    }
    else ///caso base
    {
        return 0;/// sol trivial
    }





}






int main()
{


    return 0;
}
