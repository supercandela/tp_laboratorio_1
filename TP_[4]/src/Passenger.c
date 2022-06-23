/*
 * Passenger.c
 *
 *  Author: Candela Bogado
 *  Created on: 5 Junio 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "../inc/LinkedList.h"
#include "GetData.h"

#define LEN_CHAR_TEXT 50
#define FIRSTCLASS 1
#define EXECUTIVECLASS 2
#define ECONOMYCLASS 3

/**
 * \brief Reserva un espacio de memoria para un pasajero y lo inicializa
 * \param void
 * \return puntero a Passenger creado
 *
 */
Passenger* Passenger_new() {
	Passenger *onePassenger;
	onePassenger = (Passenger*) malloc(sizeof(Passenger));
	if (onePassenger != NULL) {
		Passenger_setId(onePassenger, 0);
		Passenger_setNombre(onePassenger, " ", LEN_CHAR_TEXT);
		Passenger_setApellido(onePassenger, " ", LEN_CHAR_TEXT);
		Passenger_setPrecio(onePassenger, 1);
		Passenger_setTipoPasajero(onePassenger, 1);
		Passenger_setCodigoVuelo(onePassenger, " ", LEN_CHAR_TEXT);
		Passenger_setEstadoVuelo(onePassenger, 1);
	}
	return onePassenger;
}

/**
 * \brief Genera un puntero a un nuevo pasajero, con los datos que se pasan por parámetros
 * \param int id del pasajero a setear
 * \param char array nombre a setear
 * \param char array apellido a setear
 * \param float precio a setear
 * \param int tipo de pasajero
 * \param char array código de vuelo
 * \return puntero a Passenger creado
 *
 */
Passenger* Passenger_newParametros(int id, char *nombre, char *apellido, float precio,
		int tipoPax, char *codigoVuelo, int estadoVuelo) {
	Passenger *pPassenger;
	pPassenger = Passenger_new();
	if (id < 0){
		id = getNewId();
	}
	if (pPassenger != NULL && id > 0 && nombre != NULL && apellido != NULL
			&& precio > 0 && tipoPax > 0 && tipoPax < 4 && codigoVuelo != NULL
			&& estadoVuelo > 0 && estadoVuelo < 4) {
		Passenger_setId(pPassenger, id);
		Passenger_setNombre(pPassenger, nombre, LEN_CHAR_TEXT);
		Passenger_setApellido(pPassenger, apellido, LEN_CHAR_TEXT);
		Passenger_setPrecio(pPassenger, precio);
		Passenger_setTipoPasajero(pPassenger, tipoPax);
		Passenger_setCodigoVuelo(pPassenger, codigoVuelo, LEN_CHAR_TEXT);
		Passenger_setEstadoVuelo(pPassenger, estadoVuelo);
	}
	return pPassenger;
}

/**
 * \brief Libera el espacio en memoria ocupado por el pasajero que va a ser borrado
 * \param Passenger pointer al pasajero a remover
 * \return void
 *
 */
void Passenger_delete(Passenger * aux) {
	free(aux);
}

/**
 * \brief Setea el id del pasajero en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a setear
 * \param int id del pasajero a setear
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_setId(Passenger *this, int id) {
	int validation;
	validation = -1;
	if (this != NULL && id > -1) {
		this->id = id;
		validation = 0;
	}
	return validation;
}

/**
 * \brief Obtiene el id del pasajero guardado en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a obtener
 * \param Int pointer para recibir el id
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_getId(Passenger *this, int *id) {
	int validation;
	validation = -1;
	if (this != NULL && id != NULL) {
		*id = this->id;
		validation = 0;
	}
	return validation;
}

/**
 * \brief Setea el nombre del pasajero en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a setear
 * \param char array del nombre del pasajero a setear
 * \param int longitud del char array nombre
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_setNombre(Passenger *this, char *nombre, int len_name) {
	int validation;
	validation = -1;
	if (this != NULL && nombre != NULL && len_name > 0) {
		strncpy(this->nombre, nombre, len_name);
		validation = 0;
	}
	return validation;
}

/**
 * \brief Obtiene el nombre del pasajero guardado en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a obtener
 * \param char array para guardar el nombre del pasajero
 * \param int longitud del nombre
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_getNombre(Passenger *this, char *nombre, int len_name) {
	int validation;
	validation = -1;
	if (this != NULL && nombre != NULL && len_name > 0) {
		strncpy(nombre, this->nombre, len_name);
		validation = 0;
	}
	return validation;
}

/**
 * \brief Setea el apellido del pasajero en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a setear
 * \param char array del apellido del pasajero a setear
 * \param int longitud del char array apellido
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_setApellido(Passenger *this, char *apellido, int len_apellido) {
	int validation;
	validation = -1;
	if (this != NULL && apellido != NULL && len_apellido > 0) {
		strncpy(this->apellido, apellido, len_apellido);
		validation = 0;
	}
	return validation;
}

/**
 * \brief Obtiene el apellido del pasajero guardado en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a obtener
 * \param char array para guardar el apellido del pasajero
 * \param int longitud del apellido
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_getApellido(Passenger *this, char *apellido, int len_apellido) {
	int validation;
	validation = -1;
	if (this != NULL && apellido != NULL && len_apellido > 0) {
		strncpy(apellido, this->apellido, len_apellido);
		validation = 0;
	}
	return validation;
}

/**
 * \brief Setea el código de vuelo del pasajero en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a setear
 * \param char array del código de vuelo del pasajero a setear
 * \param int longitud del char array codigoVuelo
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo, int len_codigo) {
	int validation;
	validation = -1;
	if (this != NULL && codigoVuelo != NULL && len_codigo > 0) {
		strncpy(this->codigoVuelo, codigoVuelo, len_codigo);
		validation = 0;
	}
	return validation;
}

/**
 * \brief Obtiene el codigo de vuelo del pasajero guardado en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a obtener
 * \param char array para guardar el código de vuelo del pasajero
 * \param int longitud del char array codigoVuelo
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo, int len_codigo) {
	int validation;
	validation = -1;
	if (this != NULL && codigoVuelo != NULL && len_codigo > 0) {
		strncpy(codigoVuelo, this->codigoVuelo, len_codigo);
		validation = 0;
	}
	return validation;
}

/**
 * \brief Setea el tipo de pasajero para el vuelo en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a setear
 * \param int tipo de pasajero a setear
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero) {
	int validation;
	validation = -1;
	if (this != NULL && tipoPasajero > 0 && tipoPasajero < 4) {
		this->tipoPasajero = tipoPasajero;
		validation = 0;
	}
	return validation;
}

/**
 * \brief Obtiene el tipo de pasajero guardado en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a obtener
 * \param Int pointer para recibir el tipo de pasajero
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero) {
	int validation;
	validation = -1;
	if (this != NULL && tipoPasajero != NULL) {
		*tipoPasajero = this->tipoPasajero;
		validation = 0;
	}
	return validation;
}

/**
 * \brief Setea el estado del vuelo en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a setear
 * \param int estado a setear
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_setEstadoVuelo(Passenger *this, int estadoVuelo) {
	int validation;
	validation = -1;
	if (this != NULL && estadoVuelo > 0 && estadoVuelo < 4) {
		this->estadoVuelo = estadoVuelo;
		validation = 0;
	}
	return validation;
}

/**
 * \brief Obtiene el estado del vuelo guardado en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a obtener
 * \param Int pointer para recibir el dato
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_getEstadoVuelo(Passenger *this, int *estadoVuelo) {
	int validation;
	validation = -1;
	if (this != NULL && estadoVuelo != NULL) {
		*estadoVuelo = this->tipoPasajero;
		validation = 0;
	}
	return validation;
}

/**
 * \brief Setea el precio pagado por el pasajero para el vuelo en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a setear
 * \param float valor del vuelo a setear
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_setPrecio(Passenger *this, float precio) {
	int validation;
	validation = -1;
	if (this != NULL && precio > 0) {
		this->precio = precio;
		validation = 0;
	}
	return validation;
}

/**
 * \brief Obtiene el precio del vuelo del pasajero guardado en el campo de la estructura destinado a ello
 * \param Passenger pointer al pasajero a obtener
 * \param Float pointer para recibir el precio
 * \return Int - 0 : success - (-1) : error
 *
 */
int Passenger_getPrecio(Passenger *this, float *precio) {
	int validation;
	validation = -1;
	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		validation = 0;
	}
	return validation;
}

/**
 * \brief Genera un valor autoincremental para el campo ID de la estructura Passenger
 * \param void
 * \return Int - the new id created
 *
 */
int getNewId() {
	int idToSet = -1;
	int id;
	int cant;
	FILE * idSaver;

	if((idSaver = fopen("idGenerator.bin","r+b")) == NULL) {
		if((idSaver = fopen("idGenerator.bin","w+b")) != NULL) {
			id = 1001;
			idToSet = id;
			id++;
			fwrite(&id, sizeof(int), 1, idSaver);
			fclose(idSaver);
		}
	} else {
		cant = fread(&id, sizeof(int), 1, idSaver);
		if (cant == 1) {
			fclose(idSaver);
			if((idSaver = fopen("idGenerator.bin","w+b")) != NULL) {
				idToSet = id;
				id++;
				cant = fwrite(&id, sizeof(int), 1, idSaver);
			}
		}
		fclose(idSaver);
	}
	return idToSet;
}

/**
 * \brief Prints one passenger on a formated list
 * \param Passengers passenger
 * \return void
 *
 */
void showPax(Passenger *pax) {
	if (pax != NULL) {
		int column_id = 8;
		int column_text = -30;
		int column_type = -20;
		int column_code = -12;
		int column_price = 15 - 1; //resto 1 por el signo

		int auxId;
		char auxApellido[LEN_CHAR_TEXT];
		char auxNombre[LEN_CHAR_TEXT];
		int auxTipoPax;
		char paxType[15];
		float auxPrecio;
		char auxCodigo[LEN_CHAR_TEXT];
		int auxEstadoVuelo;
		char auxEstadoConvertido[20];

		if (!Passenger_getId(pax, &auxId)
				&& !Passenger_getApellido(pax, auxApellido, LEN_CHAR_TEXT)
				&& !Passenger_getNombre(pax, auxNombre, LEN_CHAR_TEXT)
				&& !Passenger_getTipoPasajero(pax, &auxTipoPax)
				&& !Passenger_getPrecio(pax, &auxPrecio)
				&& !Passenger_getCodigoVuelo(pax, auxCodigo, LEN_CHAR_TEXT)
				&& !Passenger_getEstadoVuelo(pax, &auxEstadoVuelo)) {
			switch (auxTipoPax) {
				case 1:
					strncpy(paxType, "First Class", 15);
					break;
				case 2:
					strncpy(paxType, "Executive", 15);
					break;
				case 3:
					strncpy(paxType, "Economy", 15);
					break;
			}
			switch (auxEstadoVuelo) {
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
		printf("|%*d|%*s|%*s|%*s|%*s|$%*.2f|%*s|\n", column_id, auxId, column_text, auxApellido, column_text, auxNombre,
				column_type, paxType, column_code, auxCodigo, column_price, auxPrecio, column_text, auxEstadoConvertido);
		}
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

printf(
		"\n=========================================================================================================================================================\n");
printf(
		"\n                                                  	LISTADO DE PASAJEROS\n");
printf(
		"\n=========================================================================================================================================================\n");

printf(
		"+--------+------------------------------+------------------------------+--------------------+------------+---------------+------------------------------+\n");
printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n", column_id, " ID", column_text,
		" Apellido", column_text, " Nombre", column_type, " Tipo", column_code,
		" Vuelo", column_price, " Precio", column_text, " Estado Vuelo");
printf(
		"+--------+------------------------------+------------------------------+--------------------+------------+---------------+------------------------------+\n");
}

/**
 * \brief Prints the content of the passengers array
 * \param LinkedList puntero
 * \return Int - 0 : success - (-1) : error
 *
 */
int printPassengers(LinkedList *pArrayListPassenger) {
int validation;
validation = -1;
int len;
int i;
if (pArrayListPassenger != NULL) {
	len = ll_len(pArrayListPassenger);
	if (len > 0) {
		Passenger *aux;
		printPaxListHeader();
		for (i = 0; i < len; i++) {
			aux = ll_get(pArrayListPassenger, i);
			showPax(aux);
		}

		printf(
				"+--------+------------------------------+------------------------------+--------------------+------------+---------------+------------------------------+\n");
		printf(
				"\n=========================================================================================================================================================\n");
		printf("\n\n");

		validation = 0;
	}
}
return validation;
}

/**
 * \brief Obtiene el pasajero según el id
 * \param LinkedList puntero a la lista de pasajeros
 * \param Int id del pasajero a encontrar
 * \return Puntero a pasajero: success - NULL : error
 *
 */
Passenger * getPassengerById(LinkedList * pArrayListPassenger, int idToGet) {
	Passenger * auxPaxToCheck = NULL;
	Passenger * auxPaxToReturn = NULL;
	int len;
	int auxPaxId;
	if (pArrayListPassenger != NULL && idToGet > 0) {
		len = ll_len(pArrayListPassenger);
		for (int i = 0; i < len; i++) {
			auxPaxToCheck = ll_get(pArrayListPassenger, i);
			Passenger_getId(auxPaxToCheck, &auxPaxId);
			if (auxPaxId == idToGet) {
				auxPaxToReturn = auxPaxToCheck;
				break;
			}
		}
	}
	return auxPaxToReturn;
}

/**
 * \brief Compara los IDs de dos pasajeros
 * \param Passenger puntero al primer pasajero a comparar
 * \param Passenger puntero al segundo pasajero a comparar
 * \return Int: -1: si el primer pasajero es menor / 1: si el segundo pasajero es menor / 0: si los valores son iguales
 *
 */
int Passenger_compareById (Passenger * pasajeroUno, Passenger * pasajeroDos) {
	int retorno;
	int auxIdUno;
	int auxIdDos;
	retorno = 0;
	if (pasajeroUno != NULL && pasajeroDos != NULL) {
		Passenger_getId(pasajeroUno, &auxIdUno);
		Passenger_getId(pasajeroDos, &auxIdDos);
		if (auxIdUno > auxIdDos) {
			retorno = 1;
		} else if (auxIdDos > auxIdUno) {
			retorno = -1;
		}
	}
	return retorno;
}

/**
 * \brief Compara los apellidos de dos pasajeros
 * \param Passenger puntero al primer pasajero a comparar
 * \param Passenger puntero al segundo pasajero a comparar
 * \return Int: -1: si el primer pasajero es menor / 1: si el segundo pasajero es menor / 0: si los valores son iguales
 *
 */
int Passenger_compareByApellido (Passenger * pasajeroUno, Passenger * pasajeroDos) {
	int retorno;
	char auxApellidoUno[50];
	char auxApellidoDos[50];

	if(pasajeroUno != NULL && pasajeroDos != NULL) {
		Passenger_getApellido(pasajeroUno, auxApellidoUno, LEN_CHAR_TEXT);
		Passenger_getApellido(pasajeroDos, auxApellidoDos, LEN_CHAR_TEXT);
		retorno = strcmp(auxApellidoUno, auxApellidoDos);
	}
	return retorno;
}

/**
 * \brief Compara los tipos de dos pasajeros
 * \param Passenger puntero al primer pasajero a comparar
 * \param Passenger puntero al segundo pasajero a comparar
 * \return Int: -1: si el primer pasajero es menor / 1: si el segundo pasajero es menor / 0: si los valores son iguales
 *
 */
int Passenger_compareByType (Passenger * pasajeroUno, Passenger * pasajeroDos) {
	int retorno;
	int auxTipoUno;
	int auxTipoDos;
	retorno = 0;
	if (pasajeroUno != NULL && pasajeroDos != NULL) {
		Passenger_getTipoPasajero(pasajeroUno, &auxTipoUno);
		Passenger_getTipoPasajero(pasajeroDos, &auxTipoDos);
		if (auxTipoUno > auxTipoDos) {
			retorno = 1;
		} else if (auxTipoDos > auxTipoUno) {
			retorno = -1;
		}
	}
	return retorno;
}

/**
 * \brief Compara los precios de vuelo de dos pasajeros
 * \param Passenger puntero al primer pasajero a comparar
 * \param Passenger puntero al segundo pasajero a comparar
 * \return Int: -1: si el primer pasajero es menor / 1: si el segundo pasajero es menor / 0: si los valores son iguales
 *
 */
int Passenger_compareByPrecio (Passenger * pasajeroUno, Passenger * pasajeroDos) {
	int retorno;
	float auxPrecioUno;
	float auxPrecioDos;
	retorno = 0;
	if (pasajeroUno != NULL && pasajeroDos != NULL) {
		Passenger_getPrecio(pasajeroUno, &auxPrecioUno);
		Passenger_getPrecio(pasajeroDos, &auxPrecioDos);
		if (auxPrecioUno > auxPrecioDos) {
			retorno = 1;
		} else if (auxPrecioDos > auxPrecioUno) {
			retorno = -1;
		}
	}
	return retorno;
}

/**
 * \brief
 * \param Passenger puntero
 * \return Int: -1 si error. Tipo de pasajero para éxito
 *
 */
int Passenger_CountByType (Passenger * pax) {
	int auxTipoPax;
	auxTipoPax = -1;
	if (pax != NULL) {
		Passenger_getTipoPasajero(pax, &auxTipoPax);
	}
	return auxTipoPax;
}

/**
 * \brief
 * \param Passenger puntero
 * \return Int: -1 si error. 0 si el código de vuelo coincide
 *
 */
int Passenger_SearchByCode (Passenger * pax) {
	int validation;
	validation = -1;
	char auxCodigo[LEN_CHAR_TEXT];
	if (pax != NULL) {
		Passenger_getCodigoVuelo(pax, auxCodigo, LEN_CHAR_TEXT);
		validation = strcmp(auxCodigo, codigoDelUsuario);
	}
	return validation;
}

/**
 * \brief
 * \param Passenger puntero
 * \return void
 *
 */
void Passenger_CalcularMillas (Passenger * pax) {
	float auxPrecio;
	int auxTipoPasajero;
	int millasAEntregar;
	int valorUnitarioMilla;
	valorUnitarioMilla = 100;
	if (pax != NULL) {
		Passenger_getPrecio(pax, &auxPrecio);
		Passenger_getTipoPasajero(pax, &auxTipoPasajero);

		millasAEntregar = auxPrecio / valorUnitarioMilla;
		if (auxTipoPasajero == FIRSTCLASS) {
			millasAEntregar = millasAEntregar * 2;
		} else if (auxTipoPasajero == EXECUTIVECLASS) {
			millasAEntregar = millasAEntregar * 3;
		}



//		se deberá informar el listado de pasajeros con una columna extra
//		que indicará las millas que se acumularon con ese vuelo según el siguiente criterio:
//
//
//
//		Para el desarrollo de este punto se deberá crear la función “ll_map()”, que permitirá calcular
//		el campo millas.

//		Prototipo de la función:
//		La función “ll_map” recibirá una lista y una función “fn”. Se deberá iterar todos los elementos
//		de la lista y pasárselos a la función “fn”. La función “fn” podrá realizar un cálculo con el
//		elemento recibido y modificar alguno de sus campos si es necesario. Al finalizar la iteración,
//		los elementos de la lista quedarán modificados.
	}
}


