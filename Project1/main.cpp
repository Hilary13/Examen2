#include <iostream>
#include <sstream>
using namespace std;
#include "banco.h"


int main(int, const char*[]) {

   Banco *b = new Banco();
   b->menu();

   // no hace falta agregar nada mas en el main
	cin.get();
	return 0;
}