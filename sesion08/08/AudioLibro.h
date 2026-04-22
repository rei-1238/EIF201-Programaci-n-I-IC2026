#ifndef AUDIOLIBRO_H
#define AUDIOLIBRO_H
#include <sstream>
#include <string>
#include "Contenido.h"

namespace EIF201 {

	class AudioLibro : public Contenido {
	private:
		int numCapitulos;
		double precioVenta;
		int unidadesVendidas;
	public:
		AudioLibro(const std::string nombre, int duracion, int numCapitulos, double precioVenta, int unidadesVendidas);

		double calcularRegalias()const override;
		std::string getTipo()const override;
		int getNivelPopularidad()const override;
		 
		virtual ~AudioLibro();





	};



}




#endif

