/*
 * Passengers.c
 *
 *  Author: Candela Bogado
 *  Created on: 12 Mayo 2022
 *
 *  Description: TP2 - Passengers Library
 */

#include <stdio.h>
#include "Passengers.h"
#include "GetData.h"

/**
* \brief To indicate that all positions in the array are empty, this function puts the flag (isEmpty) in TRUE in all
* 			positions of the array list Passengers* Pointer to array of passenger
* \param Passengers Array pointer to array of Passengers
* \param int array length
* \return Int - 0 : success - (-1) : error [Invalid length or NULL pointer]
*
*/
int initPassengers(Passengers pArray[], int len) {
	int validation = -1;
	if (pArray != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			pArray[i].isEmpty = 1;
			validation = 0;
		}
	}
	return validation;
}

/**
* \brief Adds in an existing list of passengers the values received as parameters in the first empty position
* \param Passengers Array pointer to array of Passengers
* \param int array length
* \param int passenger큦 Id
* \param char array	passenger큦 name
* \param char array	passenger큦 lastname
* \param float flight큦 price
* \param int passenger큦 type
* \param char array flycode
* \return Int - 0 : success - (-1) : error [Invalid length or NULL pointer or without free space]
*/
int addPassenger(Passengers pArray[], int len, int id, char name[], char lastName[], float price, int passengerType,
		char flycode[]) {
	int validation = -1;

//	int indexLibre;
//	if (pArray != NULL && len > 0) {
//		indexLibre = buscarIndexPorIsEmpty(pArray, len);
//		if (indexLibre != -1) {
//			printf("Ingrese nombre: \n");
//			__fpurge(stdin); // cambiar a fflush al pasar a eclipse
//			scanf("%s", pArray[indexLibre].nombre);
//			printf("Ingrese apellido: \n");
//			__fpurge(stdin);
//			scanf("%s", pArray[indexLibre].apellido);
//			printf("Ingrese dni: \n");
//			scanf("%d", &pArray[indexLibre].dni);
//			printf("Ingrese edad: \n");
//			scanf("%d", &pArray[indexLibre].edad);
//			pArray[indexLibre].idAsociado = incrementarId();
//			pArray[indexLibre].isEmpty = 0;
//
//			mostrarAsociado(pArray[indexLibre]);
//			retorno = 0;
//		}
//
//	}

	return validation;
}

/**
* \brief Creates an autoincremental interger for the field "ID"
* \param void
* \return Int - the new id created
*
*/
int getNewId()
{
    static int id = 1000;
    id++;
    return id;
}





