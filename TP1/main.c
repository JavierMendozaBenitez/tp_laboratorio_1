#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main()
{
    int opcion;
    int respuesta;
    int factorizando;
    int factorizando2;
    int flag1;
    int flag2;
    int flag3;
    int contadorOperando1;
    int contadorOperando2;
    int dividiendo;
    float ingreso1;
    float ingreso2;
    float sumando;
    float restando;
    float multiplicando;
    float resolucionSuma;
    float resolucionResta;
    float resolucionDivision;
    float resolucionFactorial;
    float resolucionFactorial2;
    float resolucionMultiplicacion;

    flag1 = 0;
    flag2 = 0;
    flag3 = 0;
    contadorOperando1 = 0;
    contadorOperando2 = 0;

    do
    {
        system("cls");

        if(contadorOperando1 == 0)
        {
            printf("*** Menu de Opciones ***\n\n1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n");
        }
        else
        {
            if(contadorOperando2 == 0)
            {
                printf("*** Menu de Opciones ***\n\n1. Ingresar 1er operando (A=%.2f)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n", ingreso1);
            }
            else
            {
                printf("*** Menu de Opciones ***\n\n1. Ingresar 1er operando (A=%.2f)\n2. Ingresar 2do operando (B=%.2f)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n", ingreso1, ingreso2);
            }
        }

        respuesta = utn_getNumero(&opcion,"\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 a 5\n\n",1,5);

        if(!respuesta)
        {
            switch(opcion)
            {
            case 1:
                contadorOperando1++;
                printf("\nIngrese el primer operando\n");
                fflush(stdin);
                scanf("%f", &ingreso1);
                flag1 = 1;
                break;
            case 2:
                if(flag1 == 1)
                {
                    printf("\nIngrese el segundo operando\n");
                    fflush(stdin);
                    scanf("%f", &ingreso2);
                    flag2 = 1;
                    flag1 = 0;
                    contadorOperando2++;
                }
                else
                {
                    printf("\nPrimero debe ingresar el primer operando, reintente.\n\n");
                }
                break;
            case 3:
                if(flag2 == 1)
                {
                    sumando = suma(ingreso1, ingreso2);
                    restando = resta(ingreso1, ingreso2);
                    dividiendo = division(&resolucionDivision, ingreso1, ingreso2);
                    multiplicando = multiplicacion(ingreso1, ingreso2);
                    factorizando = factorial(&resolucionFactorial, ingreso1);
                    flag3 = 1;
                    flag2 = 0;
                    printf("\nLas operaciones se hicieron correctamente.\n\n");
                }
                else
                {
                    printf("\nPara hacer las operaciones es obligatorio ingresar el primero y segundo operando, reintente.\n\n");
                }
                break;
            case 4:
                if(flag3 == 1)
                {
                    printf("\nEl resultado de %.2f + %.2f es: %.2f\n", ingreso1, ingreso2, sumando);
                    printf("\nEl resultado de %.2f - %.2f es: %.2f\n", ingreso1, ingreso2, restando);

                    if(dividiendo == 0)
                    {
                        printf("\nEl resultado de %.2f / %.2f es: %.2f\n", ingreso1, ingreso2, resolucionDivision);
                    }
                    else
                    {
                        printf("\nNo es posible dividir por cero.\n");
                    }

                    printf("\nEl resultado de %.2f * %.2f es: %.2f\n", ingreso1, ingreso2, multiplicando);

                    if(factorizando == 0)
                    {
                        printf("\nEl factorial de %.2f es: %.2f\n", ingreso1, resolucionFactorial);
                    }
                    else
                    {
                        printf("\nEl numero %.2f no se puede factorizar, debe ingresar un numero mayor a 0 y sin decimales.\n", ingreso1);
                    }

                    factorizando2 = factorial(&resolucionFactorial2, ingreso2);

                    if(factorizando2 == 0)
                    {
                        printf("El factorial de %.2f es: %.2f\n\n", ingreso2, resolucionFactorial2);
                    }
                    else
                    {
                        printf("El numero %.2f no se puede factorizar, debe ingresar un numero mayor a 0 y sin decimales.\n\n", ingreso2);
                    }

                    contadorOperando1 = 0;
                    contadorOperando2 = 0;
                    flag3 = 0;
                }
                else
                {
                    printf("\nPara ver los resultados primero debe ingresar los dos operandos y realizar las cuentas del punto 3, reintente.\n\n");
                }
                break;
            default:
                break;
            }
            system("pause");
        }
        else
        {
            system("pause");
        }
    }

    while(opcion != 5);

    return 0;
}

