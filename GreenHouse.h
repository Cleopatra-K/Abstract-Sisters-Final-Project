#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "PlantType.h"

class GreenHouse {
private:
    std::vector<PlantType*> inventory;

public:
    GreenHouse() {}
    // GreenHouse owns plants
  ~GreenHouse() {
        clearInventory();
    }

    void addToInventory(PlantType* plant) { inventory.push_back(plant); }

    void removeFromInventory(PlantType* plant) {
        inventory.erase(std::remove(inventory.begin(), inventory.end(), plant), inventory.end());
    }

    std::vector<PlantType*> getInventory() const { return inventory; }

    bool isPlantAvailable(PlantType* plant) const {
        return std::find(inventory.begin(), inventory.end(), plant) != inventory.end();
    }

    // void displayAll() const {
    //     std::cout << "=== GreenHouse Plants ===" << std::endl;
    //     for (auto p : inventory)
    //         p->display();
    // }

      void displayAll() const {
        if (inventory.empty()) {
            std::cout << " The greenhouse is currently empty.\n";
            return;
        }

        std::cout << "\n===  Pretoria Blooms Collection  ===\n";
        std::cout << "----------------------------------------\n";
        int index = 1;

        for (auto p : inventory) {
            std::cout << index++ << ". " << p->getName()
                      << " | Price: R" << std::fixed << std::setprecision(2) << p->getPrice()
                      << " | Season: " << p->getSeason()
                      << " | Colour: " << p->getColour()
                      << " | State: " << p->getStateAsString() << "\n";
        }

        std::cout << "----------------------------------------\n";
    }

    void clearInventory() {
        for (auto* p : inventory)
            delete p;
        inventory.clear();
    }
};

#endif
