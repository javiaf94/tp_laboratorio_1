#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED

/** \brief Solicita ingresar un entero por teclado. Valida el exito en la carga, según el tipo de dato ingresado.
 *
 * \param texto, recibe el texto a mostrar por pantalla, solicitando la entrada de datos.
 * \param pValor, recibe la dirección de memoria donde se guardara el valor ingresado.
 * \return retorna 1 si el dato ingresado es un entero, y 0 si es otro tipo de dato.
 *
 */
 int pedirEntero(char texto[], int* pValor);



/** \brief Muestra el menu principal con las opciones a elegir. Solicitando elegir la opción
 *
 * \param pX, recibe dirección de memoria del primer operando, para ser mostrado por pantalla en caso de ya haber sido ingresado
 * \param pY, recibe dirección de memoria del segundo operando, para ser mostrado por pantalla en caso de ya haber sido ingresado
 * \param pFlagOperandoUno, recibe la direccion de memoria del flag operandoUno, para validar si ya se ingresó un operando
 * \param pFlagOperandoDos, recibe la direccion de memoria del flag operandoDos, para validar si ya se ingresó un operando
 * \return retorna el valor de opción ingresado por el usuario, se espera un entero.
 *
 */
int mostrarMenu(int* pX, int* pY, int* pFlagOperandoUno, int* pFlagOperandoDos);



/** \brief Recibe dos enteros y devuelve la suma de los mismos
 *
 * \param X recibe el primer sumando
 * \param Y recibe el segundo sumando
 * \return Retorna el resultado de la suma entre x e y.
 *
 */
int suma(int x,int y);



/** \brief Recibe dos enteros y devuelve la resta entre el primero y el segundo
 *
 * \param X recibe el entero minuendo
 * \param Y recibe el  entero sustraendo
 * \return Retorna el resultado de la resta x e y
 *
 */
int resta(int x, int y);



/** \brief Recibe dos enteros y devuelve el producto entre ambos
 *
 * \param X recibe un entero multiplicando
 * \param Y recibe otro entero multiplicando
 * \return Retorna el producto entre x e y
 *
 */
int multiplicacion(int x, int y);



/** \brief Recibe un numero y devuelve su factorial obtenido de forma recursiva
 *
 * \param X recibe el entero del que se calculara el factorial
 * \return Retorna el factorial de X.
 *
 */
long long int factorial(int x);



/** \brief Recibe dos enteros, y la direccion de memoria de la variable donde se almacenará el resultado de la división entre ambos
 *
 * \param X recibe el entero dividendo
 * \param Y recibe el entero divisor
 * \param resultado recibe la dirección de memoria donde se actualizará el resultado
 * \return Retorna 0 si el divisor es igual a 0, y 1 en caso contrario.
 *
 */
int division(int x, int y, float* pResultado);

#endif // TP1_H_INCLUDED
