#include "Arquero.h"
#include <sstream>

namespace EIF201 {


   Arquero::Arquero( const std:: string& nombre, int nivel, double puntosVida, double destreza, int flechas): 
	   Criatura(nombre,nivel,puntosVida), destreza(destreza),flechas(flechas){}

   Arquero:: ~Arquero(){}

   double Arquero::calcularAtaque() {
	   double ataqueBase;

	   if (flechas > 0) {
		   ataqueBase = destreza * 1.5 * (1.0 + nivel + 0.1);

		   if (flechas > (flechalMax / 2)) {
			   ataqueBase *= 1.2;
		   }

		   flechas--;
	   }
	   else {
		   ataqueBase = destreza * 0.3;
	   }
	   return ataqueBase;
   }

   std::string Arquero::getTipo()const {
	   return"ARQUERO MAG";
   }








  

}