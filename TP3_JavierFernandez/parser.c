#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int error = 1;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        char buffer[4][128];
        Employee* auxEmp;
        int cant;
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);
        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);
            if(cant==4)
            {
                auxEmp = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                ll_add(pArrayListEmployee,auxEmp);
                error = 0;
            }
        }
    }
    return error;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int error = 1;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        error = 0;
        int cant;
        while(!feof(pFile))
        {
            Employee* auxEmp = employee_new();
            cant = fread(auxEmp, sizeof(Employee), 1, pFile);
            if(cant==1)
            {
                ll_add(pArrayListEmployee,auxEmp);
            }
        }
    }
    return error;
}
