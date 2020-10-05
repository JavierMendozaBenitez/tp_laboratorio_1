#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char sexo;
    float salario;
    int sector;
    int isEmpty;

} eEmpleado;


#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief Inicializa empleados
 *
 * \param gente[] eEmpleado es el array de tipo eEmpleado
 * \param tam int tamanio del array
 * \return int devuelve 0 si está vacio o 1 si está lleno
 *
 */
int initEmployees(eEmpleado gente[], int tam);

/** \brief muestra empleados
 *
 * \param gente[] eEmpleado es el array de tipo eEmpleado
 * \param tam int tamanio del array
 * \return int devuelve 0 si logo hacerlo o 1 si hubo algun error
 *
 */
int printEmployees(eEmpleado gente[], int tam);

/** \brief muestra 1 empleado
 *
 * \param unEmpleado eEmpleado variable de tipo eEmpleado
 * \return void no devuelve nada
 *
 */
void mostrarEmpleado(eEmpleado unEmpleado);

/** \brief busca lugares libres
 *
 * \param gente[] eEmpleado array de tipo eEmpleado
 * \param tam int tamanio del array
 * \return int devuelve el lugar libre
 *
 */
int buscarLibre(eEmpleado gente[], int tam);

/** \brief chequea que solo se ingresen letras
 *
 * \param cadena[] char colocas el array que quieras validar
 * \return int devuelve 0 si pudo hacerlo
 *
 */
int soloLetras(char cadena[]);

/** \brief valida que el largo de la cadena no sobrepase el limite estipulado y que el caracter ingresado sea alfabetico
 *
 * \param cadena[] char colocas el array que quieras validar
 * \param tamanio int tamanio del array
 * \param mensaje[] char mensaje para el usuario
 * \param errorMensaje[] char mensaje de error para el usuario si ingreso un caracter no alfabetico
 * \return void no devuelve nada
 *
 */
void largoCadena(char cadena[],int tamanio,char mensaje[],char errorMensaje[]);

/** \brief es para agregar empleados
 *
 * \param gente[] eEmpleado array de tipo empleado
 * \param tam int tamanio del array
 * \param id int ID del empleado
 * \return int devuelve  si pudo hacerlo o 1 si no pudo.
 *
 */
int addEmployee(eEmpleado gente[], int tam, int id);

/** \brief quita un empleado
 *
 * \param gente[] eEmpleado array de tipo eEmpleado
 * \param tam int tamanio del array
 * \return int devuelve 4 valores de errores
 *
 */
int removeEmployee(eEmpleado gente[], int tam);

/** \brief modific los datos de los empleados
 *
 * \param gente[] eEmpleado array de tipo eEmpleado
 * \param tam int tamanio del array
 * \return int devuelve 0 si se hixo correctamente
 *
 */
int modificarEmpleado(eEmpleado gente[], int tam);

/** \brief busca un empleado
 *
 * \param gente[] eEmpleado array de tipio eEmpleado
 * \param tam int tamanio del array
 * \param id int id del empleado
 * \return int devuelve el indice del empleado encontrado
 *
 */
int findEmployeeById(eEmpleado gente[], int tam, int id);

/** \brief ordena los empleados por apellido y si tienen el ismo apellido los ordena por sector
 *
 * \param gente[] eEmpleado array de tipo eEmpleado
 * \param tam int tamanio del array
 * \param criterioS int criterio de ordenamiento ascendente para el apellido
 * \param criterioA int criterio de ordenamiento ascendente para el sector
 * \return int devuelve 0 si se hizo correctamente
 *
 */
int sortEmployees(eEmpleado gente[], int tam, int criterioS, int criterioA);

/** \brief Valida un numero entre un minimo y un maximo.
 *
 * \param pResultado int* Guarda el valor de la opción que se ingresa.
 * \param mensaje char* Muestra un mensaje al  usuario.
 * \param mensajeError char* Muestra un mensaje de error si ingreso un valor erroneo.
 * \param minimo int Es el numero minimo que puede ingresar el usuario.
 * \param maximo int Es el numero maximo que puede ingresar el usuario.
 * \return int Devuelve 0 si el dato ingresado es correcto.
 *
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);

/** \brief cuenta la cantidad de empleados
 *
 * \param gente[] eEmpleado array de tipo empleado
 * \param tam int tamanio del array
 * \return float devuelve la cantidad de empleados
 *
 */
float cantidadEmpleados(eEmpleado gente[], int tam);

/** \brief acumula los salarios
 *
 * \param gente[] eEmpleado array de tipo eEmpleado
 * \param tam int tamanio del array
 * \return float devuelve los sueldos acumulados
 *
 */
float acumuladorSalario(eEmpleado gente[], int tam);

/** \brief calcula el promedio de los sueldos
 *
 * \param gente[] eEmpleado array de tipo eEmpleado
 * \param tam int tamanio del array
 * \return float devuelve el promedio de sueldos
 *
 */
float promedioSueldos(eEmpleado gente[], int tam);

/** \brief calcula los sueldos superiores al promedio
 *
 * \param gente[] eEmpleado array de tipo eEmpleado
 * \param tam int tamanio del array
 * \return float devuelve la cantidad de sueldos superiores al promedio
 *
 */
float sueldosSuperioresAlPromedio(eEmpleado gente[], int tam);
