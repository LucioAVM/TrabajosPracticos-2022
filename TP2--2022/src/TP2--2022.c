/*
 ============================================================================
 Name        : TP2--2022.c
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

#define TAM 2000

int main(void)
{
	setbuf(stdout, NULL);

	int menu;
	int id;

	id = 0;

	ePasajero listaPrincipalPasajeros[TAM];

	if(ePasajeros_Inicializar(listaPrincipalPasajeros, TAM))
	{
		printf("Error al inicializar el programa, reiniciene eh intente nuevamente.\n");
	}

	do{
		menu = mostrarMenu();

		switch(menu)
		{
		case 1:
			if(altaPasajero(listaPrincipalPasajeros, TAM, &id))//si la funcion devuelve 0 es verdadero(usar para validar)
			{
				printf("\n-----Pasajero dado de alta exitosamente----\n");
			}else{
				printf("\nAh ocurrido un error, intente nuevamente\n");
			}
			break;

		case 2:
			if(modificarpasajero(listaPrincipalPasajeros, TAM))
			{
				printf("Pasajero se ah modificado exitosamente");
			}else{
				printf("Ah ocurrido un error, intente nuevamente");
			}
			break;

		case 3:
			if(bajaPasajero(listaPrincipalPasajeros, TAM))
			{
				printf("Pasajero se dado de baja exitosamente");
			}else{
				printf("Ah ocurrido un error, intente nuevamente");
			}
			break;

		case 4:
			ordenarPasajeros(listaPrincipalPasajeros, TAM);
			break;


		case 5:
			hardcodeoPasajeros(listaPrincipalPasajeros, &id);
			break;

		case 6:
			printf( "\n           GRACIAS POR UTILIZAR ESTE PROGRAMA\n"
									"             PRODUCIDO POR Monsalbo lucio\n"
									"              EDITADO POR Lucio Monsalbo\n"
									"         BUILDEADO POR Alejandro Lucio Monsalbo\n"
									"        TESTEADO POR Valerio Alejandro Monsalbo\n"
									"        ENVIADO POR Monsalbo Lucio Alejandro Valerio\n"
									"   AGRADECIMIENTO ESPECIAL A Lucio Alejandro Valerio Monsalbo\n");
			break;
		}
	}while(menu != 6);

	return EXIT_SUCCESS;
}
