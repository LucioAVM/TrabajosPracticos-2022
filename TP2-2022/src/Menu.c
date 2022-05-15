/*
 * Menu.c
 *
 *  Created on: 12 may. 2022
 *      Author: Monsalbo Lucio
 */

#include "Pasajeros.h"
#include "Menu.h"
#include "Monsalbo.h"


int mostrarMenu(void)
{
	int retorno;

	printf("\n\t\t\tADMINISTRACION DE PASAJEROS\n"
			"\t\t\t...........................\n\n"
			"1. ALTA\n\n"
			"2. MODIFICACION\n\n"
			"3. BAJA\n\n"
			"4. INFORMACION\n\n"
			"5. HARDCODEO\n\n"
			"6. FINALIZAR PROGRAMA\n"
			"Ingrese una opcion:\t");
	fflush(stdin);
	scanf("%d", &retorno);

	return retorno;
}

int altaPasajero(ePasajero listaPrincipalPasajeros[],int TAM)
{
	int retorno = 0;
	int validacion;

	char nombre[51];
	char apellido[51];
	float precioVuelo;
	char codigoVuelo[10];
	int estadoVuelo;
	int tipoVuelo;
	int idPasajero;

	int validacionNombre;
	int validacionApellido;

	idPasajero = 0;
	int libre;

	//recorre la lista buscando el primer lugar libre y lo devuelve si lo encuentra
	libre = ePasajeros_ObtenerLibre(listaPrincipalPasajeros, TAM);
	if(libre != -1)
	{
		//PIDE DATOS DEL PASAJERO AL USUARIO

								//NOMBRE
		validacionNombre = getStringLetras("\n\nIngresar nombre del pasajero:\t", nombre);
		if(validacionNombre == -1)
		{
			printf("\n\nERROR, no se pudo ingresar correctamente el nombre \n");
		}

								//APELLIDO
		validacionApellido = getStringLetras("\n\nIngresar apellido del pasajero:\t", apellido);
		if(validacionApellido == -1)
		{
			printf("\nERROR, no se pudo ingresar correctamente el apellido \n");
		}

							//PRECIO DE VUELO
		getFloat(&precioVuelo, "\n\nIngresar precio del vuelo:\t", "\nERROR, Ingresar precio del vuelo:\t",0,1000000, 5);

							//CODIGO DE VUELO
		getString("\n\nIngrese codigo del vuelo: \t", codigoVuelo);

							//TIPO DE PASAJERO
		tipoVuelo = getInt("\n\nIngrese tipo del vuelo:\t","\nERROR, Ingrese tipo del vuelo:\t", 0,5,5);

							//ESTADO DEL VUELO
		estadoVuelo = getInt("\n\nIngrese estado del vuelo\t","\nERROR, Ingrese estado del vuelo\t", 0, 3, 5);

		validacion = addPasajeros(listaPrincipalPasajeros
				, libre
				, &idPasajero
				, nombre
				, apellido
				, precioVuelo
				, codigoVuelo
				, tipoVuelo
				, estadoVuelo);

		if(validacion == 1)
		{
			retorno = 1;

		}
	}else{
		printf("\nNo se encontro lugar libre en el sistema");
	}
	return retorno;
}


int modificarpasajero(ePasajero listaPrincipalPasajeros[], int TAM)
{
	int retorno;
	int menu;

	int IDIngresado;
	int index;

	int validacion;
	int validacionNombre;
	int validacionApellido;

	ePasajero auxiliar;

	retorno = 0;

	mostrarPasajeros(listaPrincipalPasajeros, TAM);

	printf("ingrese el ID del pasajero que desea modificar\t");
	scanf("%d",&IDIngresado);

	index = findempleadoById(listaPrincipalPasajeros, TAM, IDIngresado);

	if(index != -1)
	{
		auxiliar = listaPrincipalPasajeros[index];
		do
		{
			printf("\n\nLista de modificaciones:\n"
					"1- Nombre\n"
					"2- Apellido\n"
					"3- Precio\n"
					"4- Tipo de pasajero\n"
					"5- Codigo de vuelo\n"
					"6- Volver al menu\n"
					"Ingrese la opcion deseada:\t");
			scanf("%d", &menu);

			switch(menu)
			{

			case 1:
				validacionNombre = getStringLetras("\nIngresar nombre del pasajero: \t", auxiliar.nombre);
				if(validacionNombre == -1)
				{
					printf("\n\nERROR, no se pudo ingresar correctamente el nombre \n");
				}
				break;


			case 2:
				validacionApellido = getStringLetras("\n\nIngresar apellido del pasajero: \t", auxiliar.apellido);
				if(validacionApellido == -1)
				{
					printf("\nERROR, no se pudo ingresar correctamente el apellido \n");
				}
				break;


			case 3:
				getFloat(&auxiliar.precio, "\n\nIngresar precio del vuelo: \t", "\nERROR, Ingresar precio del vuelo: \t",0,1000000, 5);
				break;


			case 4:
				auxiliar.tipoPasajero = getInt("\n\nIngrese tipo de pasajero:\t","\nERROR, Ingrese tipo de pasajero:\t", 0,5,5);
				break;


			case 5:
				getString("\n\nIngrese codigo del vuelo: \t", auxiliar.codigoViaje);
				break;


			case 6://queres aplicar las modificaciones (mostrar modificasiones Si o NO
				do
				{

					printf( "ORIGINAL:"
							" ____________________________________________________________________________________________________________\n"
							"|---ID-------NOMBRE-------APELLIDO-------PRECIO-------CODIGO DE VUELO-------TIPO DE PASAJERO-------ESTADO DEL VUELO---| \n");
					mostrarUnPasajero(auxiliar, TAM);

					printf( "MODIFICADO:"
							" __________________________________________________________________________________________________________\n"
							"|---ID-------NOMBRE-------APELLIDO-------PRECIO-------CODIGO DE VUELO-------TIPO DE PASAJERO-------ESTADO DEL VUELO---| \n");
					mostrarUnPasajero(listaPrincipalPasajeros[index], TAM);

					printf("\nDesea realizar las siguientes modificaciones?\n"
							"1_ SI\n"
							"2_ NO\n"
							"Ingrese la opcion deseada:\t");

					scanf("%d",&validacion);
					if(validacion == 1)
					{
						strcpy(listaPrincipalPasajeros[index].nombre, auxiliar.nombre);
						strcpy(listaPrincipalPasajeros[index].apellido, auxiliar.apellido);
						listaPrincipalPasajeros[index].precio = auxiliar.precio;
						listaPrincipalPasajeros[index].tipoPasajero = auxiliar.tipoPasajero;
						strcpy(listaPrincipalPasajeros[index].codigoViaje,auxiliar.codigoViaje);
						retorno = 1;
					}else{
						if(validacion == 2)
						{
							printf("se han descartado los cambios\n");
						}
					}
				}while(validacion != 1 && validacion != 2);

				break;
			}
		}while(menu != 6);
	}
	return retorno;
}

int bajaPasajero(ePasajero listaPrincipalPasajeros[], int TAM)
{
	int IDIngresado;
	int index;
	int validacion;
	int retorno;

	retorno = 0;

	mostrarPasajeros(listaPrincipalPasajeros, TAM);

	printf("ingrese el ID del pasajero que desea modificar\t");
	scanf("%d",&IDIngresado);

	index = findempleadoById(listaPrincipalPasajeros, TAM, IDIngresado);

	printf("\n\tQuiere dar de baja el siguiente pasajero?\n"
			" _____________________________________________________________________________________________________________________\n"
			"|---ID-------NOMBRE-------APELLIDO-------PRECIO-------CODIGO DE VUELO-------TIPO DE PASAJERO-------ESTADO DEL VUELO---| \n");
	mostrarUnPasajero(listaPrincipalPasajeros[index], TAM);
	printf("1- SI\n"
			"2- NO\n"
			"Ingrese la opcion deseada:\n");
	scanf("%d",&validacion);

	if(validacion == 1)
	{
		listaPrincipalPasajeros[index].isEmpty = LIBRE;
		printf("usuario %d dado de baja exitosamente", IDIngresado);
	}else{
		if(validacion == 2)
		{
			printf("Se han descartados los cambios");
		}else{
			printf("ERROR, ingrese una opcion valida");
		}
	}
	return retorno;
}

void ordenarPasajeros(ePasajero listaPrincipalPasajeros[], int TAM)
{
	int menu;

	printf("LISTADOS:\n"
			"1- Alfabéticamente por apellido y Tipo de pasajero\n"
			"2- Total y promedio de precios de vuelos y quienes lo superan\n"
			"3-Por codigo con estado de vuelo 'ACTIVO'\n");
	fflush(stdin);
	scanf("%d", &menu);

	switch(menu)
	{
	case 1:
		ordenarPasajerosPorApellidoYTipo(listaPrincipalPasajeros, TAM);
		break;
	case 2:
		mostrarTotalYPromedioPrecioPasajerosSuperiorPromedio( listaPrincipalPasajeros, TAM);
		break;
	case 3:
		ordenarPasajerosPorCodigo(listaPrincipalPasajeros, TAM);
		break;
	}

	mostrarPasajeros(listaPrincipalPasajeros, TAM);
}

void hardcodeoPasajeros(ePasajero listaPrincipalPasajeros[])
{
	int i;

	ePasajero hardcodeo[]=
	{
			{1,"Aquiles","Bailo",1126,"ABC123",1,2},
			{2,"Chanchope","Golzales",8853,"570j86",2,1},
			{3,"Milanesa","Papas Fritas",3312,"hambre123",1,2},
			{4,"Aitor","Menta",5647,"dgn465",2,2},
			{5,"Aitor","Tilla",6845,"645tjd",1,1}
	};

	for(i = 0; i < 5; i++)
	{
		listaPrincipalPasajeros[i] = hardcodeo[i];
	}

}
