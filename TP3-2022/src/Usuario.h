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

float get_Precio(char* precioStr);

void get_TipoPasajero(char* tipoPasajero);

void get_CodigoVuelo(char* codigoVuelo);

void get_EstadoVuelo(char* estado);

int ordenarPasajeros_Nombre(void* pElement1, void* pElement2);

int ordenarPasajeros_Apellido(void* pElement1, void* pElement2);

int ordenarPasajeros_Codigo(void* pElement1, void* pElement2);

#endif /* USUARIO_H_ */
