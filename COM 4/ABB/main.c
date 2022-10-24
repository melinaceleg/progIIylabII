#include <stdio.h>
#include <stdlib.h>

/**ARBOLES BINARIOS DE BUSQUEDA**/

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


void insertarABB(nodoA** arbol, telemento dato)
{
    if (*arbol != NULL)
    {
        if ((*arbol)->dato > dato) //si el valor de la raiz es mas grande, me muevo a izquierda
        {
            insertarABB(&((*arbol)->izq),dato);
        }
        else //si el valor de la raiz es menor, me muevo a derecha
        {
            if ((*arbol)->dato < dato)
            {
                insertarABB(&((*arbol)->der),dato);
            }
        }
    }
    else ///la direccion del campo apunta a un NULL
    {
        *arbol = crearNodoArbol(dato);
    }

}



int main()
{
    nodoA* arbol = NULL;
    insertarABB(&arbol,5);
    return 0;
}
