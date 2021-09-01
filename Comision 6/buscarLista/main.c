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

///consideraciones
///lista vacia
///lista con datos
//NULL
//3->4->2->7->5->NULL
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
        laux = *lista; ///para no perder la cabecera de la lista, ya que viene por referencia
        while (laux->sig != NULL)
        {
            laux =laux->sig;
        }

        laux->sig = nuevo;
    }

}

void cargarLista(nodo** lista)
{
    char seguir;
    telemento dato;
    do
    {
        printf("Inserte un valor\n");
        scanf("%i",&dato);
        insercionAlFinal(lista,dato);
        printf("desea seguir\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    while( seguir == 's');
}

///BUSQUEDA
/// 1. si la lista esta desordenada
/// 2. si la lista esta ordenada

///1
///busqueda de un dato que me retorne si esta o no esta (1 o 0)
//16->2->5->8>NULL
int busquedaLista(nodo* lista, telemento dato)
{
//    int busca = 0;
    while (lista != NULL && lista->dato != dato)
    {
        lista= lista->sig;
    }
//    if (lista != NULL)
//        busca = 1;
//
//    return busca;

    return (lista != NULL);
}

///2
//2->3->4->5->6->NULL
int busquedaListaOrdenada(nodo* lista, telemento dato)
{
    while(lista != NULL && lista->dato < dato)
    {
        lista=lista->sig;
    }
//    if (lista != NULL && lista->dato == dato)
//    {
//        return 1;
//    }
//    else
//        return 0;

    return (lista != NULL && lista->dato == dato);

}
//3
//
//1->2->3->4->5->NULL
//
//3->4->5->NULL

///busqueda de un dato y retornar el nodo(sublista) al cual pertenece
/// me devolvera NULL si no esta, de lo contrario un nodo (sublista)
///1 (desordenada)
nodo* busquedaListaNodo(nodo* lista, telemento dato)
{
    while (lista != NULL && lista->dato != dato)
    {
        lista=lista->sig;
    }

    return lista;
}

///2(ordenada)

nodo* busquedaListaNodoOrdenada(nodo*lista, telemento dato)
{
    while (lista != NULL && lista->dato < dato)
    {
        lista=lista->sig;
    }
    if (lista != NULL && lista->dato == dato)
    {
        return lista;
    }
    else
    {
        return NULL;
    }
}

void mostrarLista(nodo* lista)
{
    while (lista != NULL)
    {
        printf("%i ", lista->dato);
        lista = lista->sig;
    }
}





int main()
{
    nodo* lista = NULL;
    nodo* sublista;
    cargarLista(&lista);
    mostrarLista(lista);
    if (busquedaLista(lista,4) ==1 )
    {
        printf("el dato esta\n");
    }
    else
        printf("El dato no esta\n");

    sublista = busquedaListaNodo(lista,4);
    printf("\n");
//    if (sublista != NULL)
//        printf("%i", sublista->dato);
    mostrarLista(sublista);
//    busquedaListaOrdenada(lista,4);


    return 0;
}
