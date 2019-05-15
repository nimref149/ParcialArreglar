#include "actores.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define OCUPADO 1
#define LIBRE 0

void inicializarActores(eActores actores[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        actores[i].estado = LIBRE;
    }
}
/** \brief copia datos a la estructura de actores
 *
 * \param actores[] eActores
 * \param tam int
 * \return void
 *
 */
void hardcodearDatosActores(eActores actores[], int tam)
{

    int idActor[]={1,2,3,4,5,6,7,8,9,10};
    char nombre[][20]= {"Scarlett Johansson","Robert  Downey Jr","Mark Ruffalo","Chris Evans","Chris Hemsworth","Samuel Jackson","Gwyneth Paltrow","Paul Rudd","Bradley Cooper","Josh Brolin"};
    char pais[][20]= {"Argentina","EEUU","Canada","EEUU","Argentina","EEUU","Canada","Argentina","EEUU","Canada"};

    int i;
    for(i=0; i<tam; i++)
    {
        strcpy(actores[i].nombre,nombre[i]);
        strcpy(actores[i].pais,pais[i]);
        actores[i].estado = OCUPADO;
        actores[i].idActor = idActor[i];
  }

}
