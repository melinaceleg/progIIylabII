#include <stdio.h>
#include <stdlib.h>

typedef int telemento;

typedef struct nodo
{
    telemento dato;
    struct nodo* sig;
} nodo;

nodo* crearNodo(telemento dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->sig = NULL;

    return nuevo;
}

//NULL
//
//1->4->6->nuevito->NULL

void insercionAlFinal(nodo** lista,telemento dato)
{
    nodo* nuevito = crearNodo(dato);
    nodo* laux;
    if (*lista == NULL) ///si la lista esta vacia
    {
        *lista = nuevito;
    }
    else /// si la lista no esta vacia
    {
        laux = *lista; ///creo variable auxiliar para almacenar cabeza de la lista (asi no pierdo la referencia en la original)
        while (laux->sig != NULL)
        {
            laux= laux->sig;
        }

        laux->sig = nuevito;

    }

}
//NULL
//
//lista 4->5->3->4->2->NULL

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
nuevo (4)

NULL

3->4->5->NULL

1-> 2-> 3->  5->6->NULL
ant   act
1->2->3->4->5->6->NULL
nuevo->sig = act
             ant-> nuevo;
void insercionEnOrden(nodo** lista, telemento dato)
{
    nodo* nuevo = crearNodo(dato);
    nodo* act,ant;
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        if(nuevo->dato < (*lista)->dato)
        {
            nuevo->sig = *lista; ///insercion al principio
            *lista = nuevo;
        }
        else
        {
            act = (*lista)->sig;
            ant = (*lista);
            while (act != NULL && act->dato < nuevo->dato )
            {
                ant = act;
                act= act->sig;

            }
            nuevo->sig = act;
            ant->sig=nuevo;
        }
    }
}


void cargarLista(nodo** lista)
{
    char seguir;
    int valor;
    do
    {
        printf("Ingrese un dato\n");
        scanf("%i",&valor);
        // insercionAlFinal(lista,valor);
        insercionAlPrincipio(lista,valor);
        printf("Desea continuar\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    while (seguir == 's');

}


void muestraLista(nodo* lista)
{
    while (lista != NULL)
    {
        printf("%i ",lista->dato);
        lista=lista->sig;
    }
}

int main()
{
    nodo* lista = NULL; ///siempre inicializo la lista en null
    cargarLista(&lista);
    //insercionAlFinal(&lista,4);
    muestraLista(lista);

    return 0;
}
