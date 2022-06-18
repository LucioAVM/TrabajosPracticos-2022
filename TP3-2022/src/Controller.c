/*
 * controller.c
 *
 *  Created on: 9 jun. 2022
 *      Author: UGIO
 */

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Pasajero.h"
#include "Estado.h"
#include "TipoPasajero.h"
#include "Pasajero.h"
#include "Usuario.h"

int mostrarMenu(void)
{
	int menu;
	int bandera;

	bandera = 0;

	do
	{
		if(bandera > 0)
		{
			printf("Error, ingrese una opcion valida:/n/n");
		}
		printf("       Menu Pasajeros/n"
			   "       --------------/n/n"
		     "1. Cargar datos en texto/n"
		     "2. Cargar datos en binario/n"
		     "3. Alta/n"
		     "4. Modificar/n"
		     "5. Baja/n"
		     "6. Listar/n"
		     "7. Ordenar/n"
		     "8. Guardar datos en texto/n"
		     "9. Guardar datos en binario/n"
		    "10. Salir/n"
		    "/t/tOpcion:");
			fflush(stdout);
			scanf("%d",&menu);

			bandera++;
	}while(menu <= 10 && menu >= 1 );

	return menu;
}


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_cargarDesdeTexto(char* path , LinkedList* pArrayListPassenger[])
{
	FILE* pArchivo = NULL;

	pArchivo = fopen(path,"r");

	if(pArchivo == NULL)
	{
		printf("error");
	}else{
		parser_PasajeroDesdeTexto(pArchivo, pArrayListPassenger);
	}
	fclose(pArchivo);

    return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_cargarDesdeBinario(char* path , LinkedList* pArrayListPassenger)
{
    int retorno;

    retorno = -1;

    FILE* pArchivo;

    if(path != NULL && pArrayListPassenger != NULL)
    {
    	pArchivo = fopen(path,"rb");
        if(pArchivo != NULL)
        {
            retorno = parser_PasajeroDesdeBinadio(pArchivo,pArrayListPassenger);
            fclose(pArchivo);
        }
    }
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_altaPasajero(LinkedList* pArrayListPassenger)
{
	ePasajero* pasajero;

	int id;
	char nombre[50];
	char apellido[50];
	char precio[10];
	char tipoPasajero[10];
	char codigoVuelo[4];
	char estado[10];

	int retorno;

	pasajero = NULL;
	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		DatosUsuario(nombre, apellido, precio, tipoPasajero, codigoVuelo, estado);//falta validacion

			pasajero = ePasajero_new();
			id = cargar_nuevoId();

			pasajero = ePasajero_newParametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estado);
	}
    return 1;//VALIDAR QUE ESTE ABIERTO EL ARCHIVO ANTES
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_modificarPasajero(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int id;
    int opcion;
    char nombre[128];
    char apellido[128];
    char codigoVuelo[128];
    int tipoPasajero;
    float precio;
    int estado;

    ePasajero* auxPasajero;

    if(pArrayListPassenger != NULL)
    {
        printf("/nIngrese el id del pasajero a modificar: ");
        scanf("%d",&id);
        auxPasajero = buscarUsuarioPorId(pArrayListPassenger,id);
        if(auxPasajero != NULL)
        {
        	printf( "/nMENU MODIFICACION PASAJEROS/n"
        			"--------------------------/n"
        			"1- Nombre/n"
        			"2- Apellido/n"
        			"3- Precio/n"
        			"4- Tipo de Pasajero/n"
        			"5- Codigo de vuelo/n"
        			"6- Estado del vuelo/n"
        			"7- Salir/n");
            scanf("%d",&opcion);
            switch(opcion)
            {

            case 1:// NOMBRE
            	nombre = validacionNombre();
                ePasajero_setNombre(auxPasajero,nombre);
                break;


            case 2:// APELLIDO
            	apellido = validacionApellido();
                ePasajero_setApellido(auxPasajero,apellido);
                break;


            case 3:// PRECIO
            	precio = validacionPrecio();
            	ePasajero_setPrecio(auxPasajero,precio);
                break;


            case 4:// TIPO DE PASAJERO
            	tipoPasajero = tipoPasajero = validacionTipoPasajero();
                ePasajero_setTipoPasajero(auxPasajero,tipoPasajero);
                break;


            case 5:// CODIGO DE VUELO
            	codigoVuelo = validacionCodigoVuelo();
                ePasajero_setCodigoVuelo(auxPasajero,codigoVuelo);
                break;


            case 6:// ESTADO DEL VUELO
            	estado = validacionEstadoVuelo();
            	ePasajero_setEstado(auxPasajero,estado);
                break;
            }
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_bajaPasajero(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListarPasajeros(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ordenarPasajeros(LinkedList* pArrayListPassenger)
{
	int subMenu;

	printf("/nOpciones de ordenamiento:/n"
			"-------------------------/n"
			"1- Nombre/n"
			"2- Apellido/n"
			"3- Codigo de Vuelo/n"
			"Listar por: ");
	fflush(stdin);
	scanf("%s",subMenu);

    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_GuardarComoTexto(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;

	FILE* pArchivoTexto;
	ePasajero* pasajero;
	int tam;
	int i;

	retorno = -1;
	tam = ll_len(pArrayListPassenger);

	if(path != NULL && pArrayListPassenger !=NULL)
	{
		pArchivoTexto = fopen(path,"w");

		if(pArchivoTexto !=NULL)
		{
			for(i=0;i<tam;i++)
			{
				pasajero = (ePasajero*)ll_get(pArrayListPassenger,i);
				fwrite(pasajero,sizeof(ePasajero),1,pArchivoTexto);
			}
		}
		fclose(pArchivoTexto);
		retorno = 0;
	}
	return retorno;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_GuardarComoBinario(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pArchivoBinario;
	ePasajero* pasajero;
	int tam;
	int i;


	retorno = -1;
	tam = ll_len(pArrayListPassenger);

	if(path != NULL && pArrayListPassenger !=NULL)
	{
		pArchivoBinario = fopen(path,"wb");

		if(pArchivoBinario !=NULL)
		{
			for(i=0;i<tam;i++)
			{
				pasajero = (ePasajero*)ll_get(pArrayListPassenger,i);
				fwrite(pasajero,sizeof(ePasajero),1,pArchivoBinario);
			}
		}
		fclose(pArchivoBinario);
		retorno = 0;
	}
    return retorno;
}