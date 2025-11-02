#ifndef POTDECORATOR_H
#define POTDECORATOR_H

#include "PlantDecorator.h"

class PotDecorator : public PlantDecorator {
private:
    double potPrice;

public:
    PotDecorator(PlantType* plant, double price = 5.0)
        : PlantDecorator(plant), potPrice(price) {}

    double getPrice() const override {
        return decoratedPlant->getPrice() + potPrice;
    }

    std::string getDescription() const override {
        return decoratedPlant->getDescription() + " + Pot";
    }

    PlantType* clone() const override {
        return new PotDecorator(decoratedPlant->clone(), potPrice);
    }
};

#endif

