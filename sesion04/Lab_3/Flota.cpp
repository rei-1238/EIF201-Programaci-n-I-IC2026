#include "Flota.h"



namespace UNA {

	Flota::Flota() : cantidad(0), capacidad(3) {
		lista = new Vehiculo * [capacidad];
		for (int i = 0; i < capacidad; i++) {
			lista[i] = nullptr;
		}
	}

	Flota::~Flota() {
		for (int i = 0; i < cantidad; i++) {
			delete lista[i];
			lista[i] = nullptr;
		}
		delete[] lista;
		lista = nullptr;
		std::cout << "Flota destruida" << std::endl;
	}

	void Flota::redimensionar() {
		int nuevaCapacidad = capacidad * 2;

		Vehiculo** nuevoArreglo = new Vehiculo * [nuevaCapacidad];

		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = lista[i];
		}

		for (int i = cantidad; i < nuevaCapacidad; i++) {
			nuevoArreglo[i] = nullptr;
		}

		delete[] lista;
		lista = nuevoArreglo;
		capacidad = nuevaCapacidad;
	}

	void Flota::agregar(Vehiculo* nuevo) {
		if (nuevo == nullptr) {
			std::cout << "Error: vehiculo nulo" << std::endl;
			return;
		}

		if (cantidad == capacidad) {
			redimensionar();
		}

		lista[cantidad] = nuevo;
		cantidad++;
		std::cout << "Vehiculo agregado correctamente" << std::endl;
	}

	Vehiculo* Flota::buscarPorPlaca(std::string placa) const {
		for (int i = 0; i < cantidad; i++) {
			if (lista[i]->getPlaca() == placa) {
				return lista[i];
			}
		}
		return nullptr;
	}

	void Flota::mostrarPorMarca(std::string marca) const {
		int encontrados = 0;

		for (int i = 0; i < cantidad; i++) {
			if (lista[i]->getMarca() == marca) {
				lista[i]->mostrar();
				encontrados++;
			}
		}

		if (encontrados == 0) {
			std::cout << "No hay vehiculos de esa marca" << std::endl;
		}
		else {
			std::cout << "Se encontraron " << encontrados << " vehiculo(s) de esa marca" << std::endl;
		}
	}

	bool Flota::eliminar(std::string placa) {
		int posicion = -1;

		for (int i = 0; i < cantidad; i++) {
			if (lista[i]->getPlaca() == placa) {
				posicion = i;
				break;
			}
		}

		if (posicion == -1) {
			std::cout << "Vehiculo no encontrado" << std::endl;
			return false;
		}

		if (lista[posicion]->getActivo()) {
			std::cout << "Primero debe desactivarse antes de poder eliminarlo" << std::endl;
			return false;
		}

		delete lista[posicion];
		lista[posicion] = nullptr;

		for (int i = posicion; i < cantidad - 1; i++) {
			lista[i] = lista[i + 1];
		}

		lista[cantidad - 1] = nullptr;
		cantidad--;

		std::cout << "Vehiculo eliminado correctamente" << std::endl;
		return true;
	}

	int Flota::contarActivos() const {
		int total = 0;

		for (int i = 0; i < cantidad; i++) {
			if (lista[i]->getActivo()) {
				total++;
			}
		}

		return total;
	}

	void Flota::mostrarTodos() const {
		if (cantidad == 0) {
			std::cout << "No hay vehiculos registrados" << std::endl;
			return;
		}

		std::cout << "--------- FLOTA ---------" << std::endl;
		for (int i = 0; i < cantidad; i++) {
			lista[i]->mostrar();
		}
		std::cout << "-------------------------" << std::endl;
	}

	int Flota::getCantidad() const {
		return cantidad;
	}

	int Flota::getCapacidad() const {
		return capacidad;
	}

}
