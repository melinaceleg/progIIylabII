#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

///para recorrer una fila debo pasarla por referencia ya que los campos
///internos tienen las direcciones de memoria de los nodos (sea por copia o no).
void mostrarUnaFila(Fila* f)
{
  Fila aux;
  inicFila(&aux);
  while (!filaVacia(*f))
  {
    printf("%c ",frente(*f));
    poneFila(&aux,sacaFila(f));
  }
  while (!filaVacia(aux))
  {
      poneFila(f,sacaFila(&aux));
  }
}


int main()
{
    Fila f;
    inicFila(&f);
    poneFila(&f,'c');
    poneFila(&f,'d');
    poneFila(&f,'h');
    mostrarUnaFila(&f);
    printf("Ya mostre una vez\n");
    mostrarUnaFila(&f);
    return 0;
}
