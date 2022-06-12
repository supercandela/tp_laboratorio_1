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
#define LEN_PAXTYPE 50

/**
* \brief Prints the wellcome message on the screen
* \param void
* \return void
*
*/
void printWellcomeMessage() {
	printf("�Bienvenido!\n");
}

/**
* \brief Prints the principal menu on the screen
* \param void
* \return void
*
*/
void printPrincipalMenu() {
	printf("\n====================================================================================================================\n");
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
* \param char array	passenger�s name
* \param char array	passenger�s lastname
* \param int passenger�s type
* \param char array flycode
* \param float flight�s price
* \return void
*
*/
void printSubMenuAddPax(char name[], char lastName[], int passengerType, char flightCode[], float price) {
	char paxType[LEN_PAXTYPE];
	printf("\n====================================================================================================================\n");
	printf("1. Nombre Pasajero: 	%s\n", name);
	printf("2. Apellido Pasajero: 	%s\n", lastName);
	if (passengerType < 1) {
		printf("3. Tipo de Pasajero:\n");
	} else {
		switch(passengerType) {
			case FIRSTCLASS:
				strncpy( paxType, "First Class", LEN_PAXTYPE);
				break;
			case EXECUTIVECLASS:
				strncpy( paxType, "Executive Class", LEN_PAXTYPE);
				break;
			case ECONOMYCLASS:
				strncpy( paxType, "Economy Class", LEN_PAXTYPE);
				break;
		}
		printf("3. Tipo de Pasajero: 	%s\n", paxType);
	}
	printf("4. C�digo del vuelo: 	%s\n", flightCode);
	if (price < 1) {
		printf("5. Precio del vuelo:\n");
	} else {
		printf("5. Precio del vuelo: 	$%.2f\n", price);
	}
	printf("6. Guardar datos Pasajero\n");
	printf("7. Volver atr�s\n");
}
