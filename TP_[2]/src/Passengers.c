/*
 * Passengers.c
 *
 *  Author: Candela Bogado
 *  Created on: 12 Mayo 2022
 *
 *  Description: TP2 - Passengers Library
 */

#include <stdio.h>
#include <string.h>
#include "Passengers.h"
#include "GetData.h"
#include "MenusReportsOthers.h"


/**
* \brief To indicate that all positions in the array are empty, this function puts the flag (isEmpty) in TRUE in all
* 			positions of the array list Passengers* Pointer to array of passenger
* \param Passengers Array pointer to array of Passengers
* \param int array length
* \return Int - 0 : success - (-1) : error [Invalid length or NULL pointer]
*
*/
int initPassengers(Passengers pPassenger[], int len) {
	int validation = -1;
	if (pPassenger != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			pPassenger[i].isEmpty = 1;
			validation = 0;
		}
	}
	return validation;
}

/**
* \brief Adds in an existing list of passengers the values received as parameters in the first empty position
* \param Passengers Array pointer to array of Passengers
* \param int array length
* \param char array	passenger´s name
* \param int name array length
* \param char array	passenger´s lastname
* \param int lastname array length
* \param int passenger´s type
* \param char array flycode
* \param int flycode array length
* \param float flight´s price
* \return Int - 0 : success - (-1) : error [Invalid length or NULL pointer or without free space]
*/
int addPassenger(Passengers pPassenger[], int len_passenger, char pName[], int len_name, char pLastName[], int len_last_name,
		int passengerType, char flightCode[], int len_flightCode,float price) {
	int validation = -1;
	int freeIndex;
	if (pPassenger != NULL && len_passenger > 0) {
		freeIndex = getFirstEmptyPax(pPassenger, len_passenger);
		if (freeIndex != -1) {
			pPassenger[freeIndex].id = getNewId();
			strncpy(pPassenger[freeIndex].name, pName, len_name);
			strncpy(pPassenger[freeIndex].lastName, pLastName, len_last_name);
			pPassenger[freeIndex].passengerType = passengerType;
			strncpy(pPassenger[freeIndex].flightCode, flightCode, len_flightCode);
			pPassenger[freeIndex].price = price;
			pPassenger[freeIndex].isEmpty = 0;
			validation = 0;
		}
	}


	return validation;
}

/**
* \brief Creates an autoincremental interger for the field "ID"
* \param void
* \return Int - the new id created
*
*/
int getNewId() {
    static int id = 1000;
    id++;
    return id;
}

/**
* \brief Asks the end user for the name of the passenger
* \param char[] pointer to name
* \param int length of the char
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getPassengersName(char pName[], int len_char, int tries) {
	int validation;
	fflush( stdin );
	validation = -1;
	if (pName != NULL && tries > 0){
		do {
			printf("\n====================================================================================================================\n");
			printf("\nIngrese el nombre del pasajero: ");
			validation = getArrayOfLetters(pName, len_char);
			tries--;
			if (validation != 0 && tries > 0) {
				printf("\nEl nombre ingresado no es correcto.\nPor favor, ingrese sólo letras o espacios. Ejemplo: 'Maria Dolores'.\n"
						"Usted tiene %d intentos.\n", tries);
			}
		} while (validation != 0 && tries > 0);
	}
	return validation;
}

/**
* \brief Asks the end user for the lastname of the passenger
* \param char[] pointer to lastname
* \param int length of the char
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getPassengersLastName(char pLastName[], int len_char, int tries) {
	int validation;
	fflush( stdin );
	validation = -1;
	if (pLastName != NULL && tries > 0){
		do {
			printf("\n====================================================================================================================\n");
			printf("\nIngrese el apellido del pasajero: ");
			validation = getArrayOfLetters(pLastName, len_char);
			tries--;
			if (validation != 0 && tries > 0) {
				printf("\nEl apellido ingresado no es correcto.\nPor favor, ingrese sólo letras o espacios. Ejemplo: 'Ramos Mejia'.\n"
						"Usted tiene %d intentos.\n", tries);
			}
		} while (validation != 0 && tries > 0);
	}
	return validation;
}

/**
* \brief Asks the end user for the ássenger's type
* \param int pointer to selected option
* \param int minimum accepted value
* \param int maximum accepted value
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getPassengersType(int *pPaxType, int tries) {
	int validation;
	fflush( stdin );
	validation = -1;
	if (pPaxType != NULL && tries > 0){
		do {
			printf("\n====================================================================================================================\n");
			printf("\nIngrese tipo de pasajero:\n");
			printf("\n1. First Class | 2. Business | 3. Premium | 4.Turist\n");
			validation = getInt(pPaxType, 1, 4);
			tries--;
			if (validation != 0 && tries > 0) {
				printf("\nLa opción ingresada no es correcta.\nPor favor, ingrese una opción entre 1 y 4, de acuerdo a los valores. "
						"Usted tiene %d intentos.\n", tries);
			}
		} while (validation != 0 && tries > 0);
	}
	return validation;
}

/**
* \brief Asks the end user for the flight code of the passenger
* \param char[] pointer to flight code
* \param int length of the char
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getPassengersFlightCode(char pFlightCode[], int len_char, int tries) {
	int validation;
	fflush( stdin );
	validation = -1;
	if (pFlightCode != NULL && tries > 0){
		do {
			printf("\n====================================================================================================================\n");
			printf("\nIngrese el código del vuelo: ");
			validation = getArrayOfLettersAndNumbers(pFlightCode, len_char);
			tries--;
			if (validation != 0 && tries > 0) {
				printf("\nEl código ingresado no es correcto.\nPor favor, ingrese sólo letras o numeros. Ejemplo: 'MDQ082903'.\n"
						"Usted tiene %d intentos.\n", tries);
			}
		} while (validation != 0 && tries > 0);
	}
	return validation;
}

/**
* \brief Asks the end user for the price of the flight the passenger will be taken
* \param float pointer to price
* \param float minimum accepted value
* \param float maximum accepted value
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getPassengersPrice(float *pPrice, float minimumValue, float maximumValue, int tries) {
	int validation;
	fflush( stdin );
	validation = -1;
	if (pPrice != NULL && tries > 0){
		do {
			printf("\n====================================================================================================================\n");
			printf("\nIngrese el precio del vuelo: ");
			validation = getFloat(pPrice, minimumValue, maximumValue);
			tries--;
			if (validation != 0 && tries > 0) {
				printf("\nEl precio ingresado no es correcto.\nPor favor, ingrese un nuevo valor entre $%.2f y $%.2f. "
						"Usted tiene %d intentos.\n", minimumValue, maximumValue, tries);
			}
		} while (validation != 0 && tries > 0);
	}
	return validation;
}

/**
* \brief Finds if exists the first empty position on the Passengers array
* \param Passengers Array pointer to array of Passengers
* \param int array length
* \return Int - firstEmptyIndex : success - (-1) : error
*
*/
int getFirstEmptyPax(Passengers pPax[], int len) {
	int validation = -1;
	if (pPax != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (pPax[i].isEmpty == 1) {
				validation = i;
				break;
			}
		}
	}
	return validation;
}

/**
* \brief Prints one passenger on a formated list
* \param Passengers passenger
* \return void
*
*/
void showPax(Passengers pax) {
	if (pax.isEmpty == 0){
		int column_id = 8;
		int column_text = -30;
		int column_type = -20;
		int column_code = -12;
		int column_price = 15 - 1; //resto 1 por el signo
		char paxType[15];
		switch(pax.passengerType) {
			case FIRST_CLASS:
				strncpy( paxType, "First Class", 15);
				break;
			case BUSINESS:
				strncpy( paxType, "Business", 15);
				break;
			case PREMIUM:
				strncpy( paxType, "Premium", 15);
				break;
			case TURIST:
				strncpy( paxType, "Turist", 15);
				break;
		}
		printf("|%*d|%*s|%*s|%*s|%*s|$%*.2f|\n", column_id, pax.id, column_text, pax.lastName, column_text, pax.name,
				column_type, paxType, column_code, pax.flightCode, column_price, pax.price);
	}
}

/**
* \brief Prints passengers lists header
* \param void
* \return void
*
*/
void printPaxListHeader(void) {
	int column_id = -8;
	int column_text = -30;
	int column_type = -20;
	int column_code = -12;
	int column_price = -15;

	printf("\n==========================================================================================================================\n");
	printf("\n                                                  LISTADO DE PASAJEROS\n");
	printf("\n==========================================================================================================================\n");

	printf("+--------+------------------------------+------------------------------+--------------------+------------+---------------+\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n", column_id, " ID", column_text, " Apellido", column_text, " Nombre",
			column_type, " Tipo", column_code, " Vuelo", column_price, " Precio");
	printf("+--------+------------------------------+------------------------------+--------------------+------------+---------------+\n");
}

/**
* \brief Prints the content of the passengers array
* \param Passengers Array pointer to array of Passengers
* \param int array length
* \return Int - 0 : success - (-1) : error
*
*/
int printPassengersList(Passengers pPax[], int len) {
	int validation;
	validation = -1;
	if (pPax != NULL && len > 0) {
		printPaxListHeader();

		for (int i = 0; i < len; i++) {
			showPax(pPax[i]);
		}

		printf("+--------+------------------------------+------------------------------+--------------------+------------+---------------+\n");
		printf("\n==========================================================================================================================\n");
		printf("\n\n");

		validation = 0;
	}
	return validation;
}

/**
* \brief Hardcodes 10 passengers on the array of passengers
* \param Passengers Array pointer to array of Passengers
* \param int array length
* \return Int - 0 : success - (-1) : error [Invalid length or NULL pointer or without free space]
*/
int forcedLoadPassengersListWithPrechargeValues(Passengers pPassenger[], int len_passenger) {
	int validation = -1;
	if (pPassenger != NULL && len_passenger > 0) {
		addPassenger(pPassenger, len_passenger, "Maria Dolores", LEN_TEXT_CHAR, "Touceda", LEN_TEXT_CHAR, 1, "ECR082903", LEN_FLIGHT_CODE, 354586.98);
		addPassenger(pPassenger, len_passenger, "Roberto", LEN_TEXT_CHAR, "Pino", LEN_TEXT_CHAR, 1, "ECR082903", LEN_FLIGHT_CODE, 354586.98);
		addPassenger(pPassenger, len_passenger, "Natasha", LEN_TEXT_CHAR, "Romanov", LEN_TEXT_CHAR, 3, "MDR091503", LEN_FLIGHT_CODE, 245326.54);
		addPassenger(pPassenger, len_passenger, "Barbara", LEN_TEXT_CHAR, "Doctorovich", LEN_TEXT_CHAR, 2, "BCN052816", LEN_FLIGHT_CODE, 215954.14);
		addPassenger(pPassenger, len_passenger, "Micaela", LEN_TEXT_CHAR, "Pereyra Trota", LEN_TEXT_CHAR, 3, "CNC061245", LEN_FLIGHT_CODE, 154859.26);
		addPassenger(pPassenger, len_passenger, "Maria del Carmen", LEN_TEXT_CHAR, "Mezada", LEN_TEXT_CHAR, 4, "MDQ070902", LEN_FLIGHT_CODE, 26542.10);
		addPassenger(pPassenger, len_passenger, "Elsa", LEN_TEXT_CHAR, "Loureiro", LEN_TEXT_CHAR, 2, "CLF022203", LEN_FLIGHT_CODE, 54236.98);
		addPassenger(pPassenger, len_passenger, "Elisardo", LEN_TEXT_CHAR, "Castro", LEN_TEXT_CHAR, 2, "CLF022203", LEN_FLIGHT_CODE, 54236.98);
		addPassenger(pPassenger, len_passenger, "Christian Alejandro", LEN_TEXT_CHAR, "Ernodo", LEN_TEXT_CHAR, 1, "BST061304", LEN_FLIGHT_CODE, 164253.68);
		addPassenger(pPassenger, len_passenger, "Pablo", LEN_TEXT_CHAR, "Maldonado", LEN_TEXT_CHAR, 1, "TRP072560", LEN_FLIGHT_CODE, 310253.56);
		validation = 0;
	}
	return validation;
}

/**
* \brief Finds a passenger by ID and returns the index position in the array
* \param Passengers Array pointer to array of Passengers
* \param int array length
* \param int id to find
* \return Int - index position : success - (-1) : error [Invalid length or NULL pointer or passenger not found]
*/
int findPassengerById(Passengers pPassenger[], int len_passenger, int id) {
	int validation = -1;
	if (pPassenger != NULL && len_passenger > 0 && id > 0) {
		for (int i = 0; i < len_passenger; i++) {
			if (pPassenger[i].id == id && pPassenger[i].isEmpty == 0) {
				validation = i;
				break;
			}
		}
	}
	return validation;
}

/**
* \brief Modifies the information for the selected passenger
* \param Passengers Array pointer to array of Passengers
* \param int array length
* \param int id to modify
* \return Int - 0 : success - (-1) : error [Invalid length or NULL pointer or passenger not found]
*/
int modifyPassenger(Passengers pPassenger[], int len_passenger, int id) {
	int validation = -1;
	int index;
	int optionSubMenu;
	int exitValue;
	if (pPassenger != NULL && len_passenger > 0 && id > 0) {
		index = findPassengerById(pPassenger, len_passenger, id);
		if(index != -1){
			printPaxListHeader();
			showPax(pPassenger[index]);
			printf("\n\n");
			do{
				printSubMenuModifyPax(pPassenger[index].name, pPassenger[index].lastName, pPassenger[index].passengerType,
						pPassenger[index].flightCode, pPassenger[index].price);
				exitValue = getOption(&optionSubMenu, 1, 6, 3);
				switch(optionSubMenu) {
					case 1:
						if (getPassengersName( pPassenger[index].name, LEN_TEXT_CHAR, 3)) {
							printf("El nombre no fue salvado. Intente nuevamente.\n");
						}
						break;
					case 2:
						if (getPassengersLastName( pPassenger[index].lastName, LEN_TEXT_CHAR, 3)) {
							printf("El apellido no fue salvado. Intente nuevamente.\n");
						}
						break;
					case 3:
						if (getPassengersType( &pPassenger[index].passengerType, 3)) {
							printf("El tipo de pasajero no fue salvado. Intente nuevamente.\n");
						}
						break;
					case 4:
						if (getPassengersFlightCode( pPassenger[index].flightCode, LEN_FLIGHT_CODE,3)) {
							printf("El código del vuelo no fue salvado. Intente nuevamente.\n");
						}
						break;
					case 5:
						if (getPassengersPrice( &pPassenger[index].price, 1, 5000000,3)) {
							printf("El precio del vuelo no fue salvado. Intente nuevamente.\n");
						}
						break;
					case 6:
						break;
				}
			} while (exitValue == 0 && optionSubMenu != 6);

		}
	}
	return validation;
}

/**
* \brief Asks the end user for the id of the passenger to modify
* \param int pointer to selected id
* \param int minimum accepted value
* \param int maximum accepted value
* \param int number of tries the user has
* \return Int - 0 : success - (-1) : error
*
*/
int getPaxId(int *pPaxId, int minimumValue, int maximumValue, int tries) {
	int validation;
	fflush( stdin );
	validation = -1;
	if (pPaxId != NULL && tries > 0){
		do {
			printf("\n====================================================================================================================\n");
			printf("\nIngrese ID del pasajero: ");
			validation = getInt(pPaxId, minimumValue, maximumValue);
			tries--;
			if (validation != 0 && tries > 0) {
				printf("\nLa opción ingresada no es correcta.\nPor favor, ingrese una opción entre %d y %d. "
						"Usted tiene %d intentos.\n", minimumValue, maximumValue, tries);
			}
		} while (validation != 0 && tries > 0);
	}
	return validation;
}
