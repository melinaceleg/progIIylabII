#include <stdio.h>
#include <stdlib.h>

typedef struct nodoD
{
    int dato;
    struct nodoD* ant;
    struct nodoD* sig;
} nodoD;


nodoD* crearNodoDoble(int dato)
{
    nodoD* nuevo = (nodoD*)malloc(sizeof(nodoD));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    return nuevo;
}


void insertarAlPrincipioDoble(nodoD** lista, int dato)
{
    nodoD* nuevo = crearNodoDoble(dato);

    if (*lista != NULL)
    {
        (*lista)->ant = nuevo;
        nuevo->sig = *lista;
    }
    *lista = nuevo;

}

void insertarAlFinalDoble(nodoD** lista, int dato)
{
    nodoD* nuevo = crearNodoDoble(dato);
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
//casos a contemplar
/// 1. lista vacia
/// 2. insercion en la cabeza
/// 3. insercion en cualquier otro lado de la lista (tener en cuenta si act es null)
void insertarEnOrdenDoble(nodoD** lista, int dato)
{
    nodoD* ant;
    nodoD* act;
    if (*lista == NULL)
        *lista = nuevo;
    else
    {
        if ((*lista)->dato > dato)
        {
            nuevo->sig=*lista;
            (*lista)->ant = nuevo;
            *lista = nuevo;
        }
        else
        {
            ant=*lista;
            act= (*lista)->sig;
            while (act != NULL && act->dato < dato)
            {
                ant = act;
                act = act->sig;
            }
            ant->sig = nuevo;
            nuevo->ant = ant;
            nuevo->sig = act;
            if (act != NULL)
                act->ant = nuevo;
        }

    }
}

void cargarListaDoble(nodoD** lista)
{
   char seguir;
   int dato;
   do
   {
       printf("ingrese un valor\n");
       scanf("%i",&dato);
       insertarEnOrdenDoble(lista,dato);
       printf("desea seguir?\n");
       fflush(stdin);
       scanf("%c",&seguir);
   }while(seguir == 's');

}



int main()
{
    nodoD* lista = NULL;
    cargarListaDoble(&lista);
    return 0;
}
