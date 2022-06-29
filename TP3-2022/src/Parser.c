/*
 * parser.c
 *
 *  Created on: 9 jun. 2022
 *      Author: Monsalbo Lucio
*/

#include <stdio.h>
#include <string.h>
#include "Pasajero.h"
#include "LinkedList.h"

/******************************************************************************************************
											PARSEO TEXTO
 ******************************************************************************************************/
int parser_PasajeroDesdeTexto(FILE* pArchivo , LinkedList* pArrayListPassenger)
{
	ePasajero* pPasajero;

	char id[5];
	char nombre[50];
	char apellido[50];
	char precio[6];
	char tipoPasajero[30];
	char codigoVuelo[7];
	char estado[20];

	int numeroScanf;

	fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]/n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estado);//falsa lectura para el titulo

	do{
		numeroScanf = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]/n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estado);
		if(numeroScanf == 7)
		{

			pPasajero = ePasajero_newParametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estado);

			ll_add(pArrayListPassenger,(ePasajero*) pPasajero);
		}
	}while(!feof(pArchivo));

	return 1;
}

/******************************************************************************************************
										  PARSEO BINARIO
 ******************************************************************************************************/
int parser_PasajeroDesdeBinadio(FILE* pArchivo , LinkedList* pArrayListPassenger)
{
    int retorno;

    retorno = -1;

    ePasajero* auxPasajero;

    if(pArchivo != NULL && pArrayListPassenger != NULL)
    {
        while(!feof(pArchivo))
        {
            auxPasajero = ePasajero_new();

            fread(auxPasajero,sizeof(ePasajero),1,pArchivo);

            ll_add(pArrayListPassenger,auxPasajero);
        }
        retorno = 0;
    }
    return retorno;
}


int parsearEstadoPasajeroAEstructura(char estado[])
{
	int retorno;

	retorno = 0;

	if(strcmp(estado,"En horario"))
	{
		retorno = 1;
	}else{
		if(strcmp(estado,"Aterrizado"))
		{
			retorno = 2;
		}else{
			if(strcmp(estado,"Demorado"))
			{
				retorno = 3;
			}else{
				if(strcmp(estado,"Baja"))
				{
					retorno = 4;
				}
				retorno = -1;
			}
		}
	}
	return retorno;
}


int parsearEstadoPasajeroDesdeEstrutura(char estado[], ePasajero aux)
{
	int retorno;

	retorno = 0;

	switch(aux.estado)
	{
	case 1:
		strcpy(estado,"En horario");
		break;
	case 2:
		strcpy(estado,"Aterrizado");
		break;
	case 3:
		strcpy(estado,"Demorado");
		break;
	case 4:
		strcpy(estado,"Baja");
		break;
	default:
		retorno = -1;
		break;
	}
	return retorno;
}


int parsearTipoPasajeroAEstructura(char tipoPasajero[])
{
	int retorno;

	retorno = 0;

	if(strcmp(tipoPasajero,"EconomyClass"))
	{
		retorno = 1;
	}else{
		if(strcmp(tipoPasajero,"FirstClass"))
		{
			retorno = 2;
		}else{
			if(strcmp(tipoPasajero,"ExecutiveClass"))
			{
				retorno = 3;
			}else{
				retorno = -1;
			}
		}
	}
	return retorno;
}


int parsearTipoPasajeroDesdeEstrutura(char tipoPasajero[], ePasajero aux)
{
	int retorno;

	retorno = 0;

	switch(aux.tipoPasajero)
	{
	case 1:
		strcpy(tipoPasajero,"EconomyClass");
		break;
	case 2:
		strcpy(tipoPasajero,"FirstClass");
		break;
	case 3:
		strcpy(tipoPasajero,"ExecutiveClass");
		break;
	default:
		retorno = -1;
		break;
	}
	return retorno;
}
