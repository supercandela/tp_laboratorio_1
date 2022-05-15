/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Candela Bogado
 División    : 1 "E"
 Copyright   : © Candela Bogado - 2022
 Description : Trabajo Práctico 2 - Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MenusReportsOthers.h"
#include "Passengers.h"
#include "Flights.h"

#define LEN_PAX 15
#define LEN_FLIGHT 15
#define LEN_TEXT_CHAR 51
#define LEN_FLIGHT_CODE 10

/**
* \brief Main function
* \param void - none
* \return Int - 0 : success
*
*/
int main(void) {
	setbuf(stdout, NULL);

	Passengers passenger[LEN_PAX];
	Passengers auxPax;
	Flights flight[LEN_FLIGHT];
	int menuOption;
	int exitValueGetOption;
	int submenuOption;
	int exitValueGetOptionSubMenu;
	int pax_id;

	initPassengers(passenger, LEN_PAX);
	initFlights(flight, LEN_FLIGHT);

	printWellcomeMessage();

	do {
		printPrincipalMenu();
		fflush( stdin );
		exitValueGetOption = getOption(&menuOption, 1, 8, 3);

		if (exitValueGetOption == 0) {
			switch(menuOption) {
				case 1:
					strncpy( auxPax.name, "    ", LEN_TEXT_CHAR);
					strncpy( auxPax.lastName, "    ", LEN_TEXT_CHAR);
					auxPax.passengerType = -1;
					strncpy( auxPax.flightCode, "    ", LEN_FLIGHT_CODE);
					auxPax.price = -1;

					do {
						printSubMenuAddPax( auxPax.name, auxPax.lastName, auxPax.passengerType, auxPax.flightCode, auxPax.price);
						exitValueGetOptionSubMenu = getOption(&submenuOption, 1, 7, 3);
						if (exitValueGetOptionSubMenu == 0) {
							switch(submenuOption) {
								case 1:
									if (getPassengersName( auxPax.name, LEN_TEXT_CHAR, 3)) {
										printf("El nombre no fue salvado. Intente nuevamente.\n");
									}
									break;
								case 2:
									if (getPassengersLastName( auxPax.lastName, LEN_TEXT_CHAR, 3)) {
										printf("El apellido no fue salvado. Intente nuevamente.\n");
									}
									break;
								case 3:
									if (getPassengersType( &auxPax.passengerType, 3)) {
										printf("El tipo de pasajero no fue salvado. Intente nuevamente.\n");
									}
									break;
								case 4:
									if (getPassengersFlightCode( auxPax.flightCode, LEN_FLIGHT_CODE,3)) {
										printf("El código del vuelo no fue salvado. Intente nuevamente.\n");
									}
									break;
								case 5:
									if (getPassengersPrice( &auxPax.price, 1, 5000000,3)) {
										printf("El precio del vuelo no fue salvado. Intente nuevamente.\n");
									}
									break;
								case 6:
									if (addPassenger( passenger, LEN_PAX, auxPax.name, LEN_TEXT_CHAR, auxPax.lastName, LEN_TEXT_CHAR,
											auxPax.passengerType, auxPax.flightCode, LEN_FLIGHT_CODE, auxPax.price)) {
										printf("El pasajero no fue salvado. Intente nuevamente.\n");
									}
									printf("Pasajero guardado.\n");
									strncpy( auxPax.name, "    ", LEN_TEXT_CHAR);
									strncpy( auxPax.lastName, "    ", LEN_TEXT_CHAR);
									auxPax.passengerType = -1;
									strncpy( auxPax.flightCode, "    ", LEN_TEXT_CHAR);
									auxPax.price = -1;
									break;
								case 7:
									break;
							}
						}
						if (exitValueGetOptionSubMenu < 0) {
							printf("\n============================================================================="
									"=======================================\n");
							printf("\nLa opción ingresada no es válida y se quedó sin intentos.\nVuelva a intentarlo en unos minutos."
									"\nEl pasajero no fue agregado.");
						}
					} while (submenuOption != 7 && exitValueGetOptionSubMenu == 0);
					break;
				case 2:
					exitValueGetOptionSubMenu = getPaxId(&pax_id, 1000, 3001, 3);
					if (exitValueGetOptionSubMenu == 0) {
						modifyPassenger(passenger, LEN_PAX, pax_id);
					} else {
						printf("\nLa opción ingresada no es válida y se quedó sin intentos.\nVuelva a intentarlo en unos minutos.\n");
					}
					break;
				case 3:
					exitValueGetOptionSubMenu = getPaxId(&pax_id, 1000, 3001, 3);
					if (exitValueGetOptionSubMenu == 0) {
						removePassenger(passenger, LEN_PAX, pax_id);
					} else {
						printf("\nLa opción ingresada no es válida y se quedó sin intentos.\nVuelva a intentarlo en unos minutos.\n");
					}
					break;
				case 4:
					do {
						printSubMenuReports();
						exitValueGetOptionSubMenu = getOption(&submenuOption, 1, 4, 3);
						switch(submenuOption) {
							case 1:
								sortsPaxByLastNameAndPrints(passenger, LEN_PAX, 1);
								break;
							case 2:
								totalPrice(passenger, LEN_PAX);
								break;
							case 3:
								sortsPaxByFlightCodeAndPrints(passenger, LEN_PAX, flight, LEN_FLIGHT);
								break;
							case 4:
								break;
						}
					} while (exitValueGetOptionSubMenu == 0 && submenuOption != 4);
					if (exitValueGetOptionSubMenu < 1) {
						printf("\nLa opción ingresada no es válida y se quedó sin intentos.\nVuelva a intentarlo en unos minutos.\n");
					}
					break;
				case 5:
					printPassengers(passenger, LEN_PAX);
					break;
				case 6:
					printFlights(flight, LEN_FLIGHT);
					break;
				case 7:
					if (!forcedLoadPassengersListWithPrechargeValues(passenger, LEN_PAX)){
						printf("\n========================================================================================"
								"============================\n"
								"Carga de pasajeros exitosa."
								"\n======================================================================================="
								"=============================\n");
					} else {
						printf("\n========================================================================================"
								"============================\n"
								"Carga de pasajeros fallida."
								"\n======================================================================================="
								"=============================\n");
					}
					if (!forcedLoadFlightsListWithPrechargeValues(flight, LEN_FLIGHT)){
						printf("\n========================================================================================"
								"============================\n"
								"Carga de vuelos exitosa."
								"\n======================================================================================="
								"=============================\n");
					} else {
						printf("\n========================================================================================"
								"============================\n"
								"Carga de vuelos fallida."
								"\n======================================================================================="
								"=============================\n");
					}
					break;
				case 8:
					printf("\n============================================================================================="
							"=======================\n"
							"\n¡Muchas gracias por su visita!\nUsted salió del programa. Para ingresar más datos, vuelva a iniciar.\n"
							"\n============================================================================================="
							"=======================\n");
					break;
			}
		}
	} while (menuOption != 8 && exitValueGetOption == 0);

	if (exitValueGetOption < 0) {
		printf("\n======================================================================================================="
				"=============\n");
		printf("\nLa opción ingresada no es válida y se quedó sin intentos.\nVuelva a intentarlo en unos minutos.");
	}

	return 0;
}
