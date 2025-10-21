/*
Possible subtypes (categories) of plant factories.
*/
#ifndef INDOOR_H
#define INDOOR_H
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
    Aquatic(const std::string& n, double p, const std::string& desc);
    virtual PlantType* clone() const override = 0;
    std::string getCategory() const override;
    void display() const override;
};
#endif