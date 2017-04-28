#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20


int main()
{
    ePersona personas[TAM];
    char seguir='s';
    int opcion=0;


    setLista(personas,TAM);

    while(seguir=='s')
    {
        system("cls");
        printf("################# REGISTRO DE PERSONAS EN C #######################\n");
        printf("## 1- Agregar persona                                            ##\n");
        printf("## 2- Borrar persona                                             ##\n");
        printf("## 3- Imprimir lista ordenada por  nombre                        ##\n");
        printf("## 4- Imprimir grafico de edades                                 ##\n");
        printf("## 5- Salir                                                      ##\n");
        printf("###################################################################\n");



        scanf("%d",&opcion);



        switch(opcion)
        {
        case 1:
            agregarPersona(personas,TAM);
            break;
        case 2:
            borrarPersona(personas,TAM);
            break;
        case 3:
            OrdenarPorNombre(personas,TAM);
            mostrarLista(personas,TAM);
            break;
        case 4:
            estadistica(personas,TAM);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("La opcion ingresada es incorrecta.");
        }
        printf("\n\n");
        system("pause");
    }

    printf("\n############ REGISTRO EN C by Leandro Si%ceriz ##############\n",164);
    return 0;
}
