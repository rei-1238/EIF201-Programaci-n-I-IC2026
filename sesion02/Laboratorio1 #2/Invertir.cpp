#include "Invertir.h"

void invertirArreglo(const std::array<int, MAX>& arregloOriginal, std::array<int, MAX>& arregloIvertido, std::size_t cantidadElementos)
{
	for (std::size_t i = 0; i < cantidadElementos; ++i) {
		arregloIvertido[i] = arregloOriginal[cantidadElementos - 1 - i];
	}
}
