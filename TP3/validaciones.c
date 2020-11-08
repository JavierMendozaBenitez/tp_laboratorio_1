#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);


/** \brief Chequea que sea un entero
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return int Retorna 0 (EXITO) si se obtiene un numero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)//transforma a entero
{
    int retorno = -1;
    char buffer[4096];

    if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
    {
        retorno = 0;
        *pResultado = atoi(buffer);
    }
    return retorno;
}

/** \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'longitud - 1' caracteres.
 *
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int myGets(char* cadena, int longitud)//toma el dato del teclado y evita que desborde
{
    //char buffer[4096];
    //fflush(stdin);
    //scanf("%s", buffer);
    //strncpy(cadena, buffer, longitud);

    fflush(stdin);
    fgets(cadena, longitud, stdin);

    cadena[strlen(cadena)-1] = '\0';

    return 0;
}

/** \brief Verifica si la cadena ingresada es numerica
 *
 * \param cadena char* Cadena de caracteres a ser a analizada
 * \return int Retorna 1 (VERDADERO) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esNumerica(char* cadena)//chequea que sea un caracter del 0 al 9
{
    int retorno = 1;
    int i = 0;

    if(cadena[0] == '-')
    {
        i = 1;
    }

    for( ; cadena[i] != '\0'; i++)
    {
        if(cadena[i] > '9' || cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;//Si devuelve 0 no es un numero
}

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int retorno = -1;
    int buffer;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                reintentos--;
                printf("%s", mensajeError);
            }
        }
        while(reintentos >= 0);

    }
    return retorno;
}

//if(utn_getNumero(&edad,"Edad?\n","Error la edad debe ser desde 0 a 199\n", 0, 199, 2)==0)
//if(utn_getNumeroFlotante(&opcion, "Ingrese un flotante\n", "Error, debe ser un flotante.\n", 0.1, 10.2,4)==0);
//if(utn_getCaracter(&letra,"Letra?\n","Error la letra debe ser desde A a J\n",'A','J',1)==0);

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
    int retorno = -1;
    char bufferChar;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &bufferChar);
            if(bufferChar >= minimo && bufferChar <= maximo)
            {
                *pResultado = bufferChar;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }
        while(reintentos >=  0);

    }
    return retorno;
}

int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
    int retorno = -1;
    float bufferFloat;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%f", &bufferFloat);
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }
        while(reintentos >=  0);

    }
    return retorno;
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
    char auxCad[100];

    puts(mensaje);
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad) >= tamanio/* || (soloLetras(auxCad) == 0)*/)//comentado por si nqueres recibir numeros y letras como char
    {
        printf("Nombre demasiado largo o con caracteres erroneos. Reingrese nombre: ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(cadena, auxCad);

}

int utn_getNumeroConScanf(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
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
                reintentos--;
            }
        }
        while(reintentos >=  0);

    }
    return retorno;
}

char menuChar()
{
    char opcion;
    system("cls");

    printf("*** ABM Personas ***\n\n");
    printf("a Alta\n");
    printf("b Baja\n");
    printf("c Modificacion\n");
    printf("d Listar Personas\n");
    printf("e Ordenar\n");
    printf("f Listar Deportes\n");
    printf("g Listar personas de un deporte\n");
    printf("h Listar personas de todos los deportes\n");
    printf("i Contar personas de un deporte\n");
    printf("j Deporte Favorito\n");
    printf("y Informes\n");
    printf("z Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    //opcion = toupper(getchar());

    return opcion;
}

int menuInt()
{
    int opcion;
    system("cls");

    printf("*** ABM Empleados ***\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10 Destruir el Linkedlist\n");
    printf("11 Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
