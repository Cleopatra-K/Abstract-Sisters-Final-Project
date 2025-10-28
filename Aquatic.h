/*
Possible subtypes (categories) of plant factories.
*/
#ifndef AQUATIC_H
#define AQUATIC_H
#include "PlantType.h"

/**
 * @class AquaticPlant
 * @brief Plants that live in water
 * @author Cleopatra
 * 
 * These plants are like the fish of the plant world - they need water to survive.
 * Examples: Water Lilies, Lotus, Seaweed
 */
class Aquatic: public PlantType {
public:
    Aquatic(const std::string& n, double p, const std::string& desc) 
        : PlantType(n, p, desc) {}

    Aquatic(const std::string& n, double p, const std::string& desc, std::string& colourType) 
        : PlantType(n, p, desc) {(void)colourType;}

    virtual PlantType* clone() const override = 0;
    std::string getCategory() const override = 0;  // Still pure virtual
    void display() const override = 0;
    // std::string Aquatic::getCategory() const override {
    //     return "Aquatic";
    // }

    // void Aquatic::display() const override {
    //     std::cout << "Aquatic Plant: " << getName() << " | Price: R" << getPrice() 
    //             << " | " << getDescription() << std::endl;
    // }
    
};
#endif