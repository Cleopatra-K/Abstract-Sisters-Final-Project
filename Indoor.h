/*
Possible subtypes (categories) of plant factories.
*/
#ifndef INDOOR_H
#define INDOOR_H
#include "PlantType.h"

/**
 * @class IndoorPlant
 * @brief Plants that live inside your house
 * @author Cleopatra
 * 
 * These plants like being inside where it's warm and safe.
 * Examples: Peace Lilies, Spider Plants, Succulents
 */
class IndoorPlant : public PlantType {
public:
    IndoorPlant(const std::string& n, double p, const std::string& desc);
    virtual PlantType* clone() const override = 0;
    std::string getCategory() const override;
    void display() const override;
};
#endif