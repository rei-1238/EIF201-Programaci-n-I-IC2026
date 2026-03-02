#include "Matriz3x3.h"
#include<iostream>


int main() {

	Matriz3x3 matriz{};

	leerMatriz(matriz);
	imprimirMatriz(matriz);
	sumaFilas(matriz);
	sumaColumnas(matriz);

	std::cout << "\nSuma Diagonal: " << sumaDiagonal(matriz) << '\n';

	return 0;
}