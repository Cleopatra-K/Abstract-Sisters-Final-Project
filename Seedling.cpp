/**
 * @file Seedling.cpp
 * @author Cleopatra
 * @brief Implementation of the SeedlingState class methods
 */
#include "Seedling.h" 
#include "Blooming.h" 
#include "Mature.h"   
#include "Withering.h"
#include "PlantType.h" // Context
#include <iostream>

void SeedlingState::handleGrowth(PlantType* plant) {
    std::cout << " Seedling growing..." << std::endl;
    plant->setDays(plant->getDays() + 1);
    plant->setHealth(plant->getHealth() + 5); // Seedlings gain health
}

void SeedlingState::changeState(PlantType* plant) {
    // Check if ready to transition
    if (plant->getDays() >= 4 && plant->getHealth() >= 60) {
        std::cout << plant->getName() << " ready to bloom!" << std::endl;
        plant->setState(new BloomingState());
    } else if (plant->getHealth() < 30) {
        std::cout << plant->getName() << " is withering as seedling!" << std::endl;
        plant->setState(new WitheringState());
    }
    // Otherwise stay in Seedling state
}

void SeedlingState::displayState() const { 
    std::cout << "Seedling "; 
}

PlantState* SeedlingState::clone() const { 
    return new SeedlingState(*this); 
}

std::string SeedlingState::getStateName() const { 
    return "Seedling"; 
}