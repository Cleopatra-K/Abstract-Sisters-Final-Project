#ifndef ADVICESTRATEGY_H
#define ADVICESTRATEGY_H

#include "InteractionStrategy.h"
#include <iostream>

class AdviceStrategy : public InteractionStrategy {
public:
    void execute(PlantType* plant) override {
        std::cout << "Providing care instructions for " << plant->getName() << "...\n";
        plant->careForPlant();
    }
};

#endif
