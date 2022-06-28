/*
 * controller.c
 *
 *  Created on: 9 jun. 2022
 *      Author: UGIO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Pasajero.h"
#include "Pasajero.h"
#include "Usuario.h"


/************************************************************************************************************
 *                                            MENU															*
 * 																											*
 ************************************************************************************************************/
int mostrarMenu(void)
{
	int menu;
	int bandera;

	bandera = 0;

	do
	{
		if(bandera > 0)
		{
			printf("\nError, ingrese una opcion valida:/n/n");
		}
		printf("       Menu Pasajeros/n"
			   "       --------------/n/n"
		     "1. Cargar datos en texto/n"
		     "2. Cargar datos en binario/n"
		     "3. Alta/n"
		     "4. Modificar/n"
		     "5. Baja/n"
		     "6. Listar/n"
		     "7. Ordenar/n"
		     "8. Guardar datos en texto/n"
		     "9. Guardar datos en binario/n"
		    "10. Salir/n"
		    "/t/tOpcion:");
			fflush(stdout);
			scanf("%d",&menu);

			bandera++;
	}while(menu <= 10 && menu >= 1 );

	return menu;
}



/************************************************************************************************************
 *                                           OPCION															*
 * 											    1															*
 ************************************************************************************************************/
int controller_cargarDesdeTexto(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo = NULL;

	pArchivo = fopen(path,"r");

	if(pArchivo == NULL)
	{
		printf("error");
	}else{
		parser_PasajeroDesdeTexto(pArchivo, pArrayListPassenger);
	}
	fclose(pArchivo);

    return 1;
}



/************************************************************************************************************
 *                                           OPCION															*
 * 											    2															*
 ************************************************************************************************************/
int controller_cargarDesdeBinario(char* path , LinkedList* pArrayListPassenger)
{
    int retorno;

    retorno = -1;

    FILE* pArchivo;

    if(path != NULL && pArrayListPassenger != NULL)
    {
    	pArchivo = fopen(path,"rb");
        if(pArchivo != NULL)
        {
            retorno = parser_PasajeroDesdeBinadio(pArchivo,pArrayListPassenger);
            fclose(pArchivo);
        }
    }
    return retorno;
}



/************************************************************************************************************
 *                                           OPCION															*
 * 											    3															*
 ************************************************************************************************************/
int controller_altaPasajero(LinkedList* pArrayListPassenger)
{
	ePasajero* pasajero;

	int id;
	char nombre[50];
	char apellido[50];
	char precio[10];
	char tipoPasajero[10];
	char codigoVuelo[4];
	char estado[10];

	int retorno;

	pasajero = NULL;
	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
			id = cargar_nuevoId(pArrayListPassenger);

			pasajero = ePasajero_newParametros((char*)id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estado);

			ll_add(pArrayListPassenger, pasajero);

			retorno = 0;
	}
    return retorno;
}



/************************************************************************************************************
 *                                           OPCION															*
 * 											    4															*
 ************************************************************************************************************/
int controller_modificarPasajero(LinkedList* pArrayListPassenger)
{
    int retorno;
    int id;
    int opcion;
    char nombre[50];
    char apellido[50];
    char codigoVuelo[4];
    int tipoPasajero;
    float precio;
    int estado;


    char tipoPasajeroStr[3];
    char precioStr[5];
    char estadoStr[3];

    retorno = -1;

    ePasajero* auxPasajero;

    if(pArrayListPassenger != NULL)
    {
        printf("/nIngrese el id del pasajero a modificar: ");
        scanf("%d",&id);
        id = buscarUsuarioPorId(pArrayListPassenger,id);
        if(id != -1)
        {
        	printf( "/nMENU MODIFICACION PASAJEROS/n"
        			"--------------------------/n"
        			"1- Nombre/n"
        			"2- Apellido/n"
        			"3- Precio/n"
        			"4- Tipo de Pasajero/n"
        			"5- Codigo de vuelo/n"
        			"6- Estado del vuelo/n"
        			"7- Salir/n");
            scanf("%d",&opcion);
            switch(opcion)
            {

            case 1:// NOMBRE
            	get_Nombre(nombre);
                ePasajero_setNombre(auxPasajero,nombre);
                break;


            case 2:// APELLIDO
            	get_Apellido(apellido);
                ePasajero_setApellido(auxPasajero,apellido);
                break;


            case 3:// PRECIO
            	get_Precio(precioStr);
            	precio = atof(precioStr);
            	ePasajero_setPrecio(auxPasajero,precio);
                break;


            case 4:// TIPO DE PASAJERO
            	get_TipoPasajero(tipoPasajeroStr);
            	tipoPasajero = parsearTipoPasajeroAEstructura(tipoPasajeroStr);
                ePasajero_setTipoPasajero(auxPasajero,tipoPasajero);
                break;


            case 5:// CODIGO DE VUELO
            	get_CodigoVuelo(codigoVuelo);
                ePasajero_setCodigoVuelo(auxPasajero,codigoVuelo);
                break;


            case 6:// ESTADO DEL VUELO
            	get_EstadoVuelo(estadoStr);
            	estado = parsearEstadoPasajeroAEstructura(estadoStr);
            	ePasajero_setEstado(auxPasajero,estado);
                break;
            }
            retorno = 0;
        }
    }
    return retorno;
}



/************************************************************************************************************
 *                                           OPCION															*
 * 											    5															*
 ************************************************************************************************************/
int controller_bajaPasajero(LinkedList* pArrayListPassenger)
{
    return 1;
}



/************************************************************************************************************
 *                                           OPCION															*
 * 											    6															*
 ************************************************************************************************************/
int controller_ListarPasajeros(LinkedList* pArrayListPassenger)
{
    return 1;
}



/************************************************************************************************************
 *                                           OPCION															*
 * 											    7															*
 ************************************************************************************************************/
int controller_ordenarPasajeros(LinkedList* pArrayListPassenger)
{
	int subMenu;

	printf("/nOpciones de ordenamiento:/n"
			"-------------------------/n"
			"1- Nombre/n"
			"2- Apellido/n"
			"3- Codigo de Vuelo/n"
			"Listar por: ");
	fflush(stdin);
	scanf("%s", &subMenu);

	switch(subMenu)
	{
	case 1:
		ll_sort(LinkedList* pArrayListPassenger, int (*pFunc)(void* ,void*), int order);
		break;
	case 2:
		break;
	case 3:
		break;
	}

    return 1;
}



/************************************************************************************************************
 *                                           OPCION															*
 * 											    8															*
 ************************************************************************************************************/
int controller_GuardarComoTexto(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;

	FILE* pArchivoTexto;
	ePasajero* pasajero;
	int tam;
	int i;

	retorno = -1;
	tam = ll_len(pArrayListPassenger);

	if(path != NULL && pArrayListPassenger !=NULL)
	{
		pArchivoTexto = fopen(path,"w");

		if(pArchivoTexto !=NULL)
		{
			for(i=0;i<tam;i++)
			{
				pasajero = (ePasajero*)ll_get(pArrayListPassenger,i);
				fwrite(pasajero,sizeof(ePasajero),1,pArchivoTexto);
			}
		}
		fclose(pArchivoTexto);
		retorno = 0;
	}
	return retorno;
}



/************************************************************************************************************
 *                                           OPCION															*
 * 											    9															*
 ************************************************************************************************************/
int controller_GuardarComoBinario(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	int tam;
	int i;

	FILE* pArchivoBinario;
	ePasajero* pasajero;

	retorno = -1;
	tam = ll_len(pArrayListPassenger);

	if(path != NULL && pArrayListPassenger !=NULL)
	{
		pArchivoBinario = fopen(path,"wb");

		if(pArchivoBinario !=NULL)
		{
			for(i=0;i<tam;i++)
			{
				pasajero = (ePasajero*)ll_get(pArrayListPassenger,i);
				fwrite(pasajero,sizeof(ePasajero),1,pArchivoBinario);
			}
		}
		fclose(pArchivoBinario);
		retorno = 0;
	}
    return retorno;
}
