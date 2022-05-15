/*
 * Empleados.h
 *
 *  Created on: 1 may. 2022
 *      Author: Monsalbo Lucio
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoViaje[10];
	int tipoPasajero;
	int estadoVuelos;
	int isEmpty;
} ePasajero;

#endif /* EMPLEADOS_H_ */

int ePasajeros_Inicializar(ePasajero listaPrincipalPasajeros[], int TAM);

int ePasajeros_ObtenerID(int idPasajero);

int ePasajeros_ObtenerLibre(ePasajero listaPrincipalPasajeros[], int TAM);

int addPasajeros(ePasajero listaPrincipalPasajeros[]
												  , int libre
												  , int* idPasajero
												  , char nombre[]
												  , char apellido[]
	   											  , float precioVuelo
												  , char codigoVuelo[]
												  , int tipoVuelo
												  , int estadoVuelo);

int findempleadoById(ePasajero listaPrincipalPasajeros[], int TAM, int id);

void mostrarPasajeros(ePasajero listaPrincipalPasajeros[], int TAM);

void mostrarUnPasajero(ePasajero listaPrincipalPasajeros, int TAM);

void ordenarPasajerosPorApellidoYTipo(ePasajero listaPrincipalPasajeros[], int TAM);

void mostrarTotalYPromedioPrecioPasajerosSuperiorPromedio(ePasajero listaPrincipalPasajeros[], int TAM);

int pasajerosSuperanSalarioPromedio(ePasajero listaPrincipalPasajeros[], int tam, float precioPromedio);

int cantidadPasajeros(ePasajero listaPrincipalPasajeros[], int TAM);

void ordenarPasajerosPorCodigo(ePasajero listaPrincipalPasajeros[], int TAM);
