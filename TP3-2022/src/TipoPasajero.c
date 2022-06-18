/*
 * TipoPasajero.c
 *
 *  Created on: 9 jun. 2022
 *      Author: UGIO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Pasajero.h"
#include "tipoPasajero.h"

eTipoPasajero iniciarTipoPasajero(void)
{
	eTipoPasajero estructuraTipoPasajero =
	{
			{1,"EconomyClass"},
			{2,"FirstClass"},
			{3,"ExecutiveClass"}
	};

	return estructuraTipoPasajero;
}

int parsearTipoPasajeroAEstructura(char tipoPasajero[],eTipoPasajero estructuraTipoPasajero[])
{
	int retorno;

	retorno = 0;

	if(strcmp(tipoPasajero,estructuraTipoPasajero[1].tipoPasajeroChar))
	{
		retorno = estructuraTipoPasajero[1].tipoPasajeroInt;
	}else{
		if(strcmp(tipoPasajero,estructuraTipoPasajero[2].tipoPasajeroChar))
		{
			retorno = estructuraTipoPasajero[2].tipoPasajeroInt;
		}else{
			if(strcmp(tipoPasajero,estructuraTipoPasajero[3].tipoPasajeroChar))
			{
				retorno = estructuraTipoPasajero[3].tipoPasajeroInt;
			}else{
				retorno = -1;
			}
		}
	}
	return retorno;
}


int parsearTipoPasajeroDesdeEstrutura(char tipoPasajero[], ePasajero aux,eTipoPasajero estructuraTipoPasajero[])
{
	int retorno;

	retorno = 0;

	switch(aux.tipoPasajero)
	{
	case 1:
		strcpy(tipoPasajero,estructuraTipoPasajero[1].tipoPasajeroChar);
		break;
	case 2:
		strcpy(tipoPasajero,estructuraTipoPasajero[2].tipoPasajeroChar);
		break;
	case 3:
		strcpy(tipoPasajero,estructuraTipoPasajero[3].tipoPasajeroChar);
		break;
	default:
		retorno = -1;
		break;
	}
	return retorno;
}