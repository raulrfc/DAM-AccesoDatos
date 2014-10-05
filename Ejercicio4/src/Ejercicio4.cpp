//============================================================================
// Name        : Ejercicio4.cpp
// Author      : 
// Version     : 0.1
// Copyright   : Your copyright notice
// Description : Altas,Bajas,listado de un fichero
//============================================================================

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

struct ficha {
	char dni[10];
	char nombre[25];
	char apellidos[25];
};

struct indice {
	int altas;
	int bajas;
};

#include "auxiliar.h"

int main() {
	int opcion;

	do {
		cout << "Menú" << endl;
		cout << "1. Alta" << endl;
		cout << "2. Baja" << endl;
		cout << "3. Listado" << endl;
		cout << "4. Salir" << endl;
		cin >> opcion;

		switch (opcion){

		case 1:
			Alta();
			break;
		case 2:
			Baja();
			break;
		case 3:

			break;
		case 4:
			break;
		}
	} while (opcion > 0 && opcion < 4);


	return 0;
}
