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
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "MenusReportsOthers.h"
#include "GetData.h"

int main() {
	setbuf(stdout, NULL);
//	printf("Anduvo de nuevo\n");

	int exitValueGetOption;
	int menuOption;

	printWellcomeMessage();

	LinkedList* listaPasajeros = ll_newLinkedList();

//	int newId;
//	newId = getNewId();
//	printf("\n%d", newId);

	do {
		printPrincipalMenu();
		fflush(stdin);
		exitValueGetOption = askIntValue(&menuOption,
				"\n====================================================================================================================\n"
				"\nIngrese una opción: ", "La opción ingresada no es correcta.", 1, 10, 3);

		if (exitValueGetOption == 0) {
			switch (menuOption) {
			case 1:
				printf(" 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
				//controller_loadFromText("data.csv",listaPasajeros);
				break;
			case 2:
				printf(" 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
//				int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
				break;
			case 3:
				if (controller_addPassenger(listaPasajeros) != 0) {
					printf("\nNo se pueden agregar pasajeros en este momento.\n");
				}
				break;
			case 4:
				printf(" 4. Modificar datos de pasajero\n");
//				int controller_editPassenger(LinkedList* pArrayListPassenger);
				break;
			case 5:
				printf(" 5. Baja de pasajero\n");
//				int controller_removePassenger(LinkedList* pArrayListPassenger);
				break;
			case 6:
				printf(" 6. Listar pasajeros\n");
//				int controller_ListPassenger(LinkedList* pArrayListPassenger);
				break;
			case 7:
				printf(" 7. Ordenar pasajeros\n");
//				int controller_sortPassenger(LinkedList* pArrayListPassenger);
				break;
			case 8:
				printf(" 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
//				int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
				break;
			case 9:
				printf(" 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
//				int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
				break;
			case 10:
				printf("\n============================================================================================="
						"=======================\n"
						"\nUsted salió del programa. Para continuar trabajando, vuelva a iniciar.\n"
						"\n============================================================================================="
						"=======================\n");
				break;
			}
		}
	} while (menuOption != 10 && exitValueGetOption == 0);

	if (exitValueGetOption < 0) {
		printf("\n======================================================================================================="
				"=============\n");
		printf("\nLa opción ingresada no es válida y se quedó sin intentos.\nVuelva a intentarlo en unos minutos.");
	}

	return 0;
}

