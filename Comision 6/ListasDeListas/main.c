#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**

Un sistema de listado de ventas diarias,
donde en cada venta diaria aparecera un listado de las ventas
realizadas en ese dia

**/

typedef struct
{
    char DNI[9];
    float total;
    int hora;
} TicketVenta;


typedef struct nodoTicket
{
    TicketVenta dato;
    struct nodoTicket* sig;

} nodoTicket;

typedef struct nodoVenta
{
    char fecha[12];
    float total_venta_dia;
    nodoTicket* tickets;
    struct nodoVenta* sig;
} nodoVenta;


nodoTicket* crearNodoTicket(TicketVenta dato)
{
    nodoTicket* nuevo = (nodoTicket*)malloc(sizeof(nodoTicket));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}


///genero una nueva venta del dia (abro un dia)
nodoVenta* crearNodoVenta(char* fecha)
{
    nodoVenta* nuevo = (nodoVenta*)malloc(sizeof(nodoVenta));
    strcpy(nuevo->fecha,fecha);
    nuevo->total_venta_dia = 0;
    nuevo->tickets = NULL;
    nuevo->sig = NULL;
    return nuevo;
}

///carga de un ticket al final de la lista
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
            act=act->sig;
        }
        act->sig = nuevo;
    }
}

TicketVenta cargaTicket()
{
    TicketVenta t;
    printf("Ingrese DNI del comprador:\n");
    fflush(stdin);
    gets(t.DNI);
    printf("Ingrese monto:\n");
    scanf("%f",&t.total);
    printf("Ingrese hora:\n");
    scanf("%i",&t.hora);
    return t;
}

///cargo una nueva venta al final de la lista de ventas
void cargarVenta(nodoVenta** ventas,nodoVenta* nuevo)
{
    nodoVenta* act;
    if (*ventas == NULL)
    {
        *ventas = nuevo;
    }
    else
    {
        act = *ventas;
        while (act->sig != NULL)
        {
            act = act->sig;
        }
        act->sig = nuevo;
    }
}


///se genera un nuevo dia, y dentro de esta funcion se generaran las ventas en el desarrollo diario
void generarDiaVentas(nodoVenta** ventas, char* fecha)
{
    char seguir;
    TicketVenta ticket;
    nodoVenta* nuevoDia = crearNodoVenta(fecha);
    do
    {
        ticket = cargaTicket();
        ingresarTicket(&(nuevoDia->tickets),ticket);
        nuevoDia->total_venta_dia = nuevoDia->total_venta_dia + ticket.total;
        printf("Desea ingresar otra compra del dia?\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    while (seguir == 's');

    cargarVenta(ventas,nuevoDia);

}


void mostrarUnTicket(TicketVenta t)
{
    printf("DNI: %s\n",t.DNI);
    printf("monto total: %f\n",t.total);
    printf("hora: %i\n",t.hora);
}

void mostrarTicketsDelDia(nodoTicket* tickets)
{
    while (tickets != NULL)
    {
        mostrarUnTicket(tickets->dato);
        tickets=tickets->sig;
    }
}

void mostrarUnaVenta(nodoVenta* ventas, char* dia)
{
    while (ventas != NULL && strcmp(ventas->fecha,dia) < 0)
    {
        ventas= ventas->sig;
    }
    if (ventas != NULL && strcmp(ventas->fecha,dia) == 0)
    {
        printf("Venta del dia %s:\n", dia);
        printf("Monto generado: %f\n", ventas->total_venta_dia);
        mostrarTicketsDelDia(ventas->tickets);
    }
    else
        printf("NO hay ventas para ese dia\n");
}


void imprimirTicketsSegunDNI(nodoTicket* tickets, char* DNI)
{
    while (tickets != NULL)
    {
        if (strcmpi(tickets->dato.DNI, DNI) == 0)
        {
            mostrarUnTicket(tickets->dato);
        }
        tickets=tickets->sig;
    }

}


void imprimirHistorialTicketsDNI(nodoVenta* ventas, char* DNI)
{
    printf("Compras del dni: %s\n", DNI);
    while (ventas != NULL)
    {
        imprimirTicketsSegunDNI(ventas->tickets,DNI);
        ventas=ventas->sig;
    }

}

void eliminarListaTickets(nodoTicket** tickets)
{
    nodoTicket* aux;
    while (*tickets != NULL)
    {
        aux = *tickets;
        *tickets = (*tickets)->sig;
        free(aux);
    }
}

void eliminarUnDiaDeVenta(nodoVenta** ventas, char* fecha)
{
    nodoVenta* aux, *act,*ant;
    if (*ventas != NULL)
    {
        aux = (*ventas);
        if (strcmp((*ventas)->fecha,fecha) == 0 )
        {
            eliminarListaTickets(&(ventas->tickets));
        }
        *ventas = (*ventas)->sig;
        free(aux);
    }
    else
    {
        ant = *ventas;
        act = (*ventas)->sig;
        while (act != NULL &&  strcmp(act->fecha,fecha) <0 )
        {
            ant = act;
            act = act->sig;
        }
        if (act && strcmp(act->fecha,fecha) == 0)
        {
            eliminarListaTickets(&(act->tickets))
            ant->sig = act->sig;
            free(act);
        }
    }

}



int main()
{
    nodoVenta* ventas = NULL;
    generarDiaVentas(&ventas,"10-26-2021");
    mostrarUnaVenta(ventas,"10-26-2021");

    imprimirHistorialTicketsDNI(ventas,"31222111");
    return 0;
}
