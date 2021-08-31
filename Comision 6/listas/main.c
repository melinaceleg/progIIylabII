#include <stdio.h>
#include <stdlib.h>

typedef int telemento; ///redefino el nombre del tipo de dato y le pongo otro nombre

typedef struct nodo {
    telemento dato;
    struct nodo* sig;
}nodo;


nodo* crearNodo(telemento dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo)); ///genere mi nuevo nodo en el heap
    nuevo->dato = dato;
    nuevo->sig = NULL; ///el siguiente por defecto apunta hacia null (a nadie)

    return nuevo;
}
//lista 4       nuevito 1
//4->1->NULL



int main()
{
   nodo* lista; ///genere una variable en memoria stack de tipo nodo*
   lista = NULL; ///la lista esta vacia
   lista = crearNodo(4); ///la cabecer de la lista es el nodo que contiene el valor 5
   nodo* nuevito = crearNodo(1);
   lista->sig = nuevito;

//   printf("%i", lista->dato);
//   printf("%i", lista->sig->dato);
//   printf("%i", lista->sig->sig->dato)......

   ///genere una variable auxiliar para recorrer la lista y no pisar la cabecera,
   ///si la piso con lista pierdo el acceso al primer nodo
    nodo* laux = lista;
    while (laux != NULL)
    {
        printf("%i",laux->dato);
        laux = laux->sig;
    }

    printf("%i",lista->dato);

    return 0;
}
