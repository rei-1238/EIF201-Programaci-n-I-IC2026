#ifndef LOTECAFE_H
#define LOTECAFE_H

#include<string>
#include <sstream>

namespace EIF201 {
	class LoteCafe
	{
	protected:
		std::string finca;
		double pesoKg;
		int altitudMsnm;
		double puntajeBaseAltitud()const {
			if (altitudMsnm > 1400) {
				return 88.0;
			}
			else if (altitudMsnm > 1200) {
				return 84.0;
			}
			else if (altitudMsnm > 800) {
				return 80.0;
			}
			else {
				return 75.0;
			}
		}

	public:
		LoteCafe(const std:: string& finca, double pesoKg, int altitudMsnm)
			:finca(finca), pesoKg(pesoKg),altitudMsnm(altitudMsnm){}
		
		virtual ~LoteCafe(){}

		virtual double calcularPuntajeCalidad() const = 0;
		virtual double calcularPrecioPorKg() const = 0;
		virtual std:: string getProceso() const = 0;

		double calcularValorTotal() const {
			return pesoKg * calcularPrecioPorKg();
		}

		virtual std::string toString() const {
			std::ostringstream oss;
			oss << getProceso() << " | Finca: " << finca
				<< " | " << pesoKg << " kg | " << altitudMsnm << " msnm "
				<< " | Calidad: " << calcularPuntajeCalidad()
				<< " | Precio/kg: " << calcularPrecioPorKg()
				<< " | Total: " << calcularValorTotal() << " colones";
			return oss.str();
		}

		std::string getFinca()const { return finca; }
		double getPesoKg() { return pesoKg; }
		int getAltitud()const { return altitudMsnm; }

	};
}
#endif

