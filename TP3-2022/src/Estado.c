/*
 * Estado.c
 *
 *  Created on: 9 jun. 2022
 *      Author: UGIO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Estado.h"
#include "Pasajero.h"

eEstado iniciarEstado(void)// En Horario  Aterrizado  Demorado
{
	eEstado estructuraEstado =
	{
			{1,"En Horario"},
			{2,"Aterrizado"},
			{3,"Demorado"},
			{4,"Baja"}
	};

	return estructuraEstado;
}

int parsearEstadoPasajeroAEstructura(char estado[], eEstado estructuraEstado[])
{
	int retorno;

	retorno = 0;

	if(strcmp(estado,estructuraEstado[1].estadoChar))
	{
		retorno = estructuraEstado[1].estadoInt;
	}else{
		if(strcmp(estado,estructuraEstado[2].estadoChar))
		{
			retorno = estructuraEstado[2].estadoInt;
		}else{
			if(strcmp(estado,estructuraEstado[3].estadoChar))
			{
				retorno = estructuraEstado[3].estadoInt;
			}else{
				retorno = -1;
			}
		}
	}
	return retorno;
}


int parsearEstadoPasajeroDesdeEstrutura(char estado[], ePasajero aux,eEstado estructuraEstado[])
{
	int retorno;

	retorno = 0;

	switch(aux.estado)
	{
	case 1:
		strcpy(estado,estructuraEstado[1].estadoChar);
		break;
	case 2:
		strcpy(estado,estructuraEstado[2].estadoChar);
		break;
	case 3:
		strcpy(estado,estructuraEstado[3].estadoChar);
		break;
	default:
		retorno = -1;
		break;
	}
	return retorno;
}
