#ifndef NODOHISTORIAL_H
#define NODOHISTORIAL_H

#include <iostream>
#include <string>
using namespace std;

namespace EIF201 {

	struct NodoHistorial {
		string cancion;
		NodoHistorial* siguiente;
		NodoHistorial* anterior;

		NodoHistorial(const string& c) :cancion(c), siguiente(nullptr), anterior(nullptr) {
			cout << " [Historial creado: " << c << "]" << endl;
		}

		~NodoHistorial() {
			cout << " [Historial destruido: " << cancion << "]" << endl;
		}
	};

	
}
#endif 