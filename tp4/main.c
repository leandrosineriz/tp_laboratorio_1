#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "jugadores.h"
#include "ArrayList.h"

int main()
{
    FILE* pFile;
    ArrayList* jugadoresTitulares=al_newArrayList();
    ArrayList* jugadoresSuplentes=al_newArrayList();
    ArrayList* jugadoresReserva=al_newArrayList();
    char seguir='s';
    int opcion,returnAux;

    if(jugadoresTitulares==NULL || jugadoresSuplentes==NULL || jugadoresReserva==NULL)
    {
        printf("NULL");
        exit(0);
    }

    parserJugadores(pFile,"jugadoresTitulares.txt",jugadoresTitulares);
    parserJugadores(pFile,"jugadoresSuplentes.txt",jugadoresSuplentes);
    parserJugadores(pFile,"jugadoresReserva.txt",jugadoresReserva);






    do
    {
        system("cls");
        printf("########    GESTION SELECCION ARGENTINA    ##########\n");
        printf("##                                             ######\n");
        printf("## 1.Agregar Jugador.                          ######\n");
        printf("## 2.Cambiar Titular.                          ######\n");
        printf("## 3.Cambiar Suplente.                         ######\n");
        printf("## 4.Mostrar Jugadores.                        ######\n");
        printf("## 5.Mostrar Todos los datos de un Jugador.    ######\n");
        printf("## 6.Borrar todos los Reserva.                 ######\n");
        printf("## 7.Mostrar los 11 Jugadores mas jovenes.     ######\n");
        printf("## 8.Salir.                                    ######\n");
        printf("##                                             ######\n");
        printf("#####################################################\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            returnAux=altaJugador(jugadoresReserva);
            if(returnAux==0)
            {
                printf("\nJugador agregado correctamente.\n(Nota: el jugador se agrega en reserva.)\n");
            }
            else
            {
                printf("\nJugador NO agregado.\n");
            }
            break;
        case 2:
            returnAux=cambiarTitular(jugadoresTitulares,jugadoresSuplentes);
            if(returnAux==0)
            {
                printf("\nJugador cambiado correctamente.");

            }
            else
            {
                printf("\nNo se pudo cambiar al jugador.");
            }
            break;
        case 3:

            if(!jugadoresReserva->isEmpty(jugadoresReserva))
            {
                returnAux=cambiarSuplente(jugadoresSuplentes,jugadoresReserva);
                if(returnAux==0)
                {
                    printf("\nJugador cambiado correctamente.");

                }
                else
                {
                    printf("\nNo se pudo cambiar al jugador.");
                }
            }
            else
            {
                printf("\nNo hay jugadores en Reserva para cambiar\n");
            }

            break;
        case 4:
            mostrarTodosLosJugadores(jugadoresTitulares,jugadoresSuplentes,jugadoresReserva);
            break;
        case 5:
            returnAux=mostrarDatosJugador(jugadoresTitulares,jugadoresSuplentes,jugadoresReserva);
            if(returnAux==-1)
            {
                printf("\nError. No se encontro el jugador\n");
            }
            break;
        case 6:
            returnAux=borrarTodosReserva(jugadoresReserva);

            if(returnAux==0)
            {
                printf("\nSe borraron todos los Reserva exitosamente");
            }
            else
            {
                printf("\nError. No se pudieron eliminar los Reserva.");
            }
            break;
        case 7:
            mostrarLosMasJovenes(jugadoresTitulares,jugadoresSuplentes,jugadoresReserva);
            break;
        case 8:
            seguir='n';
            break;
        default:
            printf("\nOpcion Incorrecta.");
        }
        printf("\n\n");
        system("pause");
    }
    while(seguir=='s');

    printf("\n\n###### SISTEMA DE GESTION SELECCION ARGENTINA TP 4 by Leandro Si%ceriz  ######\n",164);

    return 0;
}
