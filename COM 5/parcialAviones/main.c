#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct nodoAvion
{
    int idAvion;
    nodoPasajero* pasajeros;
    struct nodoAvion* sig;
}nodoAvion;

typedef struct nodoPasajero
{
   Persona p;
   int idPasaje;
   float pesoEquipaje;
   struct nodoPasajero* sig;
}nodoPasajero;

typedef struct
{
   char nombre[30];
   char dni[9];
   int edad;
}Persona;

typedef struct
{
    char dni[9];
    char nombre[30];
    float pesoEquipaje;
    int edad;
    int idAvion;
    int idPasaje;
}registroPasajero;

/**

Hacer una función o funciones que inserten en la lista de
aviones el avión  correspondiente, así como en la lista
de pasajeros, cada pasajero que coincida con su avión
correspondiente.
La inserción de un avión en la lista de aviones se da al
final.
La inserción en la lista de pasajeros se da en orden
por “DNI” creciente

**/


void cargarLista(nodoAvion** aviones)
{
    FILE* fp = fopen("pasajerosAviones.bin", "rb");
    registroPasajero registro;
    if (fp)
    {
        while (fread(&registro,sizeof(registroPasajero),1,fp) > 0 )
        {
          insertarNuevoPasajero(aviones,registro);

        }
        fclose(fp);
    }

}

nodoAvion* existeAvion(nodoAvion* aviones, int idAvion)
{
    while (aviones != NULL && idAvion < aviones->idAvion)
    {
        aviones = aviones->sig;
    }
    if (aviones != NULL && idAvion == aviones->idAvion)
    {
        return aviones; ///retorno ese nodo
    }
    else
    {
        return NULL; ///no esta!
    }


}

nodoAvion* crearNodoAvion(int idAvion)
{
  nodoAvion* avion = (nodoAvion*)malloc(sizeof(nodoAvion));
  avion->idAvion = idAvion;
  avion->pasajeros = NULL;
  avion->sig = NULL;
  return avion;
}

void cargarPersona(Persona* p, char* dni, int edad, char* nombre)
{
    strcpy((*p).dni,dni);
    strcpy((*p).nombre,nombre);
    (*p).edad = edad;
}

nodoPasajero* crearNodoPasajero(registroPasajero p)
{
    Persona persona;
    cargarPersona(&persona,p.dni,p.edad,p.nombre);
    nodoPasajero* nuevo = (nodoPasajero*)malloc(sizeof(nodoPasajero));
    nuevo->idPasaje = p.idPasaje;
    nuevo->pesoEquipaje = p.pesoEquipaje;
    nuevo->p=persona;
    nuevo->sig=NULL;
    return nuevo;
}

void insertarPasajero(nodoPasajero** pasajeros, registroPasajero pasajero)
{
    if (*pasajeros == NULL || strcmp(*pasajeros->p.dni, pasajero.dni) >0)
    {
        nodoPasajero* nuevoPasajero = crearNodoPasajero(pasajero);
        nuevoPasajero->sig = *pasajeros;
        *pasajeros = nuevoPasajero;
    }
    else
    {
        insertarPasajero(&(*pasajeros)->sig,pasajero);
    }
}


void  insertarNuevoAvionYPasajero(nodoAvion** aviones,registroPasajero pasajero)
{
  nodoAvion* nuevoAvion = crearNodoAvion(pasajero.idAvion);
  insertarPasajero(&(nuevoAvion->pasajeros),pasajero);
  nodoAvion* seg;
  ///inserto al final de la lista el nuevo nodo avion
  if (*aviones == NULL)
  {
      *aviones = nuevoAvion;
  }
  else
  {
      seg = *aviones;
      while (seg->sig != NULL)
      {
          seg = seg->sig;
      }
      seg->sig = nuevoAvion;
  }
}

void insertarDatos(nodoAvion** aviones,registroPasajero pasajero)
{
   nodoAvion* encontrado = existeAvion(*aviones,pasajero.idAvion);
   if (encontrado == NULL) /// si no existe el avion
   {
       ///creo un avion, lo agrego a la lista y le cargo el pasajero
       insertarNuevoAvionYPasajero(aviones,pasajero);
   }
   else
   {
       ///cargo en ese avion ese pasajero
      insertarPasajero(&(encontrado->pasajeros),pasajero);
   }

}

/**
Realizar una función que retorne el
 idAvion con la  máxima cantidad de pasajero
**/

int contarPasajeros(nodoPasajero* pasajeros)
{
    int cantidad=0;
    while (pasajeros != NULL)
    {
        cantidad++;
        pasajeros = pasajeros->sig;
    }

    return cantidad;
}

int buscarIdAvionMaxCantidad(nodoAvion* aviones)
{
    int maxCant =-1;
    int cantidad;
    int idAvion= -1;
    while (aviones != NULL)
    {
        cantidad =contarPasajeros(aviones->pasajeros);
        if (cantidad > maxCant)
        {
            maxCant = cantidad;
            idAvion = aviones->idAvion;
        }

        aviones = aviones->sig;
    }

   return idAvion;
}

/**
Realizar una función que informe el Peso total en Equipaje en
un idAvion X recibido por parámetro. **/

float sumarPesos(nodoPasajero* pasajeros)
{
    float suma=0;
    while (pasajeros != NULL)
    {
        suma = suma + pasajeros->pesoEquipaje;
        pasajeros = pasajeros->sig;
    }
    return suma;
}

void informePesoTotal(nodoAvion* aviones, int idAvion)
{
    float sumaTotal;
    while (aviones != NULL && idAvion < aviones->idAvion)
    {
        aviones= aviones->sig;
    }
    if (aviones != NULL && aviones->idAvion == idAvion)
    {
        sumaTotal = sumarPesos(aviones->pasajeros);
        printf("La suma Total del avion %i es %.2f\n", idAvion,sumaTotal);
    }
    else
    {
        printf("El idAvion %i no existe\n", idAvion);
    }

}

/**
Realizar una función que, recibiendo por parámetro un idAvion X,
elimine aquellos pasajeros que su edad sea mayor a 50.
Si el avión se queda sin pasajeros (lista de pasajeros nula),
 elimine también ese nodo de avión.
**/

void borrarPersonasGrandes(nodoPasajero** pasajeros, int cotaEdad)
{
 nodoPasajero* aux;
 nodoPasajero* seg;
 nodoPasajero* ante;

 if (*pasajeros != NULL)
 {
     while (*pasajeros != NULL && (*pasajeros)->p.edad > cotaEdad)
     {
         aux = *pasajeros;
         *pasajeros = (*pasajeros)->sig;
         free(aux);
     }

     seg = (*pasajeros)->sig;
     ante = *pasajeros;
     while (seg != NULL)
     {
         if (seg->p.edad > cotaEdad)
         {
             aux= seg;
             ante->sig = seg->sig;
             seg = seg->sig; ///debo avanzar con seg antes de borrar
             free(aux);
         }
         else ///avanzo como siempre si no lo encontre
         {
            ante=seg;
            seg = seg->sig;
         }
     }
 }

}

void borrarPersonasGrandesAvionX(nodoAvion** aviones, int idAvion, int cotaEdad)
{
    nodoAvion* aux;
    nodoAvion* seg, *ante;
    if (*aviones !- NULL && (*aviones)->idAvion >= idAvion)
    {
        if((*aviones)->idAvion == idAvion)
        {
            borrarPersonasGrandes(&((*aviones)->pasajeros),cotaEdad);
            if ((*aviones)->pasajeros == NULL)
            {
              aux = *aviones;
              *aviones = (*aviones)->sig;
              free(aux);
            }
        }
        else
        {
            ante= *aviones;
            seg = (*aviones)->sig;
            while (seg != NULL && seg->idAvion > idAvion)
            {
                ante = seg;
                seg = seg->sig;
            }
            if (seg != NULL && seg->idAvion == idAvion)
            {
                borrarPersonasGrandes(&seg->pasajeros,cotaEdad);
                if (seg->pasajeros == NULL)
                {
                    aux = seg;
                    ante->sig = seg->sig;
                    free(aux);
                }
            }
        }
    }

}

/**
Realizar una función que pase a archivos los pasajeros de cada
uno de los aviones. Ej:
idAvion1.bin ->  todos los pasajeros del idAvion =1
idAvion2.bin -> todos los pasajeros del idAvion = 2
**/

void pasarPasajerosAviones(nodoAvion* aviones)
{
    while (aviones != NULL)
    {
        generarArchivo(aviones->idAvion,aviones->pasajeros);
        aviones=aviones->sig;
    }
}

void generarArchivo(int idAvion, nodoPasajero* pasajeros)
{
    char nom[20] = "avion";
    //strcat(nom,(char*)idAvion);
    sprintf(nom,"%i",idAvion);
    FILE* fp = fopen(nom,"wb");
    if (fp)
    {
        while(pasajeros != NULL)
        {
            fwrite(&(pasajeros->p),sizeof(Persona),1,fp);
            pasajeros=pasajeros->sig;
        }
        fclose(fp);
    }
}


int main()
{
    nodoAvion* aviones = NULL;
    cargarLista(&aviones);
    return 0;
}
