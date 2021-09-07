#include "Pila.h"


nodop* crearNodo(telemento dato)
{
    nodop* nuevo = (nodop*)malloc(sizeof(nodop));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}



void inicPila(Pila* p)  ///nodo** p
{
    *p = NULL;
}


void apilar(nodop** p,telemento dato)
{
    nodop* nuevo = crearNodo(dato);

    if (*p == NULL)
    {
        *p = nuevo;
    }
    else
    {
        nuevo->sig = *p;
        *p = nuevo;
    }
}


int desapilar(nodop** p)
{
    telemento dato;
    nodop* aux;
    if (*p != NULL)
    {
        aux = *p;
        dato = aux->dato;
        *p = (*p)->sig;
        free(aux);
    }

    return dato;
}


int pilaVacia(nodop* p) ///nodop* p
{
    return (p == NULL);
}


telemento tope(nodop* p) ///nodop* p
{

    return p->dato;

}

void leer(Pila* p) ///nodop** p
{
    telemento dato;
    printf("Ingrese un valor\n");
    scanf("%i",&dato);
    apilar(p,dato);
}

//tope 3->5->4->NULL base


void mostrar(Pila p) ///nodop* p
{
    printf("tope ......");
    while (p != NULL)
    {
        printf("%i ", p->dato);
        p=p->sig;
    }
    printf("....base\n");
}
