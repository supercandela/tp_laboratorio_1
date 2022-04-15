/*
 * DoCalculations.c
 *
 *  Author: Candela Bogado
 *  Created on: 15 abr. 2022
 */

#include <stdio.h>

//a) Tarjeta de débito (descuento 10%%)

/**
* \brief Calculates discount from a value
* \param float pointer to discounted value
* \param float original value
* \param float discount rate (between 0% and 100%)
* \return Int (0 : success - (-1) : error)
*
*/
int calculateDiscount(float *pDiscountedValue, float originalValue, float discountRate) {
	int validation;
	float aux;
	validation = -1;
	if (pDiscountedValue != NULL && originalValue > 0 && discountRate >= 0 && discountRate <=100) {
		aux = originalValue - (originalValue * discountRate / 100);
		*pDiscountedValue = aux;
		validation = 0;
	}
	return validation;
}

//b) Tarjeta de crédito (interés 25%%)
/**
* \brief Calculates interest from a value
* \param float pointer to increased value
* \param float original value
* \param float interest rate (between 0% and 100%)
* \return Int (0 : success - (-1) : error)
*
*/
int calculateInterest(float *pIncreasedValue, float originalValue, float interestRate) {
	int validation;
	float aux;
	validation = -1;
	if (pIncreasedValue != NULL && originalValue > 0 && interestRate >= 0 && interestRate <=100) {
		aux = originalValue + (originalValue * interestRate / 100);
		*pIncreasedValue = aux;
		validation = 0;
	}
	return validation;
}

//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
/**
* \brief Converts value from common currency to cripto currency
* \param float pointer to converted value
* \param float original value
* \param float exchange value in common currency
* \return Int (0 : success - (-1) : error)
*
*/
int convertToCriptoCurrency(float *pConvertedValue, float originalValue, float commonCurrencyValue) {
	int validation;
	float aux;
	validation = -1;
	if (pConvertedValue != NULL && originalValue > 0 && commonCurrencyValue > 0) {
		aux = originalValue / commonCurrencyValue;
		*pConvertedValue = aux;
		validation = 0;
	}
	return validation;
}

//d) Mostrar precio por km (precio unitario)
/**
* \brief Calculates unit price
* \param float pointer to unit price
* \param float original value
* \param float number of units
* \return Int (0 : success - (-1) : error)
*
*/
int calculateUnitPrice(float *pUnitPrice, float originalValue, float numberOfUnits) {
	int validation;
	float aux;
	validation = -1;
	if (pUnitPrice != NULL && originalValue > 0 && numberOfUnits > 0) {
		aux = originalValue / numberOfUnits;
		*pUnitPrice = aux;
		validation = 0;
	}
	return validation;
}

//e) Mostrar diferencia de precio ingresada (LATAM Airlines - Aerolíneas Argentinas)
/**
* \brief Calculates difference
* \param float pointer to price difference
* \param float first value
* \param float second value
* \return Int (0 : success - (-1) : error)
*
*/
int calculateDifference(float *pDifference, float firstValue, float secondValue) {
	int validation;
	float aux;
	validation = -1;
	if (pDifference != NULL && firstValue > 0 && secondValue > 0) {
		if (firstValue > secondValue) {
			aux = firstValue - secondValue;
		} else {
			aux = secondValue - firstValue;
		}
		*pDifference = aux;
		validation = 0;
	}
	return validation;
}
