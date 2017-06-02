#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include <conio.h>
#include <ctype.h>

//printf("\nID: %d\nTitulo: %s\nGenero: %s\nDescripcion: %s\nDuracion: %d\nPuntaje: %d\n LinkImagen:%s",i,(movie+i)->titulo,(movie+i)->genero,(movie+i)->descripcion,(movie+i)->duracion,(movie+i)->puntaje, (movie+i)->linkImagen);

EMovie* newMovie(EMovie* movie,int tam)
{
    movie = (EMovie*)malloc(sizeof(EMovie)*tam);

    return movie;
}


void setMovies(EMovie* movie,int tam)
{
    FILE* bin;
    char titulo[500], genero[500],descripcion[5000],linkImagen[500],duracion[500],puntaje[500];
    int cont=0,i;

    bin=fopen("bin.dat","r");

    if(bin==NULL)
    {
        printf("\nNo se encontro el archivo.");
        exit(0);
    }

    for(i=0; i<tam; i++)
    {
        (movie+i)->estado=0;
    }


    while(!feof(bin))
    {
        if(cont==tam)
        {
            break;
        }

        fscanf(bin, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n",linkImagen,titulo,genero,descripcion,duracion,puntaje);

        strcpy((movie+cont)->linkImagen,linkImagen);

        strcpy((movie+cont)->titulo,titulo);


        strcpy((movie+cont)->genero,genero);


        (movie+cont)->duracion=atoi(duracion);


        strcpy((movie+cont)->descripcion,descripcion);

        (movie+cont)->puntaje=atoi(puntaje);

        (movie+cont)->estado=1;

        cont++;
    }

    fclose(bin);

}

void printMovies(EMovie* movie, int tam)
{
    int i;



    for(i=0; i<tam; i++)
    {
        if((movie+i)->estado==1)
        {
            printf("\nINDEX: %d| TITULO: %s| GENERO: %s\n",i,(movie+i)->titulo,(movie+i)->genero);
        }

    }



}

void fprintMovies(EMovie* movie, int tam,FILE* bin)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if((movie+i)->estado==1)
        {
            fprintf(bin, "%s|%s|%s|%s|%d|%d\n", (movie+i)->linkImagen ,(movie+i)->titulo,(movie+i)->genero,(movie+i)->descripcion,(movie+i)->duracion,(movie+i)->puntaje);
        }

    }



}

int buscarLibre(EMovie* movie,int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if((movie+i)->estado==0)
        {
            return i;
        }
    }

    return -1;
}

int agregarPelicula(EMovie* movie,int tam)
{
    FILE* bin;
    char titulo[500], genero[500],descripcion[5000],pregunta,linkImagen[500];
    int duracion,puntaje,libre,auxLen,i;

    libre=buscarLibre(movie,tam);

    if(libre==-1)
    {
        printf("\nError no hay espacio para mas peliculas.");
        return 0;
    }


    printf("\nIngrese el titulo: ");
    fflush(stdin);
    gets(titulo);
    strlwr(titulo);
    titulo[0]=toupper(titulo[0]);
    auxLen=strlen(titulo);

    for(i=0; i<auxLen; i++)
    {
        if(titulo[i]==' ')
        {
            titulo[i+1]=toupper(titulo[i+1]);
        }
    }

    printf("\nIngrese el genero: ");
    fflush(stdin);
    gets(genero);
    strlwr(genero);
    genero[0]=toupper(genero[0]);

    printf("\nIngrese la descripcion: ");
    fflush(stdin);
    gets(descripcion);
    descripcion[0]=toupper(descripcion[0]);
    auxLen=strlen(descripcion);
    while(auxLen>2000)
    {
        printf("\nLa descripcion es demasiado larga(2000 o menos caracteres).Reingrese: ");
        fflush(stdin);
        gets(descripcion);
        descripcion[0]=toupper(descripcion[0]);
        auxLen=strlen(descripcion);
    }

    printf("\nIngrese la duracion(en minutos): ");
    scanf("%d",&duracion);

    printf("\nIngrese el puntaje(1 -- 10): ");
    scanf("%d",&puntaje);
    while(puntaje<1 || puntaje>10)
    {
        printf("\nError. Reingrese un puntaje entre 1 -- 10: ");
        scanf("%d",&puntaje);
    }

    printf("\nIngrese el link de imagen: ");
    fflush(stdin);
    gets(linkImagen);

    printf("Esta seguro que desea agregar esta pelicula?(s/n):\n");
    pregunta=tolower(getche());

    if(pregunta=='s')
    {
        strcpy((movie+libre)->titulo,titulo);
        strcpy((movie+libre)->genero,genero);
        (movie+libre)->duracion=duracion;
        strcpy((movie+libre)->descripcion,descripcion);
        (movie+libre)->puntaje=puntaje;
        strcpy((movie+libre)->linkImagen,linkImagen);
        (movie+libre)->estado=1;

        bin=fopen("bin.dat","w");

        if(bin==NULL)
    {
        printf("\nNo se encontro el archivo.");
        exit(0);
    }

        fprintMovies(movie,tam,bin);

        fclose(bin);

        return 1;
    }

    return 0;


}


int borrarPelicula(EMovie* movie,int tam)
{

    int i,auxInt;
    FILE* bin;
    char pregunta;

    printMovies(movie,tam);

    printf("\nIngrese el INDEX de la pelicula a eliminar: ");
    scanf("%d",&auxInt);

    for(i=0; i<tam; i++)
    {
        if(auxInt==i && (movie+i)->estado==1)
        {
            printf("\nTitulo: %s\n\nGenero: %s\n\nDescripcion: %s\n\nDuracion: %d\n\nPuntaje: %d\n\nLinkImagen: %s",(movie+i)->titulo,(movie+i)->genero,(movie+i)->descripcion,(movie+i)->duracion,(movie+i)->puntaje, (movie+i)->linkImagen);
            printf("\nEsta desguro que desea eliminar esta pelicula(s/n): ");
            pregunta=tolower(getche());

            if(pregunta=='s')
            {
                (movie+i)->estado=0;

            bin=fopen("bin.dat","w");

            if(bin==NULL)
    {
        printf("\nNo se encontro el archivo.");
        exit(0);
    }

            fprintMovies(movie,tam,bin);

            fclose(bin);

            return 1;
            }
            else
            {
                return 0;
            }

        }
    }

    printf("\nEl ID ingresado no existe.");

    return 0;


}

int modificarPelicula(EMovie* movie,int tam)
{

    int i,j,auxInt,opcion,duracion,puntaje,auxLen;
    char titulo[500], genero[500],descripcion[5000],linkImagen[500],pregunta;
    FILE* bin;

    printMovies(movie,tam);

    printf("\nIngrese el INDEX de la pelicula que desea modificar: ");
    scanf("%d",&auxInt);

    for(i=0; i<tam; i++)
    {
        if(auxInt==i && (movie+i)->estado==1)
        {
            printf("\nTitulo: %s\n\nGenero: %s\n\nDescripcion: %s\n\nDuracion: %d\n\nPuntaje: %d\n\nLinkImagen:%s",(movie+i)->titulo,(movie+i)->genero,(movie+i)->descripcion,(movie+i)->duracion,(movie+i)->puntaje, (movie+i)->linkImagen);
            printf("\nEsta desguro que desea modificar esta pelicula(s/n): ");
            pregunta=tolower(getche());

            if(pregunta=='s')
            {
                printf("\nIngrese la opcion a modificar:");
                printf("\n1- Titulo");
                printf("\n2- Genero");
                printf("\n3- Descripcion");
                printf("\n4- Duracion");
                printf("\n5- Puntaje");
                printf("\n6- LinkImagen");
                printf("\n7- Salir\n");

                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    printf("\nIngrese el nuevo titulo: ");
                    fflush(stdin);
                    gets(titulo);
                    strlwr(titulo);
                    titulo[0]=toupper(titulo[0]);
                    auxLen=strlen(titulo);

                    for(j=0; j<auxLen; j++)
                    {
                        if(titulo[j]==' ')
                        {
                            titulo[j+1]=toupper(titulo[j+1]);
                        }
                    }
                    strcpy((movie+i)->titulo,titulo);

                    break;
                case 2:
                    printf("\nIngrese el nuevo genero: ");
                    fflush(stdin);
                    gets(genero);
                    strlwr(genero);
                    genero[0]=toupper(genero[0]);

                    strcpy((movie+i)->genero,genero);
                    break;
                case 3:
                    printf("\nIngrese la nueva descripcion: ");
                    fflush(stdin);
                    gets(descripcion);
                    descripcion[0]=toupper(descripcion[0]);
                    auxLen=strlen(descripcion);
                    while(auxLen>2000)
                    {
                        printf("\nLa descripcion es demasiado larga(2000 o menos caracteres).Reingrese: ");
                        fflush(stdin);
                        gets(descripcion);
                        descripcion[0]=toupper(descripcion[0]);
                        auxLen=strlen(descripcion);
                    }

                    strcpy((movie+i)->descripcion,descripcion);
                    break;
                case 4:
                    printf("\nIngrese la nueva duracion(en minutos): ");
                    scanf("%d",&duracion);

                    (movie+i)->duracion=duracion;


                    break;
                case 5:
                    printf("\nIngrese el nuevo puntaje(1 -- 10): ");
                    scanf("%d",&puntaje);
                    while(puntaje<1 || puntaje>10)
                    {
                        printf("Error. Reingrese un puntaje entre 1 -- 10: ");
                        scanf("%d",&puntaje);
                    }

                    (movie+i)->puntaje=puntaje;
                    break;
                case 6:
                    printf("\nIngrese el nuevo link de imagen: ");
    fflush(stdin);
    gets(linkImagen);

    strcpy((movie+i)->linkImagen,linkImagen);
                    break;
                case 7:

                    return 0;
                    break;
                default:
                    printf("Opcion incorrecta.");
                    return 0;

                }


            bin=fopen("bin.dat","w");

            if(bin==NULL)
    {
        printf("No se encontro el archivo.");
        exit(0);
    }

            fprintMovies(movie,tam,bin);

            fclose(bin);

            return 1;
            }
            else
            {
                return 0;
            }

        }
    }

    printf("\nEl INDEX ingresado no existe.");

    return 0;
}


void generarPagina(EMovie* movie, char nombre[],int tam)
{
    FILE* pagina;
    int i;

    pagina=fopen(nombre,"w");

    if(pagina==NULL)
    {
        printf("\nNo se encontro el archivo.");
        exit(0);
    }

    fprintf(pagina, "<!DOCTYPE html>\
<!-- Template by Quackit.com -->\
<html lang='en'>\
<head>\
    <meta charset='utf-8'>\
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\
    <meta name='viewport' content='width=device-width, initial-scale=1'>\
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\
    <title>Lista peliculas</title>\
    <!-- Bootstrap Core CSS -->\
    <link href='html/css/bootstrap.min.css' rel='stylesheet'>\
    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\
    <link href='html/css/custom.css' rel='stylesheet'>\
    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\
    <!--[if lt IE 9]>\
        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\
        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\
    <![endif]-->\
</head>\
<body>\
    <div class='container'>\
        <div class='row'>");

        for(i=0;i<tam;i++)
        {
            if((movie+i)->estado==1)
            {
                fprintf(pagina, "<article class='col-md-12 article-intro'>\
                <a href='#'>\
                    <img class='img-responsive img-rounded' src='%s' alt=''>\
                </a>\
                <h3>\
                    <a href='#'> %s </a>\
                </h3>\
				<ul>\
					<li>Genero:%s </li>\
					<li>Puntaje:%d</li>\
					<li>Duracion:%d min</li>\
				</ul>\
                <p>%s</p>\
            </article>", (movie+i)->linkImagen , (movie+i)->titulo , (movie+i)->genero , (movie+i)->puntaje , (movie+i)->duracion , (movie+i)->descripcion );
            }
        }

        fprintf(pagina, "</div>\
        <!-- /.row -->\
    </div>\
    <!-- /.container -->\
    <!-- jQuery -->\
    <script src='html/js/jquery-1.11.3.min.js'></script>\
    <!-- Bootstrap Core JavaScript -->\
    <script src='html/js/bootstrap.min.js'></script>\
	<!-- IE10 viewport bug workaround -->\
	<script src='html/js/ie10-viewport-bug-workaround.js'></script>\
	<!-- Placeholder Images -->\
	<script src='html/js/holder.min.js'></script>\
</body>\
</html>");


}
