#include "Beneficio.h"

#include<string>
#include <iostream>

namespace EIF201 {
	Beneficio::Beneficio() :cantidad(0), capacidad(5) {
		lotes = new LoteCafe * [capacidad];// aqui se guardan las direcciones
	}

	void Beneficio::redimensionar() {
		int nuevaCapacidad = capacidad * 2;
		LoteCafe** nuevo = new LoteCafe * [nuevaCapacidad];

		for (int i = 0; i < capacidad; i++) {
			nuevo[i] = lotes[i];
		}
		delete[]lotes;
		lotes = nuevo;
		capacidad = nuevaCapacidad;
	}

	void Beneficio::agregarLote(LoteCafe* lote) {
		if (cantidad == capacidad) {
			redimensionar();
		}
		lotes[cantidad] = lote;
		cantidad++;
	}

	void Beneficio::mostrarInventario()const {
		for (int i = 0; i < capacidad; i++) {
			std::cout << lotes[i]->toString() << " Calidad : " << lotes[i]->calcularPuntajeCalidad()
				<< " Precio por Kg: " << lotes[i]->calcularPrecioPorKg() << " Proceso: " << lotes[i]->getProceso();
		}
	}
	 
	double Beneficio::valorTotalInventario()const {
		double suma = 0.0;
		for (int i = 0; i < capacidad; i++) {
			suma += lotes[i]->calcularValorTotal();
		}
		return suma;
	}

	LoteCafe* Beneficio::loteMayorCalidad()const {
		if (cantidad == 0) {
			return nullptr;
		}

		int posMayor = 0;
		for (int i = 0; i < capacidad; i++) {
			if (lotes[i]->calcularPuntajeCalidad() > lotes[posMayor]->calcularPuntajeCalidad()) {
				posMayor = i;
			}
		}
		return lotes[posMayor];
	}

	double Beneficio::promedioCalidadPorProceso(const std::string& proceso)const {
		int suma = 0;
		int contador = 0;
		for (int i = 0; i < capacidad; i++) {
			if (lotes[i]->getProceso() == proceso) {
				suma += lotes[i]->calcularPuntajeCalidad();
				contador++;
			}
		}

		if (contador == 0) {
			return 0.0;
		}
		return suma / contador;
	}

	int Beneficio::contadorPorProceso(const std::string& proceso)const {
		int contador = 0;
		for (int i = 0; i < capacidad; i++) {
			if (lotes[i]->getProceso() == proceso) {
				contador++;
			}
		}
		return contador;
	}

	Beneficio::~Beneficio(){}



}