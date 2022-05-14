/*
 * MenusReportsOthers.c
 *
 *  Author: Candela Bogado
 *  Created on: 12 Mayo 2022
 *
*  Description: TP2 - Functions that prints information on the screen and manage the menus
 */

#include <stdio.h>
#include "GetData.h"

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
	printf("7. Salir\n");

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
