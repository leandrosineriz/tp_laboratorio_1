
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int pedirNumero(char texto[])
{
    float numero;
    int num;


    printf("%s",texto);
    scanf("%f",&numero);

    num=(int)numero;


    return num;
}

int suma(int num1,int num2)
{
    int resultado;

    resultado=num1+num2;

    return resultado;
}

int resta(int num1,int num2)
{
    int resultado;

    resultado=num1-num2;

    return resultado;
}

float division(int num1,int num2)
{
    float resultado;

    resultado=(float)num1/num2;

    return resultado;
}

int multiplicacion(int num1,int num2)
{
    int resultado;

    resultado=num1*num2;

    return resultado;
}

int factorial(int num1)
{
    int resultado;


    if(num1==0)
    {
        return 1;
    }
    else
    {

    resultado=num1*factorial(num1-1);
    }
    return resultado;
}
