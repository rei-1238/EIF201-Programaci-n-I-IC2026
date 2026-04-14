#ifndef SETTLER_H
#define SETTLER_H

#include <string>

namespace spacecolony {

    class Settler {
    private:
        int id;
        std::string name;
        std::string specialty;
        double oxygenConsumption;
        int productivity;

    public:
        Settler(int id, const std::string& name, const std::string& specialty,
            double oxygenConsumption, int productivity);

        int getId() const;
        std::string getName() const;
        std::string getSpecialty() const;
        double getOxygenConsumption() const;
        int getProductivity() const;

        void display() const;
    };

}

#endif

