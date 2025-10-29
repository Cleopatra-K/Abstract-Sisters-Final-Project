/*
Possible subtypes (categories) of plant factories.
*/
#ifndef OUTDOOR_H
#define OUTDOOR_H
#include "PlantType.h"

/**
 * @class OutdoorPlant  
 * @brief Plants that live outside in the garden
 * @author Cleopatra
 * 
 * These plants like sunshine, rain, and lots of space to grow.
 * Examples: Roses, Sunflowers, Trees
 */
class Outdoor: public PlantType {
public:
    Outdoor(const std::string& n, double p, const std::string& desc, std::string &colourType, std::string season);
    virtual PlantType* clone() const override = 0;
    std::string getCategory() const override;
    void display() const override;
};
#endif