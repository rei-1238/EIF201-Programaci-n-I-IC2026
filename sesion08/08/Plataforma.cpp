#include "Plataforma.h"
#include<string>
#include <iostream>

namespace EIF201{

	
 Plataforma::Plataforma():cantidad(0),capacidad(8){
	 contenidos = new Contenido * [capacidad];//arreglo donde se van a guardar las direcciones
 }



 void Plataforma::redimensionar() {
	 int nuevaCapacidad = capacidad * 2;//se multiplica por 2 para agrandar el arreglo
	 Contenido** nuevo = new Contenido * [nuevaCapacidad];

	 for (int i = 0; i < capacidad; i++) {
		 nuevo[i] = contenidos[i];
	 }
	 delete[]contenidos;
	 contenidos = nuevo;
	 capacidad = nuevaCapacidad;
 }


 void Plataforma::agregarContenido(Contenido* contenido){
	 if (cantidad == capacidad) {
		 redimensionar();
	 }
	 contenidos[cantidad] = contenido;//guarda el nuevo puntero es la posicion libre
	 cantidad++;
 }

 void Plataforma::mostrarCatalogo()const {
	 for (int i = 0; i < cantidad; i++) {
		 std::cout << contenidos[i]->toString() << "Regalias: " << contenidos[i]->calcularRegalias()
			 << "Popularidad: " << contenidos[i]->getNivelPopularidad() << std::endl;


	 }
 }

 double Plataforma::regaliasTotales()const {
	 double suma = 0.0;
	 for (int i = 0; i < cantidad; i++) {
		 suma += contenidos[i]->calcularRegalias();

	 }
	 return suma;
 }

 Contenido* Plataforma::contenidoMasRentable()const {
	 if (cantidad == 0) {
		 return nullptr;
	 }

	 int posciMayor = 0;
	 for (int i = 0; i < cantidad; i++) {
		 if (contenidos[i]->calcularRegalias() > contenidos[posciMayor]->calcularRegalias()) {
			 posciMayor = i;
		 }
	 }
	 return contenidos[posciMayor];
 }
  

 Contenido* Plataforma::contenidoMasPopular()const {
	 if (cantidad == 0) {
		 return nullptr;
	 }

	 int posciMayor = 0;
	 for (int i = 0; i < cantidad; i++) {
		 if (contenidos[i]->getNivelPopularidad() > contenidos[posciMayor]->getNivelPopularidad()) {
			 posciMayor = i;
		 }
		 return contenidos[posciMayor];
	 }


	 

 }

 int Plataforma::contarPorTipo(const std::string& tipo) const{
	 int contador = 0;

	 for (int i = 0; i < cantidad; i++) {
		 if (contenidos[i]->getTipo() == tipo) {
			 contador++;
		 }
	 }
	 return contador;
 }



 double Plataforma::promedioDeRegaliasPorTipo(const std::string tipo)const {
	 int suma = 0;
	 int contador = 0;

	 for (int i = 0; i < cantidad; i++) {
		 if (contenidos[i]->getTipo() == tipo) {
			 suma += contenidos[i]->calcularRegalias();
			 contador++;
		 }
	 }
		 if (contador == 0) {
			 return 0.0;
		 }
		 return suma/contador;
	 
 }



 Plataforma::~Plataforma() {};
 

 
 

}
