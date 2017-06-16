#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "jugadores.h"
#include "ArrayList.h"

eJugador* newJugador()
{
    eJugador* newJugador;

    newJugador=(eJugador*)malloc(sizeof(eJugador));

    if(newJugador==NULL)
    {
        printf("NULL");

        exit(0);
    }

    return newJugador;
}

void printNombreJugador(eJugador* jugador)
{
    printf("%s %s\n",jugador->apellido,jugador->nombre);
}

void printFullJugador(eJugador* jugador)
{
    printf("Apellido: %s\nNombre: %s\nEdad: %d\nDorsal: %d\nPosicion: %s\n",jugador->apellido,jugador->nombre,jugador->edad,jugador->dorsal,jugador->posicion);
}

int ordenarPorDorsal(void* jugador1,void* jugador2)
{
    jugador1=(eJugador*)jugador1;
    jugador2=(eJugador*)jugador2;

    if(getDorsalJugador(jugador1)<getDorsalJugador(jugador2))
    {
        return 1;
    }
    else if(getDorsalJugador(jugador1)>getDorsalJugador(jugador2))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int ordenarPorApellido(void* jugador1,void* jugador2)
{
    jugador1=(eJugador*)jugador1;
    jugador2=(eJugador*)jugador2;

    return strcmp(getApellidoJugador(jugador1),getApellidoJugador(jugador2));
}

int ordenarPorEdad(void* jugador1,void* jugador2)
{
    jugador1=(eJugador*)jugador1;
    jugador2=(eJugador*)jugador2;

    if(getEdadJugador(jugador1)<getEdadJugador(jugador2))
    {
        return 1;
    }
    else if(getEdadJugador(jugador1)>getEdadJugador(jugador2))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void mostrarJugadoresConIndice(ArrayList* arrayJugadores)
{
    int tam,i;
    eJugador* jugador;

    tam=arrayJugadores->len(arrayJugadores);

    for(i=0; i<tam; i++)
    {
        jugador=arrayJugadores->get(arrayJugadores,i);
        if(jugador==NULL)
        {
            printf("NULL");
        }
        printf("Indice: %d|  ",i);
        printNombreJugador(jugador);
    }
}

void mostrarJugadores(ArrayList* arrayJugadores)
{
    int tam,i;
    eJugador* jugador;

    tam=arrayJugadores->len(arrayJugadores);

    for(i=0; i<tam; i++)
    {
        jugador=arrayJugadores->get(arrayJugadores,i);
        if(jugador==NULL)
        {
            printf("NULL");
        }
        printNombreJugador(jugador);
    }
}

void mostrarJugadoresFull(ArrayList* arrayJugadores)
{
    int tam,i;
    eJugador* jugador;

    tam=arrayJugadores->len(arrayJugadores);

    for(i=0; i<tam; i++)
    {
        jugador=arrayJugadores->get(arrayJugadores,i);
        if(jugador==NULL)
        {
            printf("NULL");
        }
        printFullJugador(jugador);
        printf("\n\n");
    }
}

int altaJugador(ArrayList* arrayJugadoresRes)
{
    char nombre[50],apellido[50],posicion[20],pregunta;
    int edad,auxLen,i,auxDorsal,returnAux=-1;
    ArrayList* auxArrayJugadores;
    eJugador* jugador;

    system("cls");
    printf("Ingrese el nombre del jugador: ");
    fflush(stdin);
    gets(nombre);
    nombre[0]=toupper(nombre[0]);
    auxLen=strlen(nombre);

    for(i=0; i<auxLen; i++)
    {
        if(nombre[i]==' ')
        {
            nombre[i+1]=toupper(nombre[i+1]);
        }
    }

    system("cls");
    printf("Ingrese el apellido: ");
    fflush(stdin);
    gets(apellido);
    auxLen=strlen(apellido);
    apellido[0]=toupper(apellido[0]);

    for(i=0; i<auxLen; i++)
    {
        if(apellido[i]==' ')
        {
            apellido[i+1]=toupper(apellido[i+1]);
        }
    }

    system("cls");
    printf("Ingrese la edad: ");
    scanf("%d",&edad);

    while(edad<18 || edad>35)
    {
        printf("Error. Reingrese la edad(entre 18 y 35): ");
        scanf("%d",&edad);
    }

    system("cls");
    printf("Ingrese la posicion(GK|DF|MD|AT): ");
    fflush(stdin);
    gets(posicion);
    strupr(posicion);

    system("cls");
    printf("\nNombre: %s %s| Edad: %d| Posicion: %s",nombre,apellido,edad,posicion);

    printf("\nEsta seguro que desea agregar a este jugador(s/n): ");
    pregunta=getche();



    if(pregunta=='s')
    {

        auxArrayJugadores=arrayJugadoresRes->clone(arrayJugadoresRes);


        auxArrayJugadores->sort(auxArrayJugadores,ordenarPorDorsal,1);



        jugador=auxArrayJugadores->get(auxArrayJugadores,0);

        auxDorsal=getDorsalJugador(jugador);
        auxDorsal++;

        jugador=(eJugador*)malloc(sizeof(eJugador));

        setNameJugador(jugador,nombre);
        setApellidoJugador(jugador,apellido);
        setEdadJugador(jugador,edad);
        setPosicionJugador(jugador,posicion);
        setDorsalJugador(jugador,auxDorsal);

        arrayJugadoresRes->add(arrayJugadoresRes,jugador);

        returnAux=0;


    }

    return returnAux;
}

int cambiarTitular(ArrayList* jugadoresTitulares,ArrayList* jugadoresSuplentes)
{
    int indiceTit,indiceSup,returnAux=-1;
    eJugador* newSuplente;
    eJugador* newTitular;
    eJugador* elNuevo;

    system("cls");
    mostrarJugadoresConIndice(jugadoresTitulares);

    printf("\nIngrese el Indice del Titular que sale: ");
    scanf("%d",&indiceTit);

    newSuplente=(eJugador*)jugadoresTitulares->get(jugadoresTitulares,indiceTit);

    if(newSuplente!=NULL)
    {

        system("cls");
        mostrarJugadoresConIndice(jugadoresSuplentes);

        printf("\nIngrese el Indice del Suplente que entra: ");
        scanf("%d",&indiceSup);

        newTitular=(eJugador*)jugadoresSuplentes->get(jugadoresSuplentes,indiceSup);

        if(newTitular!=NULL)
        {
            jugadoresTitulares->remove(jugadoresTitulares,indiceTit);
            jugadoresTitulares->push(jugadoresTitulares,indiceTit,newTitular);

            elNuevo=jugadoresSuplentes->pop(jugadoresSuplentes,indiceSup);
            jugadoresSuplentes->push(jugadoresSuplentes,indiceSup,newSuplente);

            system("cls");
            printf("Felicitaciones por haber subido a los titulares a ");
            printNombreJugador(elNuevo);
            printf("\n");

            returnAux=0;
        }


    }

    return returnAux;


}

int cambiarSuplente(ArrayList* jugadoresSuplentes,ArrayList* jugadoresReserva)
{
    int indiceSup,indiceRes,returnAux=-1;
    eJugador* newReserva;
    eJugador* newSuplente;

    system("cls");
    mostrarJugadoresConIndice(jugadoresSuplentes);

    printf("\nIngrese el Indice del Suplente que sale: ");
    scanf("%d",&indiceSup);

    newReserva=(eJugador*)jugadoresSuplentes->get(jugadoresSuplentes,indiceSup);

    if(newReserva!=NULL)
    {

        system("cls");
        mostrarJugadoresConIndice(jugadoresReserva);

        printf("\nIngrese el Indice del Reserva que entra: ");
        scanf("%d",&indiceRes);

        newSuplente=(eJugador*)jugadoresReserva->get(jugadoresReserva,indiceRes);

        if(newSuplente!=NULL)
        {
            jugadoresSuplentes->set(jugadoresSuplentes,indiceSup,newSuplente);

            jugadoresReserva->set(jugadoresReserva,indiceRes,newReserva);

            returnAux=0;
        }


    }

    system("cls");
    return returnAux;


}

void mostrarTodosLosJugadores(ArrayList* jugadoresTitulares,ArrayList* jugadoresSuplentes,ArrayList* jugadoresReserva)
{
    system("cls");
    printf("\nTitulares: \n\n");
    mostrarJugadores(jugadoresTitulares);
    printf("\n\nSuplentes: \n\n");
    mostrarJugadores(jugadoresSuplentes);
    printf("\n\nReserva: \n\n");
    mostrarJugadores(jugadoresReserva);
}

ArrayList* generarListaTodos(ArrayList* jugadoresTitulares,ArrayList* jugadoresSuplentes,ArrayList* jugadoresReserva)
{
    int tam,i;
    ArrayList* auxListJugadores=NULL;
    eJugador* jugador;

    auxListJugadores=jugadoresTitulares->clone(jugadoresTitulares);

    if(auxListJugadores!=NULL)
    {
        tam=jugadoresSuplentes->len(jugadoresSuplentes);

        for(i=0; i<tam; i++)
        {
            jugador=(eJugador*)jugadoresSuplentes->get(jugadoresSuplentes,i);
            auxListJugadores->add(auxListJugadores,jugador);
        }

        tam=jugadoresReserva->len(jugadoresReserva);

        for(i=0; i<tam; i++)
        {
            jugador=(eJugador*)jugadoresReserva->get(jugadoresReserva,i);
            auxListJugadores->add(auxListJugadores,jugador);
        }
    }

    return auxListJugadores;


}

int mostrarDatosJugador(ArrayList* jugadoresTitulares,ArrayList* jugadoresSuplentes,ArrayList* jugadoresReserva)
{
    int indice,returnAux=-1;
    ArrayList* auxListJugadores;
    eJugador* jugador;

    auxListJugadores=generarListaTodos(jugadoresTitulares,jugadoresSuplentes,jugadoresReserva);

    if(auxListJugadores!=NULL)
    {
        system("cls");
        auxListJugadores->sort(auxListJugadores,ordenarPorApellido,1);
        mostrarJugadoresConIndice(auxListJugadores);

        printf("\nIngrese el Indice del jugador que desea ver los datos: ");
        scanf("%d",&indice);

        jugador=auxListJugadores->get(auxListJugadores,indice);

        if(jugadoresTitulares->contains(jugadoresTitulares,jugador)==1)
        {
            system("cls");
            indice=jugadoresTitulares->indexOf(jugadoresTitulares,jugador);
            printf("\nEsta en la posicion %d de los Titulares\n",indice);
            printFullJugador(jugador);
            returnAux=0;
        }
        else if(jugadoresSuplentes->contains(jugadoresSuplentes,jugador)==1)
        {
            system("cls");
            indice=jugadoresSuplentes->indexOf(jugadoresSuplentes,jugador);
            printf("\nEsta en la posicion %d de los Suplentes\n",indice);
            printFullJugador(jugador);
            returnAux=0;
        }
        else if(jugadoresReserva->contains(jugadoresReserva,jugador)==1)
        {
            system("cls");
            indice=jugadoresReserva->indexOf(jugadoresReserva,jugador);
            printf("\nEsta en la posicion %d de los Reserva\n",indice);
            printFullJugador(jugador);
            returnAux=0;
        }

        free(auxListJugadores);

    }

    return returnAux;

}

void mostrarLosMasJovenes(ArrayList* jugadoresTitulares,ArrayList* jugadoresSuplentes,ArrayList* jugadoresReserva)
{
    ArrayList* auxListJugadores;
    ArrayList* auxJugadoresJovenes;

    auxListJugadores=generarListaTodos(jugadoresTitulares,jugadoresSuplentes,jugadoresReserva);

    auxListJugadores->sort(auxListJugadores,ordenarPorEdad,0);

    auxJugadoresJovenes=auxListJugadores->subList(auxListJugadores,0,11);

    system("cls");
    mostrarJugadoresFull(auxJugadoresJovenes);

}

int borrarTodosReserva(ArrayList* jugadoresReserva)
{
    int returnAux;

    system("cls");
    returnAux=jugadoresReserva->clear(jugadoresReserva);

    return returnAux;
}

int setNameJugador(eJugador* this, char* nombre)
{
    int retorno=-1;

    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }

    return retorno;
}


int setApellidoJugador(eJugador* this, char* apellido)
{
    int retorno=-1;

    if(this!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }

    return retorno;
}

int setDorsalJugador(eJugador* this, int dorsal)
{
    int retorno=-1;

    if(this!=NULL)
    {
        this->dorsal=dorsal;
        retorno=0;
    }

    return retorno;
}

int setEdadJugador(eJugador* this, int edad)
{
    int retorno=-1;

    if(this!=NULL)
    {
        this->edad=edad;
        retorno=0;
    }

    return retorno;
}

int setPosicionJugador(eJugador* this, char* posicion)
{
    int retorno=-1;

    if(this!=NULL)
    {
        strcpy(this->posicion,posicion);
        retorno=0;
    }

    return retorno;
}

int getDorsalJugador(eJugador* this)
{
    return this->dorsal;
}

char* getNameJugador(eJugador* this)
{
    return this->nombre;
}

char* getApellidoJugador(eJugador* this)
{
    return this->apellido;
}

int getEdadJugador(eJugador* this)
{
    return this->edad;
}

char* getPosicionJugador(eJugador* this)
{
    return this->posicion;
}
