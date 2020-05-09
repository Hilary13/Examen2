#pragma once
#include "sucursal.h"
#include "cliente.h"
#include "IteradorLista.h"
#include "IteradorArreglo.h"
#include "Arreglo.h"
#include "Lista.h"

// Puede agregar mas atributos o metodos si lo requiere

class Banco
{
private:
	Arreglo<Sucursal>* arregloSucu = new Arreglo<Sucursal>;

	//Lista<Cliente>* listCli = new Lista<Cliente>;

public:
	Banco();
	void menu();
	void menuCase1();
	void menuCase2();
	void menuCase3();
	void menuCase4();
	void menuCase5();
	void menuCase6();
	void menuCase7();
	void menuCase8();
	void menuCase9();
	virtual void operator[] (unsigned int);




};



//--------------Variables locales-------------
static int codigoSucu = 100;



//-----------------------------------
Banco::Banco()
{

}
//-----------------------------
void Banco::menu()
{
	string aux;
	int opc = 1;
	while (opc != 0)
	{
		cout << "---------------------------------------------------------" << endl << endl;
		       cout << "            MENU" << endl << endl;
		       cout << "1- Ingresar nueva Sucursal" << endl;
		       cout << "2- Mostrar sucursales" << endl;
			   cout << "3- Ingresar Cliente a Sucursal especifica" << endl;
			   cout << "4- Mostrar clientes por Sucursal especifica" << endl;
			   cout << "5- Ingresar  cuentas a  clientes  de una Sucursal especifica " << endl;
			   cout << "6- Mostrar cuentas por  Cliente  especifico " << endl;
			   cout << "7- Probar operador [] " << endl;
			   cout << "8- Probar operador + " << endl;
			   cout << "9- Probar operador == " << endl;
		       cout << "0- Salir" << endl << endl;
		cout << "---------------------------------------------------------" << endl << endl;
		cout << "Digite una opcion del menu: " ;
		cin >> opc;
		system("cls");

		switch (opc)
		{
		    case 1:
				menuCase1();
			    break;
		    case 2:
				menuCase2();
	             break;
			case 3:
				menuCase3();
				break;
			case 4:
				menuCase4();
				break;
			case 5:
				menuCase5();
				break;
			case 6:
				menuCase6();
				break;
			case 7:
				menuCase7();
				break;
			case 8:
				menuCase8();
				break;
			case 9:
				menuCase9();
				break;
			default :
			system("exit");
			break;
		}// fin switch

		cout << endl<<"<<<<Digite enter>>>>" << endl;
		cin.get();
		system("cls");
	}// fin while
}
//----------------------------------------------

void Banco::menuCase1() {
	cout << " --------- (1) Ingresar  nueva Sucursal--------" << endl << endl;
	string nombre;
	cout << "Digite el nombre de la Sucursal: ";
	cin >> nombre;
	codigoSucu++;
	Sucursal* sucursal = new Sucursal(nombre, codigoSucu);
	if (arregloSucu->agregaFinal(sucursal)) {

		cout << sucursal->toString();
		system("pause");
	}
	else {
		cout << "Error al crear sucursal";
	}
	
	cout << "<<Digita Enter>>" << endl;
	cin.get();
}

//----------------------------------------------
void Banco::menuCase2() {
	cout << "------ (2) Mostrar Sucursales------" << endl << endl;

		cout << arregloSucu->toString() << endl;
		system("pause");
		Banco::menu();


	cin.get();
}
//----------------------------------------------
void Banco::menuCase3() {
	cout << "--- (3) Ingresar Cliente a Sucursal especifica--" << endl << endl;
	IteradorArreglo<Sucursal>* ite = arregloSucu->getIterador();
	string nombre;
	string cedula;
	int numSucu;
	ite->first();
	cout << "Ingrese el numero de una sucursal especifica: ";
	cin >> numSucu;
	while (ite->isDone()) {
		
		if (numSucu == (ite->currenItem()->getNumSuc())) {
			cout << "Ingrese el nombre del cliente: ";
			cin >> nombre;
			cout << endl;
			cout << "Ingrese la cedula del cliente: ";
			cin >> cedula;
			ite->currenItem()->getListaCliente()->insertarInicio(new Cliente(nombre, cedula));
			ite->next();
			break;
		}
		ite->next();
	}	
	
	Banco::menu();
	cin.get();
}
//----------------------------------------------
void Banco::menuCase4() {

	cout << "----  (4)Mostrar clientes por Sucursal especifica ----" << endl << endl;
	
	IteradorArreglo<Sucursal>* ite = arregloSucu->getIterador();
	int numSucu;
	ite->first();
	cout << "Ingrese el numero de una sucursal especifica: ";
	cin >> numSucu;
	while (ite->isDone()) {
		if (numSucu == (ite->currenItem()->getNumSuc())) {
			
			cout << ite->currenItem()->getListaCliente()->toString();
		}
		else {
			cout << "Codigo no encontrado";
		}

	}

	cout << "<<Digita Enter>>" << endl;
	cin.get();
}
//----------------------------------------------
void Banco::menuCase5() {
	cout << "----- (5)Ingresar  cuentas a  clientes  de una Sucursal especifica -----" << endl;
	IteradorArreglo<Sucursal>* ite = arregloSucu->getIterador();

	string ceduClie;
	int numSucu;
	ite->first();
	cout << "Ingrese el numero de una sucursal especifica: ";
	cin >> numSucu;
	while (ite->isDone()) {
		if (numSucu == (ite->currenItem()->getNumSuc())) {

			IteradorLista<Cliente>* iteClienta = ite->currenItem()->getListaCliente()->obtenerIterador();
			cout << "Ingrese el numero de cedula: ";
			cin >> ceduClie;
			if (ceduClie == iteClienta->currenItem()->getCedula()) {
				int numCuenta;
				string tipo;
				int monto;
				cout << "Ingrese el numero de cuenta: ";
				cin >> numCuenta;
				cout << endl;
				cout << "Digite el tipo de cuenta (debito/credito): ";
				cin >> tipo;
				cout << endl;
				cout << "Ingrese el monto de la cuenta: ";
				cin >> monto;
				iteClienta->currenItem()->getCuenta()->agregaFinal(new Cuenta(numCuenta, tipo, monto));
				Banco::menu();
			}
			else {
				cout << "Cedula no existe";
			}
			
			

		}
		else {
			cout << "Codigo no encontrado";
		}

		cin.get();

	}
}
//----------------------------------------------
void Banco::menuCase6() {
	cout << "-----(6)Mostrar cuentas por  Cliente  especifico----" << endl;
	
	IteradorArreglo<Sucursal>* ite = arregloSucu->getIterador();

	string ceduClie;
	int numSucu;
	ite->first();
	cout << "Ingrese el numero de una sucursal especifica: ";
	cin >> numSucu;
	while (ite->isDone()) {
		if (numSucu == (ite->currenItem()->getNumSuc())) {

			IteradorLista<Cliente>* iteClienta = ite->currenItem()->getListaCliente()->obtenerIterador();
			cout << "Ingrese el numero de cedula: ";
			cin >> ceduClie;
			if (ceduClie == iteClienta->currenItem()->getCedula()) {

				cout << iteClienta->currenItem()->getCuenta()->toString();
				system("pause");
				system("cls");
				Banco::menu();

			}
			else {
				cout << "Cedula no existe";
			}

		}
		else {
			cout << "Codigo no encontrado";
		}

		cin.get();
	}
}
//----------------------------------------------
void Banco::menuCase7() {
	
	cout << "-----  (7)   Probar operador [] -----" << endl ;
	



	cin.get();
}
//----------------------------------------------
void Banco::menuCase8() {
	
	cout << "----------(8) Probando operador de suma + ----------" << endl;
	cout << "Al sumar dos sucursales, los clientes de la segunda Sucursal pasaran a ser tambien clientes  de la primera Sucursal" << endl << endl;
	IteradorArreglo<Sucursal>* ite = arregloSucu->getIterador();
	int sucu1;
	int sucu2;
	Sucursal* sucuAux = new Sucursal();
	Sucursal* sucuAux1 = new  Sucursal();
	cout << "Digite el codigo de la primer Sucursal (101-107): ";
	cin >> sucu1;
	
	while (ite->isDone()) {
		if (sucu1 == (ite->currenItem()->getNumSuc())) 
		{
			sucuAux = ite->currenItem();
		}
		else {
			cout << "Sucursal 1 no encontrada";
		}

	}
	cout << "Digite el codigo de la segunda Sucursal (101-107): ";
	cin >> sucu2;

	while (ite->isDone()) {
		if (sucu2 == (ite->currenItem()->getNumSuc()))
		{
			sucuAux1 = ite->currenItem();
		}
		else {
			cout << "Sucursal 1 no encontrada";
		}
	}
	 
	(*sucuAux) = *((*sucuAux) + (*sucuAux1));

	cin.get();
}

//----------------------------------------------
void Banco::menuCase9() {

	cout << endl << "--------------(9)Probar operador == --------------" << endl << endl;


	cin.get();
}

inline void Banco::operator[](unsigned int n)
{
	cout << arregloSucu[n].toString();
}




