#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* generarArreglo(int tam)
{
    int* arreglo = (int*)malloc(sizeof(int)*tam);

    for ( int i = 0 ; i < tam ; i++)
    {
        *(arreglo+i) = rand() % 20;
    }

    return arreglo;
}


void generarArregloVoid(int** arreglo,int tam)
{
    *arreglo = (int*) malloc(sizeof(int)*tam);
    for ( int i = 0 ; i < tam ; i++)
    {
        //*(*(arreglo+i)) = rand() % 20;
          arreglo[0][i] =rand() % 20;
    }
}




int main()
{
    ///genere un espacio en el heap
    /// int* arreglo = (int*)malloc(sizeof(int)*10);

    int* arreglo;
    int tam;
//  int arreglo[10];
//
//  *(arreglo+1) = 5;

    srand(time(NULL));

    printf("ingrese el tamano del arreglo\n");
    scanf("%i", &tam);

    generarArregloVoid(&arreglo,tam);

    for (int i = 0; i < tam ; i++)
    {
        printf("%x\t",arreglo+i);
    }

    printf("\n");
    for ( int i = 0 ; i < tam ; i++)
    {
        printf("%i\t", *(arreglo+i));
    }



    return 0;
}
