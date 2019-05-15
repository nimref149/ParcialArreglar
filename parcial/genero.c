#include "genero.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void hardcodearDatosGenero(eGenero generos[], int tam)
{
    int idGenero[]={1,2,3,4,5};
    char descripcion[][20]={"Accion","Comedia","Drama","Romance","Terror"};
    int i;
    for(i=0; i<tam; i++)
    {
        strcpy(generos[i].descripcion,descripcion[i]);
        generos[i].idGenero = idGenero[i];

     }

}
