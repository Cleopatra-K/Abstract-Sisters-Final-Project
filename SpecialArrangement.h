#ifndef SPECIALARRANGEMENTDECORATOR_H
#define SPECIALARRANGEMENTDECORATOR_H

#include "PlantDecorator.h"
#include <iostream>

class SpecialArrangementDecorator : public PlantDecorator {
public:
    SpecialArrangementDecorator(PlantType* plant) : PlantDecorator(plant) {}

    void decorate() const override {
        if (this->decoratedPlant) {
            this->decoratedPlant->decorate();
            std::cout << "\033[32m"; 
            std::cout << " + Arranged specially for the occasion!" << std::endl;
            std::cout << "Adding special arrangement: ceramic pot, ribbon, and personalized card." << std::endl;
            std::cout << "\033[0m"; 
    
            std::cout << "Enter personal message: ";
            std::getline(std::cin, message);
    
            std::cout << "\033[32m"; 
            std::cout << "Personalized Message: " << message << std::endl;
    
            std::cout << "\033[0m";
    }

    double orginalPrice = this->getPrice();
    double getPrice() const override {
        return this->decoratedPlant ? this->decoratedPlant->getPrice() + 30.0 : orginalPrice;
    }

    std::string orginalDescription = this->getDescription();
    std::string getDescription() const override {
        return this->decoratedPlant ? this->decoratedPlant->getDescription() + " (Special Arrangement)" : "Basic";
    }
};

#endif


