#ifndef AVAILABILITYSTRATEGY_H
#define AVAILABILITYSTRATEGY_H

#include "InteractionStrategy.h"
#include "GreenHouse.h"
#include <iostream>

class AvailabilityStrategy : public InteractionStrategy {
public:
    void execute(PlantType* plant) override {
        GreenHouse* gh = GreenHouse::getInstance();
        if (gh->isPlantAvailable(plant))
            std::cout << plant->getName() << " is available in the greenhouse.\n";
        else
            std::cout << plant->getName() << " is currently out of stock.\n";
    }
};

#endif
