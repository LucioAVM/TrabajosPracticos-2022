/*
 * TipoPasajero.h
 *
 *  Created on: 9 jun. 2022
 *      Author: UGIO
 */

#ifndef TIPOPASAJERO_H_
#define TIPOPASAJERO_H_

typedef struct
{
	int tipoPasajeroInt;
	char tipoPasajeroChar[30];
}eTipoPasajero;


/** \brief Inicia una estructura de 3 tipos de pasajeros (anidada con ePasajeros)
 *
 * @return la estructura ya cargada de tipo pasajero
 */
eTipoPasajero iniciarTipoPasajero(void);


/** \brief Cambia texto por numero de tipo de pasajero
 *
 * @param tipoPasajero
 * @param estructuraTipoPasajero
 *
 * @return 0 = OK    -1 = FALLO   != ID Tipo
 */
int parsearTipoPasajeroAEstructura(char tipoPasajero[],eTipoPasajero estructuraTipoPasajero[]);


/** \brief Cambia numero por texto del tipo de pasajero
 *
 * @param tipoPasajero
 * @param aux
 * @param estructuraTipoPasajero
 * @return 0 = OK    -1 = FALLO
 */
int parsearTipoPasajeroDesdeEstrutura(char tipoPasajero[], ePasajero aux,eTipoPasajero estructuraTipoPasajero[]);

#endif /* TIPOPASAJERO_H_ */
