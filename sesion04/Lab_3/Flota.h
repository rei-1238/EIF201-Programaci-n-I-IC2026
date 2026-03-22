#ifndef FLOTA_H
#define FLOTA_H

#include <iostream>
#include <string>
#include "Vehiculo.h"

namespace UNA {

	class Flota {
	private:
		Vehiculo** lista;
		int cantidad;
		int capacidad;

		void redimensionar();

	public:
		Flota();
		~Flota();

		void agregar(Vehiculo* nuevo);
		Vehiculo* buscarPorPlaca(std::string placa) const;
		void mostrarPorMarca(std::string marca) const;
		bool eliminar(std::string placa);
		int contarActivos() const;
		void mostrarTodos() const;

		int getCantidad() const;
		int getCapacidad() const;
	};

}

#endif