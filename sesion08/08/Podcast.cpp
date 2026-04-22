#include "Podcast.h"
namespace EIF201 {
	Podcast::Podcast(const std::string& nombre, int duracion, int numEpisodios, bool patrocinio, double oyentes)
		:Contenido(nombre, duracion),numEpisodios(numEpisodios),patrocinio(patrocinio), oyentes(oyentes){}

	



	Podcast::~Podcast(){}

	double Podcast::calcularRegalias() const
	{
		double regalias = numEpisodios * 1500 * (oyentes / 1000);
		if (patrocinio) {
			regalias *= 1.45;
		}
		if (numEpisodios > 50) {
			regalias *= 1.18;
		}
		if (duracion < 900) {
			regalias *= 0.80;
		}

		return regalias;
	}

	std::string Podcast::getTipo() const
	{
		if (numEpisodios > 50)return " Podcast veterano";
		else return "Podcast";
	}

	int Podcast::getNivelPopularidad() const
	{
		if ( oyentes > 100) return 0.1;
		else if (oyentes > 500)return 0.2;
		else if (oyentes > 1000)return 0.3;
		else if (oyentes > 2000)return 0.4;
		else if (oyentes > 3000)return 0.5;
		else if (oyentes > 4000)return 0.6;
		else if (oyentes > 5000)return 0.7;
		else if (oyentes > 6000)return 0.8;
		else if (oyentes > 7000)return 0.9;
		else if (oyentes > 8000)return 0.10;
		return oyentes;
	}

 }
