/*
 * parser.c
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

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int parser_PasajeroDesdeTexto(FILE* pArchivo , LinkedList* pArrayListPassenger[])
{
	ePasajero pPasajero;

	char id[5];
	char nombre[50];
	char apellido[50];
	char precio[6];
	char tipoPasajero[30];
	char codigoVuelo[7];
	char estado[20];

	int numeroScanf;

	fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]/n");//falsa lectura para el titulo

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

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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
