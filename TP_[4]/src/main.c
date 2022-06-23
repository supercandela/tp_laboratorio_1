/*
 ============================================================================
 TP_[3]
 Name        : main.c
 Author      : Candela Bogado
 División    : 1 "E"
 Copyright   : © Candela Bogado - 2022
 Description : Trabajo Práctico 3 - Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "MenusReportsOthers.h"
#include "GetData.h"

#include "Passenger.h"
#include "GetPassengerData.h"

int main() {
	setbuf(stdout, NULL);

	int exitValueGetOption;
	int menuOption;
	int flagLoadFile;

	printWellcomeMessage();

	LinkedList* listaPasajeros = ll_newLinkedList();
	flagLoadFile = 0;

	if (listaPasajeros != NULL) {
		do {
				printPrincipalMenu();
				fflush(stdin);
				exitValueGetOption = askIntValue(&menuOption,
						"\n=============================================================================="
						"===========================================================================\n"
						"\nIngrese una opción: ", "\n=============================================================================="
						"===========================================================================\n"
						"\nLa opción ingresada no es correcta.", 1, 10, 3);

				if (exitValueGetOption == 0) {
					switch (menuOption) {
					case 1:
						if (flagLoadFile == 0) {
							if (controller_loadFromText("data.csv", listaPasajeros) != 0) {
								printf("\nNo se pueden cargar los datos de los pasajeros desde el archivo en este momento.\n");
							} else {
								flagLoadFile = 1;
								printSeparationLine();
								printf("\nArchivo cargado exitosamente.\n");
							}
						} else {
							printSeparationLine();
							printf("\nNo puede repetir la carga del archivo.\n");
						}
						break;
					case 2:
						if (flagLoadFile == 0) {
							if (controller_loadFromBinary("data.bin", listaPasajeros) != 0) {
								printf("\nNo se pueden cargar los datos de los pasajeros desde el archivo en este momento.\n");
							} else {
								flagLoadFile = 1;
								printSeparationLine();
								printf("\nArchivo cargado exitosamente.\n");
							}
						} else {
							printSeparationLine();
							printf("\nNo puede repetir la carga del archivo.\n");
						}
						break;
					case 3:
						if (controller_addPassenger(listaPasajeros) != 0) {
							printf("\nNo se pueden agregar pasajeros en este momento.\n");
						}
						break;
					case 4:
						if (ll_isEmpty(listaPasajeros) != 0) {
							printErrorNoPassengers();
						} else if (controller_editPassenger(listaPasajeros) != 0) {
							printf("\nNo se puede editar pasajeros en este momento.\n");
						}
						break;
					case 5:
						if (ll_isEmpty(listaPasajeros) != 0) {
							printErrorNoPassengers();
						} else if (controller_removePassenger(listaPasajeros) != 0) {
							printf("\nNo se puede borrar pasajeros en este momento.\n");
						}
						break;
					case 6:
						if (ll_isEmpty(listaPasajeros) != 0) {
							printErrorNoPassengers();
						} else if (controller_ListPassenger(listaPasajeros) != 0) {
							printf("\nNo se pueden listar los pasajeros en este momento.\n");
						}
						break;
					case 7:
						if (ll_isEmpty(listaPasajeros) != 0) {
							printErrorNoPassengers();
						} else if (controller_sortPassenger(listaPasajeros) != 0) {
							printf("\nNo se pueden ordenar los pasajeros en este momento.\n");
						}
						break;
					case 8:
						if (ll_isEmpty(listaPasajeros) != 0) {
							printErrorNoPassengers();
						} else if (controller_saveAsText("data.csv", listaPasajeros) != 0) {
							printf("\nNo se pueden ordenar los pasajeros en este momento.\n");
						} else {
							printSeparationLine();
							printf("\nArchivo guardado exitosamente.\n");
						}
						break;
					case 9:
						if (ll_isEmpty(listaPasajeros) != 0) {
							printErrorNoPassengers();
						} else if (controller_saveAsBinary("data.bin", listaPasajeros) != 0) {
							printf("\nNo se pueden guardar los pasajeros en este momento.\n");
						} else {
							printSeparationLine();
							printf("\nArchivo guardado exitosamente.\n");
						}
						break;
					case 10:
						printSeparationLine();
						printf("\nUsted salió del programa. Para continuar trabajando, vuelva a iniciar.\n");
						printSeparationLine();
						break;
					}
				}
			} while (menuOption != 10 && exitValueGetOption == 0);

			if (exitValueGetOption < 0) {
				printSeparationLine();
				printf("\nLa opción ingresada no es válida y se quedó sin intentos.\nVuelva a intentarlo en unos minutos.");
			}
	} else {
		printSeparationLine();
		printf("\nOcurrió un error. Vuelva a intentarlo en unos minutos.");
	}

	return 0;
}

