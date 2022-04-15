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
* \brief Main function
* \param void - none
* \return Int - 0 : success
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
	int userOptionSubMenu;
	int exitValueGetOptionSubMenu;
	int exitValueGetFee;

	float aerolineasWithDiscount;
	float aerolineasWithInterest;
	float aerolineasToBitcoin;
	float aerolineasUnitPrice;

	float latamWithDiscount;
	float latamWithInterest;
	float latamToBitcoin;
	float latamUnitPrice;

	float priceDifference;

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
						printf("El valor ingresado para kil�metros no es v�lido y se qued� sin intentos.\n"
								"Revise los valores y vuelva a intentarlo en unos minutos.\n");
					}
					break;
				case 2:
					do {
						printSubMenu(aerolineasFee, latamFee);
						exitValueGetOptionSubMenu = getOption(&userOptionSubMenu, 1, 3, 3);
						if (exitValueGetOptionSubMenu == 0) {
							switch(userOptionSubMenu) {
								case 1:
									exitValueGetFee = getFee(&aerolineasFee, 1, 5000000, 3);
									break;
								case 2:
									exitValueGetFee = getFee(&latamFee, 1, 5000000, 3);
									break;
							}
							if (exitValueGetFee < 0) {
								printf("El valor ingresado para el vuelo no es v�lido y se qued� sin intentos.\n"
										"Revise los valores y vuelva a intentarlo en unos minutos.\n");
							}
						}
						//SI SE QUEDA SIN INTENTOS
						if (exitValueGetOptionSubMenu < 0) {
							printf("La opci�n ingresada no es v�lida y se qued� sin intentos.\nVuelva a intentarlo en unos minutos.\n");
						}
						//SALE SI SE QUEDA SIN INTENTOS O SI PRESIONA 3
					} while (userOptionSubMenu != 3 && exitValueGetOptionSubMenu == 0);
					break;
				case 3:
					if (kilometers > 0 && aerolineasFee > 0 && latamFee > 0) {
						calculateCosts(kilometers, aerolineasFee, &aerolineasWithDiscount, &aerolineasWithInterest, &aerolineasToBitcoin, &aerolineasUnitPrice);
						calculateCosts(kilometers, latamFee, &latamWithDiscount, &latamWithInterest, &latamToBitcoin, &latamUnitPrice);
						calculatePriceDifference(&priceDifference, aerolineasFee, latamFee);
						printf("Valores calculados.\n");
					} else {
						if (kilometers <= 0) {
							printf("A�n no ingres� kil�metros.\nPor favor, ingrese kil�metros para hacer los c�lculos\n");
						}
						if (aerolineasFee <= 0) {
							printf("A�n no ingres� el precio del vuelo de Aerol�neas Argentinas.\n "
										"Por favor, ingrese el valor para hacer los c�lculos\n");
						}
						if (latamFee <= 0) {
							printf("A�n no ingres� el precio del vuelo de LATAM Airlines.\n "
										"Por favor, ingrese el valor para hacer los c�lculos\n");
						}
					}
					break;
				case 4:
					if (aerolineasWithDiscount > 0 && aerolineasWithInterest > 0 && aerolineasToBitcoin > 0
							&& aerolineasUnitPrice > 0 && latamWithDiscount > 0 && latamWithInterest > 0
							&& latamToBitcoin > 0 && latamUnitPrice > 0) {
						printf("Kil�metros ingresados: %.2f\n", kilometers);
						printf("Precio Aerol�neas Argentinas: %.2f\n", aerolineasFee);
						printResultsPerAirline(aerolineasWithDiscount, aerolineasWithInterest, aerolineasToBitcoin, aerolineasUnitPrice);
						printf("Precio LATAM Airlines: %.2f\n", latamFee);
						printResultsPerAirline(latamWithDiscount, latamWithInterest, latamToBitcoin, latamUnitPrice);
						printResultsDifference(priceDifference);
					} else {
						printf("Los costos de los vuelos a�n no fueron calculados.\n"
										"Por favor, realice los c�lculos para mostrar los resultados.\n");
					}
					break;
				case 5:
					forcedLoadWithPrechargeValues(7090, 162965, 159339, &kilometers, &aerolineasFee, &latamFee);
					calculateCosts(kilometers, aerolineasFee, &aerolineasWithDiscount, &aerolineasWithInterest, &aerolineasToBitcoin, &aerolineasUnitPrice);
					calculateCosts(kilometers, latamFee, &latamWithDiscount, &latamWithInterest, &latamToBitcoin, &latamUnitPrice);
					calculatePriceDifference(&priceDifference, aerolineasFee, latamFee);
					printf("Kil�metros ingresados: %.2f\n", kilometers);
					printf("Precio Aerol�neas Argentinas: $ %.2f\n", aerolineasFee);
					printResultsPerAirline(aerolineasWithDiscount, aerolineasWithInterest, aerolineasToBitcoin, aerolineasUnitPrice);
					printf("Precio LATAM Airlines: $ %.2f\n", latamFee);
					printResultsPerAirline(latamWithDiscount, latamWithInterest, latamToBitcoin, latamUnitPrice);
					printResultsDifference(priceDifference);
					break;
				case 6:
					printf("�Muchas gracias por su visita! Usted sali� del programa.\nPara ingresar m�s datos, vuelva a iniciar.");
					break;
			}
		}
		//SALE SI SE QUEDA SIN INTENTOS O SI PRESIONA 6
	} while (userOption != 6 && exitValueGetOption == 0);

	if (exitValueGetOption < 0) {
		printf("La opci�n ingresada no es v�lida y se qued� sin intentos.\nVuelva a intentarlo en unos minutos.");
	}
	return 0;
}
