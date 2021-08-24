#include <stdio.h>
#include <stdlib.h>

int busca(int arreglo[], int N, int X)
{
    if (N >=0)
    {
        if (arreglo[N] == X)
            return N;
        else
        {
            return busca(arreglo,N-1,X);
        }
    }
    else
    {
        return -1;
    }
}


int main()
{
    int arreglo[] = {2,4,7,1};
    int validos = 4;
    int i = busca(arreglo,validos-1,4);
    if (i != -1)
      printf("%i",arreglo[i]);
    return 0;
}
