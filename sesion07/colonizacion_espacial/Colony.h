#ifndef COLONY_H
#define COLONY_H

#include <string>
#include "Dome.h"

namespace spacecolony {

    class Colony {
    private:
        std::string name;
        std::string planet;
        Dome** domes;
        int domeCount;

    public:
        Colony(const std::string& name, const std::string& planet, int domeCount);
        ~Colony();

        void addDome(int pos, Dome* d);
        Dome* getDomeByCode(const std::string& code) const;
        Dome* findBestDome(Settler* s, const std::string& excludedCode = "") const;
        bool smartAssignSettler(Settler* s);
        int evacuateDome(const std::string& code);
        bool transferSettler(int id, const std::string& fromCode, const std::string& toCode);
        int rebalanceColony();

        Settler* findSettler(int id, std::string& domeCode) const;
        void showControlBoard() const;
        void oxygenAlert(double limit) const;
        int productivityReport(const std::string& specialty) const;
        void globalStats() const;
    };

}

#endif