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
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListPassenger) {
	int validation;
	validation = -1;
	if(path != NULL && pArrayListPassenger != NULL) {
	    FILE * textFile;

		int cant;
		char aux1[128];
		char aux2[128];
		char aux3[128];
		char aux4[128];
		char aux5[128];
		char aux6[128];
		char aux7[128];

	    if((textFile = fopen(path,"r")) == NULL) {
			printf("No se pudo abrir el archivo");
	    } else {
	    	do {
	    		cant = fscanf(textFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", aux1, aux2, aux3, aux4, aux5, aux6, aux7);
		    	if (cant == 7) {
		    		printf("%s - %s - %s - %s - %s - %s - %s\n", aux1, aux2, aux3, aux4, aux5, aux6, aux7);
		    	}
	    	} while (cant == 7);
			fclose(textFile);
			validation = 0;
	    }
	}
	return validation;
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
						if (!ll_add(pArrayListPassenger, auxPax)){
							printf("Pasajero guardado.\n");
							strncpy(pName, " ", LEN_TEXT_CHAR);
							strncpy(pLastName, " ", LEN_TEXT_CHAR);
							auxTipoPax = -1;
							strncpy(pFlightCode, " ", LEN_TEXT_CHAR);
							auxPrice = -1;
						} else {
							printf("Se produjo un error. Pasajero NO guardado.\n");
						}
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
 * \param pArrayListPassenger LinkedList*
 * \return int 0 =  Success / -1 = Error
 *
 */
int controller_ListPassenger(LinkedList *pArrayListPassenger) {
	int validation;
	validation = -1;
	if (pArrayListPassenger != NULL) {
		validation = printPassengers(pArrayListPassenger);
	}
	return validation;
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

