/*
 * Passengers.h
 *
 *  Author: Candela Bogado
 *  Created on: 12 Mayo 2022
 *
 *  Description: TP2 - Passengers Library
 */

#ifndef PASSENGERS_H_
#define PASSENGERS_H_
//passengerType
#define FIRST_CLASS 1
#define BUSINESS 2
#define PREMIUM 3
#define TURIST 4

#define LEN_TEXT_CHAR 51
#define LEN_FLIGHT_CODE 10

#include "Flights.h"
//STRUCTURES
typedef struct {
	int id;
	char name[51];
	char lastName[51];
	int passengerType;
	char flightCode[10];
	float price;
	int isEmpty;
} Passengers;

//FUNCTIONS
int initPassengers(Passengers pPassenger[], int len);
int addPassenger(Passengers pPassenger[], int len_passenger, char pName[], int len_name, char pLastName[], int len_last_name,
		int passengerType, char flightCode[], int len_flightCode,float price);
int getPassengersName(char pName[], int len_char, int tries);
int getPassengersLastName(char pLastName[], int len_char, int tries);
int getPassengersType(int *pPaxType, int tries);
int getPassengersFlightCode(char pFlightCode[], int len_char, int tries);
int getPassengersPrice(float *pPrice, float minimumValue, float maximumValue, int tries);
int getFirstEmptyPax(Passengers pPax[], int len);
void showPax(Passengers pax);
int printPassengers(Passengers pPax[], int len);
int forcedLoadPassengersListWithPrechargeValues(Passengers pPassenger[], int len_passenger);
int findPassengerById(Passengers pPassenger[], int len_passenger, int id);
int modifyPassenger(Passengers pPassenger[], int len_passenger, int id);
int getPaxId(int *pPaxId, int minimumValue, int maximumValue, int tries);
int removePassenger(Passengers pPassenger[], int len_passenger, int id);
int sortPassengers(Passengers pPassenger[], int len_passenger, int order);
int sortsPaxByLastNameAndPrints(Passengers pPassenger[], int len_passenger, int order);
int totalPrice(Passengers pPassenger[], int len_passenger);
int sortPassengersByFlightCode(Passengers pPassenger[], int len_passenger);
int sortsPaxByFlightCodeAndPrints(Passengers pPassenger[], int len_passenger, Flights pFlight[], int len_flight);

#endif /* PASSENGERS_H_ */
