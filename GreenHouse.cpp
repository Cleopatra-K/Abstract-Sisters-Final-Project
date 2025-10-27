/**
 * @file GreenHouse.cpp
 * @brief Implementation of GreenHouse singleton class
 */

#include "GreenHouse.h"

// Static member definition
GreenHouse* GreenHouse::instance = nullptr;

GreenHouse* GreenHouse::getInstance() {
    if (instance == nullptr) {
        instance = new GreenHouse();
    }
    return instance;
}

void GreenHouse::addToInventory(PlantType* plant) {
    inventory.push_back(plant);
}

void GreenHouse::removeFromInventory(PlantType* plant) {
    for (size_t i = 0; i < inventory.size(); i++) {
        if (inventory[i] == plant) {
            inventory.erase(inventory.begin() + i);
            break;
        }
    }
}

std::vector<PlantType*> GreenHouse::getInventory() {
    return inventory;
}

bool GreenHouse::isPlantAvailable(PlantType* plant) {
    for (auto item : inventory) {
        if (item == plant) return true;
    }
    return false;
}