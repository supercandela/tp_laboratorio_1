/*
 * GetData.h
 *
 *  Author: Candela Bogado
 *  Created on: 12 Mayo 2022
 *
 *  Description: TP3 - Ask data to the user and validate the data
 */

#ifndef GETDATA_H_
#define GETDATA_H_

//GETTERS
int askIntValue(int *pNumber, char * message, char * errorMessage, int minimumValue, int maximumValue, int tries);
int getInt(int *pNumber, int minimumValue, int maximumValue);
int askFloatValue(float *pNumber, char * message, char * errorMessage, float minimumValue, float maximumValue, int tries);
int getFloat(float *pNumber, float minimumValue, float maximumValue);
int askArrayOfLettersValue(char * pArray, int len, char * message, char * errorMessage, int tries);
int getArrayOfLetters(char pChar[], int len);
int askArrayOfLettersAndNumbersValue(char * pArray, int len, char * message, char * errorMessage, int tries);
int getArrayOfLettersAndNumbers(char pChar[], int len);
int doYouConfirm(void);

//VALIDATIONS
int isInt(char pValueToCheck[]);
int isFloat(char pValueToCheck[]);
int isArrayOfLetters(char pValueToCheck[]);
int isArrayOfLettersAndNumbers(char pValueToCheck[]);

#endif /* GETDATA_H_ */
