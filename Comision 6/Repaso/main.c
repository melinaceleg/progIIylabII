#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 20
#define NOM_ARCH "agenda.bin"
//* Una agenda de Personas, donde cada persona tiene nombre y apellido, telefono, direccion **/


typedef struct
{
    char nombre_y_apellido[30];
    char telefono[20];
    char direccion[40];
    char ciudad[20];
} Persona;

void cargaAgenda(Persona agenda[], int* validos)
{
    int i=0;
    char seguir;
    Persona p;
    do
    {
        printf("Ingrese nombre y apellido\n");
        fflush(stdin);
        gets(p.nombre_y_apellido);
        printf("ingrese telefono\n");
        fflush(stdin);
        scanf("%s",p.telefono);
        printf("Ingrese direccion\n");
        fflush(stdin);
        gets(p.direccion);
        printf("Ingrese ciudad\n");
        fflush(stdin);
        gets(p.ciudad);
        agenda[i] = p;
        i++;
        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    while(seguir == 's' && i<CANT_MAX);

    *validos = i;
}

void mostrar_una_persona(Persona p)
{
    printf("Nombre y apellido: %s\n", p.nombre_y_apellido);
    printf("Telefono: %s\n", p.telefono);
    printf("Direccion: %s\n", p.direccion);
    printf("Ciudad: %s\n\n", p.ciudad);

}

void muestra_Agenda(Persona agenda[], int validos)
{
    for (int i = 0 ; i < validos ; i++)
    {
        mostrar_una_persona(agenda[i]);
    }
}

int busca_por_telefono(Persona agenda[],int validos, char telefono[])
{
    int i=0;
    int pos = -1;
    while (i<validos && strcmp(agenda[i].telefono,telefono) != 0)
    {
        i++;
    }
    if (i < validos)
    {
        pos = i;
    }

    return pos;

}

void persistenciaDeAgenda(Persona agenda[], int validos)
{
    FILE* fp = fopen("agenda.bin","ab");
    if (fp != NULL)
    {
        for (int i = 0 ; i < validos; i++)
        {
            fwrite(&agenda[i],sizeof(Persona),1,fp);
        }

        // fwrite(agenda,sizeof(Persona),validos,fp);

        //fwrite(agenda,sizeof(Persona)*validos,1,fp);

        fclose(fp);
    }

}

void despersistencia(Persona agenda[], int* validos)
{
    FILE* fp = fopen("agenda.bin","rb");
    int i=0;
    if (fp != NULL)
    {
        while (fread(&agenda[i],sizeof(Persona),1,fp) >0 )
        {
            i++;
        }

        fclose(fp);
    }

    *validos = i;

}

void cantidad_Personas(int* validos)
{
    FILE* fp = fopen(NOM_ARCH,"rb");
    if (fp != NULL)
    {
        fseek(fp,0,SEEK_END);
        *validos = ftell(fp)/sizeof(Persona);
    }

}

void mostrarPersonaEnPos(int pos)
{
    Persona p;
    int cant;
    FILE* fp = fopen(NOM_ARCH,"rb");
    if (fp != NULL)
    {
        cantidad_Personas(&cant);
        if (pos >= 0 && pos < cant)
        {
            fseek(fp,sizeof(Persona)*pos,SEEK_SET);
            fread(&p,sizeof(Persona),1,fp);
            mostrar_una_persona(p);
        }
        fclose(fp);
    }
}



int main()
{

    Persona agenda[20];
    int validos;
//    cargaAgenda(agenda,&validos);
//    muestra_Agenda(agenda,validos);
//    persistenciaDeAgenda(agenda,validos);
//    despersistencia(agenda,&validos);
//    muestra_Agenda(agenda,validos);
      mostrarPersonaEnPos(1);


    return 0;
}
