#include <stdio.h>
#include <stdlib.h>

typedef int telemento;
typedef struct nodoA
{
    telemento dato;
    struct nodoA* izq;
    struct nodoA* der;
} nodoA;


nodoA* crearNodoArbol(telemento dato)
{
    nodoA* nuevo = (nodoA*)malloc(sizeof(nodoA));
    nuevo->dato=dato;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;
}

void insertar(nodoA** arbol, telemento dato)
{
    if (*arbol == NULL)
    {
        *arbol = crearNodoArbol(dato);
    }
    else
    {
        if (dato < (*arbol)->dato)
        {
            insertar(&(*(arbol)->izq),dato);
        }
        else
        {
            insertar(&((*arbol)->der),dato);
        }

    }

}


void eliminarNodoABB(nodoA** A, int clave)
{
    nodoA* aux;
    if (*A != NULL)
    {
        if ((*A)->dato == clave)
        {
            aux = *A;
            if ((*A)->izq != NULL && (*A)->der != NULL) //grado 2
            {
                borrarNodoMasIzq(&((*A)->der),aux); ///uso criterio mas izquierdo de la rama derecha

            }
            else ////estoy parado en un nodo de grado 1 u hoja
            {
                if ((*A)->der != NULL)
                {
                    *A = (*A)->der;
                }
                else ///tendra enlace a izquierda o sera null
                {
                    *A = (*A)->izq;
                }
            }
        }
        else
        {
            if ((*A)->dato > clave)
            {
                eliminarNodoABB(&((*A)->izq),clave);
            }
            else
            {
                eliminarNodoABB(&((*A)->der),clave);
            }


        }


    }

}

void borrarNodoMasIzq(nodoA** A, nodoA* aux)
{
    nodoA* elim;
    if ((*A)->izq != NULL) ///busco la extrema izquierda (minimo)
    {
        borrarNodo(&((*A)->izq),aux);
    }
    else ///estoy parado en el nodo con el valor mas pequeno
    {
        ///yo se que este nodo es de grado 1 o 0, y si tiene enlace, es a derecha
        elim = *A;
        aux->dato = elim->dato; ///reemplazo el valor
        (*A) = (*A)->der;
        free(elim);
    }


}

void borrarNodoMasDer(nodoA** A, nodoA* aux)
{
    nodoA* elim;
    if ((*A)->der != NULL) ///busco la extrema derecha (maximo)
    {
        borrarNodo(&((*A)->der),aux);
    }
    else ///estoy parado en el nodo con el valor mas grande
    {
        ///yo se que este nodo es de grado 1 o 0, y si tiene enlace, es a izquierda
        elim = *A;
        aux->dato = elim->dato; ///reemplazo el valor
        (*A) = (*A)->izq;
        free(elim);
    }


}




int main()
{
    nodoA* arbol = NULL;
    ///cargamos con datos...
    return 0;
}
