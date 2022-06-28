/*
 * CalculosAuxiliares.c
 *
 *  Created on: 25 jun. 2022
 *      Author: UGIO
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculosAuxiliares.h"
#include "menu.h"

float descuento(int PorcentajeDescuento, float precio)
{
	float precioConDescuento;
	float descuentoAplicado;

	descuentoAplicado= precio * PorcentajeDescuento/100;
	precioConDescuento = precio-descuentoAplicado;

	return precioConDescuento;
}

float interes(int interes, float precio)
{
	float precioConInteres;
	float interesAplicado;

	interesAplicado= precio*interes/100;
	precioConInteres = precio+interesAplicado;

	return precioConInteres;
}

float promedioDeDosVariablesFlotantes(float primeraVariable, float segundaVariable)
{
	float promedioVariables;

	promedioVariables = primeraVariable/segundaVariable;

	return promedioVariables;
}

float diferencia2VariablesFlotantes(float primeraVariable, float segundaVariable)
{
	float diferenciaVariables;

	diferenciaVariables = -1;

	if(primeraVariable > segundaVariable)
	{
		diferenciaVariables = primeraVariable-segundaVariable;
	}else{
		if(primeraVariable < segundaVariable)
		{
			diferenciaVariables = segundaVariable-primeraVariable;
		}
	}
	return diferenciaVariables;
}


void hacerTodosLosCalculos(float* tarjetaDebitoLatam,float* tarjetaCreditoLatam,float* BTCLatam,float* precioUnitarioLatam,
		float* tarjetaDebitoAerolineas,float* tarjetaCreditoAerolineas,float* BTCAerolineas,float* precioUnitarioAerolineas,
		float latam, float aerolineas, int kilometros, float* diferenciaPrecioVuelos,
		int porcentajeDescuento,int porcentajeinteres, float BTCPrecio)
{
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

	printf("\n%.2f latam, %.2f aerolineas\n", latam, aerolineas);
	*diferenciaPrecioVuelos = diferencia2VariablesFlotantes(latam, aerolineas);
}
