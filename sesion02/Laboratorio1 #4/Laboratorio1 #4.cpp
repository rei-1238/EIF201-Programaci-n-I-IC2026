#include <iostream>
#include <string>
#include "NombreCompleto.h"

int main()
{
    std::string nombreCompleto;

    std::cout << "Digite su nombre completo: ";
    std::getline(std::cin, nombreCompleto);

    std::cout << "\nPrimer nombre: "
        << obtenerPrimerNombre(nombreCompleto);

    std::cout << "\nPrimer apellido: "
        << obtenerPrimerApellido(nombreCompleto);

    std::cout << "\nCantidad de vocales: "
        << contarVocales(nombreCompleto);

    std::cout << "\nEn mayusculas: "
        << convertirAMayusculas(nombreCompleto);

    std::cout << "\nLongitud total: "
        << obtenerLongitud(nombreCompleto);

    return 0;
}