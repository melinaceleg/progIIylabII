#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 100


typedef struct {
   int nota;
   int legajo;
   char nombreApe[40];
   char nomMateria[40];
   int idMateria;
} registroArchivo;

typedef struct {
   int nota;
   int legajo;
   char nombreApe[40];
} notaAlumno;

typedef struct nodoNota {
   notaAlumno dato;
   struct nodoNota *sig;
} nodoNota;

typedef struct {
    int idMateria;
    char nomMateria[40];
    nodoNota * listaDeNotas;
}Materia;



/**
Para la inserción se debe tener en cuenta:
La lista de notas debe estar ordenada por legajo ascendente.
El arreglo de materias debe estar ordenado por idMateria ascendente.

**/

nodoNota* crearNodoNota(notaAlumno nota)
{
    nodoNota* nuevo = (nodoNota*)malloc(sizeof(nodoNota));
    nuevo->dato = nota;
    nuevo->sig=NULL;
    return nuevo;
}

notaAlumno crearNotaAlumno(int nota, int legajo, char* nom)
{
    notaAlumno n;
    n.nota = nota;
    n.legajo = legajo;
    strcpy(n.nombreApe,nom);
    return n;
}


///busqueda en el arreglo ORDENADO por idMATERIA
int existeMateria(Materia* materias, int validos, int idMateria)
{
    int i =0;
    while (i<validos && materias[i].idMateria < idMateria)
    {
      i++;
    }
    if(i < validos && materias[i].idMateria == idMateria)
    {
        return i;
    }
    else
    {
        return -1;
    }


}
///ordenado por legajo
void insertarNotaOrdenada(nodoNota** notas, notaAlumno notaNueva)
{
    if (*notas == NULL)
    {
        *notas = crearNodoNota(notaNueva);
    }
    else
    {
        if (notaNueva.legajo < (*notas)->dato.legajo)
        {
            nodoNota* nuevo = crearNodoNota(notaNueva);
            nuevo->sig = *notas;
            *notas = nuevo;
        }
        else
        {
            insertarNotaOrdenada(&((*notas)->sig),notaNueva);
        }
    }

}

void cargarNuevaMateria(Materia* m, int idMateria, char* nom)
{
    (*m).idMateria = idMateria;
     strcpy((*m).nomMateria,nom);
     (*m).listaDeNotas = NULL;
}

///insertar ordenado por idMateria
void insertarNuevaMateriaYNota(Materia* materias,int* validos,registroArchivo reg)
{
    int i = *validos - 1;
    while (i>=0 && materias[i].idMateria > reg.idMateria)
    {
        materias[i+1] = materias[i];
        i--;
    }
    Materia materiaNueva;
    cargarNuevaMateria(&materiaNueva,reg.idMateria,reg.nomMateria);
    materias[i+1] = materiaNueva; ///inserto la materia nueva en el hueco
    //cargarNuevaMateria(&materias[i+1]);
    ///insertar en la lista de materias de esa nueva materia, la nota.
    insertarNotaOrdenada(&(materias[i+1].listaDeNotas),crearNotaAlumno(reg.nota,reg.legajo,reg.nombreApe));
    (*validos)++;

}

void insercionRegistro(Materia* materias, int* validos, registroArchivo reg)
{
    int indiceEncontrado = existeMateria(materias,*validos,reg.idMateria);
    if (indiceEncontrado != -1) ////encontre la celda donde esta la materia
    {
        insertarNotaOrdenada(&(materias[indiceEncontrado].listaDeNotas),crearNotaAlumno(reg.nota,reg.legajo,reg.nombreApe));

    }
    else /// No existe la materia
    {
        insertarNuevaMateriaYNota(materias,validos,reg);
    }


}

void pasarDeArchivoToADL(Materia* materias, int* validos)
{
    FILE* fp = fopen("notas.dat", "rb");
    registroArchivo reg;
    if (fp)
    {
        while (fread(&reg,sizeof(registroArchivo),1,fp) >0 && *validos < TAM_MAX)
        {
            insercionRegistro(materias,validos,reg);
        }

        fclose(fp);
    }
}

/**
Informar la cantidad de alumnos que obtuvieron más de 6 por cada Materia
**/

int contarNotasMayoresACota(nodoNota* notas, int notaCota)
{
    int cantidad=0;
    if (notas != NULL)
    {
        if (notas->dato.nota > notaCota)
        {
            cantidad = 1 + contarNotasMayoresACota(notas->sig,notaCota);
        }
        else
        {
            cantidad = contarNotasMayoresACota(notas->sig,notaCota);
        }
    }

    return cantidad;

}

void informarCantidadNotasMayoresXMateria(Materia* materias, int validos, int notaCota)
{
    int cantidad;
    for (int i = 0 ; i < validos ; i++)
    {
        cantidad = contarNotasMayoresACota(materias[i].listaDeNotas,notaCota);
        printf("La cantidad de alumnos de la materia %s que obtuvieron mas de %i es %i\n",materias[i].nomMateria,notaCota,cantidad);
    }
}


int main()
{
    Materia materias[TAM_MAX]; ///es un puntero por definicion!
    int validos=0;
    pasarDeArchivoToADL(materias, &validos);
    informarCantidadNotasMayoresXMateria(materias,validos,6);

    return 0;
}
