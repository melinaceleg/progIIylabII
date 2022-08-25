#include <stdio.h>
#include <stdlib.h>

///matriz de 3 x 3 en memoria dinamica


void cargaMatriz(int** mat, int N) //int mat[][3]
{
    int valor;
   for (int i = 0; i < N; i++)
   {
       for (int j = 0; j < N; j++)
       {
//           printf("Ingrese un valor\n");
//           scanf("%i", &valor);
//           *(*(matriz+i)+j) = valor;
           scanf("%i", *(matriz+i)+j);
       }
   }

}

void modif(int* a)
{
    *a = 5;

}

void inicializarMatriz(int*** matriz, int N, int M)
{
    *matriz = (int**)malloc(sizeof(int*)*N); //0x14
    for (int i = 0 ; i < N; i++)
    {
        *(*matriz+i) = (int*)malloc(sizeof(int)*M);
    }

}


int main()
{
  //int* arreglo = (int*)malloc(sizeof(int)*10);

  int** matriz; ///&matriz = 0x49
  //int arreglo[10];
  inicializarMatriz(&matriz,3,3);

  for (int i = 0 ; i < 3 ; i++)
  {
      free(*(matriz+i)); ///libero las filas
  }

  free(matriz); ///libero el arreglo de filas


//  int** matriz = (int**)malloc(sizeof(int*)*4); //filas
//  for (int i = 0; i < 4; i++ ) //creo columnas x cada fila
//  {
//      *(matriz+i) = (int*)malloc(sizeof(int)*4); //columnas por cada fila
//  }
    return 0;
}
