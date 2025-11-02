#ifndef INDOOR_H
#define INDOOR_H
#include "PlantType.h"

/**
 * @class IndoorPlant
 * @brief Plants that live inside your house
 * @author Cleopatra
 */
class Indoor : public PlantType {
public:
    Indoor(){};
    Indoor(const std::string& n, double p, const std::string& desc,
           const std::string& colourType, const std::string& season)
        : PlantType(n, p, desc, colourType, season) {}

    Indoor(const Indoor& other) : PlantType(other) {} // copy constructor
    virtual PlantType* clone() const override = 0;
    std::string getCategory() const override = 0;
    void display() const override = 0;
};

#endif
