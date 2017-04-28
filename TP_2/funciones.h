#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tamaño del array
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona[],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param tamaño del array
 * @param el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona[],int,int);

#endif // FUNCIONES_H_INCLUDED

/** \brief inicializa el estado,dni y edad
 *
 * \param array ePersona
 * \param tamaño del array
 *
 */

void setLista(ePersona [],int);

/** \brief muestra el array sin ordenar
 *
 * \param array ePersona
 * \param tamaño del array
 *
 */

void mostrarLista(ePersona[],int);

/** \brief ordena el array por nombre
 *
 * \param array ePersona
 * \param tamaño del array
 *
 */

void OrdenarPorNombre(ePersona [] ,int);

/** \brief chequea que existan personas activas(estado 1)
 *
 * \param array ePersona
 * \param tamaño del array
 * \return 1 si encontro activos 0 si no hay personas registradas
 *
 */
int buscarEstadoActivoLista(ePersona[],int);

/** \brief agrega un nuevo usuario al array
 *
 * \param array ePersona
 * \param tamaño del array
 *
 */

void agregarPersona(ePersona[],int);

/** \brief elimina un usuario de la lista cambiando el estado
 *
 * \param array ePersona
 * \param tamaño del array
 *
 */

void borrarPersona(ePersona[],int);

/** \brief muestra un grafico de edades
 *
 * \param array ePersona
 * \param tamaño del array
 *
 */

void estadistica(ePersona[],int);

//void cargarPersonas(ePersona[]);

/** \brief valida que el char ingresado sea s/n
 *
 * \param char a validar
 * \return char validado
 *
 */

char validarSoN(char);

/** \brief valida que el dni sea de 8 digitos y que no exista otro igual en el array
 *
 * \param array ePersona
 * \param tamaño del array
 * \param posicion del dni dentro del array
 * \return
 *
 */

void validarDNI(ePersona lista[],int tam,int libre);
