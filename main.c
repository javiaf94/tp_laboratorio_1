#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tp1.h"


int main()
{                   //declaro variables para operandos, resultados y flags
    int opcion;
    int x;
    int pidioExitosamenteX;
    int y;
    int pidioExitosamenteY;
    int resultSuma;
    int resultResta;
    int resultMultiplicacion;
    float resultDivision;
    int divisionExitosa;
    long long int resultFactorialX;
    long long int resultFactorialY;
    int flagOperandoUno = 0;
    int flagOperandoDos = 0;
    int flagOperaciones = 0;
    do      //Bucle principal, se muestra el menu principal hasta que la opción sea 5, para salir.
    {
        opcion = mostrarMenu(&x, &y, &flagOperandoUno, &flagOperandoDos);
        switch(opcion)
        {
        case 1:
            pidioExitosamenteX = pedirEntero("\ningrese el primer operando:\n", &x);
            if(pidioExitosamenteX)  //valido si el dato ingresado es un entero, de lo contrario se mostrara un mensaje de error
            {
                flagOperandoUno = 1;
            }
            break;

        case 2:
            pidioExitosamenteY = pedirEntero("\ningrese el segundo operando:\n",&y);
            if(pidioExitosamenteY)
            {
                flagOperandoDos = 1;
            }
            break;

        case 3:
            if (flagOperandoUno==0)   //valido que hayan sido ingresados los 2 operandos.
            {
                printf("\nERROR, falta ingresar el primer operando\n");
                getch();
                break;
            }
            else if(flagOperandoDos==0)
            {
                printf("\nERROR, falta ingresar el segundo operando\n");
                getch();
                break;
            }
            else
            {
                resultSuma = suma(x,y);
                resultResta = resta(x,y);
                resultMultiplicacion = multiplicacion(x,y);
                resultFactorialX = factorial(x);
                resultFactorialY = factorial(y);
                divisionExitosa = division(x, y, &resultDivision); //según la funcion retorne 1 o 0 se validará si es posible realizar la división
                flagOperaciones = 1;
                printf("\n Las operaciones se calcularon con exito\n");
                getch();
                break;
            }

        case 4:
            if (flagOperaciones==0)
            {
                printf("\nERROR, falta realizar las operaciones\n");
                getch();
                break;
            }
            else
            {
                printf("El resultado de %d + %d es: %d\n\n", x, y, resultSuma);
                printf("El resultado de %d - %d es: %d\n\n", x, y, resultResta);
                printf("El resultado de %d * %d es: %d\n\n", x, y, resultMultiplicacion);

                if(x<1)
                {
                    printf("A es menor a uno, no esta definido el factorial\n\n");
                }
                else
                {
                    printf("El factorial de %d es %lli \n\n", x, resultFactorialX);
                }

                if(y<1)
                {
                    printf("B es menor a uno, no esta definido el factorial\n\n");
                }
                else
                {
                    printf("El factorial de %d es %lli \n\n", y, resultFactorialY);
                }

                if(divisionExitosa)
                {
                    printf("El resultado de %d / %d es: %.2f\n\n", x, y, resultDivision);
                }
                else
                {
                    printf("No puede dividirse por cero\n\n");
                }

                printf("Presione una tecla para continuar. Se volvera al menu principal y se limpiaran las operaciones.\n");
                getch();
                flagOperandoUno = 0;  //reinicio los flags, para que al volver al menu principal, solicite ingresar los operandos nuevamente
                flagOperandoDos = 0;
                flagOperaciones = 0;
                break;
            }

        case 5:
            printf("\nHa decidido salir\n");
            break;

        default:  //si el valor ingresado en la funcion mostrar menu no es ningúna de las opciones, volverá al menu principal
            printf("\nError, ingrese un numero de opcion valido\n\n");
            printf("Presione una tecla para volver al menu principal\n");
            fflush(stdin);
            getch();
        }
    }while (opcion != 5);

    return 0;
}



