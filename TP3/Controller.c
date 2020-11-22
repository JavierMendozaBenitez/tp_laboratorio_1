#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validaciones.h"


/** \brief Busca un valor para el Id
 *
 * \param id int* puntero al Id
 * \return int devuelve 0 si se hizo correctamente
 *
 */
int obtenerId(int* id)
{
    int error = 1;
    * id = 1001;

    FILE* f;
    f = fopen("proximoId.bin", "rb");

    if(f != NULL)
    {
        fread(id, sizeof(int), 1, f);

        fclose(f);
        error = 0;
    }

    return error;
}


/** \brief Actualiza el id
 *
 * \param id int id a actualizar
 * \return int devuelve 0 si se hizo correctamente
 *
 */
int actualizarId(int id)
{
    int error = 1;
    int proximoId = ++id;

    FILE* f = fopen("proximoId.bin", "wb");

    if(f != NULL)
    {
        fwrite(&proximoId, sizeof(int), 1, f);

        fclose(f);
        error = 0;
    }
    return error;
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

    obtenerId(&id);

    sprintf(idChar, "%d", id);

    fprintf(agregar, "%s,%s,%s,%s\n", idChar, nombre, horasTrabajadas, sueldo);

    nuevoEmpleado = employee_newParametros(idChar, nombre, horasTrabajadas, sueldo);

    ll_add(pArrayListEmployee, nuevoEmpleado);

    fclose(agregar);

    actualizarId(id);

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
    Employee* auxEmpleado;

    int id;
    int auxId;
    int error = 1;
    int len;
    int index;
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



        len = ll_len(pArrayListEmployee);
        for(int i=0; i<len; i++)
        {
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);

            employee_getId(auxEmpleado, &auxId);
            if(auxId == id)
                //if(auxEmpleado->id == id)
            {
                //index = ll_indexOf(pArrayListEmployee, (Employee*) ll_get(pArrayListEmployee, i));
                index = ll_indexOf(pArrayListEmployee, auxEmpleado);

                if(index == 0)
                {
                    printf("No existe un empleado con el ID: %d.\n", id);
                    system("pause");
                }
                else
                {
                    printf("El empleado a modificar es: \n");

                    printf(" ID        Nombre       Hora Trabajadas       Sueldo\n");

                    mostrarEmpleado(auxEmpleado);

                    ll_set(pArrayListEmployee, index, nuevoEmpleado);

                    error = 0;

                    break;
                }
            }
        }
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
    int len;
    int auxId;
    Employee* auxEmpleado;

    if(pArrayListEmployee != NULL)
    {
        mostrarEmpleados(pArrayListEmployee);

        if(utn_getNumeroConScanf(&id, "\nIngrese el id que desea eliminar: ", "\nError, reingrese id valido.\n", 0, 1500, 10) == 0)
        {
            len = ll_len(pArrayListEmployee);
            for(int i=0; i<len; i++)
            {
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);

                employee_getId(auxEmpleado, &auxId);
                if(auxId == id)
                    //if(auxEmpleado->id == id)
                {
                    //index = ll_indexOf(pArrayListEmployee, (Employee*) ll_get(pArrayListEmployee, i));
                    index = ll_indexOf(pArrayListEmployee, auxEmpleado);

                    if(index == 0)
                    {
                        printf("No existe un empleado con el ID: %d.\n", id);
                        system("pause");
                    }
                    else
                    {
                        printf("\nEl empleado a eliminar es: \n");

                        printf(" ID        Nombre       Hora Trabajadas       Sueldo\n");

                        //mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, index));
                        mostrarEmpleado(auxEmpleado);


                        ll_remove(pArrayListEmployee, index);
                        if(employee_delete(auxEmpleado) == 0)
                        {
                            printf("\nMemoria liberada del empleado dado de baja.\n\n");
                        }

                        error = 0;

                        break;
                    }
                }
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
            printf("En que orden? 1 ascendente o 0 descendente.\n");
            fflush(stdin);
            scanf("%d", &opcion);
            ll_sort(pArrayListEmployee, employeeSortById, opcion);
            mostrarEmpleados(pArrayListEmployee);
            break;
        case 2:
            printf("En que orden? 1 ascendente o 0 descendente.\n");
            fflush(stdin);
            scanf("%d", &opcion);
            ll_sort(pArrayListEmployee, employeeSortByName, opcion);
            mostrarEmpleados(pArrayListEmployee);
            break;
        case 3:
            printf("En que orden? 1 ascendente o 0 descendente.\n");
            fflush(stdin);
            scanf("%d", &opcion);
            ll_sort(pArrayListEmployee, employeeSortByWorkHours, opcion);
            mostrarEmpleados(pArrayListEmployee);
            break;
        case 4:
            printf("En que orden? 1 ascendente o 0 descendente.\n");
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
        FILE* archivo = fopen(path, "wb");
        Employee* auxEmpleado;

        if(archivo != NULL)
        {
            int len = ll_len(pArrayListEmployee);
            printf("Cantidad de elementos: %d\n", len);
            system("pause");

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);

                if(auxEmpleado != NULL)
                {
                    fwrite(auxEmpleado, sizeof(Employee), 1, archivo);
                    error = 0;
                }
            }
            fclose(archivo);
        }
    }

    return error;
}

