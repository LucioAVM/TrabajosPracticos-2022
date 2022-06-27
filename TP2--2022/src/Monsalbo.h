/*
 * Monsalbo.h
 *
 *  Created on: 1 may. 2022
 *      Author: Monsalbo Lucio
 */

#ifndef MONSALBO_H_
#define MONSALBO_H_


#endif /* MONSALBO_H_ */

int getFloat(float* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int getInt(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

int getChar(char resultado[], char *mensaje, char *mensajeError, int reintentos);

int getStringLetras(char mensaje[], char input[]);

void getString(char mensaje[],char input[]);

int soloLetras(char str[]);

int getNumeros(char mensaje[]);

int getDataNum(char mensaje[]);

int validacionS_N(char *texto);

int validacionS_NParametrizadoInt(char *texto, int parametro);
