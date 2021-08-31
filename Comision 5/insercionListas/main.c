#include <stdio.h>
#include <stdlib.h>

typedef int telemento;

typedef struct nodo
{
    telemento dato;
    struct nodo* sig;
} nodo;

typedef struct
{
    char nombre[30];
    int edad;
}Persona;

nodo* crearNodo(telemento dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->sig = NULL; ///por defecto apunta hacia NADA

    return nuevo;
}

//lista NULL
//lista 3->4->7->9->8->10->NULL
//laux 8->10->NULL
//nuevo 10->NULL
void insercionAlFinal(nodo** lista, telemento dato)
{
    nodo* nuevo = crearNodo(dato);
    nodo* laux;
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        laux = *lista; ///almaceno cabecera de la lista en nodo auxiliar para no perder la referencia
        while (laux->sig != NULL) ///hasta que no llegue a un nodo donde no apunta a nadie
        {
            laux = laux->sig; ///avanzo
        }

        laux->sig = nuevo; ///modifico campo interno del nodo
    }

}
//lista NULL
//
//lista 2->3->8->9->NULL

void insercionAlPrincipio(nodo** lista, telemento dato)
{
    nodo* nuevo = crearNodo(dato);
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        nuevo->sig = *lista;
        *lista = nuevo;
    }
}
//dato 3
//lista NULL
//lista 3->5->6->7->8->NULL ///debe ir en la cabecera
//
//
//dato 5
//lista 3->4->  7->8->NULL

void insercionEnOrden(nodo** lista, telemento dato)
{
   nodo* nuevo = crearNodo(dato);
   nodo* act;
   nodo* ant;
   if (*lista == NULL)
   {
       *lista = nuevo;
   }
   else
   {
       if ((*lista)->dato >= dato) ///tengo que insertar en la cabecera
       {
         nuevo->sig = *lista;
         *lista = nuevo;
       }
       else ///en cualquier otro lado de la lista
       {
         act = (*lista)->sig;
         ant = *lista;
         while (act != NULL && act->dato < dato)
         {
             ant=act;
             act=act->sig;
         }

         ant->sig = nuevo;
         nuevo->sig = act;
       }
   }


}

void cargarLista(nodo** lista)
{
  char seguir;
  telemento dato;
  do
  {
      printf("Ingrese un valor\n");
      scanf("%i",&dato);
      //insercionAlFinal(lista,dato);
      insercionAlPrincipio(lista,dato);
      printf("Desea continuar\n");
      fflush(stdin);
      scanf("%c",&seguir);
  }while (seguir == 's');

}
///retorno 1 o 0 si encontro o no
int busquedaLista(nodo* lista, telemento dato)
{
    while (lista != NULL && lista->dato != dato)
    {
        lista=lista->sig;
    }
//    if (lista == NULL)
//        return 0;
//    else
//        return 1;
//
    return (lista != NULL);
}

//3
//
//6->5->3->8->NULL

///en el caso de que DEBAMOS retornar un nodo
nodo* busquedaListaNodo(nodo* lista, telemento dato)
{
    while (lista != NULL && lista->dato != dato)
    {
        lista=lista->sig;
    }
//    if (lista == NULL)
//        return NULL;
//    else
//        return lista;

     return lista;
}


///busqueda en listas ordenadas
int busquedaListaOrdenada(nodo* lista, telemento dato)
{
    while(lista != NULL && lista->dato < dato)
    {
        lista=lista->sig;
    }

   return (lista != NULL && lista->dato == dato);

}


nodo* busquedaListaOrdenadaNodo(nodo* lista, telemento dato)
{
    nodo* aux = NULL;
    while (lista != NULL && lista->dato < dato)
    {
        lista=lista->sig;
    }
//    if (lista != NULL && lista->dato == dato)
//    {
//        return lista;
//    }
//    else
//        return NULL;
      if (lista != NULL && lista->dato == dato)
        aux = lista;

      return aux;
}




void mostrarLista(nodo* lista)
{
    while (lista != NULL)
    {
        printf("%i ",lista->dato);
        lista = lista->sig;
    }
}

int main()
{
    nodo* lista = NULL;
    cargarLista(&lista);
    mostrarLista(lista);
    if (busquedaLista(lista,5) == 1)
        printf("El dato esta\n");
    else
        printf("El dato no esta\n");
    nodo* busc = busquedaListaNodo(lista,5);
    mostrarLista(busc); ///mostraria una sublista a partir de ese nodo

    return 0;
}
