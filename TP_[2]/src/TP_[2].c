/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Candela Bogado
 División    : 1 "E"
 Copyright   : © Candela Bogado - 2022
 Description : Trabajo Práctico 2 - Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "MenusReportsOthers.h"
#include "Passengers.h"

#define LEN_PAX 5


/**
* \brief Main function
* \param void - none
* \return Int - 0 : success
*
*/
int main(void) {
	setbuf(stdout, NULL);

	Passengers passenger[LEN_PAX];
	int menuOption;
	int exitValueGetOption;

	initPassengers(passenger, LEN_PAX);
//	INICIALIZAR ESTRUCTURA VUELOS

	printWellcomeMessage();

	do {
		printPrincipalMenu();

		exitValueGetOption = getOption(&menuOption, 1, 7, 3);

		if (exitValueGetOption == 0) {
			switch(menuOption) {
				case 1:
					printf("1. Alta Pasajero\n");
					break;
				case 2:
					printf("2. Modificar Pasajero\n");
					break;
				case 3:
					printf("3. Baja Pasajero\n");
					break;
				case 4:
					printf("4. Informes\n");
					break;
				case 5:
					printf("5. Listado de Pasajeros\n");
					break;
				case 6:
					printf("6. Listado de vuelos\n");
					break;
				case 7:
					printf("\n====================================================================================================================\n"
							"\n¡Muchas gracias por su visita!\nUsted salió del programa. Para ingresar más datos, vuelva a iniciar.\n"
							"\n====================================================================================================================\n");
					break;
			}
		}
	} while (menuOption != 7 && exitValueGetOption == 0);

	if (exitValueGetOption < 0) {
		printf("\n====================================================================================================================\n");
		printf("\nLa opción ingresada no es válida y se quedó sin intentos.\nVuelva a intentarlo en unos minutos.");
	}

	return 0;
}
