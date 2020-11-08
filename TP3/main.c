#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{

    char seguir = 's';
    char confirma;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menuInt())
        {
        case 1:
            if(controller_loadFromText("data.csv", listaEmpleados) != 0)
            {
                printf("Problema para cargar los empleados\n");
            }
            else
            {
                printf("Empleados cargados correctamente\n");
            }
            break;
        case 2:
            if(controller_loadFromBinary("data.bin", listaEmpleados) != 0)
            {
                printf("Problema para cargar los empleados\n");
            }
            else
            {
                printf("Empleados cargados correctamente\n");
            }
            break;
        case 3:
            if(controller_addEmployee(listaEmpleados) == 0)
            {
                printf("Empleado agregado con exito\n\n");
            }
            break;
        case 4:
            if(controller_editEmployee(listaEmpleados) == 0)
            {
                printf("Empleado modificado con exito\n\n");
            }
            break;
        case 5:
            if(controller_removeEmployee(listaEmpleados) == 0)
            {
                printf("Empleado quitado con exito\n\n");
            }
            break;
        case 6:
            if(controller_ListEmployee(listaEmpleados) == 0)
            {
                printf("Empleados listados con exito\n\n");
            }
            break;
        case 7:
            if(controller_sortEmployee(listaEmpleados, employeeSortByName) == 0)
            {
                printf("Empleados ordenados con exito\n\n");
            }
            break;
        case 8:
            if(controller_saveAsText("data.csv", listaEmpleados) == 0)
            {
                printf("Listas en texto realizadas con exito\n\n");
            }
            else
            {
                printf("Problema para guardar los empleados\n");
            }
            break;
        case 9:
            if(controller_saveAsBinary("data.bin", listaEmpleados) == 0)
            {
                printf("Listas en binario realizadas con exito\n\n");
            }
            else
            {
                printf("Problema para guardar los empleados\n");
            }
            break;
        case 10:
            ll_deleteLinkedList(listaEmpleados);
            break;
        case 11:
            printf("Confirma salida? Presione s para si o n para no: ");
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
    }
    while(seguir == 's');

    return 0;
}
