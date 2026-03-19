#include "Inventario.h"
#include<iomanip>

namespace EIF201 {
	//constructor
	Inventario::Inventario(int cantidadInicial) : cantidad(0), capacidad(cantidadInicial) {
		productos = new producto * [cantidadInicial];
		for (int i = 0; i < capacidad; i++)
		{
			productos[i] = nullptr;
		}

	}

	Inventario::~Inventario() {
		for (int i = 0; i < cantidad; i++) {
			delete productos[i];
			productos[i] = nullptr;
		}
		delete[]productos;
		productos = nullptr;
		std::cout << "inventario destruido";

	}
	void Inventario::redimencionar() {
		int nuevaCapacidad = capacidad * 2;

		producto** nuevoArreglo = new producto * [nuevaCapacidad];

		for (int i = 0; i < cantidad; i++)
		{
			nuevoArreglo[i] = productos[i];
		}

		for (int i = cantidad; i < nuevaCapacidad; i++)
		{
			nuevoArreglo[i] = nullptr;
		}
		delete[]productos;
		productos = nuevoArreglo;
		capacidad = nuevaCapacidad;
	}

	void Inventario::agregar(producto* nuevo) {
		if (nuevo == nullptr) {
			std::cout << "Error ";
			return;
		}
		if (cantidad == capacidad) {
			redimencionar();
		}

		productos[cantidad] = nuevo;
		cantidad++;
	}

	void Inventario::mostrarTodos()const {
		if (cantidad == 0) {
			std::cout << "Error, no data" << std::endl;
			return;
		}

		std::cout << "-----------INVENTARIO----------" << std::endl;
		for (int i = 0; i < cantidad; i++) {
			productos[i]->mostrar();
		}
		std::cout << "-------------------------------" << std::endl;
	}
	//buscar por codigo
	producto* Inventario::buscarPorCodigo(std::string codigo)const {
		for (int i = 0; i < cantidad; i++) {
			if (productos[i]->getCodigo() == codigo) {
				return productos[i];
			}
		}
		return nullptr;
	}

	bool Inventario::eliminar(std::string codigo) {
		int posicion = -1;
		for (int i = 0; i < cantidad; i++)
		{
			if (productos[i]->getCodigo() == codigo) {
				posicion = i;
				break;
			}
		}
		if (posicion == -1) {
			std::cout << "Producto no encontrado" << std::endl;
			return false;
		}
		std::string nombreProducto = productos[posicion]->getNombre();
		delete productos[posicion];

		for (int i = posicion; i < cantidad; i++) {
			productos[i] = productos[i + 1];
		}

		productos[cantidad - 1] = nullptr;
		cantidad--;//cantidad= cantidad-1

		std::cout << "Producto " << nombreProducto << "elinimado de inventario";
		return true;
	}
	//total




	//
	int Inventario::getCantidad()const {
		return cantidad;
	}
	int Inventario::getCapacidad()const {
		return capacidad;
	}

}