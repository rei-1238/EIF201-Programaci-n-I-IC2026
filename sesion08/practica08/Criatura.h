#ifndef CRIATURA_H
#define CRIATURA_H
#include<sstream>
#include <iostream>


namespace EIF201 {

	class Criatura {
	protected:
		std::string nombre;
		int nivel;
		double puntosVida;
		double puntosVidaMax;

	public:
		Criatura(const std::string nombre, int nivel, double puntosVida) : nombre(nombre), nivel(nivel), puntosVida(puntosVida), puntosVidaMax(puntosVidaMax) {}

		virtual~Criatura() {}

		//METODOS VITUAL
		virtual double calcularAtaque() = 0;
		virtual std::string getTipo() const = 0;
		virtual bool puedeAtacar()const = 0;

		virtual std::string toString() const {
			std::ostringstream oss;
			oss << getTipo() << " | " << nombre << " | " << " Nv. " << nivel << " | " << " Hp " << puntosVida << " / " << puntosVidaMax;
			return oss.str();

		}

		void recibirDanno(double danno) {
			if (danno > 0) {
				puntosVida -= danno; //puntosVida = puntosVida - danno
				if (puntosVida < 0) {
					puntosVida = 0;
				}
			}
		}

		bool estaVivo() const { return puntosVida > 0; }

		//GETTERS
		std::string getNombre()const { return nombre; }
		int getNivel()const { return nivel; }
		double  getPuntosVida()const { return puntosVida; }
		double getPuntosVidaMax()const { return puntosVidaMax; }



	};

}


#endif 
