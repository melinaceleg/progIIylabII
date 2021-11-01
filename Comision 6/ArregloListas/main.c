#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[30];
    char nom_Materia[30];
    int idMateria;
} RegistroArchivo;

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[30];
} notaAlumno;


typedef struct _nodo
{
    notaAlumno dato;
    struct _nodo *sig;
} nodo;


typedef struct
{
    int idMateria;
    char nom_materia[30];
    nodo * listaDeNotas;
} Materia;


nodo* crearNodo(notaAlumno dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->sig=NULL;
    return nuevo;
}

void insertarAlFinal(Materia* arr, Materia m, int* validos)
{

    arr[*validos] = m;
    (*validos)++;
}

Materia crearMateria(int idMateria, char* nomMateria)
{
    Materia m;
    m.idMateria = idMateria;
    strcpy(m.nom_materia,nomMateria);
    m.listaDeNotas = NULL;

    return m;
}

int busquedaMateria(Materia* arreglo,int idMateria, int validos)
{
    int i = 0;
    while (i < validos && arreglo[i].idMateria != idMateria)
    {
        i++;
    }
    return i;
}

void insertarAlFinalLista(nodo** lista, notaAlumno dato)
{
    nodo* nuevo = crearNodo(dato);
    nodo* act;
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        act = *lista;
        while (act->sig != NULL)
        {
            act = act->sig;
        }
        act->sig = nuevo;
    }
}


notaAlumno crearNotaAlumno(int nota, int legajo, char* nomyApe)
{
    notaAlumno n;
    n.nota=nota;
    n.legajo=legajo;
    strcpy(n.nombreApe,nomyApe);

    return n;

}


void cargarArreglo(Materia* arreglo, int* validos)
{
    FILE* fp = fopen("notas.bin","rb");
    RegistroArchivo r;
    Materia m;
    notaAlumno n;
    int i;
    if (fp)
    {
        while (fread(&r,sizeof(RegistroArchivo),1,fp) >0 )
        {
            i = busquedaMateria(arreglo,r.idMateria,*validos);
            n = crearNotaAlumno(r.nota,r.legajo,r.nombreApe);
            if (i == *validos) // (arreglo[i].idMateria != r.idMateria)
            {
                m = crearMateria(r.idMateria,r.nom_Materia);
                insertarAlFinal(arreglo,m,validos);
                insertarAlFinalLista(&(arreglo[i].listaDeNotas),n);
            }
            else
            {
                insertarAlFinalLista(&(arreglo[i].listaDeNotas),n);
            }
        }
        fclose(fp);
    }
}


int cantDatos()
{
    FILE* fp = fopen("notas.bin","rb");
    int cant;
    if (fp)
    {
        fseek(fp,0,SEEK_END);
        cant= ftell(fp)/sizeof(Materia);

    }
    fclose(fp);
    return cant;
}

void sumaNotasAlumno(nodo* lista, int legajo, int* cont, int* sum)
{
    int suma=0;
    while (lista!= NULL)
    {
        if (legajo = lista->dato.legajo)
        {
            *sum+= lista->dato.nota;
            (*cont)++;
        }
        lista=lista->sig;
    }
}


float promedioNotasAlumno(Materia* arreglo,int idMateria, int legajo, int validos)
{
    int i = 0;
    int suma=0;
    int cont=0;
    float prom;
    while (i < validos && idMateria != arreglo[i].idMateria)
    {
        i++;
    }
    if (i != validos)
    {
        sumaNotasAlumno(arreglo[i].listaDeNotas,legajo,&suma,&cont);
        prom = (float)sum/cont;
    }
    else
        prom =0;

    return prom;
}




int main()
{
    Materia *arreglo;
    int validos=0;
    arreglo = (Materia*)malloc(sizeof(Materia)*cantDatos());
    cargarArreglo(arreglo,&validos);
    return 0;
}
