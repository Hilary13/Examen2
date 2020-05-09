
#pragma once
#include<iostream>
#include <sstream>
#include "cuenta.h"
using namespace std;

// Los atributos NO se alteran ni se cambian
// El unico atributo que se debe agregar, es el necesario para establecer la relacion requerida
// Puede agregar metodos si lo requiere


class Cliente 
{
private:
	string nombre;
	string cedula;

public:
	Cliente(string, string);
	void setNombre(string);
	void setCedula(string);
	string getNombre();
	string getCedula();
	string toString();

};


Cliente::Cliente(string nombre, string cedula ) {
	this->nombre = nombre;
	this->cedula = cedula;
}
//-------------------------------------------------
void Cliente::setNombre(string nombre) { this->nombre = nombre; }
void Cliente::setCedula(string cedula) { this->cedula = cedula; }
string Cliente::getNombre() { return this->nombre; }
string Cliente::getCedula() { return this->cedula; }


//----------------------------------------------------
string Cliente::toString() {
	stringstream r;
	r << "\t" << "Nombre: " << this->nombre << endl;
	r << "\t" << "Cedula:" << this->cedula << endl;
	r << "\t" << "Cantidad de cuentas:" <<  "?????????????"  << endl;////////// completar
	return r.str();
}


