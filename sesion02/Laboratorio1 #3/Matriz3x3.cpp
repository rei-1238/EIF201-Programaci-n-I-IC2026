#include "Matriz3x3.h"
#include<iostream>
#include<iomanip>

void leerMatriz(Matriz3x3& matriz)
{
	for (std::size_t i = 0; i < FILAS; i++){
		for (std::size_t j = 0; j < COLS; j++){
			std::cout << "valor[" << (i + 1) << "][" << (j + 1) << "]: ";
			std::cin >> matriz[i][j];
		}
	}
}

void imprimirMatriz(const Matriz3x3& matriz){
	std::cout << "\nMATRIZ\n";
	for (std::size_t i = 0; i < FILAS; i++){
		for (std::size_t j = 0; j < COLS; j++){
			std::cout << std::setw(5) << matriz[i][j];
		}
		std::cout << '\n';
	}
}

void sumaFilas(const Matriz3x3& matriz){
	std::cout << "\nLa suma de filas:\n";
	for (std::size_t i = 0; i < FILAS; i++){
		int suma = 0;
		for (std::size_t j = 0; j < COLS; j++){
			suma += matriz[i][j];
		}
		std::cout << "Fila " << (i + 1) << ": " << suma << '\n';
	}
}

void sumaColumnas(const Matriz3x3& matriz){
	std::cout << "\nLa suma de columnas\n";
	for (std::size_t j = 0; j < COLS; j++){
		int suma = 0;
		for (std::size_t i = 0; i < FILAS; i++) {
			suma += matriz[i][j];
		}
		std::cout << "Columna " << (j + 1) << ": " << suma << '\n';
	}
}

int sumaDiagonal(const Matriz3x3& matriz){
	int suma = 0;
	for (std::size_t i = 0; i < FILAS; i++){
		suma += matriz[i][i];
	}
	return suma;
}






