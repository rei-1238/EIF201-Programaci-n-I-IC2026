#ifndef NOMBRECOMPLETO_H
#define NOMBRECOMPLETO_H

#include <string>

std::string obtenerPrimerNombre(const std::string& nombreCompleto);
std::string obtenerPrimerApellido(const std::string& nombreCompleto);
int contarVocales(const std::string& nombreCompleto);
std::string convertirAMayusculas(std::string nombreCompleto);
int obtenerLongitud(const std::string& nombreCompleto);

#endif