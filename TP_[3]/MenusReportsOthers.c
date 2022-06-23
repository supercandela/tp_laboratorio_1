/*
 * MenusReportsOthers.c
 *
 *  Author: Candela Bogado
 *  Created on: 12 Mayo 2022
 *
*  Description: TP3 - Functions that prints information on the screen and manage the menus
 */

#include <stdio.h>
#include <string.h>
#include "GetData.h"

//passengerType
#define FIRSTCLASS 1
#define EXECUTIVECLASS 2
#define ECONOMYCLASS 3
#define LEN_PAXTYPE_STATUS 50

/**
* \brief Prints the wellcome message on the screen
* \param void
* \return void
*
*/
void printWellcomeMessage() {
	printf(
			"\n=========================================================================================================================================================\n");
	printf("\n                                         					B I E N V E N I D O \n");
	printf(
			"\n=========================================================================================================================================================\n");

}

/**
* \brief Prints a line of separation between elements
* \param void
* \return void
*
*/
void printSeparationLine() {
	printf("\n=========================================================================================================================================================\n");
}

/**
* \brief Prints an error message
* \param void
* \return void
*
*/
void printErrorNoPassengers() {
	printSeparationLine();
	printf("\nAún no hay pasajeros en la lista. Agregue pasajeros para poder ingresar a esta opción.\n");
}

/**
* \brief Prints the principal menu on the screen
* \param void
* \return void
*
*/
void printPrincipalMenu() {
	printSeparationLine();
	printf("OPCIONES:\n");
	printf(" 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
	printf(" 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
	printf(" 3. Alta de pasajero\n");
	printf(" 4. Modificar datos de pasajero\n");
	printf(" 5. Baja de pasajero\n");
	printf(" 6. Listar pasajeros\n");
	printf(" 7. Ordenar pasajeros\n");
	printf(" 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	printf(" 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
	printf("10. Salir\n");
}

/**
* \brief Prints the sub menu to add a passenger
* \param char array	passenger´s name
* \param char array	passenger´s lastname
* \param int passenger´s type
* \param char array flycode
* \param float flight´s price
* \return void
*
*/
void printSubMenuAddPax(char name[], char lastName[], int passengerType, char flightCode[], float price, int statusFlight) {
	char paxType[LEN_PAXTYPE_STATUS];
	char replaceStatus[LEN_PAXTYPE_STATUS];
	printSeparationLine();
	printf("1. Nombre Pasajero: 	%s\n", name);
	printf("2. Apellido Pasajero: 	%s\n", lastName);
	if (passengerType < 1) {
		printf("3. Tipo de Pasajero:\n");
	} else {
		switch(passengerType) {
			case FIRSTCLASS:
				strncpy( paxType, "First Class", LEN_PAXTYPE_STATUS);
				break;
			case EXECUTIVECLASS:
				strncpy( paxType, "Executive Class", LEN_PAXTYPE_STATUS);
				break;
			case ECONOMYCLASS:
				strncpy( paxType, "Economy Class", LEN_PAXTYPE_STATUS);
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
	if (statusFlight < 1) {
		printf("6. Estado del vuelo:\n");
	} else {
		switch(statusFlight) {
			case FIRSTCLASS:
				strncpy( replaceStatus, "En horario", LEN_PAXTYPE_STATUS);
				break;
			case EXECUTIVECLASS:
				strncpy( replaceStatus, "En vuelo", LEN_PAXTYPE_STATUS);
				break;
			case ECONOMYCLASS:
				strncpy( replaceStatus, "Aterrizado", LEN_PAXTYPE_STATUS);
				break;
		}
		printf("6. Estado del vuelo: 	%s\n", replaceStatus);
	}
	printf("7. Guardar datos Pasajero\n");
	printf("8. Volver atrás\n");
}

/**
* \brief Prints the sub menu to edit a passenger
* \param char array	passenger´s name
* \param char array	passenger´s lastname
* \param int passenger´s type
* \param char array flycode
* \param float flight´s price
* \return void
*
*/
void printSubMenuEditPax(char name[], char lastName[], int passengerType, char flightCode[], float price, int statusFlight) {
	char paxType[LEN_PAXTYPE_STATUS];
	char replaceStatus[LEN_PAXTYPE_STATUS];
	printSeparationLine();
	printf("1. Nombre Pasajero: 	%s\n", name);
	printf("2. Apellido Pasajero: 	%s\n", lastName);
	if (passengerType < 1) {
		printf("3. Tipo de Pasajero:\n");
	} else {
		switch(passengerType) {
			case FIRSTCLASS:
				strncpy( paxType, "First Class", LEN_PAXTYPE_STATUS);
				break;
			case EXECUTIVECLASS:
				strncpy( paxType, "Executive Class", LEN_PAXTYPE_STATUS);
				break;
			case ECONOMYCLASS:
				strncpy( paxType, "Economy Class", LEN_PAXTYPE_STATUS);
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
	if (statusFlight < 1) {
		printf("6. Estado del vuelo:\n");
	} else {
		switch(statusFlight) {
			case FIRSTCLASS:
				strncpy( replaceStatus, "En horario", LEN_PAXTYPE_STATUS);
				break;
			case EXECUTIVECLASS:
				strncpy( replaceStatus, "En vuelo", LEN_PAXTYPE_STATUS);
				break;
			case ECONOMYCLASS:
				strncpy( replaceStatus, "Aterrizado", LEN_PAXTYPE_STATUS);
				break;
		}
		printf("6. Estado del vuelo: 	%s\n", replaceStatus);
	}
	printf("7. Volver atrás\n");
}

/**
* \brief Prints the sub menu to sort passengers by criteria
* \param void
* \return void
*
*/
void printSubMenuSortPax() {
	printSeparationLine();
	printf("OPCIONES:\n");
	printf(" 1. Ordenar pasajeros por ID - Ascendente.\n");
	printf(" 2. Ordenar pasajeros por ID - Descendente.\n");
	printf(" 3. Ordenar pasajeros por Apellido - Ascendente.\n");
	printf(" 4. Ordenar pasajeros por Apellido - Descendente.\n");
	printf(" 5. Ordenar pasajeros por Tipo de Pasajero - Ascendente.\n");
	printf(" 6. Ordenar pasajeros por Tipo de Pasajero - Descendente.\n");
	printf(" 7. Ordenar pasajeros por Precio - Ascendente.\n");
	printf(" 8. Ordenar pasajeros por Precio - Descendente.\n");
	printf(" 9. Salir\n");
}
