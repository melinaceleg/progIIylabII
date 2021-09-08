#include "Pila.h"


void inicPila(nodop** p) {

    *p = NULL;
}

nodop* crearNodo(int dato)
{
    nodop* nuevo = (nodop*)malloc(sizeof(nodop));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}


//tope
//8
//3
//base
void apilar(Pila* p,int dato) ///nodop **
{
  nodop* nuevo = crearNodo(dato);
  if (*p == NULL)  ///algoritmo de insertar al principio
  {
      *p = nuevo;
  }
  else
  {
      nuevo->sig = *p;
      *p = nuevo;
  }
}
//tope
//4  *p
//7
//9
//base
int desapilar(Pila* p) ///nodop*
{
   int dato;
   nodop* aux;
   aux = *p;
   dato = aux->dato;
   *p = (*p)->sig;
   free(aux);
  return dato;
}

///1 vacia, 0 si no esta vacia
int pilaVacia(Pila p) ///nodop*
{

    return (p == NULL);

}

int tope(Pila p)
{
    return p->dato;

}

void leer(Pila* p)
{
    int dato;
    printf("ingrese un valor\n");
    scanf("%i",&dato);
    apilar(p,dato);
}


void mostrar(Pila p)
{
  printf("TOPE...");
  while (p != NULL)
  {
      printf("%i ",p->dato);
      p=p->sig;
  }
  printf("..BASE\n");
}
