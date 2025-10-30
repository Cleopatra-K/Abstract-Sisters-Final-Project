#ifndef POTDECORATOR_H
#define POTDECORATOR_H

#include "PlantDecorator.h"
#include <iostream>

class PotDecorator : public PlantDecorator {
public:
    PotDecorator(PlantType* plant) : PlantDecorator(plant) {}

    void decorate() override {
        if (this->decoratedPlant) {
            this->decoratedPlant->decorate();
            std::cout << "\033[35m" << " + Placed in a stylish pot!" << "\033[0m" << std::endl;
        }
    }

    double orginalPrice = this->getPrice();
    double getPrice() override {
        return this->decoratedPlant ? this->decoratedPlant->getPrice() + 30.0 : orginalPrice;
    }

    
};

#endif




