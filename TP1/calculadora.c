#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo)
{
    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(retorno == 0);

    }
    return retorno;
}

float suma(float operando1, float operando2)
{
    float resultadoSuma;

    resultadoSuma = operando1 + operando2;

    return resultadoSuma;
}

float resta(float operando1, float operando2)
{
    float resultadoResta;

    resultadoResta = operando1 - operando2;

    return resultadoResta;
}

int division(float* pResultadoDivision, float operando1, float operando2)
{
    int retorno = -1;
    float resultadoDivision;

    if(pResultadoDivision != NULL && operando2 != 0)
    {
        resultadoDivision = (float) operando1 / operando2;
        *pResultadoDivision = resultadoDivision;
        retorno = 0;
    }

    return retorno;
}

float multiplicacion(float operando1, float operando2)
{
    float resultadoMultiplicacion;

    resultadoMultiplicacion = operando1 * operando2;

    return resultadoMultiplicacion;
}

int factorial (float* pFact, float operando1)
{
    float fact = 1;
    int retorno = -1;
    int ent;
    ent = operando1;

    if(pFact != NULL && operando1 > 0 && operando1 - ent == 0)
    {
        for ( int i = 1; i <= operando1; i++)
        {
            fact = fact * i;
            *pFact = fact;
            retorno = 0;
        }
    }
    return retorno;
}

