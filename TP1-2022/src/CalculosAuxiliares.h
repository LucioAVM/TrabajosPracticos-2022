/*
 * CalculosAuxiliares.h
 *
 *  Created on: 25 jun. 2022
 *      Author: UGIO
 */

#ifndef CALCULOSAUXILIARES_H_
#define CALCULOSAUXILIARES_H_

/**
 * DESCRIPCION: realiza el descuento de la segunda variable de a cuerdo a el porcentaje ingresada en la primera
 *
 * PARAMETRO: int PorcentajeDescuento
 * PARAMETRO: float precio
 *
 * RETORNO: el precio con descuento
 */
float descuento(int,float);

/**
 * DESCRIPCION: aplica el interes de la segunda variable de a cuerdo a el porcentaje ingresada en la primera
 *
 * PARAMETRO: int interes
 * PARAMETRO: float precio
 *
 * RETORNO: precio con interes
 */
float interes(int,float);

/**
 * DESCRIPCION: realiza la divicion: primeraVariable/segundaVariable
 *
 * PARAMETRO: float primeraVariable
 * PARAMETRO: float segundaVariable
 *
 * RETORNO: resultado de la divicion
 */
float promedioDeDosVariablesFlotantes(float,float);

/**
 * DESCRIPCION: resta la variable numerica mas alta con la mas baja
 *
 * PARAMETRO:float primeraVariable
 * PARAMETRO:float segundaVariable
 *
 * RETORNO: resultado de la resta
 */
float diferencia2VariablesFlotantes(float,float);

/**
 * DESCRIPCION: realiza el interes, descuento, promedios y diferencia entre aerolineas y latam
 *
 * PARAMETRO: float* tarjetaDebitoLatam
 * PARAMETRO: float* tarjetaCreditoLatam
 * PARAMETRO: float* BTCLatam
 * PARAMETRO: float* precioUnitarioLatam
 * PARAMETRO: float* tarjetaDebitoAerolineas
 * PARAMETRO: float* tarjetaCreditoAerolineas
 * PARAMETRO: float* BTCAerolineas
 * PARAMETRO: float* precioUnitarioAerolineas
 * PARAMETRO: float  latam
 * PARAMETRO: float  aerolineas
 * PARAMETRO: int    kilometros
 * PARAMETRO: float* diferenciaPrecioVuelos
 * PARAMETRO: int    porcentajeDescuento
 * PARAMETRO: int    porcentajeinteres
 * PARAMETRO: float  BTCPrecio
 *
 * RETORNO: void
 */
//void hacerTodosLosCalculos(float*,float*,float*,float*,float*,float*,float*,float*,float,float,int,float*,int,int,float);

void hacerTodosLosCalculos(float* tarjetaDebitoLatam,float* tarjetaCreditoLatam,float* BTCLatam,float* precioUnitarioLatam,
		float* tarjetaDebitoAerolineas,float* tarjetaCreditoAerolineas,float* BTCAerolineas,float* precioUnitarioAerolineas,
		float latam, float aerolineas, int kilometros, float* diferenciaPrecioVuelos,
		int porcentajeDescuento,int porcentajeinteres, float BTCPrecio);

#endif /* CALCULOSAUXILIARES_H_ */
