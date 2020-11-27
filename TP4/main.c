#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

void leerTexto(char* path, LinkedList* lista);
void escribirTexto(char* path, LinkedList* lista);
int filtrarHoras(void* elemento);
int filtrarSueldo(void* elemento);

int main()
{
    LinkedList* lista = ll_newLinkedList();
    if(lista != NULL)
    {
        printf("\n\n*******************************ll_newLinkedList*********************************\n\n");
        leerTexto("listaEmpleados.csv", lista);
        mostrarEmpleados(lista);
    }



    int len = ll_len(lista);

    if(len != -1)
    {
        printf("\n\n*******************************ll_len***************************************\n\n");
        printf("El tamanio de la lista devuelto por ll_len() debe ser 5 y es: %d: \n\n", len);
    }



    Employee* empGet = employee_new();
    empGet = (Employee*)ll_get(lista, 2);

    if(empGet != NULL)
    {
        printf("\n\n*******************************ll_get***************************************\n\n");
        printf("Utilice el ll_get() para conseguir el elemento de indice 2 que es el siguiente:\n\n");
        mostrarEmpleado(empGet);
    }



    Employee* empSet = employee_new();

    if(empSet != NULL)
    {
        empSet->id = 1005;
        strcpy(empSet->nombre, "Raul");
        empSet->horasTrabajadas = 44;
        empSet->sueldo = 550000;
    }

    if(!ll_set(lista, 1, empSet))
    {
        printf("\n\n*******************************ll_set***************************************\n\n");
        printf("Utilice el ll_set() para modificar el elemento de indice 1 que quedo asi:\n\n");

        mostrarEmpleados(lista);

    }



    if(!ll_remove(lista, 3))
    {
        printf("\n\n*******************************ll_remove************************************\n\n");
        printf("ll_remove() funciono, elimine el elemento de indice 3.\n\n");
        mostrarEmpleados(lista);
    }



    Employee* empIndex = employee_new();

    if(empIndex != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            empIndex = ll_get(lista, i);

            if(!(strcmp(empIndex->nombre, "Maria")))
            {
                printf("\n\n*******************************ll_indexOf***************************************\n\n");
                printf("Utilice el ll_indexOf() para buscar el indice del primer elemento que coincida con la busqueda del nombre Maria.\n\n");
                int tam = ll_indexOf(lista, empIndex);
                printf("Indice encontrado: %d \n", tam);
                mostrarEmpleado(empIndex);
                break;
            }
        }

    }



    Employee* empPush = employee_new();

    if(empPush != NULL)
    {
        empPush->id = 1022;
        strcpy(empPush->nombre, "Marcos");
        empPush->horasTrabajadas = 101;
        empPush->sueldo = 70000;

        printf("\n\n*******************************ll_push*******************************************\n\n");

        printf("\nUtilice el ll_push() para insertar un elemento en el indice 3, muestro los empleados antes del Push y si funciono, despues.\n\n");

        mostrarEmpleados(lista);

        if(!ll_push(lista, 3, empPush))
        {
            printf("\n\nFunciono el Push.\n\n");
            mostrarEmpleados(lista);
        }
        else
        {
            printf("\nProblema para hacer el push.");
        }
    }



    Employee* empPop = employee_new();
    empPop = ll_pop(lista, 2);

    if(empPop != NULL)
    {
        printf("\n\n*******************************ll_pop*******************************************\n\n");
        printf("Utilice el ll_pop() y muestro el elemento extraido del indice 2.\n\n");
        mostrarEmpleado(empPop);
        printf("\nMuestro que este elemento ya no esta en la lista.\n\n");
        mostrarEmpleados(lista);
    }



    if(ll_contains(lista, ll_get(lista, 3)))
    {
        printf("\n\n*******************************ll_contains**************************************\n\n");
        printf("Al entrar aca ll_contains encontro un elemento de indice 3 y lo muestro.\n\n");
        mostrarEmpleado(ll_get(lista, 3));
    }
    else
    {
        printf("no existe un elemento de indice 3\n\n");
    }

    printf("\nAhora intento encontrar un elemento de indice 10\n\n");
    if(ll_contains(lista, ll_get(lista, 10)))
    {
        printf("\n\n*******************************ll_contains**************************************\n\n");
        printf("Al entrar aca ll_contains encontro un elemento de indice 10 y lo muestro.\n\n");
        mostrarEmpleado(ll_get(lista, 10));
    }
    else
    {
        printf("\nNo existe un elemento de indice 10\n\n");
    }



    LinkedList* listaSubLidt = ll_newLinkedList();
    listaSubLidt = ll_subList(lista, 1, ll_len(lista));
    if(listaSubLidt != NULL)
    {
        printf("\n\n*******************************ll_subList***************************************\n\n");
        printf("Use ll_subList(), si entro aca es porque no es NULL y pude crear la nueva lista con los elementos de la Lista 1 desde el indice 1 hasta el final.\n\n");
        printf("Muestro la Lista 1\n\n");
        mostrarEmpleados(lista);
        printf("\n\nMuestro la lista creada por ll_subList\n\n");
        mostrarEmpleados(listaSubLidt);
    }



    LinkedList* listaClone = ll_newLinkedList();
    listaClone = ll_clone(lista);
    if(listaClone != NULL)
    {
        printf("\n\n*******************************ll_clone*****************************************\n\n");
        printf("Use ll_clone(), si entro aca es porque no es NULL y pude clonar la lista 1.\n\n");
        printf("Muestro la Lista 1\n\n");
        mostrarEmpleados(lista);
        printf("\n\nMuestro la lista clonada con ll_clone\n\n");
        mostrarEmpleados(listaClone);
    }


    LinkedList* lista2 = ll_newLinkedList();
    if(lista2 != NULL)
    {
        printf("\n\n*******************************Lista 2******************************************\n\n");
        printf("Creo una nueva lista, la cargo y la muestro. Esto es para usar el ll_containsAll.\n\n");
        leerTexto("listaEmpleados2.csv", lista2);
        mostrarEmpleados(lista2);
    }



    if(ll_containsAll(lista, lista2))
    {
        printf("\n\n*******************************ll_containsAll***********************************\n\n");
        printf("Use ll_containsAll(), si entro aca es porque todos los elementos de la lista 2 estan en la lista 1.\n\n");
        printf("Muestros la Lista 1\n\n");
        mostrarEmpleados(lista);
        printf("\n\nMuestros la Lista 2\n\n");
        mostrarEmpleados(lista2);
    }
    else
    {
        printf("\n\n*******************************ll_containsAll***********************************\n\n");
        printf("Use ll_containsAll(), si entro aca es porque no tienen los mismos elementos la lista 2 con respecto a la lista 1.\n\n");
        printf("Muestros la Lista 1\n\n");
        mostrarEmpleados(lista);
        printf("\n\nMuestros la Lista 2\n\n");
        mostrarEmpleados(lista2);
    }

    if(ll_containsAll(lista, listaClone))
    {
        printf("\n\n*******************************ll_containsAll***********************************\n\n");
        printf("Use ll_containsAll(), si entro aca es porque todos los elementos de la Lista Clonada estan en la Lista 1.\n\n");
        printf("Muestros la Lista 1\n\n");
        mostrarEmpleados(lista);
        printf("\n\nMuestros la Lista Clonada\n\n");
        mostrarEmpleados(listaClone);
    }
    else
    {
        printf("\n\n*******************************ll_containsAll***********************************\n\n");
        printf("Use ll_containsAll(), si entro aca es porque no tienen los mismos elementos la Lista Clonada con respecto a la Lista 1.\n\n");
        printf("Muestros la Lista 1\n\n");
        mostrarEmpleados(lista);
        printf("\n\nMuestros la Lista Clonada\n\n");
        mostrarEmpleados(listaClone);
    }



    printf("\n\n*******************************ll_sort******************************************\n\n");

    if(!ll_sort(lista, employeeSortById, 1))
    {
        printf("\n\nEmpleados ordenados por Id ascendente\n\n");
        mostrarEmpleados(lista);
    }

    if(!ll_sort(lista, employeeSortById, 0))
    {
        printf("\n\nEmpleados ordenados por Id descendente\n\n");
        mostrarEmpleados(lista);
    }

    if(!ll_sort(lista, employeeSortByName, 1))
    {
        printf("\n\nEmpleados ordenados por Nombre ascendente\n\n");
        mostrarEmpleados(lista);
    }

    if(!ll_sort(lista, employeeSortByName, 0))
    {
        printf("\n\nEmpleados ordenados por Nombre descendente\n\n");
        mostrarEmpleados(lista);
    }

    if(!ll_sort(lista, employeeSortByWorkHours, 1))
    {
        printf("\n\nEmpleados ordenados por Horas Trabajadas ascendente\n\n");
        mostrarEmpleados(lista);
    }

    if(!ll_sort(lista, employeeSortByWorkHours, 0))
    {
        printf("\n\nEmpleados ordenados por Horas Trabajadas descendente\n\n");
        mostrarEmpleados(lista);
    }

    if(!ll_sort(lista, employeeSortBySalary, 1))
    {
        printf("\n\nEmpleados ordenados por Sueldo ascendente\n\n");
        mostrarEmpleados(lista);
    }

    if(!ll_sort(lista, employeeSortBySalary, 0))
    {
        printf("\n\nEmpleados ordenados por Sueldo descendente\n\n");
        mostrarEmpleados(lista);
    }



    LinkedList* listaFiltrada = ll_newLinkedList();
    listaFiltrada = ll_filter(lista, filtrarHoras);
    if(listaFiltrada != NULL)
    {
        printf("\n\n*******************************ll_filter************************************\n\n");
        printf("ll_filter() funciono, arme una nueva lista con los filtros, en este caso cantidad de horas trabajadas superior a 30.\n\n");
        printf("Muestro lista sin filtrar:\n\n");
        mostrarEmpleados(lista);
        printf("\nMuestro lista nueva filtrada:\n\n");
        mostrarEmpleados(listaFiltrada);
    }

    listaFiltrada = ll_filter(lista, filtrarSueldo);
    if(listaFiltrada != NULL)
    {
        printf("\n\n*******************************ll_filter************************************\n\n");
        printf("ll_filter() funciono, arme una nueva lista con los filtros, en este caso sueldos superiores a 50000.\n\n");
        printf("Muestro lista sin filtrar:\n\n");
        mostrarEmpleados(lista);
        printf("\nMuestro lista nueva filtrada:\n\n");
        mostrarEmpleados(listaFiltrada);
    }



    if(lista != NULL)
    {
        printf("\n\n*******************************Guardo la lista antes de borrarla*************\n\n");
        escribirTexto("listaEmpleadosModificada.csv", lista);
        mostrarEmpleados(lista);
    }



    if(!ll_clear(lista))
    {
        printf("\n\n*******************************ll_clear*************************************\n\n");
        printf("ll_clear() funciono, elimine todos los elementos de la lista, solo deje el LinkedList.\n\n");
        mostrarEmpleados(lista);
    }



    int tamIsEmpty = ll_isEmpty(lista);
    if(tamIsEmpty)
    {
        printf("\n\n*******************************ll_isEmpty*************************************\n\n");
        printf("ll_isEmpty() funciono, despues de hacer el ll_clear si muestra 1 es que esta vacia.\n\n");
        printf("Valor: %d\n\n", tamIsEmpty);

        mostrarEmpleados(lista);
    }
    else
    {
        printf("\n\n*******************************ll_isEmpty*************************************\n\n");
        printf("ll_isEmpty() funciono, si no hice el ll_clear debe devolver 0, significa que esta cargada.\n\n");
        printf("Valor: %d\n\n", tamIsEmpty);

        mostrarEmpleados(lista);
    }



    if(!ll_deleteLinkedList(lista))
    {
        printf("\n\n*******************************ll_deleteLinkedList**************************\n\n");
        printf("ll_deleteLinkedList() funciono, elimine la lista.\n\n");
    }



    return 0;
}

void leerTexto(char* path, LinkedList* lista)
{

    Employee* auxEmpleado;
    char buffer[4][100];
    int cant;
    FILE* f;

    f = fopen(path, "r");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    while(!feof(f))
    {
        cant = fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        if(cant == 4)
        {
            auxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
            ll_add(lista, auxEmpleado);
            //printf("%d %s %d %d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
        }
        else
        {
            break;
        }
    }

    fclose(f);
}


void escribirTexto(char* path, LinkedList* lista)
{
    FILE* f;
    int len = ll_len(lista);
    f = fopen(path, "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i < len; i++)
    {
        fprintf(f, "%d,%s,%d,%d\n", ((Employee*)ll_get(lista, i))->id, ((Employee*)ll_get(lista, i))->nombre, ((Employee*)ll_get(lista, i))->horasTrabajadas, ((Employee*)ll_get(lista, i))->sueldo);
    }

    fclose(f);

}


int filtrarHoras(void* elemento)
{
    int rta = 0;
    Employee* e = (Employee*) elemento;

    if(e != NULL)
    {
        if(e->horasTrabajadas > 30)
        {
            rta = 1;
        }
    }

    return rta;
}

int filtrarSueldo(void* elemento)
{
    int rta = 0;
    Employee* e = (Employee*) elemento;

    if(e != NULL)
    {
        if(e->sueldo > 50000)
        {
            rta = 1;
        }
    }

    return rta;
}
