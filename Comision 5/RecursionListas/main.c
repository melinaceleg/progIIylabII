#include <stdio.h>
#include <stdlib.h>
typedef int telemento;

typedef struct nodo
{
    int dato; //0x44
    struct nodo* sig; //0x45
} nodo;


nodo* crearNodo(int dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo)); ///genere mi nuevo nodo en el heap
    nuevo->dato = dato;
    nuevo->sig = NULL; ///el siguiente por defecto apunta hacia null (a nadie)

    return nuevo;
}


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

void cargarLista(nodo** lista)
{
    char seguir;
    int valor;
    do
    {
        printf("Ingrese un dato\n");
        scanf("%i",&valor);
        insercionAlFinal(lista,valor);
        //insercionAlPrincipio(lista,valor);
        printf("Desea continuar\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    while (seguir == 's');

}

/**
1. Condicion de corte
2. Llamada recursiva
3. acercamiento a condicion de corte
4. solucion trivial
**/

void mostrarListaRec(nodo* lista)
{
    if (lista != NULL)
    {
        printf("%i ", lista->dato);
        mostrarListaRec(lista->sig); ///2-3

    }
    ///condicion de corte (lista == NULL)
}

void mostrarListaInvRec(nodo* lista)
{
    if (lista != NULL)
    {
        mostrarListaInvRec(lista->sig); //2-3
        printf("%i ",lista->dato);
    }
    ///condicion de corte (lista == NULL)

}

/**
1. Condicion de corte
2. Llamada recursiva
3. acercamiento a condicion de corte
4. solucion trivial
**/
//  return 2 + 12
//    return 5 + 7
//     return 7 + 0

int sumaRec(nodo* lista)
{
    if (lista != NULL)
    {
        return lista->dato + sumaRec(lista->sig);

    }
    else
        return 0;

}
///sabiendo que suma esta inicializada en 0
void sumaRecVoid(nodo* lista, int* suma)
{
    if (lista != NULL)
    {
        *suma += lista->dato;
        sumaRecVoid(lista->sig,suma);
    }

}

///suma no esta inicializada en 0
void sumaRecVoidInic(nodo* lista, int* suma)
{
    if (lista == NULL)
    {
        *suma = 0;
    }
    else
    {
        sumaRecVoidInic(lista->sig,suma);
        *suma += lista->dato;
    }
}

2->5->7
5->7->NULL
7->nuevo
nuevo
typedef struct nodo
{
    int dato; //0x44
    struct nodo* sig; //0x45
} nodo;


void insercionAlFinalRec(nodo** lista, int dato)
{
    if (*lista == NULL)
    {
        *lista = crearNodo(dato);
    }
    else
    {
        insercionAlFinalRec(&((*lista)->sig),dato);
    }
}
6

2->5->7->NULL

5->6->7->NULL

6->7->NULL

void insercionOrdenadaRec(nodo** lista, int dato)
{
    if (*lista == NULL)
    {
        *lista = crearNodo(dato);
    }
    else
    {
        if (dato > (*lista)->dato) ///avanzo con la dir del campo siguiente
        {
            insercionOrdenadaRec(&((*lista)->sig),dato);
        }
        else
        {
            ///insercion al principio
            nodo* nuevo = crearNodo(dato);
            nuevo->sig = *lista;
            *lista = nuevo;
        }
    }
}


int main()
{
    nodo* lista = NULL;
    cargarLista(&lista);
    int suma;
    //  mostrarListaRec(lista);
    mostrarListaInvRec(lista);
    //printf("suma es %i\n",sumaRec(lista));
    sumaRecVoidInic(lista,&suma);
    printf("suma es %i\n",suma);


    return 0;
}
