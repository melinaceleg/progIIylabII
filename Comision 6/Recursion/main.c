#include <stdio.h>
#include <stdlib.h>
//retornar posicion o -1 si no esta
int busqueda(int arreglo[],int validos, int X)
{
    if (validos < 0)
    {
        return -1;
    }
    else
    {
        if (arreglo[validos] == X)
        {
            return validos;
        }
        else
        {
            return busqueda(arreglo,validos-1,X);
        }
    }
}


int main()
{
    int arreglo[] = {2,4,7,8};
    int validos = 4;
    int pos;
    pos = busqueda(arreglo,validos-1,X);
    if (pos >= 0)
    {
        printf("%i", arreglo[pos]);
    }
    return 0;
}
