#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Interface.h"


int mainMenu()
{
    int option;
    system("cls");
    printf("*****  MENU PRINCIPAL *****\n\n\n");
    printf("1. Dar de alta empleado.\n\n");
    printf("2. Modificar empleado.\n\n");
    printf("3. Dar de baja empleado.\n\n");
    printf("4. Menu de informes.\n\n");
    printf("5. Salir.\n\n\n");
    getInt(&option, "Ingrese el numero de opcion del menu al que desea acceder: ", "Error, ingrese un numero valido.\n", 1, 5);
    return option;
}

int modifyMenu()
{
    int option;
    printf("1. Modificar nombre.\n\n");
    printf("2. Modificar apellido.\n\n");
    printf("3. Modificar salario.\n\n");
    printf("4. Modificar sector.\n\n");
    printf("5. Salir.\n\n\n");
    getInt(&option, "Ingrese el numero de opcion del menu al que desea acceder: ", "Error, ingrese un numero valido.\n", 1, 5);
    return option;
}

int reportsMenu()
{
    int option;
    printf("1. Listar empleados alfabeticamente por sector.\n\n");
    printf("2. Reporte salarios.\n\n");
    printf("3. Salir.\n\n\n");
    getInt(&option, "Ingrese el numero de opcion del menu al que desea acceder: ", "Error, ingrese un numero valido.\n", 1, 3);
    return option;
}
