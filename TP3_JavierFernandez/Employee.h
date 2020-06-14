#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


/** \brief Imprime por pantalla los datos de un empleado.
 *
 * \param emp Employee*
 * \return int Retorna 1 si hubo error, 0 si se completo correctamente
 *
 */
int employee_print(Employee* emp);

/** \brief Recibe un id por parametro y se lo setea a un empleado.
 *
 * \param this Employee*
 * \param id int
 * \return int Retorna 1 si hubo error, 0 si se completo correctamente
 *
 */
int employee_setId(Employee* this,int id);


/** \brief Recibe un empleado por parametro, y guarda el valor de su ID en una variable.
 *
 * \param this Employee*
 * \param id int*
 * \return int Retorna 1 si hubo error, 0 si se completo correctamente
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Recibe un nombre por parametro y se lo setea a un empleado.
 *
 * \param this Employee*
 * \param id int
 * \return int Retorna 1 si hubo error, 0 si se completo correctamente
 *
 */
int employee_setNombre(Employee* this,char* nombre);



int employee_getNombre(Employee* this,char* nombre);

/** \brief Recibe cantidad de horas por parametro y se lo setea a un empleado.
 *
 * \param this Employee*
 * \param id int
 * \return int Retorna 1 si hubo error, 0 si se completo correctamente
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


 int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

 /** \brief Recibe un sueldo por parametro y se lo setea a un empleado.
 *
 * \param this Employee*
 * \param id int
 * \return int Retorna 1 si hubo error, 0 si se completo correctamente
 *
 */
int employee_setSueldo(Employee* this,int sueldo);



int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Consigue espacio en memoria dinamica para un empleado
 *
 * \return Employee*
 *
 */
Employee* employee_new();


/** \brief Consigue espacio en memoria dinamica para un empleado, y le asigna los valores recibidos por parametro
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Borra un empleado
 *
 * \param emp Employee*
 * \return int Retorna 1 si hubo error, 0 y se borro correctamente.
 *
 */
int employee_delete(Employee* emp);

/** \brief Compara los ID de 2 empleados
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int Retorna 0 si son iguales, -1 si el primero es menor y 1 si el primero es mayor
 *
 */
int employee_compareId(void* emp1, void* emp2);

/** \brief Compara los sueldos de 2 empleados
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int Retorna 0 si son iguales, -1 si el primero es menor y 1 si el primero es mayor
 *
 */
int employee_compareSueldo(void* emp1, void* emp2);

/** \brief Compara las horas de 2 empleados
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int Retorna 0 si son iguales, -1 si el primero es menor y 1 si el primero es mayor
 *
 */
int employee_compareHsTrabajadas(void* emp1, void* emp2);

/** \brief Compara los nombres de 2 empleados
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int Retorna 0 si son iguales, -1 si el primero es menor y 1 si el primero es mayor
 *
 */
int employee_compareNombre(void* emp1, void* emp2);

#endif // employee_H_INCLUDED
