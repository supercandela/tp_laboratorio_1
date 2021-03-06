/*
 * MenusReportsOthers.h
 *
 *  Author: Candela Bogado
 *  Created on: 12 Mayo 2022
 *
 *  Description: TP2 - Functions that prints information on the screen and manage the menus
 */

#ifndef MENUSREPORTSOTHERS_H_
#define MENUSREPORTSOTHERS_H_

int printWellcomeMessage();
int printPrincipalMenu();
int getOption(int *pNumber, int minimumValue, int maximumValue, int tries);
int printSubMenuAddPax(char name[], char lastName[], int passengerType, char flightCode[], float price);
int printSubMenuModifyPax(char name[], char lastName[], int passengerType, char flightCode[], float price);
int printSubMenuReports();

#endif /* MENUSREPORTSOTHERS_H_ */
