#ifndef LOTENATURAL_H
#define LOTENATURAL_H
#include "LoteCafe.h"
#include<string>

namespace EIF201 {
	class LoteNatural : public LoteCafe {
	private:
		int diasDeSecado;
		double humedadFinal;
	public:
		LoteNatural(const std::string& finca, double pesoKg, int altitudMsnm, int diasDeSecado, double humedadFinal);

		double calcularPuntajeCalidad() const override;
		double calcularPrecioPorKg()const override;
		std::string getProceso()const override;
		~LoteNatural();
	};






}






#endif