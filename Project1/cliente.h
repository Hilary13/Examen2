
#pragma once
#include<iostream>
#include <sstream>
#include "cuenta.h"
#include "Arreglo.h"
using namespace std;

// Los atributos NO se alteran ni se cambian
// El unico atributo que se debe agregar, es el necesario para establecer la relacion requerida
// Puede agregar metodos si lo requiere


class Cliente 
{
private:
	string nombre;
	string cedula;
	Arreglo<Cuenta>* arreCuenta;

public:
	Cliente(string, string);
	void setNombre(string);
	void setCedula(string);
	string getNombre();
	string getCedula();
	Arreglo<Cuenta>* getCuenta();
	virtual string toString()const;
	bool operator==(const Cliente&);
	bool operator!=(const Cliente&);
	

};
ostream& operator<<(std::ostream&, const Cliente&);

Cliente::Cliente(string nombre, string cedula ) {
	this->nombre = nombre;
	this->cedula = cedula;
}
//-------------------------------------------------
void Cliente::setNombre(string nombre) { this->nombre = nombre; }
void Cliente::setCedula(string cedula) { this->cedula = cedula; }
string Cliente::getNombre() { return this->nombre; }
string Cliente::getCedula() { return this->cedula; }

 Arreglo<Cuenta>* Cliente::getCuenta()
{
	return arreCuenta;
}


//----------------------------------------------------
string Cliente::toString()const {
	stringstream r;
	r << "\t" << "Nombre: " << this->nombre << endl;
	r << "\t" << "Cedula:" << this->cedula << endl;
	r << "\t" << "Cantidad de cuentas:" <<  arreCuenta->getK() << endl;////////// completar
	return r.str();
}

inline bool Cliente::operator==(const Cliente& aux)
{
	if (nombre == aux.nombre && cedula == aux.cedula) {
		return true;
	}
	return false;
}

inline bool Cliente::operator!=(const Cliente& aux)
{
	if (nombre != aux.nombre && cedula != aux.cedula) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& salida, const Cliente& u)
{
	salida << u.toString();
	return salida;
}
