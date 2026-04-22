#ifndef LOTELAVADO_H
#define LOTELAVADO_H

#include "LoteCafe.h"
#include <string>
#include <sstream>

namespace EIF201 {
	class LoteLavado : public LoteCafe {
	private:

		double horasFermentacion;
	public:
		LoteLavado(const std::string& finca, double pesoKg, int altitudMsnm, double horasFermentacion);

		double calcularPuntajeCalidad() const override;
		double calcularPrecioPorKg() const override;
		std::string getProceso() const override;
		
		~LoteLavado();
		

	
	};
}
#endif
