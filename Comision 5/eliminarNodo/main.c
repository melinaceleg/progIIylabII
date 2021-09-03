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
    nuevo->sig = NULL; ///por defecto apunta hacia NADA

    return nuevo;
}

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

void cargarLista(nodo** lista)
{
    char seguir;
    telemento dato;
    do
    {
        printf("Ingrese un valor\n");
        scanf("%i",&dato);
        insercionAlFinal(lista,dato);
        printf("Desea continuar\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    while (seguir == 's');

}

///lista DESORDENADA
void eliminarNodo(nodo** lista, telemento dato)
{
    nodo* aux;
    nodo* ant;
    nodo* act;
    if (*lista != NULL)
    {
        if ((*lista)->dato == dato) ///el nodo que queremos eliminar esta en la cabecera
        {
            aux = *lista;
            *lista = (*lista)->sig;
            free(aux);
        }
        else ///cualquier otro caso
        {
            ant = *lista;
            act = (*lista)->sig;
            while (act != NULL && act->dato != dato)
            {
                ant = act;
                act=act->sig;
            }
            if (act != NULL)
            {
                ant->sig = act->sig;
                free(act);
            }
        }

    }
}
//1->2->4->7->8->9->NULL
///lista ORDENADA
void eliminarNodoOrdenada(nodo** lista, telemento dato)
{
    nodo* aux;
    nodo* act;
    nodo* ant;
    if (*lista != NULL && (*lista)->dato <= dato)
    {
        if ((*lista)->dato == dato)
        {
            aux = *lista;
            *lista = (*lista)->sig;
            free(aux);
        }
        else
        {
           ant = *lista;
           act = (*lista)->sig;
           while (act != NULL && act->dato < dato)
           {
               ant=act;
               act = act->sig;
           }
           if (act != NULL && act->dato == dato)
           {
             ant->sig = act->sig;
             free(act);
           }

        }
    }
}


int main()
{
    nodo* lista = NULL;
    cargarLista(&lista);
    eliminarNodo(&lista,3);
    return 0;
}
