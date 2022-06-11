#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "MenusReportsOthers.h"
#include "GetPassengerData.h"
#include "GetData.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListPassenger) {
	return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListPassenger) {
	return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList *pArrayListPassenger) {
	char pName[50] = " ";
	char pLastName[50] = " ";
	int auxTipoPax = -1;
	char pFlightCode[8] = " ";
	float auxPrice = -1;
	int exitValueGetOptionSubMenu;
	int submenuOption;

	do {
		printSubMenuAddPax(pName, pLastName, auxTipoPax, pFlightCode, auxPrice);
		exitValueGetOptionSubMenu = askIntValue(&submenuOption, "Ingrese una opción: ",
				"La opción ingresada no es correcta.", 1, 7, 3);
		if (exitValueGetOptionSubMenu == 0) {
			switch (submenuOption) {
			case 1:
				if (getPassengersName(pName, 50, 3)) {
					printf("El nombre no fue salvado. Intente nuevamente.\n");
				}
				break;
			case 2:
				if (getPassengersLastName(pLastName, 50, 3)) {
					printf("El apellido no fue salvado. Intente nuevamente.\n");
				}
				break;
			case 3:
				if (getPassengersType(&auxTipoPax, 3)) {
					printf("El tipo de pasajero no fue salvado. Intente nuevamente.\n");
				}
				break;
			case 4:
				if (getPassengersFlightCode(pFlightCode, 8, 3)) {
					printf("El código del vuelo no fue salvado. Intente nuevamente.\n");
				}
				break;
			case 5:
				if (getPassengersPrice(&auxPrice, 1, 5000000, 3)) {
					printf("El precio del vuelo no fue salvado. Intente nuevamente.\n");
				}
				break;
			case 6:
//				if (addPassenger(passenger, LEN_PAX, auxPax.name, LEN_TEXT_CHAR,
//						auxPax.lastName, LEN_TEXT_CHAR, auxPax.passengerType,
//						auxPax.flightCode, LEN_FLIGHT_CODE, auxPax.price)) {
//					printf("El pasajero no fue salvado. Intente nuevamente.\n");
//				}
				printf("Pasajero guardado.\n");
//				strncpy(auxPax.name, "    ", LEN_TEXT_CHAR);
//				strncpy(auxPax.lastName, "    ", LEN_TEXT_CHAR);
//				auxPax.passengerType = -1;
//				strncpy(auxPax.flightCode, "    ", LEN_TEXT_CHAR);
//				auxPax.price = -1;
				break;
			case 7:
				break;
			}
		}
		if (exitValueGetOptionSubMenu < 0) {
			printf(
					"\n============================================================================="
							"=======================================\n");
			printf(
					"\nLa opción ingresada no es válida y se quedó sin intentos.\nVuelva a intentarlo en unos minutos."
							"\nEl pasajero no fue agregado.");
		}
	} while (submenuOption != 7 && exitValueGetOptionSubMenu == 0);

	return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList *pArrayListPassenger) {
	return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList *pArrayListPassenger) {
	return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList *pArrayListPassenger) {
	return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList *pArrayListPassenger) {
	return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListPassenger) {
	return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListPassenger) {
	return 1;
}

