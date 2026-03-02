#ifndef MATRIZ3X3_h
#define MATRIZ3X3_h  
#include<cstddef>
#include<array>


const std::size_t FILAS = 3;
const std::size_t COLS = 3;

using Matriz3x3 = std::array<std::array<int, COLS>, FILAS>;

void leerMatriz(Matriz3x3& matriz);
void imprimirMatriz(const Matriz3x3& matriz);
void sumaFilas(const Matriz3x3& matriz);
void sumaColumnas(const Matriz3x3& matriz);
int sumaDiagonal(const Matriz3x3& matriz);






#endif 
