/*
 ============================================================================
 TP_[3]
 Name        : main.c
 Author      : Candela Bogado
 Divisi�n    : 1 "E"
 Copyright   : � Candela Bogado - 2022
 Description : Trabajo Pr�ctico 3 - Laboratorio 1
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

	do {
		printPrincipalMenu();
		fflush(stdin);
		exitValueGetOption = askIntValue(&menuOption,
				"\n====================================================================================================================\n"
				"Ingrese una opci�n: ", "La opci�n ingresada no es correcta.", 1, 10, 3);

		if (exitValueGetOption == 0) {
			switch (menuOption) {
			case 1:
				printf(" 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
				//controller_loadFromText("data.csv",listaPasajeros);
				break;
			case 2:
				printf(" 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
				break;
			case 3:
				printf(" 3. Alta de pasajero\n");
				controller_addPassenger(listaPasajeros);
				break;
			case 4:
				printf(" 4. Modificar datos de pasajero\n");
				break;
			case 5:
				printf(" 5. Baja de pasajero\n");
				break;
			case 6:
				printf(" 6. Listar pasajeros\n");
				break;
			case 7:
				printf(" 7. Ordenar pasajeros\n");
				break;
			case 8:
				printf(" 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
				break;
			case 9:
				printf(" 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
				break;
			case 10:
				printf("\n============================================================================================="
						"=======================\n"
						"\nUsted sali� del programa. Para continuar trabajando, vuelva a iniciar.\n"
						"\n============================================================================================="
						"=======================\n");
				break;
			}
		}
	} while (menuOption != 10 && exitValueGetOption == 0);

	if (exitValueGetOption < 0) {
		printf("\n======================================================================================================="
				"=============\n");
		printf("\nLa opci�n ingresada no es v�lida y se qued� sin intentos.\nVuelva a intentarlo en unos minutos.");
	}

	return 0;
}
