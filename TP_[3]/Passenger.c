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

/**
* \brief Reserva un espacio de memoria para un pasajero y lo inicializa
* \param void
* \return puntero a Passenger creado
*
*/
Passenger* Passenger_new() {
	Passenger * onePassenger;
	onePassenger = (Passenger *) malloc(sizeof(Passenger));
	if (onePassenger != NULL) {
		Passenger_setId(onePassenger, 0);
		Passenger_setNombre(onePassenger, " ", 50);
		Passenger_setApellido(onePassenger, " ", 50);
		Passenger_setPrecio(onePassenger, 1);
		Passenger_setTipoPasajero(onePassenger, 1);
		Passenger_setCodigoVuelo(onePassenger, " ", 8);
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
Passenger* Passenger_newParametros(int id, char* nombre,char* apellido, float precio,
		int tipoPax, char* codigoVuelo) {
	Passenger *pPassenger;
	pPassenger = Passenger_new();

	if (pPassenger != NULL) {
		Passenger_setId(pPassenger, id);
		Passenger_setNombre(pPassenger, nombre, 50);
		Passenger_setApellido(pPassenger, apellido, 50);
		Passenger_setPrecio(pPassenger, precio);
		Passenger_setTipoPasajero(pPassenger, tipoPax);
		Passenger_setCodigoVuelo(pPassenger, codigoVuelo, 8);
	}
	return pPassenger;
}


/**
* \brief Setea el id del pasajero en el campo de la estructura destinado a ello
* \param Passenger pointer al pasajero a setear
* \param int id del pasajero a setear
* \return Int - 0 : success - (-1) : error
*
*/
int Passenger_setId(Passenger* this, int id) {
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
int Passenger_getId(Passenger* this, int * id) {
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
int Passenger_setNombre(Passenger* this, char* nombre, int len_name) {
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
int Passenger_getNombre(Passenger* this, char* nombre, int len_name) {
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
int Passenger_setApellido(Passenger* this, char* apellido, int len_apellido) {
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
int Passenger_getApellido(Passenger* this, char* apellido, int len_apellido) {
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
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo, int len_codigo) {
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
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo, int len_codigo) {
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
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero) {
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
int Passenger_getTipoPasajero(Passenger* this, int * tipoPasajero) {
	int validation;
	validation = -1;
	if (this != NULL && tipoPasajero != NULL) {
		*tipoPasajero = this->tipoPasajero;
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
int Passenger_setPrecio(Passenger* this, float precio) {
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
int Passenger_getPrecio(Passenger* this, float * precio) {
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
//int getNewId() {
//    static int id = 0;
//    id++;
//    return id;
//}
