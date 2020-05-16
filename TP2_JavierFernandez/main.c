#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interface.h"
#include "ArrayEmployees.h"
#include "inputs.h"
#include "sectors.h"

#define LEN 1000
#define SECTLEN 5



int main()
{
    //inicializo vector de Empleados con tamaño 1000
    eEmployee employees[LEN];
    initEmployees(employees, LEN);
    //inicializo un vector de Sectores hardcodeado con sus valores
    eSector sectors[SECTLEN] = {{1, "Tecnologia"}, {2, "Networking"},{3, "Finanzas"},{4, "RRHH"},{5, "Marketing"}};
    int flagAddEmployee = 0;
    int autoID = 1001;
    int idSearch; //declare aqui las variables utilizadas para almacenar el ID de la busqueda de un empleado,
    int index;   // y el indice de una posicion vacia,  ya que las llamare en varios cases.
    char auxStr[51]; //Declare las variables auxiliares con la misma logica que los comments anteriores
    int auxInt;
    float auxFloat;
    eEmployee auxEmployee;
    int option;
    do
    {
        switch(option = mainMenu())
        {
        case 1:
            system("cls");
            printf("***** MENU ALTA DE EMPLEADO *****\n\n");
            index = thereIsFreeSlot(employees, LEN);    //valido que haya lugar libre para realizar la carga
            if(index == -1)
            {
                printf("La lista de empleados esta llena.\n");
            }
            else                           //solicito los datos del nuevo empleado y lo almaceno en un empleado aux
            {
                auxEmployee.id = autoID;
                getName(auxStr);
                strcpy(auxEmployee.name, auxStr);
                getLastName(auxStr);
                strcpy(auxEmployee.lastName, auxStr);
                getSalary(&auxFloat);
                auxEmployee.salary = auxFloat;
                printSectors(sectors, SECTLEN);
                getSector(&auxInt);
                auxEmployee.sector = auxInt;
                auxEmployee.isEmpty = 0;

                if(addEmployee(employees, auxEmployee, sectors,SECTLEN,index)== 0) //pido confirmacion para el alta
                {
                    printf("\nEl empleado se dio de alta correctamente.\n");
                    autoID++;
                    flagAddEmployee = 1;
                }
                else
                {
                    printf("\nSe aborto el alta del empleado. Volvera al menu principal\n");
                }
            }
            system("pause");
            break;


        case 2:
            if(flagAddEmployee==0)
            {
                printf("\nDebe cargarse un empleado primero antes de poder acceder al menu de modificaciones.\n");
                system("pause");
                break;
            }
            system("cls");
            printf("***** MENU MODIFICAR EMPLEADO *****\n\n\n");
            getId(&idSearch);                                   //pido el ID a modificar
            index = findEmployeeById(employees, LEN, idSearch);
            if (index == -1)
            {
                printf("El id ingresado no corresponde a ningun empleado activo.\n");
            }
            else
            {
                printf("\nEmpleado encontrado. \n\n");
                printf("  ID             NOMBRE            APELLIDO             SUELDO           SECTOR\n");
                printEmployee(employees[index], sectors, SECTLEN);
                printf("\n\n");
                int confirms;
                switch (modifyMenu())
                {
                case 1:             //solicito el nombre a modificar
                    getName(auxStr);
                    printf("Seguro que desea modificar el nombre  por %s ?", auxStr);
                    confirms = getYesOrNo("(Ingrese s/n)", "\nIngrese una opcion valida.");
                    if(confirms)    //segun confirme, borro el empleado o aborto la modificacion
                    {
                        strcpy(employees[index].name, auxStr);
                        printf("\nSe cambio el nombre con exito.\n");
                    }
                    else
                    {
                        printf("\nModificacion cancelada, volvera al menu principal.\n");
                    }
                    break;

                case 2:
                    getLastName(auxStr);
                    printf("Seguro que desea modificar el apellido por %s ?", auxStr);
                    confirms = getYesOrNo("(Ingrese s/n)", "\nIngrese una opcion valida.");
                    if (confirms)
                    {
                        strcpy(employees[index].lastName, auxStr);
                        printf("\nSe cambio el apellido con exito.\n");
                    }
                    else
                    {
                        printf("\nModificacion cancelada, volvera al menu principal.\n");
                    }
                    break;

                case 3:
                    getSalary(&auxFloat);
                    printf("Seguro que desea modificar el salario por %.2f ?", auxFloat);
                    confirms = getYesOrNo("(Ingrese s/n)", "\nIngrese una opcion valida.");
                    if (confirms)
                    {
                        employees[index].salary = auxFloat;
                        printf("\nSe cambio el salario con exito.\n");
                    }
                    else
                    {
                        printf("\nModificacion cancelada, volvera al menu principal.\n");
                    }
                    break;

                case 4:
                    printSectors(sectors, SECTLEN); //muestro la lista de sectores y pido ingresar el ID
                    getSector(&auxInt);            //del sector que se modificará.
                    printf("Seguro que desea modificar el sector por el numero %02d ?", auxInt);
                    confirms = getYesOrNo("(Ingrese s/n)", "\nIngrese una opcion valida.");
                    if (confirms)
                    {
                        employees[index].sector = auxInt;
                        printf("\nSe cambio el sector con exito.\n");
                    }
                    else
                    {
                        printf("\nModificacion cancelada, volvera al menu principal.\n");
                    }
                    break;

                case 5:
                    printf("Salio al menu principal");
                    break;
                }
            }
            system("pause");
            break;



        case 3:
            if(flagAddEmployee==0)
            {
                printf("\nDebe cargarse un empleado primero antes de poder acceder al menu de bajas.\n");
                system("pause");
                break;
            }
            system("cls");
            printf("***** MENU BAJA DE EMPLEADO *****\n\n\n");
            getId(&idSearch);
            int deleted = removeEmployee(employees, LEN, idSearch, sectors, SECTLEN);
            if (deleted == -1)
            {
                printf("\nEl id ingresado no corresponde a ningun empleado activo.\n\n");
            }
            else if(deleted == 0)
            {
                printf("\nSe aborto el borrado. Volvera al menu principal\n\n");
            }
            else if(deleted == 1)
            {
                printf("\nEl empleado ha sido borrado con exito.\n\n");
            }
            system("pause");
            break;



        case 4:
            if(flagAddEmployee==0)
            {
                printf("\nDebe cargarse un empleado primero antes de poder acceder al menu de informes.\n");
                system("pause");
                break;
            }

            system("cls");
            printf("***** LISTADO DE EMPLEADOS *****\n\n");
            switch(reportsMenu())
            {
            case 1:
                system("cls");
                printf("***** LISTADO DE EMPLEADOS *****\n\n");
                printf("Empleados alfabeticamente por sector.\n\n");
                sortEmployees(employees, LEN);
                printEmployees(employees, LEN, sectors, SECTLEN);
                break;

            case 2:
                system("cls");
                printf("***** LISTADO DE EMPLEADOS *****\n\n");
                printf("Reporte salarios.\n\n");
                aboveAvgSalary(employees, LEN, sectors, SECTLEN, averageSalary(employees, LEN));
                break;

            case 3:
                printf("\nEligio salir. Volvera al menu principal\n");
                break;
            }
            system("pause");
            break;


        case 5:
            printf("\nSalio del sistema.\n");
            break;

        }
    }
    while(option!=5);


    return 0;
}

