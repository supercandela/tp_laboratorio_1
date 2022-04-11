/*
 * CustomFunctions.c
 *
 *  Author: Candela Bogado
 *  Created on: 10 abr. 2022
 *
 *  Description: TP1 - Custom Functions
 */

#include <stdio.h>
//#include "GetNumbers.h"

/**
* \brief Prints the menu on the screen
* \param float amount of kilometers
* \param float amount of kilometers
* \param float amount of kilometers
* \return Int - 0 : success
*
*/
int printMenu(float kilometers, float aerolineasFee, float latamFee) {
	if (kilometers > 0) {
		printf("1. Ingresar Kil�metros: %.2fkm.\n", kilometers);
	} else {
		printf("1. Ingresar Kil�metros: A�n no se ha ingresado ning�n valor.\n");
	}
	printf("2. Ingresar Precio de Vuelos: \n");
	if(aerolineasFee > 0) {
		printf("- Precio vuelo Aerol�neas: $%.2f.\n", aerolineasFee);
	} else {
		printf("- Precio vuelo Aerol�neas: A�n no se ha ingresado ning�n valor.\n");
	}
	if(latamFee > 0) {
		printf("- Precio vuelo Latam: $%.2f.\n", latamFee);
	} else {
		printf("- Precio vuelo Latam: A�n no se ha ingresado ning�n valor.\n");
	}
//	printf("3. Calcular todos los costos:\na) Tarjeta de d�bito (descuento 10%%)\nb) Tarjeta de cr�dito (inter�s 25%%)\nc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nd) Mostrar precio por km (precio unitario)\ne) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)\n");
//	printf("4. Informar Resultados\n\"Latam:\na) Precio con tarjeta de d�bito: r\nb) Precio con tarjeta de cr�dito: r\nc) Precio pagando con bitcoin : r\nd) Precio unitario: r\nAerol�neas:\na) Precio con tarjeta de d�bito: r\nb) Precio con tarjeta de cr�dito: r\nc) Precio pagando con bitcoin : r\nd) Precio unitario: r\nLa diferencia de precio es : r \"\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n");

	return 0;
}

/**
* \brief Asks the end user for the option of the menu
* \param pointer int
* \param int minimum accepted value
* \param int maximum accepted value
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getOption(int *pNumber, int minimumValue, int maximumValue, int tries) {
	int aux;
	fflush( stdin );
	printf("Ingrese una opci�n: ");
	scanf("%d", &aux);
	tries--;
	while ((aux < minimumValue || aux > maximumValue) && tries > 0) {
		printf("La opci�n ingresada no es correcta.\nPor favor, ingrese una opci�n entre %d y %d. Usted tiene %d intentos.", minimumValue, maximumValue, tries);
		scanf("%d", &aux);
		tries--;
	}
	if (aux >= minimumValue && aux <= maximumValue) {
		*pNumber = aux;
		return 0;
	}
	return -1;
}

/**
* \brief Asks the end user for the amount of kilometers
* \param pointer float
* \param int minimum accepted value
* \param int maximum accepted value
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getKilometers(float *pKilometers, int minimumValue, int maximumValue, int tries) {
	float aux;
	fflush( stdin );
	printf("Ingrese la cantidad de kil�metros: ");
	scanf("%f", &aux);
	tries--;
	while ((aux < minimumValue || aux > maximumValue) && tries > 0) {
		printf("El valor de kil�metros ingresado no es correcto.\nPor favor, ingrese un nuevo valor entre %d y %d kil�metros. Usted tiene %d intentos.", minimumValue, maximumValue, tries);
		scanf("%f", &aux);
		tries--;
	}
	if (aux >= minimumValue && aux <= maximumValue) {
		*pKilometers = aux;
		return 0;
	}
	return -1;
}
