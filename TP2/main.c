#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1000
#define ASC 1
#define DESC 0

int main()
{
    int proximoLegajo = 0;
    int rta;
    int respuesta;
    int opcion;
    int flag1;
    float cantidadIngresados;
    float acumuladorSalarioIngresado;
    float promedioSueldosIngresados;
    float sueldosSuperioresAPromedio;

    flag1 = 0;

    eEmpleado lista [TAM];

    if(initEmployees(lista, TAM)==0)
    {
        printf("Personas inicializadas con exito!\n\n");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar personas");
    }

    proximoLegajo += 1;

    do
    {
        system("cls");

        respuesta = utn_getNumero(&opcion,"*** ABM Empleados ***\n\n1 ALTA\n2 MODIFICAR\n3 BAJA\n4 INFORMAR\n5 SALIR\n\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 a 5\n\n",1,5);

        if(!respuesta)
        {
            switch(opcion)
            {

            case 1:
                if(addEmployee(lista, TAM, proximoLegajo) == 0)
                {
                    proximoLegajo++;
                    printf("\nALTA EXITOSA!\n\n");
                    flag1 = 1;
                }
                else
                {
                    printf("Problema para realizar el alta\n\n");
                }
                break;
            case 2:
                if( flag1 == 1)
                {
                    rta = modificarEmpleado(lista, TAM);
                    if(rta == 0)
                    {
                        printf("La modificacion fue exitosa\n\n");
                    }
                }
                else
                {
                    printf("\nAun no se cargaron empleados, elija la opcion 1 y carguelos.\n\n");
                }
                break;
            case 3:
                if( flag1 == 1)
                {
                    rta = removeEmployee(lista, TAM);

                    if( rta == 0)
                    {
                        printf("\n\nBaja exitosa\n\n");
                    }
                    else if(rta == 2)
                    {
                        printf("\n\nBaja cancelada por usuario\n\n");
                    }
                    else if(rta == 3)
                    {
                        printf("\nNo existe un empleado con ese id.\n\n");
                    }
                    else if(rta == 4)
                    {
                        printf("\nEliminaste todos los empleados. Carga nuevos en la opcion 1.\n\n");
                    }
                }
                else
                {
                    printf("\nAun no se cargaron empleados, elija la opcion 1 y carguelos.\n\n");
                }

                break;
            case 4:
                if( flag1 == 1)
                {
                    system("cls");
                    printf("********Epleados ordenados por Apellido y si tienen el mismo Apellido, desempatamos ordenando por Sector********\n\n");
                    sortEmployees(lista, TAM, 1, 1);
                    printEmployees(lista,TAM);

                    cantidadIngresados = cantidadEmpleados(lista,TAM);
                    printf("\nCantidad empleados: %2.f.\n\n",cantidadIngresados);

                    acumuladorSalarioIngresado = acumuladorSalario(lista, TAM);
                    printf("Sueldos acumulados: %2.f.\n\n",acumuladorSalarioIngresado);

                    promedioSueldosIngresados = promedioSueldos(lista, TAM);
                    printf("El promedio de los sueldos es: %2.f.\n\n",promedioSueldosIngresados);

                    sueldosSuperioresAPromedio = sueldosSuperioresAlPromedio(lista, TAM);
                    printf("La cantidad de sueldos superiores al promedio son:%2.f.\n\n", sueldosSuperioresAPromedio);
                }
                else
                {
                    printf("\nAun no se cargaron empleados, elija la opcion 1 y carguelos.\n\n");
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
    while( opcion != 5);

    return 0;
}
