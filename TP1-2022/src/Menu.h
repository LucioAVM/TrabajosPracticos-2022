/*
 * Menu.h
 *
 *  Created on: 25 jun. 2022
 *      Author: UGIO
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * DESCRIPCION: muestra error y devuelve si quiere o no ingresar nuevamente una opcion
 *
 * PARAMETRO: int opcionIngresada
 * PARAMETRO: int max
 * PARAMETRO: int min
 * PARAMETRO: int* repeticiones
 *
 * RETORNO:
 *     -1= ERROR
 * 		1= para volver a mostrar el menu fuera de esta funcion
 * 		2= vuelve al menu
 */
int mostrarError(int,int,int,int*);

/**
 * DESCRIPCION:muestra el menu y devuelve un int con la opcion elegida
 *
 * PARAMETRO: void
 *
 * RETORNO: opcion elegida del menu
 */
int mostrarMenu(void);

/**
 * DESCRIPCION: pide datos al usuario (kilometros) y valida
 *
 * PARAMETRO: void
 *
 * RETORNO: los kilometros ingresados por el usuario
 */
int ingresarKilometros(void);

/**
 * DESCRIPCION: pide datos al usuario (precio de los vuelos) y valida
 *
 * PARAMETRO: float* latam
 * PARAMETRO: float* aerolineas
 *
 *  RETORNO: -1 = error
 *  		  1 = todo bien
 */
int menuPrecioVuelos(float*,float*);

/**
 * DESCRIPCION: calcula precios, los devuelve por punteros, muestra precios de vuelos y la respectiva diferencia
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
int calcularCostos(float*,float*,float*,float*,float*,float*,float*,float*,float,float,int,float*,int,int,float);

/**
 * DESCRIPCION: muestra los resultados pasados por parametros
 *
 * PARAMETRO: float tarjetaDebitoLatam
 * PARAMETRO: float tarjetaCreditoLatam
 * PARAMETRO: float BTCLatam
 * PARAMETRO: float precioUnitarioLatam
 * PARAMETRO: float tarjetaDebitoAerolineas
 * PARAMETRO: float tarjetaCreditoAerolineas
 * PARAMETRO: float BTCAerolineas
 * PARAMETRO: float precioUnitarioAerolineas
 * PARAMETRO: float diferenciaPrecioVuelos
 *
 * RETORNO: void
 */
void mostrarResultados(float,float,float,float,float,float,float,float,float);

/**
 * DESCRIPCION: hace los calculos y muestra los resultados a partir de los parametros ingresados
 *
 * PARAMETRO: int porcentajeDescuento
 * PARAMETRO: int porcentajeInteres
 * PARAMETRO: float BTCPrecio
 * PARAMETRO: float latam
 * PARAMETRO: float aerolineas
 * PARAMETRO: int kilometros
 *
 * RETORNO: void
 */
void cargaForzada(int porcentajeDescuento,int porcentajeInteres, float BTCPrecio, float* latam, float* aerolineas, int* kilometros);

#endif /* MENU_H_ */
