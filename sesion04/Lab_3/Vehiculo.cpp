#include "Vehiculo.h"

namespace UNA {

	Vehiculo::Vehiculo(std::string placa, std::string marca, int anio, double kilometraje)
		: placa(placa), marca(marca), anio(anio), kilometraje(kilometraje), activo(true) {
	}

	std::string Vehiculo::getPlaca() const {
		return placa;
	}

	std::string Vehiculo::getMarca() const {
		return marca;
	}

	int Vehiculo::getAnio() const {
		return anio;
	}

	double Vehiculo::getKilometraje() const {
		return kilometraje;
	}

	bool Vehiculo::getActivo() const {
		return activo;
	}

	void Vehiculo::registrarKilometros(double km) {
		if (!activo) {
			std::cout << "Error: el vehiculo esta fuera de servicio" << std::endl;
			return;
		}

		if (km <= 0) {
			std::cout << "Error: los kilometros deben ser positivos" << std::endl;
			return;
		}

		kilometraje += km;
		std::cout << "Kilometros registrados correctamente" << std::endl;
	}

	void Vehiculo::desactivar() {
		if (!activo) {
			std::cout << "El vehiculo ya esta fuera de servicio" << std::endl;
			return;
		}

		activo = false;
		std::cout << "Vehiculo desactivado" << std::endl;
	}

	void Vehiculo::reactivar() {
		if (activo) {
			std::cout << "El vehiculo ya esta activo" << std::endl;
			return;
		}

		activo = true;
		std::cout << "Vehiculo reactivado" << std::endl;
	}

	void Vehiculo::mostrar() const {
		std::cout << "Placa: " << placa << std::endl;
		std::cout << "Marca: " << marca << std::endl;
		std::cout << "Anio: " << anio << std::endl;
		std::cout << "Kilometraje: " << kilometraje << std::endl;
		std::cout << "Estado: " << (activo ? "ACTIVO" : "FUERA DE SERVICIO") << std::endl;
		std::cout << "-----------------------------" << std::endl;
	}

}
