/*
 * Menu.c
 *
 *  Created on: 25 jun. 2022
 *      Author: UGIO
 */

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "calculosAuxiliares.h"

int mostrarMenu(void)
{
	int OpcionUsuario;

	printf("\n\n		 MENU				\n"
			" ___________________________________\n"
			"|1.     Ingresar Kilometros        |\n"
			"|2.   Ingresar Precio de Vuelos    |\n"
			"|3.   Calcular todos los costos    |\n"
			"|4.      Informar Resultados       |\n"
			"|5.     Carga forzada de datos     |\n"
			"|6.            Salir               |\n"
			"|__________________________________|\n");

	fflush(stdin);
	scanf("%d", &OpcionUsuario);

	if(OpcionUsuario<1 || OpcionUsuario>6)
	{
		printf("OPCION INGRESADA NO VALIDA\n");
	}
	return OpcionUsuario;
}

int ingresarKilometros(void)
{
	int retorno;
	int bandera;
	int repeticiones;

	bandera = 0;
	repeticiones = 5;
	retorno = -1;

	do{
		printf("ingrese kilometros del viaje\n");
		fflush(stdin);
		scanf("%d", &retorno);

		if(retorno < 0)
		{
			bandera = 1;
			repeticiones--;
			printf("                       ERROR\n"
					"debe ingresar un kilometraje valido(no puede ser negativo)\n"
					"le quedan %d intentos", repeticiones);
		}else{
			bandera = 0;
		}
	}while(bandera == 1 && repeticiones > 1);

	return retorno;
}

int menuPrecioVuelos(float *latam, float *aerolineas)
{
	int retorno;
	int opcionIngresada;
	int bandera;
	float auxiliarLatam;
	float auxiliarAerolineas;
	int opcionValidacion;
	retorno = -1;
	bandera = 0;

	//MENU
	do{

		printf("Ingrese precios de vuelos:((Aerolineas = $ %.2f, Latam = $%.2f))\n"
				"1)Aerolineas\n"
				"2)Latam\n",*aerolineas,*latam);// agregar valor predeterminado x2
		fflush(stdin);
		scanf("%d", &opcionIngresada);

		if(opcionIngresada>2 || opcionIngresada<1)
		{
			printf("OPCION INGRESADA NO VALIDA\n"
					"1)ingresar opcion nuevamente\n"
					"2)volver al menu principal\n");
			scanf("%d", &opcionValidacion);
		}
	}while(opcionValidacion == 1);

	//OPCIONES DE MENU
	switch(opcionIngresada)
	{
	case 1:
		printf("ingrese precio del vuelo de Aerolineas\n");
		fflush(stdin);
		scanf("%f", &auxiliarAerolineas);
		bandera = 1;
		break;

	case 2:
		printf("ingrese precio del vuelo de Latam\n");
		fflush(stdin);
		scanf("%f", &auxiliarLatam);
		bandera = 2;
		break;
	}

	if(bandera == 1 || bandera ==2)
	{
		*aerolineas = auxiliarAerolineas;
		*latam = auxiliarLatam;
		retorno = 1;
	}
	return retorno;
}

int calcularCostos(float* tarjetaDebitoLatam,float* tarjetaCreditoLatam,float* BTCLatam,float* precioUnitarioLatam,
		float* tarjetaDebitoAerolineas,float* tarjetaCreditoAerolineas,float* BTCAerolineas,float* precioUnitarioAerolineas,
		float latam, float aerolineas, int kilometros, float* diferenciaPrecioVuelos,
		int porcentajeDescuento,int porcentajeinteres, float BTCPrecio)
{
	int retorno;

	retorno = -1;

	//LATAM
	*tarjetaDebitoLatam = descuento(porcentajeDescuento, latam);
	*tarjetaCreditoLatam = interes(porcentajeinteres, latam);
	*BTCLatam = promedioDeDosVariablesFlotantes( BTCPrecio, latam);
	*precioUnitarioLatam = promedioDeDosVariablesFlotantes( latam, (float)kilometros);

	//AEROLINEAS
	*tarjetaDebitoAerolineas = descuento(porcentajeDescuento, aerolineas);
	*tarjetaCreditoAerolineas = interes(porcentajeinteres, aerolineas);
	*BTCAerolineas = promedioDeDosVariablesFlotantes( BTCPrecio, aerolineas);
	*precioUnitarioAerolineas = promedioDeDosVariablesFlotantes( aerolineas, (float)kilometros);

	*diferenciaPrecioVuelos = diferencia2VariablesFlotantes(latam, aerolineas);

													//MOSTRAR RESULTADOS
	printf("Se han calculado exitosamente todos los costos: \n"
			"a) Tarjeta de debito                              _\n"
			"b) Tarjeta de credito                              |opcion 4 del menu\n"
			"c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)  _|   para mostrar\n"
			"d) precio por km\n"
			"	|_Latam      = $ %.2f\n"
			"	|_Aerolineas = $ %.2f\n\n"
			"e) diferencia de precio ingresada (Latam - Aerol�neas) = $ %.2f\n",*precioUnitarioLatam,*precioUnitarioAerolineas,*diferenciaPrecioVuelos);

	return retorno;
}
void mostrarResultados(float tarjetaDebitoLatam,float tarjetaCreditoLatam,float BTCLatam,float precioUnitarioLatam,
		float tarjetaDebitoAerolineas,float tarjetaCreditoAerolineas,float BTCAerolineas,float precioUnitarioAerolineas,float diferenciaPrecioVuelos)
{
	printf("Latam:\n"
			"a) Precio con tarjeta de debito: $ %.2f\n"
			"b) Precio con tarjeta de credito: $ %.2f\n"
			"c) Precio pagando con bitcoin : $ %.2f\n"
			"d) Precio unitario: %.2f\n"
			"Aerol�neas:\n"
			"a) Precio con tarjeta de debito: $ %.2f\n"
			"b) Precio con tarjeta de credito: $ %.2f\n"
			"c) Precio pagando con bitcoin : $ %.2f\n"
			"d) Precio unitario: $ %.2f\n"
			"La diferencia de precio es : $ %.2f\n",tarjetaDebitoLatam,tarjetaCreditoLatam,BTCLatam,precioUnitarioLatam,
			tarjetaDebitoAerolineas,tarjetaCreditoAerolineas,BTCAerolineas,precioUnitarioAerolineas,diferenciaPrecioVuelos);
}

void cargaForzada(int porcentajeDescuento,int porcentajeInteres, float BTCPrecio, float* latam, float* aerolineas, int* kilometros)
{
	float tarjetaDebitoLatam;
	float tarjetaCreditoLatam;
	float BTCLatam;
	float precioUnitarioLatam;

	float tarjetaDebitoAerolineas;
	float tarjetaCreditoAerolineas;
	float BTCAerolineas;
	float precioUnitarioAerolineas;
	float diferenciaPrecioVuelos;

	float auxLatam;
	float auxAerolineas;
	int auxKilometros;

	*kilometros = 7090;
	*aerolineas = 162965;
	*latam = 159339;
	//***********************HARDCODEO

	auxLatam = *latam;
	auxAerolineas = *aerolineas;
	auxKilometros = *kilometros;

	hacerTodosLosCalculos(&tarjetaDebitoLatam, &tarjetaCreditoLatam, &BTCLatam, &precioUnitarioLatam,
				&tarjetaDebitoAerolineas,&tarjetaCreditoAerolineas, &BTCAerolineas, &precioUnitarioAerolineas,
				auxLatam,auxAerolineas,auxKilometros, &diferenciaPrecioVuelos,
				porcentajeDescuento,porcentajeInteres, BTCPrecio);

	mostrarResultados(tarjetaDebitoLatam,tarjetaCreditoLatam,BTCLatam,precioUnitarioLatam,
			tarjetaDebitoAerolineas,tarjetaCreditoAerolineas,BTCAerolineas,precioUnitarioAerolineas,diferenciaPrecioVuelos);
}

