#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "PlantType.h"
#include <iostream>

class PlantDecorator {
protected:
    PlantType* decoratedPlant;  // Aggregation (not ownership)

public:
    // The decorator does not own the plant — it just references it
    PlantDecorator(PlantType* plant) : decoratedPlant(plant) {}

    virtual ~PlantDecorator() {}  // No deletion here, since it doesn't own the object

    virtual void display() const {
        if (decoratedPlant)
            decoratedPlant->display();
    }

    virtual void careForPlant() {
        if (decoratedPlant)
            decoratedPlant->careForPlant();
    }

    virtual double getPrice() const {
        return decoratedPlant ? decoratedPlant->getPrice() : 0.0;
    }

    virtual std::string getDescription() const {
        return decoratedPlant ? decoratedPlant->getDescription() : "";
    }
};

#endif
