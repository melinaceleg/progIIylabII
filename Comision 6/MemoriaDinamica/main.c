#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generarArreglo(int tam)
{
    int* arreglo;
    arreglo = (int*)malloc(sizeof(int)*tam);

    return arreglo;
}


void generarArregloVoid(int** arregloDinamico, int tam)
{
    *arregloDinamico = (int*)malloc(sizeof(int)*tam);
    for (int i=0; i < tam ; i++)
   {
     *(*arregloDinamico+i)  = rand() % 50;
    // arregloDinamico[0][i]
   }

   free(*arregloDinamico);

}




int main()
{
   int* arregloDinamico;
   srand(time(NULL));
   int tam;
   printf("Ingrese un tamano para el arreglo\n");
   scanf("%i",&tam);
   generarArregloVoid(&arregloDinamico,tam);
   arregloDinamico = generarArreglo(tam);
  // arregloDinamico = (int*)malloc(sizeof(int)*tam);

   for (int i=0; i < tam ; i++)
   {
       *(arregloDinamico+i) = rand() % 50;
   }

   for (int i = 0 ; i < tam ; i++)
   {
       printf("%i\t",*(arregloDinamico+i));
   }

   free(arregloDinamico);

  printf("aca se va a mostrar cualquier cosa\n");
    for (int i = 0 ; i < tam ; i++)
   {
       printf("%i\t",*(arregloDinamico+i));
   }


    return 0;
}
