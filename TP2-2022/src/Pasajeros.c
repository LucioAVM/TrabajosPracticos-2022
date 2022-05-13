/*
 * Empleados.c
 *
 *  Created on: 1 may. 2022
 *      Author: Monsalbo Lucio
 */

#include "Menu.h"
#include "Pasajeros.h"
#include "Monsalbo.h"

//

int ePasajeros_Inicializar(ePasajero listaPrincipalPasajeros[], int TAM)
{
	int i;
	int retorno;

	retorno = 1;

	if (listaPrincipalPasajeros != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			listaPrincipalPasajeros[i].isEmpty = LIBRE;
		}
		retorno = 0;
	}
	return retorno;
}

//

int ePasajeros_ObtenerID(int idPasajero)
{
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	idPasajero = idPasajero+1;

	return idPasajero;
}

//

int ePasajeros_ObtenerLibre(ePasajero listaPrincipalPasajeros[], int TAM)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (listaPrincipalPasajeros != NULL && TAM > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++)
		{
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (listaPrincipalPasajeros[i].isEmpty == 0)
			{
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int addPasajeros(ePasajero listaPrincipalPasajeros[]
												  , int libre
												  , int IDPasajero
												  , char nombre[]
												  , char apellido[]
	   											  , float precioVuelo
												  , char codigoVuelo[]
												  , int tipoVuelo
												  , int estadoVuelo)
{
	int retorno;
	int validacion;

	retorno = 0;

	if(listaPrincipalPasajeros != NULL && libre > -1 && IDPasajero > 0 && nombre != NULL && apellido != NULL && precioVuelo > 0 && codigoVuelo != NULL)
	{
		ePasajero auxiliar;

		auxiliar.id = IDPasajero;
		strcpy(auxiliar.nombre, nombre);
		strcpy(auxiliar.apellido, apellido);
		auxiliar.precio = precioVuelo;
		strcpy(auxiliar.codigoViaje, codigoVuelo);
		auxiliar.tipoPasajero = tipoVuelo;
		auxiliar.estadoVuelos = estadoVuelo;


		do
		{
			printf("\nesta seguro que quiere dar de alta el empleado ingresado?\n"
					"\n1- SI"
					"\n2- NO"
					"\ningrese opcion: ");
			scanf("%d", &validacion);
		}while(validacion != 1 && validacion != 2);

		if(validacion == 1)
		{
			listaPrincipalPasajeros[libre].id = auxiliar.id;
			strcpy(listaPrincipalPasajeros[libre].nombre, auxiliar.nombre);
			strcpy(listaPrincipalPasajeros[libre].apellido, auxiliar.apellido);
			listaPrincipalPasajeros[libre].precio = auxiliar.precio;
			strcpy(listaPrincipalPasajeros[libre].codigoViaje, auxiliar.codigoViaje);
			listaPrincipalPasajeros[libre].tipoPasajero = auxiliar.tipoPasajero;
			listaPrincipalPasajeros[libre].estadoVuelos = auxiliar.estadoVuelos;

			listaPrincipalPasajeros[libre].isEmpty = OCUPADO;

			retorno = 1;
		}else{
			printf("\noperacion cancelada");
		}
	}
	return retorno;
}

