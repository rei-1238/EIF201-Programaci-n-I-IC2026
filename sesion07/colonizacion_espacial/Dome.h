#ifndef DOME_H
#define DOME_H

#include <string>
#include "Settler.h"

namespace spacecolony {

    class Dome {
    private:
        std::string code;
        std::string type;
        double oxygenCapacity;
        int maxOccupants;
        bool sealed;
        Settler** settlers;
        int settlerCount;

    public:
        Dome(const std::string& code, const std::string& type,
            double oxygenCapacity, int maxOccupants);
        ~Dome();

        std::string getCode() const;
        std::string getType() const;
        double getOxygenCapacity() const;
        int getMaxOccupants() const;
        int getSettlerCount() const;
        bool isSealed() const;
        Settler* getSettlerAt(int index) const;

        bool specialtyCompatible(Settler* s) const;
        bool canReceive(Settler* s) const;
        bool addSettler(Settler* s);
        Settler* removeSettler(int id, bool force = false);
        Settler* findSettler(int id) const;

        double getCurrentConsumption() const;
        double getOxygenRatio() const;
        double getProjectedRatio(Settler* s) const;

        bool isFull() const;
        void seal();
        void unseal();
        void display() const;
    };

}

#endif