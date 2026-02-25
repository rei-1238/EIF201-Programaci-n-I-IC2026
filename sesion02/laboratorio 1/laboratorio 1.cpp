using namespace std;
#include <iostream>
#include <array>
#include"funciones.h"

 
int main()
{
    array<int, 10> ListaNum;
    for (size_t i = 0; i < ListaNum.size(); i++) {
        cout << "ingrese un numero entero:" << endl;
        cin >> ListaNum[i];

    }
    cout << "El mayor es: " << obtenerMayor(ListaNum) << endl;
    cout << "El menor es: " << obtenerMenor(ListaNum) << endl;
    cout << "El promedio es: " << calcularPromedio(ListaNum) << endl;
    cout << "La suma es: " << calcularSuma(ListaNum) << endl;
    
}

