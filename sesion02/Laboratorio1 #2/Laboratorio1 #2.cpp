#include<iostream>
#include<array>
#include "Invertir.h"

void imprimirArreglo(const std::array<int, MAX>& arreglo, std::size_t cantidadElementos) {
	for (std::size_t i = 0; i < cantidadElementos; ++i) {
		std::cout << arreglo[i] << " ";
	}
	std::cout << "\n";
}

int main() {


	std::array<int, MAX> arregloOriginal{};
	std::array<int, MAX> arregloInvertido{};
	std::size_t cantidadElementos;

	do	{
		std::cout << "Pon la cantidad de elementos (1 a 20): "; 
		std:: cin >> cantidadElementos;


	} while (cantidadElementos< 1 || cantidadElementos>MAX);

	for (std::size_t i = 0; i < cantidadElementos; ++i) {
		std::cout << "Numero[" << i << "]: "; 
		std::cin >> arregloOriginal[i];
	}

	invertirArreglo(arregloOriginal, arregloInvertido, cantidadElementos);

	std::cout << "\nArreglo original: ";
	imprimirArreglo(arregloOriginal, cantidadElementos);

	std::cout << "Arreglo invertido: ";
	imprimirArreglo(arregloInvertido, cantidadElementos);




	return 0;
}