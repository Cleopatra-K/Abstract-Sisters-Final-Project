#ifndef POTDECORATOR_H
#define POTDECORATOR_H

#include "PlantDecorator.h"
#include <iostream>

class PotDecorator : public PlantDecorator {
public:
    PotDecorator(PlantType* plant) : PlantDecorator(plant) {}

    void decorate() const override {
        if (decoratedPlant) {
            decoratedPlant->decorate();
            std::cout << "\033[35m" << " + Placed in a stylish pot!" << "\033[0m" << std::endl;
        }
    }

    double orginalPrice = this->getPrice();
    double getPrice() const override {
        return decoratedPlant ? decoratedPlant->getPrice() + 30.0 : orginalPrice;
    }

    std::string getDescription() const override {
        return decoratedPlant ? decoratedPlant->getDescription() + " in Pot" : "No Pot";
    }
};

#endif


