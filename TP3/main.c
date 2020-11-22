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
    int flagLoadFromText = 0;
    int flagLoadFromBinary = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menuInt())
        {
        case 1:
            if(flagLoadFromBinary == 0)
            {
                if(controller_loadFromText("data.csv", listaEmpleados) != 0)
                {
                    printf("Problema para cargar los empleados\n");
                }
                else
                {
                    printf("Empleados cargados correctamente\n");
                    flagLoadFromText = 1;
                }
            }
            else
            {
                printf("Ya cargo el listado como binario, solo se puede cargar en Texto o Binario, si se cargan ambos se duplican.\n");
            }
            break;
        case 2:
            if(flagLoadFromText == 0)
            {
                if(controller_loadFromBinary("data.bin", listaEmpleados) != 0)
                {
                    printf("Problema para cargar los empleados\n");
                }
                else
                {
                    printf("Empleados cargados correctamente\n");
                    mostrarEmpleados(listaEmpleados);
                    flagLoadFromBinary = 1;
                }
            }
            else
            {
                printf("Ya cargo el listado como texto, solo se puede cargar en Texto o Binario, si se cargan ambos se duplican.\n");
            }
            break;
        case 3:
            if(flagLoadFromText == 1 || flagLoadFromBinary == 1)
            {
                if(controller_addEmployee(listaEmpleados) == 0)
                {
                    printf("Empleado agregado con exito\n\n");
                }
            }
            else
            {
                printf("Primero debe seleccionar la opcion 1 o 2.\n");
            }
            break;
        case 4:
            if(flagLoadFromText == 1 || flagLoadFromBinary == 1)
            {
                if(controller_editEmployee(listaEmpleados) == 0)
                {
                    printf("Empleado modificado con exito\n\n");
                }
            }
            else
            {
                printf("Primero debe seleccionar la opcion 1 o 2.\n");
            }
            break;
        case 5:
            if(flagLoadFromText == 1 || flagLoadFromBinary == 1)
            {
                if(controller_removeEmployee(listaEmpleados) == 0)
                {
                    printf("Empleado quitado con exito\n\n");
                }
            }
            else
            {
                printf("Primero debe seleccionar la opcion 1 o 2.\n");
            }
            break;
        case 6:
            if(flagLoadFromText == 1 || flagLoadFromBinary == 1)
            {
                if(controller_ListEmployee(listaEmpleados) == 0)
                {
                    printf("Empleados listados con exito\n\n");
                }
            }
            else
            {
                printf("Primero debe seleccionar la opcion 1 o 2.\n");
            }
            break;
        case 7:
            if(flagLoadFromText == 1 || flagLoadFromBinary == 1)
            {
                if(controller_sortEmployee(listaEmpleados) == 0)
                {
                    printf("Empleados ordenados con exito\n\n");
                }
            }
            else
            {
                printf("Primero debe seleccionar la opcion 1 o 2.\n");
            }
            break;
        case 8:
            if(flagLoadFromText == 1 || flagLoadFromBinary == 1)
            {
                if(controller_saveAsText("data.csv", listaEmpleados) == 0)
                {
                    printf("Listas en texto realizadas con exito\n\n");
                }
                else
                {
                    printf("Problema para guardar los empleados\n");
                }
            }
            else
            {
                printf("Primero debe seleccionar la opcion 1 o 2.\n");
            }
            break;
        case 9:
            if(flagLoadFromText == 1 || flagLoadFromBinary == 1)
            {
                if(controller_saveAsBinary("data.bin", listaEmpleados) == 0)
                {
                    printf("Listas en binario realizadas con exito\n\n");
                }
                else
                {
                    printf("Problema para guardar los empleados\n");
                }
            }
            else
            {
                printf("Primero debe seleccionar la opcion 1 o 2.\n");
            }
            break;
        case 10:
            if(flagLoadFromText == 1 || flagLoadFromBinary == 1)
            {
                ll_deleteLinkedList(listaEmpleados);
                printf("LinkedList borrado, si quiere continuar debe presionar la opcion del menu 1 o 2.\n");
                flagLoadFromText = 0;
                flagLoadFromBinary = 0;
            }
            else
            {
                printf("Primero debe seleccionar la opcion 1 o 2.\n");
            }
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
