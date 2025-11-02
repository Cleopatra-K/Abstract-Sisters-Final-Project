#ifndef GIFTWRAPDECORATOR_H
#define GIFTWRAPDECORATOR_H

#include "PlantDecorator.h"

class GiftWrapDecorator : public PlantDecorator {
private:
    double wrapPrice;

public:
    GiftWrapDecorator(PlantType* plant, double price = 3.0)
        : PlantDecorator(plant), wrapPrice(price) {}

    double getPrice() const override {
        return decoratedPlant->getPrice() + wrapPrice;
    }

    std::string getDescription() const override {
        return decoratedPlant->getDescription() + " + Gift Wrap";
    }

    PlantType* clone() const override {
        return new GiftWrapDecorator(decoratedPlant->clone(), wrapPrice);
    }
};

#endif
