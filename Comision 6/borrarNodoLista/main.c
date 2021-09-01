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
    nuevo->sig = NULL; ///por defecto apunta a NULL

    return nuevo;
}
//
//1. El dato esta en la cabeza
//2. El dato esta en otro lado de la lista
//aux 0x33
//1
//2->  4->  1->  3->  7->NULL
//ant   act
void eliminarNodo(nodo** lista, telemento dato)
{
    nodo* aux;
    nodo* ant;
    nodo* act;
    if (*lista != NULL)
    {
        if ((*lista)->dato == dato) ///si el dato se encuentra en la cabeza de la lista
        {
            aux = *lista;
            *lista = (*lista)->sig;
            free(aux);
        }
        else /// cualquier otro caso
        {
            ant = *lista;
            act= (*lista)->sig;
            while (act != NULL && act->dato != dato)
            {
                ant = act;
                act=act->sig;
            }
            if (act != NULL) ///si efectivamente ese dato lo encontre
            {
                ant->sig = act->sig;
                free(act);
            }
            ///si no, no hago nada
        }
    }
}
//
//    1->2->3->4->5->6->7->NULL
///elimiinacion de un nodo en una lista ordenada
void eliminarNodoOrdenada(nodo** lista, telemento dato)
{
    nodo* aux;
    nodo* ant;
    nodo* act;

    if (*lista)
    {
        if ((*lista)->dato <= dato)
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
                while (act != NULL && act->dato < dato )
                {
                    ant = act;
                    act = act->sig;
                }
                if (act != NULL && act->dato == dato)
                {
                    aux =act;
                    ant->sig = act->sig;
                    free(aux);
                }

            }
        }


    }


}



int main()
{
    nodo* lista = NULL;
    cargarLista(&lista);
    eliminarNodo
    return 0;
}
