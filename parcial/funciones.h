#define OCUPADO 1
#define LIBRE 0
#include "genero.h"
#include "actores.h"
typedef struct
{
    int id;
    char titulo[50];
    int idGenero;
    int idActor;
    int dia;
    int mes;
    int anio;
    int estado;
}ePeliculas;

/** \brief muestra el menu principal
 *
 * \return void
 *
 */
void menu();

/** \brief inicialisa el estado de todos los arrays de peliculas estructura en 0 libre
 *
 * \param ePeliculas[]
 * \param int
 * \return void
 *
 */
void inicializarPeliculas(ePeliculas[], int);
/** \brief copia datos a la estructura de peliculas
 *
 * \param
 * \param
 * \return
 *
 */

void hardcodearDatosPeliculas(ePeliculas[], int);

/** \brief recibe un texto y devuelve un numero
 *
 * \param char[]
 * \return int
 *
 */
int menuDeOpciones(char[]);

/** \brief carga una pelicula al la estructura de peliculas
 *
 * \param ePeliculas[]
 * \param int
 * \param eGenero[]
 * \param eActores[]
 * \return void
 *
 */
void cargarPeliculaAutomatico(ePeliculas[], int,eGenero[],eActores[]);
/** \brief busca un lugar linre en la estructura de peliculas y devuelve el numero del vector libre, caso contrario devuelve -1
 *
 * \param ePeliculas[]
 * \param int
 * \return int
 *
 */
int buscarLibre( ePeliculas[], int);

/** \brief lansa un menu que muestra la estructua de generos y devuelve un numero
 *
 * \param eGenero[]
 * \param int
 * \return int
 *
 */
int elegirGenero(eGenero[], int);

/** \brief lansa un menu que muestra la estructua de actores y devuelve un numero
 *
 * \param eActores[]
 * \param int
 * \return int
 *
 */
int elegirActor(eActores[], int);

/** \brief borra el estado de una pelicula
 *
 * \param ePeliculas[]
 * \param int
 * \param int
 * \return void
 *
 */
void borrarPelicula(ePeliculas[], int, int);

/** \brief permite modificar los datos de una pelicula genero actor y fecha
 *
 * \param ePeliculas[]
 * \param int
 * \param int
 * \param eGenero[]
 * \param eActores[]
 * \param int
 * \return void
 *
 */
void modificarPelicula(ePeliculas[],int,int,eGenero[],eActores[],int);

/** \brief busca una pelicula en base a su id y devuelve el numero de la estructura donde esta ubicada
 *
 * \param ePeliculas[]
 * \param int
 * \param int
 * \return int
 *
 */
int buscarPelicula(ePeliculas[], int, int);

/** \brief muestra todos los datos de una pelicula
 *
 * \param ePeliculas
 * \param int
 * \param eGenero[]
 * \param int
 * \param eActores[]
 * \param int
 * \return void
 *
 */
void mostrarPelicula(ePeliculas,int, eGenero[],int,eActores[],int);

/** \brief compara un id de genero y devuelve la descripcion al que pertenece
 *
 * \param
 * \param
 * \return
 *
 */

void cargarDescripcionGenero(eGenero[], int,int,char cadena[]);

/** \brief compara un id de actor y devuelve el nombre al que pertenece
 *
 * \param eActores[]
 * \param int
 * \param int
 * \param cadena[] char
 * \return void
 *
 */
void cargarDescripcionActor(eActores[], int,int,char cadena[]);


/** \brief ordena las peliculas en base al año
 *
 * \param ePeliculas[]
 * \param int
 * \return void
 *
 */
void ordenarPeliculasPorAnio(ePeliculas[], int);


/** \brief muestra todas las peliculas que se encuentra en la estructura de peliculas
 *
 * \param ePeliculas[]
 * \param int
 * \param eGenero[]
 * \param int
 * \param eActores[]
 * \param int
 * \return void
 *
 */
void mostrarPeliculas(ePeliculas[], int,eGenero[], int,eActores[],int);

int sumar(int);

/** \brief ordena la estructura de actores por pais
 *
 * \param eActores[]
 * \param int
 * \return void
 *
 */
void ordenarActoresPorPais(eActores[],int);

/** \brief muestra una lista de datos de actores
 *
 * \param eActores[]
 * \param int
 * \return void
 *
 */
void mostrarActores(eActores[], int);

/** \brief muestra los datos de un actor
 *
 * \param eActores
 * \param int
 * \return void
 *
 */
void mostrarActor(eActores,int);



void mostrarPeliculasActorGenero(ePeliculas[], int,eGenero[], int,eActores[],int);
void mostrarPeliculaGeneroActor(ePeliculas,int, eGenero[],int,eActores[],int);

void mostrarPeliculasNacionalidadActorEEUU(ePeliculas[], int,eGenero[], int,eActores[],int);

void mostrarPeliculaEEUU(ePeliculas);
int siactoreeuu(eActores[],int, int);

void mostrarGeneroPeliculas(ePeliculas[], int,eGenero[], int,eActores[],int);

void mostrarPeliculaConGenero(ePeliculas);
int elegirGenero2(eGenero generos[], int);

void listarPeliculasXGenero(ePeliculas[],int, eGenero[], int);

void listarPeliculasXcantidadGenero(ePeliculas[],int,eGenero[], int);

void listarGeneroMenosPelis(ePeliculas[],int, eGenero[], int);





