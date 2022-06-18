/*
 * parser.h
 *
 *  Created on: 9 jun. 2022
 *      Author: UGIO
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include "LinkedList.h"
#include "Estado.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PasajeroDesdeTexto(FILE* pArchivo , LinkedList* pArrayListPassenger[]);


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PasajeroDesdeBinadio(FILE* pFile , LinkedList* pArrayListPassenger);

#endif /* PARSER_H_ */