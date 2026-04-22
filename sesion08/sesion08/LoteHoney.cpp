#include "LoteHoney.h"
#include<string>
#include <sstream>

namespace EIF201 {
	
   LoteHoney::LoteHoney(const std::string& finca, double pesoKg, int altitudMsnm, double porcentajeMucilago)
	   :LoteCafe(finca,pesoKg,altitudMsnm), porcentajeMucilago(porcentajeMucilago){}

   double LoteHoney::calcularPuntajeCalidad() const {
	   double puntaje = puntajeBaseAltitud();

	   puntaje += porcentajeMucilago * 0.08;
	   if (altitudMsnm > 1200 && porcentajeMucilago > 60) {
		   puntaje += 2.5;
	   }
	   return puntaje; 
   }

   double LoteHoney::calcularPrecioPorKg()const {
	   double precioBase = 3200;
	   if (porcentajeMucilago >= 75) {
		   precioBase += 1.15;
	   }

	   return precioBase;
   }

   std::string LoteHoney::getProceso()const {
	   if (porcentajeMucilago < 25) {
		   return "White";
	   }
	   else if (porcentajeMucilago < 50) {
		   return "Yellow";
	   }
	   else if (porcentajeMucilago < 75) {
		   return "Red";
	   }
	   else if (porcentajeMucilago < 100) {
		   return "Black";
	   }

   }

   LoteHoney::~LoteHoney(){}

}