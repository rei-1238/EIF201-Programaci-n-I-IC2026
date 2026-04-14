#include "Dome.h"
#include <iostream>
#include <iomanip>

namespace spacecolony {

    Dome::Dome(const std::string& code, const std::string& type,
        double oxygenCapacity, int maxOccupants)
        : code(code), type(type), oxygenCapacity(oxygenCapacity),
        maxOccupants(maxOccupants), sealed(false), settlerCount(0) {
        settlers = new Settler * [maxOccupants];
        for (int i = 0; i < maxOccupants; i++) {
            settlers[i] = 0;
        }
    }

    Dome::~Dome() {
        delete[] settlers;
    }

    std::string Dome::getCode() const {
        return code;
    }

    std::string Dome::getType() const {
        return type;
    }

    double Dome::getOxygenCapacity() const {
        return oxygenCapacity;
    }

    int Dome::getMaxOccupants() const {
        return maxOccupants;
    }

    int Dome::getSettlerCount() const {
        return settlerCount;
    }

    bool Dome::isSealed() const {
        return sealed;
    }

    Settler* Dome::getSettlerAt(int index) const {
        if (index < 0 || index >= settlerCount) {
            return 0;
        }
        return settlers[index];
    }

    bool Dome::specialtyCompatible(Settler* s) const {
        if (s == 0) {
            return false;
        }

        std::string sp = s->getSpecialty();

        if (type == "laboratory") {
            return sp == "biologist" || sp == "doctor" || sp == "geologist";
        }

        if (type == "engineering") {
            return sp == "engineer" || sp == "pilot";
        }

        if (type == "habitat") {
            return true;
        }

        return false;
    }

    bool Dome::isFull() const {
        return settlerCount >= maxOccupants;
    }

    double Dome::getCurrentConsumption() const {
        double total = 0.0;
        for (int i = 0; i < settlerCount; i++) {
            total += settlers[i]->getOxygenConsumption();
        }
        return total;
    }

    double Dome::getOxygenRatio() const {
        double current = getCurrentConsumption();
        if (current <= 0.0) {
            return 999999.0;
        }
        return oxygenCapacity / current;
    }

    double Dome::getProjectedRatio(Settler* s) const {
        if (s == 0) {
            return 0.0;
        }

        double projected = getCurrentConsumption() + s->getOxygenConsumption();
        if (projected <= 0.0) {
            return 999999.0;
        }
        return oxygenCapacity / projected;
    }

    bool Dome::canReceive(Settler* s) const {
        if (s == 0) {
            return false;
        }
        if (sealed) {
            return false;
        }
        if (isFull()) {
            return false;
        }
        if (!specialtyCompatible(s)) {
            return false;
        }

        double projectedConsumption = getCurrentConsumption() + s->getOxygenConsumption();
        return projectedConsumption <= oxygenCapacity;
    }

    bool Dome::addSettler(Settler* s) {
        if (!canReceive(s)) {
            return false;
        }

        settlers[settlerCount] = s;
        settlerCount++;
        return true;
    }

    Settler* Dome::findSettler(int id) const {
        for (int i = 0; i < settlerCount; i++) {
            if (settlers[i]->getId() == id) {
                return settlers[i];
            }
        }
        return 0;
    }

    Settler* Dome::removeSettler(int id, bool force) {
        if (sealed && !force) {
            return 0;
        }

        for (int i = 0; i < settlerCount; i++) {
            if (settlers[i]->getId() == id) {
                Settler* removed = settlers[i];
                for (int j = i; j < settlerCount - 1; j++) {
                    settlers[j] = settlers[j + 1];
                }
                settlers[settlerCount - 1] = 0;
                settlerCount--;
                return removed;
            }
        }

        return 0;
    }

    void Dome::seal() {
        sealed = true;
    }

    void Dome::unseal() {
        sealed = false;
    }

    void Dome::display() const {
        std::cout << "Domo " << code
            << " | Tipo: " << type
            << " | Colonos: " << settlerCount << "/" << maxOccupants
            << " | O2 Capacidad: " << oxygenCapacity
            << " | O2 Usado: " << getCurrentConsumption()
            << " | Ratio: " << std::fixed << std::setprecision(2) << getOxygenRatio()
            << " | Sellado: " << (sealed ? "Si" : "No") << '\n';

        for (int i = 0; i < settlerCount; i++) {
            std::cout << "   - ";
            settlers[i]->display();
        }
    }

}