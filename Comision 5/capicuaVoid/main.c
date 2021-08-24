#include <stdio.h>
#include <stdlib.h>

void verificarCapicua(int arreglo[], int validos1, int validos2, int* esCapicua) //(0,validos 2)
{
    if (validos1 >= validos2)
    {
        *esCapicua = 1;
    }
    else
    {
        if (arreglo[validos1] == arreglo[validos2])//
        {

            verificarCapicua(arreglo, validos1 + 1, validos2 - 1);
        }
        else
        {
            *esCapicua = 0;
        }
    }
}



int main()
{
  int arreglo[] = {1,2,1};
  int validos = 3;
  int escapi;
  verificarCapicua(arreglo,0,validos-1,&escapi);
  if (escapi == 1)
    printf("Es capicua");
  else
    printf("No es capicua");
    return 0;
}
