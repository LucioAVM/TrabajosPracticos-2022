/*
 * Usuario.c
 *
 *  Created on: 10 jun. 2022
 *      Author: UGIO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Monsalbo.h"

int altaDatosUsuario(char* id, char nombre[], char apellido[], char precio[], char tipoPasajero[], char codigoVuelo[], char estado[])
{
	int retorno;
	int menu;

	int validacionNombre;
	int validacionApellido;

	retorno = 0;

	//PIDE DATOS DEL PASAJERO AL USUARIO
	if(nombre != NULL && apellido != NULL && precio != NULL && tipoPasajero && codigoVuelo != NULL && estado != NULL)
	{
				   //NOMBRE
		nombre = validacionNombre();

				   //APELLIDO
		apellido = validacionApellido();

				//PRECIO DE VUELO
		precio = validacionPrecio();


				//TIPO DE PASAJERO
		tipoPasajero = tipoPasajero = validacionTipoPasajero();


				//CODIGO DE VUELO
		codigoVuelo = validacionCodigoVuelo();

				//ESTADO DEL VUELO
		estado = validacionEstadoVuelo();
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

char* validacionNombre()
{
	char nombre[];
	int validacion;

	validacion = getStringLetras("\n\nIngresar nombre del pasajero:\t", nombre);
	if(validacion == -1)
	{
		printf("\n\nERROR, no se pudo establecer correctamente el nombre \n");

		strcpy(nombre,"");
	}

	return nombre;
}

char* validacionApellido()
{
	char apellido[];
	int validacion;

	validacion = getStringLetras("\n\nIngresar apellido del pasajero:\t", apellido);
	if(validacion == -1)
	{
		printf("\nERROR, no se pudo establecer correctamente el apellido \n");

		strcpy(apellido,"");
	}

	return apellido;
}

char* validacionPrecio()
{
	char precio[];
	int validacion;

	validacion = getSoloNumeros("\n\nIngresar precio del vuelo:\t","\nERROR", "Ingresar precio del vuelo:\t", precio);
	if(validacion == -1)
	{
		printf("\nERROR, no se pudo establecer correctamente el precio \n");

		strcpy(precio,"");//comparar en setprecio y cambiar a 0
	}
	return precio;
}

char* validacionTipoPasajero()
{
	char tipoPasajero[];
	int validacion;
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
		if(tipoPasajero != "EconomyClass" && tipoPasajero != "FirstClass" && tipoPasajero != "ExecutiveClass")
		{
			bandera = -1;
			printf("/nERROR, ingrese una de las 3 opciones validas/n");
		}
	}while(bandera != -1);

	return tipoPasajero;
}

char* validacionCodigoVuelo()
{
	char codigoVuelo[];
	int validacion;

	getString("\n\nIngrese codigo del vuelo: \t", codigoVuelo);

	return codigoVuelo;
}

char* validacionEstadoVuelo()
{
	char estado[];
	int validacion;
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
		if(estado != "En Horario" && estado != "Aterrizado" && estado != "Demorado")
		{
			bandera = -1;
			printf("/nERROR, ingrese una de las 3 opciones validas/n");
		}
	}while(bandera != -1);

	return estado;
}

void ordenarPasajerosPorNombre(ePasajero listaPrincipalPasajeros[], int TAM)
{
  int i;
  int j;
  int retornoCmp;

  ePasajero auxiliar;

    for(i=0; i<TAM-1; i++)
    {
        for(j=i+1; j<TAM; j++)
        {
            retornoCmp = strcmp(listaPrincipalPasajeros[i].nombre, listaPrincipalPasajeros[j].nombre);

            if(retornoCmp == 1 && (listaPrincipalPasajeros[i].estado != 4 && listaPrincipalPasajeros[j].estado != 4))
            {
                auxiliar = listaPrincipalPasajeros[i];
                listaPrincipalPasajeros[i] = listaPrincipalPasajeros[j];
                listaPrincipalPasajeros[j] = auxiliar;
            }
        }
    }
}

void ordenarPasajerosPorApellido(ePasajero listaPrincipalPasajeros[], int TAM)
{
  int i;
  int j;
  int retornoCmp;

  ePasajero auxiliar;

    for(i=0; i<TAM-1; i++)
    {
        for(j=i+1; j<TAM; j++)
        {
            retornoCmp = strcmp(listaPrincipalPasajeros[i].apellido, listaPrincipalPasajeros[j].apellido);

            if(retornoCmp == 1 && (listaPrincipalPasajeros[i].estado != 4 && listaPrincipalPasajeros[j].estado != 4))
            {
                auxiliar = listaPrincipalPasajeros[i];
                listaPrincipalPasajeros[i] = listaPrincipalPasajeros[j];
                listaPrincipalPasajeros[j] = auxiliar;
            }
        }
    }
}


void ordenarPasajerosPorCodigo(ePasajero listaPrincipalPasajeros[], int TAM)
{
  int i;
  int j;
  int retornoCmp;

  ePasajero auxiliar;


  for(i=0; i<TAM-1; i++)
  {
	  for(j=i+1; j<TAM; j++)
	  {
		  retornoCmp = strcmp(listaPrincipalPasajeros[i].codigoVuelo, listaPrincipalPasajeros[j].codigoVuelo);

		  if(retornoCmp == 1 && (listaPrincipalPasajeros[i].estado != 4 && listaPrincipalPasajeros[j].estado != 4))
		  {
			  auxiliar = listaPrincipalPasajeros[i];
			  listaPrincipalPasajeros[i] = listaPrincipalPasajeros[j];
			  listaPrincipalPasajeros[j] = auxiliar;
		  }
	  }
  }
}
