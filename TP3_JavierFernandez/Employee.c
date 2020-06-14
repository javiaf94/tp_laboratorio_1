#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"


int employee_delete(Employee* emp)
{
    int error = 1;
    if(emp!=NULL)
    {
        error = 0;
        free(emp);
    }
    return error;
}


int employee_setId(Employee* this,int id)
{
    int error = 1;
    if(this!=NULL)
    {
        error = 0;
        this->id = id;
    }
    return error;
}

int employee_getId(Employee* this,int* id)
{
    int error = 1;
    if(this!=NULL && id!= NULL)
    {
        error = 0;
        *id = this->id;
    }
    return error;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error = 1;
    if(this!=NULL && strlen(nombre) > 0 && strlen(nombre) < 128)
    {
        error = 0;
        strcpy(this->nombre, nombre);
    }
    return error;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int error = 1;
    if(this!=NULL && nombre!= NULL)
    {
        error = 0;
        strcpy(nombre, this->nombre );
    }
    return error;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int error = 1;
    if(this!=NULL && horasTrabajadas >= 0 && horasTrabajadas < 730)
    {
        error = 0;
        this->horasTrabajadas = horasTrabajadas;
    }
    return error;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error = 1;
    if(this!=NULL && horasTrabajadas!= NULL)
    {
        error = 0;
        *horasTrabajadas = this->horasTrabajadas;
    }
    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int error = 1;
    if(this!=NULL && sueldo >= 0 )
    {
        error = 0;
        this->sueldo = sueldo;
    }
    return error;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = 1;
    if(this!=NULL && sueldo!= NULL)
    {
        error = 0;
        *sueldo = this->sueldo;
    }
    return error;
}

Employee* employee_new()
{
    Employee* auxEmp = (Employee*) malloc(sizeof(Employee));
    if(auxEmp!=NULL)
    {
        auxEmp->id = 0;
        strcpy(auxEmp->nombre, "");
        auxEmp->horasTrabajadas = 0;
        auxEmp->sueldo = 0;
    }
    return auxEmp;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* auxEmp = (Employee*) malloc(sizeof(Employee));
    if(auxEmp!=NULL)
    {
        if(employee_setId(auxEmp, atoi(idStr)) || employee_setNombre(auxEmp, nombreStr) ||
           employee_setHorasTrabajadas(auxEmp, atoi(horasTrabajadasStr)) || employee_setSueldo(auxEmp, atoi(sueldoStr)) )
        {
            free(auxEmp);
            auxEmp = NULL;
        }
    }
    return auxEmp;
}

int employee_print(Employee* emp)
{
    int error = 1;
    if(emp!=NULL)
    {
        printf("%4d       %10s                 %3d       %10d\n" , emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
        error = 0;
    }
    return error;
}

int employee_compareId(void* emp1, void* emp2)
{
    int rta;
    Employee* a = (Employee*) emp1;
    Employee* b = (Employee*) emp2;

    if(a->id == b->id)
    {
        rta = 0;
    }
    else if(a->id > b->id)
    {
        rta = 1;
    }
    else
    {
        rta = -1;
    }
    return rta;
}

int employee_compareSueldo(void* emp1, void* emp2)
{
    int rta;
    Employee* a = (Employee*) emp1;
    Employee* b = (Employee*) emp2;

    if(a->sueldo == b->sueldo)
    {
        rta = 0;
    }
    else if(a->sueldo > b->sueldo)
    {
        rta = 1;
    }
    else
    {
        rta = -1;
    }
    return rta;
}

int employee_compareHsTrabajadas(void* emp1, void* emp2)
{
    int rta;
    Employee* a = (Employee*) emp1;
    Employee* b = (Employee*) emp2;

    if(a->horasTrabajadas == b->horasTrabajadas)
    {
        rta = 0;
    }
    else if(a->horasTrabajadas > b->horasTrabajadas)
    {
        rta = 1;
    }
    else
    {
        rta = -1;
    }
    return rta;
}

int employee_compareNombre(void* emp1, void* emp2)
{
    int rta;
    Employee* a = (Employee*) emp1;
    Employee* b = (Employee*) emp2;

    if(strcmp(a->nombre, b->nombre)== 0)
    {
        rta = 0;
    }
    else if(strcmp(a->nombre, b->nombre)== 1)
    {
        rta = 1;
    }
    else
    {
        rta = -1;
    }
    return rta;
}
