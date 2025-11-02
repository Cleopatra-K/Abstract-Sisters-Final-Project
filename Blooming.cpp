/**
 * @file Blooming.cpp
 * @author Cleopatra
 * @brief Implementation of the BloomingState class methods
 */
#include "Blooming.h"
#include "Mature.h"
#include "Withering.h"
#include "PlantType.h"
#include <iostream>

void BloomingState::handleGrowth(PlantType* plant) {
    std::cout << "  Blooming beautifully..." << std::endl;
    plant->setDays(plant->getDays() + 1);
    plant->setHealth(plant->getHealth() - 2); // Blooming is energy-intensive
}

void BloomingState::changeState(PlantType* plant) {
    // Transition to Mature after enough days with good health
    if (plant->getDays() >= 10 && plant->getHealth() >= 50) {
        std::cout << plant->getName() << " has matured!" << std::endl;
        plant->setState(new MatureState());
    } 
    // Or wither if health drops too low
    else if (plant->getHealth() < 40) {
        std::cout <<  plant->getName() << " is withering!" << std::endl;
        plant->setState(new WitheringState());
    }
    // Otherwise stay in Blooming state
}

void BloomingState::displayState() const { 
    std::cout << "Blooming"; 
}

PlantState* BloomingState::clone() const { 
    return new BloomingState(*this); 
}

std::string BloomingState::getStateName() const { 
    return "Blooming"; 
}