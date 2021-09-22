#include <stdio.h>
#include <stdlib.h>

typedef int telemento;

typedef struct nodo
{
    int dato; //0x44
    struct nodo* sig; //0x45
} nodo;

0x45 = crearNodo(dato);

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
void insercionAlPrincipio(nodo** lista, telemento dato)
{
    nodo* nuevo = crearNodo(dato);
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        nuevo->sig = *lista;
        *lista = nuevo;

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

//1. condicion de corte
//2. llamada recursiva
//3. aproximacion a la condicion de corte
//4. solucion trivial (con retorno)
void mostrarListaRec(nodo* lista)
{
    if (lista != NULL) //1
    {
        printf("%i", lista->dato);
        mostrarListaRec(lista->sig); //2-3
    }
}

void mostrarListaInvRec(nodo* lista)
{
    if (lista != NULL)
    {
        mostrarListaInvRec(lista->sig);
        printf("%i",lista->dato);
    }
}

//1. condicion de corte
//2. llamada recursiva
//3. aproximacion a la condicion de corte
//4. solucion trivial (con retorno)

int sumarListaRec(nodo* lista)
{
  if (lista != NULL)
  {
      return lista->dato + sumaListaRec(lista->sig); //2-3

  }
  else //1 (lista == NULL)
    return 0; //4

}

int sumaListarec(nodo* lista)
{
    if (lista == NULL) //1
    {
        return 0; //4
    }
    else
    {
      return lista->dato + sumaListaRec(lista->sig); //2-3
    }
}

NULL
 *suma = 0 + 1
   *suma = 1 + 4
     *suma = 5 + 6
*suma=11


///considerando que suma=0 en el main
void sumarListaRecVoid(nodo* lista, int* suma)
{
    if (lista != NULL)
    {
        *suma += lista->dato;
        sumarListaRecVoid(lista->sig,suma);
    }
}
1->4->7->NULL
///inicializando la variable dentro de la funcion
void sumarListaRecVoid2(nodo* lista, int* suma)
{
  if (lista == NULL)
  {
      *suma = 0;
  }
  else
  {
     sumarListaRecVoid2(lista->sig,suma);
     *suma += lista->dato;
  }


}


///recibo la direccion de memoria de una variable
///que almacena el primer nodo de la lista
///ingreso al nodo
///envio direccion del CAMPO SIG
///para poder modificarlo
void insercionAlFinalRec(nodo** lista, int dato)
{
   if (*lista == NULL)
   {
       *lista = crearNodo(dato);
   }
   else
   {
    insercionAlFinalRec(&((*lista)->sig)),dato);
   }
}

int main()
{
    nodo* lista = NULL;
    cargarLista(&lista);
    //mostrarListaRec(lista);
    mostrarListaInvRec(lista);
    return 0;
}
