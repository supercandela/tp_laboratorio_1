/*
 * MenusReportsOthers.c
 *
 *  Author: Candela Bogado
 *  Created on: 12 Mayo 2022
 *
*  Description: TP2 - Functions that prints information on the screen and manage the menus
 */

#include <stdio.h>
#include <string.h>
#include "GetData.h"
#include "Passengers.h"

#define LEN_TEXT_CHAR 51
#define LEN_FLIGHT_CODE 10

/**
* \brief Prints the wellcome message on the screen
* \param void
* \return Int - 0 : success
*
*/
int printWellcomeMessage() {
	printf("¡Bienvenido!\n");

	return 0;
}

/**
* \brief Prints the principal menu on the screen
* \param void
* \return Int - 0 : success
*
*/
int printPrincipalMenu() {
	printf("OPCIONES:\n");
	printf("1. Alta Pasajero\n");
	printf("2. Modificar Pasajero\n");
	printf("3. Baja Pasajero\n");
	printf("4. Informes\n");
	printf("5. Listado de Pasajeros\n");
	printf("6. Listado de vuelos\n");
	printf("7. Carga forzada de Datos\n");
	printf("8. Salir\n");

	return 0;
}

/**
* \brief Asks the end user for the option of the menu
* \param int pointer to selected option
* \param int minimum accepted value
* \param int maximum accepted value
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getOption(int *pNumber, int minimumValue, int maximumValue, int tries) {
	int validation;
	fflush( stdin );
	validation = -1;
	if (pNumber != NULL && tries > 0){
		do {
			printf("\n====================================================================================================================\n");
			printf("\nIngrese una opción: ");
			validation = getInt(pNumber, minimumValue, maximumValue);
			tries--;
			if (validation != 0 && tries > 0) {
				printf("\nLa opción ingresada no es correcta.\nPor favor, ingrese una opción entre %d y %d. "
						"Usted tiene %d intentos.\n", minimumValue, maximumValue, tries);
			}
		} while (validation != 0 && tries > 0);
	}
	return validation;
}

/**
* \brief Prints the sub menu to add a passenger
* \param char array	passenger´s name
* \param char array	passenger´s lastname
* \param int passenger´s type
* \param char array flycode
* \param float flight´s price
* \return Int - 0 : success
*
*/
int printSubMenuAddPax(char name[], char lastName[], int passengerType, char flightCode[], float price) {
	char paxType[15];
	printf("1. Nombre Pasajero: 	%s\n", name);
	printf("2. Apellido Pasajero: 	%s\n", lastName);
	if (passengerType < 1) {
		printf("3. Tipo de Pasajero:\n");
	} else {
		switch(passengerType) {
			case FIRST_CLASS:
				strncpy( paxType, "First Class", 15);
				break;
			case BUSINESS:
				strncpy( paxType, "Business", 15);
				break;
			case PREMIUM:
				strncpy( paxType, "Premium", 15);
				break;
			case TURIST:
				strncpy( paxType, "Turist", 15);
				break;
		}
		printf("3. Tipo de Pasajero: 	%s\n", paxType);
	}
	printf("4. Código del vuelo: 	%s\n", flightCode);
	if (price < 1) {
		printf("5. Precio del vuelo:\n");
	} else {
		printf("5. Precio del vuelo: 	$%.2f\n", price);
	}
	printf("6. Guardar datos Pasajero\n");
	printf("7. Volver atrás\n");

	return 0;
}

/**
* \brief Prints the sub menu to modify a passenger
* \param char array	passenger´s name
* \param char array	passenger´s lastname
* \param int passenger´s type
* \param char array flycode
* \param float flight´s price
* \return Int - 0 : success
*
*/
int printSubMenuModifyPax(char name[], char lastName[], int passengerType, char flightCode[], float price) {
	char paxType[15];
	printf("1. Nombre Pasajero: 	%s\n", name);
	printf("2. Apellido Pasajero: 	%s\n", lastName);
	if (passengerType < 1) {
		printf("3. Tipo de Pasajero:\n");
	} else {
		switch(passengerType) {
			case FIRST_CLASS:
				strncpy( paxType, "First Class", 15);
				break;
			case BUSINESS:
				strncpy( paxType, "Business", 15);
				break;
			case PREMIUM:
				strncpy( paxType, "Premium", 15);
				break;
			case TURIST:
				strncpy( paxType, "Turist", 15);
				break;
		}
		printf("3. Tipo de Pasajero: 	%s\n", paxType);
	}
	printf("4. Código del vuelo: 	%s\n", flightCode);
	if (price < 1) {
		printf("5. Precio del vuelo:\n");
	} else {
		printf("5. Precio del vuelo: 	$%.2f\n", price);
	}
	printf("6. Volver atrás\n");

	return 0;
}

/**
* \brief Prints the sub menu to reports
* \param void
* \return Int - 0 : success
*
*/
int printSubMenuReports() {
	printf("1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n");
	printf("2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n");
	printf("3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’. \n");
	printf("4. Volver atrás. \n");
	return 0;
}


