#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int num1=0;
    int num2=0;
    int resultado=0;
    float resultadoFloat=0;
    int flagA=0;
    int flagB=0;
    long int resultadoFact;

    while(seguir=='s')
    {
        system("cls");

        printf("####################CALCULADORA EN C ########################\n");
        printf("##1- Ingresar 1er operando (A=%d)                           ##\n",num1);
        printf("##2- Ingresar 2do operando (B=%d)                           ##\n",num2);
        printf("##3- Calcular la suma (A+B)                                ##\n");
        printf("##4- Calcular la resta (A-B)                               ##\n");
        printf("##5- Calcular la division (A/B)                            ##\n");
        printf("##6- Calcular la multiplicacion (A*B)                      ##\n");
        printf("##7- Calcular el factorial (A!)                            ##\n");
        printf("##8- Calcular todas las operaciones                        ##\n");
        printf("##9- Salir                                                 ##\n");
        printf("#############################################################\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            flagA=1;
            num1=pedirNumero("Ingrese el operando A: ");
            break;

        case 2:
            flagB=1;
            num2=pedirNumero("Ingrese el operando B: ");

            break;

        case 3:
            if(flagA==0)
            {
                printf("Por favor ingrese el operando A.\n");

            }
            else if(flagB==0)
            {
                printf("Por favor ingrese el operando B.\n");
            }
            else
            {
                resultado=suma(num1,num2);

                printf("El resultado de la suma es: %d\n\n",resultado);

            }

            system("pause");

            break;


        case 4:
            if(flagA==0)
            {
                printf("Por favor ingrese el operando A.\n");

            }
            else if(flagB==0)
            {
                printf("Por favor ingrese el operando B.\n");
            }
            else
            {
                resultado=resta(num1,num2);

                printf("El resultado de la resta es: %d\n\n",resultado);
            }

            system("pause");

            break;

        case 5:
            if(flagA==0)
            {
                printf("Por favor ingrese el operando A.\n");

            }
            else if(flagB==0)
            {
                printf("Por favor ingrese el operando B.\n");
            }
            else
            {
                if(num2==0)
                {
                    printf("Error, no se puede dividir por 0.\n\n");

                }
                else
                {
                    resultadoFloat=division(num1,num2);

                    printf("El resultado de la division es: %.2f\n\n",resultadoFloat);

                }
            }
            system("pause");

            break;

        case 6:
            if(flagA==0)
            {
                printf("Por favor ingrese el operando A.\n");

            }
            else if(flagB==0)
            {
                printf("Por favor ingrese el operando B.\n");
            }
            else
            {
                resultado=multiplicacion(num1,num2);

                printf("El resultado de la multiplicacion es %d\n\n",resultado);
            }

            system("pause");

            break;

        case 7:
            if(flagA==0)
            {
                printf("Por favor ingrese el operando A.\n");

            }
            else if(num1<0)
            {
                printf("Error no se puede factorear numeros negativos.\n\n");

            }
            else
            {


                resultadoFact=factorial(num1);

                printf("El resultado del factoreo de %d es: %ld\n\n",num1,resultadoFact);
            }


            system("pause");

            break;
        case 8:

            if(flagA==0)
            {
                printf("Por favor ingrese el operando A.\n");

            }
            else if(flagB==0)
            {
                printf("Por favor ingrese el operando B.\n");
            }
            else
            {

                resultado=suma(num1,num2);

                printf("El resultado de la suma es: %d\n\n",resultado);


                resultado=resta(num1,num2);

                printf("El resultado de la resta es: %d\n\n",resultado);


                if(num2==0)
                {
                    printf("Error, no se puede dividir por 0\n\n");

                }
                else
                {
                    resultadoFloat=division(num1,num2);

                    printf("El resultado de la division es: %.2f\n\n",resultadoFloat);

                }


                resultado=multiplicacion(num1,num2);

                printf("El resultado de la multiplicacion es: %d\n\n",resultado);



                if(num1<0)
                {
                    printf("Error no se puede factorear numeros negativos.\n\n");

                }
                else
                {

                    resultadoFact=factorial(num1);

                    printf("El resultado del factoreo de %d es: %ld\n\n",num1,resultadoFact);
                }


                system("pause");


                break;
            case 9:
                seguir = 'n';
                break;
            }

        }
    }

    printf("############CALCULADORA EL C BY Leandro Si%ceriz##############\n",164);
    system("pause");


    return 0;
}
