#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int** crearMatriz(int cantFilas,int cantCols)
{
    int** matriz;

    matriz = (int**)malloc(sizeof(int)*cantFilas); ////le doy  cantFilas

    ///le doy columnas a las filas
    for (int i = 0 ; i < cantFilas ; i++)
    {
        matriz[i] = (int*)malloc(sizeof(int)*cantCols);
    }

    for (int i = 0 ; i < cantFilas ; i++)
    {
        for (int j=0; j < cantCols ; j++)
        {
            matriz[i][j] = rand() % 20;
        }

    }

    return matriz;
}

// 0x23 0x24 0x25
// 0x44 0x45

void crearMatrizVoid(int*** matriz, int cantFilas,int cantCols)
{
    *matriz = (int**)malloc(sizeof(int)*cantFilas); ///arreglo de punteros a entero

    for ( int i = 0; i < cantFilas; i++)
    {
        (*matriz)[i] = (int*)malloc(sizeof(int)*cantCols); //cada celda del arreglo almacenara una dir de memoria hacia un bloque
    }

    for (int i = 0 ; i < cantFilas ; i++)
    {
        for (int j=0; j < cantCols ; j++)
        {
            (*matriz)[i][j] = rand() % 20;
        }

    }

}


int main()
{
    int cantFilas,cantCols;
    srand(time(NULL));
//    int* arreglo = (int*)malloc(sizeof(int)*10);
    int** matriz ;
    int num;
//    matriz[0] = (int*)malloc(sizeof(int)*10);
//    matriz[1] = (int*)malloc(sizeof(int)*10);
//    matriz[2] = (int*)malloc(sizeof(int)*10);
//    matriz[3] = (int*)malloc(sizeof(int)*10);
//    ....

    printf("ingrese cantidad de filas de la matriz\n");
    scanf("%i",&cantFilas);
    printf("Ingrese cantidad de columnas\n");
    scanf("%i",&cantCols);

    // matriz = crearMatriz(cantFilas,cantCols);
    crearMatrizVoid(&matriz,cantFilas,cantCols);

    for (int i = 0 ; i < cantFilas ; i++)
    {
        for (int j=0; j < cantCols ; j++)
        {
            printf("%i\t", matriz[i][j]);
        }
        printf("\n");

    }


    for(int i = 0 ; i < cantFilas; i++)
    {
       free(matriz[i]);  ///libero cada celda que almacena la dir de otro arreglo DE ENTEROS
    }

    free(matriz); ///libero el arreglo de punteros a entero


    return 0;
}
