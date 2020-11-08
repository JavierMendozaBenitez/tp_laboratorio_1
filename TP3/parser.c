#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    int error = -1;
    int cant;
    char buffer[4][100];

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    printf("%s  %s  %s  %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        if(cant == 4)
        {
            auxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
            ll_add(pArrayListEmployee, auxEmpleado);
            printf("%d %s %d %d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
            error = 0;
        }
        else
        {
            break;
        }
    }

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    int error = -1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            fread(&auxEmpleado, sizeof(Employee*), 1, pFile);
            ll_add(pArrayListEmployee, auxEmpleado);
            error = 0;
        }
    }

    return error;
}
