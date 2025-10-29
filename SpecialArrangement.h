#ifndef SPECIALARRANGEMENTDECORATOR_H
#define SPECIALARRANGEMENTDECORATOR_H

#include "PlantDecorator.h"
#include <iostream>

class SpecialArrangementDecorator : public PlantDecorator {
public:
    SpecialArrangementDecorator(PlantType* plant) : PlantDecorator(plant) {}

    void display() const override {
        if (decoratedPlant) {
            decoratedPlant->display();
            std::cout << " + Arranged specially for the occasion!" << std::endl;
        }
    }

    double getPrice() const override {
        return decoratedPlant ? decoratedPlant->getPrice() + 30.0 : 30.0;
    }

    std::string getDescription() const override {
        return decoratedPlant ? decoratedPlant->getDescription() + " (Special Arrangement)" : "Special Arrangement";
    }
};

#endif
