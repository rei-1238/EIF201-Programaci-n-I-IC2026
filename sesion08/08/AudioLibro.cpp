#include "AudioLibro.h"

namespace EIF201 {

	AudioLibro::AudioLibro(const std::string nombre, int duracion, int numCapitulos, double precioVenta, int unidadesVendidas)
		:Contenido(nombre,duracion), numCapitulos(numCapitulos), precioVenta(precioVenta),unidadesVendidas(unidadesVendidas){}

	double AudioLibro::calcularRegalias() const
	{
		double tasa = 0.25;
		if (duracion > 36000) {
			tasa = 0.30;
		}
		double regalias = precioVenta * tasa * unidadesVendidas;
		if (unidadesVendidas > 1000) {
			regalias = 0.12;
		}
		if (numCapitulos > 20) {
			regalias = 0.8;
		}
		return regalias;
	}

	std::string AudioLibro::getTipo() const
	{
		return "AudioLibro";
	}

	int AudioLibro::getNivelPopularidad()const {
		if (unidadesVendidas > 100)return 1;
		else if (unidadesVendidas > 500)return 2;
		else if (unidadesVendidas > 1000)return 3;
		else if (unidadesVendidas > 2000)return 4;
		else if (unidadesVendidas > 3000)return 5;
		else if (unidadesVendidas > 4000)return 6;
		else if (unidadesVendidas > 5000)return 7;
		else if (unidadesVendidas > 6000)return 8;
		else if (unidadesVendidas > 7000)return 9;
		else if (unidadesVendidas > 8000)return 10;
		return unidadesVendidas;
	}

	AudioLibro::~AudioLibro()
	{
	}

}
