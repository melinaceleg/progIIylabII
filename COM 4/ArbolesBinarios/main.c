#include <stdio.h>
#include <stdlib.h>
/* Contar la cantidad de nodos del arbol */

typedef struct nodoA
{
    int dato;
    struct nodoA* izq;
    struct nodoA* der;

}nodoA;


nodoA* crearNodoArbol(int dato)
{
  nodoA* nuevo = (nodoA*)malloc(sizeof(nodoA));
  nuevo->dato = dato;
  nuevo->izq=NULL;
  nuevo->der=NULL;

  return nuevo;
}


int contarNodosF1(nodoA* Arbol)
{
if (Arbol != NULL)
{
  return 1 + contarNodosF1(Arbol->izq) + contarNodosF1(Arbol->der);

}
else
    return 0;

}


int contarNodosF2(nodoA* Arbol)
{
    int cantidad=0;
    if (Arbol != NULL)
    {
        cantidad = 1 + contarNodosF2(Arbol->izq);
        cantidad = cantidad + contarNodosF2(Arbol->der);

    }

        return cantidad;


}




int main()
{
    nodoA* arbol = NULL;
    ///inserto raiz
    arbol = crearNodoArbol(25);
    ///cargo subarbol izquierdo
    arbol->izq = crearNodoArbol(13);
    (arbol->izq)->izq = crearNodoArbol(12);
    arbol->izq->der = crearNodoArbol(14);
    ///cargo todo subarbol derecho
    arbol->der = crearNodoArbol(46);
    arbol->der->izq = crearNodoArbol(44);
    arbol->der->der = crearNodoArbol(68);
    arbol->der->der->izq = crearNodoArbol(67);
    printf("%i", contarNodosF2(arbol));
    return 0;
}
