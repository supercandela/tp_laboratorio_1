/*
 * Flights.h
 *
 *  Author: Candela Bogado
 *  Created on: 14 Mayo 2022
 *
 *  Description: TP2 - Flights Library
 */

#ifndef FLIGHTS_H_
#define FLIGHTS_H_

//statusFlight
#define ACTIVO 1
#define DEMORADO 2
#define REPROGRAMADO 3
#define CANCELADO 4
#define ATERRIZADO 5

#define LEN_TEXT_CHAR 51
#define LEN_FLIGHT_CODE 10

//STRUCTURES
typedef struct {
	int id;
	char flightCode[10];
	char destination[51];
	int statusFlight;
	int year;
	int month;
	int day;
	int isEmpty;
} Flights;

//FUNCTIONS
int initFlights(Flights pFlight[], int len);
int addFlight(Flights pFlight[], int len_flight, char flightCode[], int len_flightCode, char pDestination[], int len_destination,
				int statusFlight, int year, int month, int day);
int getFirstEmptyFlight(Flights pFlight[], int len);
int forcedLoadFlightsListWithPrechargeValues(Flights pFlight[], int len);
void showFlight(Flights flight);
void printFlightsListHeader(void);
int printFlights(Flights pFlight[], int len);

#endif /* FLIGHTS_H_ */
