#ifndef GIFTWRAPDECORATOR_H
#define GIFTWRAPDECORATOR_H

#include "PlantDecorator.h"
#include <iostream>

class GiftWrapDecorator : public PlantDecorator {
public:
    GiftWrapDecorator(PlantType* plant) : PlantDecorator(plant) {}

    void display() const override {
        if (decoratedPlant) {
            decoratedPlant->display();
            std::cout << " + Wrapped beautifully for gifting!" << std::endl;
        }
    }

    double orginalPrice = this->getPrice();
    double getPrice() const override {
        return decoratedPlant ? decoratedPlant->getPrice() + 10.0 : orginalPrice;
    }

    std::string getDescription() const override {
        return decoratedPlant ? decoratedPlant->getDescription() + " with Gift Wrap" : " No Gift Wrap";
    }
};

#endif
