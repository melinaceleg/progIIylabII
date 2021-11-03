#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[30];
    char nom_materia[30];
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
    struct _nodo *siguiente;
} nodo;

typedef struct
{
    int idMateria;
    char nom_materia[30];
    nodo * listaDeNotas;
} Materia; ///celda de mi arreglo

///estructura de datos compuesta : arreglo de listas


nodo* crearNodo(notaAlumno dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;

    return nuevo;
}
///creo la celda
Materia crearMateria(int idMateria, char* nom_materia)
{
    Materia m;
    m.idMateria=idMateria;
    strcpy(m.nom_materia,nom_materia);
    m.listaDeNotas = NULL;

    return m;
}


///retorna indice
int busquedaMateria(Materia* materias,int idMateria, int validos)
{
    int i=0;
    while (i < validos && materias[i].idMateria < idMateria)
    {
        i++;
    }
    return i;
}

void insertarAlFinal(nodo** lista, notaAlumno n)
{
    nodo* nuevo = crearNodo(n);
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
            act=act->sig;
        }
        act->sig = nuevo;
    }

}


notaAlumno crearNota(int legajo, char* nomyApe, int nota)
{
    notaAlumno n;
    n.legajo=legajo;
    strcpy(n.nombreApe,nomyApe);
    n.nota=nota;
    return n;
}

////insercion al final del arreglo y de la lista
void cargarArreglo(Materia* materias, int* validos)
{
    RegistroArchivo r;
    int i;
    notaAlumno n;
    FILE* fp = fopen("notas.bin","rb");
    if (fp)
    {
        while (fread(&r,sizeof(RegistroArchivo),1,fp) > 0)
        {
            i=busquedaMateria(materias,r.idMateria,*validos);
            if (i == validos) ///la materia no existe ordenado-> (i == validos || materias[i].idMateria != r.idMateria)
            {
                materias[i] = crearMateria(r.idMateria,r.nom_materia);
                (*validos)++;
                n = crearNota(r.legajo,r.nombreApe,r.nota);
                insertarAlFinal(&(materias[i].listaDeNotas),n);
            }
            else ///la materia existe
            {
                n = crearNota(r.legajo,r.nombreApe,r.nota);
                insertarAlFinal(&(materias[i].listaDeNotas),n);
            }

        }
        fclose(fp);
    }
}
///eliminar todas las notas correspondientes a un legajo
void eliminarNotasAlumnoLista(nodo** lista, int legajo)
{
    nodo* aux;
    nodo* act, *ant;

    while (*lista && (*lista)->dato.legajo == legajo) ///elimino todo lo que coincida en el primer tramo
    {
        aux = *lista;
        *lista = (*lista)->sig;
        free(aux);
    }
    if (*lista != NULL)
    {
        ant = *lista;
        act = (*lista)->sig;
        while (act != NULL) ///de esta manera recorro hasta el final
        {
            while (act != NULL && act->dato.legajo != legajo)
            {
                ant = act;
                act= act->sig;
            }
            if (act!= NULL)
            {
                aux = act;
                ant->sig = act->sig;
                act=act->sig; //esto ocurre aca por que tengo que seguir buscando
                free(aux);
            }
        }
    }
}

/// la lista de notas puede tener varios legajos iguales

void eliminarNotasAlumno(Materia* materias, int idMateria, int legajo,int validos)
{
    int i=0;
    while (i< validos && materias[i].idMateria != idMateria)
    {
        i++;
    }
    if (i<validos)
    {
        eliminarNotasAlumnoLista(&(materias[i].listaDeNotas),legajo);
    }

}

void obtenerNotas(nodo* lista, int legajo, int* suma, int* cant)
{
    while (lista != NULL)
    {
        if (lista->legajo == legajo)
        {
            *suma = *suma + lista->nota;
            *(cant)++;
        }
        lista=lista->sig;
    }

}


void mostrarPromedioNotasAlumnoMateria(Materia* materias, int idMateria, int legajo, int validos)
{
    int i = 0;
    int suma=0;
    int cant=0;
    while (i<validos && materias[i].idMateria != idMateria)
    {
        i++;
    }
    if (i<validos)
    {
        obtenerNotas(materias[i].listaDeNotas,legajo,&suma,&cant);
        printf("promedio de notas de %i: %.2f,", legajo, (float)suma/cant);
    }
}



///la dimension del arreglo es la cantidad de registros del archivo
int cantDatos()
{
    int cant=0;
    FILE* fp = fopen("notas.bin","rb");
    if (fp)
    {
        fseek(fp,0,SEEK_END);
        cant = ftell(fp)/sizeof(RegistroArchivo);
        fclose(fp);
    }
    return cant;
}




int main()
{
    Materia* materias;
    materias = (Materia*)malloc(sizeof(Materia)*cantDatos());
    int validos=0;
    cargarArreglo(materias,&validos);
    return 0;
}
