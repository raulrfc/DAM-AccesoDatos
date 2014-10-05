bool existeDNI(char dni[10]) {
	ficha persona;
	bool existe = false;

	ifstream ficheroL("c:\\datos\\fichero.dat", ios::in | ios::binary);
	ficheroL.read(reinterpret_cast<char*>(&persona), sizeof(ficha));

	while (!ficheroL.eof()) {
		ficheroL.read(reinterpret_cast<char*>(&persona), sizeof(ficha));
		cout << "Compara"  << strcmp(persona.dni,dni) << endl;

		if (strcmp(persona.dni, dni) == 0) {
			existe = true;
			return existe;
		}
	}
	return existe;
}

int buscarDNI(char dni[]) {
	int posicion;
	ficha persona;

	ifstream lectura("c:\\datos\\fichero.dat", ios::in | ios::binary);
	lectura.read(reinterpret_cast<char*>(&persona), sizeof(ficha));

	for (int i = 0; i < lectura.end; i++){
		if (strcmp(persona.dni, dni) == 0) {
			posicion = i;
		}
	}
	lectura.close();

	return posicion;
}


ficha pedirDatos() {
	ficha persona;

	cout << "Introduce DNI" << endl;
	cin >> persona.dni;
	if(!existeDNI(persona.dni)) {
		cout << "Introduce nombre" << endl;
		cin >> persona.nombre;
		cout << "Introduce apellido" << endl;
		cin >> persona.apellidos;
	} else {
		pedirDatos();
	}

	return persona;
}

void crearFicheroIndice(){
	ofstream indicesE("c:\\datos\\indices.txt", ios::out);
	indicesE << "0" << endl;
	indicesE << "0" << endl;
	indicesE.close();
}

indice leerAltasBajas() {
	indice registro;
	ifstream indicesL("c:\\datos\\indices.txt", ios::in);

	if (!indicesL.is_open()) { // Si el fichero no puede abrirse se crea uno nuevo asignandole los valores por defecto
		crearFicheroIndice();
		registro.bajas = 0;
		registro.altas = 0;
	} else {//Si el fichero ya existe se leen los datos del mismo y se cargan en "registro"
		while (!indicesL.eof()) {
			indicesL >> registro.altas;
			indicesL >> registro.bajas;
		}
		indicesL.close();
	}

	return registro;
}

void escribirAlta(indice i, ficha f) {
	//Apertura del fichero indices para escritura, se escriben los datos de "registro" en el fichero
	ofstream indicesE("c:\\datos\\indices.txt", ios::out);
	indicesE << i.altas << endl;
	indicesE << i.bajas << endl;
	indicesE.close();

	//Apertura del fichero para escribir los datos de la ficha
	ofstream ficheroE("c:\\datos\\fichero.dat", ios::out | ios::binary | ios::app);
	ficheroE.write(reinterpret_cast<char*>(&f), sizeof(ficha));
	ficheroE.close();
}

void Alta() {

	ficha persona;
	indice registro;

	//Se piden los datos para el alta
	persona = pedirDatos();

	//Apertura del fichero indices para lectura
	registro = leerAltasBajas();


	if (registro.bajas == 0) {//Si no hay bajas se inserta el alta en la siguiente posición libre del fichero
		registro.altas++;
		escribirAlta(registro, persona);
	} else {

	}

	cout << registro.altas;
	cout << registro.bajas;

}

void Baja() {
	char dni [10];
	int posicion;

	cout << "Introduce DNI" << endl;
	cin >> dni;

	if (existeDNI(dni)) {
		posicion = buscarDNI(dni);
		cout << "posicion" << posicion << endl;
	} else {
		cout << "El DNI introducido no existe" << endl;
	}

}

















