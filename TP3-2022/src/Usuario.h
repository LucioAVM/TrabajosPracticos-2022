/*
 * Usuario.h
 *
 *  Created on: 10 jun. 2022
 *      Author: Monsalbo Lucio
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include "LinkedList.h"
#include "Pasajero.h"

int altaDatosUsuario(char* id, char nombre[], char apellido[], char *precio, char *tipoPasajero, char codigoVuelo[], char *estado);

int cargar_nuevoId(LinkedList* pArrayListPassenger);

int buscarUsuarioPorId(LinkedList* pArrayListPassenger,int id);

void get_Nombre(char* nombre);

void get_Apellido(char* apellido);

void get_Precio(char* precio);

void get_TipoPasajero(char* tipoPasajero);

void get_CodigoVuelo(char* codigoVuelo);

char* get_EstadoVuelo(char* estado);

void ordenarPasajerosPorNombre(ePasajero listaPrincipalPasajeros[], int TAM);

void ordenarPasajerosPorApellido(ePasajero listaPrincipalPasajeros[], int TAM);

void ordenarPasajerosPorCodigo(ePasajero listaPrincipalPasajeros[], int TAM);

#endif /* USUARIO_H_ */
