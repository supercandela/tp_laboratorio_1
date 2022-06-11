#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "MenusReportsOthers.h"
#include "GetPassengerData.h"
#include "GetData.h"

#define LEN_TEXT_CHAR 50

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

/**
 * \brief Prints one passenger on a formated list
 * \param Passengers passenger
 * \return void
 *
 */
void showPax(Passenger *pax) {
	if (pax != NULL) {
		int column_id = 8;
		int column_text = -30;
		int column_type = -20;
		int column_code = -12;
		int column_price = 15 - 1; //resto 1 por el signo
		char paxType[15];
		switch (pax->tipoPasajero) {
		case 1:
			strncpy(paxType, "First Class", 15);
			break;
		case 2:
			strncpy(paxType, "Executive", 15);
			break;
		case 3:
			strncpy(paxType, "Economy", 15);
			break;
		}
		printf("|%*d|%*s|%*s|%*s|%*s|$%*.2f|\n", column_id, pax->id,
				column_text, pax->apellido, column_text, pax->nombre,
				column_type, paxType, column_code, pax->codigoVuelo,
				column_price, pax->precio);
	}
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList *pArrayListPassenger) {
	int validation;
	validation = -1;
	if (pArrayListPassenger != NULL) {
		char pName[LEN_TEXT_CHAR] = " ";
		char pLastName[LEN_TEXT_CHAR] = " ";
		char pFlightCode[LEN_TEXT_CHAR] = " ";
		int auxTipoPax = -1;
		float auxPrice = -1;
		int exitValueGetOptionSubMenu;
		int submenuOption;
		Passenger *auxPax;
		int prueba;

		do {
			printSubMenuAddPax(pName, pLastName, auxTipoPax, pFlightCode,
					auxPrice);
			exitValueGetOptionSubMenu = askIntValue(&submenuOption,
							"\n================================================================================"
							"====================================\n\nIngrese una opción: ",
							"La opción ingresada no es correcta.", 1, 7, 3);
			if (exitValueGetOptionSubMenu == 0) {
				switch (submenuOption) {
				case 1:
					if (getPassengersName(pName, LEN_TEXT_CHAR, 3)) {
						printf(
								"El nombre no fue salvado. Intente nuevamente.\n");
					}
					break;
				case 2:
					if (getPassengersLastName(pLastName, LEN_TEXT_CHAR, 3)) {
						printf(
								"El apellido no fue salvado. Intente nuevamente.\n");
					}
					break;
				case 3:
					if (getPassengersType(&auxTipoPax, 3)) {
						printf(
								"El tipo de pasajero no fue salvado. Intente nuevamente.\n");
					}
					break;
				case 4:
					if (getPassengersFlightCode(pFlightCode, LEN_TEXT_CHAR,
							3)) {
						printf(
								"El código del vuelo no fue salvado. Intente nuevamente.\n");
					}
					break;
				case 5:
					if (getPassengersPrice(&auxPrice, 1, 5000000, 3)) {
						printf(
								"El precio del vuelo no fue salvado. Intente nuevamente.\n");
					}
					break;
				case 6:
					auxPax = Passenger_newParametros(pName, pLastName, auxPrice,
							auxTipoPax, pFlightCode);
					if (auxPax == NULL) {
						printf(
								"El pasajero no fue salvado. Intente nuevamente.\n");
					} else {
						printf("Pasajero guardado.\n");
						prueba = ll_add(pArrayListPassenger, auxPax);
						printf("prueba %d\n", prueba);
						auxPax = ll_get(pArrayListPassenger, 0);
						showPax(auxPax);
						strncpy(pName, " ", LEN_TEXT_CHAR);
						strncpy(pLastName, " ", LEN_TEXT_CHAR);
						auxTipoPax = -1;
						strncpy(pFlightCode, " ", LEN_TEXT_CHAR);
						auxPrice = -1;
					}
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
			validation = 0;
		} while (submenuOption != 7 && exitValueGetOptionSubMenu == 0);

	}
	return validation;
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

