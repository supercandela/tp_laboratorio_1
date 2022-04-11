/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Candela Bogado
 Divisi�n    : 1 "E"
 Copyright   : � Candela Bogado - 2022
 Description : Trabajo Pr�ctico 1 - Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "CustomFunctions.h"


/**
* \brief Funci�n principal
* \param Void - Ninguno
* \return Int hardcodeado en 0, para cerrar el programa.
*
*/
int main(void) {
	setbuf(stdout, NULL);

	printf("�Bienvenido al sistema de c�lculo de precios!\nPresione \"Enter\" para continuar...");
	getchar();

	int userOption;
	int exitValueGetOption;
	float kilometers;
	int exitValueGetKilometers;
	float aerolineasFee;
	float latamFee;

	kilometers = 0;
	aerolineasFee = 0;
	latamFee = 0;

	do {
		printMenu(kilometers, aerolineasFee, latamFee);

		exitValueGetOption = getOption(&userOption, 1, 6, 3);

		if (exitValueGetOption == 0) {
			switch(userOption) {
				case 1:
					exitValueGetKilometers = getKilometers(&kilometers, 1, 30000, 3);
					if (exitValueGetKilometers < 0) {
						printf("El valor ingresado para kil�metros no es v�lido y se qued� sin intentos.\n");
					}
					break;
				case 2:

					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
			}
		}
	} while (userOption != 6 && exitValueGetOption == 0);

	if (exitValueGetOption < 0) {
		printf("La opci�n ingresada no es v�lida y se qued� sin intentos.\nVuelva a intentarlo en unos minutos.");
	}
	if (userOption == 6) {
		printf("�Muchas gracias por su visita! Usted sali� del programa.\nPara ingresar m�s datos, vuelva a iniciar.");
	}
	return 0;
}
