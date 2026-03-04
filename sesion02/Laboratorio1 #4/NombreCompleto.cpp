#include "NombreCompleto.h"
#include <array>
#include <cctype>



std::string obtenerPrimerNombre(const std::string& nombreCompleto)
{
    int primerEspacio = nombreCompleto.find(' ');
    return nombreCompleto.substr(0, primerEspacio);
}

std::string obtenerPrimerApellido(const std::string& nombreCompleto)
{
        int primerEspacio = nombreCompleto.find(' ');
        int segundoEspacio = nombreCompleto.find(' ', primerEspacio + 1);

        return nombreCompleto.substr(primerEspacio + 1,
            segundoEspacio - primerEspacio - 1);
   
}

int contarVocales(const std::string& nombreCompleto)
{
    std::array<char, 5> vocales = {'a','e','i','o','u'};
    int cantidad = 0;

    for (int i = 0; i < nombreCompleto.length(); i++)
    {
        char letra = std::tolower(nombreCompleto[i]);

        for (int j = 0; j < 5; j++)
        {
            if (letra == vocales[j])
            {
                cantidad++;
            }
        }
    }

    return cantidad;
}

std::string convertirAMayusculas(std::string nombreCompleto)
{
    for (int i = 0; i < nombreCompleto.length(); i++)
    {
        nombreCompleto[i] = std::toupper(nombreCompleto[i]);
    }

    return nombreCompleto;
}

int obtenerLongitud(const std::string& nombreCompleto)
{
    return nombreCompleto.length();
}


