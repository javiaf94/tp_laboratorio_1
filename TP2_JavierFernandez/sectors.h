#ifndef SECTORS_H_INCLUDED
#define SECTORS_H_INCLUDED

typedef struct
{
    int id;
    char description[20];

}eSector;


#endif // SECTORS_H_INCLUDED

/** \brief Recibe el ID de un sector, recorre un vector de sectores, comparando el ID con el de cada sector.
          copia el valor de la descripcion de ese sector en una cadena de caracteres, en caso de encontrarlo.
 *
 * \param description[] char Cadena de caracteres donde se pegara la descripcion encontrada
 * \param id int ID del sector del que se busca la descripcion
 * \param sect[] eSector Array de sectores que sera recorrido buscando coincidencia del ID pasado por parametro
 * \param sectLen int Largo del vector de sectores
 * \return int Retorna 1 si encontro el ID
 *
 */
int loadSectorDescription(char description[], int id, eSector sect[], int sectLen);



/** \brief Imprime la informacion de un array de sectores.
 *
 * \param sect[] eSector Array de sectores que sera recorrido imprimiendo cada ID y descripcion.
 * \param sectLen int  Largo del array de sectores
 * \return void
 *
 */
void printSectors(eSector sect[] , int sectLen);
