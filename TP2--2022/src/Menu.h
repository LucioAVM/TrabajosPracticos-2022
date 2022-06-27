/*
 * Menu.h
 *
 *  Created on: 12 may. 2022
 *      Author: Monsalbo Lucio
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Pasajeros.h"

#define LIBRE 0
#define OCUPADO 1



#ifndef MENU_H_
#define MENU_H_

#endif /* MENU_H_ */

/**
 *
 */
int mostrarMenu(void);

int altaPasajero(ePasajero listaPrincipalPasajeros[],int TAM, int* id);

int modificarpasajero(ePasajero listaPrincipalPasajeros[], int TAM);

int bajaPasajero(ePasajero listaPrincipalPasajeros[], int TAM);

void ordenarPasajeros(ePasajero listaPrincipalPasajeros[], int TAM);

void hardcodeoPasajeros(ePasajero listaPrincipalPasajeros[],int* id);
