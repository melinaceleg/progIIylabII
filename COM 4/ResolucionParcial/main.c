#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#define archConsumos "consumos.bin"
#define archReservas "reservas.bin"
#define archVIPS "clientesVIP.bin"
typedef struct
{
    char item[30];
    float valor;
    int nro_mesa;
} Consumo;

typedef struct
{
    char nombre_cliente[30];
    char DNI[9];
    int nro_mesa;
} Reserva;

typedef struct
{
    char DNI[9];
    float descuento;
} ClienteVIP;

typedef struct nodoConsumo
{
    Consumo dato;
    struct nodoConsumo* siguiente;
} nodoConsumo;

typedef struct nodoReserva
{
    Reserva dato;
    struct nodoReserva* siguiente;
} nodoReserva;

/**
Carga de datos
a) Generar una lista simplemente enlazada de tipo “Consumo” ordenada por “nro_mesa” ascendente. (recursiva)
b) Generar una lista simplemente enlazada de tipo “Reserva” ordenada por “nro_mesa” ascendente..

**/

///a)

nodoConsumo* crearNodoConsumo(Consumo dato)
{
    nodoConsumo* nuevo = (nodoConsumo*)malloc(sizeof(nodoConsumo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}


void insertarOrdenadoConsumos(nodoConsumo** consumos, Consumo dato)
{

    if(*consumos == NULL || (*consumos)->dato.nro_mesa > dato.nro_mesa)
    {
        nodoConsumo* nuevo = crearNodoConsumo(dato);
        nuevo->siguiente = *consumos;
        *consumos = nuevo;
    }
    else
    {
        insertarOrdenadoConsumos(&((*consumos)->siguiente),dato);
    }

}

void cargaListaConsumos(nodoConsumo** listaConsumos)
{
    FILE* fp = fopen(archConsumos,"rb");
    Consumo dato;
    if (fp)
    {
        while (fread(&dato,sizeof(Consumo),1,fp) > 0)
        {
            insertarOrdenadoConsumos(listaConsumos,dato);
        }

        fclose(fp);

    }

}


///b)
nodoReserva* crearNodoReserva(Reserva dato)
{
    nodoReserva* nuevo = (nodoReserva*)malloc(sizeof(nodoReserva));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;

}

void insertarOrdenadoReservas(nodoReserva** listaReservas,Reserva dato)
{
    nodoReserva* nuevo = crearNodoReserva(dato);
    nodoReserva* ante, *seg;
    if (*listaReservas == NULL || (*listaReservas)->dato.nro_mesa > dato.nro_mesa)
    {
        nuevo->siguiente = *listaReservas;
        *listaReservas = nuevo;
    }
    else
    {
        ante = *listaReservas;
        seg = (*listaReservas)->siguiente;
        while (seg != NULL && (seg->dato.nro_mesa < dato.nro_mesa))
        {
            ante = seg;
            seg = seg->siguiente;
        }
        ante->siguiente = nuevo;
        nuevo->siguiente = seg;
    }
}

void cargaListaReservas(nodoConsumo** listaReservas)
{
    FILE* fp = fopen(archReservas,"rb");
    Reserva dato;
    if (fp)
    {
        while (fread(&dato,sizeof(Reserva),1,fp) > 0)
        {
            insertarOrdenadoReservas(listaReservas,dato);
        }
        fclose(fp);
    }

}


/**
Generar una función que cargue una fila de tickets (se recibe por parámetro),
donde cada ticket posee el “nro_mesa”, la suma total del consumo de esa mesa,
y el “totalConDescuento” (si posee).
Por lo tanto para saber si tiene descuento o no se debe ir a buscar el DNI de
la reserva con ese “nro_mesa” al archivo de “ClientesVIP.bin”,
y si no es “ClienteVIP” no se le hará descuento (es el mismo valor que total).
Aclaración: No traer los datos del archivo clientesVIP.bin a una lista,
usarlos desde el archivo.

 La estructura de "ticket" es la siguiente:
**/

typedef struct
{
    int nro_mesa;
    char DNI[9];
    char nombre_cliente[30];
    float total;
    float totalConDescuento;
} ticket;
///2)

float calcularTotal(nodoConsumo* consumos, int nroMesa)
{
    float total  = 0;
    while ((consumos != NULL) && (consumos->dato.nro_mesa < nroMesa))
    {
        consumos = consumos->siguiente;
    }
    while ((consumos != NULL) && (consumos->dato.nro_mesa == nroMesa)) ///puede haber varios consumos en el mismo nro_mesa
    {
        total = total + consumos->dato.valor;
        consumos = consumos->siguiente;
    }
    return total;

}


void cargaFila(Fila* tickets, nodoConsumo* consumos, nodoReserva* reservas)
{
    Ticket nuevoTicket;
    float total;
    FILE* fp = fopen(archVIPS, "rb");
    ClienteVIP cliente;
    if (fp)
    {

        while (reservas != NULL)
        {
            rewind(fp); ///situo el puntero a posicion en el archivo al principio.
            total = calcularTotal(consumos,reservas->dato.nro_mesa);
            nuevoTicket.nro_mesa = reservas->dato.nro_mesa;
            strcpy(nuevoTicket.DNI,reservas->dato.DNI);
            strcpy(nuevoTicket.nombre_cliente,reservas->dato.nombre_cliente);
            nuevoTicket.total = total;
            while(fread(&cliente,sizeof(ClienteVIP),1,fp)> 0 && strcmp(cliente.DNI,nuevoTicket.DNI) != 0);
            if (!feof(fp)) /// o strcmp(cliente.DNI,nuevoTicket.DNI) == 0)
            {
                nuevoTicket.totalConDescuento = (nuevoTicket.total*cliente.descuento)/100;
            }
            else
            {
                nuevoTicket.totalConDescuento = nuevoTicket.total;
            }

            poneFila(tickets,nuevoTicket);
            reservas = reservas->siguiente;
        }
        fclose(fp);
    }

}
/**
Hacer una función recursiva que muestre todos los consumos de un “nro_mesa”
recibido por parámetro. (ojo!, recordar que la lista está ordenada ;) )
**/

///3

void mostrarUnConsumo(Consumo c)
{
    printf("nombre: %s\n", c.item);
    printf("nro mesa: %i\n", c.nro_mesa);
    printf("valor: %.2f\n", c.valor);

}

void mostrarConsumosMesa(nodoConsumo* consumos, int nroMesa)
{
    if (consumos != NULL && consumos->dato.nro_mesa <= nroMesa) /// si es distinta de null y ademas estoy parado sobre un valor de mesa que es menor o igual al que busco
    {
        if (consumos->dato.nro_mesa == nroMesa)
        {
            mostrarUnConsumo(consumos->dato);
        }
        mostrarConsumosMesa(consumos->siguiente,nroMesa);
    }
}

///4
/**
Hacer una función que muestre los tickets de la fila, no perder la fila.
**/

///4

void mostrarUnTicket(Ticket t)
{
    printf("\nDNI: %s\n",t.DNI);
    printf("nombre: %s\n",t.nombre_cliente);
    printf("nro mesa: %i\n",t.nro_mesa);
    printf("total: %.2f\n",t.total);
    printf("con descuento: %.2f\n",t.totalConDescuento);

}

void mostrarTicketsFila(Fila* tickets)
{
    Fila aux;
    inicFila(&aux);
    Ticket ticket;
    printf("\nTickets: \n");
    while (!Filavacia(*tickets))
    {
       ticket = sacaFila(tickets);
       mostrarUnTicket(ticket);
       poneFila(&aux,ticket);
    }
   while (!Filavacia(aux))
    {
       poneFila(tickets,sacaFila(&aux));
    }

}



int main()
{
    nodoConsumo* consumos = NULL;
    nodoReserva* reservas = NULL;
    int nroMesa;
    Fila tickets;
    inicFila(&tickets);
    ///1
    cargaListaConsumos(&consumos);
    cargaListaReservas(&reservas);
    ///2
    cargaFila(&tickets,consumos,reservas);
    ///3
    nroMesa=3;
    printf("Consumos de la mesa %i:\n",nroMesa);
    mostrarConsumosMesa(consumos,nroMesa);
    ///4
    mostrarTicketsFila(&tickets);

    return 0;
}
