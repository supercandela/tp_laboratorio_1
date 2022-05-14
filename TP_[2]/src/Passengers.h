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

//STRUCTURES
typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flightCode[10];
	int typePassenger;
	int isEmpty;
} Passengers;

//FUNCTIONS
int initPassengers(Passengers pArray[], int len);
int addPassenger(Passengers pArray[], int len, int id, char name[], char lastName[], float price, int passengerType,
		char flycode[]);
int getNewId();





#endif /* PASSENGERS_H_ */
