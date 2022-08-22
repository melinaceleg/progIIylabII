#include <stdio.h>
#include <stdlib.h>


void func1(int*** punt)
{
    ///scope, ambito
  int var;
}


///void* malloc(unsigned long size);
int main()
{
//    int a = 10;
//    int* puntero;
//    int** doblepuntero;
////    puntero = &a; /// &a 0xFF
////    doblepuntero = &puntero; ///&puntero 0x1D
////    doblepuntero ///0x1D
////    *doblepuntero /// 0xFF
////    **doblepuntero ///10
////    **doblepuntero = 20;
////    func1(&doblepuntero);

  int validos = 100;
  int* arreglo = (int*)malloc(sizeof(int)*validos);
  arreglo[0] = 3;
  *arreglo = 3;
  arreglo[1] = 5;
  *(arreglo+1)= 5;
  *(arreglo+2) = 6;
  *(arreglo+3)= 8;
  free(arreglo);

//    int arreglo[10];
//    arreglo[0] = 5;
//    printf("%i", arreglo);
//    *(arreglo+0) = 5;
//    *(arreglo+1) = 2;



    return 0;
}
