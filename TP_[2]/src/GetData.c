/*
 * GetData.c
 *
 *  Author: Candela Bogado
 *  Created on: 12 Mayo 2022
 *
 *  Description: TP2 - Ask data to the user and validate the data
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GetData.h"

/**
* \brief Asks the end user for an interger
* \param int pointer
* \param int minimum accepted value
* \param int maximum accepted value
* \return Int (0 : success - (-1) : error)
*
*/
int getInt(int *pNumber, int minimumValue, int maximumValue) {
	int validation;
	char auxChar[15];
	int auxNumber;
	validation = -1;
	if (pNumber != NULL && minimumValue <= maximumValue) {
		scanf("%s", auxChar);
		if(isInt(auxChar)) {
			auxNumber = atoi(auxChar);
			if (auxNumber >= minimumValue && auxNumber <= maximumValue) {
				*pNumber = auxNumber;
				validation = 0;
			}
		}
	}
	return validation;
}

/**
* \brief Validates a value as an interger
* \param char[] value to evaluate
* \return Int (0 : false - 1 : true)
*
*/
int isInt(char pValueToCheck[]) {
	int validation = 1;
	int i;
	int len = strlen(pValueToCheck);
	for (i = 0; i < len; i++) {
		if (pValueToCheck[i] < '0' || pValueToCheck[i] > '9' ) {
			validation = 0;
			break;
		}
	}
	return validation;
}

/**
* \brief Asks the end user for a float
* \param float pointer
* \param float minimum accepted value
* \param float maximum accepted value
* \return Int (0 : success - (-1) : error)
*
*/
int getFloat(float *pNumber, float minimumValue, float maximumValue) {
	int validation;
	char auxChar[15];
	float auxNumber;
	validation = -1;
	if (pNumber != NULL && minimumValue <= maximumValue) {
		scanf("%s", auxChar);
		if(isFloat(auxChar)) {
			auxNumber = atof(auxChar);
			if (auxNumber >= minimumValue && auxNumber <= maximumValue) {
				*pNumber = auxNumber;
				validation = 0;
			}
		}
	}
	return validation;
}

/**
* \brief Validates a value as a float
* \param char[] value to evaluate
* \return Int (0 : false - 1 : true)
*
*/
int isFloat(char pValueToCheck[]) {
	int validation = 1;
	int i;
	int len = strlen(pValueToCheck);
	int flagPoint;
	flagPoint = 0;
	for (i = 0; i < len; i++) {
		if(pValueToCheck[i] == '.') {
			flagPoint++;
		}
		if ((pValueToCheck[i] != '.' && pValueToCheck[i] < '0') || pValueToCheck[i] > '9' || flagPoint > 1) {
			validation = 0;
			break;
		}
	}
	return validation;
}

/**
* \brief Asks the end user for an array of chars that includes ONLY LETTERS and SPACES
* \param char[] pointer
* \param int lenght of the destination array
* \return Int (0 : success - (-1) : error)
*
*/
int getArrayOfLetters(char pChar[], int len) {
	int validation;
	char auxChar[51];
	validation = -1;
	if (pChar != NULL) {
		fgets(auxChar, 51, stdin);
		if(isArrayOfLetters(auxChar)) {
			strncpy(pChar, auxChar, len);
			pChar[strlen(pChar)-1] = '\0';
			validation = 0;
		}
	}
	return validation;
}

/**
* \brief Validates a value that includes ONLY LETTERS and SPACES
* \param char[] value to evaluate
* \return Int (0 : false - 1 : true)
*
*/
int isArrayOfLetters(char pValueToCheck[]) {
	int validation = 1;
	int i;
	int len = strlen(pValueToCheck) - 1;
	int flagSpace;
	flagSpace = 0;
	for (i = 0; i < len; i++) {
		if(pValueToCheck[i] == ' ') {
			flagSpace++;
		}
		if ((pValueToCheck[i] != ' ' && pValueToCheck[i] < 'A') || (pValueToCheck[i] > 'Z' && pValueToCheck[i] < 'a')
				|| pValueToCheck[i] > 'z' || flagSpace > 2) {
			validation = 0;
			break;
		}
	}
	return validation;
}

/**
* \brief Asks the end user for an array of chars that includes ONLY LETTERS and NUMBERS
* \param char[] pointer
* \param int lenght of the destination array
* \return Int (0 : success - (-1) : error)
*
*/
int getArrayOfLettersAndNumbers(char pChar[], int len) {
	int validation;
	char auxChar[51];
	validation = -1;
	if (pChar != NULL) {
		fgets(auxChar, 51, stdin);
		if(isArrayOfLettersAndNumbers(auxChar)) {
			strncpy(pChar, auxChar, len);
			pChar[strlen(pChar)-1] = '\0';
			validation = 0;
		}
	}
	return validation;
}

/**
* \brief Validates a value that includes ONLY LETTERS and NUMBERS
* \param char[] value to evaluate
* \return Int (0 : false - 1 : true)
*
*/
int isArrayOfLettersAndNumbers(char pValueToCheck[]) {
	int validation = 1;
	int i;
	int len = strlen(pValueToCheck) - 1;
	for (i = 0; i < len; i++) {
		if ( pValueToCheck[i] < '0' || (pValueToCheck[i] > '9' && pValueToCheck[i] < 'A') ||
				(pValueToCheck[i] > 'Z' && pValueToCheck[i] < 'a') || pValueToCheck[i] > 'z') {
			validation = 0;
			break;
		}
	}
	return validation;
}

/**
* \brief Asks the end user for confirmation in an action
* \param void
* \return Int (0 : false - 1 : true)
*
*/
int doYouConfirm(void) {
	int validation;
	validation = 0;
	char auxChar;
	printf("¿Confirmar acción? ( S - N )");
	fflush( stdin );
	scanf("%c", &auxChar);
	if ( auxChar == 's' || auxChar == 'S') {
		validation = 1;
	}
	return validation;
}

/**
* \brief Creates an autoincremental interger for the field "ID"
* \param void
* \return Int - the new id created
*
*/
int getNewId() {
    static int id = 1000;
    id++;
    return id;
}
