#include "funciones.h"

int obtenerMayor(const array<int, 10> ListaNum)
{
	int mayor = ListaNum[0];
	for (size_t i = 0; i < ListaNum.size();i++) {
		if (ListaNum[i] > mayor ) {
			mayor = ListaNum[i];
		}

	}
	return mayor;
}

int obtenerMenor(const array<int, 10> ListaNum)
{
	int menor = ListaNum[0];
	for (size_t i = 0; i < ListaNum.size(); i++) {
		if (ListaNum[i] < menor) {
			menor = ListaNum[i];
		}
	}
	return 0;
}

int calcularSuma(const array<int, 10> ListaNum)
{
	int suma = 0;
	for (size_t i = 0; i < ListaNum.size(); i++) {
		suma += ListaNum[i];
	
	}
	return suma;
}

double calcularPromedio(const array<int, 10> ListaNum)
{
	double promedio = 0;
	double suma = 0;
	suma = calcularSuma(ListaNum);
	promedio = suma / 10;
	return promedio;
}

