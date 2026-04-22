#ifndef CONTENIDO_H
#define  CONTENIDO_H
#include <sstream>
#include <string>

namespace EIF201 {
	class Contenido {
	protected:
		std::string nombre;
		int duracion;
	public:
		Contenido(const std::string& nombre, int duracion) :nombre(nombre), duracion(duracion) {}

		virtual ~Contenido() {}

		virtual double calcularRegalias()const = 0;
		virtual std::string getTipo()const = 0;
		virtual int getNivelPopularidad()const = 0;

		virtual std::string toString() const {
			 std::ostringstream oss;
			 oss << " | Tipo: " << getTipo() << " | Nombre: " << nombre << " | Duracion: " << duracion << "segundos";
			 return oss.str();


		}
		//GETTERS
		std::string getNombre()const { return nombre; }
		int getDuracion()const { return duracion; }
	};






}


#endif // !CONTENIDO_H
