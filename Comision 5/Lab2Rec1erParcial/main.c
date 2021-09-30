#include <stdio.h>
#include <stdlib.h>
#define archPersonas "Personas.dat"
#define archNotas "notas.dat"
#include "Fila.h"

typedef struct
{
    char nombre[20];
    int edad;
    char DNI[9];
}Persona;

typedef struct
{
    char DNI[9];
    int nota;
}Nota;

typedef struct
{
    Persona p;
    float prom_nota;
}Alumno;


///nodo de lista
typedef struct nodo
{
    Alumno dato;
    struct nodo* sig;
}nodo;


///prototipados
nodo* crearNodo(Alumno dato);
void agregarAlPrincipio(nodo**,Alumno);


///1
/**Hacer una función que agregue un nuevo nodo al principio de una lista de Alumnos. La función recibe una lista
 y el dato de tipo Alumno.**/

nodo* crearNodo(Alumno dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->sig = NULL;
    return nuevo;
}

void agregarAlPrincipio(nodo** lista, Alumno dato)
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
///

///2

float promNotasPersona(char* DNI)
{
    float sumanotas=0;
    Nota n;
    int i=0;
    FILE *fp = fopen("notas.dat","rb");
    if (fp)
    {
        while (fread(&n,sizeof(Nota),1,fp)>0 && i < 2)
        {
            if (strcmp(DNI,n.DNI) == 0)
            {
                sumanotas = sumanotas + n.nota;
                i++;
            }

        }

        fclose(fp);
    }
    return sumanotas/2;
}


void cargarLista(nodo** lista)
{
    FILE* fp = fopen(archPersonas,"rb");
    Alumno alumno;
    Persona persona;
    if (fp)
    {
        while (fread(&persona,sizeof(Persona),1,fp)>0)
        {
            alumno.p = persona;
            alumno.prom_nota = promNotasPersona(alumno.p.DNI);
            agregarAlPrincipio(lista,alumno);
        }

        fclose(fp);
    }
}

//////////////

///6
void pasarDnisAFila (nodoAlumno * lista,  Fila* dnis)
{
    while (lista != NULL)
    {
        if (lista->dato.p.edad > 22)
        {
            poneFila(dnis,lista->dato.p.DNI);
        }
     lista=lista->sig;
    }
}

///7
/**
(Recursivo) Hacer una función que muestre
los DNIS de la fila en orden inverso al de
la fila, no perder la fila!
(no se puede hacer dentro del TDA)**/

///supogo aux inicializado en el main

1234->1238->1237

t= 1234
aux 1234


1234->1238...
t= 1238
aux 1238->1237


1234
t= 1237
aux 1238->1237


vacia


void mostrarFila(Fila* f, Fila* aux)
{
    Telemento t;
    if (!filaVacia(*f))
    {
        strcpy(t,frente(f));
        poneFila(aux,sacaFila(f));
        mostrarFila(f,aux);
        poneFila(f,sacaFila(aux));
        printf("%s\n",t);
    }
}


int main()
{
    nodo* lista = NULL;
    Fila dnis;
    inicFila(&dnis);


    return 0;
}
