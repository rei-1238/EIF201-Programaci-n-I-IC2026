#ifndef HISTORIALDOBLE_H
#define HISTORIALDOBLE_H

#include "NodoHistorial.h"

namespace EIF201 {
	class HistorialDoble{
	private:
		NodoHistorial* cabeza;//primer nodo de la lista
		NodoHistorial* cola;//ultimo nodo de la lista
		int cantidad;//cantidad de nodos actuales
	public:
		//constructor y destructor
		HistorialDoble();
		
		~HistorialDoble();

		//inserción
		//agregar una cancion al inicio(nueva cabeza)
		void insertarAlInicio(const string& cancion);

		//Agregar una cancion al final 
		void insertarAlFinal(const string& cancion);

		//insertar en la posicion asignada(0-indexed)
		//si pos<=0, insertar al inicio. Si pos >= cantidad, al final 
		void insertarEnPosicion(const string& cancion, int pos);

		//insertar nueva justo antes de la primera ocurrencia de"referencia"
		//retornar false si "referencia" no existe
		bool insertarAntesDe(const string& referencia, const string& nueva);

		//insertar nueva justo despues de la primera ocurrencia de referencia
		//retornar false si referencia no existe
		bool insertarDespuesDe(const string& referencia, const string& nueva);
		
		//busqueda
		//retornar true si el nombre de la cancion existe en el historial
		bool existeCancion(const string& cancion)const;

		//retonrar la posicion (0-indexed) de la primera ocurrencia
		//retornar " " so la posicion esta fuera de rango 
		int obtenerPosicion(const string& cancion)const;
		string obtenerEnPosicion(int pos)const;

		int obtenerPosicionDesdeElFinal(const string& cancion)const;
		bool eliminarPrimera(const string& cancion);
		bool eliminarUltima(const string& cancion);
		bool eliminarEnPosicion(int pos);
		bool eliminarCabeza();
		bool eliminarCola();
		void imprimirCronologico()const; //cabeza -> cola
		void imprimirInverso()const; //cola -> cabeza
		int getCantidad()const;
		bool estaVacia()const;

		

	};
}
#endif