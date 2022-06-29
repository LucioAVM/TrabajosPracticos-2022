/*
 * Monsalbo.h
 *
 *  Created on: 9 jun. 2022
 *      Author: Monsalbo Lucio
 */

#ifndef MONSALBO_H_
#define MONSALBO_H_

int getStringLetras(char mensaje[], char input[]);

void getString(char mensaje[],char input[]);

int soloLetras(char str[]);

int soloNumeros(char* string);

int getFloat(float* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int getInt(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

int getSoloNumeros(char mensaje[], char mensajeError[], char input[]);
#endif /* MONSALBO_H_ */
