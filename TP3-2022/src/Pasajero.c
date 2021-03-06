/*
 * Pasajero.c
 *
 *  Created on: 9 jun. 2022
 *      Author: Monsalbo Lucio
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Pasajero.h"
#include "Monsalbo.h"
#include "Parser.h"

/******************************************************************************************************
											Nuevo
 ******************************************************************************************************/

ePasajero* ePasajero_new()
{
    ePasajero* this = (ePasajero*) malloc(sizeof(ePasajero));
    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre,"");
        strcpy(this->apellido,"");
        this->precio = 0;
        this->tipoPasajero = 0;
        strcpy(this->codigoVuelo,"");
        this->estado = 0;
    }
    return this;
}

/******************************************************************************************************

 ******************************************************************************************************/

ePasajero* ePasajero_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoStr)
{
    ePasajero* retorno = NULL;
    ePasajero* pPasajero;
    int id;
    int precio;
    int estado;
    int tipoPasajero;

    if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoStr != NULL)
    {

        id = atoi(idStr);

        //NOMBRE Y APELLIDO YA SON CHAR[]

        precio = atoi(precioStr);

        tipoPasajero = parsearTipoPasajeroAEstructura(tipoPasajeroStr);

        estado = parsearEstadoPasajeroAEstructura(estadoStr);

        pPasajero = ePasajero_new();

        if(pPasajero != NULL)
        {
            ePasajero_setId(pPasajero,id);
            ePasajero_setNombre(pPasajero,nombreStr);
            ePasajero_setApellido(pPasajero,apellidoStr);
            ePasajero_setPrecio(pPasajero,precio);
            ePasajero_setTipoPasajero(pPasajero,tipoPasajero);
            ePasajero_setCodigoVuelo(pPasajero,codigoVueloStr);
            ePasajero_setEstado(pPasajero,estado);

            retorno = pPasajero;
        }
    }
    return retorno;
}
/******************************************************************************************************
											Borrar
 ******************************************************************************************************/
void ePasajero_delete(ePasajero* this)
{
    free(this);
}

/******************************************************************************************************
											  ID
 ******************************************************************************************************/

int ePasajero_setId(ePasajero* this,int id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}


int ePasajero_getId(ePasajero* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
											Nombre
 ******************************************************************************************************/

int ePasajero_setNombre(ePasajero* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}


int ePasajero_getNombre(ePasajero* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
											Apellido
 ******************************************************************************************************/

int ePasajero_setApellido(ePasajero* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL && soloLetras(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno = 0;
    }
    return retorno;
}
int ePasajero_getApellido(ePasajero* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strcpy(apellido,this->apellido);
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
											Codigo
 ******************************************************************************************************/

int ePasajero_setCodigoVuelo(ePasajero* this,char* codigoVuelo)
{
    int retorno = -1;
    if(this != NULL && codigoVuelo != NULL)
    {
        strcpy(this->codigoVuelo,codigoVuelo);
        retorno = 0;
    }
    return retorno;
}
int ePasajero_getCodigoVuelo(ePasajero* this,char* codigoVuelo)
{
    int retorno = -1;
    if(this != NULL && codigoVuelo != NULL)
    {
        strcpy(codigoVuelo,this->codigoVuelo);
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
										Tipo Pasajero
 ******************************************************************************************************/

int ePasajero_setTipoPasajero(ePasajero* this,int tipoPasajero)
{
    int retorno = -1;
    if(this != NULL && tipoPasajero < 4 && tipoPasajero > 0)
    {
        this->tipoPasajero = tipoPasajero;
        retorno = 0;
    }
    return retorno;
}
int ePasajero_getTipoPasajero(ePasajero* this,int* tipoPasajero)
{
    int retorno = -1;
    if(this != NULL && tipoPasajero != NULL)
    {
        *tipoPasajero = this->tipoPasajero;
        retorno = 0;
    }
    return retorno;
}

/******************************************************************************************************
											Precio
 ******************************************************************************************************/

int ePasajero_setPrecio(ePasajero* this,float precio)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}
int ePasajero_getPrecio(ePasajero* this,float* precio)
{
    int retorno = -1;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno = 0;
    }
    return retorno;
}
/******************************************************************************************************
											Estado
 ******************************************************************************************************/

int ePasajero_setEstado(ePasajero* this,int estado)
{
    int retorno = -1;
    if(this != NULL && estado >= 0)
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}
int ePasajero_getEstado(ePasajero* this, int* estado)
{
    int retorno = -1;
    if(this != NULL && estado != NULL)
    {
        *estado = this->estado;
        retorno = 0;
    }
    return retorno;
}


int mostrarUnPasajero(LinkedList* pArrayListPassenger, int index)
{
	ePasajero* pasajero = NULL;

	int retorno;

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int estado;

	retorno = -1;

	pasajero = (ePasajero*) ll_get(pArrayListPassenger, index);

	if(!(validacion_gets(pasajero, &id, nombre, apellido, &precio, &tipoPasajero, codigoVuelo, &estado)))
	{
		printf("%d      %s      %s      %f.2       %d        %s      %d\n",id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estado);

		retorno = 0;
	}
	return retorno;
}


void mostrarPasajeros(LinkedList* pArrayListPassenger)
{
	int tam;
	int i;

	tam = ll_len(pArrayListPassenger);

	printf("Listado de Pasajeros:\n"
			"-ID-------Nombre-------Apellido-------Precio-------Tipo-------Codigo-------Estado-\n");

	if(tam > 0)
	{
		for(i = 0 ; i < tam ; i++)
		{
			if(!mostrarUnPasajero(pArrayListPassenger, i))
			{
				printf("error al cargar el pasajero en la pocision N?? %d\n", i);
			}
		}
	}
}


int validacion_gets(ePasajero* pasajero, int* id, char nombre[], char apellido[], float* precio, int* tipoPasajero, char codigoVuelo[], int* estado)
{
	int retorno;

	retorno = -1;

	if(pasajero != NULL && id != NULL && nombre != NULL && apellido != NULL && precio != NULL && tipoPasajero != NULL && codigoVuelo!= NULL
			&& estado != NULL)
	{
		if((!(ePasajero_getId(pasajero,id)) &&
				!(ePasajero_getNombre(pasajero,nombre)) &&
				!(ePasajero_getApellido(pasajero,apellido)) &&
				!(ePasajero_getPrecio(pasajero,precio)) &&
				!(ePasajero_getTipoPasajero(pasajero,tipoPasajero)) &&
				!(ePasajero_getCodigoVuelo(pasajero,codigoVuelo)) &&
				!(ePasajero_getEstado(pasajero,estado))))
		{
			retorno = 0;
		}
	}

	return retorno;
}


int buscarPorId(LinkedList* pArrayListPassenger, int id)
{
	int tam;
	int i;
	int contador;
	int retorno;
	int idAux;

	contador = 0;

	ePasajero* pasajero;

	tam = ll_len(pArrayListPassenger);

	if(tam > 0)
		{
			for(i = 0 ; i < tam ; i++)
			{
				pasajero = (ePasajero*) ll_get(pArrayListPassenger, i);

				ePasajero_getId(pasajero,&idAux);

				if(idAux == id)
				{
					retorno = contador;
				}else{
					contador++;
				}
			}
		}
	return retorno;
}
