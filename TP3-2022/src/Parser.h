/*
 * parser.h
 *
 *  Created on: 9 jun. 2022
 *      Author: Monsalbo Lucio
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include "Pasajero.h"
#include "LinkedList.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PasajeroDesdeTexto(FILE* pArchivo , LinkedList* pArrayListPassenger);


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PasajeroDesdeBinadio(FILE* pFile , LinkedList* pArrayListPassenger);


/** \brief Cambia texto por el numero del estado del pasajero
 *
 * @param tipoPasajero
 *
 * @return 0 = OK    -1 = FALLO   != ID Estado
 */
int parsearEstadoPasajeroAEstructura(char estado[]);


/** \brief Cambia numero por texto del estado del pasajero
 *
 * @param isEmpty
 * @param aux
 *
 * @return 0 = OK    -1 = FALLO
 */
int parsearEstadoPasajeroDesdeEstrutura(char estado[], ePasajero aux);

/** \brief Cambia texto por numero de tipo de pasajero
 *
 * @param tipoPasajero
 *
 * @return 0 = OK    -1 = FALLO   != ID Tipo
 */
int parsearTipoPasajeroAEstructura(char tipoPasajero[]);


/** \brief Cambia numero por texto del tipo de pasajero
 *
 * @param tipoPasajero
 * @param aux
 *
 * @return 0 = OK    -1 = FALLO
 */
int parsearTipoPasajeroDesdeEstrutura(char tipoPasajero[], ePasajero aux);

#endif /* PARSER_H_ */
