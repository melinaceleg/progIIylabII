#include <stdio.h>
#include <stdlib.h>

typedef int telemento;

typedef struct nodo
{
    telemento dato;
    struct nodo* siguiente;
}nodo;

/**

nuevo->dato
(*nuevo).dato
(*nuevo).siguiente

**/

nodo* crearNodo(telemento dato)
{
 nodo* nuevo = (nodo*)malloc(sizeof(nodo)); ///genero el espacio de ese nodo
 nuevo->dato = dato;
 nuevo->siguiente = NULL;

 return nuevo;
}

/**
  1 : la lista puede estar vacia
  2 : la lista tiene datos

  **/

void insertarAlPrincipio(nodo** lista, telemento dato)
{
    nodo* nuevo = crearNodo(dato);
    if (*lista == NULL) /// 1
    {
        *lista = nuevo;
    }
    else ///2
    {
       nuevo->siguiente = *lista;
       *lista = nuevo;

    }

}
/**
    1: puede estar vacia
    2: puede tener datos
**/

void insertarAlFinal(nodo** lista, telemento dato)
{
   nodo* seg; ///var auxiliar para recorrer
   nodo* nuevo = crearNodo(dato);
   if (*lista == NULL) ///1
   {
       *lista = nuevo;
   }
   else ///2
   {
       seg = *lista;
       while (seg->siguiente != NULL)
       {
           seg = seg->siguiente;
       }

       seg->siguiente = nuevo;
   }


}
int main()
{
  nodo* lista;
  lista = NULL;
  insertarAlPrincipio(&lista,3);

    return 0;
}
