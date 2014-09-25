//============================================================================
// Name        : Ejercicio1.cpp
// Author      : Raúl Franco
// Version     : 1.0
// Copyright   : -
// Description : Crear registros de alumnos y busca alumno
//============================================================================

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

struct mialumno
{
int clase; //número de registro donde se almacena
char apellido[25];//apellidos del alumno
float nota1;//nota primera evaluación
float nota2;//nota segunda evaluación
float nota3;//nota tercera evaluación
};


int main() {
	mialumno alumno;
	string apellidos [5] = {"Fernandez", "Gomez", "García", "Rojo", "Azul"};
	string ap;
	int registro = 0, numreg;

	// --- PARTE 1: Generación de 100 alumnos y guardar los datos en un archivo ---

	//Abrir un stream de salida para añadir registros
	ofstream fsalida("c:\\datos\\alumnos.dat", ios::out | ios::binary);
	srand (time(NULL));

	for (int i = 0; i < 100; i++) {

		registro = registro + 1;

		alumno.clase = registro;
		strcpy(alumno.apellido, apellidos[rand() % 5].c_str());
		alumno.nota1 = rand() % 11;
		alumno.nota2 = rand() % 11;
		alumno.nota3 = rand() % 11;

		//Escribe en el fichero
		fsalida.write(reinterpret_cast<char*>(&alumno), sizeof(mialumno));
	}

	fsalida.close();

	// --- PARTE 2: Búsqueda de alumno por registro y muestra por pantalla ---

	cout << "Introduce el número de registro del alumno" << endl;
	cin >> numreg;

	//Abrir un stream de entrada para leer el fichero
	ifstream fentrada("c:\\datos\\alumnos.dat", ios::in | ios::binary);

	//Se posiciona en el número de registro introducido por teclado
	fentrada.seekg((numreg-1)*sizeof(mialumno), ios::beg);

	//Lee el archivo y muestra por pantalla los datos del registro indicado
	fentrada.read(reinterpret_cast<char*>(&alumno), sizeof(mialumno));
	cout << alumno.clase << " " << alumno.apellido << " " << alumno.nota1 << " " << alumno.nota2 << " " << alumno.nota3 << endl;
	cout << "------------------------------" << endl;

	//Se posiciona el puntero al inicio del archivo para mostrar el contenido completo del mismo
	fentrada.seekg(0*sizeof(mialumno), ios::beg);
	fentrada.read(reinterpret_cast<char*>(&alumno), sizeof(mialumno));

	while (!fentrada.eof()) {
		cout << alumno.clase << " " << alumno.apellido << " " << alumno.nota1 << " " << alumno.nota2 << " " << alumno.nota3 << endl;
		fentrada.read(reinterpret_cast<char*>(&alumno), sizeof(mialumno));
	}

	fentrada.close();
	return 0;
}
