//============================================================================
// Name        : Ejercicio2.cpp
// Author      : Raúl Franco
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct mialumno {
	int clase; //número de registro donde se almacena
	char apellido[25];//apellidos del alumno
	float nota1;//nota primera evaluación
	float nota2;//nota segunda evaluación
	float nota3;//nota tercera evaluación
};


int main() {
	float media;
	int registro;
	mialumno alumno;

	map<float, int, less<float> > m;
	map<float, int, less<float> >::iterator inicio;

	ifstream fentrada("c:\\datos\\alumnos.dat", ios::in | ios::binary);

	for (int i = 0; i < 100; i++) {
		fentrada.read(reinterpret_cast<char*>(&alumno), sizeof(mialumno));
		media = (alumno.nota1 + alumno.nota2 + alumno.nota3) / 3;
		registro = alumno.clase;
		m.insert(pair<float, int>(media, registro));
	}

	for (inicio = m.begin(); inicio != m.end(); inicio++) {
		fentrada.seekg(((*inicio).second-1)*sizeof(mialumno), ios::beg);
		fentrada.read(reinterpret_cast<char*>(&alumno), sizeof(mialumno));
		cout << alumno.clase << " " << alumno.apellido << " " << alumno.nota1 << " " << alumno.nota2 << " " << alumno.nota3 << " Media: " << (*inicio).first << endl;

	}
	fentrada.close();

	return 0;
}
