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
/**
  1- el dato esta
    a) en la cabecera
    b) en el resto de la lista

  2- el dato no este


**/
///lista desordenada
void borrarDato(nodo** lista, telemento dato)
{
    nodo*seg,*ante, *aux;

    if (*lista != NULL)
    {
        if ((*lista)->dato == dato) /// 1-a
        {
            aux = *lista;
            *lista = (*lista)->siguiente;
            free(aux);
        }
        else ///1-b
        {
            ante = *lista;
            seg = (*lista)->siguiente;
            while (seg != NULL && seg->dato != dato)
            {
                ante = seg;
                seg=seg->siguiente;
            }
            if (seg != NULL) ///si encontro el dato, lo borro
            {
                ante->siguiente = seg->siguiente;
                free(seg);
            }
        }
    }



}


///lista ordenada
void borrarDato(nodo** lista, telemento dato)
{
    nodo*seg,*ante, *aux;

    if (*lista != NULL && dato >= (*lista)->dato)
    {
        if ((*lista)->dato == dato) /// 1-a
        {
            aux = *lista;
            *lista = (*lista)->siguiente;
            free(aux);
        }
        else ///1-b
        {
            ante = *lista;
            seg = (*lista)->siguiente;
            while (seg != NULL && seg->dato < dato)
            {
                ante = seg;
                seg=seg->siguiente;
            }
            if (seg != NULL && seg->dato == dato) ///si encontro el dato, lo borro
            {
                ante->siguiente = seg->siguiente;
                free(seg);
            }
        }
    }



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
