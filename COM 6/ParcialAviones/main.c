#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char dni[9];
    char nombre[30];
    float pesoEquipaje;
    int edad;
    int idAvion;
    int idPasaje;
}registroPasajero;


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




/**

Cargar los datos desde el archivo
Hacer una función o funciones que inserten en la lista de aviones el
 avión correspondiente, así como en la lista de pasajeros,
 cada pasajero que coincida con su avión correspondiente.
La inserción de un avión en la lista de aviones se da al final.
La inserción en la lista de pasajeros se da en orden por “DNI” creciente.
**/

nodoAvion* crearNodoAvion(int idAvion)
{
    nodoAvion* nuevo = (nodoAvion*)malloc(sizeof(nodoAvion));
    nuevo->idAvion = idAvion;
    nuevo->pasajeros = NULL;
    nuevo->sig = NULL;

    return nuevo;
}

void cargarPersona(Persona* p, char* nombre, char* dni, int edad)
{
    strcpy((*p).dni, dni);
    strcpy((*p).nombre,nombre);
    (*p).edad = edad;
}

nodoPasajero* crearNodoPasajero(registroPasajero pasajero)
{
    Persona p;
    nodoPasajero* nuevo = (nodoPasajero*)malloc(sizeof(nodoPasajero));
    nuevo->idPasaje = pasajero.idPasaje;
    nuevo->pesoEquipaje = pasajero.pesoEquipaje;
    cargarPersona(&p); ///cargarPersona(&(nuevo->p));
    nuevo->p = p;
    nuevo->sig = NULL;

    return nuevo;
}


void cargarLista(nodoAvion** aviones)
{
    FILE* fp = fopen("pasajerosAviones.bin","rb");
    registroPasajero registro;
    if (fp)
    {
        while (fread(&registro,sizeof(registroPasajero),1,fp) > 0)
        {
            insertarDatos(aviones,registro);
        }
        fclose(fp);
    }
}

nodoAvion* existeAvion(nodoAvion* aviones, int idAvion)
{
    nodoAvion* encontrado = NULL;
    while (aviones != NULL && aviones->idAvion > idAvion)
    {
        aviones = aviones->sig;
    }
    if (aviones != NULL && aviones->idAvion == idAvion)
    {
        encontrado = aviones; ///le guardo el nodo donde estoy parada
    }

    return encontrado;
}
///insertar en una lista ordenado por DNI
void insertarPasajero(nodoPasajero** pasajeros, registroPasajero pasajero)
{
    if (*pasajeros == NULL || strcmp((*pasajeros)->p.DNI, pasajero.dni) >0)
    {
        nodoPasajero* nuevo = crearNodoPasajero(pasajero);
        nuevo->sig = *pasajeros;
        *pasajeros = nuevo;
    }
    else
    {
        insertarPasajero(&((*pasajeros)->sig),pasajero);
    }




}

///la insercion en la lista de aviones es al final
void insertarAvionYPasajero(nodoAvion** aviones, registroPasajero pasajero)
{
    nodoAvion* seg;
    nodoAvion* nuevo = crearNodoAvion(pasajero.idAvion);
    insertarPasajero(&(nuevo->pasajeros),pasajero);

    if (*aviones == NULL)
    {
        *aviones = nuevo;
    }
    else
    {
        seg = *aviones;
        while (seg->sig != NULL)
        {
            seg = seg->sig;
        }
        seg->sig = nuevo;
    }

}

void insertarDatos(nodoAvion** aviones, registroPasajero pasajero)
{

    nodoAvion* encontrado = existeAvion(*aviones,pasajero.idAvion);
    if (encontrado != NULL)
    {
        insertarPasajero(&(encontrado->pasajeros),pasajero);
    }
    else
    {
        insertarAvionYPasajero(aviones,pasajero);
    }

}

/**
Realizar una función que retorne el idAvion
 con la  máxima cantidad de pasajeros.
 **/

 int contarPasajeros(nodoPasajero* pasajeros)
 {
     int cantidad = 0;
     while (pasajeros != NULL)
     {
         cantidad++;
         pasajeros = pasajeros->sig;
     }

     return cantidad;
 }

 int maximaCantidadIdAvion(nodoAvion* aviones)
 {
     int maxCantidad =-1;
     int cantidad;
     int idAvionMax=-1;
     while (aviones != NULL)
     {
         cantidad = contarPasajeros(aviones->pasajeros);
         if (cantidad > maxCantidad)
         {
             maxCantidad = cantidad;
             idAvionMax = aviones->idAvion;
         }

         aviones=aviones->sig;
     }

    return idAvionMax;
 }

 /**
 Realizar una función que informe el Peso total en Equipaje
 en un idAvion X recibido por parámetro.
**/
float sumaPesos(nodoPasajero* pasajeros)
{
    float suma=0;
    while (pasajeros != NULL)
    {
        suma = suma + pasajeros->pesoEquipaje;
        pasajeros = pasajeros->sig;
    }
    return suma;
}

void informarPesoTotalAvionX(nodoAvion* aviones, int idAvion)
{
    float sumaTotal;
    while (aviones != NULL && aviones->idAvion > idAvion)
    {
        aviones=aviones->sig;
    }
    if (aviones != NULL  && aviones->idAvion == idAvion)
    {
        sumaTotal = sumaPesos(aviones->pasajeros);
        printf("La suma total de equipaje del avion %i es %.2f\n", idAvion,sumaTotal);
    }
    else
    {
        printf("No existe un avion con el id %i\n",idAvion);
    }

}

/**
Realizar una función que, recibiendo por parámetro un idAvion X,
elimine aquellos pasajeros que su edad sea mayor a 50.
Si el avión se queda sin pasajeros (lista de pasajeros nula),
elimine también ese nodo de avión.

**/

///Eliminar de una lista de pasajeros todos los que son mayores a 50 anios
void eliminarMayoresACota(nodoPasajero** pasajeros, int cotaEdad)
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
                aux = seg;
                ante->sig = seg->sig;
                seg = seg->sig; ///debo seguir recorriendo la lista
                free(aux);
            }
            else
            {
                ante = seg;
                seg = seg->sig;
            }
        }

    }

}

void eliminarPersonasMayoresAvionX(nodoAvion** aviones, int idAvion, int cotaEdad)
{
    nodoAvion* aux;
    nodoAvion* ante;
    nodoAvion* seg;
    if (*aviones != NULL && (*aviones)->idAvion == idAvion)
    {
        eliminarMayoresACota(&(*aviones)->pasajeros,cotaEdad);
        if ((*aviones)->pasajeros == NULL)
        {
            aux = *aviones;
            *aviones = *aviones->sig;
            free(aux);
        }
    }
    else
    {
        seg = (*aviones)->sig;
        ante = *aviones;
        while (seg != NULL && seg->idAvion > idAvion)
        {
            ante = seg;
            seg = seg->sig;
        }
        if (seg != NULL && seg->idAvion == idAvion)
        {
            eliminarMayoresACota(&(seg->pasajeros),cotaEdad);
            if (seg->pasajeros == NULL)
            {
                aux = seg;
                ante->sig = seg->sig;
                free(aux);
            }
        }
    }
}




int main()
{
    nodoAvion* aviones = NULL;
    cargaLista(&aviones);
    return 0;
}
