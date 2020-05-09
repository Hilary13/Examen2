#pragma once
#include<iostream>
#include <sstream>
#include "cliente.h"
using namespace std;

// Los atributos NO se alteran ni se cambian
// El unico atributo que se debe agregar, es el necesario para establecer la relacion requerida
// Puede agregar metodos si lo requiere


class Sucursal
{
private:
	string nombre;
	int numSuc;
	Cliente* cliente;

public:
	Sucursal(string, int, Cliente*);
	string toString();
	int getNumSuc();
	string getNombre();
};
//------------------------------------------------------------
Sucursal::Sucursal(string nom, int num, Cliente* clie) {
	nombre = nom;
	numSuc = num;
	cliente = clie;
}
//------------------------------------------------------------
string Sucursal::toString() {
	stringstream s;
	s << "Nombre de Sucursal: " << nombre << endl;
	s << "Numero de Sucursal: " << numSuc << endl; 
	s << "\t" << "Cantidad de clientes:" << "?????????????" << endl;////////// completar
	s << endl;
	return s.str();
}
//------------------------------------------------------------
int Sucursal::getNumSuc() { return numSuc;  }
//------------------------------------------------------------
string Sucursal::getNombre() { return nombre; }
//------------------------------------------------------------

