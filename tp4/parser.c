#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugadores.h"
#include "parser.h"
#include "ArrayList.h"

void parserJugadores(FILE* pFile,char* archivo, ArrayList* arrayJugadores)
{

    char nombre[100],apellido[100],dorsal[100],edad[100],posicion[100];
    int returnAux;
    pFile=fopen(archivo,"r");

    if(pFile==NULL)
    {
        printf("NULL");
        exit(0);
    }



    while(!feof(pFile))
    {
        eJugador* jugador=newJugador();

       fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",dorsal,nombre,apellido,edad,posicion);


       setNameJugador(jugador,nombre);
       setApellidoJugador(jugador,apellido);
       setDorsalJugador(jugador,atoi(dorsal));
       setEdadJugador(jugador,atoi(edad));
       setPosicionJugador(jugador,posicion);

       returnAux=arrayJugadores->add(arrayJugadores,jugador);

       if(returnAux==-1)
       {
           printf("Error add parser");
       }

    }

    fclose(pFile);

}

