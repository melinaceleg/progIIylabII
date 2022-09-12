#include <stdio.h>
#include <stdlib.h>

typedef int telemento;

typedef struct nodo
{
    telemento dato;
    struct nodo* siguiente;
} nodo;

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
/**
 1: la lista esta vacia
 2: tiene datos
          a) tenga que insertar en la cabecera (es mas chico que todos)
          b) tenga que insertar en CUALQUIER otro lado de la lista

**/

void insertarEnOrden(nodo**lista, telemento dato)
{
    nodo* seg, *ante;
    nodo* nuevo = crearNodo(dato);
    if (*lista == NULL) ///1
    {
        *lista = nuevo;

    }
    else ///2
    {
        if ( (*lista)->dato >= dato) ///a)
        {
            nuevo->siguiente = *lista;
            *lista = nuevo;
        }
        else  ///b)
        {
            ante = *lista;
            seg = (*lista)->siguiente;
            while (seg != NULL && seg->dato < dato)
            {
                ante = seg;
                seg= seg->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->siguiente = seg;

        }

    }
}




void cargarLista(nodo** lista)
{
    FILE* fp = fopen("Archivo.bin", "rb");
    if (fp)
    {
        while (fread(&dato,sizeof(Dato),1,fp) > 0)
        {
            insertarAlfinal(lista,dato);
        }
    }


}



void mostrarLista(nodo* lista)
{
    while (lista != NULL)
    {
        printf("%i ", lista->dato);
        lista = lista->siguiente;
    }

}

////lista desordenada
int buscarLista(nodo* lista, telemento dato)
{
    while(lista != NULL && dato != lista->dato)
    {
        lista = lista->siguiente;
    }
    if(lista != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

// o puedo:  return (lista != NULL)

}


////lista ordenada
int buscarLista(nodo* lista, telemento dato)
{
    while(lista != NULL && dato > lista->dato)
    {
        lista = lista->siguiente;
    }
    if(lista != NULL && dato == lista->dato)
    {
        return 1;
    }
    else
    {
        return 0;
    }

// o puedo:  return (lista != NULL && dato == lista->dato)

}





int main()
{
    nodo* lista;
    lista = NULL;
    insertarEnOrden(&lista,3);
    mostrarLista(lista);
    //cargarLista(&lista);
    return 0;
}
