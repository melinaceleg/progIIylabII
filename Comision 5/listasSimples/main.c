#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
   int dato;
   struct nodo* sig;
}nodo;


nodo* crearNodo(int dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}

//lista 3->  7->   8->  10->11->NULL
//    0x44  0x55  0x80

int main()
{
  nodo* lista = NULL;
  nodo*nuevo;
  lista = crearNodo(3); ///lista = 0x44
  nuevo = crearNodo(7);
  lista->sig = nuevo;
  lista->sig->sig = crearNodo(8);
  lista->sig->sig->sig...

  printf("%i", lista->dato);
  printf("%i", (lista->sig)->dato);

  nodo *laux = lista; 0x44
 while (laux != NULL)
  {
      printf("%i",laux->dato);
      laux = laux->sig; 0x55...
  }

  printf("%i",lista->dato);
    return 0;
}
