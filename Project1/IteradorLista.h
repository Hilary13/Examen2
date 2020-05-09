#pragma once
#include "Iterador.h"
#include "Nodo.h"


template <class T>
class IteradorLista : public Iterador<T> {
private:
	Nodo<T>* cur;
	Nodo<T>* primero;
public:
	IteradorLista(Nodo<T>*);

	virtual bool isDone(); // retorna true si hay mas elementos
	virtual void next();// avanza cur
	virtual T* currenItem();// retorna el elemento actual
	virtual void first(); //pone cur al inicio

};


//----------iterador------------
template <class T>
IteradorLista<T>::IteradorLista(Nodo<T>* p) : cur(p), primero(p) {}
//-------------------------------
template <class T>
bool IteradorLista<T>::isDone()
{
	return (cur != NULL);
}

//------------------------------
template <class T>
T* IteradorLista<T>::currenItem() {
	return  cur->getElemento();
}

//--------------------------------
template <class T>
void IteradorLista<T>::first()
{
	cur = primero;
}

//---------------------------------

template <class T>
void IteradorLista<T>::next()
{
	cur = cur->getSig();
}
