/*
 * Menu.c
 *
 *  Created on: 12 may. 2022
 *      Author: Monsalbo Lucio
 */

#include "Pasajeros.h"
#include "Menu.h"
#include "Monsalbo.h"


int mostrarMenu(void)
{
	int retorno;

	printf("\t\t\tADMINISTRACION DE PASAJEROS\n"
			"\t\t\t...........................\n\n"
			"1. ALTA\n\n"
			"2. MODIFICACION\n\n"
			"3. BAJA\n\n"
			"4. INFORMACION\n\n"
			"Ingrese una opcion:");
	fflush(stdin);
	scanf("%d", &retorno);

	return retorno;
}

int AltaEmpleado(ePasajero listaPrincipalPasajeros[],int TAM, int* idPasajero)
{
	int retorno = 0;
	int validacion;

	char nombre[51];
	char apellido[51];
	float precioVuelo;
	char codigoVuelo[10];
	int estadoVuelo;
	int tipoVuelo;

	int libre;
	int auxiliarIDPasajero;

	//recorre la lista buscando el primer lugar libre y lo devuelve si lo encuentra
	libre = ePasajeros_ObtenerLibre(listaPrincipalPasajeros, TAM);
	if(libre != -1)
	{

		//copia el valor al que apunta a un auxiliar y despues sobreescribe el puntero con lo que devuelve la funcion
		auxiliarIDPasajero = *idPasajero;
		auxiliarIDPasajero = ePasajeros_ObtenerID(auxiliarIDPasajero);
		*idPasajero = auxiliarIDPasajero;

		//PIDE DATOS DEL PASAJERO AL USUARIO

								//NOMBRE
		getString("Ingresar nombre: \n", nombre);
		strlwr(nombre);
		nombre[0] = toupper(nombre[0]);

								//APELLIDO
		getString("Ingresar apellido del empleado: \n", apellido);
		strlwr(apellido);
		apellido[0] = toupper(apellido[0]);

							//PRECIO DE VUELO
		getFloat("Ingresar precio del vuelo: \n", &precioVuelo);

							//CODIGO DE VUELO
		getString("Ingrese codigo del vuelo: \n", codigoVuelo);
		strlwr(codigoVuelo);
		codigoVuelo[0] = toupper(codigoVuelo[0]);

							//TIPO DE PASAJERO
		getInt("Ingrese codigo del vuelo: \n", &tipoVuelo);

							//ESTADO DEL VUELO
		getInt("Ingrese estado del vuelo: \n", &estadoVuelo);

		validacion = addPasajeros(listaPrincipalPasajeros
				, libre
				, auxiliarIDPasajero
				, nombre
				, apellido
				, precioVuelo
				, codigoVuelo
				, tipoVuelo
				, estadoVuelo);

		if(validacion != 0)
		{
			printf("\nERROR, no se pudo dar de alta correctamente  el empleado");
		}else{
			printf("\nse dio de alta correctamente el empleado");
		}
	}else{
		printf("\nno se encontro lugar libre en el sistema");
	}
	return retorno;
}
