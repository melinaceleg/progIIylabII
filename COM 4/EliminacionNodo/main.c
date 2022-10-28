#include <stdio.h>
#include <stdlib.h>

typedef struct nodoA
{
    int dato;
    struct nodoA* izq;
    struct nodoA* der;
}nodoA;

void eliminacionNodo(nodoA** A, int dato)
{
    nodo* aux;
    if (*A != NULL)
    {
        if ((*A)->dato == dato)
        {
            aux = *A;
            if ((*A)->izq != NULL && (*A)->der != NULL) ///grado 2
            {
                borrarNodoIzq(&(*A)->izq, aux); ///voy a usar el criterio del max de la ramizq
            }
            else
            {
                if ((*A)->izq != NULL) ///tengo solo hijo a izq
                {
                    *A = (*A)->izq;
                }
                else ///si tiene hijo a derecha o es hoja
                {
                    *A =(*A)->der;
                }

                free(aux);

            }

        }
        else
        { ///si no es el dato, avanzo en la busqueda
            if ((*A)->dato > dato)
            {
                eliminacionNodo(&(*A)->izq,dato);
            }
            else
            {
                eliminacionNodo(&(*A)->der,dato);
            }
        }

    }

}


void borrarNodoIzq(nodoA** subA, nodoA* aux)
{
    nodo* aEliminar;
    if ((*subA)->der != NULL) ///me voy al maximo de la rama
    {
        borrarNodo(&(*subA)->der,aux);
    }
    else
    {
       aux->dato = (*subA)->dato; ///copio el dato en el nodo
       aEliminar = *subA;
       *subA = (*subA)->izq;
       ///me desplazo hacia la izq porque como estoy en un maximo, si tiene hijo es SOLAMENTE a izquierda
        free(aEliminar);
    }

}








int main()
{
    nodoA* arbol = NULL;
    ///cargamos el arbol
    return 0;
}
