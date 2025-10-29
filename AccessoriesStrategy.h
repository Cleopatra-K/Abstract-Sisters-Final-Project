#ifndef ACCESSORIESSTRATEGY_H
#define ACCESSORIESSTRATEGY_H

#include "InteractionStrategy.h"
#include <iostream>

class AccessoriesStrategy : public InteractionStrategy {
public:
    void execute(PlantType* plant) override {
        std::cout << "Suggesting accessories for " << plant->getName() << ":\n";
        std::cout << "→ Pot color: Terracotta\n";
        std::cout << "→ Add small pebbles and ribbon wrap.\n";
    }
};

#endif
