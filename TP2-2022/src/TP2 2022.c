/*
 ============================================================================
 Name        : TP2 2022.c
 Author      : Monsalbo Lucio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Monsalbo.h"
#include "Pasajeros.h"
#include "Menu.h"

#define TAM 5//cambiar a 2000


int main(void)
{
	setbuf(stdout, NULL);

	int menu;
	int idPasajero;
	//int validacion;//cambiar nombre

	ePasajero listaPrincipalPasajeros[TAM];

	idPasajero = 0;

	if(ePasajeros_Inicializar(listaPrincipalPasajeros,TAM))
	{
		printf("Error al inicializar el programa, reiniciene intente nuevamente.\n");
	}

	menu = mostrarMenu();

	switch(menu)
	{
	case 1:
		if(AltaEmpleado(listaPrincipalPasajeros, TAM, &idPasajero))//si la funcion devuelve 0 es verdadero(usar para validar)
		{

		}
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		printf("1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n\n"
				"2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n\n"
				"3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n\n");
		fflush(stdin);
		scanf("%d", &menu);
		break;
	}

	return EXIT_SUCCESS;
}
