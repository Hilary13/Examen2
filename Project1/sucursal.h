#pragma once
#include<iostream>
#include <sstream>
#include "cliente.h"
#include "Lista.h"
#include "IteradorLista.h"
using namespace std;

// Los atributos NO se alteran ni se cambian
// El unico atributo que se debe agregar, es el necesario para establecer la relacion requerida
// Puede agregar metodos si lo requiere


class Sucursal
{
private:
	string nombre;
	int numSuc;
	Lista<Cliente>* listCliente = new Lista<Cliente>;

public:
	Sucursal(string, int);
	Sucursal();
	string toString();
	int getNumSuc();
	string getNombre();
	Lista<Cliente>* getListaCliente();
	Sucursal& operator=(Sucursal&);
	virtual void operator[] (unsigned int);
	virtual Sucursal* operator + (Sucursal&);
};
//------------------------------------------------------------
Sucursal::Sucursal(string nom, int num) {
	nombre = nom;
	numSuc = num;
	//cliente = clie;
}

inline Sucursal::Sucursal()
{
	nombre = "";
	numSuc = 0;
}



//------------------------------------------------------------
string Sucursal::toString() {
	stringstream s;
	s << "Nombre de Sucursal: " << nombre << endl;
	s << "Numero de Sucursal: " << numSuc << endl; 
	s << "\t" << "Cantidad de clientes:" << listCliente->getCantidad() << endl;////////// completar
	s << endl;
	return s.str();
}
//------------------------------------------------------------
int Sucursal::getNumSuc() { return numSuc;  }
//------------------------------------------------------------
string Sucursal::getNombre() { return nombre; }
inline Lista<Cliente>* Sucursal::getListaCliente()
{
	return listCliente;
}

inline Sucursal& Sucursal::operator=(Sucursal& n)
{
	nombre = n.getNombre();
	numSuc = n.getNumSuc();
	listCliente = n.getListaCliente();
	return *this;

}

inline void Sucursal::operator[](unsigned int n)
{
	//cout<<listCliente->
}

Sucursal* Sucursal::operator+(Sucursal& sucu)
{
	Lista<Cliente>* sucu1 = listCliente;
	Lista<Cliente>* sucu2 = sucu.getListaCliente();
	IteradorLista<Cliente>* ite = sucu2->obtenerIterador();
	while(ite->isDone()) {

		sucu1->insertarInicio(ite->currenItem());

	}

	return this;
	
}


