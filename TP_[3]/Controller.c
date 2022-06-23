#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "MenusReportsOthers.h"
#include "GetPassengerData.h"
#include "GetData.h"

#define LEN_TEXT_CHAR 50

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListPassenger) {
	int validation;
	validation = -1;
    FILE * textFile;
	int cant;
	char auxId[LEN_TEXT_CHAR];
	char auxName[LEN_TEXT_CHAR];
	char auxLastName[LEN_TEXT_CHAR];
	char auxPrice[LEN_TEXT_CHAR];
	char auxFlightCode[LEN_TEXT_CHAR];
	char auxTypePassenger[LEN_TEXT_CHAR];
	char auxStatusFlight[LEN_TEXT_CHAR];
	int idToSet;
	float priceToSet;
	int typePaxToSet;
	int statusFlightToSet;
	Passenger *auxPax;
	if(path != NULL && pArrayListPassenger != NULL) {
	    if((textFile = fopen(path,"r")) == NULL) {
			printf("No se pudo abrir el archivo");
	    } else {
	    	do {
	    		cant = fscanf(textFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
	    				auxId, auxName, auxLastName, auxPrice, auxFlightCode, auxTypePassenger, auxStatusFlight);
		    	if (cant == 7) {
		    		if (isInt(auxId)) {
						idToSet = atoi(auxId);
						priceToSet = atof(auxPrice);
						if (strcmp(auxTypePassenger, "FirstClass") == 0) {
							typePaxToSet = 1;
						} else if (strcmp(auxTypePassenger, "ExecutiveClass") == 0) {
							typePaxToSet = 2;
						} else if (strcmp(auxTypePassenger, "EconomyClass") == 0) {
							typePaxToSet = 3;
						}
						if (strcmp(auxStatusFlight, "En Horario") == 0) {
							statusFlightToSet = 1;
						} else if (strcmp(auxStatusFlight, "En Vuelo") == 0) {
							statusFlightToSet = 2;
						} else if (strcmp(auxStatusFlight, "Aterrizado") == 0) {
							statusFlightToSet = 3;
						}
						auxPax = Passenger_newParametros(idToSet, auxName, auxLastName, priceToSet,
								typePaxToSet, auxFlightCode, statusFlightToSet);
						if (auxPax == NULL) {
							printf("El pasajero no fue salvado. Intente nuevamente.\n");
						} else {
							ll_add(pArrayListPassenger, auxPax);
						}
		    		}
		    	}
	    	} while (cant == 7);
			fclose(textFile);
			validation = 0;
	    }
	}
	return validation;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListPassenger) {
	int validation;
	validation = -1;
    FILE * binFile;
	int cant;
	Passenger *auxPax;
	int idToSet;
	char auxName[LEN_TEXT_CHAR];
	char auxLastName[LEN_TEXT_CHAR];
	float auxPrice;
	char auxFlightCode[LEN_TEXT_CHAR];
	int typePaxToSet;
	int statusFlightToSet;
	if(path != NULL && pArrayListPassenger != NULL) {
		printf("Primer if\n");
	    if((binFile = fopen(path,"r+b")) == NULL) {
			printf("No se pudo abrir el archivo");
	    } else {
	    	printf("Abre el archivo\n");
	    	do {
	    		printf("entra al do\n");
	    		cant = fread(&auxPax, sizeof(Passenger), 1, binFile);
	    		printf("%d,%s,%s,%f,%s,%d,%d\n",
							auxPax->id, auxPax->nombre, auxPax->apellido, auxPax->precio, auxPax->codigoVuelo,
							auxPax->tipoPasajero, auxPax->estadoVuelo);
		    	if (cant == 1) {
		    		if (!Passenger_getId(auxPax, &idToSet)
							&& !Passenger_getApellido(auxPax, auxLastName, LEN_TEXT_CHAR)
							&& !Passenger_getNombre(auxPax, auxName, LEN_TEXT_CHAR)
							&& !Passenger_getTipoPasajero(auxPax, &typePaxToSet)
							&& !Passenger_getPrecio(auxPax, &auxPrice)
							&& !Passenger_getCodigoVuelo(auxPax, auxFlightCode, LEN_TEXT_CHAR)
							&& !Passenger_getEstadoVuelo(auxPax, &statusFlightToSet)) {
						auxPax = Passenger_newParametros(idToSet, auxName, auxLastName, auxPrice,
								typePaxToSet, auxFlightCode, statusFlightToSet);
						if (auxPax == NULL) {
							printf("El pasajero no fue salvado. Intente nuevamente.\n");
						} else {
							ll_add(pArrayListPassenger, auxPax);
						}
		    		}
		    	}
	    	} while (cant == 1);
			fclose(binFile);
			validation = 0;
	    }
	}
	return validation;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList *pArrayListPassenger) {
	int validation;
	validation = -1;
	if (pArrayListPassenger != NULL) {
		char pName[LEN_TEXT_CHAR] = " ";
		char pLastName[LEN_TEXT_CHAR] = " ";
		char pFlightCode[LEN_TEXT_CHAR] = " ";
		int auxTipoPax = -1;
		float auxPrice = -1;
		int auxStatusFlight = -1;
		int exitValueGetOptionSubMenu;
		int submenuOption;
		Passenger *auxPax;

		do {
			printSubMenuAddPax(pName, pLastName, auxTipoPax, pFlightCode,
					auxPrice, auxStatusFlight);
			exitValueGetOptionSubMenu = askIntValue(&submenuOption,
							"\n================================================================================"
							"=========================================================================\n\nIngrese una opción: ",
							"La opción ingresada no es correcta.", 1, 8, 3);
			if (exitValueGetOptionSubMenu == 0) {
				switch (submenuOption) {
				case 1:
					if (getPassengersName(pName, LEN_TEXT_CHAR, 3)) {
						printf("El nombre no fue salvado. Intente nuevamente.\n");
					}
					break;
				case 2:
					if (getPassengersLastName(pLastName, LEN_TEXT_CHAR, 3)) {
						printf("El apellido no fue salvado. Intente nuevamente.\n");
					}
					break;
				case 3:
					if (getPassengersType(&auxTipoPax, 3)) {
						printf("El tipo de pasajero no fue salvado. Intente nuevamente.\n");
					}
					break;
				case 4:
					if (getPassengersFlightCode(pFlightCode, LEN_TEXT_CHAR, 3)) {
						printf("El código del vuelo no fue salvado. Intente nuevamente.\n");
					}
					break;
				case 5:
					if (getPassengersPrice(&auxPrice, 1, 30000000, 3)) {
						printf("El precio del vuelo no fue salvado. Intente nuevamente.\n");
					}
					break;
				case 6:
					if (getStatusFlight(&auxStatusFlight, 3)) {
						printf("El estado del vuelo no fue salvado. Intente nuevamente.\n");
					}
					break;
				case 7:
					auxPax = Passenger_newParametros(-1, pName, pLastName, auxPrice,
							auxTipoPax, pFlightCode, auxStatusFlight);
					if (auxPax == NULL) {
						printf("El pasajero no fue salvado. Intente nuevamente.\n");
					} else {
						if (!ll_add(pArrayListPassenger, auxPax)){
							printSeparationLine();
							printf("\nPasajero guardado.\n");
							strncpy(pName, " ", LEN_TEXT_CHAR);
							strncpy(pLastName, " ", LEN_TEXT_CHAR);
							auxTipoPax = -1;
							strncpy(pFlightCode, " ", LEN_TEXT_CHAR);
							auxPrice = -1;
							auxStatusFlight = -1;
						} else {
							printf("Se produjo un error. Pasajero NO guardado.\n");
						}
					}
					break;
				case 8:
					break;
				}
			}
			if (exitValueGetOptionSubMenu < 0) {
				printSeparationLine();
				printf("\nLa opción ingresada no es válida y se quedó sin intentos.\nVuelva a intentarlo en unos minutos."
								"\nEl pasajero no fue agregado.");
			}
			validation = 0;
		} while (submenuOption != 8 && exitValueGetOptionSubMenu == 0);

	}
	return validation;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList *pArrayListPassenger) {
	int validation;
	validation = -1;
	int idAModificar;
	Passenger * auxPax = NULL;
	int exitValueGetOptionSubMenu;
	int submenuOption;
	int auxPaxId;
	char pName[LEN_TEXT_CHAR] = " ";
	char pLastName[LEN_TEXT_CHAR] = " ";
	char pFlightCode[LEN_TEXT_CHAR] = " ";
	int auxTipoPax = -1;
	float auxPrice = -1;
	int auxStatusFlight = -1;
	if (pArrayListPassenger != NULL) {
		do {
			if (printPassengers(pArrayListPassenger) == 0 &&
					askIntValue(&idAModificar, "Ingrese el ID del pasajero a modificar:", "ID Incorrecto.", 1, 10000, 3) == 0) {
				auxPax = getPassengerById(pArrayListPassenger, idAModificar);

				if (auxPax != NULL) {
					if (!Passenger_getId(auxPax, &auxPaxId)
							&& !Passenger_getApellido(auxPax, pLastName, LEN_TEXT_CHAR)
							&& !Passenger_getNombre(auxPax, pName, LEN_TEXT_CHAR)
							&& !Passenger_getTipoPasajero(auxPax, &auxTipoPax)
							&& !Passenger_getPrecio(auxPax, &auxPrice)
							&& !Passenger_getCodigoVuelo(auxPax, pFlightCode, LEN_TEXT_CHAR)
							&& !Passenger_getEstadoVuelo(auxPax, &auxStatusFlight)) {

						do {
							printSubMenuEditPax(pName, pLastName, auxTipoPax, pFlightCode, auxPrice, auxStatusFlight);
							exitValueGetOptionSubMenu = askIntValue(&submenuOption,
										"\n================================================================================"
										"=========================================================================\n\nIngrese una opción: ",
										"La opción ingresada no es correcta.", 1, 7, 3);

							if (exitValueGetOptionSubMenu == 0) {
								switch (submenuOption) {
								case 1:
									if (getPassengersName(pName, LEN_TEXT_CHAR, 3)) {
										printf("El nombre no fue salvado. Intente nuevamente.\n");
									} else {
										Passenger_setNombre(auxPax, pName, LEN_TEXT_CHAR);
									}
									break;
								case 2:
									if (getPassengersLastName(pLastName, LEN_TEXT_CHAR, 3)) {
										printf("El apellido no fue salvado. Intente nuevamente.\n");
									} else {
										Passenger_setApellido(auxPax, pLastName, LEN_TEXT_CHAR);
									}
									break;
								case 3:
									if (getPassengersType(&auxTipoPax, 3)) {
										printf("El tipo de pasajero no fue salvado. Intente nuevamente.\n");
									} else {
										Passenger_setTipoPasajero(auxPax, auxTipoPax);
									}
									break;
								case 4:
									if (getPassengersFlightCode(pFlightCode, LEN_TEXT_CHAR, 3)) {
										printf("El código del vuelo no fue salvado. Intente nuevamente.\n");
									} else {
										Passenger_setCodigoVuelo(auxPax, pFlightCode, LEN_TEXT_CHAR);
									}
									break;
								case 5:
									if (getPassengersPrice(&auxPrice, 1, 30000000, 3)) {
										printf("El precio del vuelo no fue salvado. Intente nuevamente.\n");
									} else {
										Passenger_setPrecio(auxPax, auxPrice);
									}
									break;
								case 6:
									if (getStatusFlight(&auxStatusFlight, 3)) {
										printf("El estado del vuelo no fue salvado. Intente nuevamente.\n");
									} else {
										Passenger_setEstadoVuelo(auxPax, auxStatusFlight);
									}
									break;
								case 7:
									break;
								}
							} else if (exitValueGetOptionSubMenu < 0) {
								printSeparationLine();
								printf("\nLa opción ingresada no es válida y se quedó sin intentos.\nVuelva a intentarlo en unos minutos."
												"\nEl pasajero no fue editado.");
							}
							validation = 0;
						} while (submenuOption != 7 && exitValueGetOptionSubMenu == 0);
					}
				} else {
					printf("\nNo se encontró el pasajero ingresado.\n");
				}
			} else {
				printf("\nNo se pueden listar los pasajeros en este momento.\n");
			}
			printf("\n¿Modificar otro pasajero?\n");
		} while (doYouConfirm());
	}
	return validation;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList *pArrayListPassenger) {
	int validation;
	validation = -1;
	int idAEliminar;
	Passenger * auxPax = NULL;
	char pName[LEN_TEXT_CHAR] = " ";
	char pLastName[LEN_TEXT_CHAR] = " ";
	char pFlightCode[LEN_TEXT_CHAR] = " ";
	int auxTipoPax = -1;
	float auxPrice = -1;
	int auxStatusFlight = -1;
	int auxPaxId;
	int indexAEliminar;

	if (pArrayListPassenger != NULL) {
		do {
			if (printPassengers(pArrayListPassenger) == 0 &&
					askIntValue(&idAEliminar, "Ingrese el ID del pasajero a eliminar:", "ID Incorrecto.", 1, 10000, 3) == 0) {
				auxPax = getPassengerById(pArrayListPassenger, idAEliminar);
				if (auxPax != NULL) {
					if (!Passenger_getId(auxPax, &auxPaxId)
							&& !Passenger_getApellido(auxPax, pLastName, LEN_TEXT_CHAR)
							&& !Passenger_getNombre(auxPax, pName, LEN_TEXT_CHAR)
							&& !Passenger_getTipoPasajero(auxPax, &auxTipoPax)
							&& !Passenger_getPrecio(auxPax, &auxPrice)
							&& !Passenger_getCodigoVuelo(auxPax, pFlightCode, LEN_TEXT_CHAR)
							&& !Passenger_getEstadoVuelo(auxPax, &auxStatusFlight)) {

						printSubMenuEditPax(pName, pLastName, auxTipoPax, pFlightCode, auxPrice, auxStatusFlight);
						printf("\nEliminar pasajero\n");
						if(doYouConfirm()){
							indexAEliminar = ll_indexOf(pArrayListPassenger, auxPax);
							if (indexAEliminar > -1) {
								Passenger_delete(auxPax);
								if(ll_remove(pArrayListPassenger, indexAEliminar) == 0) {
									printf("\nPasajero eliminado.\n");
									validation = 0;
								}
							}
						}
					}
				} else {
					printf("\nNo se encontró el pasajero ingresado.\n");
				}
			} else {
				printf("\nNo se pueden listar los pasajeros en este momento.\n");
			}
			printf("\n¿Eliminar otro pasajero?\n");
		} while (doYouConfirm());
	}
	return validation;

}

/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return int 0 =  Success / -1 = Error
 *
 */
int controller_ListPassenger(LinkedList *pArrayListPassenger) {
	int validation;
	validation = -1;
	if (pArrayListPassenger != NULL) {
		validation = printPassengers(pArrayListPassenger);
	}
	return validation;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList *pArrayListPassenger) {
	int validation;
	validation = -1;
	int exitValueGetOptionSubMenu;
	int submenuOption;

	if (pArrayListPassenger != NULL) {
		do {
			printSubMenuSortPax();
			exitValueGetOptionSubMenu = askIntValue(&submenuOption,
				"\n================================================================================"
				"=========================================================================\n\nIngrese una opción: ",
				"La opción ingresada no es correcta.", 1, 9, 3);
			if (exitValueGetOptionSubMenu == 0) {
				switch (submenuOption) {
				case 1:
					if (ll_sort(pArrayListPassenger, Passenger_compareById, 1) == 0) {
						printPassengers(pArrayListPassenger);
					}
					break;
				case 2:
					if (ll_sort(pArrayListPassenger, Passenger_compareById, 0) == 0) {
						printPassengers(pArrayListPassenger);
					}
					break;
				case 3:
					if (ll_sort(pArrayListPassenger, Passenger_compareByApellido, 1) == 0) {
						printPassengers(pArrayListPassenger);
					}
					break;
				case 4:
					if (ll_sort(pArrayListPassenger, Passenger_compareByApellido, 0) == 0) {
						printPassengers(pArrayListPassenger);
					}
					break;
				case 5:
					if (ll_sort(pArrayListPassenger, Passenger_compareByType, 1) == 0) {
						printPassengers(pArrayListPassenger);
					}
					break;
				case 6:
					if (ll_sort(pArrayListPassenger, Passenger_compareByType, 0) == 0) {
						printPassengers(pArrayListPassenger);
					}
					break;
				case 7:
					if (ll_sort(pArrayListPassenger, Passenger_compareByPrecio, 1) == 0) {
						printPassengers(pArrayListPassenger);
					}
					break;
				case 8:
					if (ll_sort(pArrayListPassenger, Passenger_compareByPrecio, 0) == 0) {
						printPassengers(pArrayListPassenger);
					}
					break;
				case 9:
					break;
				}
			} else if (exitValueGetOptionSubMenu < 0) {
				printSeparationLine();
				printf("\nLa opción ingresada no es válida y se quedó sin intentos.\nVuelva a intentarlo en unos minutos.\n");
			}
			validation = 0;
		} while (submenuOption != 9 && exitValueGetOptionSubMenu == 0);
	}
	return validation;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListPassenger) {
	int validation;
	validation = -1;
	FILE * textFile;
	int len;
	Passenger * aux;
	int idToSet;
	char auxName[LEN_TEXT_CHAR];
	char auxLastName[LEN_TEXT_CHAR];
	float auxPrice;
	char auxFlightCode[LEN_TEXT_CHAR];
	int typePaxToSet;
	int statusFlightToSet;
	char paxType[15];
	char auxEstadoConvertido[20];

	if (path != NULL && pArrayListPassenger != NULL){
		textFile = fopen(path, "w");
		if (textFile == NULL){
			printf("\nEl archivo no fue abierto. Intente nuevamente en unos minutos.\n");
		} else {
			len = ll_len(pArrayListPassenger);
			if (len > 0) {
				fprintf(textFile, "%s,%s,%s,%s,%s,%s,%s\n",
						"id", "name", "lastname", "price", "flycode", "typePassenger","statusFlight");
				for (int i = 0; i < len; i++) {
					aux = ll_get(pArrayListPassenger, i);
					if (!Passenger_getId(aux, &idToSet)
							&& !Passenger_getApellido(aux, auxLastName, LEN_TEXT_CHAR)
							&& !Passenger_getNombre(aux, auxName, LEN_TEXT_CHAR)
							&& !Passenger_getTipoPasajero(aux, &typePaxToSet)
							&& !Passenger_getPrecio(aux, &auxPrice)
							&& !Passenger_getCodigoVuelo(aux, auxFlightCode, LEN_TEXT_CHAR)
							&& !Passenger_getEstadoVuelo(aux, &statusFlightToSet)) {

						switch (typePaxToSet) {
							case 1:
								strncpy(paxType, "FirstClass", 15);
								break;
							case 2:
								strncpy(paxType, "ExecutiveClass", 15);
								break;
							case 3:
								strncpy(paxType, "EconomyClass", 15);
								break;
						}
						switch (statusFlightToSet) {
							case 1:
								strncpy(auxEstadoConvertido, "En horario", 20);
								break;
							case 2:
								strncpy(auxEstadoConvertido, "En vuelo", 20);
								break;
							case 3:
								strncpy(auxEstadoConvertido, "Aterrizado", 20);
								break;
						}

						fprintf(textFile, "%d,%s,%s,%f,%s,%s,%s\n",
								idToSet, auxName, auxLastName, auxPrice, auxFlightCode, paxType, auxEstadoConvertido);
					}
				}
				validation = 0;
			}
			fclose(textFile);
		}
	}
	return validation;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListPassenger) {
	int validation;
	validation = -1;
	FILE * binFile;
	int len;
	Passenger *aux;
	if (path != NULL && pArrayListPassenger != NULL) {
		printf("\nPrimer IF Save\n");
		binFile = fopen(path,"w+b");
		if (binFile == NULL){
			printf("\nEl archivo no fue abierto. Intente nuevamente en unos minutos.\n");
		} else {
			printf("\nElse Save.\n");
			len = ll_len(pArrayListPassenger);
			if (len > 0) {
				for (int i = 0; i < len; i++) {
					aux = ll_get(pArrayListPassenger, i);
					printf("%d,%s,%s,%f,%s,%d,%d\n",
							aux->id, aux->nombre, aux->apellido, aux->precio, aux->codigoVuelo,
							aux->tipoPasajero, aux->estadoVuelo);
					int cant;
					cant = fwrite(&aux, sizeof(Passenger), 1, binFile);
					printf("cant: %d\n", cant);
				}
				validation = 0;
			}
			fclose(binFile);
		}
	}
	return validation;
}

