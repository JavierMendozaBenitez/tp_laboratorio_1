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
            printf("%d,%s,%d,%d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
            error = 0;
        }
        else
        {
            break;
        }
    }
    int len = ll_len(pArrayListEmployee);
    printf("Cantidad de elementos: %d\n", len);
    system("pause");

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
    int cant;

    auxEmpleado = employee_new();

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cant = fread(auxEmpleado, sizeof(Employee),1, pFile);

            if(cant!=1)
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro\n");
                    break;
                }
            }
            else
            {
                ll_add(pArrayListEmployee, auxEmpleado);
                auxEmpleado = employee_new();
                error = 0;
            }
        }
    }

    int len = ll_len(pArrayListEmployee);
    printf("Cantidad de elementos: %d\n", len);
    system("pause");

    return error;
}
