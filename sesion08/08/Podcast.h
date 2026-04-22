#ifndef PODCAST_H
#define  PODCAST_H
#include <sstream>
#include <string>
#include "Contenido.h"

namespace EIF201 {

	class Podcast : public Contenido {
	private:
		int numEpisodios;
		bool patrocinio;
		double oyentes;

	public:
		Podcast(const std::string& nombre, int duracion, int numEpisodios, bool patrocinio, double oyentes);
		virtual ~Podcast();

		double calcularRegalias()const override;
		std::string getTipo()const override;
		int getNivelPopularidad()const override;

	};




}









#endif