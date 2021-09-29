#include <stdio.h>
#include <stdlib.h>
#define DIM 20

typedef struct
{
    automovil dato;
    struct nodoAuto * sig;
} nodoAuto;

typedef struct
{
    char patente[6];
    int valor;
    char marca[10];
} Automovil;


///prototipados
nodoAuto* crearNodo(Automovil);
void agregarAlFinal(nodoAuto**,nodoAuto*);
int insertarCelda(Automovil[],Automovil,int);
void agregarMuchos(nodoAuto**);
int pasar(nodoAuto*, Automovil[]);
void mostrarArregloRecursivo(Automovil[], int, int);
int sumarPar(nodoAuto*);
void sumarParVoid(nodoAuto*, int*);

////
///1
nodoAuto* crearNodo(Automovil dato)
{
    nodoAuto* nuevo = (nodoAuto*)malloc(sizeof(nodoAuto));
    nuevo->dato = dato;
    nuevo->sig = NULL;

    return nuevo;
}

//2
void agregarAlFinal(nodoAuto** lista,nodoAuto* nuevo)
{
    nodoAuto* aux;
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        aux = *lista;
        while (aux->sig != NULL)
        {
            aux=aux->sig;
        }

        aux->sig = nuevo;
    }
}

///3
int insertarCelda(Automovil automoviles[],Automovil dato,int validos)
{
    if (validos == 0)
    {
        automoviles[validos]=automovil;
    }
    else
    {
        int i = validos -1;
        ///insercion ordenada
        while ( i>=0 && dato.valor > automoviles[i].valor)
        {
            automoviles[i+1] = automoviles[i];
            i--;
        }
        automoviles[i+1] = dato;
    }

    validos++;

    return validos;
}

///4
void agregarMuchos(nodoAuto** lista)
{
    char seguir;
    Automovil automovil;
    nodoAuto* nuevo;
    do
    {
        printf("Ingrese datos de automovil\n");
        printf("Ingrese patente\n");
        fflush(stdin);
        gets(automovil.patente);
        printf("Ingrese marca\n");
        fflush(stdin);
        gets(automovil.marca);
        printf("Ingrese valor\n");
        scanf("%i",automovil.valor);
        nuevo = crearNodo(automovil);
        agregarAlFinal(lista,nuevo);
        ///agregarAlFinal(lista,crearNodo(automovil));
        printf("desea seguir\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    while(seguir == 's');

}

///5
int pasar(nodoAuto* lista, Automovil automoviles[])
{
    int validos = 0;
    while (lista != NULL && validos < dim)
    {
        validos = insertarCelda(automoviles,lista->dato,validos);
        lista=lista->sig;
    }

    return validos;

}

///6

void mostrarAutomovil(Automovil automovil)
{
    printf("Patente: %s\n",automovil.patente);
    printf("Marca: %s\n",automovil.marca);
    printf("Valor: %i\n",automovil.valor);
}

void mostrarArregloRecursivo(Automovil automoviles[], int i, int pos).
{
    if (i <= pos)
    {
        mostrarAutomovil(automoviles[i]);
        mostrarArregloRecursivo(automoviles,i+1,pos);
    }
}

///7
int sumarPar(nodoAuto* lista)
{
    int num;
    if (lista != NULL)
    {
        num = (int)lista->dato.patente[5];
        //num = strbol(lista->dato.patente[5]);
        if (num % 2 == 0)
        {
            return lista->dato.valor + sumarPar(lista->sig); ///llamada recursiva, acerc cond.
        }
        else
        {
            return sumarPar(lista->sig); ///llamada recursiva, acercamiento cond. corte
        }

    }
    else //lista == null cond de corte
    {
        return 0; ///sol trivial
    }

}

///7
///el parametro suma no esta inicializado
void sumarParVoid(nodoAuto* lista, int* suma)
{
    int num;

    if (lista == NULL)
    {
        *suma = 0;
    }
    else
    {
        sumarParVoid(lista->sig,suma);
        num = (int)lista->dato.patente[5];
        if (num % 2 == 0)
        {
            *suma = *suma + lista->dato.valor;
        }
    }
}





int main()
{
    int validos;
    int suma;
    Automovil automoviles[DIM];
    nodoAuto* lista = NULL;
    agregarMuchos(&lista);
    validos = pasar(lista,automoviles);
    mostrarArregloRecursivo(automoviles,0,5);
    sumaParVoid(lista,&suma);
    printf("la suma es %i\n", suma);
    printf("la suma es %i\n", sumaPar(lista));
    return 0;
}
