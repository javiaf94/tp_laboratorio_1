#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tp1.h"


int pedirEntero(char texto[],int* pValor)
{
    int exito;
    printf("%s\n", texto);
    exito = scanf("%d", pValor);
    if(exito != 1)
    {
        printf("\nERROR, ingrese un numero entero \n\n");
        fflush(stdin);
        getch();
        return 0;
    }
    else
    {
        printf("\nEl numero se cargo correctamente.\n");
        fflush(stdin);
        getch();
        return 1;
    }
}

int mostrarMenu(int* pX, int* pY, int* pFlagOperandoUno, int* pFlagOperandoDos)
{
    int opcion;
    system("cls");
    printf("BIENVENIDO, INGRESE EL NUMERO DE LA OPCION DESEADA.\n\n");

    if(*pFlagOperandoUno == 1)  //clausula para validar si ya se ingresó un valor para A, y mostrarlo por pantalla.
    {
        printf("1. Ingresar primer operando. El numero ingresado actualmente es A = %d\n\n", *pX);
    }
    else
    {
        printf("1. Ingresar primer operando.\n\n");
    }

    if(*pFlagOperandoDos == 1)   //clausula para validar si ya se ingresó un valor para B, y mostrarlo por pantalla.
    {
        printf("2. Ingresar segundo operando. El numero ingresado actualmente es B = %d\n\n", *pY);
    }
    else
    {
        printf("2. Ingresar segundo operando.\n\n");
    }

    printf("3. Calcular las operaciones.\n\n");
    printf("4. Informar resultados.\n\n");
    printf("5. Salir.\n\n");
    scanf("%d", &opcion);
    return opcion;
}

int suma(int x,int y)
{
    return x+y;
}

int resta(int x, int y)
{
    return x-y;
}

int multiplicacion(int x, int y)
{
    return x*y;
}

long long int factorial(int x)
{
    if(x<1)
    {
        return 1;
    }
    else
    {
        return (long long) x*factorial(x-1);
    }
}

int division(int x, int y, float* pResultado)
{
    if (y==0)
    {
        return 0;
    }
    else
    {
        *pResultado = (float)x / y;
        return 1;
    }
}
