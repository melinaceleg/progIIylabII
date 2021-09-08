#include <stdio.h>
#include <stdlib.h>

typedef struct nodoD
{
    int dato;
    struct nodoD* ant;
    struct nodoD* sig;
} nodoD;

//typedef struct TLista
//{
//    nodoD* head;
//    nodoD* tail;
//
//}TLista;



nodoD* crearNodoD(int dato)
{
    nodoD* nuevo = (nodoD*)malloc(sizeof(nodoD));
    nuevo->dato = dato;
    nuevo->ant = NULL;
    nuevo->sig = NULL;
    return nuevo;
}

//NULL
//
//NULL <-nuevo -> 2
//lista
//NULL <-nuevo -> <-2 -> <- 3 -> NULL

void insertarAlPrincipioD(nodoD** lista, int dato)
{
    nodoD* nuevo = crearNodoD(dato);

    nuevo->sig = *lista;
    if (*lista != NULL)
        (*lista)->ant = nuevo;
    *lista = nuevo;
}


void insercionAlfinal(nodoD** lista, int dato)
{
    nodoD* nuevo = crearNodo(dato);
    nodoD* act;
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        act = *lista;
        while (act->sig != NULL)
        {
            act=act->sig;
        }
        act->sig = nuevo;
        nuevo->ant = act;
    }

}

void insertarEnOrdenD(nodoD** lista, int dato)
{
    nodoD* nuevo = crearNodo(dato);
    nodoD* ant;
    nodoD* act;
    if (*lista == NULL) //si la lista esta vacia
    {
        *lista = nuevo;  ///la lista sera el nodo nuevo
    }
    else
    {
        if ((*lista)->dato > dato)  //si la cabeza es mas grande que el dato a insertar
        {
            nuevo->sig = *lista;
            (*lista)->ant = nuevo;
            *lista = nuevo;
        }
        else
        {
            ant = *lista;
            act = (*lista)->sig;
            while (act != NULL && act->dato < dato)
            {
                ant = act;
                act=act->sig;
            }
            ant->sig = nuevo;
            nuevo->ant = ant;
            nuevo->sig = act;
            if (act != NULL) ///si la insercion no es al final
            {
                act->ant = nuevo;
            }

        }


    }
}

void cargarListaDoble(nodoD** lista)
{
    char seguir;
    int valor;
    do
    {
        printf("Ingrese un valor\n");
        scanf("%i",&valor);
        insertarAlPrincipioD(lista,valor);
        printf("Desea continuar?\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    while(seguir == 's');

}

void muestraLista(nodoD* lista)
{
    while (lista != NULL)
    {
        printf("%i ",lista->dato);
        lista=lista->sig;
    }
}

void borrarNodoD(nodoD* lista, int dato)
{
    nodo* aux;
    nodo* ant;
    nodo* act;
    if (*lista != NULL)
    {
        if (*lista->dato == dato) // si el dato esta en la cabecera
        {
            aux = *lista;
            *lista = (*lista)->sig;
            (*lista)->ant = NULL; //lo nuevo!
            free(aux);
        }
        else
        {
            ant = *lista;
            act = (*lista)->sig;

            while (act != NULL && act->dato != dato)
            {
                ant = act;
                act= act->sig;
            }
            if (act != NULL) ///si encontraste el dato
            {
                aux = act; //nodo a borrar
                act=act->sig;   //avanzo al siguiente
                ant->sig = act; //puentecito por arriba
                if (act != NULL)
                {
                    act->ant = ant; //puentecito por abajo
                }
                free(aux); ///libero el nodo
            }
        }

    }


}


int main()
{
    nodoD* lista = NULL;
    cargarListaDoble(&lista);
    return 0;
}
