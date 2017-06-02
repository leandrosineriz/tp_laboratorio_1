#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 50

int main()
{
    char seguir='s';
    int opcion=0,estado;
    EMovie* movies;

    movies=newMovie(movies,TAM);

    if(movies==NULL)
    {
        printf("\nProblema al reservar espacio en memoria.");
        exit(0);
    }

    setMovies(movies,TAM);


    while(seguir=='s')
    {
        system("cls");
        printf("############ SISTEMA DE GESTION DE PELICULAS EN C #################\n");
        printf("## 1- Agregar pelicula                                           ##\n");
        printf("## 2- Borrar pelicula                                            ##\n");
        printf("## 3- Modificar pelicula                                         ##\n");
        printf("## 4- Generar pagina web                                         ##\n");
        printf("## 5- Salir                                                      ##\n");
        printf("###################################################################\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                estado=agregarPelicula(movies,TAM);

                if(estado==0)
                {
                    printf("\nNo se agrego la pelicula.");
                }
                else
                {
                    printf("\nPelicula agregada correctamente.");
                }
                break;
            case 2:

                estado=borrarPelicula(movies,TAM);

                if(estado==0)
                {
                    printf("\nNo se elimino la pelicula.");
                }
                else
                {
                    printf("\nLa Pelicula ah sido eliminada correctamente.");
                }
                break;
            case 3:

                estado=modificarPelicula(movies,TAM);

                if(estado==0)
                {
                    printf("\nNo se modifico la pelicula.");
                }
                else
                {
                    printf("\nLa Pelicula ah sido modificada correctamente.");
                }
               break;
            case 4:

                generarPagina(movies,"listaPeliculas.html",TAM);
                printf("\nPagina generada correctamente.");


                break;
            case 5:

                seguir = 'n';
                break;
            default:
                printf("\nLa opcion ingresada es incorrecta.");
        }

        printf("\n");
        system("pause");
    }

        printf("\n");
        printf("######### Lectura y Escritura FILE by Leandro Si%ceriz #############",164);
        printf("\n");

    return 0;
}
