/*
 * GetPassengerData.h
 *
 *  Author: Candela Bogado
 *  Created on: 6 jun. 2022
 *
 *  Description: TP3 - Ask passenger's data to the user and validate the data
 */

#ifndef GETPASSENGERDATA_H_
#define GETPASSENGERDATA_H_

int getPassengersName(char pName[], int len_char, int tries);
int getPassengersLastName(char pLastName[], int len_char, int tries);
int getPassengersType(int *pPaxType, int tries);
int getPassengersFlightCode(char pFlightCode[], int len_char, int tries);
int getPassengersPrice(float *pPrice, float minimumValue, float maximumValue, int tries);

#endif /* GETPASSENGERDATA_H_ */
