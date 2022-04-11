/*
 * GetNumbers.c
 *
 *  Author: Candela Bogado
 *  Created on: 10 abr. 2022
 */

#include <stdio.h>

/**
* \brief Asks the end user for an interger
* \param pointer int
* \param int minimum accepted value
* \param int maximum accepted value
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getInt(int *pNumber, int minimumValue, int maximumValue, int tries) {
	int aux;
	fflush( stdin );
	printf("Ingrese un n�mero: ");
	scanf("%d", &aux);
	tries--;
	while ((aux < minimumValue || aux > maximumValue) && tries > 0) {
		printf("El n�mero ingresado no es correcto.\nPor favor, ingrese un n�mero entre %d y %d. Usted tiene %d intentos.", minimumValue, maximumValue, tries);
		scanf("%d", &aux);
		tries--;
	}
	if (aux >= minimumValue && aux <= maximumValue) {
		printf("aux: %d", aux);
		*pNumber = aux;
		return 0;
	}
	return -1;
}
