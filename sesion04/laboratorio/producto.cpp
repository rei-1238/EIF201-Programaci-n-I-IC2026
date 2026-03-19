#include "producto.h"
#include<iomanip>


namespace EIF201 {

	producto::producto(std::string nombre,double precio, int stock, std::string codigo): nombre
		(nombre),precio(precio),stock(stock),codigo(codigo){}

	//getter
	std::string producto::getNombre()const {
		return nombre;
	}
	
	double producto::getPrecio()const {
		return precio;
	}

	int producto::getStock()const {
		return stock;
	}

	std::string producto::getCodigo()const {
		return codigo;
	}

	//setter

	void producto::setPrecio(double nuevoPrecio) {
		if (nuevoPrecio < 0) {
			std:: cout<< "error";
		}
		
			precio = nuevoPrecio;
	}

	void producto::setStock(int nuevaCantidad) {
		if (nuevaCantidad < 0) {
			std::cout << "Error. La cantidad no puede ser negativa";
		}
		stock = nuevaCantidad;
	}

	void producto::mostrar()const {
		std::cout << " [ " << codigo << " ] " << nombre 
			<< "|precio: " << std::fixed << std::setprecision(2) << precio
			<< " | Stock: " << stock << " unidades " << std::endl;
	}
	//vender ---
}
