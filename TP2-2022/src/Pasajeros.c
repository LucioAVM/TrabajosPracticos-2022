/*
 * pasajeros.c
 *
 *  Created on: 1 may. 2022
 *      Author: Monsalbo Lucio
 */

#include "Menu.h"
#include "Pasajeros.h"
#include "Monsalbo.h"

//

int ePasajeros_Inicializar(ePasajero listaPrincipalPasajeros[], int TAM)
{
	int i;
	int retorno;

	retorno = 1;

	if (listaPrincipalPasajeros != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			listaPrincipalPasajeros[i].isEmpty = LIBRE;
		}
		retorno = 0;
	}
	return retorno;
}

//

int ePasajeros_ObtenerID(int idPasajero)
{
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	idPasajero = idPasajero+1;

	return idPasajero;
}

//

int ePasajeros_ObtenerLibre(ePasajero listaPrincipalPasajeros[], int TAM)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (listaPrincipalPasajeros != NULL && TAM > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++)
		{
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (listaPrincipalPasajeros[i].isEmpty == 0)
			{
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int addPasajeros(ePasajero listaPrincipalPasajeros[]
												  , int libre
												  , int* idPasajero
												  , char nombre[]
												  , char apellido[]
	   											  , float precioVuelo
												  , char codigoVuelo[]
												  , int tipoVuelo
												  , int estadoVuelo)
{
	int retorno;
	int validacion;
	int idAuxiliar;

	validacion = -1;
	retorno = 0;

	if(listaPrincipalPasajeros != NULL && libre > -1 && nombre != NULL && apellido != NULL && precioVuelo > 0 && codigoVuelo != NULL)
	{
		ePasajero auxiliar;

		strcpy(auxiliar.nombre, nombre);
		strcpy(auxiliar.apellido, apellido);
		auxiliar.precio = precioVuelo;
		strcpy(auxiliar.codigoViaje, codigoVuelo);
		auxiliar.tipoPasajero = tipoVuelo;
		auxiliar.estadoVuelos = estadoVuelo;

		do
		{
			printf("\nEsta seguro que quiere dar de alta el pasajero ingresado?"
					"\n1- SI"
					"\n2- NO\n"
					"\nIngrese opcion:\t");
			scanf("%d", &validacion);
		}while(validacion != 1 && validacion != 2);

		if(validacion == 1)
		{
			idAuxiliar = *idPasajero;
			*idPasajero = ePasajeros_ObtenerID(idAuxiliar);

			listaPrincipalPasajeros[libre].id = *idPasajero;
			strcpy(listaPrincipalPasajeros[libre].nombre, auxiliar.nombre);
			strcpy(listaPrincipalPasajeros[libre].apellido, auxiliar.apellido);
			listaPrincipalPasajeros[libre].precio = auxiliar.precio;
			strcpy(listaPrincipalPasajeros[libre].codigoViaje, auxiliar.codigoViaje);
			listaPrincipalPasajeros[libre].tipoPasajero = auxiliar.tipoPasajero;
			listaPrincipalPasajeros[libre].estadoVuelos = auxiliar.estadoVuelos;

			listaPrincipalPasajeros[libre].isEmpty = OCUPADO;

			retorno = 1;
		}else{
			printf("\noperacion cancelada");
		}
	}
	return retorno;
}

int findempleadoById(ePasajero listaPrincipalPasajeros[], int TAM, int id)
{
	int retorno = -1;
	int i;

	if (listaPrincipalPasajeros != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (listaPrincipalPasajeros[i].id == id && listaPrincipalPasajeros[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void mostrarPasajeros(ePasajero listaPrincipalPasajeros[], int TAM)
{
	int i;

	printf( " _____________________________________________________________________________________________________________________\n"
			"|---ID-------NOMBRE-------APELLIDO-------PRECIO-------CODIGO DE VUELO-------TIPO DE PASAJERO-------ESTADO DEL VUELO---| \n");

	for(i = 0; i < TAM; i++)
	{
		if(listaPrincipalPasajeros[i].isEmpty == OCUPADO)
		{
			mostrarUnPasajero(listaPrincipalPasajeros[i],TAM);
		}
	}
	printf( "|_____________________________________________________________________________________________________________________| \n");
}

void mostrarUnPasajero(ePasajero listaPrincipalPasajeros, int TAM)
{
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelos;

	id = listaPrincipalPasajeros.id;
	strcpy(nombre, listaPrincipalPasajeros.nombre);
	strcpy(apellido, listaPrincipalPasajeros.apellido);
	precio = listaPrincipalPasajeros.precio;
	strcpy(codigoVuelo, listaPrincipalPasajeros.codigoViaje);
	tipoPasajero = listaPrincipalPasajeros.tipoPasajero;
	estadoVuelos = listaPrincipalPasajeros.estadoVuelos;

	printf( "| %4d        %4s      %5s        %5.2f            %5s                   %5d              %5d   |\n",id ,nombre, apellido, precio, codigoVuelo,tipoPasajero, estadoVuelos);
}

void ordenarPasajerosPorApellidoYTipo(ePasajero listaPrincipalPasajeros[], int TAM)
{
    int i;
    int j;
    int retornoCmp;
    ePasajero auxiliar;

    for(i=0; i<TAM-1; i++)
    {
    	for(j=i+1; j<TAM; j++)
    	{
    		retornoCmp = strcmp(listaPrincipalPasajeros[i].apellido, listaPrincipalPasajeros[j].apellido);
    		if(retornoCmp < 0)
    		{
    			auxiliar = listaPrincipalPasajeros[i];
    			listaPrincipalPasajeros[i] = listaPrincipalPasajeros[j];
    			listaPrincipalPasajeros[j] = auxiliar;
    		}else{
    			if(retornoCmp == 0 && (listaPrincipalPasajeros[i].tipoPasajero < listaPrincipalPasajeros[j].tipoPasajero))
    			{
    				auxiliar = listaPrincipalPasajeros[i];
    				listaPrincipalPasajeros[i] = listaPrincipalPasajeros[j];
    				listaPrincipalPasajeros[j] = auxiliar;
    			}
    		}
    	}
    }
}


void mostrarTotalYPromedioPrecioPasajerosSuperiorPromedio(ePasajero listaPrincipalPasajeros[], int TAM)
{
    int i;
    int contadorPrecio;
    float sumaPrecio;
    float promedioPrecio;
    int pasajerosSuperiorPromedio;
    int largo;

    contadorPrecio = 0;
    promedioPrecio = 0;
    sumaPrecio = 0;

    largo = cantidadPasajeros(listaPrincipalPasajeros, TAM);

    if(largo > 0)
    {
        for(i=0; i<TAM; i++)
        {
            if(listaPrincipalPasajeros[i].isEmpty == OCUPADO)
            {
            	sumaPrecio = sumaPrecio + listaPrincipalPasajeros[i].precio;
                contadorPrecio++;
            }
        }

        promedioPrecio = sumaPrecio / contadorPrecio;

        pasajerosSuperiorPromedio = pasajerosSuperanSalarioPromedio(listaPrincipalPasajeros, TAM, promedioPrecio);

        printf("\nEmpleados cargados hasta el momento: \n");
        mostrarPasajeros(listaPrincipalPasajeros, TAM);

        printf("\nEl total del precio de los pasajes es: %.2f", sumaPrecio);
        printf("\nEl promedio del precio de los pasajes es: %.2f", promedioPrecio);
        printf("\nLa cantidad de pasajeros que superan el precio promedio del pasaje es: %d\n", pasajerosSuperiorPromedio);

    }
    else
    {
        printf("\nNo hay empleados cargados para mostrar el promedio de los precios de los vuelos, total de precios de pasajes y la cantidad de pasajeros que lo superan.");
    }
}

int pasajerosSuperanSalarioPromedio(ePasajero listaPrincipalPasajeros[], int tam, float precioPromedio)
{
    int i;
    int pasajerosSuperiorPromedio;

    pasajerosSuperiorPromedio = 0;

    for(i=0; i<tam; i++)
    {
        if(listaPrincipalPasajeros[i].isEmpty == OCUPADO)
        {
            if(listaPrincipalPasajeros[i].precio > precioPromedio)
            {
            	pasajerosSuperiorPromedio++;
            }
        }
    }

    return pasajerosSuperiorPromedio;
}

int cantidadPasajeros(ePasajero listaPrincipalPasajeros[], int TAM)
{
	int i;
	int contador;

	contador = 0;

	for(i=0; i<TAM; i++)
	{
		if(listaPrincipalPasajeros[i].isEmpty == OCUPADO)
		{
			contador++;
		}
	}
	return contador;
}


void ordenarPasajerosPorCodigo(ePasajero listaPrincipalPasajeros[], int TAM)
{
  int i;
  int j;
  int retornoCmp;

  ePasajero auxiliar;

  for(i=0; i<TAM-1; i++)
  {
	  for(j=i+1; j<TAM; j++)
	  {
		  {
			  retornoCmp = strcmp(listaPrincipalPasajeros[i].codigoViaje, listaPrincipalPasajeros[j].codigoViaje);

			  printf("%d", retornoCmp);

			  if(retornoCmp > 0 && listaPrincipalPasajeros[i].isEmpty == OCUPADO && listaPrincipalPasajeros[j].isEmpty == OCUPADO)
			  {
				  	  auxiliar = listaPrincipalPasajeros[i];
				  	  listaPrincipalPasajeros[i] = listaPrincipalPasajeros[j];
				  	  listaPrincipalPasajeros[j] = auxiliar;
			  }
		  }
	  }
  }
  printf( " _____________________________________________________________________________________________________________________\n"
		  "|---ID-------NOMBRE-------APELLIDO-------PRECIO-------CODIGO DE VUELO-------TIPO DE PASAJERO-------ESTADO DEL VUELO---| \n");

  	for(i = 0; i < TAM; i++)
  	{
  		if(listaPrincipalPasajeros[i].isEmpty == OCUPADO && listaPrincipalPasajeros[i].estadoVuelos == 1)
  		{
  			mostrarUnPasajero(listaPrincipalPasajeros[i],TAM);
  		}
  	}
  	printf( "|_____________________________________________________________________________________________________________________| \n");
}
