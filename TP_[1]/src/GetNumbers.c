/*
 * GetNumbers.c
 *
 *  Author: Candela Bogado
 *  Created on: 10 abr. 2022
 */

#include <stdio.h>

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
	int aux;
	validation = -1;
	if (pNumber != NULL && minimumValue <= maximumValue) {
		scanf("%d", &aux);
		if (aux >= minimumValue && aux <= maximumValue) {
			*pNumber = aux;
			validation = 0;
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
	float aux;
	validation = -1;
	if (pNumber != NULL && minimumValue <= maximumValue) {
		scanf("%f", &aux);
		if (aux >= minimumValue && aux <= maximumValue) {
			*pNumber = aux;
			validation = 0;
		}
	}
	return validation;
}
