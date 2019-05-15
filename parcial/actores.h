
typedef struct
{
    int idActor;
    char nombre[20];
    char pais[20];
    int estado;
}eActores;


/** \brief inicialisa el estado de los arrays de todos los actores en 0 libre
 *
 * \param eActores[]
 * \param int
 * \return void
 *
 */
void inicializarActores(eActores[], int);

/** \brief copia datos a la estructura de actores
 *
 * \param eActores[]
 * \param int
 * \return void
 *
 */
void hardcodearDatosActores(eActores[], int);







