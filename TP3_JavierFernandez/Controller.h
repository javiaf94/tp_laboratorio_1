/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna 1 si hubo error 0 si se completó correctamente.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna 1 si hubo error 0 si se completó correctamente.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);



/** \brief Recorre una Linked List y busca si hay algun empleado con el ID pasado por parametro
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int Retorna 1 si hubo error 0 si se completó correctamente.
 *
 */
int controller_findId(LinkedList* pArrayListEmployee, int id);



/** \brief Recorre una Linked List, busca cual es el ID del empleado mas grande y devuelve ese ID + 1
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_newId(LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna 1 si hubo error 0 si se completó correctamente.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna 1 si hubo error 0 si se completó correctamente.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna 1 si hubo error 0 si se completó correctamente.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna 1 si hubo error 0 si se completó correctamente.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna 1 si hubo error 0 si se completó correctamente.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna 1 si hubo error 0 si se completó correctamente.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna 1 si hubo error 0 si se completó correctamente.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);




