#ifndef GIFTWRAPDECORATOR_H
#define GIFTWRAPDECORATOR_H

#include "PlantDecorator.h"
#include <iostream>

class GiftWrapDecorator : public PlantDecorator {
public:
    GiftWrapDecorator(PlantType* plant) : PlantDecorator(plant) {}

    void decorate() override {
        if (this->decoratedPlant) {
            this->decoratedPlant->decorate();
            std::cout << "\033[35m"
                  << " + Wrapped beautifully for gifting!" << "\033[0m"<< std::endl;
        }
    }

    double orginalPrice = this->getPrice();
    double getPrice() override {
        return this->decoratedPlant ? this->decoratedPlant->getPrice() + 10.0 : orginalPrice;
    }

    std::string getDescription() override {
        return this->decoratedPlant ? this->decoratedPlant->getDescription() + " with Gift Wrap" : " No Gift Wrap";
    }
    GiftWrapDecorator::~GiftWrapDecorator() {
    }
};

#endif




