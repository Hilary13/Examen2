#pragma once
#include "Arreglo.h"
#include "Iterador.h"

template <class T>
class IteradorArreglo : public Iterador<T> {
private:
    int cur;
    T** vec;
    int	_k;

public:
    IteradorArreglo(T**, int);

    bool isDone(); // retorna true si hay mas elementos
    T** currenItem();// retorna el elemento actual
    void first(); //pone cur al inicio
    void next();// avanza cur
};


//------------ IteradorArreglo --------------
template<class T>
IteradorArreglo<T>::IteradorArreglo(T** vec, int k) {
    cur = 0;
    _k = k;
    this->vec = vec;
}

//---------------------------------------------
template<class T>
bool IteradorArreglo<T>::isDone()
{

    return (cur < _k);  // no verifica que haya un elemento en la posicion
}

//---------------------------------------------
template<class T>
T** IteradorArreglo<T>::currenItem()
{
    return vec[cur];
    //return *(vec + cur); // esto se denomina aritmetica de operadores y suele verse en progra 1

}
//---------------------------------------------
template<class T>
void IteradorArreglo<T>::next() { cur++; }

//---------------------------------------------
template<class T>
void IteradorArreglo<T>::first() { cur = 0; }
