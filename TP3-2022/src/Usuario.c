/*
 * Usuario.c
 *
 *  Created on: 10 jun. 2022
 *      Author: Monsalbo Lucio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"
#include "Monsalbo.h"


int altaDatosUsuario(char* id, char nombre[], char apellido[], char precio[], char tipoPasajero[], char codigoVuelo[], char estado[])
{
	int retorno;

	retorno = 0;

	//PIDE DATOS DEL PASAJERO AL USUARIO
	if(nombre != NULL && apellido != NULL && precio != NULL && tipoPasajero && codigoVuelo != NULL && estado != NULL)
	{
				   //NOMBRE
		get_Nombre(nombre);

				   //APELLIDO
		get_Apellido(apellido);

				//PRECIO DE VUELO
		get_Precio(precio);


				//TIPO DE PASAJERO
		get_TipoPasajero(tipoPasajero);


				//CODIGO DE VUELO
		get_CodigoVuelo(codigoVuelo);

				//ESTADO DEL VUELO
		get_EstadoVuelo(estado);
	}

	return retorno;
}

int cargar_nuevoId(LinkedList* pArrayListPassenger)
{
	ePasajero* auxPasajero;

    int retorno;
    int id;
    int i;
    int auxId;

    retorno = -1;
    for(i=0;i<ll_len(pArrayListPassenger);i++)
    {
        auxPasajero = ll_get(pArrayListPassenger,i);
        ePasajero_getId(auxPasajero,&auxId);
        if(auxId > id)
        {
            id = auxId;
        }
    }
    retorno = id + 1;

    return retorno;
}

int buscarUsuarioPorId(LinkedList* pArrayListPassenger,int id)
{
    ePasajero* auxPasajero;

    int retorno;
    int i;

    retorno = -1;
    if(pArrayListPassenger != NULL)
    {
        for(i=0;i<ll_len(pArrayListPassenger);i++)
        {
            auxPasajero = ll_get(pArrayListPassenger,i);
            if(ePasajero_getId(auxPasajero,&id) == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void get_Nombre(char* nombre)
{	int validacion;

	validacion = getStringLetras("\n\nIngresar nombre del pasajero:\t", nombre);
	if(validacion == -1)
	{
		printf("\n\nERROR, no se pudo establecer correctamente el nombre \n");

		strcpy(nombre,"");
	}
}

void get_Apellido(char* apellido)
{
	int validacion;

	validacion = getStringLetras("\n\nIngresar apellido del pasajero:\t", apellido);
	if(validacion == -1)
	{
		printf("\nERROR, no se pudo establecer correctamente el apellido \n");

		strcpy(apellido,"");
	}

}

float get_Precio(char* precioStr)
{
	float precio;
	int validacion;

	validacion = getSoloNumeros("\n\nIngresar precio del vuelo:\t","\nERROR, Ingresar precio del vuelo:\t", precioStr);
	if(validacion == -1)
	{
		printf("\nERROR, no se pudo establecer correctamente el precio \n");

		strcpy(precioStr,"");//comparar en setprecio y cambiar a 0
	}
	precio = atof(precioStr);
	return precio;
}

void get_TipoPasajero(char* tipoPasajero)
{
	int bandera;

	bandera = 0;

	do
	{
		printf("/ningrese el tipo de pasajero;/n"
				"-------------------------/n"
				" EconomyClass/n"
				" FirstClass/n"
				" ExecutiveClass/n"
				"Tipo de Pasajero: ");
		fflush(stdin);
		scanf("%s",tipoPasajero);

		if(!(strcmp(tipoPasajero,"EconomyClass")) && !(strcmp(tipoPasajero,"FirstClass"))
				&& !(strcmp(tipoPasajero,"ExecutiveClass")))
		{
			bandera = -1;
			printf("/nERROR, ingrese una de las 3 opciones validas/n");
		}
	}while(bandera != -1);

}

void get_CodigoVuelo(char* codigoVuelo)
{
	getString("\n\nIngrese codigo del vuelo: \t", codigoVuelo);
}

void get_EstadoVuelo(char* estado)
{
	int bandera;

	bandera = 0;

	do
	{
		printf("/ningrese el estado del vuelo;/n"
				"-------------------------/n"
				" En Horario/n"
				" Aterrizado/n"
				" Demorado/n"
				"Estado del vuelo: ");
		fflush(stdin);
		scanf("%s",estado);

		if(!(strcmp(estado,"En Horario")) && !(strcmp(estado,"En Aterrizado"))&&
				!(strcmp(estado,"En Demorado")))
		{
			bandera = -1;
			printf("/nERROR, ingrese una de las 3 opciones validas/n");
		}
	}while(bandera != -1);

}

int ordenarPasajeros_Nombre(void* pElement1, void* pElement2)
{
	int retorno;//1 o -1

	char str_1[25];
	char str_2[25];

	retorno = 0;//no hace nada en ll_sort

	if(!(ePasajero_getNombre(pElement1,str_1)) && !(ePasajero_getNombre(pElement2,str_2)))
	{
		retorno = strcmp(str_1,str_2);
	}

	return retorno;
}

int ordenarPasajeros_Apellido(void* pElement1, void* pElement2)
{
	int retorno;//1 o -1

	char str_1[25];
	char str_2[25];

	retorno = 0;//no hace nada en ll_sort

	if(!(ePasajero_getApellido(pElement1,str_1)) && !(ePasajero_getApellido(pElement2,str_2)))
	{
		retorno = strcmp(str_1,str_2);
	}

	return retorno;
}

int ordenarPasajeros_Codigo(void* pElement1, void* pElement2)
{
	int retorno;//1 o -1

	char str_1[25];
	char str_2[25];

	retorno = 0;//no hace nada en ll_sort

	if(!(ePasajero_getCodigoVuelo(pElement1,str_1)) && !(ePasajero_getCodigoVuelo(pElement2,str_2)))
	{
		retorno = strcmp(str_1,str_2);
	}

	return retorno;
}
