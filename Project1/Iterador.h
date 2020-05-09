#pragma once

template <class T>

class  Iterador {
public:
	virtual bool isDone() = 0;
	virtual  void next() = 0;
	virtual  T* currenItem() = 0;
	virtual  void first() = 0;
};

