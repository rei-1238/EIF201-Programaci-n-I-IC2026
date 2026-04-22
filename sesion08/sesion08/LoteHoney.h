#ifndef LOTEHONEY_H
#define LOTEHONEY_H
#include "LoteCafe.h"
#include <string>
#include <sstream>

namespace EIF201 {
	class LoteHoney : public LoteCafe {
	private: 
		double porcentajeMucilago;
	public:
		LoteHoney(const std::string& finca, double pesoKg, int altitudMsnm, double porcentajeMucilago);

		double calcularPuntajeCalidad() const override;
		double calcularPrecioPorKg()const override;
		std::string getProceso()const override;
		
		~LoteHoney();

			
	};



}


#endif