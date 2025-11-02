// Withering.cpp
#include "Withering.h"
#include "Mature.h"
#include "Seedling.h"
#include "PlantType.h"
#include <iostream>

void WitheringState::handleGrowth(PlantType* plant) {
    std::cout << " Withering..." << std::endl;
    plant->setDays(plant->getDays() + 1);
    plant->setHealth(plant->getHealth() - 5); // losing health
}

void WitheringState::changeState(PlantType* plant) {
    if (plant->getHealth() > 50) {
        std::cout << plant->getName() << " has recovered!" << std::endl;
        plant->setState(new SeedlingState());
    }
    // else remain Withering
}

void WitheringState::displayState() const {
    std::cout << "Withering ";
}

PlantState* WitheringState::clone() const {
    return new WitheringState(*this);
}

std::string WitheringState::getStateName() const {
    return "Withering";
}
