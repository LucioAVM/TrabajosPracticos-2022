/*
 ============================================================================
 Name        : TP3-2022.c
 Author      : Monsalbo Lucio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Pasajero.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Usuario.h"
#include "Pasajero.h"
#include "LinkedList.h"

#define TAM 10

int main()
{
	setbuf(stdout,NULL);

    int option = 0;
    char path[25];

    LinkedList* pArrayListPassenger = ll_newLinkedList();

    do{
    	option = mostrarMenu();

        switch(option)
        {
            case 1:
            	printf("ingrese el nombre del archivo que desea cargar\n");
            	fflush(stdout);
            	scanf("%s",path);
            	controller_cargarDesdeTexto(path , pArrayListPassenger);
                 break;
            case 2:
            	printf("ingrese el nombre del archivo que desea cargar\n");
            	fflush(stdout);
            	scanf("%s",path);
            	controller_cargarDesdeBinario(path , pArrayListPassenger);
                break;
            case 3:
            	controller_altaPasajero(pArrayListPassenger);
                break;
            case 4:
            	controller_modificarPasajero(pArrayListPassenger);
                break;
            case 5:
            	controller_bajaPasajero(pArrayListPassenger);
                break;
            case 6:
            	controller_ListarPasajeros(pArrayListPassenger);
                break;
            case 7:
            	controller_ordenarPasajeros(pArrayListPassenger);
                break;
            case 8:
            	controller_GuardarComoTexto(path ,pArrayListPassenger);
                break;
            case 9:
            	controller_GuardarComoBinario(path , pArrayListPassenger);
                break;
            case 10:
            	printf( "\n           GRACIAS POR UTILIZAR ESTE PROGRAMA\n"
            		"             PRODUCIDO POR Monsalbo lucio\n"
					"              EDITADO POR Lucio Monsalbo\n"
					"         BUILDEADO POR Alejandro Lucio Monsalbo\n"
					"        TESTEADO POR Valerio Alejandro Monsalbo\n"
					"        ENVIADO POR Monsalbo Lucio Alejandro Valerio\n"
					"   AGRADECIMIENTO ESPECIAL A Lucio Alejandro Valerio Monsalbo\n");
                break;
        }
    }while(option != 10);

    return EXIT_SUCCESS;
}
