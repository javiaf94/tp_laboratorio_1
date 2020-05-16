#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interface.h"
#include "ArrayEmployees.h"
#include "inputs.h"
#include "sectors.h"

int loadSectorDescription(char description[], int id, eSector sect[], int sectLen)
{
    int success = 0;
    for(int i=0; i<sectLen; i++)
    {
        if(id== sect[i].id)
        {
            strcpy(description, sect[i].description);
            success = 1;
        }
    }
    return success;
}

void printSectors(eSector sect[] , int sectLen)
{
    printf("\n***** Sectores *****\n\n");
    printf("ID          DESCRIPCION\n\n");
    for(int i=0; i<sectLen; i++)
    {
        printf("%02d  %20s\n", sect[i].id, sect[i].description);
    }
}
