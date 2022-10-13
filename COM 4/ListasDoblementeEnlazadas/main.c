#include <stdio.h>
#include <stdlib.h>

typedef int telemento;

typedef struct nodoD
{
    telemento dato;
    struct nodoD* siguiente;
    struct nodoD* anterior;
} nodoD;

void insertarAlPrincipio(nodoD**, telemento);
nodoD* crearNodoD(telemento);
void insertarAlFinal(nodoD**, telemento)

nodoD* crearNodo(telemento dato)
{
    nodoD* nuevo = (nodoD*)malloc(sizeof(nodoD));
    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    return nuevo;
}


void insertarAlPrincipio(nodoD** lista, telemento dato)
{
    nodoD* nuevo = crearNodoD(dato);
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        nuevo->siguiente = *lista;
        (*lista)->anterior = nuevo;
        *lista = nuevo;
    }

}

void insertarAlFinal(nodoD** lista, telemento dato)
{
    nodoD* seg;
    nodoD* nuevo = crearNodoD(dato);
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        seg = *lista;
        while (seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }

        seg->siguiente = nuevo;
        nuevo->anterior = seg; ///esto es nuevo
    }

}
/**
1 - Esta vacia
2 - Tiene datos
    a) en la cabecera
    b) en cualquier otro lado
        I) entre medio
        II) al final

**/

void insertarEnOrden(nodoD** lista, telemento dato)
{
    nodoD* seg, *ante;
    nodoD* nuevo = crearNodoD(dato);
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        if (nuevo->dato < (*lista)->dato) ///insercion en la cabecera
        {
            nuevo->siguiente = *lista;
            (*lista)->anterior = nuevo;
            *lista = nuevo;
        }
        else
        {
            seg = *lista;
            //ante = *lista;
            while (seg->siguiente != NULL && nuevo->dato > seg->dato)
            {
                seg = seg->siguiente;

            }
            if(nuevo->dato > seg->dato) ///al final de la lista
            {
                seg->siguiente = nuevo;
                nuevo->anterior = seg;
            }
            else ///interior de la lista
            {
                ante = seg->anterior; ///auxiliar para evitar el doble enlace

                nuevo->anterior = seg->anterior;
                (seg->anterior)->siguiente = nuevo; ///ante->siguiente = nuevo;
                nuevo->siguiente = seg;
                seg->anterior = nuevo;
            }
        }
    }

}

///eliminar nodo de una lista
///una forma distitna para la cabecera
void borrarNodo(nodo** lista, telemento dato)
{
    nodoD* aux;
    if (*lista != NULL)
    {
        if ((*lista)->dato == dato)
        {

            if ((*lista)-> siguiente == NULL)
            {
                free(*lista);
                *lista = NULL;
            }
            else
            {
                aux = *lista;
                *lista =  (*lista)->siguiente;
                (*lista)->anterior = NULL;
                free(aux);
            }

        }
        else
        {
            seg = (*lista)->siguiente;
            while (seg != NULL && seg->dato != dato)
            {
                seg = seg->siguiente;
            }
            if (seg != NULL)
            {
                aux = seg;
                ante = seg->anterior;
                ante->siguiente = seg->siguiente;
                seg = seg->siguiente; ///avanzo con seguidora
                if (seg != NULL)
                {
                    seg->anterior = ante;
                }

                free(aux);
            }

        }

    }


}


void borrarNodo(nodo** lista, telemento dato)
{
    nodoD* aux;
    nodoD* seg;
    nodoD* ante;
    if (*lista != NULL)
    {
        if ((*lista)->dato == dato)
        {
            aux= *lista;
            *lista = (*lista)->siguiente;
            if (*lista != NULL)
            {
                (*lista)->anterior = NULL;
            }
            free(aux);
        }
        else
        {
            seg = (*lista)->siguiente;
            while (seg != NULL && seg->dato != dato)
            {
                seg = seg->siguiente;
            }
            if (seg != NULL)
            {
                aux = seg;
                ante = seg->anterior;
                ante->siguiente = seg->siguiente;
                seg = seg->siguiente; ///avanzo con seguidora
                if (seg != NULL)
                {
                    seg->anterior = ante;
                }

                free(aux);
            }

        }

    }


}

void borrarNodoOrdenado(nodo** lista, telemento dato)
{
    nodoD* aux;
    nodoD* seg;
    nodoD* ante;
    if (*lista != NULL && (*lista)->dato <= dato)
    {
        if ((*lista)->dato == dato)
        {
            aux= *lista;
            *lista = (*lista)->siguiente;
            if (*lista != NULL)
            {
                (*lista)->anterior = NULL;
            }
            free(aux);
        }
        else
        {
            seg = (*lista)->siguiente;
            while (seg != NULL && seg->dato < dato)
            {
                seg = seg->siguiente;
            }
            if (seg != NULL && seg->dato == dato)
            {
                aux = seg;
                ante = seg->anterior;
                ante->siguiente = seg->siguiente;
                seg = seg->siguiente; ///avanzo con seguidora
                if (seg != NULL)
                {
                    seg->anterior = ante;
                }

                free(aux);
            }

        }

    }


}




int main()
{
    nodoD* lista = NULL;

    return 0;
}
