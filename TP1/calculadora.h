#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED



#endif // CALCULADORA_H_INCLUDED

/** \brief Valida un numero entre 1 y 5.
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

/** \brief Devuelve la suma de los parametros.
 *
 * \param operando1 int Primer operando.
 * \param operando2 int Segundo operando.
 * \return int Devuelve el resultado de la suma.
 *
 */

int suma(int operando1, int operando2);

/** \brief Devuelve la resta de los parametros.
 *
 * \param operando1 int Primer operando.
 * \param operando2 int Segundo operando.
 * \return int Devuelve el resultado de la resta.
 *
 */
int resta(int operando1, int operando2);

/** \brief Devuelve la division de los parametros.
 *
 * \param pResultadoDivision float* Es el resultado de la division.
 * \param operando1 int Es el operando 1.
 * \param operando2 int Es el operando 2.
 * \return int Devuelve 0 si la operacion se hizo.
 *
 */
int division(float* pResultadoDivision, int operando1, int operando2);

/** \brief Devuelve la multiplicacion de los parametros.
 *
 * \param operando1 int Es el operando 1.
 * \param operando2 int Es el operando 2.
 * \return int Devuelve el resultado de la multiplicacion.
 *
 */
int multiplicacion(int operando1, int operando2);


/** \brief Devuelve el factorial.
 *
 * \param pFact Devuelve el resultado.
 * \param operando1 Es el operando que utiliza.
 * \return int Devuelve 0 si se hizo correctamente.
 *
 */
int factorial (int* pFact, int operando1);
