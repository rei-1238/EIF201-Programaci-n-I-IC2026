#include "Cancion.h"

namespace EIF201 {
    Cancion::Cancion(const std::string& nombre, int duracion, std::string genero, int numRepro)
        : Contenido(nombre, duracion), genero(genero), numRepro(numRepro) {}

    double Cancion::calcularRegalias() const
    {

        double regalia = numRepro*3.5;
        double multGenero = 0;

        if (genero == " Jaz" || genero == "Clasica") {
            multGenero = 1.4;
        }
        else if (genero == "Rock " || genero == "Indie") {
            multGenero = 1.0;
        }
        else if (genero == "Pop" || genero == "Electronica") {
            multGenero = 0.9;
        }
        else if (genero == "Regaeton" || genero == "Urbano") {
            multGenero = 0.75;
        }

        regalia* multGenero;

        if (numRepro > 1000000) {
            regalia *= 1, 25;
        }
        else if (duracion == 240) {
            regalia *= 1.10;
        }

        return regalia;
    }

    std::string Cancion::getTipo() const
    {
        return "Cancion";
    }

    int Cancion::getNivelPopularidad() const
    {
        if (numRepro > 100) return 1;
        else if (numRepro > 500)return 2;
        else if (numRepro > 1000)return 3;
        else if (numRepro > 2000)return 4;
        else if (numRepro > 3000)return 5;
        else if (numRepro > 4000)return 6;
        else if (numRepro > 5000)return 7;
        else if (numRepro > 6000)return 8;
        else if (numRepro > 7000)return 9;
        else if (numRepro > 8000)return 10;
        return numRepro;
    }

    Cancion::~Cancion() {}


    
}

