#include <stdio.h>
#include <stdlib.h>
#define CANTMAX 100



typedef struct {
   int nota;
   int legajo;
   char nombreApe[40];
   char nomMateria[40];
   int idMateria;
}registroArchivo;


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

///El arreglo de materias debe estar ordenado por idMateria ascendente.
int existeMateria(Materia* materias, int validos, int idMateria)
{
    int i= 0;
    while (i < validos && materias[i].idMateria < idMateria)
    {
        i++;
    }
    if (i < validos && materias[i].idMateria == idMateria)
    {
        return i;
    }
    else
    {
        return -1;
    }

}

void cargarNotaAlumno(notaAlumno* n,int legajo, char*nom, int nota)
{
  (*n).legajo = legajo;
  strcpy((*n).nombreApe,nom);
  (*n).nota = nota;
}

nodoNota* crearNodoNota(int legajo, char* nom, int nota)
{
    nodoNota* nuevo = (nodoNota*)malloc(sizeof(nodoNota));
    cargarNotaAlumno(&(nuevo->dato),legajo,nom,nota);
    nuevo->sig=NULL;

    return nuevo;
}


///ordenado por legajo ascendente
void insertarNotaOrdenada(nodoNota** notas, int legajo, char* nom, int valor)
{
    if (*notas == NULL || (*notas)->dato.legajo > legajo)
    {
        nodoNota* nuevo = crearNodoNota(legajo,nom,valor);
        nuevo->sig = *notas;
        *notas = nuevo;
    }
    else
    {
        insertarNotaOrdenada(&((*notas)->sig),legajo,nom,valor);
    }
}

void crearMateria(Materia* m,int idMateria, char* nom)
{
    (*m).idMateria = idMateria;
    strcpy((*m).nomMateria,nom);
    (*m).listaDeNotas = NULL; /// INICIALIZO LA LISTA DE NOTAS!
}

///insertar una nueva materia por orden idMateria ascendente
void insertarNuevaMateriaYNota(Materia* materias, int* validos, registroArchivo reg)
{
  int i = *validos -1;
  while (i >= 0 && materias[i].idMateria > reg.idMateria)
  {
      materias[i+1] = materias[i];
      i--;
  }
  crearMateria(&materias[i+1],reg.idMateria,reg.nomMateria);
  insertarNotaOrdenada(&(materias[i+1].listaDeNotas),reg.legajo,reg.nombreApe,reg.nota);
  (*validos)++;
}

void insertarNuevaNota(Materia* materias, int* validos, registroArchivo nota)
{
  int indiceEncontrado = existeMateria(materias,*validos,nota.idMateria);
  if ( indiceEncontrado != -1)
  {
      insertarNotaOrdenada(&(materias[indiceEncontrado].listaDeNotas),nota.legajo,nota.nombreApe,nota.nota);
  }
  else
  {
      insertarNuevaMateriaYNota(materias,validos,nota);
  }


}


void cargarNotasDeFile(Materia* materias, int* validos)
{
    registroArchivo reg;
    FILE* fp = fopen("Notas.dat", "rb");
    if (fp)
    {
        while (fread(&reg,sizeof(registroArchivo),1,fp) >0 )
        {
            insertarNuevaNota(materias,validos,reg);
        }

        fclose(fp);
    }
}

/**
Informar la cantidad de alumnos que obtuvieron más de 6
 por cada Materia
**/

int contarNotasMayoresACota(nodoNota* notas, int notaCota)
{
    int cantidad = 0;
    while (notas != NULL)
    {
        if (notas->dato.nota > notaCota)
        {
            cantidad++;
        }
        notas = notas->sig;
    }

    return cantidad;
}

void informarCantNotasPorMateria(Materia* materias, int validos, int notaCota)
{
    int cantidad;
    for (int i = 0 ; i < validos; i++)
    {
        cantidad = contarNotasMayoresACota(materias[i].listaDeNotas,notaCota);
        printf("La materia %s posee %i notas mayores a %i\n", materias[i].nomMateria, cantidad, notaCota);
    }
}


int main()
{
   Materia materias[100];
   int validos=0;
   cargarNotasDeFile(materias, &validos);
   informarCantNotasPorMateria(materias,validos,6);

    return 0;
}
