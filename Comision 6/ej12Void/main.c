#include <stdio.h>
#include <stdlib.h>

void busquedaVoid1(int arreglo[],int u,int busca,int* enc)
{
    if (u == 0)
    {
        if (arreglo[0] == busca)
            *enc = 1;
        else
            *enc = 0;
    }
    else
    {
        if (arreglo[u] == busca)
        {
            *enc =1;
        }
        else
        {
            busquedaVoid(arreglo,u-1,busca,enc);
        }
    }

}
///esta variante hace una llamada recursiva mas (con u=-1)
void busquedaVoid2(int arreglo[],int u,int busca,int* enc)
{
    if (u == -1)
    {
        *enc = 0;
    }
    else
    {
        if (arreglo[u] == busca)
        {
            *enc =1;
        }
        else
        {
            busquedaVoid(arreglo,u-1,busca,enc);
        }
    }

}

///otra variante donde se hara una llamada recursiva mas (con u = -1)
void busquedaVoid3(int arreglo[],int u,int busca,int* enc)
{

    if (u >=0)
    {

        if (arreglo[u] == busca)
        {
            *enc =1;
        }
        else
        {
            busquedaVoid(arreglo,u-1,busca,enc);
        }
    }
    else
    {
        *enc=0;
    }

}

///las funciones siguientes de suma no necesitan recibir el parametro de salida inicializado,
///ya que se inicializa dentro

////retorno la suma a traves del parametro por referencia
void sumaVoid(int arreglo[],int u,int* suma)
{
    if (u==0)
    {
        *suma = arreglo[0];
    }
    else
    {
        sumaVoid(arreglo,u-1,suma);
        *suma = *suma + arreglo[u];
    }

}
//desventaja : tiene un parametro mas (debo tener el valor de la ultima posicion y no alteraarlo)
void sumaVoid2(int arreglo[],int u, int* suma,int ult)
{
    if (u == ult)
    {
        *suma = arreglo[u];
        sumaVoid2(arreglo,u-1,suma,ult);
    }
    else
    {
        if (u>=0)
        {
            *suma = *suma + arreglo[u];
            sumaVoid2(arreglo,u-1,suma,ult);
        }
    }
}

/// 1 2 4 1
void capicuaVoid(int arreglo[],int i, int u, int* flag)
{
    if ( i < u)
    {
        if (arreglo[i] != arreglo[u])
        {
            *flag = 0;
        }
        else
        {
            capicuaVoid(arreglo,i+1,u-1,flag);
        }

    }
    else
    {
        *flag = 1;
    }

}




int main()
{
    int arreglo[] = {1,2,4,1};
    int validos = 4;
    int busca;
    int enc;
    int suma;
    int flag;
    printf("Ingrese un valor a buscar\n");
    scanf("%i",&busca);
    busquedaVoid(arreglo,validos-1,busca,&enc);
    sumaVoid(arreglo,validos-1,&suma);
    sumaVoid2(arreglo,validos-1,&suma,validos-1);
    capicuaVoid(arreglo,0,validos-1,&flag);
    return 0;
}
