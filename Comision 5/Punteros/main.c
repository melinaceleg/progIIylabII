#include <stdio.h>
#include <stdlib.h>


void intercambio(int* a, int* b) 0x44 , 0x55
{
    int x;
    x = *a; /// x = 5
    *a = *b; /// a = 12
    *b = x; /// b = 5
}


int main()
{
    int num = 5;
    int* puntero;

    puntero = &num;

    *puntero = 6;

    printf("que almacena puntero: %x\n", puntero);
    printf("que hay adentro de la direccion que almacena puntero: %i\n", *puntero);
    printf("direccion de num: %x\n", &num);
    printf("num :%i\n", num);

    int a = 5; /// 0x44
    int b = 12; /// 0x55
    intercambio(&a,&b);

    return 0;
}
