/*
 * CustomFunctions.h
 *
 *  Author: Candela Bogado
 *  Created on: 10 abr. 2022
 *
 *  Description: TP1 - Custom Functions
 */

#ifndef CUSTOMFUNCTIONS_H_
#define CUSTOMFUNCTIONS_H_

int printMenu(float kilometers, float aerolineasFee, float latamFee);
int getOption(int *pNumber, int minimumValue, int maximumValue, int tries);
int getKilometers(float *pKilometers, float minimumValue, float maximumValue, int tries);
int printSubMenu(float aerolineasFee, float latamFee);
int getFee(float *pFee, float minimumValue, float maximumValue, int tries);
int calculateCosts(float kilometers, float fee, float *pDiscountedValue, float *pIncreasedValue, float *pConvertedValue, float *pUnitPrice);
int calculatePriceDifference(float *pPriceDifference, float firstValue, float secondValue);
int printResultsPerAirline(float discountedPrice, float increasedPrice, float convertedPrice, float unitPrice);
int printResultsDifference(float priceDifference);
int forcedLoadWithPrechargeValues(float kilometersValue, float aerolineasFeeValue, float latamFeeValue,
		float *kilometers, float *aerolineasFee, float *latamFee);

#endif /* CUSTOMFUNCTIONS_H_ */
