#include "Settler.h"
#include <iostream>

namespace spacecolony {

    Settler::Settler(int id, const std::string& name, const std::string& specialty,
        double oxygenConsumption, int productivity)
        : id(id), name(name), specialty(specialty),
        oxygenConsumption(oxygenConsumption), productivity(productivity) {
    }

    int Settler::getId() const {
        return id;
    }

    std::string Settler::getName() const {
        return name;
    }

    std::string Settler::getSpecialty() const {
        return specialty;
    }

    double Settler::getOxygenConsumption() const {
        return oxygenConsumption;
    }

    int Settler::getProductivity() const {
        return productivity;
    }

    void Settler::display() const {
        std::cout << "ID: " << id
            << " | Nombre: " << name
            << " | Especialidad: " << specialty
            << " | O2: " << oxygenConsumption
            << " | Productividad: " << productivity << '\n';
    }

}