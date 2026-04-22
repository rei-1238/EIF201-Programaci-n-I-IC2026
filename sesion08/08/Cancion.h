#ifndef CANCION_H
#define CANCION_H
#include <sstream>
#include <string>
#include "Contenido.h"

namespace EIF201 {
	class Cancion : public Contenido {
	private:
		std::string genero;
		int numRepro;
	public:
		Cancion(const std::string& nombre, int duracion, std::string genero, int numRepro);

		virtual ~Cancion();

		double calcularRegalias()const override;
		std::string getTipo()const override;
		int getNivelPopularidad()const override;
		



	};

}

#endif

