/*
 * MenusReportsOthers.h
 *
 *  Author: Candela Bogado
 *  Created on: 12 Mayo 2022
 *
 *  Description: TP3 - Functions that prints information on the screen and manage the menus
 */

#ifndef MENUSREPORTSOTHERS_H_
#define MENUSREPORTSOTHERS_H_

void printWellcomeMessage();
void printSeparationLine();
void printErrorNoPassengers();
void printPrincipalMenu();
void printSubMenuAddPax(char name[], char lastName[], int passengerType, char flightCode[], float price, int statusFlight);
void printSubMenuEditPax(char name[], char lastName[], int passengerType, char flightCode[], float price, int statusFlight);
void printSubMenuSortPax();

#endif /* MENUSREPORTSOTHERS_H_ */
