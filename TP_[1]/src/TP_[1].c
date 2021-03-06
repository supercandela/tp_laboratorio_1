/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Candela Bogado
 Divisi?n    : 1 "E"
 Copyright   : ? Candela Bogado - 2022
 Description : Trabajo Pr?ctico 1 - Laboratorio 1
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

	printf("       _________________________________\n______|                                 |_______\n"
			"\\     |   ?Bienvenido al sistema de     |       /\n \\    |       c?lculo de precios!       |      /\n"
			" /    |_________________________________|      \\\n/________)                            (_________\\\n");
	printf("\nPresione \"Enter\" para continuar...\n");
	getchar();

	int userOption;
	float kilometers;
	float aerolineasFee;
	float latamFee;
	int userOptionSubMenu;

	int exitValueGetOption;
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
					if (getKilometers(&kilometers, 1, 30000, 3) < 0) {
						printf("\nEl valor ingresado para kil?metros no es v?lido y se qued? sin intentos.\n"
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
								printf("\nEl valor ingresado para el vuelo no es v?lido y se qued? sin intentos.\n"
										"Revise los valores y vuelva a intentarlo en unos minutos.\n");
							}
						}
						//SI SE QUEDA SIN INTENTOS
						if (exitValueGetOptionSubMenu < 0) {
							printf("\n================================================================================"
									"====================================\n"
									"\nLa opci?n ingresada no es v?lida y se qued? sin intentos.\nVuelva a intentarlo en unos minutos.\n");
						}
						//SALE SI SE QUEDA SIN INTENTOS O SI PRESIONA 3
					} while (userOptionSubMenu != 3 && exitValueGetOptionSubMenu == 0);
					break;
				case 3:
					if (kilometers > 0 && aerolineasFee > 0 && latamFee > 0) {
						if (calculateCosts(kilometers, aerolineasFee, &aerolineasWithDiscount, &aerolineasWithInterest,
								&aerolineasToBitcoin, &aerolineasUnitPrice) == 0 && calculateCosts(kilometers, latamFee,
								&latamWithDiscount, &latamWithInterest, &latamToBitcoin, &latamUnitPrice) == 0
								&& calculatePriceDifference(&priceDifference, aerolineasFee, latamFee) == 0) {
							printf("\n================================================================================="
									"===================================\n\nValores calculados.\n");
						}
					} else {
						if (kilometers <= 0) {
							printf("\n========================================================================================="
									"===========================\n");
							printf("\nA?n no ingres? kil?metros.\nPor favor, ingrese kil?metros para hacer los c?lculos\n");
						}
						if (aerolineasFee <= 0) {
							printf("\n========================================================================================="
									"===========================\n");
							printf("\nA?n no ingres? el precio del vuelo de Aerol?neas Argentinas.\n"
										"Por favor, ingrese el valor para hacer los c?lculos\n");
						}
						if (latamFee <= 0) {
							printf("\n=========================================================================================="
									"==========================\n");
							printf("\nA?n no ingres? el precio del vuelo de LATAM Airlines.\n"
										"Por favor, ingrese el valor para hacer los c?lculos\n");
						}
					}
					break;
				case 4:
					if (aerolineasWithDiscount > 0 && aerolineasWithInterest > 0 && aerolineasToBitcoin > 0
							&& aerolineasUnitPrice > 0 && latamWithDiscount > 0 && latamWithInterest > 0
							&& latamToBitcoin > 0 && latamUnitPrice > 0) {
						printf("\n=========================================================================================="
								"==========================\n");
						printf("\nKil?metros ingresados: %.2fKm.\n", kilometers);
						printf("\nPrecio Aerol?neas Argentinas: $%.2f\n", aerolineasFee);
						printResultsPerAirline(aerolineasWithDiscount, aerolineasWithInterest, aerolineasToBitcoin, aerolineasUnitPrice);
						printf("\nPrecio LATAM Airlines: $%.2f\n", latamFee);
						printResultsPerAirline(latamWithDiscount, latamWithInterest, latamToBitcoin, latamUnitPrice);
						printResultsDifference(priceDifference);
					} else {
						printf("\n==============================================================================================="
								"=====================\n"
								"\nLos costos de los vuelos a?n no fueron calculados.\n"
										"Por favor, realice los c?lculos para mostrar los resultados.\n");
					}
					break;
				case 5:
					if(forcedLoadWithPrechargeValues(7090, 162965, 159339, &kilometers, &aerolineasFee, &latamFee) == 0) {
						if (calculateCosts(kilometers, aerolineasFee, &aerolineasWithDiscount, &aerolineasWithInterest,
								&aerolineasToBitcoin, &aerolineasUnitPrice) == 0 &&
								calculateCosts(kilometers, latamFee, &latamWithDiscount, &latamWithInterest,
								&latamToBitcoin, &latamUnitPrice) == 0 &&
								calculatePriceDifference(&priceDifference, aerolineasFee, latamFee) == 0) {
							printf("\n=============================================================================================="
									"======================\n");
							printf("\nKil?metros ingresados: %.2f\n", kilometers);
							printf("\nPrecio Aerol?neas Argentinas: $ %.2f\n", aerolineasFee);
							printResultsPerAirline(aerolineasWithDiscount, aerolineasWithInterest, aerolineasToBitcoin, aerolineasUnitPrice);
							printf("\nPrecio LATAM Airlines: $ %.2f\n", latamFee);
							printResultsPerAirline(latamWithDiscount, latamWithInterest, latamToBitcoin, latamUnitPrice);
							printResultsDifference(priceDifference);
						}
					}
					break;
				case 6:
					printf("\n====================================================================================================================\n"
							"\n?Muchas gracias por su visita!\nUsted sali? del programa. Para ingresar m?s datos, vuelva a iniciar.\n"
							"\n====================================================================================================================\n");
					break;
			}
		}
	} while (userOption != 6 && exitValueGetOption == 0);

	if (exitValueGetOption < 0) {
		printf("\n====================================================================================================================\n");
		printf("\nLa opci?n ingresada no es v?lida y se qued? sin intentos.\nVuelva a intentarlo en unos minutos.");
	}
	return 0;
}
