#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es el numero minimo a ser aceptado
 * \param maximo int Es el numero maximo a ser aceptado
 * \param reintentos int Es el numero de reintentos para el usuario
 * \return int Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es el numero minimo a ser aceptado
 * \param maximo int Es el numero maximo a ser aceptado
 * \param reintentos int Es el numero de reintentos para el usuario
 * \return int Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumeroConScanf(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado float* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo float Es el numero minimo a ser aceptado
 * \param maximo float Es el numero maximo a ser aceptado
 * \param reintentos int Es el numero de reintentos para el usuario
 * \return int Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

/** \brief Solicita una letra al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo char Es el numero minimo a ser aceptado
 * \param maximo char Es el numero maximo a ser aceptado
 * \param reintentos int Es el numero de reintentos para el usuario
 * \return int Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

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

/** \brief Menu de opciones char
 *
 * \return char devuelve el valor ingresado
 *
 */
char menuChar();

/** \brief Menu de opciones int
 *
 * \return int devuelve el valor ingresado
 *
 */
int menuInt();
