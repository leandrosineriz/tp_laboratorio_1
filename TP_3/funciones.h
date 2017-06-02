#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct{
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[2000];
    int puntaje;
    char linkImagen[500];
    int estado;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario.
 *  @param puntero a estructura EMovie.
 *  @param tamaño del puntero.
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no.
 */
int agregarPelicula(EMovie*,int);

/**
 *  Borra una pelicula del archivo binario.
 *  @param puntero a estructura EMovie.
 *  @param tamaño del puntero.
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no.
 */
int borrarPelicula(EMovie* movie,int);

/** \brief Modifica una pelicula del archibo binario
 *
 * \param puntero a estructura EMovie.
 * \param tamaño del puntero.
 * \return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no.
 *
 */

int modificarPelicula(EMovie* movie,int);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param puntero a estructura EMovie.
 *  @param nombre el nombre para el archivo.
 *  @param tamaño del puntero.
 */
void generarPagina(EMovie* movie, char [],int);

#endif // FUNCIONES_H_INCLUDED

/** \brief Constructor eMovie, reserva espacio en memoria segun el tamaño pasado por parametro
 *
 * \param puntero a estructura EMovie.
 * \param tamaño del puntero.
 * \return retorna la direccion de memoria de la estructura.
 *
 */

EMovie* newMovie(EMovie* movie,int );

/** \brief Inicia los estados en 0 del puntero EMovie y guarda los datos leidos del archivo binario.
 *
 * \param puntero a estructura EMovie.
 * \param tamaño del puntero.
 *
 */

void setMovies(EMovie* movie,int);

/** \brief Muestra en consola el index, titulo y genero de las peliculas con estado 1.
 *
 * \param puntero a estructura EMovie.
 * \param tamaño del puntero.
 *
 */

void printMovies(EMovie* movie, int tam);

/** \brief Imprime en el archivo binario los datos de las peliculas que tienen estado 1.
 *
 * \param puntero a estructura EMovie.
 * \param tamaño del puntero.
 * \param puntero a archivo donde se va a imprimir.
 *
 */

void fprintMovies(EMovie* movie, int tam,FILE* bin);

/** \brief Busca el primer estado 0 dentro del puntero.
 *
 * \param puntero a estructura EMovie.
 * \param tamaño del puntero.
 * \return retorna la posicion del primer elemento con estado 0 o -1 de acuerdo a si encontro espacio libre o no.
 *
 */

int buscarLibre(EMovie* movie,int tam);
