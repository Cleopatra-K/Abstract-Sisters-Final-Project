#ifndef POTDECORATOR_H
#define POTDECORATOR_H

#include "PlantDecorator.h"
#include <iostream>

class PotDecorator : public PlantDecorator {
public:
    PotDecorator(PlantType* plant) : PlantDecorator(plant) {}

    void display() const override {
        if (decoratedPlant) {
            decoratedPlant->display();
            std::cout << " + Placed in a stylish pot!" << std::endl;
        }
    }

    double getPrice() const override {
        return decoratedPlant ? decoratedPlant->getPrice() + 30.0 : 30.0;
    }

    std::string getDescription() const override {
        return decoratedPlant ? decoratedPlant->getDescription() + " in Pot" : "Pot Decor";
    }
};

#endif
