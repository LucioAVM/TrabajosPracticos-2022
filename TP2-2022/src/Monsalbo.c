/*
 * Monsalbo.c
 *
 *  Created on: 6 jul. 2021
 *      Author: Ususario
 */

#include "Monsalbo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getInt (char* mensaje, int* entero)
{
    printf(mensaje);
    scanf("%d", entero);
}

void getFloat (char* mensaje, float* flotante)
{
    printf(mensaje);
    scanf("%f", flotante);
}

void getString(char* mensaje, char* cadena)
{
    printf(mensaje);
    fflush(stdin);
    gets(cadena);
}

void getChar (char* mensaje, char* caracter)
{
    printf(mensaje);
    fflush(stdin);
    scanf("%c",caracter);
}
