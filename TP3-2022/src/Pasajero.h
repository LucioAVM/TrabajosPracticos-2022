/*
 * Pasajero.h
 *
 *  Created on: 9 jun. 2022
 *      Author: UGIO
 */

#ifndef PASAJERO_H_
#define PASAJERO_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int estado;

}ePasajero;

ePasajero* ePasajero_new();
ePasajero* ePasajero_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoStr);
void ePasajero_delete(ePasajero* );

int ePasajero_setId(ePasajero* this,int id);
int ePasajero_getId(ePasajero* this,int* id);

int ePasajero_setNombre(ePasajero* this,char* nombre);
int ePasajero_getNombre(ePasajero* this,char* nombre);

int ePasajero_setApellido(ePasajero* this,char* apellido);
int ePasajero_getApellido(ePasajero* this,char* apellido);

int ePasajero_setCodigoVuelo(ePasajero* this,char* codigoVuelo);
int ePasajero_getCodigoVuelo(ePasajero* this,char* codigoVuelo);

int ePasajero_setTipoPasajero(ePasajero* this,int tipoPasajero);
int ePasajero_getTipoPasajero(ePasajero* this,int* tipoPasajero);

int ePasajero_setPrecio(ePasajero* this,float precio);
int ePasajero_getPrecio(ePasajero* this,float* precio);

int ePasajero_setEstado(ePasajero* this,float estado);
int ePasajero_getEstado(ePasajero* this,float* estado);

//agregar estados

#endif /* PASAJERO_H_ */
