#ifndef AVAILABILITYSTRATEGY_H
#define AVAILABILITYSTRATEGY_H

#include "InteractionStrategy.h"
#include "GreenHouse.h"
#include <iostream>

class AvailabilityStrategy : public InteractionStrategy {
private:
    GreenHouse* greenhouse;  

public:
    // Constructor takes the GreenHouse to operate on
    AvailabilityStrategy(GreenHouse* gh) : greenhouse(gh) {}

    void execute(PlantType* plant) override {
        if (!greenhouse) {
            std::cerr << "Error: GreenHouse not set in AvailabilityStrategy.\n";
            return;
        }

        if (greenhouse->isPlantAvailable(plant))
            std::cout << plant->getName() << " is available in the greenhouse.\n";
        else
            std::cout << plant->getName() << " is currently out of stock.\n";
    }
};

#endif
