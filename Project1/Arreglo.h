#pragma once

#include <sstream>
#include <string>
#include "coleccion.h"
#include "IteradorArreglo.h"
#define MAX 7
using namespace std;

template <class T>


class Arreglo : public Coleccion<T> {
private:
	int _n;
	T** _v;
	int _k;
public:
	Arreglo();
	~Arreglo();
	T* buscar(T*);
	bool buscar(int);
	T** getV();
	int getN();
	int getK();
	string toString();
	void borrarTodo();
	bool agregaFinal(T*);
	bool vacio();
	IteradorArreglo<T>* getIterador();


};

//--------------------------------------------
template <class T>
Arreglo <T>::Arreglo() : _n(MAX), _k(0), _v(new T* [MAX]) {}


//-------------------------------------------------------
template <class T>
bool Arreglo <T>::vacio()
{
	if (_k == 0) { return false; }
	else return true;
}

//-----------------------------------------------

template<class T>
IteradorArreglo<T>* Arreglo<T>::getIterador()
{
	return new IteradorArreglo<T>(_v, _k);
}

//-----------------------------------------------

template <class T>
void Arreglo<T>::borrarTodo() {
	for (int i = 0; i < _k; i++)
	{
		delete _v[i];
	}
	// no borra el arreglo
}


//--------------------------------

template <class T>
Arreglo<T>::~Arreglo() {
	borrarTodo();
	delete[] _v;
}


//--------------------------------------------

template <class T>
bool Arreglo<T>::agregaFinal(T* x) {

	if (_k < MAX) {
		_v[_k++] = x;
		return true;
	}
	return false;
}


//--------------------------------------------
template <class T>
string Arreglo<T>::toString() {
	stringstream r;


	for (int i = 0; i < _k; i++) {

		r << i + 1 << " - ";
		r << _v[i]->toString() << endl;
	}
	return r.str();
}

//----------------------------------------------
template <class T>
T* Arreglo<T>::buscar(T* aux) {
	for (int i = 0; i < _k; i++)
	{
		if (*(aux) == *(_v[i]))
		{
			return  _v[i];
		}
	}
	return NULL;
}

template<class T>
bool Arreglo<T>::buscar(int aux)
{
	for (int i = 0; i < _k; i++)
	{
		if ((aux) = (_v[i]))
		{
			return  true;
		}
	}
	return false;
}

//----------------------------------------------
template <class T>
T** Arreglo<T>::getV() 
{
	return _v;
}


//-----------------------------------------------
template <class T>
int Arreglo<T>::getN() { return _n; }


//-----------------------------------------------
template <class T>
int Arreglo<T>::getK() { return _k; }