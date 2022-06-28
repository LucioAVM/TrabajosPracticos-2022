/*
 ============================================================================
 Name        : TP1--2022.c
 Author      : Monsalbo Lucio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "calculosAuxiliares.h"

int main(void)
{
	setbuf(stdout, NULL);

	float latam;
	int kilometros;
	float aerolineas;
	int validacionOrden;

	float tarjetaDebitoLatam;
	float tarjetaCreditoLatam;
	float BTCLatam;
	float precioUnitarioLatam;

	float tarjetaDebitoAerolineas;
	float tarjetaCreditoAerolineas;
	float BTCAerolineas;
	float precioUnitarioAerolineas;

	float diferenciaPrecioVuelos;

	int porcentajeDescuento;
	int porcentajeInteres;
	float BTCPrecio;

	int opcionMenu;
														//INICIALIZACION
	porcentajeDescuento = 10;
	porcentajeInteres = 25;
	BTCPrecio = 4606954.55;

	validacionOrden = -1;


	do{
		opcionMenu = mostrarMenu();

		switch(opcionMenu)
		{
		case 1:
			kilometros = ingresarKilometros();
			break;


		case 2:
			validacionOrden = menuPrecioVuelos(&latam, &aerolineas);
			break;


		case 3:
			if(validacionOrden == 1)
			{
				calcularCostos(&tarjetaDebitoLatam,&tarjetaCreditoLatam,&BTCLatam,&precioUnitarioLatam
						,&tarjetaDebitoAerolineas,&tarjetaCreditoAerolineas,&BTCAerolineas,&precioUnitarioAerolineas,
						latam,aerolineas,kilometros,&diferenciaPrecioVuelos, porcentajeDescuento, porcentajeInteres, BTCPrecio);
			}else{
				printf("ERROR EN EL ORDEN DE INGRESO DE DATOS:\n"
						"no es posible realizar los calculos sin haber ingresado los kilometros o el precio de vuelo de ambas companias\n");
			}
			break;


		case 4:
			if(validacionOrden == 1)
			{
				mostrarResultados(tarjetaDebitoLatam,tarjetaCreditoLatam,BTCLatam,precioUnitarioLatam,
						tarjetaDebitoAerolineas,tarjetaCreditoAerolineas,BTCAerolineas,precioUnitarioAerolineas,
						diferenciaPrecioVuelos);
			}else{
				printf("ERROR EN EL ORDEN DE INGRESO DE DATOS:\n"
						"no es posible mostrar los calculos sin haber ingresado los kilometros o el precio de vuelo de ambas companias\n");
			}
			break;


		case 5:
			cargaForzada(porcentajeDescuento,porcentajeInteres,BTCPrecio,&latam,&aerolineas,&kilometros);
			validacionOrden = 1;
			break;
		}

		if(opcionMenu > 6 || opcionMenu < 1)
		{
			printf("ERROR, INGRESE UNA OPCION VALIDA");
		}

	}while(opcionMenu != 6);

	printf( "\n           GRACIAS POR UTILIZAR ESTE PROGRAMA\n"
						"             PRODUCIDO POR Monsalbo lucio\n"
						"              EDITADO POR Lucio Monsalbo\n"
						"         BUILDEADO POR Alejandro Lucio Monsalbo\n"
						"        TESTEADO POR Valerio Alejandro Monsalbo\n"
						"        ENVIADO POR Monsalbo Lucio Alejandro Valerio\n"
						"   AGRADECIMIENTO ESPECIAL A Lucio Alejandro Valerio Monsalbo\n");
	return EXIT_SUCCESS;
}
