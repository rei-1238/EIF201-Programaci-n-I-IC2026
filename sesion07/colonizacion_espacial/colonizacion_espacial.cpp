#include <iostream>
#include "Colony.h"

using namespace spacecolony;

int main() {
    Colony colony("Ares Prime", "Mars", 3);

    colony.addDome(0, new Dome("D1", "laboratory", 120.0, 3));
    colony.addDome(1, new Dome("D2", "engineering", 100.0, 3));
    colony.addDome(2, new Dome("D3", "habitat", 140.0, 4));

    Settler* settlers[8];
    settlers[0] = new Settler(1, "Liam", "engineer", 30.0, 80);
    settlers[1] = new Settler(2, "Mia", "biologist", 25.0, 90);
    settlers[2] = new Settler(3, "Noah", "doctor", 28.0, 85);
    settlers[3] = new Settler(4, "Eva", "geologist", 35.0, 70);
    settlers[4] = new Settler(5, "Ryan", "pilot", 32.0, 88);
    settlers[5] = new Settler(6, "Sofia", "engineer", 29.0, 76);
    settlers[6] = new Settler(7, "Leo", "biologist", 26.0, 84);
    settlers[7] = new Settler(8, "Zoe", "pilot", 31.0, 79);

    std::cout << "\nASIGNACION\n";
    for (int i = 0; i < 8; i++) {
        bool ok = colony.smartAssignSettler(settlers[i]);
        std::cout << settlers[i]->getName() << " -> "
            << (ok ? "asignado" : "no asignado") << '\n';
    }

    colony.showControlBoard();
    colony.oxygenAlert(1.5);

    std::cout << "\nPrueba De Transferencia\n";
    std::cout << "Mover a Mia de D1 a D2: "
        << (colony.transferSettler(2, "D1", "D2") ? "Exito" : "Fallo") << '\n';
    std::cout << "Mover a Liam de D2 a D3: "
        << (colony.transferSettler(1, "D2", "D3") ? "Exito" : "Fallo") << '\n';

    colony.showControlBoard();

    std::cout << "\nPruaba De Evacuacion\n";
    int notRelocated = colony.evacuateDome("D2");
    std::cout << "Colonos no reubicados despues de la evacuacion: "
        << notRelocated << '\n';

    colony.showControlBoard();

    std::cout << "\nPrueba De Revalanceo\n";
    int moved = colony.rebalanceColony();
    std::cout << "Colonos movidos en el rebalanceo: " << moved << '\n';

    colony.showControlBoard();

    std::string domeCode;
    Settler* found = colony.findSettler(4, domeCode);

    std::cout << "\nPrueba De Busqueda\n";
    if (found != 0) {
        std::cout << found->getName()
            << " fue encontrado en el domo "
            << domeCode << '\n';
    }
    else {
        std::cout << "Colono no encontrado\n";
    }

    std::cout << "\nReporte De Productividad\n";
    std::cout << "Productividad de biologos: "
        << colony.productivityReport("biologist") << '\n';
    std::cout << "Productividad de ingenieros: "
        << colony.productivityReport("engineer") << '\n';

    colony.globalStats();

    for (int i = 0; i < 8; i++) {
        delete settlers[i];
    }

    return 0;
}