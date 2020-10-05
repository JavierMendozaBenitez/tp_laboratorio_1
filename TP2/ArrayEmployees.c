#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

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

int initEmployees(eEmpleado gente[], int tam)
{

    int error = 1;
    if (gente!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            gente[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int printEmployees(eEmpleado gente[], int tam)
{

    int error = 1;
    int flag = 0;

    if( gente != NULL && tam > 0)
    {
        printf("     ID         Nombre            Apellido        Salario      Sector\n");
        printf("---------------------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                mostrarEmpleado(gente[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay empleados en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}
void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("\n | %4d |   %12s   |   %12s   |  %6.2f | %6d\n\n", unEmpleado.id, unEmpleado.nombre, unEmpleado.apellido, unEmpleado.salario, unEmpleado.sector);

}

int buscarLibre(eEmpleado gente[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(gente[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int soloLetras(char cadena[])
{
    int retorno = 1;

    for(int i=0; cadena[i]!='\0'; i++)
    {
        if((cadena[i]<'a'||cadena[i]>'z')&&(cadena[i]<'A'||cadena[i]>'Z'))
        {
            retorno=0;
        }
    }

    return retorno;
}

void largoCadena(char cadena[],int tamanio,char mensaje[],char errorMensaje[])
{
    puts(mensaje);
    fflush(stdin);;
    fgets(cadena,tamanio,stdin);
    cadena[strlen(cadena)-1]='\0';

    while(!soloLetras(cadena))
    {
        puts(errorMensaje);
        fflush(stdin);
        fgets(cadena,tamanio,stdin);
        cadena[strlen(cadena)-1]='\0';
    }
}
int addEmployee(eEmpleado gente[], int tam, int id)
{

    int error = 1;
    int indice;
    eEmpleado nuevoEmpleado;

    if(gente!=NULL && tam > 0 && id > 0)
    {

        system("cls");
        printf("ALTA DE EMPLEADO\n\n");
        indice = buscarLibre(gente, tam);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            nuevoEmpleado.id = id;
            nuevoEmpleado.isEmpty = 0;

            largoCadena(nuevoEmpleado.nombre,51,"\n\nIngrese nombre: ","\nReingrese nombre, escribio uno con caracteres diferentes a letras.");
            printf("El nombre ingresado es:%s\n",nuevoEmpleado.nombre);

            largoCadena(nuevoEmpleado.apellido,51,"\n\nIngrese apellido: ","\nReingrese apellido, escribio uno con caracteres diferentes a letras.");
            printf("\nEl apellido ingresado es:%s\n",nuevoEmpleado.apellido);

            printf("Ingrese salario: ");
            scanf("%f", &nuevoEmpleado.salario);

            printf("Ingrese sector: ");
            scanf("%d", &nuevoEmpleado.sector);

            gente[indice] = nuevoEmpleado;
            error = 0;
        }
    }

    return error;
}

int findEmployeeById(eEmpleado gente[], int tam, int id)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(gente[i].id == id && gente[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int removeEmployee(eEmpleado gente[], int tam)
{
    int error = 1;
    int id;
    int indice;
    int confirma;
    int respuesta;
    int cantEmpleados;

    cantEmpleados = cantidadEmpleados(gente,tam);

    if(gente != NULL && tam > 0 && cantEmpleados >0)
    {
        system("cls");
        printf("******************** BAJA DE EMPLEADO **********************\n");
        printEmployees(gente, tam);
        printf("Ingrese el id: ");
        scanf("%d", &id);

        indice = findEmployeeById(gente, tam, id);

        if( indice == -1)
        {
            error = 3;
        }
        else
        {
            mostrarEmpleado(gente[indice]);
            do
            {
                respuesta = utn_getNumero(&confirma,"\nConfirma baja: Presione 1 para dar de baja o 2 para NO dar de baja.\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 o 2\n\n",1,2);

                if(!respuesta)
                {
                    switch(confirma)
                    {

                    case 1:
                        gente[indice].isEmpty = 1;
                        error = 0;
                        break;
                    case 2:
                        error = 2;
                        break;
                    default:
                        break;
                    }

                    system("pause");
                }
            }
            while(confirma != 1 && confirma !=2);
        }
    }
    else
    {
        error = 4;
    }

    return error;
}

int modificarEmpleado(eEmpleado gente[], int tam)
{
    int id;
    int indice;
    int elegido;
    int respondio;
    eEmpleado nuevosDatos;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("    *** MODIFICAR EMPLEADO ***\n");
        printEmployees(gente, tam);
        printf("\nIngrese el id: ");
        scanf("%d", &id);

        indice = findEmployeeById(gente, tam, id);

        if( indice == -1)
        {
            printf("\nNo existe un empleado con ese id.\n");
        }
        else
        {
            mostrarEmpleado(gente[indice]);

            do
            {
                system("cls");

                respondio = utn_getNumero(&elegido,"Que desea modificar?\n\n1 NOMBRE\n2 APELLIDO\n3 SALARIO\n4 SECTOR\n5 TERMINAR\n\nQue opcion elige? \n\n","\nError la opcion debe ser desde 1 a 4\n\n",1,5);

                if(!respondio)
                {
                    switch(elegido)
                    {
                    case 1:
                        largoCadena(nuevosDatos.nombre,51,"\n\nIngrese nombre: ","\nReingrese nombre, escribio uno con caracteres diferentes a letras.");
                        strcpy(gente[indice].nombre, nuevosDatos.nombre);
                        printf("El nombre ingresado es:%s\n",nuevosDatos.nombre);
                        break;
                    case 2:
                        largoCadena(nuevosDatos.apellido,51,"\n\nIngrese apellido: ","\nReingrese apellido, escribio uno con caracteres diferentes a letras.");
                        strcpy(gente[indice].apellido, nuevosDatos.apellido);
                        printf("\nEl apellido ingresado es:%s\n",nuevosDatos.apellido);
                        break;
                    case 3:
                        printf("\nIngrese nuevo salario: ");
                        fflush(stdin);
                        scanf("%f", &nuevosDatos.salario);
                        gente[indice].salario = nuevosDatos.salario;
                        break;
                    case 4:
                        printf("\nIngrese nuevo sector: ");
                        fflush(stdin);
                        scanf("%d", &nuevosDatos.sector);
                        gente[indice].sector = nuevosDatos.sector;
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

                printf("\nLos datos modificados quedaron de este modo: \n\n");
                mostrarEmpleado(gente[indice]);

            }
            while( elegido != 5);
        }
    }
    return 0;
}

int sortEmployees(eEmpleado gente[], int tam, int criterioS, int criterioA)
{
    eEmpleado auxEmpleado;

    if(gente!=NULL && tam>0 && criterioS>=0 && criterioS<=1 && criterioA >= 0 && criterioA <= 1)
    {
        for(int i=0; i-tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((strcmp(gente[i].apellido, gente[j].apellido) > 0 && criterioS == 1))
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
                else if((strcmp(gente[i].apellido, gente[j].apellido) < 0 && criterioS == 0))
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
                else if((strcmp(gente[i].apellido, gente[j].apellido) == 0) && gente[i].sector > gente[j].sector && criterioA == 1)
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
                else if(gente[i].apellido == gente[j].apellido && gente[i].sector < gente[j].sector && criterioA == 0)
                {
                    auxEmpleado = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxEmpleado;
                }
            }
        }
    }

    return 0;

}

float cantidadEmpleados(eEmpleado gente[], int tam)
{
    float contadorEmpleados = 0;

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                contadorEmpleados++;
            }
        }
    }
    return contadorEmpleados;
}

float acumuladorSalario(eEmpleado gente[], int tam)
{
    float acumuladorSueldo = 0;

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].salario != 0)
            {
                acumuladorSueldo = acumuladorSueldo + gente[i].salario;
            }
        }
    }
    return acumuladorSueldo;
}

float promedioSueldos(eEmpleado gente[], int tam)
{
    float promedio;

    promedio = (acumuladorSalario(gente, tam)) / (cantidadEmpleados(gente, tam));

    return promedio;
}

float sueldosSuperioresAlPromedio(eEmpleado gente[], int tam)
{
    float proSueldos;
    float contadorSuperioresAlPromedio = 0;

    proSueldos = promedioSueldos(gente, tam);

    if( gente != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(gente[i].salario > proSueldos)
            {
                contadorSuperioresAlPromedio++;
            }

        }
    }

    return contadorSuperioresAlPromedio;
}
