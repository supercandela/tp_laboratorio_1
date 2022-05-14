/*
 * GetData.h
 *
 *  Author: Candela Bogado
 *  Created on: 12 Mayo 2022
 *
 *  Description: TP2 - Ask data to the user and validate the data
 */

#ifndef GETDATA_H_
#define GETDATA_H_

//GETTERS
int getInt(int *pNumber, int minimumValue, int maximumValue);
int getFloat(float *pNumber, float minimumValue, float maximumValue);
int getArrayOfLetters(char pChar[], int len);
int getArrayOfLettersAndNumbers(char pChar[], int len);

//VALIDATIONS
int isInt(char pValueToCheck[]);
int isFloat(char pValueToCheck[]);
int isArrayOfLetters(char pValueToCheck[]);
int isArrayOfLettersAndNumbers(char pValueToCheck[]);

#endif /* GETDATA_H_ */
