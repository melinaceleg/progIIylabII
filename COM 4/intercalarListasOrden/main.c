#include <stdio.h>
#include <stdlib.h>



typedef int telemento;
typedef struct nodo
{
    telemento dato;
    struct nodo* siguiente;

} nodo;

///prototipado
nodo* crearNodo(telemento);
void intercalarListas(nodo*,nodo*,nodo**);



nodo* crearNodo(telemento dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo)); ///genero el espacio de ese nodo
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
}

void insertarNodoAlFinal(nodo** lista, nodo* nuevo)
{
    nodo* seg; ///var auxiliar para recorrer
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

void intercalarListas(nodo* lista1,nodo* lista2,nodo** lista3)
{
    nodo* aux,*aux2;
    while (lista1 != NULL && lista2 != NULL)
    {
        if (lista1->dato > lista2->dato)
        {
            aux = lista2;
            lista2 = lista2->siguiente;
            aux->siguiente = NULL; ///lo desenlazamos para no llevarnos toda la lista
            insertarNodoAlFinal(lista3,aux);
        }
        else
        {
            if (lista->dato < lista2->dato)
            {
                aux = lista1;
                lista1 = lista1->siguiente;
                aux->siguiente = NULL;
                insertarNodoAlFinal(lista3,aux);
            }
            else ///para no pasar datos repetidos
            {
                aux = lista1;
                aux2= lista2;
                lista1 = lista1->siguiente;
                lista2 = lista2->siguiente;
                aux->siguiente = NULL;
                insertarNodoAlFinal(lista3,aux);
                free(aux2);

            }
        }
    }

    if (lista2 != NULL)
    {
        insertarNodoAlFinal(lista,lista2);
    }
    else if (lista1 != NULL)
    {
        insertarNodoAlFinal(lista3,lista1);
    }


}




int main()
{
    printf("Hello world!\n");
    return 0;
}
