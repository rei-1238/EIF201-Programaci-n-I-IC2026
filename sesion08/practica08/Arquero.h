#ifndef ARQUERO_H
#define ARQUERO_H
#include<sstream>
#include <iostream>

#include "Criatura.h"

namespace EIF201 {
	class Arquero : public Criatura{
	private:
		double destreza;
		int flechas;
		int flechalMax;

	public:
		Arquero(const std::string& nombre, int nivel, double puntosVida, double destreza, int flechas);

		~Arquero() override;

		double calcularAtaque()override;
		std::string getTipo()const override;
		bool puedeAtacar()const override;
		std::string toString() const override;

		int getFlechas() const;


			
	};


}



























#endif // !ARQUERO_H


