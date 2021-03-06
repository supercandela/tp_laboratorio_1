/*
 * CustomFunctions.c
 *
 *  Author: Candela Bogado
 *  Created on: 10 abr. 2022
 *
 *  Description: TP1 - Custom Functions
 */

#include <stdio.h>
#include "GetNumbers.h"
#include "DoCalculations.h"

/**
* \brief Prints the menu on the screen
* \param float amount of kilometers
* \param float Aerol?neas Argentinas Fee
* \param float LATAM Airlines Fee
* \return Int - 0 : success
*
*/
int printMenu(float kilometers, float aerolineasFee, float latamFee) {
	printf("\n====================================================================================================================\n");
	if (kilometers > 0) {
		printf("\n1. Ingresar Kil?metros: %.2fkm.\n", kilometers);
	} else {
		printf("\n1. Ingresar Kil?metros: A?n no se ha ingresado ning?n valor.\n");
	}
	printf("2. Ingresar Precio de Vuelos: \n");
	if(aerolineasFee > 0) {
		printf("   - Precio vuelo Aerol?neas Argentinas: $%.2f.\n", aerolineasFee);
	} else {
		printf("   - Precio vuelo Aerol?neas Argentinas: A?n no se ha ingresado ning?n valor.\n");
	}
	if(latamFee > 0) {
		printf("   - Precio vuelo LATAM Airlines: $%.2f.\n", latamFee);
	} else {
		printf("   - Precio vuelo LATAM Airlines: A?n no se ha ingresado ning?n valor.\n");
	}
	printf("3. Calcular todos los costos para cada aerol?nea:\n   a) Tarjeta de d?bito (descuento 10%%)\n"
			"   b) Tarjeta de cr?dito (inter?s 25%%)\n   c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
			"   d) Mostrar precio por km (precio unitario)\n   e) Mostrar diferencia de precio ingresada (LATAM Airlines - Aerol?neas Argentinas)\n");
	printf("4. Informar resultados de los costos calculados\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n");

	return 0;
}

/**
* \brief Asks the end user for the option of the menu
* \param int pointer to selected option
* \param int minimum accepted value
* \param int maximum accepted value
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getOption(int *pNumber, int minimumValue, int maximumValue, int tries) {
	int validation;
	fflush( stdin );
	validation = -1;
	if (pNumber != NULL && tries > 0){
		do {
			printf("\n====================================================================================================================\n");
			printf("\nIngrese una opci?n: ");
			validation = getInt(pNumber, minimumValue, maximumValue);
			tries--;
			if (validation != 0 && tries > 0) {
				printf("\nLa opci?n ingresada no es correcta.\nPor favor, ingrese una opci?n entre %d y %d. "
						"Usted tiene %d intentos.\n", minimumValue, maximumValue, tries);
			}
		} while (validation != 0 && tries > 0);
	}
	return validation;
}

/**
* \brief Asks the end user for the amount of kilometers
* \param float pointer to kilometers
* \param float minimum accepted value
* \param float maximum accepted value
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getKilometers(float *pKilometers, float minimumValue, float maximumValue, int tries) {
	int validation;
	fflush( stdin );
	validation = -1;
	if (pKilometers != NULL && tries > 0){
		do {
			printf("\n====================================================================================================================\n");
			printf("\nIngrese la cantidad de kil?metros: ");
			validation = getFloat(pKilometers, minimumValue, maximumValue);
			tries--;
			if (validation != 0 && tries > 0) {
				printf("\nEl valor de kil?metros ingresado no es correcto.\nPor favor, ingrese un nuevo valor entre %.2f y %.2f kil?metros. "
						"Usted tiene %d intentos.\n", minimumValue, maximumValue, tries);
			}
		} while (validation != 0 && tries > 0);
	}
	return validation;
}

/**
* \brief Prints the submenu for airlines on the screen
* \param float Aerol?neas Argentinas Fee
* \param float LATAM Airlines Fee
* \return Int - 0 : success
*
*/
int printSubMenu(float aerolineasFee, float latamFee) {
	printf("\n====================================================================================================================\n");
	if(aerolineasFee > 0) {
		printf("\n- Precio vuelo Aerol?neas Argentinas: $%.2f.\n", aerolineasFee);
	} else {
		printf("\n- Precio vuelo Aerol?neas Argentinas: A?n no se ha ingresado ning?n valor.\n");
	}
	if(latamFee > 0) {
		printf("- Precio vuelo LATAM Airlines: $%.2f.\n", latamFee);
	} else {
		printf("- Precio vuelo LATAM Airlines: A?n no se ha ingresado ning?n valor.\n");
	}
	printf("\n1. Ingrese precio para vuelo Aerol?neas Argentinas.\n");
	printf("2. Ingrese precio para vuelo LATAM Airlines.\n");
	printf("3. Volver al men? anterior.\n");
	return 0;
}

/**
* \brief Asks the end user for the fee of the travel
* \param float pointer to fee
* \param float minimum accepted value
* \param float maximum accepted value
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getFee(float *pFee, float minimumValue, float maximumValue, int tries) {
	int validation;
	fflush( stdin );
	validation = -1;
	if (pFee != NULL && tries > 0){
		do {
			printf("\n====================================================================================================================\n");
			printf("\nIngrese el precio del vuelo $");
			validation = getFloat(pFee, minimumValue, maximumValue);
			tries--;
			if (validation != 0 && tries > 0) {
				printf("\nEl valor ingresado no es correcto.\nPor favor, ingrese un nuevo valor entre $%.2f y $%.2f. "
						"Usted tiene %d intentos.\n", minimumValue, maximumValue, tries);
			}
		} while (validation != 0 && tries > 0);
	}
	return validation;
}

/**
* \brief Calculate all costs
* \param float amount of kilometers
* \param float fee
* \param float pointer to discounted value
* \param float pointer to increased value
* \param float pointer to converted value
* \param float pointer to unit price
* \return Int - 0 : success - (-1) : error
*
*/
int calculateCosts(float kilometers, float fee, float *pDiscountedValue, float *pIncreasedValue, float *pConvertedValue, float *pUnitPrice) {
	int validation;
	float discountRate;
	float interestRate;
	float commonCurrencyValue;
	validation = -1;
	discountRate = 10;
	interestRate = 25;
	commonCurrencyValue = 4606954.55;

	if (pDiscountedValue != NULL && pIncreasedValue != NULL && pConvertedValue != NULL
			&& pUnitPrice != NULL && kilometers > 0 && fee > 0) {
		calculateDiscount(pDiscountedValue, fee, discountRate);
		calculateInterest(pIncreasedValue, fee, interestRate);
		convertToCriptoCurrency(pConvertedValue, fee, commonCurrencyValue);
		calculateUnitPrice(pUnitPrice, fee, kilometers);
		validation = 0;
	}
	return validation;
}

/**
* \brief Calculate price difference
* \param float pointer to price difference
* \param float pointer to first fee
* \param float pointer to second fee
* \return Int - 0 : success - (-1) : error
*
*/
int calculatePriceDifference(float *pPriceDifference, float firstValue, float secondValue) {
	int validation;
	validation = -1;

	if (pPriceDifference != NULL && firstValue > 0 && secondValue > 0){
		validation = calculateDifference(pPriceDifference, firstValue, secondValue);
	}
	return validation;
}

/**
* \brief Prints the results on the screen
* \param float discounted price
* \param float increase price
* \param float converted price
* \param float unit price
* \return Int - 0 : success
*
*/
int printResultsPerAirline(float discountedPrice, float increasedPrice, float convertedPrice, float unitPrice) {
	printf("   a) Precio con tarjeta de d?bito: $ %.2f\n   b) Precio con tarjeta de cr?dito: $ %.2f\n"
			"   c) Precio pagando con bitcoin: %.2f BTC\n   d) Precio unitario por kil?metro: $ %.2f\n",
			discountedPrice, increasedPrice, convertedPrice, unitPrice);
	return 0;
}

/**
* \brief Prints the results on the screen
* \param float pointer to result
* \return Int - 0 : success
*
*/
int printResultsDifference(float priceDifference) {

	printf("\nLa diferencia de precio es: $ %.2f\n", priceDifference);
	return 0;
}

/**
* \brief Sets predetermined values for kilometers, Aerol?neas Argentinas fee and LATAM Airlines fee
* \param float predetermined kilometers
* \param float predetermined Aerol?neas Argentinas fee
* \param float predetermined Latam Fee
* \param float pointer to kilometers
* \param float pointer to Aerol?neas Argentinas fee
* \param float pointer to LATAM Airlines fee
* \return Int - 0 : success - (-1) : error
*
*/
int forcedLoadWithPrechargeValues(float kilometersValue, float aerolineasFeeValue, float latamFeeValue,
		float *kilometers, float *aerolineasFee, float *latamFee) {
	int validation;
	validation = -1;
	if(kilometers != NULL && aerolineasFee != NULL && latamFee != NULL
			&& kilometersValue > 0 && aerolineasFeeValue > 0 && latamFeeValue > 0) {
		*kilometers = kilometersValue;
		*aerolineasFee = aerolineasFeeValue;
		*latamFee = latamFeeValue;
		validation = 0;
	}
	return validation;
}





