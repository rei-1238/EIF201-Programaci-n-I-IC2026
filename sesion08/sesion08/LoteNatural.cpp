#include "LoteNatural.h"

namespace EIF201{
	LoteNatural::LoteNatural(const std::string& finca, double pesoKg, int altitudMsnm, int diasDeSecado, double humedadFinal)
		: LoteCafe(finca, pesoKg, altitudMsnm), diasDeSecado(diasDeSecado), humedadFinal(humedadFinal){}

	double LoteNatural::calcularPuntajeCalidad()const {
		double puntaje = puntajeBaseAltitud();

		if (diasDeSecado >= 18 && diasDeSecado <= 25) {
			puntaje += 5.0;
		}
		else if (diasDeSecado < 18) {
			puntaje -= 6.0;
		}
		else {
			puntaje -= (diasDeSecado - 25) * 0.8;
		}

		//humedad
		if (humedadFinal >=10 && humedadFinal <= 12) {
			puntaje += 3.0;
		}
		else if (humedadFinal < 10) {
			puntaje -= (10 - humedadFinal);
		}
		else {
			puntaje -= (12 - humedadFinal);
		}

		return puntaje;
	}

	double LoteNatural::calcularPrecioPorKg()const {
		double precioBase = 3600.0;
		if (calcularPuntajeCalidad()>90) {
			precioBase += 1.20;
		}
		return precioBase;
	}
	
	std::string LoteNatural::getProceso()const {
		return "Natural";
	}


	LoteNatural::~LoteNatural(){}

}