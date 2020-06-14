#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

int menu();

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        option = menu();
        switch(option)
        {
            case 1:
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("\nEmpleados cargados con exito.\n\n");
                }
                else
                {
                    printf("\nProblema para cargar los empleados.\n\n");
                }
                system("pause");
                break;

            case 2:
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("\nEmpleados cargados con exito.\n\n");
                }
                else
                {
                    printf("\nProblema para cargar los empleados.\n\n");
                }
                system("pause");
                break;

            case 3:
                system("cls");
                printf("*****  ALTA DE EMPLEADO  *****\n\n");
                if(!controller_addEmployee(listaEmpleados))
                {
                    printf("\nEmpleado dado de alta con exito.\n\n");
                }
                else
                {
                    printf("\nNo se dio de alta al empleado.\n\n");
                }
                system("pause");
                break;

            case 4:
                system("cls");
                printf("*****  MODIFICAR EMPLEADO  *****\n\n");

                if(!controller_ListEmployee(listaEmpleados))
                {
                    if(!controller_editEmployee(listaEmpleados))
                    {
                        printf("\n\nEmpleado modificado con exito.\n\n");
                    }
                    else
                    {
                        printf("\n\nNo se modifico el empleado.\n\n");
                    }
                }

                system("pause");
                break;

            case 5:
                system("cls");
                printf("*****  ELIMINAR EMPLEADO  *****\n\n");

                if(!controller_ListEmployee(listaEmpleados))
                {
                    if(!controller_removeEmployee(listaEmpleados))
                    {
                        printf("\n\nEl empleado se borro con exito\n\n");
                    }
                    else
                    {
                        printf("\n\nNo se pudo borrar el empleado.\n\n");
                    }
                }

                system("pause");
                break;

            case 6:
                system("cls");
                printf("*****  LISTA DE EMPLEADOS  *****\n\n");
                controller_ListEmployee(listaEmpleados);
                system("pause");
                break;

            case 7:
                system("cls");
                printf("*****  ORDENAR EMPLEADOS  *****\n\n");
                if(!controller_sortEmployee(listaEmpleados))
                {
                    printf("\n\nSe ordenaron los empleados con exito.\n\n");
                }
                else
                {
                    printf("\n\nNo se pudo realizar el ordenamiento.\n\n");
                }
                system("pause");
                break;


            case 8:
                if(!controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("\nArchivo guardado correctamente.\n\n");
                }
                else
                {
                    printf("\nNo pudo guardarse el archivo.\n\n");
                }
                system("pause");
                break;

            case 9:
                if(!controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("\nArchivo guardado correctamente.\n\n");
                }
                else
                {
                    printf("\nNo pudo guardarse el archivo.\n\n");
                }
                system("pause");
                break;

            case 10:
                printf("\nDecidio salir.\n\n");
                break;

            default:
                printf("\nIngrese una opcion valida.\n\n");
                system("pause");
        }
    }while(option != 10);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

int menu()
{
     int auxInt;
     system("cls");
     printf("*****  MENU PRINCIPAL GESTION EMPLEADOS CON LINKED LIST  *****\n\n");
     printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
     printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
     printf("3. Alta de empleado.\n");
     printf("4. Modificar datos de empleado.\n");
     printf("5. Baja de empleado.\n");
     printf("6. Listar empleados.\n");
     printf("7. Ordenar empleados.\n");
     printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
     printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
     printf("10. Salir.\n\n");
     printf("Ingrese el numero de opcion a la que quiere acceder: ");
     fflush(stdin);
     scanf("%d", &auxInt);
     return auxInt;
}


