#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "PlantType.h"
#include <iostream>
#include <vector>

class PlantDecorator : public PlantType {
protected:
    PlantType* decoratedPlant;  // Not owned — just referenced

public:
    // PlantDecorator(PlantType* plant) : decoratedPlant(plant) {}
    PlantDecorator(PlantType* plant)
        : PlantType(plant->getName(), plant->getPrice(), plant->getDescription(),
                    plant->getColour(), plant->getSeason()),
          decoratedPlant(plant) {}
    virtual ~PlantDecorator() {}

    // Forward core PlantType interface methods
    void display() const override {
        if (decoratedPlant)
            decoratedPlant->display();
    }

    void careForPlant() override {
        if (decoratedPlant)
            decoratedPlant->careForPlant();
    }

    double getPrice() const override {
        return decoratedPlant ? decoratedPlant->getPrice() : 0.0;
    }

    std::string getDescription() const override {
        return decoratedPlant ? decoratedPlant->getDescription() : "";
    }

    // Composite-related methods (usually no operations for decorators)
    void add(PlantType* component) override {}
    void remove(PlantType* component) override {}
    std::vector<PlantType*> getChildren() override { return {}; }

    // Iterator (decorator usually delegates)
    Iterator* createIterator() override {
        return decoratedPlant ? decoratedPlant->createIterator() : nullptr;
    }

    std::string getCategory() const override {
        return decoratedPlant ? decoratedPlant->getCategory() + " + Decoration" : "Decoration";
    }

    PlantType* clone() const override {
        // Shallow clone by default (override in subclasses for deep copy)
        return new PlantDecorator(decoratedPlant);
    }
};

#endif
