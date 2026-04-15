#include "Colony.h"
#include <iostream>
#include <iomanip>

namespace spacecolony {

    Colony::Colony(const std::string& name, const std::string& planet, int domeCount)
        : name(name), planet(planet), domeCount(domeCount) {
        domes = new Dome * [domeCount];
        for (int i = 0; i < domeCount; i++) {
            domes[i] = 0;
        }
    }

    Colony::~Colony() {
        for (int i = 0; i < domeCount; i++) {
            delete domes[i];
        }
        delete[] domes;
    }

    void Colony::addDome(int pos, Dome* d) {
        if (pos >= 0 && pos < domeCount) {
            domes[pos] = d;
        }
    }

    Dome* Colony::getDomeByCode(const std::string& code) const {
        for (int i = 0; i < domeCount; i++) {
            if (domes[i] != 0 && domes[i]->getCode() == code) {
                return domes[i];
            }
        }
        return 0;
    }

    Dome* Colony::findBestDome(Settler* s, const std::string& excludedCode) const {
        Dome* best = 0;
        double bestRatio = -1.0;

        for (int i = 0; i < domeCount; i++) {
            if (domes[i] == 0) {
                continue;
            }
            if (!excludedCode.empty() && domes[i]->getCode() == excludedCode) {
                continue;
            }
            if (domes[i]->canReceive(s)) {
                double projectedRatio = domes[i]->getProjectedRatio(s);
                if (projectedRatio > bestRatio) {
                    bestRatio = projectedRatio;
                    best = domes[i];
                }
            }
        }

        return best;
    }

    bool Colony::smartAssignSettler(Settler* s) {
        Dome* best = findBestDome(s);
        if (best == 0) {
            return false;
        }
        return best->addSettler(s);
    }

    int Colony::evacuateDome(const std::string& code) {
        Dome* source = getDomeByCode(code);
        if (source == 0) {
            return 0;
        }

        source->seal();

        int originalCount = source->getSettlerCount();
        if (originalCount == 0) {
            return 0;
        }

        Settler** evacuated = new Settler * [originalCount];
        int evacuatedCount = 0;

        while (source->getSettlerCount() > 0) {
            Settler* current = source->getSettlerAt(0);
            if (current == 0) {
                break;
            }
            evacuated[evacuatedCount] = source->removeSettler(current->getId(), true);
            evacuatedCount++;
        }

        int notRelocated = 0;

        for (int i = 0; i < evacuatedCount; i++) {
            Dome* best = findBestDome(evacuated[i], code);
            if (best == 0) {
                notRelocated++;
                std::cout << "No se pudo reubicar al colono: "
                    << evacuated[i]->getName() << '\n';
            }
            else {
                best->addSettler(evacuated[i]);
            }
        }

        delete[] evacuated;
        return notRelocated;
    }

    bool Colony::transferSettler(int id, const std::string& fromCode, const std::string& toCode) {
        Dome* from = getDomeByCode(fromCode);
        Dome* to = getDomeByCode(toCode);

        if (from == 0 || to == 0) {
            return false;
        }

        Settler* s = from->findSettler(id);
        if (s == 0) {
            return false;
        }

        if (!to->canReceive(s)) {
            return false;
        }

        Settler* removed = from->removeSettler(id);
        if (removed == 0) {
            return false;
        }

        if (!to->addSettler(removed)) {
            from->addSettler(removed);
            return false;
        }

        return true;
    }

    int Colony::rebalanceColony() {
        int moved = 0;

        for (int i = 0; i < domeCount; i++) {
            if (domes[i] == 0) {
                continue;
            }

            while (domes[i]->getSettlerCount() > 0 && domes[i]->getOxygenRatio() < 1.3) {
                bool changed = false;

                for (int j = 0; j < domes[i]->getSettlerCount(); j++) {
                    Settler* candidate = domes[i]->getSettlerAt(j);
                    if (candidate == 0) {
                        continue;
                    }

                    Dome* bestTarget = 0;
                    double bestRatio = -1.0;

                    for (int k = 0; k < domeCount; k++) {
                        if (domes[k] == 0 || k == i) {
                            continue;
                        }

                        if (domes[k]->canReceive(candidate)) {
                            double projected = domes[k]->getProjectedRatio(candidate);
                            if (projected >= 1.3 && projected > bestRatio) {
                                bestRatio = projected;
                                bestTarget = domes[k];
                            }
                        }
                    }

                    if (bestTarget != 0) {
                        Settler* removed = domes[i]->removeSettler(candidate->getId());
                        if (removed != 0) {
                            if (bestTarget->addSettler(removed)) {
                                moved++;
                                changed = true;
                                break;
                            }
                            else {
                                domes[i]->addSettler(removed);
                            }
                        }
                    }
                }

                if (!changed) {
                    break;
                }
            }
        }

        return moved;
    }

    Settler* Colony::findSettler(int id, std::string& domeCode) const {
        for (int i = 0; i < domeCount; i++) {
            if (domes[i] == 0) {
                continue;
            }

            Settler* found = domes[i]->findSettler(id);
            if (found != 0) {
                domeCode = domes[i]->getCode();
                return found;
            }
        }

        domeCode = "";
        return 0;
    }

    void Colony::showControlBoard() const {
        std::cout << "\n Panel de control: " << name
            << " en " << planet << "\n";

        for (int i = 0; i < domeCount; i++) {
            if (domes[i] == 0) {
                continue;
            }

            double ratio = domes[i]->getOxygenRatio();
            std::string status;

            if (ratio > 1.5) {
                status = "Seguro";
            }
            else if (ratio >= 1.2) {
                status = "Precaucion";
            }
            else {
                status = "Critico";
            }

            std::cout << domes[i]->getCode()
                << " | Tipo: " << domes[i]->getType()
                << " | Colonos: " << domes[i]->getSettlerCount()
                << "/" << domes[i]->getMaxOccupants()
                << " | Ratio: " << std::fixed << std::setprecision(2) << ratio
                << " | Estado: " << status
                << " | Sellado: " << (domes[i]->isSealed() ? "Sí" : "No")
                << '\n';
        }
    }

    void Colony::oxygenAlert(double limit) const {
        std::cout << "\n Alerta de oxigeno (esta debajo de "
            << limit << ") \n";

        for (int i = 0; i < domeCount; i++) {
            if (domes[i] != 0 && domes[i]->getOxygenRatio() < limit) {
                std::cout << domes[i]->getCode()
                    << " | Ratio: " << std::fixed << std::setprecision(2)
                    << domes[i]->getOxygenRatio() << '\n';
            }
        }
    }

    int Colony::productivityReport(const std::string& specialty) const {
        int total = 0;

        for (int i = 0; i < domeCount; i++) {
            if (domes[i] == 0) {
                continue;
            }

            for (int j = 0; j < domes[i]->getSettlerCount(); j++) {
                Settler* s = domes[i]->getSettlerAt(j);
                if (s != 0 && s->getSpecialty() == specialty) {
                    total += s->getProductivity();
                }
            }
        }

        return total;
    }

    void Colony::globalStats() const {
        int totalSettlers = 0;
        double totalConsumption = 0.0;
        double totalCapacity = 0.0;
        int totalProductivity = 0;

        for (int i = 0; i < domeCount; i++) {
            if (domes[i] == 0) {
                continue;
            }

            totalSettlers += domes[i]->getSettlerCount();
            totalConsumption += domes[i]->getCurrentConsumption();
            totalCapacity += domes[i]->getOxygenCapacity();

            for (int j = 0; j < domes[i]->getSettlerCount(); j++) {
                Settler* s = domes[i]->getSettlerAt(j);
                if (s != 0) {
                    totalProductivity += s->getProductivity();
                }
            }
        }

        std::cout << "\n==== Estadisticas globales ====\n";
        std::cout << "Total de colonos: " << totalSettlers << '\n';
        std::cout << "Consumo total de O2: " << totalConsumption << '\n';
        std::cout << "Capacidad total de O2: " << totalCapacity << '\n';
        std::cout << "Productividad total: " << totalProductivity << '\n';
    }

}