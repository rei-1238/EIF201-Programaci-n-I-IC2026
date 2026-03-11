#include <iostream>
#include "paquetes.h"

int main() {

    int cantidad;

    std::cout << "Cantidad de paquetes: ";
    std::cin >> cantidad;

    while (cantidad <= 0) {
        std::cout << "Debe ser mayor que 0. Intente otra vez: ";
        std::cin >> cantidad;
    }

    double* pesos = crearRegistro(cantidad);

    ingresarPesos(pesos, cantidad);

    double total = calcularPesoTotal(pesos, cantidad);

    double promedio = total / cantidad;

    std::cout << "Peso total: " << total << std::endl;
    std::cout << "Promedio: " << promedio << std::endl;

    double limite;
    std::cout << "Ingrese limite de peso: ";
    std::cin >> limite;

    int sobre = contarSobreLimite(pesos, cantidad, limite);

    std::cout << "Paquetes sobre limite: " << sobre << std::endl;

    const double* masPesado = buscarMasPesado(pesos, cantidad);

    std::cout << "Paquete mas pesado: " << *masPesado << std::endl;

    delete[] pesos;
    pesos = nullptr;

    return 0;
}