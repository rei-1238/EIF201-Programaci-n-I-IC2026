#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include<iostream>


namespace EIF201 {

	class producto
	{
	private:
		std::string nombre;
		double precio;
		int stock;
		std::string codigo;
	public:
		producto(std::string nombre, double precio, int stock, std::string codigo);
	
		// getter
		std::string getNombre()const;
		double getPrecio()const;
		int getStock()const;
		std::string getCodigo()const;
	
		//setter
		void setPrecio(double nuevoPrecio);
		void setStock(int nuevaCantidad);

		//mostrar informacion
		void mostrar()const;
		bool vender(int cantidad);
	
	};
}
#endif // !PRODUCTO_H