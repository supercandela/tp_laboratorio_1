/*
 * GetPassengerData.c
 *
 *  Author: Candela Bogado
 *  Created on: 6 jun. 2022
 *
 *  Description: TP3 - Ask passenger's data to the user and validate the data
 */

#include <stdio.h>
#include <string.h>
#include "GetData.h"

/**
* \brief Asks the end user for the name of the passenger
* \param char[] pointer to name
* \param int length of the char
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getPassengersName(char pName[], int len_char, int tries) {
	int validation;
	validation = -1;
	if (pName != NULL && tries >= 0 && len_char > 0){
		validation =  askArrayOfLettersValue(pName, len_char,
			"\n====================================================================================================================\n"
			"\nIngrese el nombre del pasajero: ",
			"\nEl nombre ingresado no es correcto.\nPor favor, ingrese sólo letras o espacios. Ejemplo: 'Maria Dolores'.\n", tries);
	}
	return validation;
}

/**
* \brief Asks the end user for the lastname of the passenger
* \param char[] pointer to lastname
* \param int length of the char
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getPassengersLastName(char pLastName[], int len_char, int tries) {
	int validation;
	validation = -1;
	if (pLastName != NULL && tries > 0 && len_char > 0){
		validation =  askArrayOfLettersValue(pLastName, len_char,
					"\n====================================================================================================================\n"
					"\nIngrese el apellido del pasajero: ",
					"\nEl apellido ingresado no es correcto.\nPor favor, ingrese sólo letras o espacios. Ejemplo: 'Maria Dolores'.\n", tries);
	}
	return validation;
}

/**
* \brief Asks the end user for the pssenger's type
* \param int pointer to selected option
* \param int minimum accepted value
* \param int maximum accepted value
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getPassengersType(int *pPaxType, int tries) {
	int validation;
	validation = -1;
	if (pPaxType != NULL && tries > 0){
		validation = askIntValue(pPaxType,
				"\n====================================================================================================================\n"
				"\nIngrese tipo de pasajero:\n"
				"\n1. First Class | 2. Executive Class | 3. Economy Class\n",
				"\nLa opción ingresada no es correcta.\nPor favor, ingrese una opción entre 1 y 3, de acuerdo a los valores.\n",
				1, 3, tries);
	}
	return validation;
}

/**
* \brief Asks the end user for the flight code of the passenger
* \param char[] pointer to flight code
* \param int length of the char
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getPassengersFlightCode(char pFlightCode[], int len_char, int tries) {
	int validation;
	validation = -1;
	if (pFlightCode != NULL && tries > 0 && len_char > 0){
		validation =  askArrayOfLettersAndNumbersValue(pFlightCode, len_char,
				"\n====================================================================================================================\n"
				"\nIngrese el código del vuelo: ",
				"\nEl código ingresado no es correcto.\nPor favor, ingrese sólo letras o numeros. Ejemplo: 'MDQ082903'.\n", tries);
	}
	return validation;
}

/**
* \brief Asks the end user for the price of the flight the passenger will be taken
* \param float pointer to price
* \param float minimum accepted value
* \param float maximum accepted value
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getPassengersPrice(float *pPrice, float minimumValue, float maximumValue, int tries) {
	int validation;
	validation = -1;
	if (pPrice != NULL && tries >= 0 && minimumValue < maximumValue){
		validation = askFloatValue(pPrice,
				"\n====================================================================================================================\n"
				"\nIngrese el precio del vuelo: \n",
				"\nEl precio ingresado no es correcto.\nPor favor, ingrese un nuevo valor.\n",
				minimumValue, maximumValue, tries);
	}
	return validation;
}
