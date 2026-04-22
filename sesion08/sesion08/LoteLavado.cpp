#include "LoteLavado.h"
#include <string>
#include<sstream>
 

namespace EIF201 {

	LoteLavado::LoteLavado(const std::string& finca, double pesoKg, int altitudMsnm, double horasFermentacion)
		: LoteCafe(finca, pesoKg, altitudMsnm), horasFermentacion(horasFermentacion) {}

	double LoteLavado::calcularPuntajeCalidad() const{
		double puntaje = puntajeBaseAltitud();
		 
		if (horasFermentacion >= 18 && horasFermentacion <= 36) {
			puntaje += 3.0;
		}
		else if (horasFermentacion < 18) {
			puntaje -= 4.0;
		}
		else if (horasFermentacion < 36) {
			double exceso = horasFermentacion - 36;
			int bloques12h = static_cast<int>(exceso / 12.0); //static_cast es para pasar un valor tipo double a int
			puntaje -= bloques12h * 2.0;
			}
		return puntaje;
		
	}

	double LoteLavado::calcularPrecioPorKg() const
	{
		double precioBase = 2800.0;
		return precioBase + calcularPuntajeCalidad() * 10.0;
	}

	std::string LoteLavado::getProceso() const{
		return "Lavado";
	}

	LoteLavado::~LoteLavado()
	{
	}

	




}