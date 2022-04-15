/*
 * DoCalculations.h
 *
 *  Author: Candela Bogado
 *  Created on: 15 abr. 2022
 */

#ifndef DOCALCULATIONS_H_
#define DOCALCULATIONS_H_

int calculateDiscount(float *pDiscountedValue, float originalValue, float discountRate);
int calculateInterest(float *pIncreasedValue, float originalValue, float interestRate);
int convertToCriptoCurrency(float *pConvertedValue, float originalValue, float commonCurrencyValue);
int calculateUnitPrice(float *pUnitPrice, float originalValue, float numberOfUnits);
int calculateDifference(float *pPriceDifference, float firstValue, float secondValue);

#endif /* DOCALCULATIONS_H_ */

