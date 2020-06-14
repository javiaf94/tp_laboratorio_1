#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "inputs.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* f = fopen(path,"r");
        error = parser_EmployeeFromText(f, pArrayListEmployee);
        fclose(f);
    }
    return error;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* f = fopen(path,"rb");
        error = parser_EmployeeFromBinary(f, pArrayListEmployee);
        fclose(f);
    }
    return error;
}

int controller_findId(LinkedList* pArrayListEmployee, int id)
{
    int indice = -1;

    if(pArrayListEmployee!=NULL)
    {
        Employee* auxEmp;
        int tam = ll_len(pArrayListEmployee);
        for(int i=0; i<tam; i++)
        {
            auxEmp = ll_get(pArrayListEmployee, i);
            if(auxEmp->id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int controller_newId(LinkedList* pArrayListEmployee)
{
    int id = 0;

    if(pArrayListEmployee != NULL)
    {
        int tam = ll_len(pArrayListEmployee);
        for(int i = 0; i<tam; i++)
        {
            Employee* auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            if(auxEmp->id > id )
            {
                id = auxEmp->id;
            }

        }

    }

    return id+1;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;

    if(pArrayListEmployee != NULL)
    {

        int id = controller_newId(pArrayListEmployee);
        if(id>0)
        {
            char strId[100];
            sprintf(strId, "%d", id);
            char nombre[128];
            getString(nombre, "\n\nIngrese nombre del nuevo empleado: ", 128);
            char strSueldo[10];
            char strHsTrabajadas[10];
            int hsTrabajadas;
            int sueldo;
            getInt(&hsTrabajadas, "\nIngrese horas trabajadas por el empleado: ", "\nError, ingrese una cantidad mayor a 0 y menor a 730", 1, 730  );
            getIntMin(&sueldo, "\nIngrese sueldo del empleado: ", "\nError, ingrese un sueldo mayor a 0", 1 );
            sprintf(strHsTrabajadas, "%d", hsTrabajadas);
            sprintf(strSueldo, "%d", sueldo);

            Employee* auxEmp = employee_newParametros(strId, nombre, strHsTrabajadas, strSueldo);

            printf("\n  ID            Nombre       HorasTrabajadas         Sueldo\n");
            printf("-------------------------------------------------------------\n");
            employee_print(auxEmp);

            if(getYesOrNo("\n\nSeguro que desea dar de alta el empleado? (s/n) ", "\nError ingrese s o n"))
            {
                ll_add(pArrayListEmployee, auxEmp);
                error = 0;
            }
        }
    }
    return error;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;

    if(pArrayListEmployee!=NULL)
    {
        int auxInt;
        int indice;

        printf("\nIngrese el ID del empleado que desea modificar: ");
        scanf("%d", &auxInt);

        indice = controller_findId(pArrayListEmployee, auxInt);

        if(indice != -1)
        {
            printf("\nEmpleado encontrado\n");
            system("pause");

            int opcion;
            system("cls");
            printf("*****  MODIFICAR EMPLEADO  *****\n\n");
            printf("\n  ID            Nombre       HorasTrabajadas         Sueldo\n");
            printf("-------------------------------------------------------------\n");

            Employee* auxEmp = (Employee*) ll_get(pArrayListEmployee, indice);
            employee_print(auxEmp);

            printf("\n\n1. Modificar nombre.\n");
            printf("\n\n2. Modificar horas trabajadas.\n");
            printf("\n\n3. Modificar sueldo.\n");
            printf("\n\n4. Salir del menu modificar.\n\n\n");
            getInt(&opcion, "Ingrese el numero de opcion del campo a modificar: ", "Error, ingrese un numero ente 1 y 4", 1 , 4);
            if(opcion==1)
            {
                char nombre[128];
                getString(nombre, "\nIngrese el nuevo nombre: " , 128);
                if(getYesOrNo("\n\nSeguro que desea modificar el nombre del empleado?(s/n)", "\nError, ingrese s o n."))
                {
                    employee_setNombre(auxEmp, nombre);
                    error = 0;
                }
            }
            else if(opcion==2)
            {
                int hsTrabajadas;
                getInt(&hsTrabajadas, "\nIngrese horas trabajadas: ", "\nError, ingrese una cantidad mayor a 0 y menor a 730", 1, 730  );
                if(getYesOrNo("\n\nSeguro que desea modificar las horas trabajadas del empleado?(s/n)", "\nError, ingrese s o n."))
                {
                    employee_setHorasTrabajadas(auxEmp, hsTrabajadas);
                    error = 0;
                }
            }
            else if(opcion==3)
            {
                int sueldo;
                getIntMin(&sueldo, "\nIngrese el nuevo sueldo: ", "\nError, ingrese un sueldo mayor a 0", 1 );
                if(getYesOrNo("\n\nSeguro que desea modificar el sueldo del empleado?(s/n)", "\nError, ingrese s o n."))
                {
                    employee_setSueldo(auxEmp, sueldo);
                    error = 0;
                }
            }

            free(auxEmp);

        }
        else
        {
            printf("\nNo se encontro al empleado.\n");
        }
    }

    return error;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;

    if(pArrayListEmployee!=NULL)
    {
        int auxInt;
        int indice;

        printf("\nIngrese el ID del empleado que desea eliminar: ");
        scanf("%d", &auxInt);

        indice = controller_findId(pArrayListEmployee, auxInt);

        if(indice != -1)
        {
            employee_print((Employee*) ll_get(pArrayListEmployee, indice));
            if (getYesOrNo("\nSeguro que desea eliminar al empleado? (s/n) ", "\nError, ingrese s o n "))
            {
                ll_remove(pArrayListEmployee, indice);
                error = 0;
            }
        }
        else
        {
            printf("\nNo se encontro al empleado.\n");
        }
    }

    return error;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int flag = 0;
    if(pArrayListEmployee!=NULL)
    {
        printf("\n  ID            Nombre       HorasTrabajadas         Sueldo\n");
        printf("-------------------------------------------------------------\n");
        for(int i= 0; i< ll_len(pArrayListEmployee); i++)
        {
            if(!employee_print((Employee*) ll_get(pArrayListEmployee, i)))
            {
                flag = 1;
                error = 0;
            }
        }
        if (flag==0)
        {
            printf("No hay empleados para mostrar\n\n");
        }
    }
    return error;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;

    if(pArrayListEmployee!=NULL)
    {
        if(ll_len(pArrayListEmployee)<1)
        {
            printf("\nNo hay empleados para ordenar.\n");
        }
        else
        {
           int opcion;
           printf("1.Ordenar empleados por ID ascendentemente.\n");
           printf("2.Ordenar empleados por ID descendentemente.\n");
           printf("3.Ordenar empleados por nombre ascendentemente.\n");
           printf("4.Ordenar empleados por nombre descendentemente.\n");
           printf("5.Ordenar empleados por cantidad de horas ascendentemente.\n");
           printf("6.Ordenar empleados por cantidad de horas descendentemente.\n");
           printf("7.Ordenar empleados por sueldo ascendentemente.\n");
           printf("8.Ordenar empleados por sueldo descendentemente.\n");
           printf("9.Salir.\n");
           getInt(&opcion, "\n\nIngrese el numero de la opcion a la que desea acceder: ", "\nError, ingrese una opcion valida: ", 1, 9);
           if (opcion==1)
           {

                if(!ll_sort(pArrayListEmployee, employee_compareId, 1 ))
                {
                    error = 0;
                }
           }
           else if (opcion==2)
           {

                if(!ll_sort(pArrayListEmployee, employee_compareId, 0 ))
                {
                    error = 0;
                }
           }
           else if (opcion==3)
           {
                if(!ll_sort(pArrayListEmployee, employee_compareNombre, 1 ))
                {
                    error = 0;
                }
           }
           else if (opcion==4)
           {
                if(!ll_sort(pArrayListEmployee, employee_compareNombre, 0 ))
                {
                    error = 0;
                }
           }
           else if (opcion==5)
           {
                if(!ll_sort(pArrayListEmployee, employee_compareHsTrabajadas, 1 ))
                {
                    error = 0;
                }
           }
           else if (opcion==6)
           {
                if(!ll_sort(pArrayListEmployee, employee_compareHsTrabajadas, 0 ))
                {
                    error = 0;
                }
           }
           else if (opcion==7)
           {
                if(!ll_sort(pArrayListEmployee, employee_compareSueldo, 1 ))
                {
                    error = 0;
                }
           }
           else if (opcion==8)
           {
                if(!ll_sort(pArrayListEmployee, employee_compareSueldo, 0 ))
                {
                    error = 0;
                }
           }
           else
           {
               printf("\nSalio del menu ordenar.\n");
           }
        }
    }
    return error;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    Employee* auxEmp;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        error = 0;
        FILE* f = fopen(path, "w");
        int len = ll_len(pArrayListEmployee);
        fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");
        for(int i= 0; i<len; i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(f, "%d,%s,%d,%d\n", auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
        }
        fclose(f);
    }
    return error;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* f = fopen(path, "wb");
        if(f!=NULL)
        {
            error = 0;
            int tam = ll_len(pArrayListEmployee);
            Employee* auxEmp;
            for(int i = 0; i<tam; i++)
            {
                auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                fwrite(auxEmp, sizeof(Employee), 1, f);
            }
        }
    }
    return error;
}


