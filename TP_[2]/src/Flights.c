/*
 * Flights.c
 *
 *  Author: Candela Bogado
 *  Created on: 14 Mayo 2022
 *
 *  Description: TP2 - Flights Library
 */

#include <stdio.h>
#include <string.h>
#include "Passengers.h"
#include "Flights.h"
#include "GetData.h"
#include "MenusReportsOthers.h"

/**
* \brief To indicate that all positions in the array are empty, this function puts the flag (isEmpty) in TRUE in all
* 			positions of the array list Flights* Pointer to array of flight
* \param Passengers Array pointer to array of Flights
* \param int array length
* \return Int - 0 : success - (-1) : error [Invalid length or NULL pointer]
*
*/
int initFlights(Flights pFlight[], int len) {
	int validation = -1;
	if (pFlight != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			pFlight[i].isEmpty = 1;
			validation = 0;
		}
	}
	return validation;
}

/**
* \brief Adds in an existing list of flights the values received as parameters in the first empty position
* \param Flights Array pointer to array of Flights
* \param int array length
* \param char array flycode
* \param int flycode array length
* \param int status of the flight
* \param int year
* \param int month
* \param int day
* \return Int - 0 : success - (-1) : error [Invalid length or NULL pointer or without free space]
*/
int addFlight(Flights pFlight[], int len_flight, char flightCode[], int len_flightCode, char pDestination[], int len_destination,
				int statusFlight, int year, int month, int day) {
	int validation = -1;
	int freeIndex;
	if (pFlight != NULL && len_flight > 0) {
		freeIndex = getFirstEmptyFlight(pFlight, len_flight);
		if (freeIndex != -1) {
			pFlight[freeIndex].id = getNewId();
			strncpy(pFlight[freeIndex].flightCode, flightCode, len_flightCode);
			strncpy(pFlight[freeIndex].destination, pDestination, len_destination);
			pFlight[freeIndex].statusFlight = statusFlight;
			pFlight[freeIndex].year = year;
			pFlight[freeIndex].month = month;
			pFlight[freeIndex].day = day;
			pFlight[freeIndex].isEmpty = 0;
			validation = 0;
		}
	}
	return validation;
}

/**
* \brief Finds if exists the first empty position on the Flights array
* \param Flights Array pointer to array of Flights
* \param int array length
* \return Int - firstEmptyIndex : success - (-1) : error
*
*/
int getFirstEmptyFlight(Flights pFlight[], int len) {
	int validation = -1;
	if (pFlight != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (pFlight[i].isEmpty == 1) {
				validation = i;
				break;
			}
		}
	}
	return validation;
}

/**
* \brief Hardcodes 10 flights on the array of flights
* \param Flights Array pointer to array of flights
* \param int array length
* \return Int - 0 : success - (-1) : error [Invalid length or NULL pointer or without free space]
*/
int forcedLoadFlightsListWithPrechargeValues(Flights pFlight[], int len) {
	int validation = -1;
	if (pFlight != NULL && len > 0) {
		addFlight(pFlight, len, "ECR082903", LEN_FLIGHT_CODE, "El Cairo", LEN_TEXT_CHAR, 1, 2022, 8, 29);
		addFlight(pFlight, len, "MDR091503", LEN_FLIGHT_CODE, "Madrid", LEN_TEXT_CHAR, 1, 2022, 9, 15);
		addFlight(pFlight, len, "BCN052816", LEN_FLIGHT_CODE, "Barcelona", LEN_TEXT_CHAR, 1, 2022, 5, 28);
		addFlight(pFlight, len, "CNC061245", LEN_FLIGHT_CODE, "Cancun", LEN_TEXT_CHAR, 2, 2022, 6, 12);
		addFlight(pFlight, len, "MDQ070902", LEN_FLIGHT_CODE, "Mar del Plata", LEN_TEXT_CHAR, 2, 2022, 7, 9);
		addFlight(pFlight, len, "CLF022203", LEN_FLIGHT_CODE, "Calafate", LEN_TEXT_CHAR, 3, 2023, 2, 22);
		addFlight(pFlight, len, "BST061304", LEN_FLIGHT_CODE, "Boston", LEN_TEXT_CHAR, 4, 2023, 6, 13);
		addFlight(pFlight, len, "TRP072560", LEN_FLIGHT_CODE, "Saint Tropez", LEN_TEXT_CHAR, 5, 2022, 7, 25);
		addFlight(pFlight, len, "TKO122404", LEN_FLIGHT_CODE, "Tokio", LEN_TEXT_CHAR, 4, 2022, 12, 24);
		addFlight(pFlight, len, "QTR111260", LEN_FLIGHT_CODE, "Qatar", LEN_TEXT_CHAR, 5, 2022, 11, 12);
		validation = 0;
	}
	return validation;
}

/**
* \brief Prints one flight on a formated list
* \param Flights flight
* \return void
*
*/
void showFlight(Flights flight) {
	if (flight.isEmpty == 0){
		int column_id = 8;
		int column_code = -12;
		int column_text = -30;
		int column_type = -20;
		char status[15];
		switch(flight.statusFlight) {
			case ACTIVO:
				strncpy( status, "Activo", 15);
				break;
			case DEMORADO:
				strncpy( status, "Demorado", 15);
				break;
			case REPROGRAMADO:
				strncpy( status, "Reprogramado", 15);
				break;
			case CANCELADO:
				strncpy( status, "Cancelado", 15);
				break;
			case ATERRIZADO:
				strncpy( status, "Aterrizado", 15);
				break;
		}
	printf("|%*d|%*s|%*s|%*s|%*s|\n", column_id, flight.id, column_code, flight.flightCode, column_text, flight.destination,
			column_type, status, column_type, " ");
	}
}

/**
* \brief Prints Flights lists header
* \param void
* \return void
*
*/
void printFlightsListHeader(void) {
	int column_id = -8;
	int column_code = -12;
	int column_text = -30;
	int column_type = -20;

	printf("\n==========================================================================================================================\n");
	printf("\n                                                  LISTADO DE VUELOS\n");
	printf("\n==========================================================================================================================\n");

	printf("+--------+------------+------------------------------+--------------------+--------------------+\n");
	printf("|%*s|%*s|%*s|%*s|%*s|\n", column_id, " ID", column_code, " Vuelo", column_text, " Destino",
			column_type, " Status", column_type, " Fecha");
	printf("+--------+------------+------------------------------+--------------------+--------------------+\n");
}

/**
* \brief Prints the content of the flights array
* \param Flights Array pointer to array of Flights
* \param int array length
* \return Int - 0 : success - (-1) : error
*
*/
int printFlights(Flights pFlight[], int len) {
	int validation;
	validation = -1;
	if (pFlight != NULL && len > 0) {
		printFlightsListHeader();

		for (int i = 0; i < len; i++) {
			showFlight(pFlight[i]);
		}

		printf("+--------+------------+------------------------------+--------------------+--------------------+\n");
		printf("\n==========================================================================================================================\n");
		printf("\n\n");

		validation = 0;
	}
	return validation;
}

