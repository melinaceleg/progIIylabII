#include <stdio.h>
#include <stdlib.h>
/**

Un sistema de listado de ventas diarias,
donde en cada venta diaria aparecera un listado de las ventas
realizadas en ese dia **/

/*LISTA CON SUBLISTAS*/

typedef struct
{
    char DNI[9];
    float total;
    int hora;
}TicketVenta;

typedef struct nodoTicket {
    TicketVenta dato;
    struct nodoTicket* sig;
}nodoTicket;

typedef struct nodoVenta {
    char fecha[12];
    float total_venta;
    nodoTicket* tickets;
    struct nodoVenta* sig;
}nodoVenta;

nodoTicket* crearNodoTicket(TicketVenta dato)
{
    nodoTicket* nuevo = (nodoTicket*) malloc(sizeof(nodoTicket));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}

nodoVenta* crearNodoVenta(char* fecha)
{
    nodoVenta* nuevo = (nodoVenta*)malloc(sizeof(nodoVenta));
    strcpy(nuevo->fecha,fecha);
    nuevo->total_venta = 0;
    nuevo->tickets = NULL;
    return nuevo;
}

TicketVenta cargaTicket()
{
    TicketVenta t;
    printf("Ingrese un total de venta\n");
    scanf("%f", &t.total);
    printf("Ingrese DNI del comprador\n");
    fflush(stdin);
    gets(t.DNI);
    printf("Ingrese hora\n");
    scanf("%i", &t.hora);

    return t;

}

///cargo una venta al final de la lista de ventas
void cargarVenta(nodoVenta** ventas, nodoVenta* nuevoDia)
{
    nodoVenta* act;
    if (*ventas == NULL)
    {
        *ventas = nuevoDia;
    }
    else
    {
        act = *ventas;
        while (act->sig != NULL)
        {
            act = act->sig;
        }
        act->sig = nuevoDia;
    }
}
///cargo un ticket al final de la lista de tickets
void ingresarTicket(nodoTicket** tickets, TicketVenta ticket)
{
    nodoTicket* nuevo = crearNodoTicket(ticket);
    nodoTicket* act;
    if (*tickets == NULL)
    {
        *tickets = nuevo;
    }
    else
    {
        act = *tickets;
        while (act->sig != NULL)
        {
            act = act->sig;
        }
        act->sig = nuevo;
    }
}

///genero unn nuevo dia de ventas
///cargar los tickets que van ingresando
void generarDiaVentas(nodoVenta** ventas, char* fecha)
{
    char seguir;
    TicketVenta ticket;
    nodoVenta* nuevoDia = crearNodoVenta(fecha);
    cargarVenta(ventas,nuevoDia);
    do
    {
        ticket = cargaTicket();
        ingresarTicket(&(nuevoDia->tickets),ticket);
        nuevoDia->total_venta = nuevoDia->total_venta + ticket.total;
        printf("Desea ingresar otro ticket?\n");
        fflush(stdin);
        scanf("%c", &seguir);
    }while (seguir == 's');

}


void mostrarUnTicket(TicketVenta dato)
{
    printf("DNI comprador: %s\n", dato.DNI);
    printf("hora: %i\n", dato.hora);
    printf("total: %f\n", dato.total);
}

void mostrarTicketsDelDia(nodoTicket* tickets)
{
    while (tickets != NULL)
    {
        mostrarUnTicket(tickets->dato);
        tickets=tickets->sig;
    }
}

void mostrarUnDiaDeVentas(nodoVenta* ventas, char* fecha)
{
    while (ventas != NULL && strcmp(fecha,ventas->fecha) < 0)
    {
        ventas=ventas->sig;
    }
    if (ventas != NULL && strcmp(fecha,ventas->fecha) == 0)
    {
        printf("Tickets del dia %s \n", fecha);
        printf("Monto total: %f \n", ventas->total_venta);
        printf("****tickets****\n");
        mostrarTicketsDelDia(ventas->tickets);
    }



}

void borrarListaTickets(nodoTicket** tickets)
{
    nodoTicket* aux;
    while (*tickets != NULL)
    {
        aux = *tickets;
        *tickets = (*tickets)->sig;
        free(aux);
    }
}


void borrarUnTicket(nodoTicket ** tickets, char* DNI)
{
    ///implementar


}

void eliminarUnTicket(nodoVenta* ventas, char* DNI, char* fecha)
{
    while (ventas != NULL && strcmp(fecha,ventas->fecha) <0)
    {
        ventas= ventas->sig;
    }
    if (ventas!= NULL && strcmp(ventas->fecha,fecha)==0)
    {
        borrarUnTicket(&(ventas->tickets),DNI);
    }
}



void borrarUnaVentaDiaria(nodoVenta** ventas, char* fecha)
{
    nodoVenta* aux;
    nodoVenta* ant,*act;
    if (*ventas != NULL)
    {
        if (strcmp(*ventas->fecha,fecha) == 0)
        {
            aux = *ventas;
            *ventas=(*ventas)->sig;
            borrarListaTickets(&(aux->tickets));
            free(aux);
        }
        ant = *ventas;
        act = (*ventas)->sig;

        while (act != NULL && strcmp(fecha,act->fecha) < 0)
        {
            ant = act;
            act = act->sig;
        }
        if (act != NULL && strcmp(fecha,act->fecha)==0)
        {
            ant->sig = act->sig;
            borrarListaTickets(&(act->tickets));
            free(act);
        }
    }
}



int main()
{
    nodoVenta* ventas = NULL;
    generarDiaVentas(&ventas,"10-22-2021");
    mostrarUnDiaDeVentas(ventas,"10-22-2021");
    borrarUnaVentaDiaria(&ventas,"10-22-2021");
    eliminarUnTicket(ventas,"3323","10-22-2021");
//    generarDiaVentas(&ventas,"10-23-2021");
//    generarDiaVentas(&ventas,"10-24-2021");
    return 0;
}
