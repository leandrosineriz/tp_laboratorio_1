#include "ArrayList.h"

typedef struct{

    char nombre[50];
    char apellido[50];
    int dorsal;
    int edad;
    char posicion[20];

}eJugador;



/** \brief Reserva espacio en memoria para un puntero eJugador
 *
 * \return La posicion en memoria reservada
 *
 */

eJugador* newJugador();

/** \brief Modifica el nombre de un puntero eJugador
 *
 * \param puntero eJugador
 * \param nuevo nombre
 * \return 0 si pudo 1 si no pudo
 *
 */

int setNameJugador(eJugador*,char* nombre);

/** \brief Modifica el apellido de un puntero eJugador
 *
 * \param puntero eJugador
 * \param nuevo apellido
 * \return 0 si pudo 1 si no pudo
 *
 */
int setApellidoJugador(eJugador*, char* apellido);

/** \brief Modifica el dorsal de un puntero eJugador
 *
 * \param puntero eJugador
 * \param nuevo dorsal
 * \return 0 si pudo 1 si no pudo
 *
 */
int setDorsalJugador(eJugador*, int dorsal);

/** \brief Modifica la edad de un puntero eJugador
 *
 * \param puntero eJugador
 * \param nueva edad
 * \return 0 si pudo 1 si no pudo
 *
 */
int setEdadJugador(eJugador* this, int edad);

/** \brief Modifica la posicion de un puntero eJugador
 *
 * \param puntero eJugador
 * \param nueva posicion
 * \return 0 si pudo 1 si no pudo
 *
 */
int setPosicionJugador(eJugador* this, char* posicion);

/** \brief Retorna el nombre de un puntero eJugador
 *
 * \param puntero eJugador
 * \return el nombre
 *
 */
char* getNameJugador(eJugador* this);

/** \brief Retorna el apellido de un puntero eJugador
 *
 * \param puntero eJugador
 * \return el apellido
 *
 */
char* getApellidoJugador(eJugador* this);

/** \brief Retorna la posicion de un puntero eJugador
 *
 * \param puntero eJugador
 * \return la posicion
 *
 */
char* getPosicionJugador(eJugador* this);

/** \brief Retorna la edad de un puntero eJugador
 *
 * \param puntero eJugador
 * \return la edad
 *
 */
int getEdadJugador(eJugador* this);

/** \brief Retorna el Dorsal de un puntero eJugador
 *
 * \param puntero eJugador
 * \return la edad
 *
 */
int getDorsalJugador(eJugador* this);

/** \brief Muestra el nombre y apellido de los jugadores
 *
 * \param puntero a ArrayList de eJugadores
 *
 */

void mostrarJugadores(ArrayList* arrayJugadores);

/** \brief Muestra todos los datos de los jugadores
 *
 * \param puntero a ArrayList de eJugadores
 *
 */

void mostrarJugadoresFull(ArrayList* arrayJugadores);

/** \brief Muestra en consola el nombre y apellido del jugador
 *
 * \param puntero a un jugador eJugador
 *
 */

void printNombreJugador(eJugador* jugador);

/** \brief Muestra en consola todos los datos del jugador
 *
 * \param puntero a un jugador eJugador
 *
 */
void printFullJugador(eJugador* jugador);

/** \brief Compara y devuelve un numero en base al dorsal
 *
 * \param elemento de ArrayList
 * \param otro elemento de ArrayList
 * \return 0 si son iguales, 1 si el primero es mas grande -1 si es mas chico
 *
 */

int ordenarPorDorsal(void* jugador1,void* jugador2);

/** \brief Compara y devuelve un numero en base al apellido
 *
 * \param elemento de ArrayList
 * \param otro elemento de ArrayList
 * \return 0 si son iguales, 1 si el primero es mas grande -1 si es mas chico
 *
 */
int ordenarPorApellido(void* jugador1,void* jugador2);

/** \brief Compara y devuelve un numero en base a la edad
 *
 * \param elemento de ArrayList
 * \param otro elemento de ArrayList
 * \return 0 si son iguales, 1 si el primero es mas grande -1 si es mas chico
 *
 */
int ordenarPorEdad(void* jugador1,void* jugador2);

/** \brief Pide los datos y crea un nuevo jugador con un dorsal generado automaticamente que se guarda en los jugadores de reserva
 *
 * \param puntero a ArrayList de eJugadores reserva
 *
 */

int altaJugador(ArrayList* arrayJugadoresRes);

/** \brief Cambia un jugador entre el array de los titulares y el array de los suplentes
 *         (este usa las funciones remove pop y push del ArrayList)
 * \param puntero a ArrayList de eJugador titulares
 * \param otro puntero a ArrayList de eJugador suplentes
 * \return 0 si pudo cambiar 1 si no encontro algun jugador
 *
 */

int cambiarTitular(ArrayList* jugadoresTitulares,ArrayList* jugadoresSuplentes);


/** \brief Cambia un jugador entre el array de los suplentes y el array de los reserva
 *         (este usa la funcion set del ArrayList)
 * \param puntero a ArrayList de eJugador suplentes
 * \param otro puntero a ArrayList de eJugador reserva
 * \return 0 si pudo cambiar 1 si no encontro algun jugador
 *
 */

int cambiarSuplente(ArrayList* jugadoresSuplentes,ArrayList* jugadoresReserva);

/** \brief Muestra todos los jugadores divididos por titulares, suplentes y reserva
 *
 * \param puntero a ArrayList de eJugador de titulares
 * \param otro puntero a ArrayList de eJugador de suplentes
 * \param otro puntero a ArrayList de eJugador de reserva
 *
 */

void mostrarTodosLosJugadores(ArrayList* jugadoresTitulares,ArrayList* jugadoresSuplentes,ArrayList* jugadoresReserva);

/** \brief Muestra los jugadores del ArrayList con su indice
 *
 * \param otro puntero a ArrayList de eJugador
 *
 */

void mostrarJugadoresConIndice(ArrayList* arrayJugadores);

/** \brief Muestra la lista entera de jugadores ordenados por nombre y luego busca el jugador elegido por indice
 *         dentro de los arrays y muestra todos sus datos
 * \param puntero a ArrayList de eJugador de titulares
 * \param otro puntero a ArrayList de eJugador de suplentes
 * \param otro puntero a ArrayList de eJugador de reserva
 *
 */

int mostrarDatosJugador(ArrayList* jugadoresTitulares,ArrayList* jugadoresSuplentes,ArrayList* jugadoresReserva);

/** \brief Borra todos los jugadores en el ArrayList
 *
 * \param puntero a ArrayList de eJugador de reserva
 * \return 0 si pudo -1 si error
 *
 */

int borrarTodosReserva(ArrayList* jugadoresReserva);

/** \brief toma todos los elmentos en los 3 ArrayList y los guarda en un solo nuevo array
 *
 * \param puntero a ArrayList de eJugador de titulares
 * \param otro puntero a ArrayList de eJugador de suplentes
 * \param otro puntero a ArrayList de eJugador de reserva
 * \return un nuevo ArrayList con todos los jugadores
 *
 */

ArrayList* generarListaTodos(ArrayList* jugadoresTitulares,ArrayList* jugadoresSuplentes,ArrayList* jugadoresReserva);

/** \brief Muestra de entre todos los jugadores en los 3 ArrayList los 11 mas jovenes
 *
 * \param puntero a ArrayList de eJugador de titulares
 * \param otro puntero a ArrayList de eJugador de suplentes
 * \param otro puntero a ArrayList de eJugador de reserva
 *
 */

void mostrarLosMasJovenes(ArrayList* jugadoresTitulares,ArrayList* jugadoresSuplentes,ArrayList* jugadoresReserva);






