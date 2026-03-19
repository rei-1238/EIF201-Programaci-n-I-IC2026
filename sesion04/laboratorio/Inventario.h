#ifndef INVENTARIO_H
#define INVENTARIO_H
#include"producto.h"
#include<string>

namespace EIF201 {
	class Inventario
	{
	private:
		producto** productos;
		int cantidad;
		int capacidad;

		void redimencionar();
	public:
		Inventario(int capacidadInicial = 3);
		~Inventario();

		void agregar(producto* nuevo);
		void mostrarTodos()const;

		producto* buscarPorCodigo(std::string codigo)const;
		bool eliminar(std::string codigo);
		double calcularValorTotal()const;

		int getCantidad() const;
		int getCapacidad()const;
	
	};
}

#endif 