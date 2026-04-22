#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include<string>

#include "Contenido.h"


namespace EIF201{
	class Plataforma {
	private:
		Contenido** contenidos;
		int cantidad;
		int capacidad;

		void redimensionar();
	public:
		Plataforma();

		~Plataforma();

		void agregarContenido(Contenido* contenido);
		void mostrarCatalogo()const;
		double regaliasTotales() const;
		Contenido* contenidoMasRentable()const;
		Contenido* contenidoMasPopular()const;
		int contarPorTipo(const std::string& tipo)const;
		double promedioDeRegaliasPorTipo(const std:: string tipo) const;



		

	};




}





#endif