#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 20
#define NOM_ARCH "agenda.bin"

/** Generar una agenda de Personas, donde cada persona posee nombre y apellido,
telefono, direccion y ciudad a la que pertenece **/


typedef struct
{
    char nombreYapellido[30];
    char telefono[20];
    char direccion[30];
    char ciudad[20];
} Persona;



///prototipados
Persona cargarPersona();
void cargarPersona2(Persona*);
int cargaPersonas(Persona[]);
void cargaPersonasVoid(Persona[],int*);
///

Persona cargarPersona()
{
    Persona p;
    printf("Ingrese nombre y apellido\n");
    fflush(stdin);
    gets(p.nombreYapellido);
    printf("ingrese telefono\n");
    fflush(stdin);
    gets(p.telefono); ///"22345678\0"
    printf("ingrese la direccion\n");
    fflush(stdin);
    gets(p.direccion);
    printf("ingrese la ciudad\n");
    fflush(stdin);
    gets(p.ciudad);

    return p;
}

void cargarPersona2(Persona* p)  // p = 0x36235
{
    printf("Ingrese nombre y apellido\n");
    fflush(stdin);
    gets((*p).nombreYapellido);
    printf("ingrese telefono\n");
    fflush(stdin);
    gets((*p).telefono); ///"22345678\0"
    printf("ingrese la direccion\n");
    fflush(stdin);
    gets((*p).direccion);
    printf("ingrese la ciudad\n");
    fflush(stdin);
    gets((*p).ciudad);
}


int cargaPersonas(Persona agenda[])
{
    int i=0;
    char seguir;
    do
    {
        agenda[i] = cargarPersona();
        //cargarPersona2(&agenda[i]);
        printf("desea continuar\n");
        fflush(stdin);
        scanf("%c",&seguir);
        i++;
    }
    while(seguir == 's' && i < CANT_MAX);


    return i;

}

void cargaPersonasVoid(Persona agenda[],int* validos)
{
    int i=0;
    char seguir;
    do
    {
        agenda[i] = cargarPersona();
        //cargarPersona2(&agenda[i]);
        printf("desea continuar\n");
        fflush(stdin);
        scanf("%c",&seguir);
        i++;
    }
    while(seguir == 's' && i < CANT_MAX);

    *validos = i;

}

void muestraUnaPersona(Persona p)
{
    printf("nombre y apellido: %s\n",p.nombreYapellido);
    printf("telefono: %s\n",p.telefono);
    printf("direccion: %s\n",p.direccion);
    printf("ciudad: %s\n",p.ciudad);
}

void mostrarPersonas(Persona agenda[], int validos)
{
    for (int i= 0; i < validos ; i++)
    {
        muestraUnaPersona(agenda[i]);
    }

}

///retorno indice o -1 si no encontrado
int buscarXTelefono(Persona agenda[], int validos, char telefono[20])
{
    int i =0;
    int pos = -1;
    while (i < validos && strcmpi(telefono,agenda[i].telefono)!=0)
    {
        i++;
    }
    if (i<validos)
    {
        pos = i;
    }

    return pos;
}

void persistencia(Persona agenda[], int validos)
{
  FILE* fp = fopen("agenda.bin","ab");
  if(fp != NULL)
  {
     for (int i = 0 ; i < validos; i++)
     {
         fwrite(&agenda[i],sizeof(Persona),1,fp);
     }

    ///fwrite(agenda,sizeof(Persona),validos,fp);

      fclose(fp);
  }

}

int cantidadRegistrosArchivo()
{
    int cant=0;
    FILE* fp = fopen(NOM_ARCH,"rb");
    if (fp != NULL)
    {
        fseek(fp,0,SEEK_END);
        cant = ftell(fp)/sizeof(Persona);
        fclose(fp);
    }
    return cant;
}


void despersistencia(Persona agenda[], int* validos)
{
   int i = 0;
   FILE* fp = fopen(NOM_ARCH,"rb");
   if (fp != NULL)
   {
      while(fread(&agenda[i],sizeof(Persona),1,fp) > 0)
      {
          i++;
      }

      fclose(fp);
   }
   *validos = i;
}

void despersistencia(Persona agenda[], int* validos)
{
    *validos = cantidadRegistrosArchivo();
    FILE* fp = fopen(NOM_ARCH,"rb");
    if (fp != NULL)
    {
      fread(agenda,sizeof(Persona),*validos,fp);
      fclose(fp);
    }
}

///ir a una posicion paraticular del archivo y mostrar la persona
///pos empieza desde 1
void mostrarPosArchivo(int pos)
{
    Persona p;
    if ( pos >= 1 && pos < cantidadRegistrosArchivo())
    {
        FILE* fp = fopen(NOM_ARCH,"rb");
        if (fp != NULL)
        {
          fseek(fp,sizeof(Persona)*(pos-1),SEEK_SET);
          fread(&p,sizeof(Persona),1,fp);
          fclose(fp);

          muestraUnaPersona(p);
        }

    }

}


int main()
{
    Persona agenda[20];
    int validos;
    int pos;
//    validos = cargaPersonas(agenda);
     //cargaPersonasVoid(agenda,&validos);
//    mostrarPersonas(agenda,validos);
//    pos = buscarXTelefono(agenda,validos,"2234567");
//    if (pos != -1)
//        muestraUnaPersona(agenda[pos]);
//
//   persistencia(agenda,validos);
     despersistencia(agenda,&validos);
     mostrarPersonas(agenda,validos);


    return 0;
}
