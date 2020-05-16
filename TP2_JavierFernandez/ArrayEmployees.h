#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#include "inputs.h"
#include "sectors.h"

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;


#endif // ARRAYEMPLOYEES_H_INCLUDED


/** \brief Inicializa un array de empleados, poniendo los valores isEmpty de cada posicion en 1
 *
 * \param emp[] eEmployee Array de empleados que se recorrera
 * \param len int Largo del array de empleados
 * \return void
 *
 */
void initEmployees(eEmployee emp[], int len);




/** \brief Recorre un vector de empleados y verifica si hay al menos una posicion libre
 *
 * \param emp[] eEmployee Vector de empleados a recorrer
 * \param len int Largo del vector de empleados
 * \return int Retorna -1 si no hay ninguna posicion libre. Retorna el indice de la primer posicion libre, de encontrarla.
 *
 */
int thereIsFreeSlot(eEmployee emp[], int len);




/** \brief Solicita una cadena de caracteres por teclado, valida el largo y copia el valor en un array de caracteres.
 *
 * \param name[] char array de caracteres donde se copiara el valor ingresado por teclado una vez validado
 * \return void
 *
 */
void getName(char name[]);



/** \brief Solicita una cadena de caracteres por teclado, valida el largo y copia el valor en un array de caracteres.
 *
 * \param lastName[] char array de caracteres donde se copiara el valor ingresado por teclado una vez validado
 * \return void
 *
 */
void getLastName(char lastName[]);



/** \brief Solicita un numero tipo float por teclado y copia el valor ingresado en una variable pasada por parametro.
 *
 * \param salary float* variable donde se almacenara el valor ingresado por teclado
 * \return void
 *
 */
void getSalary(float *salary);



/** \brief  Solicita un entero mediante la funcion getInt, valida que se encuentre en el rango correcto y lo actualiza en una
            variable pasada por parametro.
 *
 * \param sector int* variable donde se almacenara el entero ingresado por teclado
 * \return void
 *
 */
void getSector(int *sector);



/** \brief  Solicito un entero por teclado, actualizo el dato ingresado en una variable tipo entero
 *
 * \param id int* Puntero a la direccion de memoria donde se cargara el valor ingersado
 * \return void
 *
 */
void getId(int* id);


/*Plantee la funcion addEmployee con algunas diferencias a como era propuesta en el enunciado. Esto se debe a que, por ejemplo,
En el enunciado retornaba -1 si no habia lugar, pero tambien recibia por parametro los datos de un nuevo empleado. Es decir
(entiendo) que habia que solicitar los datos por pantalla primero, y luego validar si habia lugar o no, lo que me parecio poco
eficiente. También, por una cuestion de practicidad, decidí pasar los datos del nuevo empleado utilizando un empleado auxiliar,
para no tener que pasarle un parametro por cada dato.
*/

/** \brief  Recibe los datos de un nuevo empleado y pide confirmacion para el alta del mismo
 *
 * \param emp[] eEmployee Vector de empleados donde se cargara el nuevo empleado
 * \param newEmp eEmployee Empleado auxiliar que contiene la informacion a ser cargaeda en el vector de empleados
 * \param sect[] eSector  Vector de sectores utilizado para mostrar sector con la funcion mostrarEmpleado.
 * \param sectlen int largo del vector de sectores
 * \param index int indice del vector de empleados donde se cargará el nuevo empleado
 * \return int Retorna 0 si se confirma la carga, -1 si no se confirma
 *
 */
int addEmployee(eEmployee emp[], eEmployee newEmp, eSector sect[], int sectlen, int index);



/** \brief Recibe un ID por parametro, y busca en el vector de empleados si hay algun empleado activo con dicho ID
 *
 * \param emp[] eEmployee vector de empleados a recorrer
 * \param len int largo del vector de empleados
 * \param id int ID que se buscara en el vector.
 * \return int  Retorna -1 si el empleado no existe, o no esta activo. de lo contrario, retorna el indice de la posicion
           donde encuentra coincidencia
 *
 */
int findEmployeeById(eEmployee emp[], int len, int id);


/** \brief Muestra por pantalla los datos de un empleado de manera encolumnada. Muestra la descripcion correspondiente al IDSector del usuario
 *
 * \param emp eEmployee empleado que se imprimira
 * \param sect[] eSector Vector de empleados utilizado para buscar la descripcion segun el ID.
 * \param sectLen int Largo del vector de sectores.
 * \return void
 *
 */
void printEmployee(eEmployee emp, eSector sect[], int sectLen);



/** \brief Recorre un vector de empleados, imprimiendo la informacion del empleado en cada indice.
 *
 * \param emp[] eEmployee Vector de empleados que se imprimira
 * \param len int Largo del vector de empleados a recorrer.
 * \param sect[] eSector Vector de sectores de donde se copiara la descripcion del sector.
 * \param sectLen int Largo del vector de sectores a recorrer
 * \return int Retorna 1 en caso de que haya impreso por lo menos un empleado. Retorna 0 en el caso contrario
 *
 */
int printEmployees(eEmployee emp[], int len, eSector sect[], int sectLen);



/** \brief Da la opcion de borrar un empleado del vector de empleados de manera logica.
 *
 * \param emp[] eEmployee Vector de empleados que sera recorrido para ver si el empleado existe.
 * \param len int Largo del vector de empleados a recorrer
 * \param id int  ID del empleado a borrar. Se validara que el mismo corresponde a un empleado activo
 * \param sect[] eSector Vector de sectores utilizado para mostrar la descripcion del IDSector del usuario por pantalla
 * \param sectlen int Largo del vector de sectores a recorrer
 * \return int Retorna -1 si el ID no corresponde a un empleado activo; 0 si el usuario no confirma la baja; 1 si se borró exitosamente.
 *
 */
int removeEmployee(eEmployee emp[], int len, int id, eSector sect[], int sectlen);



/** \brief Recibe un vector de empleados y lo ordena alfabeticamente por apellido y agrupados por sector.
 *
 * \param emp[] eEmployee Vector de empleados a ordenar
 * \param len int Largo del vector de empleados a recorrer.
 * \return void
 *
 */
void sortEmployees(eEmployee emp[], int len);




/** \brief Calcula e imprime por pantalla la sumatoria de salarios activos y su promedio.
 *
 * \param emp[] eEmployee Vector de empleados que se recorrerá para calcular los salarios.
 * \param len int Largo del vector a recorrer
 * \return float Retorna el promedio de los salarios activos.
 *
 */
float averageSalary(eEmployee emp[], int len);




/** \brief Cuenta la cantidad de empleados con un salario mayor al promedio, y los imprime por pantalla.
 *
 * \param emp[] eEmployee Vector de empleados que sera recorrido buscando empleados con salario mayor al promedio
 * \param len int Largo del vector de empleados a recorrer
 * \param sect[] eSector Vector de sectores utilizado para mostrar por pantalla la descripcion del IDsector de los empleados
 * \param sectlen int Largo del vector de sectores a recorrer
 * \param avg int Promedio de salarios del vector de empleados con el cual se comparara el salario de cada empleado del vector.
 * \return int Retorna la cantidad de empleados con salario mayor al promedio.
 *
 */
int aboveAvgSalary(eEmployee emp[], int len, eSector sect[], int sectlen, int avg);
