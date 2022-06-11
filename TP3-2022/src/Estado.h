/*
 * Estado.h
 *
 *  Created on: 9 jun. 2022
 *      Author: UGIO
 */

#ifndef ESTADO_H_
#define ESTADO_H_

#include "Pasajero.h"

typedef struct
{
	int  estadoInt;
	char estadoChar[11];
}eEstado;

/** \brief Inicia una estructura de 3 estados del pasajeros (anidada con ePasajeros)
 *
 * @return la estructura ya cargada de estado pasajero
 */
eEstado iniciarEstado(void);


/** \brief Cambia texto por el numero del estado del pasajero
 *
 * @param tipoPasajero
 * @param estructuraEstado
 *
 * @return 0 = OK    -1 = FALLO   != ID Estado
 */
int parsearEstadoPasajeroAEstructura(char estado[],eEstado estructuraEstado[]);


/** \brief Cambia numero por texto del estado del pasajero
 *
 * @param isEmpty
 * @param aux
 * @param estructuraEstado
 *
 * @return 0 = OK    -1 = FALLO
 */
int parsearEstadoPasajeroDesdeEstrutura(char estado[], ePasajero aux, eEstado estructuraEstado[]);

#endif /* ESTADO_H_ */
