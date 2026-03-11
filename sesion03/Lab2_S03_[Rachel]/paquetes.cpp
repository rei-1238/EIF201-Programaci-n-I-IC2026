#include "paquetes.h"
#include<iostream>

double* crearRegistro(int& cantidad) {
    double* pesos = new double[cantidad];
    return pesos;
}

void* ingresarPesos(double* pesos, int cantidad){
    for (int i = 0; i < cantidad; i++){
        std::cout << "Peso paquete " << i + 1 << ": ";
        std::cin >> pesos[i];

        while (pesos[i] <= 0) {
            std::cout << "Peso invalido, intente de nuevo: ";
            std::cin >> pesos[i];
        }

    }
    return pesos;
}

double calcularPesoTotal(const double* pesos, int cantidad){
    double suma = 0;
    for (int i = 0; i < cantidad; i++){
        suma += pesos[i];
    }
    return suma;
}

int contarSobreLimite(const double* pesos, int cantidad, double limite){
    int contador = 0;
    for (int i = 0; i < cantidad; i++) {
        if (pesos[i]> limite){
            contador++;
        }

    }
    return contador;
}

const double* buscarMasPesado(const double* pesos, int cantidad){
    int indice = 0;
    for (int i = 0; 1 < cantidad; i++){
        if (pesos[i]>pesos[indice]){
            indice = i;

        }
    
    }
    return &pesos[indice];
    
}

