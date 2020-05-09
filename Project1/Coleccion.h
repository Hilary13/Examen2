#pragma once
template <class T>
class Coleccion {
public:
	virtual void borrarTodo() = 0;
	virtual bool agregaFinal(T*) = 0;// 
	virtual bool vacio() = 0;
	virtual string toString() = 0;

	// 	virtual void eliminarFinal() = 0;// No tiene utilidad practica
};