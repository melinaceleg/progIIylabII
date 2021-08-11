#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 5;
    int* puntero;
    puntero = &num;
//    printf("contenido de puntero: %x", puntero);
//    printf("direccion de num: %x\n", &num);
//
//    *puntero = 8;
//
//    printf("contenido de la direccion que apunta puntero: %i\n", *puntero);
//    printf("contenido de num: %i", num);

 /////////////////
    int arreglo[] = {1,2,3,4,5,6,7,8,9,10};
    int *punt;

    punt = arreglo;

    printf("%x\n", arreglo+0);

    for (int i = 0 ; i < 10 ; i++)
    {
        printf("%x\t",&arreglo[i]); /// arreglo+i
    }
    printf("\n");


    for (int i = 0 ; i< 10 ; i++)
    {
        printf("%i\t", *(arreglo+i));

    }

    for (int i = 0; i < 10; i++)
    {
        printf("%i\t", punt[i]);
        //printf("%i", *(punt+i))
    }





    return 0;
}
