/*
 * Monsalbo.c
 *
 *  Created on: 9 jun. 2022
 *      Author: Monsalbo Lucio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Monsalbo.h"

int getStringLetras(char mensaje[], char input[])
{
	char aux[256];
	int retorno;
	retorno = -1;
	int intentos;

	intentos = 5;

	do{
		getString(mensaje, aux);
		if (soloLetras(aux))
		{
			strlwr(aux);
			aux[0] = toupper(aux[0]);

			strcpy(input, aux);
			retorno = 0;
		}else{
			intentos--;
			printf(
					"no se ah ingresado solo letras intente nuevamente(quedan %d intentos):",
					intentos);
			if (intentos == 0)
			{
				retorno = -2;
				break;
			}
		}
	} while (retorno == -1);

	return retorno;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int soloLetras(char str[])
{
	int i = 0;
	int retorno;

	retorno = -1;

	while (str[i] != '\0')
	{
		if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
			retorno = 0;
		i++;
	}
	return retorno;
}

int getFloat(float* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	float auxiliarFloat;
	int i;

	retorno = -1;

	if (resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		for (i = reintentos; i > -1; i--)
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &auxiliarFloat);
			if (auxiliarFloat > minimo && auxiliarFloat < maximo)
			{
				*resultado = auxiliarFloat ;
				retorno = 0;
				break;
			}else{
				printf("\nEl numero ingresado no esta dentro del limite(%d-%d), intente nuevamente\n",minimo, maximo);
			}
		}
	}
	return retorno;
}

//INT//
int getInt(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno;
	int resultado;

	retorno = -1;

	if (mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		do{
			printf("%s", mensaje);
			scanf("%d", &resultado);

			if (resultado > minimo && resultado < maximo)
			{
				retorno = resultado;
				break;
			}else{
				printf("\nEl numero ingresado no esta dentro del limite(%d-%d), intente nuevamente\n",minimo, maximo);
			}
			reintentos--;
		} while (reintentos > 0);
	}
	return retorno;
}

int getSoloNumeros(char mensaje[], char mensajeError[], char input[])
{
	int retorno;
	int validacionNumero;
	int intentos;

	retorno = -1;
	intentos = 5;

	do
	{
		getString(mensaje, input);

		validacionNumero = soloNumeros(input);

			if(validacionNumero == 0)
			{
				retorno = 0;
			}else{
				printf("El texto ingresado no es un numero valido/n"
						"quedan %d intentos/n",intentos);
			}

			intentos--;
	}while(retorno !=0 && intentos > 0);

	return retorno;
}


int soloNumeros(char* string)
{
    int i;
    int retorno;

    retorno = 1;

    for(i=0;i<strlen(string);i++)
    {
        if(string[i]<'0' || string[i]>'9')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
