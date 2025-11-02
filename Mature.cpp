/**
 * @file Mature.cpp
 * @author Cleopatra
 * @brief Implementation of the MatureState class methods
 */
#include "Mature.h"
#include "Blooming.h"
#include "Withering.h"
#include "PlantType.h"
#include <iostream>


void MatureState::handleGrowth(PlantType* plant) {
    std::cout << "  🌳 Mature and stable..." << std::endl;
    plant->setDays(plant->getDays() + 1);
    plant->setHealth(plant->getHealth() - 1); // Slow aging
}

void MatureState::changeState(PlantType* plant) {
    // Can bloom again if health is excellent
    if (plant->getHealth() > 80 && plant->getDays() % 15 == 0) {
        std::cout << "  ✨ " << plant->getName() << " is blooming again!" << std::endl;
        plant->setState(new BloomingState());
    }
    // Or wither with old age or poor health
    else if (plant->getDays() >= 20 || plant->getHealth() < 30) {
        std::cout << "  ⚠️  " << plant->getName() << " is withering with age..." << std::endl;
        plant->setState(new WitheringState());
    }
    // Otherwise stay Mature
}

void MatureState::displayState() const { 
    std::cout << "Mature 🌳"; 
}

PlantState* MatureState::clone() const { 
    return new MatureState(*this); 
}

std::string MatureState::getStateName() const { 
    return "Mature"; 
}