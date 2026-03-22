#include "Flota.h"
#include <iostream>
#include <string>
#include <limits>


int mostrarMenu() {


	std::cout << "----- MENU -----" << std::endl;
	std::cout << "1. Registrar vehiculo" << std::endl;
	std::cout << "2. Buscar vehiculo por placa" << std::endl;
	std::cout << "3. Mostrar vehiculos por marca" << std::endl;
	std::cout << "4. Registrar kilometros a un vehiculo" << std::endl;
	std::cout << "5. Desactivar vehiculo" << std::endl;
	std::cout << "6. Reactivar vehiculo" << std::endl;
	std::cout << "7. Eliminar vehiculo" << std::endl;
	std::cout << "8. Mostrar flota completa" << std::endl;
	std::cout << "9. Mostrar cantidad de vehiculos activos" << std::endl;
	std::cout << "10. Salir" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "Opcion: ";

	int opcion;
	std::cin >> opcion;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return opcion;
}

int main() {
	UNA::Flota flota;
	bool ejecutado = true;

	while (ejecutado) {
		int opcion = mostrarMenu();

		switch (opcion) {

		case 1: {
			std::string placa, marca;
			int anio;
			double kilometraje;

			std::cout << "Placa del vehiculo: ";
			std::getline(std::cin, placa);

			std::cout << "Marca del vehiculo: ";
			std::getline(std::cin, marca);

			std::cout << "Anio del vehiculo: ";
			std::cin >> anio;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Anio invalido" << std::endl;
				break;
			}

			std::cout << "Kilometraje del vehiculo: ";
			std::cin >> kilometraje;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Kilometraje invalido" << std::endl;
				break;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			UNA::Vehiculo* nuevo = new UNA::Vehiculo(placa, marca, anio, kilometraje);
			flota.agregar(nuevo);
		}
			  break;

		case 2: {
			std::string placaBuscar;
			std::cout << "Ingrese la placa del vehiculo que desea buscar: ";
			std::getline(std::cin, placaBuscar);

			UNA::Vehiculo* encontrado = flota.buscarPorPlaca(placaBuscar);

			if (encontrado != nullptr) {
				std::cout << "Vehiculo encontrado" << std::endl;
				encontrado->mostrar();
			}
			else {
				std::cout << "Vehiculo no encontrado" << std::endl;
			}
		}
			  break;

		case 3: {
			std::string marcaBuscar;
			std::cout << "Ingrese la marca que desea buscar: ";
			std::getline(std::cin, marcaBuscar);

			flota.mostrarPorMarca(marcaBuscar);
		}
			  break;

		case 4: {
			std::string placaBuscar;
			double km;

			std::cout << "Ingrese la placa del vehiculo: ";
			std::getline(std::cin, placaBuscar);

			UNA::Vehiculo* encontrado = flota.buscarPorPlaca(placaBuscar);

			if (encontrado != nullptr) {
				std::cout << "Ingrese los kilometros a registrar: ";
				std::cin >> km;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Dato invalido" << std::endl;
					break;
				}

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				encontrado->registrarKilometros(km);
			}
			else {
				std::cout << "Vehiculo no encontrado" << std::endl;
			}
		}
			  break;

		case 5: {
			std::string placaBuscar;
			std::cout << "Ingrese la placa del vehiculo a desactivar: ";
			std::getline(std::cin, placaBuscar);

			UNA::Vehiculo* encontrado = flota.buscarPorPlaca(placaBuscar);

			if (encontrado != nullptr) {
				encontrado->desactivar();
			}
			else {
				std::cout << "Vehiculo no encontrado" << std::endl;
			}
		}
			  break;

		case 6: {
			std::string placaBuscar;
			std::cout << "Ingrese la placa del vehiculo a reactivar: ";
			std::getline(std::cin, placaBuscar);

			UNA::Vehiculo* encontrado = flota.buscarPorPlaca(placaBuscar);

			if (encontrado != nullptr) {
				encontrado->reactivar();
			}
			else {
				std::cout << "Vehiculo no encontrado" << std::endl;
			}
		}
			  break;

		case 7: {
			std::string placaEliminar;
			std::cout << "Ingrese la placa del vehiculo que desea eliminar: ";
			std::getline(std::cin, placaEliminar);

			flota.eliminar(placaEliminar);
		}
			  break;

		case 8: {
			flota.mostrarTodos();
		}
			  break;

		case 9: {
			std::cout << "Cantidad de vehiculos activos: " << flota.contarActivos() << std::endl;
		}
			  break;

		case 10: {
			std::cout << "Saliendo del programa..." << std::endl;
			ejecutado = false;
		}
			   break;

		default:
			std::cout << "Opcion invalida" << std::endl;
			break;
		}
	}

	return 0;
}
