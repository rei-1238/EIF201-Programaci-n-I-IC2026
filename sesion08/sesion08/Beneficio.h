#ifndef BENEFICIO_H
#define BENEFICIO_H
#include "LoteCafe.h"


namespace EIF201 {
	class Beneficio {
	private:
		LoteCafe** lotes;
		int capacidad;
		int cantidad;

		void redimensionar();
	public:
		Beneficio();
		void agregarLote(LoteCafe* lote);
		void mostrarInventario()const;
		double valorTotalInventario()const;
		LoteCafe* loteMayorCalidad()const;
		double promedioCalidadPorProceso(const std::string& proceso)const;
		int contadorPorProceso(const std::string& proceso)const;
		~Beneficio();
	};



}

#endif