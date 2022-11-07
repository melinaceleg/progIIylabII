#include <stdio.h>
#include <stdlib.h>
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
    nodoNota* listaDeNotas;
}Materia;

/**

Para la inserción se debe tener en cuenta:
->La lista de notas debe estar ordenada por legajo ascendente.
->El arreglo de materias debe estar ordenado por idMateria ascendente.

**/

///proto
void pasarDeArchivoToADL(Materia materias[TAM_MAX],int* validos); ///primera funcion
void insertarEnArregloDeListas(Materia[],int*,registroArchivo);
int existeMateria(Materia[],int,int);
nodoNota* crearNodoNota(notaAlumno);
void insercionOrdenadaLista(nodoNota**,notaAlumno);
void insercionOrdenadaArreglo(Materia[],int*,Materia);

///implementacion

nodoNota* crearNodoNota(notaAlumno nuevaNota)
{
    nodoNota* nuevo = (nodoNota*)malloc(sizeof(nodoNota));
    nuevo->dato = nuevaNota;
    nuevo->sig = NULL;
    return nuevo;
}

///insercion ordenada por legajo
void insercionOrdenadaLista(nodoNota** lista,notaAlumno notaNueva)
{
  if (*lista == NULL || (*lista)->dato.legajo > notaNueva.legajo)
  {
      nodoNota* nuevo = crearNodoNota(notaNueva);
      nuevo->sig = *lista;
      *lista = nuevo;
  }
  else
  {
      insercionOrdenadaLista(&((*lista)->sig),notaNueva);
  }

}



///retorno indice si existe, de lo contrario -1
///busqueda ordenada por idMateria
int existeMateria(Materia materias[],int validos, int idMateria)
{
    int i=0;
    int indiceEncontrado;
    while (i < validos && materias[i].idMateria < idMateria)
    {
       i++;
    }
    if (i<validos && materias[i].idMateria == idMateria)
    {
        indiceEncontrado = i;
    }
    else
    {
        indiceEncontrado = -1;
    }

    return indiceEncontrado;

}



///genero un nuevo tipo de dato notaAlumno (estructura)
notaAlumno crearNotaAlumno(char* nom,int legajo, int nota)
{
    notaAlumno nuevo;
    nuevo.legajo = legajo;
    strcpy(nuevo.nombreApe,nom);
    nuevo.nota=nota;

    return nuevo;
}

Materia crearMateria(char* nom, int idMateria,notaAlumno notaNueva)
{
    Materia nuevaMateria;
    nuevaMateria.idMateria = idMateria;
    strcpy(nuevaMateria.nomMateria,nom);
    nuevaMateria.listaDeNotas = NULL;
    ///le agrego la nota de alumno a la lista
    insercionOrdenadaLista(&(nuevaMateria.listaDeNotas),notaNueva);

    return nuevaMateria;

}

void insercionOrdenadaArreglo(Materia materias[],int* validos,Materia nueva)
{
   int i = *validos - 1;
   while (i >= 0 && materias[i].idMateria > nueva.idMateria)
   {
       materias[i+1] = materias[i];
       i--;
   }

   materias[i+1] = nueva;
    (*validos)++; ///no olvidar

}

/**
Verifico que ese idMateria exista
    si existe -> inserto la notaAlumno en esa Materia
    si no -> debo crear una nueva Materia, insertarla en arreglo y luego cargar
             el alumno en dicho indice del arreglo (insertarlo en la lista)

**/
void insertarEnArregloDeListas(Materia materias[],int* validos,registroArchivo reg)
{
   int indiceEncontrado = existeMateria(materias,*validos,reg.idMateria);
   notaAlumno notaNueva = crearNotaAlumno(reg.nombreApe,reg.legajo,reg.nota);
   if (indiceEncontrado != -1) ///si la Materia ya existe
   {
       insercionOrdenadaLista(&(materias[indiceEncontrado].listaDeNotas),notaNueva);
   }
   else
   {
       Materia nuevaMateria = crearMateria(reg.nomMateria,reg.idMateria,notaNueva);
       insercionOrdenadaArreglo(materias,validos,nuevaMateria);
   }

}


///lee el archivo e invoca a la funcion de insercion en el arreglo de listas
void pasarDeArchivoToADL(Materia materias[TAM_MAX],int* validos)
{
 registroArchivo reg;
 FILE* fp = fopen("notas.dat", "rb");
 if (fp)
 {
     while (fread(&reg,sizeof(registroArchivo),1,fp) > 0)
     {
         insertarEnArregloDeListas(materias,validos,reg);
     }

     fclose(fp);

 }
}

/**
Informar la cantidad de alumnos que obtuvieron más de 6 por cada Materia.

**/

int contarAlumnos(nodoNota* lista, int notaCota)
{
    int cantidad=0;
    while( lista != NULL)
    {
        if (lista->dato.nota > 6)
        {
            cantidad++;
        }
        lista = lista->sig;
    }

    return cantidad;
}

void informarCantidadAlumnosMayorACota(Materia materias[],int validos, int notaCota)
{
    int cantidad;
    for (int i = 0 ; i<validos; i++)
    {
        cantidad = contarAlumnos(materias[i].listaDeNotas,notaCota);
        printf("La cantidad de alumnos de la materia %s que obtuvieron mayor a %i es: %i\n", materias[i].nomMateria, notaCota, cantidad);
    }

}







int main()
{
  Materia arregloMaterias[TAM_MAX];
  int validos=0;
  pasarDeArchivoToADL(arregloMaterias,&validos);
  informarCantidadAlumnosMayorACota(materias,validos,6);

 return 0;
}
