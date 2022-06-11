/*
 * Passenger.h
 *
 *  Author: Candela Bogado
 *  Created on: 5 Junio 2022
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

//passengerType
#define FIRSTCLASS 1
#define EXECUTIVECLASS 2
#define ECONOMYCLASS 3

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
} Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id, char* nombre,char* apellido, float precio, int tipoPax, char* codigoVuelo);
//void Passenger_delete();
//
int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this, char* nombre, int len_name);
int Passenger_getNombre(Passenger* this, char* nombre, int len_name);

int Passenger_setApellido(Passenger* this, char* apellido, int len_apellido);
int Passenger_getApellido(Passenger* this, char* apellido, int len_apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo, int len_codigo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo, int len_codigo);

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, int * tipoPasajero);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float * precio);

//int getNewId();

#endif /* PASSENGER_H_ */
