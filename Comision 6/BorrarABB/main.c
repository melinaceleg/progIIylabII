#include <stdio.h>
#include <stdlib.h>

typedef int telemento;
typedef struct nodoA
{
    telemento dato;
    struct nodoA* izq;
    struct nodoA* der;
} nodoA;


nodoA* crearNodo(telemento dato)
{
    nodoA* nuevo = (nodoA*)malloc(sizeof(nodoA));
    nuevo->dato = dato;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;
}

void insertarABB(nodoA** arbol, telemento dato)
{
    if (*arbol == NULL)
    {
        *arbol = crearNodo(dato);
    }
    else
    {
        if (dato < (*arbol)->dato)
        {
            insertarABB(&((*arbol)->izq,dato);
        }
        else
        {
            insertarABB(&((*arbol)->der),dato);
        }

    }

}


void eliminarNodo(nodoA** A, telemento clave)
{
    if (*A != NULL)
    {
        if ((*A)->dato == clave) ///si encontre el dato a borrar
        {
            nodo* aux = *A; ///guardo la direccion de memoria del nodo
            if ((*A)->izq != NULL && (*A)->der != NULL) ///es de grado 2
            {
                borrarNodo(&((*A)->der),*A); ///le enviamos el nodo *A para modificar su valor (clave) (reemplazarlo por el mas pequeno)
            }
            else
            {
                ///grado 1 o 0
                if ((*A)->izq != NULL) ///tiene rama izquierda
                {
                    (*A) = (*A)->izq;
                }
                else ///tiene rama a derecha o es hoja
                {
                    (*A) = (*A)->der;
                }

                free(aux);
            }
        }
        else
        {
            if ((*A)->dato > clave)
            {
                eliminarNodo(&((*A)->izq),clave);
            }
            else
            {
                eliminarNodo(&((*A)->der),clave);
            }
        }


    }rutina

}

///usamos criterio nodo mas a izq de rama derecha
void borrarNodoMasIzq(nodoA** A, nodoA* aux)
{
    nodo* borrar;
    if ((*A)->izq != NULL) ///me tengo que ir a la extrema izquierda
    {
        borrarNodoMasIzq(&((*A)->izq),aux);
    }
    else
    {
        aux->dato = (*A)->dato; ///reemplazo el valor
        borrar = *A; ///antes de avanzar, guardo la referencia
        (*A)= (*A)->der; ///avanza a la rama derecha, si hay enlace se reemplazara con la derecha, si no con null
        free(borrar);
    }
}




int main()
{
    nodoA* arbol = NULL;

    return 0;
}
