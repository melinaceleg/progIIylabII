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
} registroPasajero;

typedef struct
{
    char nombre[30];
    char dni[9];
    int edad;
} Persona;

typedef struct nodoPasajero
{
    Persona p;
    int idPasaje;
    float pesoEquipaje;
    struct nodoPasajero* sig;
} nodoPasajero;

typedef struct nodoAvion
{
    int idAvion;
    nodoPasajero* pasajeros;
    struct nodoAvion* sig;
} nodoAvion;






/**

Hacer una función o funciones que inserten en la lista de aviones el avión
correspondiente, así como en la lista de pasajeros, cada pasajero que coincida con su
avión correspondiente.
La inserción de un avión en la lista de aviones se da al final.
La inserción en la lista de pasajeros se da en orden por “DNI” creciente.

**/

void cargarPersona(Persona* p, char* nombre, char* dni, int edad)
{
    strcpy((*p).nombre,nombre);
    strcpy((*p).dni,dni);
    (*p).edad = edad;
}

nodoPasajero* crearNodoPasajero(registroPasajero pasajero)
{
    nodoPasajero* nuevo = (nodoPasajero*)malloc(sizeof(nodoPasajero));
    nuevo->idPasaje = pasajero.idPasaje;
    nuevo->pesoEquipaje = pasajero.pesoEquipaje;
    cargarPersona(&(nuevo->p),pasajero.nombre,pasajero.dni,pasajero.edad);
    nuevo->sig = NULL;

    return nuevo;

}

nodoAvion* crearNodoAvion(int idAvion)
{
    nodoAvion* nuevo  = (nodoAvion*)malloc(sizeof(nodoAvion));
    nuevo->idAvion = idAvion;
    nuevo->pasajeros = NULL;
    nuevo->sig = NULL;

    return nuevo;
}


nodoAvion* existeAvion(nodoAvion* aviones, int idAvion)
{
    while (aviones != NULL && aviones->idAvion < idAvion)
    {
        aviones = aviones->sig;
    }
    if (aviones != NULL && aviones->idAvion == idAvion)
    {
        return aviones;
    }
    else
    {
        return NULL;
    }
}



///inserto ordenado por DNI
void insertarPasajeroOrdenado(nodoPasajero** pasajeros, registroPasajero pasajero)
{
    if (*pasajeros == NULL || strcmp((*pasajeros)->p.dni,pasajero.dni) > 0)
    {
        nodoPasajero* nuevo = crearNodoPasajero(pasajero);
        nuevo->sig = *pasajeros;
        *pasajeros = nuevo;
    }
    else
    {
        insertarPasajeroOrdenado(&(*pasajeros)->sig,pasajero);
    }
}


void insertarAvionYPasajero(nodoAvion** aviones, registroPasajero pasajero)
{
    if (*aviones == NULL)
    {
        nodoAvion* nuevo;
        nuevo = crearNodoAvion(pasajero.idAvion);
//        nuevo->pasajeros = crearNodoPasajero(pasajero);
//        insertarPasajeroOrdenado(&(nuevo->pasajeros),pasajero);
        *aviones = nuevo;
    }
    else
    {
        insertarAvionYPasajero(&(*aviones)->sig,pasajero);
    }
}


void insertarPasajero(nodoAvion** aviones, registroPasajero pasajero)
{
    nodoAvion* encontrado = existeAvion(*aviones,pasajero.idAvion);
    if (encontrado != NULL) ///si existe el idAvion en la lista de aviones
    {
        insertarPasajeroOrdenado(&(encontrado->pasajeros),pasajero);
    }
    else
    {
        insertarAvionYPasajero(aviones,pasajero);
    }
}


void cargaLista(nodoAvion** aviones)
{
    FILE* fp = fopen("pasajerosAviones.bin","rb");
    registroPasajero pasajero;
    if (fp)
    {
        while (fread(&pasajero,sizeof(registroPasajero),1,fp) > 0)
        {
            insertarPasajero(aviones,pasajero);
        }

        fclose(fp);

    }
}

/**
Realizar una función que retorne el idAvion con la  máxima cantidad de pasajeros.
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

int avionMaximaCantPasajeros(nodoAvion* aviones)
{
    int maxCant=0;
    int maxId;
    int cant;
    if (aviones == NULL) ///no hay aviones si no hay pasajeros
    {
        maxId = -1;
    }
    else
    {
        while (aviones != NULL)
        {
            cant=contarPasajeros(aviones->pasajeros);
            if (cant > maxCant)
            {
                maxCant = cant;
                maxId = aviones->idAvion;
            }
            aviones=aviones->sig;
        }
    }

      return maxId;

}

/**
Realizar una función que informe el Peso total en Equipaje en un idAvion X recibido
por parámetro.

**/

float sumarEquipajes(nodoPasajero* pasajeros)
{
    float suma=0;
    while (pasajeros != NULL)
    {
        suma+= pasajeros->pesoEquipaje;
        pasajeros=pasajeros->sig;
    }
    return suma;
}

void informarPesoTotalAvionX(nodoAvion* aviones, int idAvion)
{
    float pesoTotal=0;
    while (aviones != NULL && aviones->idAvion > idAvion)
    {
        aviones=aviones->sig;
    }
    if(aviones != NULL && aviones->idAvion == idAvion)
    {
        pesoTotal= sumarEquipajes(aviones->pasajeros);
        printf("El peso total del avion %i es %.2f\n", idAvion,pesoTotal);
    }
    else
    {
        printf("No existe avion con el id %i\n",idAvion);
    }

}

/**
Realizar una función que, recibiendo por parámetro un idAvion X,
elimine aquellos pasajeros que su edad sea mayor a 50.
Si el avión se queda sin pasajeros (lista de pasajeros nula),
elimine también ese nodo de avión.

**/

void eliminarPasajerosMayores(nodoPasajero** pasajeros, int cotaEdad)
{
    nodoPasajero* seg, *ante;
    nodoPasajero* aux;

    if (*pasajeros != NULL)
    {
        while (*pasajeros != NULL && (*pasajeros)->p.edad > cotaEdad)
        {
            aux = *pasajeros;
            *pasajeros= (*pasajeros)->sig;
            free(aux);
        }
        if (*pasajeros != NULL)
        {
            seg = (*pasajeros)->sig;
            ante = *pasajeros;
            while (seg != NULL)
            {
                if (seg->p.edad > cotaEdad)
                {
                    aux = seg;
                    ante->sig = seg->sig;
                    seg=seg->sig;
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

}

void eliminarPasajerosAvionX(nodoAvion** aviones, int idAvion, int cotaEdad)
{
    nodoAvion* aux;
    nodoAvion* ante=NULL;
    nodoAvion* seg=*aviones;
    while (seg != NULL && seg->idAvion > idAvion)
    {
        ante= seg;
        seg = seg->sig;
    }
    if (seg != NULL && seg->idAvion == idAvion)
    {
        eliminarPasajerosMayores(&(seg->pasajeros),cotaEdad);
        if (seg->pasajeros == NULL) ///la lista de pasajeros quedo vacia procedo a eliminar el avion
        {
            aux = seg;
            if (ante == NULL) /// ((*aviones) == seg)
            {
                *aviones = (*aviones)->sig;
            }
            else ///el resto de la lista
            {
               ante->sig = seg->sig;
            }
            free(aux);
        }
    }
}

/**
Realizar una función que pase a archivos las personas de cada uno de los aviones. Ej:
idAvion1.bin ->  todos los pasajeros del idAvion =1
idAvion2.bin -> todos los pasajeros del idAvion = 2

 Puede ser cualquier nombre, no necesariamente debe ser como el ejemplo

**/

void cargarPasajerosArchivo(nodoPasajero* pasajeros, int idAvion)
{
    char nom[12];
    snprintf(nom, 12, "idAvion%i", idAvion);
    FILE* fp = fopen(nom,"wb");
    if (fp)
    {
        while (pasajeros != NULL)
        {
            fwrite(&(pasajeros->p),sizeof(Persona),1,fp);
            pasajeros=pasajeros->sig;
        }
        fclose(fp);
    }
}


void pasarPasajerosArchivos(nodoAvion* aviones)
{
    while (aviones != NULL)
    {
        cargarPasajerosArchivo(aviones->pasajeros,aviones->idAvion);
        aviones=aviones->sig;
    }
}



int main()
{
    nodoAvion* aviones = NULL;
    cargaLista(&aviones);
    pasarPasajerosArchivos(aviones);
    return 0;
}
