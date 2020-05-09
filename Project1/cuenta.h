#pragma once
#include<iostream>
#include <sstream>
using namespace std;

// Los atributos NO se alteran ni se cambian
// Puede agregar metodos si lo requiere


class Cuenta
{
private:
	int numCuenta; 
	string tipo; // credito o debito
	int monto;
public:
	Cuenta(int, string, int );
	int  getMonto();
	int getNumCuenta();
	string getTipo();
	string toString();
};

Cuenta::Cuenta(int numCuenta, string tipo, int monto) {
	this->numCuenta = numCuenta;
	this->tipo = tipo;
	this->monto = monto;
}
//----------------------------------------------------
int Cuenta::getNumCuenta() { return numCuenta; }
//----------------------------------------------------
int Cuenta::getMonto() { return monto; }
//----------------------------------------------------
string Cuenta::getTipo() { return tipo; }

//----------------------------------------------------
string Cuenta::toString() {
	stringstream r;
	r << "\t\t" << "Numero de Cuenta: " << this->numCuenta << endl;
	r << "\t\t" << "Tipo :" << this->tipo<< endl;
	r << "\t\t" << "Monto:" << this->monto<< endl;
	return r.str();
}

