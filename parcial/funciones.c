#include <stdlib.h>
#include "funciones.h"
#define TP 1000
#define TA 50
#define TG 5
#include <string.h>
#include <stdio.h>
#define OCUPADO 1
#define LIBRE 0

void menu()
{

    int opcion;

    ePeliculas peliculas[TP];
    inicializarPeliculas(peliculas,TP);
    hardcodearDatosPeliculas(peliculas,21);

    eActores actores[TA];
    inicializarActores(actores,TA);
    hardcodearDatosActores(actores,10);

    eGenero generos[TG];
    hardcodearDatosGenero(generos,5);
    int opcion2;

    do
    {
        opcion = menuDeOpciones("[>>>>>>>>>>>>>ABM PELICULAS<<<<<<<<<<<<]\n\n1.Alta\n\n2.Modificar\n\n3.Baja\n\n4.Mostrar\n\n5-MasOpciones\n\n10.Salir\n\nElija una opcion: ");
        switch(opcion)
        {
            case 1:
                cargarPeliculaAutomatico(peliculas,TP,generos,actores);
                break;
            case 2:
                modificarPelicula(peliculas, TP, 3,generos,actores,TA);
                break;
            case 3:
                borrarPelicula(peliculas, TP, 3);
                break;
            case 4:
                ordenarPeliculasPorAnio(peliculas,TP);
                mostrarPeliculas(peliculas,TP,generos,TG,actores,TA);
                ordenarActoresPorPais(actores,TA);
                mostrarActores(actores,TA);

                break;
            case 5:
                printf("Elija una opcion\n1-Mostrar todas las peliculas con genero y actor\n2-Peliculas cuya nacionalidad del actor es EEUU\n3-Por cada genero el titulo del las peliculas que perteneces a ese genero\n4-Por cada genero cantidad de peliculas\n");
                scanf("%d",&opcion2);
                switch(opcion2){
                case 1:
                mostrarPeliculasActorGenero(peliculas,TP,generos,TG,actores,TA);
                break;
                case 2:
                mostrarPeliculasNacionalidadActorEEUU(peliculas,TP,generos,TG,actores,TA);
                break;
                case 3:
                listarPeliculasXGenero(peliculas,TP,generos,TG);
                case 4:
                listarPeliculasXcantidadGenero(peliculas,TP,generos,TG);
                break;
                }
            case 10:
                printf("Esta saliendo del programa");
                break;
            default:
            printf("La opcion ingreda no es correcta\n");
            break;

        }
    }while(opcion!=10);

}

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}


void inicializarPeliculas(ePeliculas peliculas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        peliculas[i].estado = LIBRE;
    }
}

void hardcodearDatosPeliculas(ePeliculas peliculas[], int tam)
{


    int id[]={1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,1019,1020};
    int idActor[]= {2,5,4,5,2,3,1,9,4,9,7,1,9,1,10,2,10,10,7,6,6};

    char titulo[][50]= {"Avengers end game","Thor","Cellular","Men in Black","IronMan","13 Going on 30","Lucy","Nace una estrella","¿Dime con cuantos?","Guardianes de la galaxia","A perfect murder","La isla","Que paso ayer","Home Alone 3","Deadpool","Sherlock Holmes","Men in Black 3","Avengers infinity war","Grandes esperanzas","SWAT","XxX"};
    int idGenero[]= {1,1,1,1,1,4,1,4,4,1,3,3,2,2,1,1,1,1,4,1,1};
    int dia[]={20,10,2,10,5,7,9,8,4,20,6,3,5,6,7,5,2,6,8,20,11};
    int mes[]={4,6,5,7,9,5,2,3,4,5,8,10,2,10,12,6,5,4,12,2,5};
    int anio[]={2019,2013,2004,2019,2012,2004,2014,2018,2010,2014,1995,2005,2013,1997,2015,2011,2010,2017,1995,1998,1992};
    int i;
    for(i=0; i<tam; i++)
    {

        peliculas[i].id=id[i];
        peliculas[i].idActor=idActor[i];
        strcpy(peliculas[i].titulo,titulo[i]);
        peliculas[i].idGenero=idGenero[i];
        peliculas[i].dia=dia[i];
        peliculas[i].mes=mes[i];
        peliculas[i].anio=anio[i];
        peliculas[i].estado=OCUPADO;
  }

}


void cargarPeliculaAutomatico(ePeliculas peliculas[], int tam,eGenero generos[],eActores actores[])
{
    int i;
    i = buscarLibre(peliculas, tam);
    if(i!=-1)
    {
        fflush(stdin);
        printf("Ingrese titulo de pelicula\n");
        fflush(stdin);
        gets(peliculas[i].titulo);
        printf("\nIngrese Dia de pelicula\n");
        fflush(stdin);
        scanf("%d", &peliculas[i].dia);
        printf("\nIngrese Mes de pelicula\n");
        fflush(stdin);
        scanf("%d", &peliculas[i].mes);
        printf("\nIngrese Anio de pelicula\n");
        fflush(stdin);
        scanf("%d", &peliculas[i].anio);
        fflush(stdin);
        peliculas[i].idGenero=elegirGenero(generos, 5);
        peliculas[i].idActor=elegirActor(actores,50);
        peliculas[i].estado = OCUPADO;
        //una funciones q busque si ese id existe devuelva un -1 si esta y el lugar sino
        peliculas[i].id=sumar(i);
        printf("Su id es %d\n",peliculas[i].id);
        system("pause");
        system("cls");
    }
    else
    {
        printf("No hay espacio\n");
        system("pause");
        system("cls");
    }
}

int buscarLibre( ePeliculas x[], int tam)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {

        if( x[i].estado==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int elegirGenero(eGenero generos[], int tam)
{
    int idGenero;
    printf("\nGeneros\n\n");
    int i;
    for(i=0; i < tam; i++)
    {
        printf("%d %s\n", generos[i].idGenero, generos[i].descripcion);
    }
    printf("\nSeleccione genero: ");
    fflush(stdin);
    scanf("%d", &idGenero);

    return idGenero;
}

int elegirActor(eActores actores[], int tam)
{
    int idActor;
    printf("\nActores\n\n");
    int i;
    for(i=0; i < tam; i++)
    {
        if(actores[i].estado!=0)
        printf("%d     %s\n", actores[i].idActor, actores[i].nombre);
    }
    printf("\nSeleccione actor: ");
    scanf("%d", &idActor);

    return idActor;
}

void borrarPelicula(ePeliculas peliculas[], int tam, int id)
{
        int i;
        int loEncontro = 0;
        char respuesta;
        printf("Ingrese ID de pelicula: ");
        scanf("%d", &id);

        for(i=0; i<tam; i++)
        {
            if(id == peliculas[i].id)
            {
                printf("Desea realmente borrar la pelicula? s/n \n");
                fflush(stdin);
                scanf("%c",&respuesta);
                if(respuesta=='s')
                {
                    peliculas[i].estado=LIBRE;
                    loEncontro = 1;
                    printf("La pelicula se elimino con exito\n");

                }
                loEncontro=1;
                system("pause");
                 system("cls");
                break;
            }
        }



    if(loEncontro==0)
    {
        printf("El id no existe\n");
        system("pause");
        system("cls");

    }

}



void modificarPelicula(ePeliculas peliculas[], int tam, int id,eGenero generos[],eActores actores[],int ta)
{
    int indice;
    int opcion;
    int flag=0;
    printf("Ingrese ID: ");
    scanf("%d", &id);
    indice = buscarPelicula(peliculas, tam, id);
    if( indice == -1)
    {
        printf("No hay ninguna pelicula con el id %d\n",id);
        system("pause");
        system("cls");

    }
    else
    {
        system("cls");
        printf("----------------------------------------------------------------------------------\n");
        printf(" ID\t\t TITULO\t\t DIA\tMES  ANIO     GENERO\t     ACTOR \n");
        printf("----------------------------------------------------------------------------------\n\n");
        mostrarPelicula(peliculas[indice],tam,generos,5,actores,ta);
        do{

        printf("Que desea modificar?\n1-Titulo\n2-Actor\n3-Fecha de estreno\n");
         scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                printf("Ingrese nuevo titulo: \n");
                scanf("%s",peliculas[indice].titulo);
                flag=1;
                break;

            case 2:
                printf("Ingrese nuevo actor: \n");
                peliculas[indice].idActor=elegirActor(actores,10);
                flag=1;
                break;

            case 3:
                printf("Ingrese dia de estreno: \n");
                scanf("%d",&peliculas[indice].dia);
                printf("\nIngrese mes de estreno: \n");
                scanf("%d",&peliculas[indice].mes);
                printf("\nIngrese anio de estreno: \n");
                scanf("%d",&peliculas[indice].anio);
                flag=1;
                break;
            default:
                printf("Opcion invalida\n");
                break;
            }
            }while(flag!=1);

             system("pause");
            system("cls");

        }

}



int buscarPelicula(ePeliculas x[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {


        if( x[i].id == id && x[i].estado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarPelicula(ePeliculas pelicula,int tp,eGenero generos[],int tg,eActores actores[],int ta)
{
    char descripcion[20];
    char descripcion2[20];
    cargarDescripcionGenero(generos,tg,pelicula.idGenero, descripcion);
    cargarDescripcionActor(actores,ta,pelicula.idActor, descripcion2);

    printf("%5d %25s %5d %5d %5d %10s %20s \n\n", pelicula.id,pelicula.titulo, pelicula.dia,pelicula.mes,pelicula.anio,descripcion,descripcion2);

}


void cargarDescripcionGenero(eGenero generos[], int tg, int idGenero, char cadena[])
{

     int i;
    for(i=0; i < tg; i++)
    {
        if( generos[i].idGenero == idGenero)
        {

            strcpy(cadena, generos[i].descripcion);
            break;
        }
    }


}
void cargarDescripcionActor(eActores actores[], int ta, int idActor, char cadena[])
{

 int i;
    for(i=0; i < ta; i++)
    {
        if( actores[i].idActor == idActor)
        {

            strcpy(cadena, actores[i].nombre);
            break;
        }
    }


}

void ordenarPeliculasPorAnio(ePeliculas peliculas[], int tam)
{
    ePeliculas aux;
    int i;
    int j;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(peliculas[i].estado==1&&peliculas[j].estado==1){
            if(peliculas[i].anio>peliculas[j].anio)
            {
                aux = peliculas[i];
                peliculas[i] = peliculas[j];
                peliculas[j] = aux;

            }
            }
        }
    }


}


void mostrarPeliculas(ePeliculas peliculas[], int tp,eGenero generos[], int tg,eActores actores[],int ta)
{
    system("cls");
    printf("----------------------------------------------------------------------------------\n");
    printf(" ID\t\t TITULO\t\t DIA\tMES  ANIO     GENERO\t     ACTOR \n");
    printf("----------------------------------------------------------------------------------\n\n");
    int i;
    for( i=0; i< tp; i++)
    {
        if( peliculas[i].estado == 1)
        {
            mostrarPelicula(peliculas[i],tp,generos,5,actores,ta);
        }
    }
    system("pause");
    system("cls");

}


int sumar(int numero){
int suma;
suma=numero+1000;


return suma;
}


void ordenarActoresPorPais(eActores actores[], int ta)
{
    eActores aux;
    int i;
    int j;
    for(i=0; i<ta-1; i++)
    {
        for(j=i+1; j<ta; j++)
        {
            if(stricmp(actores[i].pais,actores[j].pais)>0)
            {
                aux = actores[i];
                actores[i] = actores[j];
                actores[j] = aux;

            }
        }
    }


}

void mostrarActores(eActores actores[], int ta)
{
    system("cls");
    printf("----------------------------------------------------------------------------------\n");
    printf("---------------------------ACTORES ORDENADOS POR PAIS----------------------------\n");
    printf(" ID          NOMBRE           PAIS\n");
    printf("----------------------------------------------------------------------------------\n\n");
    int i;
    for(i=0; i< ta; i++)
    {
        if( actores[i].estado == 1)
        {
            mostrarActor(actores[i],ta);
        }
    }
    system("pause");
    system("cls");

}
/*
void mostrarActores(eActores actores[], int ta)
{
    system("cls");
    printf("----------------------------------------------------------------------------------\n");
    printf("---------------------------ACTORES ORDENADOS POR PAIS----------------------------\n");
    printf(" ID          NOMBRE           PAIS\n");
    printf("----------------------------------------------------------------------------------\n\n");
    int i;
    for(i=0; i< ta; i++)
    {
        if( actores[i].estado == 1)
        {
            mostrarActor(actores[i],ta);
        }
    }
    system("pause");
    system("cls");

}
*/
void mostrarActor(eActores actores,int ta)
{
    printf("%5d %20s %10s \n\n", actores.idActor,actores.nombre,actores.pais);

}


void mostrarPeliculasActorGenero(ePeliculas peliculas[], int tp,eGenero generos[], int tg,eActores actores[],int ta)
{
    system("cls");
    printf("----------------------------------------------------------------------------------\n");
    printf("                   TITULO     GENERO\t  ACTOR \n");
    printf("----------------------------------------------------------------------------------\n\n");
    int i;
    for( i=0; i< tp; i++)
    {
        if( peliculas[i].estado == 1)
        {
            mostrarPeliculaGeneroActor(peliculas[i],tp,generos,5,actores,ta);
        }
    }
    system("pause");
    system("cls");

}


void mostrarPeliculaGeneroActor(ePeliculas pelicula,int tp,eGenero generos[],int tg,eActores actores[],int ta)
{
    char descripcion[20];
    char descripcion2[20];
    cargarDescripcionGenero(generos,tg,pelicula.idGenero, descripcion);
    cargarDescripcionActor(actores,ta,pelicula.idActor, descripcion2);

    printf("%25s %10s %20s \n\n",pelicula.titulo,descripcion,descripcion2);

}

void mostrarPeliculasNacionalidadActorEEUU(ePeliculas peliculas[], int tp,eGenero generos[], int tg,eActores actores[],int ta)
{

    int respuesta;
    system("cls");
    printf("----------------------------------------------------------------------------------\n");
    printf(" PELICULAS CUYA NACIONALIDAD DE ACTOR ES EEUU");
    printf("----------------------------------------------------------------------------------\n\n");
    int i;
    int auxiliar;
    for( i=0; i< tp; i++)
    {

        auxiliar=peliculas[i].idActor;//esto guarda el id del actor osea su numero
        respuesta=siactoreeuu(actores,ta,auxiliar);

        if(respuesta==1&&peliculas[i].estado==1)
        {
            mostrarPeliculaEEUU(peliculas[i]);
        }


    }
    system("pause");
    system("cls");

}
void mostrarPeliculaEEUU(ePeliculas pelicula)
{
    printf("%20s\n\n",pelicula.titulo);

}

int siactoreeuu(eActores x[], int tam, int numeroactor)
{

    int indice = -1;
    int i;
    for(i=0;i<tam;i++){

    if(x[i].idActor==numeroactor)
        {
         if(strcmp(x[i].pais,"EEUU")==0)
        indice=1;
        break;
        }
    }
    return indice;
}


void mostrarGeneroPeliculas(ePeliculas peliculas[], int tp,eGenero generos[], int tg,eActores actores[],int ta)
{
    system("cls");
    printf("----------------------------------------------------------------------------------\n");
    printf(" ID\t\t TITULO\t\t DIA\tMES  ANIO     GENERO\t     ACTOR \n");
    printf("----------------------------------------------------------------------------------\n\n");
    int i;
    for( i=0; i< tp; i++)
    {
        if( peliculas[i].estado == 1)
        {
            mostrarPelicula(peliculas[i],tp,generos,5,actores,ta);
        }
    }
    system("pause");
    system("cls");

}

void listarPeliculasXGenero(ePeliculas x[],int tam, eGenero generos[], int tg)
{
    int idGenero;
    char descripcion[20];
    int flag = 0;

    idGenero = elegirGenero2(generos,tg);

    cargarDescripcionGenero(generos,tg,idGenero,descripcion);

    system("cls");
    printf("Peliculas del genero %s\n\n", descripcion);
    int i;
    for(i=0; i< tam; i++)
    {
        if(x[i].estado == 1 && x[i].idGenero == idGenero)
        {
            mostrarPeliculaConGenero(x[i]);
            flag = 1;

        }
    }


    if(flag == 0)
    {
        printf("No hay peliculas que mostrar\n\n");
    }
    system("pause");
    system("cls");

}
int elegirGenero2(eGenero generos[], int tam)
{
    int idGenero;
    printf("\nGeneros\n\n");
    int i;
    for(i=0; i < tam; i++)
    {
        printf("%d %s\n", generos[i].idGenero, generos[i].descripcion);
    }
    printf("\nSeleccione genero: ");
    scanf("%d", &idGenero);

    return idGenero;
}

void mostrarPeliculaConGenero(ePeliculas pelicula)
{
    printf("%25s \n\n",pelicula.titulo);

}

void listarPeliculasXcantidadGenero(ePeliculas x[],int tam, eGenero generos[], int tg)
{

    int idGenero;
    char descripcion[20];
    int flag = 0;

    idGenero = elegirGenero2(generos,tg);

    cargarDescripcionGenero(generos,tg,idGenero,descripcion);

    system("cls");
    printf("Cantidad de peliculas de %s\n\n", descripcion);
    int i;
    int contador=0;
    for(i=0; i< tam; i++)
    {
        if(x[i].estado == 1 && x[i].idGenero == idGenero)
        {
            contador++;
            flag = 1;

        }
    }
    printf("La cantidad de peliculas en el genero %s es %d\n",descripcion,contador);

    if(flag == 0)
    {
        printf("No hay peliculas que mostrar\n\n");
    }
    system("pause");
    system("cls");


}


















