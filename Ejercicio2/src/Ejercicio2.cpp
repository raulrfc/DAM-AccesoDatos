//============================================================================
// Name        : Ejercicio2.cpp
// Author      : Raúl Franco
// Version     : 1.2
// Copyright   : Your copyright notice
// Description : Carga los datos de un archivo y los ordena de mayor a menor
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

	//Se crea un multimapa para poder almacenar las notas medias ordenadas
	multimap<float, int, less<float> > m;
	//Iterador inverso para poder mostrar los resultados del mapa ordenados de mayor a menor
	multimap<float, int, less<float> >::reverse_iterator inicio;


	//Apertura y lectura del archivo
	ifstream fentrada("c:\\datos\\alumnos.dat", ios::in | ios::binary);
	fentrada.read(reinterpret_cast<char*>(&alumno), sizeof(mialumno));

	//Se posiciona con cada iteración, lee y guarda los datos en el mapa
	for (int i = 0; i < 100; i++){
		fentrada.seekg(i*sizeof(mialumno), ios::beg);
		fentrada.read(reinterpret_cast<char*>(&alumno), sizeof(mialumno));
		media = (alumno.nota1 + alumno.nota2 + alumno.nota3) / 3;
		registro = alumno.clase;
		m.insert(pair<float, int>(media, registro));
	}

	//Bucle para mostrar los datos del mapa de mayor a menor
	for (inicio = m.rbegin(); inicio != m.rend(); inicio++) {
		fentrada.seekg(((*inicio).second-1)*sizeof(mialumno), ios::beg);
		fentrada.read(reinterpret_cast<char*>(&alumno), sizeof(mialumno));
		cout << alumno.clase << " " << alumno.apellido << " " << alumno.nota1 << " " << alumno.nota2 << " " << alumno.nota3 << " Media: " << (*inicio).first << endl;
	}

	fentrada.close();

	return 0;
}
