#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Interface.h"
#include "inputs.h"
#include "sectors.h"

void initEmployees(eEmployee emp[], int len)
{
    for (int i=0; i<len; i++)
    {
        emp[i].isEmpty = 1;
    }
}

int thereIsFreeSlot(eEmployee emp[], int len)
{
    int index = -1;
    for(int i=0; i<len; i++)
    {
        if(emp[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

void printEmployee(eEmployee emp, eSector sect[], int sectLen)
{
    char description[20];
    int sectorFound = loadSectorDescription(description, emp.sector, sect, sectLen);
    if(sectorFound)
    {
        printf("%4d    %15s     %15s      %13.2f       %10s\n",
               emp.id, emp.name, emp.lastName, emp.salary, description);
    }
    else
    {
        printf("%4d    %15s     %15s      %13.2f     No se encontro sector\n",
               emp.id, emp.name, emp.lastName, emp.salary);
    }
}

int printEmployees(eEmployee emp[], int len, eSector sect[], int sectLen)
{
    int flag = 0;
    printf("  ID             NOMBRE            APELLIDO             SUELDO           SECTOR\n\n");
    for (int i=0; i<len; i++)
    {
        if(emp[i].isEmpty == 0)
        {
            printEmployee(emp[i], sect, sectLen);
            flag = 1;
        }
    }
    if (flag==0)
    {
        printf("No se encontraron empleados activos\n");
    }
    return flag;
}

void getId(int* id)
{
    printf("Ingrese ID del empleado que busca: ");
    scanf("%d", id);
}

void getName(char name[])
{
    getString(name, "\nIngrese nombre del empleado: ", 51);
}

void getLastName(char lastName[])
{
    getString(lastName, "\n\nIngrese apellido del empleado: ", 51);
}

void getSalary(float *salary)
{
        printf("\n\nIngrese sueldo del empleado: ");
        fflush(stdin);
        scanf("%f", salary);
}

void getSector(int *sector)
{
        getInt(sector, "\nIngrese el numero de sector: ", "\nError, ingrese un numero valido: ", 1, 5);
}

int findEmployeeById(eEmployee emp[], int len, int id)
{
    int index = -1;
    for(int i=0; i<len; i++)
    {
        if(id== emp[i].id && emp[i].isEmpty == 0)
        {
            index = i;
        }
    }
    return index;
}

int removeEmployee(eEmployee emp[], int len, int id, eSector sect[], int sectlen)
{
    int success;
    int index = findEmployeeById(emp, len, id);
    if(index == -1)
    {
        success = -1;
    }
    else
    {
        printf("\nEmpleado encontrado.\n\n");
        printf("  ID             NOMBRE            APELLIDO             SUELDO           SECTOR\n");
        printEmployee(emp[index], sect, sectlen);
        int confirms = getYesOrNo("\n\nEsta seguro que desea borrar al siguiente empleado?(s/n)", "\nError, ingrese una opcion valida\n");
        if(confirms)
        {
            emp[index].isEmpty = 1;
            success = 1;
        }
        else
        {
            success = 0;
        }
    }
    return success;
}


int addEmployee(eEmployee emp[], eEmployee newEmp, eSector sect[], int sectlen, int index)
{
    int success = -1;
    printf("\n  ID             NOMBRE            APELLIDO             SUELDO           SECTOR\n\n");
    printEmployee(newEmp, sect, sectlen);
    int confirms = getYesOrNo("\nConfirma el alta del siguiente empleado?(s/n) ","\nError, ingrese una opcion valida\n");
    if(confirms)
    {
        emp[index] = newEmp;
        success = 0;
    }
    return success;
}

void sortEmployees(eEmployee emp[], int len)
{
    eEmployee auxEmp;
    for (int i=0; i<len-1;i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if (emp[i].sector > emp[j].sector)
            {
                auxEmp = emp[i];
                emp[i] = emp[j];
                emp[j] = auxEmp;
            }
        }
    }
    for (int i=0; i<len-1;i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if (strcmp(emp[i].lastName , emp[j].lastName) > 0 && emp[i].sector == emp[j].sector)
            {
                auxEmp = emp[i];
                emp[i] = emp[j];
                emp[j] = auxEmp;
            }
        }
    }
}



float averageSalary(eEmployee emp[], int len)
{
    float total = 0;
    float average;
    int empNumber = 0;
    for(int i=0; i<len; i++)
    {
        if(emp[i].isEmpty == 0)
        {
            total += emp[i].salary;
            empNumber++;
        }
    }
    average = total/empNumber;
    printf("\nTotal de salarios: %f", total);
    printf("\nPromedio de salarios: %f", average);
    return average;
}

int aboveAvgSalary(eEmployee emp[], int len, eSector sect[], int sectlen, int avg)
{
    int counter = 0;
    printf("\nLos siguientes empleados tienen un salario superior al promedio:\n\n");
    printf("  ID             NOMBRE            APELLIDO             SUELDO           SECTOR\n\n");
    for(int i=0; i<len; i++)
    {
        if(emp[i].salary > avg && emp[i].isEmpty == 0)
        {
            counter++;
            printEmployee(emp[i], sect, sectlen);
        }
    }
    printf("\nTotal de empleados con sueldo mayor al promedio: %d\n\n", counter);
    return counter;
}
