#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validaciones.h"


static int obtenerId()
{
    static int id = 1001;

    id++;

    return id;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;

    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                todoOk = 0;
            }
            fclose(pFile);
        }
    }
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;

    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
            {
                todoOk = 0;
            }
            fclose(pFile);
        }
    }
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;

    int id;
    char idChar[120];
    char nombre[20];
    char horasTrabajadas[20];
    char sueldo[20];

    FILE* agregar;

    agregar = fopen("data.csv", "a");

    if(agregar == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    printf("Ingrese Nombre\n");
    fflush(stdin);
    scanf("%s", nombre);

    printf("Nombre ingresado: %s\n", nombre);



    printf("Ingrese Horas Trabajadas\n");
    fflush(stdin);
    scanf("%s", horasTrabajadas);

    printf("Horas ingresadas: %s\n", horasTrabajadas);



    printf("Ingrese Sueldo\n");
    fflush(stdin);
    scanf("%s", sueldo);

    printf("Sueldo ingresado: %s\n", sueldo);

    id = obtenerId();

    sprintf(idChar, "%d", id);

    fprintf(agregar, "%s,%s,%s,%s\n", idChar, nombre, horasTrabajadas, sueldo);

    nuevoEmpleado = employee_newParametros(idChar, nombre, horasTrabajadas, sueldo);

    ll_add(pArrayListEmployee, nuevoEmpleado);

    fclose(agregar);

    return 0;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    Employee* nuevoEmpleado;

    int id;
    int error = 1;
    char idChar[120];
    char nombre[20];
    char horasTrabajadas[20];
    char sueldo[20];

    FILE* agregar;

    agregar = fopen("data.csv", "a");

    if(agregar == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    mostrarEmpleados(pArrayListEmployee);

    if(utn_getNumeroConScanf(&id, "Ingrese el id que desea modificar: ", "\nError, reingrese id valido.\n", 0, 1500, 10) == 0)
    {
        printf("Ingrese Nombre\n");
        fflush(stdin);
        scanf("%s", nombre);

        printf("Nombre ingresado: %s\n", nombre);



        printf("Ingrese Horas Trabajadas\n");
        fflush(stdin);
        scanf("%s", horasTrabajadas);

        printf("Horas ingresadas: %s\n", horasTrabajadas);



        printf("Ingrese Sueldo\n");
        fflush(stdin);
        scanf("%s", sueldo);

        printf("Sueldo ingresado: %s\n", sueldo);

        sprintf(idChar, "%d", id);

        nuevoEmpleado = employee_newParametros(idChar, nombre, horasTrabajadas, sueldo);

        ll_set(pArrayListEmployee, id-1, nuevoEmpleado);

        error = 0;
    }
    fclose(agregar);

    return error;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int index = -1;
    int id;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        if(utn_getNumeroConScanf(&id, "Ingrese el id que desea eliminar: ", "\nError, reingrese id valido.\n", 0, 1500, 10) == 0)
        {
            index = ll_indexOf(pArrayListEmployee, (Employee*) ll_get(pArrayListEmployee, id));

            if(index == 0)
            {
                printf("No existe un empleado con el ID: %d.\n", id);
                system("pause");
            }
            else
            {
                printf("El empleado a eliminar es: \n");

                printf(" ID        Nombre       Hora Trabajadas       Sueldo\n");

                mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, index));

                ll_remove(pArrayListEmployee, index);
                printf("\nEliminado.\n");
                error = 0;
            }
        }
    }

    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    mostrarEmpleados(pArrayListEmployee);

    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int opcion;
    char seguir = 's';
    char confirma;

    do
    {
        switch(subMenuInt())
        {
        case 1:
            printf("En que orden? 1 ascendente o 2 descendente.\n");
            fflush(stdin);
            scanf("%d", &opcion);
            ll_sort(pArrayListEmployee, employeeSortById, opcion);
            mostrarEmpleados(pArrayListEmployee);
            break;
        case 2:
            printf("En que orden? 1 ascendente o 2 descendente.\n");
            fflush(stdin);
            scanf("%d", &opcion);
            ll_sort(pArrayListEmployee, employeeSortByName, opcion);
            mostrarEmpleados(pArrayListEmployee);
        case 3:
            printf("En que orden? 1 ascendente o 2 descendente.\n");
            fflush(stdin);
            scanf("%d", &opcion);
            ll_sort(pArrayListEmployee, employeeSortByWorkHours, opcion);
            mostrarEmpleados(pArrayListEmployee);
            break;
        case 4:
            printf("En que orden? 1 ascendente o 2 descendente.\n");
            fflush(stdin);
            scanf("%d", &opcion);
            ll_sort(pArrayListEmployee, employeeSortBySalary, opcion);
            mostrarEmpleados(pArrayListEmployee);
            break;
        case 5:
            printf("Volver al menu principal? Presione s para si o n para no: ");
            fflush(stdin);
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("Opcion invalida!!!\n");
        }
        system("pause");
        retorno = 0;
    }
    while(seguir == 's');

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;

    if(pArrayListEmployee != NULL)
    {
        FILE* archivo = fopen(path, "w");
        Employee* auxEmpleado;
        if(archivo != NULL)
        {
            fprintf(archivo, "id,nombre,horasTrabajadas,sueldo\n");
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
                if(auxEmpleado != NULL)
                {
                    fprintf(archivo, "%d,%s,%d,%d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
                    error = 0;
                }
            }
            fclose(archivo);
        }
    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;

    if(pArrayListEmployee != NULL)
    {
        FILE* archivo = fopen(path, "ab");
        Employee* auxEmpleado;
        if(archivo != NULL)
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
                if(auxEmpleado != NULL)
                {
                    fread(&auxEmpleado, sizeof(Employee*), 1, archivo);
                    error = 0;
                }
                fclose(archivo);
            }
        }
    }

    return error;
}

