#include <stdio.h>
#include <stdlib.h>


int busca(int arreglo[], int i, int validos, int X)
{
    if (i < validos)
    {
        if (arreglo[i] == X) ///caso base
        {
            return 1;
        }
        else ///caso recursivo
        {
            return busca(arreglo,i+1,validos,X);
        }

    }
    else ///caso base
    {
        return 0;
    }

}

///N ultimo indice valido
int suma(int arreglo[], int N)
{
    if (N >=0) ///caso recursivo
    {
        return arreglo[N] + suma(arreglo,N-1); ///llamada recursiva
    }
    else ///caso base
        return 0;  ///solucion trivial

}



int main()
{
    int arreglo[4] = {1,2,3,4};
    int validos = 4;
    int resultado = busca(arreglo,0, validos, 3);
    int result = suma(arreglo,validos-1);

    return 0;
}
